extern "C"
{
	#include "atari.h"
	#include "config.h"
	#include "monitor.h"
	#include "colours.h"
	#include "screen.h"

	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include <math.h>

	#include "atari_gp32.h"
	#include "colour_hsv.h"
	//#include "gp2xminlib.h"
}

#include <windows.h>
#include "gx.h"

extern "C"
{
	/* These need C name mangling */
#include "screen.h"
#include "main.h"
#include "colours.h"
#include "ui.h"
#include "keyboard.h"

int smooth_filter = 1; /* default is YES */
int filter_available = 0;
int emulator_active;
};

//#define COUNT_FPS
#ifdef COUNT_FPS
#define DEBUG_TEXT
#endif
//#define DEBUG_TEXT
//#define PALETTE

#ifdef NATY
	extern SDL_Surface * surface;
#endif

// Used externally as an easy way of getting text on the screen!
char * debugTextBuffer = 0;
char * debugText =0;

// Brightness (used externally in state save)
unsigned char defaultBrightness = 2;
unsigned char brightness = 2;

// Screen buffers -> theoretically we double buffer.
// In practice it is not bad without so it is off ATM
// I have performance concerns with GpSwapBuffer
// Need to investigate further
// Update: Just tried -> performance reduced by approx 30-40%
// WTF? Guess it must be waiting for sync?
int pal[256];

// Interrupt driven frame count
// Every second we get called back and store the value here
#ifdef COUNT_FPS
static char countFPSResult[256];
static int drawFPS = 0;
static int realFPS = 0;
static int realFPSCount = 0;
static int drawFPSCount = 0;
void fpsCallback() { drawFPS = drawFPSCount; drawFPSCount = 0; realFPS = realFPSCount; realFPSCount = 0; }
void countFPS(int fullRender);
#endif

// Notes on DIRTYRECT
// Tried it and found it to be slower than without.
// Seemed to be that when it was enabled the antic rendering took 10ms longer. Since the copy to screen takes 5ms that isn't a gain.

#ifndef PI
#define PI 3.142
#endif


#define MAX_CLR         0x100
static UBYTE palRed[MAX_CLR];
static UBYTE palGreen[MAX_CLR];
static UBYTE palBlue[MAX_CLR];
static unsigned short optpalRedBlue[MAX_CLR], optpalGreen[MAX_CLR];

/* First 10 and last 10 colors on palettized devices require special treatment,
   this table will map all colors into 236-color space starting at 10 */
static UBYTE staticTranslate[256];

/* Hicolor mode conversion parameters */
static int redshift = 8; /* 8 for 565 mode, 7 for 555 */
static int greenmask = 0xfc; /* 0xfc for 565, 0xf8 for 555 */
static unsigned short optgreenmask = 0x7E0;
static unsigned short optgreenmaskN = ~optgreenmask;
/* Monochromatic mode conversion parameters */
static UBYTE invert = 0;
static int colorscale = 0;

/* Using vectorized function to save on branches */
typedef void (*tCls)();
typedef void (*tRefresh)(UBYTE*, unsigned int *, int, int);
typedef void (*tDrawKbd)(UBYTE*);

//void palette(int ent, UBYTE r, UBYTE g, UBYTE b);

void hicolor_Cls();
void hicolor_Refresh(UBYTE*, unsigned int *, int, int);

void null_DrawKbd(UBYTE*);
//void smartphone_hicolor_Refresh(UBYTE*);

//void vga_hicolor_Refresh(UBYTE*);

static tCls        pCls        = NULL;
static tRefresh    pRefresh    = NULL;
static tDrawKbd    pDrawKbd    = NULL;

// Acquire screen pointer every frame?
#define FRAMEBASE

// Legacy GAPI mode
static bool legagy_gapi = true;

// VGA device flag
static bool res_VGA = false;

void *RawBeginDraw(void);

#define BEGIN_DRAW ( (legagy_gapi) ? (UBYTE*)GXBeginDraw() : (UBYTE*)RawBeginDraw() )
#define END_DRAW {if (legagy_gapi) GXEndDraw();}

#ifdef FRAMEBASE
	#define GET_SCREEN_PTR() BEGIN_DRAW
	#define RELEASE_SCREEN() END_DRAW
#else
	UBYTE* spScreen = NULL;
	#define GET_SCREEN_PTR() (spScreen)
	#define RELEASE_SCREEN()
#endif

/* the following enables the linear filtering rout for portait.    *-
-* it is left out at the moment, because of bad picture quality,   *-
-* due to the integral downsampling factor & atari's "mostly"      *-
-* double horizontal pixels                                        */
#undef SMARTPHONE_FILTER_PORTRAIT

GXDisplayProperties gxdp;
int kbd_image_ok = 0; /* flag to prevent extra redraws of non-overlay keyboard */

struct tScreenGeometry
{
	long width;
	long height;
	long startoffset;
	long sourceoffset;
	long linestep;
	long pixelstep;
	long xSkipMask;
	long xLimit;
	long lineLimit;
};

tScreenGeometry geom[3];

int useMode = 0;
int maxMode = 2;
static bool translatelandscape = false;

/* 
   This is Microsoft's idea of consistent interfaces.
   Looks like they sacked a lot of people in between OS versions.
   The original team must really like this new way
*/
#define GETRAWFRAMEBUFFER   0x00020001

#define FORMAT_565 1
#define FORMAT_555 2
#define FORMAT_OTHER 3
// I believe this FORMAT_OTHER takes the cake.

typedef struct _RawFrameBufferInfo
{
   WORD wFormat;
   WORD wBPP;
   VOID *pFramePointer;
   int  cxStride;
   int  cyStride;
   int  cxPixels;
   int  cyPixels;
} RawFrameBufferInfo;


///////////////////////////////////////////////////////////////
// Interface, called externally

extern "C" void gron();

extern "C" void * Atari_DisplayActiveBuffer()
{
	return GET_SCREEN_PTR();
}

extern "C" void Atari_DisplayInitPhase2()
{
#ifdef PALETTE
	gp2x_video_init(8);
#else
	// NOP (already gronned)
#endif
	Atari_DisplayBrightness(brightness);

	//FIXME - clear... gp2x_fill_rect(0,0,320,240,0);
	gp2x_video_flip();
}

extern "C" void Atari_DisplayInitialise()
{
#ifdef DEBUG_TEXT
	debugTextBuffer = (char *) malloc(256);
#endif

	//// Set palette (colortable is setup by emulator palette code)
	//Atari_DisplayBrightness(brightness);

#ifdef COUNT_FPS
	// FPS count
	GpTimerOptSet(gpNextTimer, 1, 0, fpsCallback);
	GpTimerSet(gpNextTimer++);
#endif
}

extern "C" unsigned short gp2x_video_color15(unsigned char R, unsigned char G, unsigned char B, unsigned char A)

{
	unsigned short res = ((R&0x00F8)<<8)|((G&0x00F8)<<3)|((B&0x00F8)>>3);
	return res;
}

extern "C" void Atari_DisplayBrightness(int level)
{
#ifdef NATY
	SDL_Color entry[256];
#endif
	int i;

	brightness = level;

	for( i = 0 ; i < 256 ; i++ )
	{
		int R = (colortable[i]&0xff0000) >> 16;
		int G = (colortable[i]&0xff00) >> 8;
		int B = (colortable[i]&0xff) >> 0;

		if (brightness!=0)
		{
			double Rd=R,Gd=G,Bd=B;

			double Vadj = 1.0 + brightness/10.0;
			double Sadj = 1.0 + brightness/35.0;
			
			double H,S,V;
			rgb2hsv(Rd,Gd,Bd,&H,&S,&V);
			//fprintf(stderr, "BE:R:%03f:G:%03f:B:%03f H:%03f:S:%03f:V:%03f\n", Rd,Gd,Gd,H,S,V);
			V*=Vadj;
			S*=Sadj;
			if (V>1.0) V=1.0;
			if (S>1.0) S=1.0;
			hsv2rgb(H,S,V,&Rd,&Gd,&Bd);
                        //fprintf(stderr, "AF:R:%03f:G:%03f:B:%03f H:%03f:S:%03f:V:%03f\n", Rd,Gd,Gd,H,S,V);

			// Scale by sin first, to boost mid range
			//Rd = (1.0 + PI*(double)Rd/(double)256)/2.0;
			//Gd = (1.0 + PI*(double)Gd/(double)256)/2.0;
			//Bd = (1.0 + PI*(double)Bd/(double)256)/2.0;

			R = Rd<256 ? Rd : 255;
			G = Gd<256 ? Gd : 255;
			B = Bd<256 ? Bd : 255;
		}

#ifdef PALETTE
#ifdef NATY		
		entry[i].unused = 0;
		entry[i].r = R;
		entry[i].g = G;
		entry[i].b = B;
#endif
#endif
		pal[i] = (R<<16)|(G<<8)|B;
	}

	for (i=0; i<256; ++i)
	{
#ifdef PALETTE
		gp2x_video_color8(i,(pal[i]&0xFF0000)>>16, (pal[i]&0xFF00)>>8, (pal[i]&0xFF)); 
#endif
		pal[i] = gp2x_video_color15((pal[i]&0xFF0000)>>16, (pal[i]&0xFF00)>>8, (pal[i]&0xFF), 0);
	}

#ifdef PALETTE
#ifdef NATY
	SDL_SetPalette(surface, SDL_PHYSPAL, entry, 0, 256);
#endif
	gp2x_video_setpalette();
#endif
}

extern "C" void refreshv(UBYTE* scr_ptr, unsigned int * dest, int width, int height);
extern "C" void Atari_DisplayScreen()
{	
	// Passed a null pointer if we are not expected to draw
	// Called every frame regardless...
#ifdef DEBUG_TEXT
	int oldbackbuf = backbuf;
#endif


	if (timeDrawNextFrame)
	{
		unsigned char * screen = (unsigned char *)atari_screen;
	//	if (SDL_MUSTLOCK(gp2Draw))
	//		SDL_LockSurface(gp2Draw);
		
		int width = 320-menuWidth;
		int offset = menuWidth + ((ATARI_WIDTH-320)/2);
		int height = 240-menuHeight;

#ifdef PALETTE
		char * dest = ((char *) gp2x_screen8) + menuWidth;
#else
		unsigned int * dest = (unsigned int *)(((short *) GET_SCREEN_PTR()) + menuWidth);
#endif
		unsigned char * src = (unsigned char *) (screen + offset);

		refreshv(src, dest, width, height);

		/*int y=0;
		for (y=0; y<height; ++y)
		{
#ifdef PALETTE
			memcpy(dest,src,width);
			src+=ATARI_WIDTH;
			dest+=320;
#else
			int x=0;
			for (x=0; x<width; x+=2)
			{
				dest[x>>1] = pal[src[x+1]]<<16|pal[src[x]]; 
			}
			src += ATARI_WIDTH;
			dest += 160;
#endif
		}*/

		//if (SDL_MUSTLOCK(gp2Draw))
		//	SDL_UnlockSurface(gp2Draw);
		//SDL_UpdateRect(gp2Draw,0,0,0,0);
		gp2x_video_flip();
	}

//	debugText = debugTextBuffer;
//	sprintf(debugTextBuffer, "RTC:%8d %8d\n", rtcTick, GpTickCountGet());

#ifdef DEBUG_TEXT
	if (debugText)
	{
		GpRectFill(NULL, &gpDraw[oldbackbuf],5,220,305,10, 0x00);
		GpTextOut(0, &gpDraw[oldbackbuf], 9, 220, debugText, 0xff);
	}
#endif

#ifdef COUNT_FPS
	countFPS(screen!=0);
	GpRectFill(NULL, &gpDraw[oldbackbuf],5,230,305,10, 0x00);
	GpTextOut(0, &gpDraw[oldbackbuf], 9, 230, countFPSResult, 0xff);
#endif
}

///////////////////////////////////////////////////////////////
// Internal
#ifdef COUNT_FPS
void countFPS(int fullRender)
{
	static int first = 1;
	static int lastTicks = 0;
	static int totalTicks = 0;
	static int totalFrames = 0;
	static int skipCount = 0;

	static int fullRenderTicks[10];
	static int fullRenderPos = 0;

	if (first)
	{
		lastTicks = GpTickCountGet();
		first = 0;
	}
	else
	{
		int now = GpTickCountGet();
		int taken = now - lastTicks;
		int avgFrames = ((++totalFrames)*1000)/totalTicks;

		lastTicks = now;
		totalTicks += taken;

		if (fullRender) // Did we render this frame?
		{
			fullRenderPos++;
			if (fullRenderPos == 10)
				fullRenderPos = 0;

			fullRenderTicks[fullRenderPos] = taken;

			drawFPSCount++;
		}
		else
			skipCount++;
		realFPSCount++;

		int fullRenderTickCount=0;
		int k;
		for (k=0;k<10;++k)
			fullRenderTickCount += fullRenderTicks[k];

		sprintf(countFPSResult, "dps:%2d eps:%2d skp:%d rms:%2d rfp:%2d", drawFPS, realFPS, skipCount, fullRenderTickCount/10, 10000/fullRenderTickCount);

	}
}
#endif

int mapPal(int input)
{
#ifdef PALETTE
	return input;
#else
	return pal[input];
#endif
}

/*
 * screen.cpp - WinCE port specific code
 *
 * Copyright (C) 2001-2002 Vasyl Tsvirkunov
 * Copyright (C) 2002-2006 Atari800 development team (see DOC/CREDITS)
 *
 * This file is part of the Atari800 emulator project which emulates
 * the Atari 400, 800, 800XL, 130XE, and 5200 8-bit computers.
 *
 * Atari800 is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Atari800 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Atari800; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/* Originally based on Win32 port by  Krzysztof Nikiel */

DWORD REG_bat, REG_ac, REG_disp, bat_timeout;

static DWORD reg_access(TCHAR *key, TCHAR *val, DWORD data)
{
	HKEY regkey;
	DWORD tmpval, cbdata;

	if (RegOpenKeyEx(HKEY_CURRENT_USER, key, 0, 0, &regkey) != ERROR_SUCCESS)
		return data;

	cbdata = sizeof(DWORD);
	if (RegQueryValueEx(regkey, val, NULL, NULL, (LPBYTE) &tmpval, &cbdata) != ERROR_SUCCESS)
	{
		RegCloseKey(regkey);
		return data;
	}

	cbdata = sizeof(DWORD);
	if (RegSetValueEx(regkey, val, 0, REG_DWORD, (LPBYTE) &data, cbdata) != ERROR_SUCCESS)
	{
		RegCloseKey(regkey);
		return data;
	}

	RegCloseKey(regkey);
	return tmpval;
}

static void backlight_xchg(void)
{
	HANDLE h;

	REG_bat = reg_access(_T("ControlPanel\\BackLight"), _T("BatteryTimeout"), REG_bat);
	REG_ac = reg_access(_T("ControlPanel\\BackLight"), _T("ACTimeout"), REG_ac);
	REG_disp = reg_access(_T("ControlPanel\\Power"), _T("Display"), REG_disp);

	h = CreateEvent(NULL, FALSE, FALSE, _T("BackLightChangeEvent"));
	if (h)
	{
		SetEvent(h);
		CloseHandle(h);
	}
}

void *RawBeginDraw(void)
{
	static RawFrameBufferInfo rfbi;
	HDC hdc = GetDC(NULL);
	ExtEscape(hdc, GETRAWFRAMEBUFFER, 0, NULL, sizeof(RawFrameBufferInfo), (char *) &rfbi);
	ReleaseDC(NULL, hdc);
	return rfbi.pFramePointer;
}

extern "C" void gr_suspend()
{
	if(emulator_active)
	{
#ifndef FRAMEBASE
		if(spScreen)
		{
			END_DRAW;
			spScreen = NULL;
		}
#endif
		emulator_active = 0;
		GXSuspend();
	}
}

extern "C" void gr_resume()
{
	if(!emulator_active)
	{
		emulator_active = 1;
		GXResume();
#ifndef FRAMEBASE
		spScreen = BEGIN_DRAW;
#endif
	}
	//palette_update();
	kbd_image_ok = 0;
}

extern "C" void groff(void)
{
	backlight_xchg();	/* restore backlight settings */
	SystemParametersInfo(SPI_SETBATTERYIDLETIMEOUT, bat_timeout, NULL, SPIF_SENDCHANGE);

#ifndef FRAMEBASE
	if(spScreen)
	{
		END_DRAW;
		spScreen = NULL;
	}
#endif
	GXCloseDisplay();
	emulator_active = 0;
}

extern "C" void gron()
{
	GXOpenDisplay(hWndMain, GX_FULLSCREEN);
	
	gxdp = GXGetDisplayProperties();

	// let's see what type of device we got here
	if (((unsigned int) GetSystemMetrics(SM_CXSCREEN) != gxdp.cxWidth) || ((unsigned int) GetSystemMetrics(SM_CYSCREEN) != gxdp.cyHeight))
	{
		// 2003SE+ and lying about the resolution. good luck.
		legagy_gapi = false;

		RawFrameBufferInfo rfbi;
		HDC hdc = GetDC(NULL);
		ExtEscape(hdc, GETRAWFRAMEBUFFER, 0, NULL, sizeof(RawFrameBufferInfo), (char *) &rfbi);
		ReleaseDC(NULL, hdc);

		if (rfbi.wFormat == FORMAT_565)
			gxdp.ffFormat = kfDirect565;
		else if (rfbi.wFormat == FORMAT_555)
			gxdp.ffFormat = kfDirect555;
		else
			gxdp.ffFormat = 0;
		gxdp.cBPP = rfbi.wBPP;
		gxdp.cbxPitch = rfbi.cxStride;
		gxdp.cbyPitch = rfbi.cyStride;
		gxdp.cxWidth  = rfbi.cxPixels;
		gxdp.cyHeight = rfbi.cyPixels;
	}

	if(gxdp.ffFormat & kfDirect565)
	{
		pCls =        hicolor_Cls;
		pRefresh =    hicolor_Refresh;
		pDrawKbd =    null_DrawKbd;

		redshift = 8;
		greenmask = 0xfc;
		optgreenmask = 0x7E0;
		optgreenmaskN = 0xF81F;

		filter_available = 1;
	}
	else
	{
		//Unsupported...
		exit(0);
	}


	if( !pCls || !pRefresh || !pDrawKbd || ((gxdp.cxWidth < 240) && (gxdp.cxWidth != 176))
		|| ((gxdp.cyHeight < 240) && ((gxdp.cyHeight != 220))) )
	{
	// I don't believe there are devices that end up here
		groff();
		return;
	}

	// portrait
	geom[0].width = gxdp.cxWidth; // 240
	geom[0].height = gxdp.cyHeight; // 320
	geom[0].startoffset = 0;
	geom[0].sourceoffset = 8;
	geom[0].linestep = gxdp.cbyPitch;
	geom[0].pixelstep = gxdp.cbxPitch;
	geom[0].xSkipMask = gxdp.cxWidth < 320 ? 0x00000003 : 0xffffffff;
	geom[0].xLimit = 320; // skip 1/4
	geom[0].lineLimit = ATARI_WIDTH*240;
	
	// left handed landscape
	geom[1].width = gxdp.cyHeight; // 320
	geom[1].height = gxdp.cxWidth; // 240
	geom[1].startoffset = gxdp.cbyPitch*(gxdp.cyHeight-1);
	geom[1].sourceoffset = 8;
	geom[1].linestep = gxdp.cbxPitch;
	geom[1].pixelstep = -gxdp.cbyPitch;
	geom[1].xSkipMask = 0xffffffff;
	geom[1].xLimit = 320; // no skip
	geom[1].lineLimit = ATARI_WIDTH*240;
	
	// right handed landscape
	geom[2].width = gxdp.cyHeight; // 320
	geom[2].height = gxdp.cxWidth; // 240
	geom[2].startoffset = gxdp.cbxPitch*(gxdp.cxWidth-1);
	geom[2].sourceoffset = 8;
	geom[2].linestep = -gxdp.cbxPitch;
	geom[2].pixelstep = gxdp.cbyPitch;
	geom[2].xSkipMask = 0xffffffff;
	geom[2].xLimit = 320; // no skip
	geom[2].lineLimit = ATARI_WIDTH*240;

	/* Fine tune the selection of blit routines */ 
	if ((gxdp.cxWidth == 176) & (gxdp.cyHeight == 220) & (pRefresh == hicolor_Refresh))
	{
		exit(0);
	}
	else if (issmartphone)
	{
		// implicit QVGA
		pDrawKbd = null_DrawKbd;
		geom[0].startoffset = geom[0].linestep * 30;
	}
	else if(gxdp.cyHeight < 320)
	{
			maxMode = 0; // portrait only!
	}



	if ((gxdp.cxWidth == 480) & (gxdp.cyHeight == 640) & (pRefresh == hicolor_Refresh))
	{
		exit(0);
	}


	emulator_active = 1;
	kbd_image_ok = 0;

#ifndef FRAMEBASE
	spScreen = BEGIN_DRAW;
#endif

	/* backlight */
	REG_bat = REG_ac = REG_disp = 2 * 60 * 60 * 1000; /* 2hrs should do it */
	backlight_xchg();
	SystemParametersInfo(SPI_GETBATTERYIDLETIMEOUT, 0, (void *) &bat_timeout, 0);
	SystemParametersInfo(SPI_SETBATTERYIDLETIMEOUT, 60 * 60 * 2, NULL, SPIF_SENDCHANGE);
}

void cls()
{
	pCls();
}

void hicolor_Cls()
{
	int x, y;
	UBYTE* dst;
	UBYTE *scraddr;
	scraddr = GET_SCREEN_PTR();
	if(scraddr)
	{
		for(y=0; y<geom[useMode].height; y++)
		{
			dst = scraddr+geom[useMode].startoffset;
			for(x=0; x<geom[useMode].width; x++)
			{
				*(unsigned short*)dst = 0;
				dst += geom[useMode].pixelstep;
			}
			scraddr += geom[useMode].linestep;
		}
		RELEASE_SCREEN();
	}
	kbd_image_ok = 0;
}

extern "C" void refreshv(UBYTE* scr_ptr, unsigned int * dest_ptr, int width, int height)
{
	pRefresh(scr_ptr, dest_ptr, width, height);
}

void hicolor_Refresh(UBYTE* scr_ptr, unsigned int * dest, int width, int height)
{
/* Mode-specific metrics */
	static long pixelstep = geom[useMode].pixelstep;
	static long linestep  = geom[useMode].linestep;
	static long low_limit = geom[useMode].sourceoffset+24;
	static long high_limit = low_limit + geom[useMode].xLimit;

/* Addressing withing screen_dirty array. This implementation assumes that the
   array does not get reallocated in runtime */
//	static UBYTE* screen_dirty_ptr;
//	static UBYTE* screen_dirty_limit = screen_dirty + ATARI_HEIGHT*ATARI_WIDTH/8;

/* Source base pointer */
	static UBYTE* screen_line_ptr;
/* Source/destination pixel offset */
	static long xoffset;

/* Destination base pointer */
	static UBYTE* dest_line_ptr;

/* Running source and destination pointers */
	static UBYTE* src_ptr;
	static UBYTE* src_ptr_next;
	static ULONG* dest_ptr;

//	if(!emulator_active)
//	{
//		Sleep(100);
//#ifndef MULTITHREADED
//		MsgPump();
//#endif
//		return;
//	}

/* Update screen mode, also thread protection by doing this */
	//if(useMode != currentScreenMode)
	{
		//useMode = currentScreenMode;

		pixelstep = geom[useMode].pixelstep;
		linestep = geom[useMode].linestep;
		low_limit = geom[useMode].sourceoffset+24;
		high_limit = low_limit + geom[useMode].xLimit;
	}
		
/* Overlay keyboard in landscape modes */
	dest_line_ptr = (unsigned char *)dest;
	if(dest_line_ptr)
	{
//		screen_dirty_ptr = screen_dirty;
		screen_line_ptr = (UBYTE*)scr_ptr;
		xoffset = 0;

	/* Offset destination pointer to allow for rotation and particular screen geometry */
		dest_line_ptr += geom[useMode].startoffset;

	/* There are multiple versions of the internal loop based on screen geometry and settings */
		height/=2;
		if(geom[useMode].xSkipMask == 0xffffffff)
		{
		/* Regular 1:1 copy, with color conversion */
			int y=0;
			dest_ptr = (unsigned long *)(dest_line_ptr);
			//dest_ptr+=4;
			src_ptr = screen_line_ptr;
			//src_ptr+=32;
			for (y=0;y<height;++y)//240;)
			{
				int x=0;
				for (x=0; x<width; x+=2)
				{
					dest_ptr[x>>1] = pal[src_ptr[x+1]]<<16|pal[src_ptr[x]];
				}
				src_ptr+=ATARI_WIDTH;
				dest_ptr+=160;
				int w2 = width+2;
				for (x=0; x<w2; x+=2)
				{
					dest_ptr[x>>1] = pal[src_ptr[x]]<<16|pal[src_ptr[x-1]];
				}
				src_ptr+=ATARI_WIDTH;
				dest_ptr+=161;
			}
		}

		RELEASE_SCREEN();
	}
}


void null_DrawKbd(UBYTE* scraddr)
{
	return;
}

extern "C" void gp2x_video_plot(int x, int y, int color)
{
	unsigned short * buffer = (unsigned short *)Atari_DisplayActiveBuffer();

	buffer[x+y*321] = color;
}

extern "C" void gp2x_fill_rect(int x, int y, int width, int height, int col)
{
	if (x+width > 320)
		width = 320-x;
	if (y+height > 240)
		height = 240-y;

	unsigned short * surface = (unsigned short *)Atari_DisplayActiveBuffer();
	surface +=y*321 + x;
	int j=0;
	for (j=0; j<height; ++j)
	{
		int i=0;
		for (i=0;i<width; ++i)
		{
				surface[i] = col;
		}
		surface +=321;
	}
}

 
