/*
Copyright (C) 1996-1997 Id Software, Inc.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/

//Pocket PC Video Driver
//Dan East - Jan 20, 2001
//pocketquake@pocketmatrix.com
//www.pocketmatrix.com/pocketmatrix
//Optimized By TheReaper for Gizmondo for Uses with My GX.DLL.

#include "quakedef.h"
#include "winquake.h"
#include "d_local.h"
#include "../resource.h"
#include "../gx.h"
#include <Aygshell.h>
#define MAX_MODE_LIST	30
#define VID_ROW_SIZE	3

__int64 FPM_TMPVAR_INT64;
qboolean	dibonly;

HWND		mainwindow;

HWND WINAPI InitializeWindow (HINSTANCE hInstance, int nCmdShow);

int			DIBWidth, DIBHeight;
qboolean	DDActive;
RECT		WindowRect;
DWORD		WindowStyle, ExWindowStyle;

int			window_center_x, window_center_y, window_x, window_y, window_width, window_height;
RECT		window_rect;

static DEVMODE	gdevmode;
static qboolean	startwindowed = 0, windowed_mode_set;
static int		firstupdate = 1;
static qboolean	vid_initialized = false, vid_palettized;
static int		lockcount;
static int		vid_fulldib_on_focus_mode;
static qboolean	force_minimized, in_mode_set, is_mode0x13, force_mode_set;
static int		vid_stretched, windowed_mouse;
static qboolean	palette_changed, syscolchg, vid_mode_set, hide_window, pal_is_nostatic;
static HICON	hIcon;

//vars for mlook
int mouse_down=0, mlook=0;
static int mouse_start_x, mouse_start_y;
float start_yaw, start_pitch;
static int virt_key;
static int autoyaw_left, autoyaw_right;
float yaw_modifier=0;
int		vid_paused=0;

viddef_t	vid;				// global video state

#ifdef _X86_
BITMAPINFOHEADER	vidppc_pDib;
HBITMAP				vidppc_hDibSect;
COLORREF			*vidppc_outbuf;
HDC					vidppc_hdc;
#endif

#define MODE_WINDOWED			0
//#define MODE_SETTABLE_WINDOW	10	//Dan, was 2, incremented to get out of our way
#define NO_MODE					(MODE_WINDOWED - 1)
#define MODE_FULLSCREEN_DEFAULT	(MODE_WINDOWED + 3)

// Note that 0 is MODE_WINDOWED
cvar_t		vid_mode = {"vid_mode","0", false};
// Note that 0 is MODE_WINDOWED
cvar_t		_vid_default_mode = {"_vid_default_mode","1", true};
// Note that 3 is MODE_FULLSCREEN_DEFAULT
cvar_t		_vid_default_mode_win = {"_vid_default_mode_win","3", true};
cvar_t		vid_wait = {"vid_wait","0"};
//cvar_t		vid_nopageflip = {"vid_nopageflip","0", true};
cvar_t		_vid_wait_override = {"_vid_wait_override", "1", true};
cvar_t		vid_config_x = {"vid_config_x","320", true};
cvar_t		vid_config_y = {"vid_config_y","240", true};
cvar_t		vid_stretch_by_2 = {"vid_stretch_by_2","1", true};
cvar_t		_windowed_mouse = {"_windowed_mouse","0", true};
cvar_t		vid_fullscreen_mode = {"vid_fullscreen_mode","3", true};
cvar_t		vid_windowed_mode = {"vid_windowed_mode","0", true};
cvar_t		block_switch = {"block_switch","0", true};
cvar_t		vid_window_x = {"vid_window_x", "0", true};
cvar_t		vid_window_y = {"vid_window_y", "0", true};
cvar_t		in_autoyawrate = {"in_autoyawrate", "15", true};

int			vid_modenum = NO_MODE;
int			vid_testingmode, vid_realmode;
double		vid_testendtime;
int			vid_default = 1;//MODE_FULLSCREEN_DEFAULT;//MODE_WINDOWED;
static int	windowed_default;

modestate_t	modestate = MS_UNINIT;

static byte		*vid_surfcache;
static int		vid_surfcachesize;
static int		VID_highhunkmark;

#ifndef _X86_
//Dan: Palette for 565 / 555 RGB
unsigned long	vid_curpal[256];
#else
//Dan: Palette for windows DIB
char			vid_curpal[256][3];
#endif

extern HWND hWnd;

unsigned short	d_8to16table[256];
unsigned	d_8to24table[256];

int     driver = -2,mode;
int    useWinDirect = true, useDirectDraw = true;

//GAPI vars
typedef void * (*GXBEGINDRAW)(void);
extern GXBEGINDRAW GXBeginDraw_;
extern FARPROC GXEndDraw_;
extern struct GXDisplayProperties g_dispProps;
extern int cbxPitch;
extern int cbyPitch;
extern int cbNewRowPitch240;
extern int cbNewColPitch320;


//Dan:
typedef struct {
	modestate_t	type;
	int			width;
	int			height;
	int			modenum;
	int			mode13;
	int			stretched;
	int			dib;
	int			fullscreen;
	int			bpp;
	int			halfscreen;
	char		modedesc[50];//13];
} vmode_t;

static vmode_t	modelist[MAX_MODE_LIST];
static int		nummodes;
static vmode_t	*pcurrentmode;

static vmode_t	badmode;

int min_vid_width=320;

typedef struct cachepic_s
{
	char		name[MAX_QPATH];
	cache_user_t	cache;
} cachepic_t;

#define	MAX_CACHED_PICS		128
cachepic_t	menu_cachepics[MAX_CACHED_PICS];
int			menu_numcachepics;


void VID_MenuDraw (void);
void VID_MenuKey (int key);

LONG WINAPI MainWndProc (HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void AppActivate(BOOL fActive, BOOL minimize);

unsigned short *pScreenBuf=NULL;


/*
================
VID_UpdateWindowStatus
================
*/
void VID_UpdateWindowStatus (void)
{
}


/*
================
ClearAllStates
================
*/
void ClearAllStates (void)
{
	int		i;
	
// send an up event for each key, to make sure the server clears them all
	for (i=0 ; i<256 ; i++)
	{
		Key_Event (i, false);
	}

	Key_ClearStates ();
	IN_ClearStates ();
}


/*
================
VID_CheckAdequateMem
================
*/
qboolean VID_CheckAdequateMem (int width, int height)
{
	int		tbuffersize;

	tbuffersize = width * height * sizeof (*d_pzbuffer);

	tbuffersize += D_SurfaceCacheForRes (width, height);

// see if there's enough memory, allowing for the normal mode 0x13 pixel,
// z, and surface buffers
	if ((host_parms.memsize - tbuffersize + SURFCACHE_SIZE_AT_320X200 +
		 0x10000 * 3) < minimum_memory)
	{
		return false;		// not enough memory for mode
	}

	return true;
}


/*
================
VID_AllocBuffers
================
*/
qboolean VID_AllocBuffers (int width, int height)
{
	int		tsize, tbuffersize;

	tbuffersize = width * height * sizeof (*d_pzbuffer);

	tsize = D_SurfaceCacheForRes (width, height);

	tbuffersize += tsize;

// see if there's enough memory, allowing for the normal mode 0x13 pixel,
// z, and surface buffers
	if ((host_parms.memsize - tbuffersize + SURFCACHE_SIZE_AT_320X200 +
		 0x10000 * 3) < minimum_memory)
	{
		Con_SafePrintf ("Not enough memory for video mode\n");
		return false;		// not enough memory for mode
	}

	vid_surfcachesize = tsize;

	if (d_pzbuffer)
	{
		D_FlushCaches ();
		Hunk_FreeToHighMark (VID_highhunkmark);
		d_pzbuffer = NULL;
	}

	VID_highhunkmark = Hunk_HighMark ();

	d_pzbuffer = Hunk_HighAllocName (tbuffersize, "video");

	vid_surfcache = (byte *)d_pzbuffer +
			width * height * sizeof (*d_pzbuffer);
	
	return true;
}



/*
=================
VID_InitFullDIB
=================
*/
void VID_InitFullDIB (HINSTANCE hInstance)
{
}


/*
=================
VID_NumModes
=================
*/
int VID_NumModes (void)
{
	return nummodes;
}

	
/*
=================
VID_GetModePtr
=================
*/
vmode_t *VID_GetModePtr (int modenum)
{

	if ((modenum >= 0) && (modenum < nummodes))
		return &modelist[modenum];
	else
		return &badmode;
}



/*
=================
VID_GetModeDescriptionMemCheck
=================
*/
char *VID_GetModeDescriptionMemCheck (int mode)
{
	char		*pinfo;
	vmode_t		*pv;

	if ((mode < 0) || (mode >= nummodes))
		return NULL;

	//VID_CheckModedescFixup (mode);

	pv = VID_GetModePtr (mode);
	pinfo = pv->modedesc;

	if (VID_CheckAdequateMem (pv->width, pv->height))
	{
		return pinfo;
	}
	else
	{
		return NULL;
	}
}


/*
=================
VID_GetModeDescription
=================
*/
char *VID_GetModeDescription (int mode)
{
	char		*pinfo;
	vmode_t		*pv;

	if ((mode < 0) || (mode >= nummodes))
		return NULL;

	//VID_CheckModedescFixup (mode);

	pv = VID_GetModePtr (mode);
	pinfo = pv->modedesc;
	return pinfo;
}


/*
=================
VID_GetModeDescription2

Tacks on "windowed" or "fullscreen"
=================
*/
char *VID_GetModeDescription2 (int mode)
{
	static char	pinfo[40];
	vmode_t		*pv;

	if ((mode < 0) || (mode >= nummodes))
		return NULL;

	//VID_CheckModedescFixup (mode);

	pv = VID_GetModePtr (mode);

	if (modelist[mode].type == MS_FULLSCREEN)
	{
		sprintf(pinfo,"%s fullscreen", pv->modedesc);
	}
	else if (modelist[mode].type == MS_FULLDIB)
	{
		sprintf(pinfo,"%s fullscreen", pv->modedesc);
	}
	else
	{
		sprintf(pinfo, "%s windowed", pv->modedesc);
	}

	return pinfo;
}


// KJB: Added this to return the mode driver name in description for console

char *VID_GetExtModeDescription (int mode)
{
	static char	pinfo[40];

	vmode_t		*pv;

	if ((mode < 0) || (mode >= nummodes))
		return NULL;

	//VID_CheckModedescFixup (mode);

	pv = VID_GetModePtr (mode);
	if (modelist[mode].type == MS_FULLDIB)
	{
		sprintf(pinfo,"%s fullscreen DIB", pv->modedesc);
	}
	else
	{
		sprintf(pinfo, "%s windowed", pv->modedesc);
	}

	return pinfo;
}


qboolean VID_SetFullDIBMode (int modenum)
{
	DDActive = 0;

	if (vid.buffer) free(vid.buffer);
	switch (modenum) {
		case 0:
			vid.buffer = vid.conbuffer = vid.direct = malloc(320*240);
			vid.rowbytes = vid.conrowbytes = 320;//*2;//640*2;
			vid.numpages = 1;
			vid.maxwarpwidth = WARP_WIDTH;
			vid.maxwarpheight = WARP_HEIGHT;
			vid.height = vid.conheight = 160;
			vid.width = vid.conwidth = 240;
			vid.aspect = ((float)vid.height / (float)vid.width) *
						(float)(320.0 / 240.0);
			break;
		case 1:
			vid.buffer = vid.conbuffer = vid.direct = malloc(320*241);
			vid.rowbytes = vid.conrowbytes = 320;
			vid.numpages = 1;
			vid.maxwarpwidth = WARP_WIDTH;
			vid.maxwarpheight = WARP_HEIGHT;
			vid.height = vid.conheight = 240;
			vid.width = vid.conwidth = 320;
			vid.aspect = ((float)vid.height / (float)vid.width) *
						(float)(320.0 / 240.0);
			break;
		case 2:
			//Same as mode 1
			vid.buffer = vid.conbuffer = vid.direct = malloc(320*241);
			vid.rowbytes = vid.conrowbytes = 320;
			vid.numpages = 1;
			vid.maxwarpwidth = WARP_WIDTH;
			vid.maxwarpheight = WARP_HEIGHT;
			vid.height = vid.conheight = 240;
			vid.width = vid.conwidth = 320;
			vid.aspect = ((float)vid.height / (float)vid.width) *
						(float)(320.0 / 240.0);
			break;
	}

	return true;
}


void VID_RestoreOldMode (int original_mode)
{
}


void VID_SetDefaultMode (void)
{

	if (vid_initialized)
		VID_SetMode (0, NULL);

}

HWND main_hwnd;

DEFINE_GUID( CLSID_DirectDraw,			0xD7B70EE0,0x4340,0x11CF,0xB0,0x63,0x00,0x20,0xAF,0xC2,0xCD,0x35 );
DEFINE_GUID( CLSID_DirectDrawClipper,           0x593817A0,0x7DB3,0x11CF,0xA2,0xDE,0x00,0xAA,0x00,0xb9,0x33,0x56 );
DEFINE_GUID( IID_IDirectDraw,			0x6C14DB80,0xA733,0x11CE,0xA5,0x21,0x00,0x20,0xAF,0x0B,0xE5,0x60 );
DEFINE_GUID( IID_IDirectDraw2,                  0xB3A6F3E0,0x2B43,0x11CF,0xA2,0xDE,0x00,0xAA,0x00,0xB9,0x33,0x56 );
DEFINE_GUID( IID_IDirectDraw4,                  0x9c59509a,0x39bd,0x11d1,0x8c,0x4a,0x00,0xc0,0x4f,0xd9,0x30,0xc5 );
DEFINE_GUID( IID_IDirectDrawSurface,		0x6C14DB81,0xA733,0x11CE,0xA5,0x21,0x00,0x20,0xAF,0x0B,0xE5,0x60 );
DEFINE_GUID( IID_IDirectDrawSurface2,		0x57805885,0x6eec,0x11cf,0x94,0x41,0xa8,0x23,0x03,0xc1,0x0e,0x27 );
DEFINE_GUID( IID_IDirectDrawSurface3,           0xDA044E00,0x69B2,0x11D0,0xA1,0xD5,0x00,0xAA,0x00,0xB8,0xDF,0xBB );
DEFINE_GUID( IID_IDirectDrawSurface4,           0x0B2B8630,0xAD35,0x11D0,0x8E,0xA6,0x00,0x60,0x97,0x97,0xEA,0x5B );
DEFINE_GUID( IID_IDirectDrawSurface5,           0xb0e83e4,0xf37f,0x11d2,0x8b,0x15,0x0,0xc0,0x4f,0x68,0x92,0x92);


DEFINE_GUID( IID_IDirectDrawPalette,		0x6C14DB84,0xA733,0x11CE,0xA5,0x21,0x00,0x20,0xAF,0x0B,0xE5,0x60 );
DEFINE_GUID( IID_IDirectDrawClipper,		0x6C14DB85,0xA733,0x11CE,0xA5,0x21,0x00,0x20,0xAF,0x0B,0xE5,0x60 );
DEFINE_GUID( IID_IDirectDrawColorControl, 	0x4B9F0EE0,0x0D7E,0x11D0,0x9B,0x06,0x00,0xA0,0xC9,0x03,0xA3,0xB8 );
DEFINE_GUID( IID_IDirectDrawGammaControl,       0x69C11C3E,0xB46B,0x11D1,0xAD,0x7A,0x00,0xC0,0x4F,0xC2,0x9B,0x4E );


static short *pDrawStart=0;
static int nextRow=0;
static int xPitch=0;
static int yPitch=0;
static byte *colEnd;
int rowEnd;
static int nextSrcRow=0;

int VID_GetScreenBuf(int calcParams) {
	//Return codes:
	// 0: failure
	// 1: success

	//We don't have a direct screen access buffer, try to get it.
	if (!GXBeginDraw_) return 0;	//gx.dll has not been loaded
	pScreenBuf=(unsigned short *)(*GXBeginDraw_)();
	if (!pScreenBuf) return 0;	//Can't access screen buffer

	memset(pScreenBuf, 0xff, 2000);


	//Calculate 
	//if (calcParams||!pDrawStart)
		if (!vid_modenum) {
			//Move down to buttom of taskbar
			//TODO: We could use GetSystemMetrics for this value to be nice little coders.
			pDrawStart=pScreenBuf+(cbyPitch*24);	//26 - harcoded height of taskbar
			//This value represents how we have to offset to go from right side of the screen
			//to the left side of the screen and down one pixel:
			//(0, y+1) = (240, y)+rowInc
			//In the case of devices whose screen has (0,0) at the top left this will be zero
			//For devices whose (0,0) is the bottom left (iPaq), this will be a large negative number.
			nextRow=cbyPitch-(320*cbxPitch);
			xPitch=cbxPitch;
			yPitch=cbyPitch;
			//Calculate the ending column pixel
			colEnd=vid.buffer+320*160;
			rowEnd=320;
			nextSrcRow=320-320;	
		} else if (vid_modenum==1) {
			//Landscape Right
			//Move to bottom of screen
			pDrawStart=pScreenBuf;
			nextRow=cbyPitch-(320*cbxPitch);
			xPitch=cbxPitch;
			yPitch=cbyPitch;
			//Calculate the ending column pixel
			colEnd=vid.buffer+320*240;
			rowEnd=320;
			nextSrcRow=0;
		} else {
			//Assume Landscape rotated Left
			pDrawStart=pScreenBuf+(cbxPitch*240);
			nextRow=-(cbxPitch+(320*cbyPitch));
			xPitch=cbyPitch;
			yPitch=-cbxPitch;
			//Calculate the ending column pixel
			colEnd=vid.buffer+320*240;
			rowEnd=320;
			nextSrcRow=0;
		}

	return 1;
}

void VID_ReleaseScreenBuf() {
	if (pScreenBuf&&GXEndDraw_) GXEndDraw_();
	pScreenBuf=NULL;
}

int VID_SetMode (int modenum, unsigned char *palette)
{
	int				original_mode, temp;
//	qboolean		stat;
    MSG				msg;

	while ((modenum >= nummodes) || (modenum < 0))
	{
		if (vid_modenum == NO_MODE)
		{
			if (modenum == vid_default)
			{
				modenum = windowed_default;
			}
			else
			{
				modenum = vid_default;
			}

			Cvar_SetValue ("vid_mode", (float)modenum);
		}
		else
		{
			Cvar_SetValue ("vid_mode", (float)vid_modenum);
			return 0;
		}
	}

	if (!force_mode_set && (modenum == vid_modenum))
		return true;

// so Con_Printfs don't mess us up by forcing vid and snd updates
	temp = scr_disabled_for_loading;
	scr_disabled_for_loading = true;
	in_mode_set = true;

	CDAudio_Pause ();
	S_ClearBuffer ();

	if (vid_modenum == NO_MODE)
		original_mode = windowed_default;
	else
		original_mode = vid_modenum;
	VID_SetFullDIBMode(modenum);

	window_width = vid.width << vid_stretched;
	window_height = vid.height << vid_stretched;

	CDAudio_Resume ();
	scr_disabled_for_loading = temp;

	if (hide_window)
		return true;

	vid_modenum = modenum;
	Cvar_SetValue ("vid_mode", (float)vid_modenum);

	if (vid.width<320) min_vid_width=vid.width;
	else min_vid_width=320;

	if (!VID_AllocBuffers (vid.width, vid.height))
	{
	// couldn't get memory for this mode; try to fall back to previous mode
		VID_RestoreOldMode (original_mode);
		return false;
	}

	D_InitCaches (vid_surfcache, vid_surfcachesize);

	while (	PeekMessage (&msg, NULL, 0, 0, PM_REMOVE))
	{
      	TranslateMessage (&msg);
      	DispatchMessage (&msg);
	}

	if (!msg_suppress_1)
		Con_SafePrintf ("%s\n", VID_GetModeDescription (vid_modenum));

	VID_SetPalette (palette);

	//Dan: Make window redraw to update skins
	InvalidateRect(hWnd, NULL, FALSE);
	UpdateWindow(hWnd);

	in_mode_set = false;
	vid.recalc_refdef = 1;

#ifndef _X86_
	//Calculate buffer vars
	VID_GetScreenBuf(1);
	if (vid_modenum) SetCapture(hWnd);
	else ReleaseCapture();
	VID_ReleaseScreenBuf();
#endif

	switch (vid_modenum) {
		case 0:
			//Auto yaw scroll ranges:
			autoyaw_left=20;
			autoyaw_right=220;
			break;
		case 1:
		case 2:
			//Auto yaw scroll ranges:
			autoyaw_left=40;
			autoyaw_right=280;
			break;
	}


	return true;
}

void VID_LockBuffer (void)
{
}
		
		
void VID_UnlockBuffer (void)
{

}


typedef unsigned short (COLORFUNCTYPE) (unsigned char r, unsigned char g, unsigned char b);
COLORFUNCTYPE *ColorConvert;

unsigned short RGB565(unsigned char r, unsigned char g, unsigned char b) {
	//Dan: RGB 565 mapping
	unsigned int gi=g>>2;
	unsigned int ri=r>>3;
	return b>>3|(gi<<5)|(ri<<11);
}

unsigned short RGB555(unsigned char r, unsigned char g, unsigned char b) {
	//Dan: RGB 555 mapping
	unsigned int gi=g>>3;
	unsigned int ri=r>>3;
	return b>>3|(gi<<5)|(ri<<10);
}

void	VID_SetPalette (unsigned char *palette)
{
	int i;

	if (!palette) return;
#ifndef _X86_
	for (i = 0; i < 256; i++)
		vid_curpal[i]=ColorConvert(palette[i*3],palette[i*3+1],palette[i*3+2]);
#else
	for (i = 0; i < 256; i++)
	{
		//if (palette[i*3]==255&&palette[i*3+1]==0&&palette[i*3+2]==0)
		//	i=i;

		vid_curpal[i][2]=palette[i*3];
		vid_curpal[i][1]=palette[i*3+1];
		vid_curpal[i][0]=palette[i*3+2];
	}
#endif
}


void	VID_ShiftPalette (unsigned char *palette)
{
	VID_SetPalette (palette);
}


/*
=================
VID_DescribeCurrentMode_f
=================
*/
void VID_DescribeCurrentMode_f (void)
{
	Con_Printf ("%s\n", VID_GetExtModeDescription (vid_modenum));
}


/*
=================
VID_NumModes_f
=================
*/
void VID_NumModes_f (void)
{

	if (nummodes == 1)
		Con_Printf ("%d video mode is available\n", nummodes);
	else
		Con_Printf ("%d video modes are available\n", nummodes);
}


/*
=================
VID_DescribeMode_f
=================
*/
void VID_DescribeMode_f (void)
{
	int		modenum;
	
	modenum = Q_atoi (Cmd_Argv(1));

	Con_Printf ("%s\n", VID_GetExtModeDescription (modenum));
}


/*
=================
VID_DescribeModes_f
=================
*/
void VID_DescribeModes_f (void)
{
	int			i, lnummodes;
	char		*pinfo;
	qboolean	na;
	vmode_t		*pv;

	na = false;

	lnummodes = VID_NumModes ();

	for (i=0 ; i<lnummodes ; i++)
	{
		pv = VID_GetModePtr (i);
		pinfo = VID_GetExtModeDescription (i);

		if (VID_CheckAdequateMem (pv->width, pv->height))
		{
			Con_Printf ("%2d: %s\n", i, pinfo);
		}
		else
		{
			Con_Printf ("**: %s\n", pinfo);
			na = true;
		}
	}

	if (na)
	{
		Con_Printf ("\n[**: not enough system RAM for mode]\n");
	}
}



/*
=================
VID_Windowed_f
=================
*/
void VID_Windowed_f (void)
{

	VID_SetMode (0, NULL);
}


/*
=================
VID_Fullscreen_f
=================
*/
void VID_Fullscreen_f (void)
{
	VID_SetMode (1, NULL);
}


/*
=================
VID_Minimize_f
=================
*/
void VID_Minimize_f (void)
{

// we only support minimizing windows; if you're fullscreen,
// switch to windowed first
	if (modestate == MS_WINDOWED)
		ShowWindow (mainwindow, SW_MINIMIZE);
}


LONG WINAPI AboutWndProc (
    HWND    hWnd,
    UINT    uMsg,
    WPARAM  wParam,
    LPARAM  lParam)
{
	LONG			lRet = 0;
	static int		recursiveflag;

	switch (uMsg)
	{
		case WM_INITDIALOG: {
			HWND wnd=GetDlgItem(hWnd, IDC_CREDITS);
			if (wnd) {
				TCHAR s[1024];
#ifdef _MIPS_
				wsprintf(s, _T("Pocket Quake BETA v%0.3f\nDan East: Pocket PC Port\nJacco Bikker: 3D Optimizations\n999: Skins, Alpha Testing\nCarpediem: MIPS Debugging"), POCKETQUAKE_VERSION);
#elif defined (_SH3_)
				wsprintf(s, _T("Pocket Quake BETA v%0.3f\nDan East: Pocket PC Port\nJacco Bikker: 3D Optimizations\n999: Skins, Alpha Testing\nLucas Alonso: SH3 Debugging"), POCKETQUAKE_VERSION);
#else
				wsprintf(s, _T("Pocket Quake BETA v%0.3f\nDan East: Pocket PC Port\nJacco Bikker: 3D Optimizations\n999: Skins, Alpha Testing"), POCKETQUAKE_VERSION);
#endif
				SetWindowText(wnd, s);
			}
			break;
		}
		case WM_CLOSE:
		case WM_COMMAND: 
			EndDialog(hWnd, 0);
			break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}


void	VID_Init (unsigned char *palette)
{
	int		basenummodes;
#ifdef _X86_
	//Non Game-API support
	HDC hdc;
#endif
	
	Cvar_RegisterVariable (&vid_mode);
	Cvar_RegisterVariable (&vid_wait);
	Cvar_RegisterVariable (&_vid_wait_override);
	Cvar_RegisterVariable (&_vid_default_mode);
	Cvar_RegisterVariable (&_vid_default_mode_win);
	Cvar_RegisterVariable (&vid_config_x);
	Cvar_RegisterVariable (&vid_config_y);
	Cvar_RegisterVariable (&vid_stretch_by_2);
	Cvar_RegisterVariable (&_windowed_mouse);
	Cvar_RegisterVariable (&vid_fullscreen_mode);
	Cvar_RegisterVariable (&vid_windowed_mode);
	Cvar_RegisterVariable (&block_switch);
	Cvar_RegisterVariable (&vid_window_x);
	Cvar_RegisterVariable (&vid_window_y);
	Cvar_RegisterVariable (&in_autoyawrate);

	Cmd_AddCommand ("vid_nummodes", VID_NumModes_f);
	Cmd_AddCommand ("vid_describecurrentmode", VID_DescribeCurrentMode_f);
	Cmd_AddCommand ("vid_describemode", VID_DescribeMode_f);
	Cmd_AddCommand ("vid_describemodes", VID_DescribeModes_f);
	Cmd_AddCommand ("vid_windowed", VID_Windowed_f);
	Cmd_AddCommand ("vid_fullscreen", VID_Fullscreen_f);
	Cmd_AddCommand ("vid_minimize", VID_Minimize_f);


	if (COM_CheckParm ("-dibonly"))
		dibonly = true;


	modelist[nummodes].type = MS_FULLDIB;
	modelist[nummodes].width = 240;
	modelist[nummodes].height = 180;
	modelist[nummodes].modenum = 0;
	modelist[nummodes].mode13 = 0;
	modelist[nummodes].stretched = 0;
	modelist[nummodes].halfscreen = 0;
	modelist[nummodes].dib = 1;
	modelist[nummodes].fullscreen = 1;
	modelist[nummodes].bpp = 12;
	strcpy(modelist[nummodes].modedesc, "240 x 180 Portrait");
	nummodes++;

	modelist[nummodes].type = MS_FULLDIB;
	modelist[nummodes].width = 320;
	modelist[nummodes].height = 240;
	modelist[nummodes].modenum = 1;
	modelist[nummodes].mode13 = 0;
	modelist[nummodes].stretched = 0;
	modelist[nummodes].halfscreen = 0;
	modelist[nummodes].dib = 1;
	modelist[nummodes].fullscreen = 1;
	modelist[nummodes].bpp = 12;
	strcpy(modelist[nummodes].modedesc, "320 x 240 Landscape Right");
	nummodes++;

	modelist[nummodes].type = MS_FULLDIB;
	modelist[nummodes].width = 320;
	modelist[nummodes].height = 240;
	modelist[nummodes].modenum = 2;
	modelist[nummodes].mode13 = 0;
	modelist[nummodes].stretched = 0;
	modelist[nummodes].halfscreen = 0;
	modelist[nummodes].dib = 1;
	modelist[nummodes].fullscreen = 1;
	modelist[nummodes].bpp = 12;
	strcpy(modelist[nummodes].modedesc, "320 x 240 Landscape Left");
	nummodes++;

	basenummodes = nummodes;

	vid.maxwarpwidth = WARP_WIDTH;
	vid.maxwarpheight = WARP_HEIGHT;
	vid.colormap = host_colormap;
	vid.fullbright = 256 - LittleLong (*((int *)vid.colormap + 2048));
	vid_testingmode = 0;

	if (hwnd_dialog)
		DestroyWindow (hwnd_dialog);

	
#ifndef DEBUG
	//Dan: I don't want to see this dialog when I debug
	//This is the splash dialog
	//DialogBox(global_hInstance, MAKEINTRESOURCE(IDD_DIALOG2), hWnd, AboutWndProc);
#endif

#ifdef _X86_
	//Non Game-API support
	hdc=GetDC(hWnd);
	vidppc_hdc=CreateCompatibleDC(hdc);
	ReleaseDC(hWnd, hdc);

    memset( &vidppc_pDib, 0, sizeof( BITMAPINFOHEADER ) );
    vidppc_pDib.biSize = sizeof( BITMAPINFOHEADER );
    vidppc_pDib.biWidth = 240;
    vidppc_pDib.biHeight = -320; // top down
    vidppc_pDib.biPlanes = 1;
    vidppc_pDib.biBitCount = 16; // 16 bit color
    vidppc_pDib.biCompression = BI_RGB;

    vidppc_hDibSect = CreateDIBSection( vidppc_hdc, (BITMAPINFO*)&vidppc_pDib,
        DIB_RGB_COLORS, &vidppc_outbuf, NULL, 0);
	SelectObject(vidppc_hdc, vidppc_hDibSect);
#else
/*
	//Set the palette version function based on the GAPI properties for this device
	if (g_dispProps.ffFormat | kfDirect565) ColorConvert=RGB565;
	else if (g_dispProps.ffFormat | kfDirect555) ColorConvert=RGB555;
	else {
		//We don't support this type of RGB encoding.
		ASSERT(0);
		ColorConvert=RGB565;
	}
*/
	ColorConvert=RGB565;
  
	#endif


	//Sound initialization
	S_Init ();

	vid_initialized = true;

	force_mode_set = true;
	VID_SetMode (vid_default, palette);
	force_mode_set = false;

	vid_realmode = vid_modenum;

	VID_SetPalette (palette);

	vid_menudrawfn = VID_MenuDraw;
	vid_menukeyfn = VID_MenuKey;

	strcpy (badmode.modedesc, "Bad mode");

	Draw_Init();

	//Dan:
	v_gamma.value = 1.0;
	Cvar_SetValue ("gamma", v_gamma.value);

}


void	VID_Shutdown (void)
{
	VID_ReleaseScreenBuf();
}

double			last_clock_update=0;
extern double	win_time;
RECT			vid_clockrect;
void PaintCapTime(HDC hdc, LPRECT rect);

void	VID_Update (vrect_t *rects)
{
	//Dan East:
	//Here is where we lookup each quake pixel in the palette and blit it to the output.
#ifndef _X86_
	//This is the Game API specific code

	register unsigned short *cdst;
	register byte *csrc, *rowEnd2;
	register int xPitch2=xPitch, nextRow2=nextRow, nextSrcRow2=nextSrcRow;

#if !defined(MIPS)&&!defined(SH3)
	//We need to get the buffer each frame for MIPS (SH3 too)
	//Thanks to Carpediem's debugging to determine this is necessary.
//	if (!pScreenBuf) 
#endif
		if (!VID_GetScreenBuf(0)) return;

	cdst=pDrawStart;
	csrc=vid.buffer;

	while (csrc<colEnd) {
		//Calculate the ending row pixel
		rowEnd2=csrc+rowEnd;
		while (csrc<rowEnd2) {
			//The next line is what actually sets the color value of the display pixel
			*cdst=(short)vid_curpal[*csrc];
			//Increment our source and display buffer pointers one pixel to the right
			cdst+=xPitch2;
			csrc++;
		}
		//Move down to the next row and all the way to the left
		cdst+=nextRow2;
		csrc+=nextSrcRow2;
	}
#if defined(MIPS)||defined(SH3)
	//We release the buffer each frame for MIPS (SH3 too)
	//Thanks to Carpediem's debugging to determine this is necessary.
	VID_ReleaseScreenBuf();
#endif
	VID_ReleaseScreenBuf();


#else
	//This routine is for non-Game API support, such as the emulator (or non-CE 3.0 devices).
	//This can be optimized quite a bit, but the emulator is far faster than any CE device to begin with.

	register byte *csrc;
	HDC hdc;
	int x,y;
	char *pos=(char *)vidppc_outbuf;

	csrc=vid.buffer;
	for (y=0; y<160; y++) {
		for (x=0; x<240; x++ ) {
			*pos++=vid_curpal[*csrc][0];
			*pos++=vid_curpal[*csrc][1];
			*pos++=vid_curpal[*csrc++][2];
		}
		csrc+=320-240;
	}
	hdc=GetDC(hWnd);
	BitBlt(hdc, 0, 24, 240, 160, vidppc_hdc, 0, 0, SRCCOPY);
	ReleaseDC(hWnd, hdc);
#endif
	//See if the video mode variable has been changed
	if ((int)vid_mode.value != vid_realmode) {
		//It has, so change modes
		VID_SetMode ((int)vid_mode.value, NULL);
		Cvar_SetValue ("vid_mode", (float)vid_modenum);
		vid_realmode = vid_modenum;
	}
	//See if the clock needs to be updated in portrait mode
	if (vid_realmode==0) {
		if (win_time-last_clock_update>60) {
			HDC hdc=GetDC(hWnd);
			PaintCapTime(hdc, &vid_clockrect);
			ReleaseDC(hWnd, hdc);
			last_clock_update=win_time;
		}
	}
}


//==========================================================================
//Dan: Here is where we map keys
byte        scantokey[256] = {
	0,      '\x001', '\x002', '\x003', '\x004', '\x005', '\x006', '\x007', K_BACKSPACE, '\x009',
	'\x00a', '\x00b', '\x00c', K_ENTER, '\x00e', '\x00f', K_SHIFT, K_CTRL, '\x012', '\x013', 
	'\x014', '\x015', '\x016', '\x017', '\x018', '\x019', '\x01a', '\x01b', '\x01c', '\x01d', 
	'\x01e', '\x01f', '\x020', '\x021', '\x022', '\x023', '\x024', K_LEFTARROW, K_UPARROW, K_RIGHTARROW, 
	K_DOWNARROW, '\x029', '\x02a', '\x02b', '\x02c', '\x02d', '\x02e', '\x02f', ')', '!',
	'@', '#', '$', '%', '^', '&', '*', '(', '\x03a', '\x03b', 
	'\x03c', '\x03d', '\x03e', '\x03f', '\x040', '\x041', '\x042', '\x043', '\x044', '\x045', 
	'\x046', '\x047', '\x048', '\x049', '\x04a', '\x04b', '\x04c', '\x04d', '\x04e', '\x04f', 
	'\x050', '\x051', '\x052', '\x053', '\x054', '\x055', '\x056', '\x057', '\x058', '\x059', 	
	'\x05a', 0/*'\x05b'*/, '\x05c', '\x05d', '\x05e', '\x05f', '\x060', '\x061', '\x062', '\x063', 	
	'\x064', '\x065', '\x066', '\x067', '\x068', '\x069', '\x06a', '\x06b', '\x06c', '\x06d', 	
	'\x06e', '\x06f', '\x070', '\x071', '\x072', '\x073', '\x074', '\x075', '\x076', '\x077', 	
	'\x078', '\x079', '\x07a', '\x07b', '\x07c', '\x07d', '\x07e', '\x07f', '\x080', '\x081', 
	'\x082', '\x083', '\x084', '\x085', K_JOY1,  '\x087', '\x088', '\x089', '\x08a', '\x08b', 	
	'\x08c', '\x08d', '\x08e', '\x08f', '\x090', '\x091', '\x092', '\x093', '\x094', '\x095', 	
	'\x096', '\x097', '\x098', '\x099', '\x09a', '\x09b', '\x09c', '\x09d', '\x09e', '\x09f', 	
	'\x0a0', '\x0a1', '\x0a2', '\x0a3', '\x0a4', '\x0a5', '\x0a6', '\x0a7', '\x0a8', '\x0a9', 	
	'\x0aa', '\x0ab', '\x0ac', '\x0ad', '\x0ae', '\x0af', '\x0b0', '\x0b1', '\x0b2', '\x0b3', 	
	'\x0b4', '\x0b5', '\x0b6', '\x0b7', '\x0b8', '\x0b9', ':', '+', '<', '_', 
	'>', '?', '\x0c0', K_AUX1,  K_AUX2,  K_AUX3,  K_AUX4, K_AUX5, '\x0c6', '\x0c7', 
	'\x0c8', '\x0c9', '\x0ca', '\x0cb', '\x0cc', '\x0cd', '\x0ce', '\x0cf', '\x0d0', '\x0d1', 
	'\x0d2', '\x0d3', '\x0d4', '\x0d5', '\x0d6', '\x0d7', '\x0d8', '\x0d9', '\x0da', '{', 
	'|', '}', '"', '\x0df', '\x0e0', '\x0e1', '\x0e2', '\x0e3', '\x0e4', '\x0e5', 
	'\x0e6', '\x0e7', '\x0e8', '\x0e9', '\x0ea', '\x0eb', '\x0ec', '\x0ed', '\x0ee', '\x0ef', 
	'\x0f0', '\x0f1', '\x0f2', '\x0f3', '\x0f4', '\x0f5', '\x0f6', '\x0f7', '\x0f8', '\x0f9', 
	'\x0fa', '\x0fb', '\x0fc', '\x0fd', '\x0fe', '\x0ff'};

byte        scantolower[256] = {
	0,      '\x001', '\x002', '\x003', '\x004', '\x005', '\x006', '\x007', K_BACKSPACE, '\x009',
	'\x00a', '\x00b', '\x00c', K_ENTER, '\x00e', '\x00f', K_SHIFT, K_CTRL, '\x012', '\x013', 
	'\x014', '\x015', '\x016', '\x017', '\x018', '\x019', '\x01a', '\x01b', '\x01c', '\x01d', 
	'\x01e', '\x01f', '\x020', '\x021', '\x022', '\x023', '\x024', K_LEFTARROW, K_UPARROW, K_RIGHTARROW, 
	K_DOWNARROW, '\x029', '\x02a', '\x02b', '\x02c', '\x02d', '\x02e', '\x02f', '\x030', '\x031',
	'\x032', '\x033', '\x034', '\x035', '\x036', '\x037', '\x038', '\x039', '\x03a', '\x03b', 
	'\x03c', '\x03d', '\x03e', '\x03f', '\x040', 'a', 'b', 'c', 'd', 'e', 
	'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 
	'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 	
	'z', 0, '\x05c', '\x05d', '\x05e', '\x05f', '\x060', '\x061', '\x062', '\x063', 	
	'\x064', '\x065', '\x066', '\x067', '\x068', '\x069', '\x06a', '\x06b', '\x06c', '\x06d', 	
	'\x06e', '\x06f', '\x070', '\x071', '\x072', '\x073', '\x074', '\x075', '\x076', '\x077', 	
	'\x078', '\x079', '\x07a', '\x07b', '\x07c', '\x07d', '\x07e', '\x07f', '\x080', '\x081', 
	'\x082', '\x083', '\x084', '\x085', K_JOY1,  '\x087', '\x088', '\x089', '\x08a', '\x08b', 	
	'\x08c', '\x08d', '\x08e', '\x08f', '\x090', '\x091', '\x092', '\x093', '\x094', '\x095', 	
	'\x096', '\x097', '\x098', '\x099', '\x09a', '\x09b', '\x09c', '\x09d', '\x09e', '\x09f', 	
	'\x0a0', '\x0a1', '\x0a2', '\x0a3', '\x0a4', '\x0a5', '\x0a6', '\x0a7', '\x0a8', '\x0a9', 	
	'\x0aa', '\x0ab', '\x0ac', '\x0ad', '\x0ae', '\x0af', '\x0b0', '\x0b1', '\x0b2', '\x0b3', 	
	'\x0b4', '\x0b5', '\x0b6', '\x0b7', '\x0b8', '\x0b9', ';', '=', ',', '-', 
	'.', '/', '\x0c0', K_AUX1,  K_AUX2,  K_AUX3,  K_AUX4, K_AUX5, '\x0c6', '\x0c7', 
	'\x0c8', '\x0c9', '\x0ca', '\x0cb', '\x0cc', '\x0cd', '\x0ce', '\x0cf', '\x0d0', '\x0d1', 
	'\x0d2', '\x0d3', '\x0d4', '\x0d5', '\x0d6', '\x0d7', '\x0d8', '\x0d9', '\x0da', '[', 
	'\\', ']', '\'', '\x0df', '\x0e0', '\x0e1', '\x0e2', '\x0e3', '\x0e4', '\x0e5', 
	'\x0e6', '\x0e7', '\x0e8', '\x0e9', '\x0ea', '\x0eb', '\x0ec', '\x0ed', '\x0ee', '\x0ef', 
	'\x0f0', '\x0f1', '\x0f2', '\x0f3', '\x0f4', '\x0f5', '\x0f6', '\x0f7', '\x0f8', '\x0f9', 
	'\x0fa', '\x0fb', '\x0fc', '\x0fd', '\x0fe', '\x0ff'};

/*
=======
MapKey

Map from windows to quake keynums
=======
*/
int ignoreNextKey=0;

int MapKey (int key)
{
	if (ignoreNextKey==-key) {
		return ignoreNextKey=0;
	} 
	if (ignoreNextKey==key) {
		ignoreNextKey=-key;
		return 0;
	}

	if (key==134) ignoreNextKey=13;

	//Here we take into account screen orientation:
	if (!vid_modenum) return scantokey[key];
	if (vid_modenum==1) {
		int k=scantokey[key];
		switch (k) {
			default:			return k;
		}
	}
	if (vid_modenum==2) {
		int k=scantokey[key];
		switch (k) {
			case K_LEFTARROW:	return K_DOWNARROW;
			case K_RIGHTARROW:	return K_UPARROW;
			case K_UPARROW:		return K_LEFTARROW;
			case K_DOWNARROW:	return K_RIGHTARROW;
			default:			return k;
		}
	}
	return scantokey[key];
}

int MapToCap (int key)
{
	if (ignoreNextKey==-key) {
		return ignoreNextKey=0;
	} 
	if (ignoreNextKey==key) {
		ignoreNextKey=-key;
		return 0;
	}

	if (key==134) ignoreNextKey=13;

	//Here we take into account screen orientation:
	if (!vid_modenum) return scantokey[key];
	if (vid_modenum==1) {
		int k=scantokey[key];
		switch (k) {
			default:			return k;
		}
	}
	if (vid_modenum==2) {
		int k=scantokey[key];
		switch (k) {
			case K_LEFTARROW:	return K_DOWNARROW;
			case K_RIGHTARROW:	return K_UPARROW;
			case K_UPARROW:		return K_LEFTARROW;
			case K_DOWNARROW:	return K_RIGHTARROW;
			default:			return k;
		}
	}
	return scantokey[key];
}

int MapToLower (int key)
{
	if (ignoreNextKey==-key) {
		return ignoreNextKey=0;
	} 
	if (ignoreNextKey==key) {
		ignoreNextKey=-key;
		return 0;
	}

	if (key==134) ignoreNextKey=13;

	//Here we take into account screen orientation:
	if (!vid_modenum) return scantolower[key];
	if (vid_modenum==1) {
		int k=scantolower[key];
		switch (k) {
			default:			return k;
		}
	}
	if (vid_modenum==2) {
		int k=scantolower[key];
		switch (k) {
			case K_LEFTARROW:	return K_DOWNARROW;
			case K_RIGHTARROW:	return K_UPARROW;
			case K_UPARROW:		return K_LEFTARROW;
			case K_DOWNARROW:	return K_RIGHTARROW;
			default:			return k;
		}
	}
	return scantolower[key];
}

/*
================
VID_HandlePause
================
*/
void VID_HandlePause (qboolean pause)
{

	if ((modestate == MS_WINDOWED) && _windowed_mouse.value)
	{
		if (pause)
		{
			IN_DeactivateMouse ();
			IN_ShowMouse ();
		}
		else
		{
			IN_ActivateMouse ();
			IN_HideMouse ();
		}
	}
}

//These are the mapping coordinates for the virtual on screen controls
//Note that with this scheme all vertical dividers must extend the extent of the
//mapping region.  In other words columns must extend from the top to the bottom
//and be of continuous width.  Rows may be discontinuous.

//define the 4 columns:
static int control_horz[4]={27, 54, 184, 0};
//define the rows for each of the columns:
static int control_vert[4][5]={
	{27, 54, 81, 108, 0},
	{27, 54, 81, 108, 0},
	{27, 108, 0},
	{27, 69, 108, 0}};

static HBITMAP ctrlBmp, titlebarBmp;

#define CONTROL_TOP 184

//Mouse movement handler
void Win_MouseMove(WPARAM wParam, LPARAM lParam) {
	//Dan: This is where we calculate the pitch and yaw based on the stylus deviation from
	//the point where the user first clicked in the mlook area.
	int x=LOWORD(lParam), y=HIWORD(lParam);

	yaw_modifier=0;

	if (!mouse_down||!mlook) return;

	//Dan: TODO: We force pitch drift off here.  For some reason it always wants to
	//center the view.  Need to fix so when it is enabled and the stylus is lifted the
	//pitch will center.
	V_StopPitchDrift ();

	//Take into account the screen orientation:
	if (!vid_modenum) {
		if (in_autoyawrate.value) {
			if (x<autoyaw_left) yaw_modifier=in_autoyawrate.value;
			else if (x>autoyaw_right) yaw_modifier=-in_autoyawrate.value;
			else cl.viewangles[YAW]=start_yaw-(m_yaw.value*(x-mouse_start_x)*sensitivity.value*10);
		} else cl.viewangles[YAW]=start_yaw-(m_yaw.value*(x-mouse_start_x)*sensitivity.value*10);
		cl.viewangles[PITCH]=start_pitch+(m_pitch.value*(y-mouse_start_y)*sensitivity.value*10);
	} else if (vid_modenum==1) {
		if (in_autoyawrate.value) {
			if ((320-y)<autoyaw_left) yaw_modifier=in_autoyawrate.value;
			else if ((320-y)>autoyaw_right) yaw_modifier=-in_autoyawrate.value;
			else cl.viewangles[YAW]=start_yaw+(m_yaw.value*(y-mouse_start_y)*sensitivity.value*10);
		} else cl.viewangles[YAW]=start_yaw+(m_yaw.value*(y-mouse_start_y)*sensitivity.value*10);
		cl.viewangles[PITCH]=start_pitch+(m_pitch.value*(x-mouse_start_x)*sensitivity.value*10);
	} else {
		if (in_autoyawrate.value) {
			if (y<autoyaw_left) yaw_modifier=in_autoyawrate.value;
			else if (y>autoyaw_right) yaw_modifier=-in_autoyawrate.value;
			else cl.viewangles[YAW]=start_yaw-(m_yaw.value*(y-mouse_start_y)*sensitivity.value*10);
		} else cl.viewangles[YAW]=start_yaw-(m_yaw.value*(y-mouse_start_y)*sensitivity.value*10);
		cl.viewangles[PITCH]=start_pitch-(m_pitch.value*(x-mouse_start_x)*sensitivity.value*10);
	}

	if (cl.viewangles[PITCH] > 80)
		cl.viewangles[PITCH] = 80;
	else
	if (cl.viewangles[PITCH] < -70)
		cl.viewangles[PITCH] = -70;
}

void Win_MouseButton(WPARAM wParam, LPARAM lParam, int pressed) {
	//Dan: Determine what the user tapped on, and trigger
	//the appropriate key event, mouse capture, etc.
	if (pressed) {
		int row=0, col=0;
		int idx;

		mouse_start_x=LOWORD(lParam);
		mouse_start_y=HIWORD(lParam);


		//Signal the stylus is down and get stylus capture
		mouse_down=1;
		SetCapture(hWnd);

		if (vid_modenum==0) {
			if (mouse_start_y<24) {//The user clicked on the title bar
				if (mouse_start_x<25) {
					//Start button
					vid_paused=1;
					/////////////////SHFullScreen(hWnd, SHFS_SHOWTASKBAR);
					ShowWindow(hWnd, SW_MINIMIZE);
/*
					while (vid_paused) {
						MSG msg;
						while (PeekMessage (&msg, NULL, 0, 0, PM_NOREMOVE))
						{
							if (!GetMessage (&msg, NULL, 0, 0)) {
								vid_paused=0;
								Sys_Quit ();
							}
							//if (TranslateMessage (&msg));
      						DispatchMessage (&msg);
							Sleep(50);
						}
					}
*/
				} else if (mouse_start_x<50) {
					//Mute button
					if (snd_blocked) snd_blocked=0;
					else snd_blocked=1;
				} else if (mouse_start_x>216) {
					//Close button
					PostMessage(hWnd, WM_CLOSE, 0, 0);
					ReleaseCapture();
					return;
				}
			}
			if (mouse_start_y<CONTROL_TOP) //The user clicked in the game area
			{
				//Start mlook
				//Store starting player view angles
				start_yaw=cl.viewangles[YAW];
				start_pitch=cl.viewangles[PITCH];
				mlook=1;
				return; //TODO: handle as mouse click
			}
			//Offset so that the top of the control area is y==0
			mouse_start_y-=CONTROL_TOP;

			//Determine which column of buttons was pressed:
			while (control_horz[col]) {
				if (mouse_start_x<=control_horz[col]) break;
				col++;
			}
			//Now for the row
			while (control_vert[col][row]) {
				if (mouse_start_y<=control_vert[col][row]) break;
				row++;
			}

			//Act on which col and row were selected.
			idx=col<<8|row;
			switch (idx) {
				case 0x0000: virt_key='1'; break;
				case 0x0001: virt_key='3'; break;
				case 0x0002: virt_key='5'; break;
				case 0x0003: virt_key='7'; break;
				case 0x0004: virt_key=K_AUX22; break;
				case 0x0100: virt_key='2'; break;
				case 0x0101: virt_key='4'; break;
				case 0x0102: virt_key='6'; break;
				case 0x0103: virt_key='8'; break;
				case 0x0104: virt_key=K_AUX23; break;
				case 0x0200: virt_key=K_CTRL; break;
				case 0x0201: //MLOOK pad area
					//Restore real mouse y pos (remember we offset so that y==top of control area)
					mouse_start_y=HIWORD(lParam);

					//Store starting player view angles
					start_yaw=cl.viewangles[YAW];
					start_pitch=cl.viewangles[PITCH];
					mlook=1;
					virt_key=0;
					break;
				case 0x0202: virt_key=' '; break;
				case 0x0300: virt_key=27; break;
				case 0x0301: virt_key=K_AUX21; break;
				case 0x0302: virt_key=K_AUX20; break;
				case 0x0303: virt_key='~'; break;
				default:
					//Error - we don't have a handler for this region
					ASSERT(0);
					virt_key=0;
					break;
			}
		} else {
			int x, y;
			if (vid_modenum==1) {
				x=320-mouse_start_y;
				y=mouse_start_x;//-192;
			} else {
				x=mouse_start_y;
				y=240-mouse_start_x;
			}
			if (x<45) {
				if (y<160) virt_key=K_AUX10;
				else virt_key=K_AUX11;
			} else if (x>320-45) {
				if (y<160) virt_key=K_AUX12;
				else virt_key=K_AUX13;
			} else {
				if (y<35) virt_key=K_AUX14;
				else if (y>192) virt_key=K_AUX15;
				else {
					//mlook Area
					//Store starting player view angles
					start_yaw=cl.viewangles[YAW];
					start_pitch=cl.viewangles[PITCH];
					mlook=1;
				}
			}
		}
		if (virt_key) Key_Event (virt_key, true);
	} else {
		//Stylus lifted
		if (virt_key) {
			//Signal quake that the key was released
			Key_Event (virt_key, false);
			virt_key=0;
		}
		mouse_down=mlook=0;
		yaw_modifier=0.0f;
		if (vid_modenum) ReleaseCapture();

		//TODO: Here is where we can reenable the drift pitch if this was a mlook
		//release and drift pitch was on.
	}
}

HFONT vid_hClockFont;

void PaintCapTime(HDC hdc, LPRECT rect) {
	//int hour;
	TCHAR s[256];
	SYSTEMTIME systime;
	COLORREF oldcolor=SetTextColor(hdc, (COLORREF)0x0);
	HFONT ofont=(HFONT)SelectObject(hdc, vid_hClockFont);
	int omode = SetBkMode(hdc, TRANSPARENT);


	FillRect(hdc, rect, GetStockObject(WHITE_BRUSH));

	GetLocalTime(&systime);
	_stprintf(s, _T("%d/%d"), systime.wMonth, systime.wDay);
	ExtTextOut(hdc, rect->left, rect->top-2, ETO_CLIPPED, rect, s, _tcslen(s), NULL);

	//hour=systime.wHour;
	//if (hour>12) hour-=12;
	//else if (!hour) hour=12;

	//_stprintf(s, _T("%d:%02d%s"), hour, systime.wMinute, systime.wHour>11?_T("p"):_T("a"));
	_stprintf(s, _T("%02d:%02d"), systime.wHour, systime.wMinute);
	ExtTextOut(hdc, rect->left, rect->top+8, ETO_CLIPPED, rect, s, _tcslen(s), NULL);

	SetBkMode(hdc, omode);
	SelectObject(hdc, ofont);
	SetTextColor(hdc, oldcolor);
}

/*
===================================================================

MAIN WINDOW

===================================================================
*/

LONG CDAudio_MessageHandler(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

typedef struct tag_KEYDATA
 {
     WORD    cRepeat       ;
     BYTE    ScanCode      ;
     BYTE    fExtended : 1 ;
     BYTE    Reserved  : 3 ;
     BYTE    fAltDown  : 1 ;
     BYTE    fRepeat   : 1 ;
     BYTE    fUp       : 1 ;
 } KEYDATA ;


int vid_inactivating=0; 

/* main window procedure */
LONG WINAPI MainWndProc (
    HWND    hWnd,
    UINT    uMsg,
    WPARAM  wParam,
    LPARAM  lParam)
{
	LONG			lRet = 0;
	HDC				hdc;
	PAINTSTRUCT		ps;
	static int		recursiveflag;

	switch (uMsg)
	{
		case WM_CREATE:
			//Load the bitmap skins
			//TODO: allow external skins
			//ctrlBmp=LoadBitmap(global_hInstance, MAKEINTRESOURCE(IDB_CONTROLS));
			//titlebarBmp=LoadBitmap(global_hInstance, MAKEINTRESOURCE(IDB_TITLEBAR));
			{
				//Create font for clock
				//LOGFONT lf;
				//lf.lfHeight=12;
				//lf.lfWidth=0;
				//lf.lfEscapement=0;
				//lf.lfOrientation=0;
				//lf.lfWeight=FW_BOLD;
				//lf.lfItalic=FALSE;
				//lf.lfUnderline=FALSE;
				//lf.lfStrikeOut=FALSE;
				//lf.lfCharSet=DEFAULT_CHARSET;
				//lf.lfOutPrecision=OUT_DEFAULT_PRECIS;
				//lf.lfClipPrecision=CLIP_DEFAULT_PRECIS;
				//lf.lfQuality=DEFAULT_QUALITY;
				//lf.lfPitchAndFamily=DEFAULT_PITCH;
				//_tcscpy(lf.lfFaceName, _T("Tahoma"));

				//vid_hClockFont=CreateFontIndirect(&lf);
			}
			break;
		case WM_ACTIVATE:
			if (LOWORD(wParam)==WA_INACTIVE) { 

				//HWND wnd;
				//if (lParam&&(GetParent((HWND)lParam)==hWnd)) break;
				//if (vid_paused) break;

				vid_inactivating=1;
				//MessageBox(hWnd, _T("INACTIVE"), NULL, MB_OK);
#ifndef _X86_
				if (pScreenBuf) {
					if (GXEndDraw_) (*GXEndDraw_)();
					pScreenBuf=NULL;
				}
#endif 

				vid_paused=1;
				//SHFullScreen(hWnd, SHFS_SHOWTASKBAR);
				ShowWindow(hWnd, SW_MINIMIZE);

				vid_inactivating=0;
				//The following is to add GigaBar support.
				//wnd=FindWindow(_T("GigaBar"), NULL);
				//if (wnd) ShowWindow(wnd, SW_SHOW);


			} else {
				HWND wnd;
				//sndPlaySound(_T("Alarm1.wav"), SND_ASYNC);
				//if (vid_inactivating) return;
				//if ((lParam&&GetParent((HWND)lParam)!=hWnd))
				//	MessageBox(hWnd, _T("Activate"), NULL, MB_OK);
				////////////SHFullScreen(hWnd, SHFS_HIDETASKBAR);
				//The following is to add GigaBar support.  We hide GigaBar if we are full screen
				wnd=FindWindow(_T("GigaBar"), NULL);
				if (wnd) ShowWindow(wnd, SW_HIDE);
				MoveWindow(hWnd, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), TRUE);

				if (vid_paused) {
					MSG msg;

					ShowWindow(hWnd, SW_SHOW);

					while (PeekMessage (&msg, NULL, 0, 0, PM_NOREMOVE))
					{
						if (!GetMessage (&msg, NULL, 0, 0)) {
							Sys_Quit ();
							return lRet;
						}
      					DispatchMessage (&msg);
					}


  vid_paused=0;
				}
			}

			break;
		case WM_PAINT: {
			hdc = BeginPaint(hWnd, &ps);
			//Here we paint the control skin if in portrait mode
			if (/*!vid_paused&&*/(vid_modenum==0||vid_modenum==NO_MODE)) {
				//HBITMAP oBmp;
				//HDC bmpDC;

				//TODO: Create  DC for the skin bitmaps once when the bitmaps are loaded.
				//bmpDC=CreateCompatibleDC(hdc);
				//oBmp=SelectObject(bmpDC, titlebarBmp);
				//Blit the titlebar bitmap
				//BitBlt(hdc, 0, 0, 240, 24, bmpDC, 0, 0, SRCCOPY);
				//Update the clock
				//vid_clockrect.left=181;
				//vid_clockrect.top=3;
				//vid_clockrect.right=211;
				//vid_clockrect.bottom=21;
				//PaintCapTime(hdc, &vid_clockrect);

				//SelectObject(bmpDC, ctrlBmp);
				//Blit the control bitmap
				//BitBlt(hdc, 0, CONTROL_TOP, 240, 320-CONTROL_TOP, bmpDC, 0, 0, SRCCOPY);

				//SelectObject(bmpDC, oBmp);
				//DeleteDC(bmpDC);

				//Tell Quake to force an update of the game portion of the screen
				//if (!in_mode_set && host_initialized)
					//SCR_UpdateWholeScreen ();
				
			}
			//EndPaint(hWnd, &ps);
			break;
		}
		case WM_CHAR:
			if (!in_mode_set&&!vid_paused)
					if (MapKey(wParam))
						Key_Event (MapKey(wParam), true);
			break;
		case WM_DEADCHAR:
			if (!in_mode_set&&!vid_paused)
					if (MapKey(wParam))
						Key_Event (MapKey(wParam), false);
			break;
		case WM_KEYDOWN: {
			if (!in_mode_set&&!vid_paused) {
				if (GetKeyState(VK_SHIFT)&0x8000||GetKeyState(VK_CAPITAL)&0x0001) {
					if (MapToCap(wParam)) Key_Event (MapToCap(wParam), true);
				} else 
					if (MapToLower(wParam)) Key_Event (MapToLower(wParam), true);
			}
			break;
		}
		case WM_KEYUP:
			if (!in_mode_set&&!vid_paused) {
				if (GetKeyState(VK_SHIFT)&0x8000||GetKeyState(VK_CAPITAL)&0x0001) {
					if (MapToCap(wParam)) Key_Event (MapToCap(wParam), false);
				} else 
					if (MapToLower(wParam)) Key_Event (MapToLower(wParam), false);
			}
			break;
		case WM_LBUTTONDOWN:
			if (!vid_paused)
				Win_MouseButton(wParam, lParam, true);
			break;
		case WM_LBUTTONUP:
			if (!vid_paused)
				Win_MouseButton(wParam, lParam, false);
			break;
		case WM_MOUSEMOVE:
			if (!vid_paused)
				Win_MouseMove(wParam, lParam);
			break;
   	    case WM_CLOSE:
		//Dan East: TODO: Looks like ID Software forgot to save any settings when a quit
		//is requested via Windows.  Quitting by a windows command should result in the same
		//code being called as quitting via the Quake Console command "Quit".
			if (!in_mode_set)
			{
				if (MessageBox (hWnd, _T("Are you sure you want to quit?"), _T("Confirm Exit"),
							MB_YESNO | MB_SETFOREGROUND | MB_ICONQUESTION) == IDYES)
				{
					vid_paused=0;
					Sys_Quit ();
				}
			}
			break;
		default:
            /* pass all unhandled messages to DefWindowProc */
            lRet = DefWindowProc (hWnd, uMsg, wParam, lParam);
	        break;
    }

    /* return 0 if handled message, 1 if not */
    return lRet;
}


extern void M_Menu_Options_f (void);
extern void M_Print (int cx, int cy, char *str);
extern void M_PrintWhite (int cx, int cy, char *str);
extern void M_DrawCharacter (int cx, int line, int num);
extern void M_DrawTransPic (int x, int y, qpic_t *pic);
extern void M_DrawPic (int x, int y, qpic_t *pic);

static int	vid_line, vid_wmodes;

typedef struct
{
	int		modenum;
	char	*desc;
	int		iscur;
	int		ismode13;
	int		width;
} modedesc_t;

#define MAX_COLUMN_SIZE		5
#define MODE_AREA_HEIGHT	(MAX_COLUMN_SIZE + 6)
#define MAX_MODEDESCS		(MAX_COLUMN_SIZE*3)

static modedesc_t	modedescs[MAX_MODEDESCS];

/*
================
VID_MenuDraw
================
*/
void VID_MenuDraw (void)
{
	qpic_t		*p;
	char		*ptr;
	int			lnummodes, i, j, k, column, row, dup, dupmode;
	vmode_t		*pv;
	modedesc_t	tmodedesc;

	p = Draw_CachePic ("gfx/vidmodes.lmp");
	M_DrawPic ( (min_vid_width-p->width)/2, 4, p);

	for (i=0 ; i<3 ; i++)
	{
		ptr = VID_GetModeDescriptionMemCheck (i);
		modedescs[i].modenum = modelist[i].modenum;
		modedescs[i].desc = ptr;
		modedescs[i].ismode13 = 0;
		modedescs[i].iscur = 0;

		if (vid_modenum == i)
			modedescs[i].iscur = 1;
	}

	vid_wmodes = 3;
	lnummodes = VID_NumModes ();
	
	for (i=3 ; i<lnummodes ; i++)
	{
		ptr = VID_GetModeDescriptionMemCheck (i);
		pv = VID_GetModePtr (i);

	// we only have room for 15 fullscreen modes, so don't allow
	// 360-wide modes, because if there are 5 320-wide modes and
	// 5 360-wide modes, we'll run out of space
		if (ptr && ((pv->width != 360) || COM_CheckParm("-allow360")))
		{
			dup = 0;

			for (j=3 ; j<vid_wmodes ; j++)
			{
				if (!strcmp (modedescs[j].desc, ptr))
				{
					dup = 1;
					dupmode = j;
					break;
				}
			}

			if (dup || (vid_wmodes < MAX_MODEDESCS))       
			{
				if (!dup || !modedescs[dupmode].ismode13 || COM_CheckParm("-noforcevga"))
				{
					if (dup)
					{
						k = dupmode;
					}
					else
					{
						k = vid_wmodes;
					}

					modedescs[k].modenum = i;
					modedescs[k].desc = ptr;
					modedescs[k].ismode13 = pv->mode13;
					modedescs[k].iscur = 0;
					modedescs[k].width = pv->width;

					if (i == vid_modenum)
						modedescs[k].iscur = 1;

					if (!dup)
						vid_wmodes++;
				}
			}
		}
	}

// sort the modes on width (to handle picking up oddball dibonly modes
// after all the others)
	for (i=3 ; i<(vid_wmodes-1) ; i++)
	{
		for (j=(i+1) ; j<vid_wmodes ; j++)
		{
			if (modedescs[i].width > modedescs[j].width)
			{
				tmodedesc = modedescs[i];
				modedescs[i] = modedescs[j];
				modedescs[j] = tmodedesc;
			}
		}
	}


	M_Print ((vid.width-15*8)/2 /*13*8*/, 36, "Pocket PC Modes");

	column = 16;
	row = 36+2*8;

	for (i=0 ; i<3; i++)
	{
		if (modedescs[i].iscur)
			M_PrintWhite (column, row, modedescs[i].desc);
		else
			M_Print (column, row, modedescs[i].desc);

		//column += 13*8;
		row+=16;
	}
	{
		M_Print ((vid.width-23*8)/2 /*9*8*/, 36 + MODE_AREA_HEIGHT * 8 + 8,
				"Press Enter to set mode");
		ptr = VID_GetModeDescription2 (vid_modenum);
		M_Print ((vid.width-11*8)/2 /*15*8*/, 36 + MODE_AREA_HEIGHT * 8 + 24,
				"Esc to exit");


		column-=10;
		row -= (3-vid_line)*16;
		

		M_DrawCharacter (column, row, 12+((int)(realtime*4)&1));
	}
}


/*
================
VID_MenuKey
================
*/
void VID_MenuKey (int key)
{
	if (vid_testingmode)
		return;

	switch (key)
	{
	case K_ESCAPE:
		S_LocalSound ("misc/menu1.wav");
		M_Menu_Options_f ();
		break;
	case K_LEFTARROW:
	case K_UPARROW:
		S_LocalSound ("misc/menu1.wav");
		vid_line--;
		if (vid_line < 0) vid_line=vid_wmodes-1;
		break;
	case K_RIGHTARROW:
	case K_DOWNARROW:
		S_LocalSound ("misc/menu1.wav");
		vid_line++;
		if (vid_line>=vid_wmodes) vid_line=0;
		break;

	case K_ENTER:
		S_LocalSound ("misc/menu1.wav");
		VID_SetMode (modedescs[vid_line].modenum, NULL);
		//VID_SetMode (modedescs[vid_line].modenum, (unsigned char *)vid_curpal);
		break;

	case 'T':
	case 't':
		S_LocalSound ("misc/menu1.wav");
	// have to set this before setting the mode because WM_PAINT
	// happens during the mode set and does a VID_Update, which
	// checks vid_testingmode
		//if (!VID_SetMode (modedescs[vid_line].modenum, (unsigned char *)vid_curpal))
		VID_SetMode (modedescs[vid_line].modenum, NULL);
		break;
	default:
		break;
	}
}

void DeinitConProc (void);

void LogIt(char *c) {
	HANDLE f=CreateFile(_T("/log.txt"), GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (f) {
		DWORD d;
		SetFilePointer(f, 0, 0, FILE_END);
		WriteFile(f, c, strlen(c), &d, NULL);
		CloseHandle(f);
	}
}