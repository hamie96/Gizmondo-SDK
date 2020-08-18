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
// sys_win.c -- Win32 system interface code

#include "quakedef.h"
#include "winquake.h"
#include "../resource.h"
#include "../zlib/zlib.h"
#include "../gx.h"
#include <Aygshell.h>

#include "conproc.h"

#define MINIMUM_WIN_MEMORY		(MINIMUM_MEMORY+1000000)
//#define MINIMUM_WIN_MEMORY		0x0880000
#define MAXIMUM_WIN_MEMORY		0x1000000

#define CONSOLE_ERROR_TIMEOUT	60.0	// # of seconds to wait on Sys_Error running
										//  dedicated before exiting
#define PAUSE_SLEEP		50				// sleep time on pause or minimization
#define NOT_FOCUS_SLEEP	20				// sleep time when not focus

int			starttime;
qboolean	ActiveApp;
qboolean	WinNT;

static double		pfreq;
static double		curtime = 0.0;
static double		lastcurtime = 0.0;
static int			lowshift;
qboolean			isDedicated;
static qboolean		sc_return_on_enter = false;
HANDLE				hinput, houtput;

static char			*tracking_tag = "Clams & Mooses";

static HANDLE	tevent;
static HANDLE	hFile;
static HANDLE	heventParent;
static HANDLE	heventChild;

void MaskExceptions (void);
void Sys_InitFloatTime (void);
void Sys_PushFPCW_SetHigh (void);
void Sys_PopFPCW (void);

volatile int					sys_checksum;

typedef int (*GXOPENDISPLAY)(HWND, DWORD);
typedef struct GXDisplayProperties (*GXGETDISPLAYPROPERTIES)(void);
typedef void * (*GXBEGINDRAW)(void);
typedef struct GXKeyList (*GXGETDEFAULTKEYS)(int);

struct GXDisplayProperties g_dispProps;
struct GXKeyList g_keyList;
int cbxPitch=1;
int cbyPitch=1;
int cbNewRowPitch240=1;
int cbNewColPitch320=1;

HINSTANCE dxDllLib;
GXOPENDISPLAY GXOpenDisplay_=NULL;
FARPROC GXCloseDisplay_;
GXGETDISPLAYPROPERTIES GXGetDisplayProperties_;
GXBEGINDRAW GXBeginDraw_;
FARPROC GXEndDraw_;
FARPROC GXOpenInput_;
FARPROC GXCloseInput_;
GXGETDEFAULTKEYS GXGetDefaultKeys_;


/*
================
Sys_PageIn
================
*/
void Sys_PageIn (void *ptr, int size)
{
	byte	*x;
	int		/*j, */m, n;

// touch all the memory to make sure it's there. The 16-page skip is to
// keep Win 95 from thinking we're trying to page ourselves in (we are
// doing that, of course, but there's no reason we shouldn't)
	x = (byte *)ptr;

	for (n=0 ; n<4 ; n++)
	{
		for (m=0 ; m<(size - 16 * 0x1000) ; m += 4)
		{
			sys_checksum += *(int *)&x[m];
			sys_checksum += *(int *)&x[m + 16 * 0x1000];
		}
	}
}


/*
===============================================================================

FILE IO

===============================================================================
*/

//Dan: This struct is used to support both stdio and gzio file IO.
struct SYS_HANDLE {
	FILE *f;
	int compressed;
};

#define	MAX_HANDLES		10
struct SYS_HANDLE sys_handles[MAX_HANDLES];

int		findhandle (void)
{
	int		i;
	
	for (i=1 ; i<MAX_HANDLES ; i++)
		if (!sys_handles[i].f)
			return i;
	Sys_Error ("out of handles");
	return -1;
}

/*
================
filelength
================
*/
//int filelength (FILE *f)
int filelength (struct SYS_HANDLE *sh)
{
	int		pos;
	int		end;

	if (sh->compressed) {
		pos = gztell((gzFile)sh->f);
		gzseek ((gzFile)sh->f, 0, SEEK_END);
		end = gztell ((gzFile)sh->f);
		gzseek ((gzFile)sh->f, pos, SEEK_SET);
	} else {
		pos = ftell (sh->f);
		fseek (sh->f, 0, SEEK_END);
		end = ftell (sh->f);
		fseek (sh->f, pos, SEEK_SET);
	}

	return end;
}

int Sys_FileOpenRead (char *path, int *hndl)
{
	FILE	*f;
	int		i, retval;
	int		len;
	int		compressed=false;


	//TODO: make sure a handle was returned
	i = findhandle ();

	len=strlen(path);
	if (len>3) {
		len--;
		if (((path[len]=='z')||(path[len]=='Z'))&&
			((path[len-1]=='g')||(path[len-1]=='G'))&&
			((path[len-2]=='.')||(path[len-2]  =='.')))
			compressed=true;
	}

	if (compressed)
		f = (FILE *)gzopen(path, "rb");
	else
		f = fopen(path, "rb");

	if (!f)
	{
		*hndl = -1;
		retval = -1;
	}
	else
	{
		sys_handles[i].f = f;
		sys_handles[i].compressed=compressed;

		*hndl = i;
		retval = filelength(&sys_handles[i]);
	}

	return retval;
}

int Sys_FileOpenWrite (char *path)
{
	FILE	*f;
	int		i;


	i = findhandle ();

	f = fopen(path, "wb");
	//Dan: TODO:
//	if (!f)
//		Sys_Error ("Error opening %s: %s", path,strerror(errno));
	sys_handles[i].f = f;
	sys_handles[i].compressed = false;
	

	return i;
}

void Sys_FileClose (int handle)
{
	if (sys_handles[handle].compressed)
		gzclose(sys_handles[handle].f);
	else
		fclose (sys_handles[handle].f);

	sys_handles[handle].f = NULL;
}

void Sys_FileSeek (int handle, int position)
{
	if (sys_handles[handle].compressed) {
		int curpos=gztell(sys_handles[handle].f);
		gzseek(sys_handles[handle].f, position-curpos, SEEK_CUR);
		//gzseek(sys_handles[handle].f, position, SEEK_SET);
	} else
		fseek (sys_handles[handle].f, position, SEEK_SET);
}

int Sys_FileRead (int handle, void *dest, int count)
{
	int		x;

	if (sys_handles[handle].compressed)
		x = gzread((gzFile) sys_handles[handle].f, dest, count);
	else
		x = fread (dest, 1, count, sys_handles[handle].f);
	return x;
}

int Sys_FileWrite (int handle, void *data, int count)
{
	int		x;

	if (!sys_handles[handle].compressed)
		x = fwrite (data, 1, count, sys_handles[handle].f);
	else //TODO: Support compression writing
		return 0;

	return x;
}

int	Sys_FileTime (char *path)
{
	FILE	*f;
	int		retval;

	f = fopen(path, "rb");

	if (f)
	{
		fclose(f);
		retval = 1;
	}
	else
	{
		retval = -1;
	}
	
	return retval;
}

void Sys_mkdir (char *path)
{
	//Dan:
#ifdef UNICODE
	TCHAR pathW[MAX_PATH];

	MultiByteToWideChar(CP_ACP, 0, path, -1, pathW, sizeof(pathW)/sizeof(TCHAR));
	CreateDirectory(pathW, NULL);
#else
	_mkdir (path);
#endif
}


/*
===============================================================================

SYSTEM IO

===============================================================================
*/

/*
================
Sys_MakeCodeWriteable
================
*/
void Sys_MakeCodeWriteable (unsigned long startaddr, unsigned long length)
{
	DWORD  flOldProtect;

	if (!VirtualProtect((LPVOID)startaddr, length, PAGE_READWRITE, &flOldProtect))
   		Sys_Error("Protection change failed\n");
}


//#ifndef _M_IX86

void Sys_SetFPCW (void)
{
}

void Sys_PushFPCW_SetHigh (void)
{
}

void Sys_PopFPCW (void)
{
}

void MaskExceptions (void)
{
}

//#endif

/*
================
Sys_Init
================
*/
void Sys_Init (void)
{
	LARGE_INTEGER	PerformanceFreq;
	unsigned int	lowpart, highpart;

	MaskExceptions ();
	Sys_SetFPCW ();

	if (!QueryPerformanceFrequency (&PerformanceFreq))
		Sys_Error ("No hardware timer available");

// get 32 out of the 64 time bits such that we have around
// 1 microsecond resolution
	lowpart = (unsigned int)PerformanceFreq.LowPart;
	highpart = (unsigned int)PerformanceFreq.HighPart;
	lowshift = 0;

	while (highpart || (lowpart > 2000000.0))
	{
		lowshift++;
		lowpart >>= 1;
		lowpart |= (highpart & 1) << 31;
		highpart >>= 1;
	}

	pfreq = 1.0 / (double)lowpart;

	Sys_InitFloatTime ();


	WinNT=false;
}


void Sys_Error (char *error, ...)
{
	va_list		argptr;
	char		text[1024], text2[1024];
	char		*text3 = "Press Enter to exit\n";
	char		*text4 = "***********************************\n";
	char		*text5 = "\n";
	DWORD		dummy;
	double		starttime;
	static int	in_sys_error0 = 0;
	static int	in_sys_error1 = 0;
	static int	in_sys_error2 = 0;
	static int	in_sys_error3 = 0;

	if (!in_sys_error3)
	{
		in_sys_error3 = 1;
	}

	va_start (argptr, error);
	vsprintf (text, error, argptr);
	va_end (argptr);

	if (isDedicated)
	{
		va_start (argptr, error);
		vsprintf (text, error, argptr);
		va_end (argptr);

		sprintf (text2, "ERROR: %s\n", text);
		WriteFile (houtput, text5, strlen (text5), &dummy, NULL);
		WriteFile (houtput, text4, strlen (text4), &dummy, NULL);
		WriteFile (houtput, text2, strlen (text2), &dummy, NULL);
		WriteFile (houtput, text3, strlen (text3), &dummy, NULL);
		WriteFile (houtput, text4, strlen (text4), &dummy, NULL);


		starttime = Sys_FloatTime ();
		sc_return_on_enter = true;	// so Enter will get us out of here

		while (!Sys_ConsoleInput () &&
				((Sys_FloatTime () - starttime) < CONSOLE_ERROR_TIMEOUT))
		{
		}
	}
	else
	{
		//Dan: Unicode conversion
		TCHAR textW[sizeof(text)];
		MultiByteToWideChar(CP_ACP, 0, text, -1, textW, sizeof(textW)/sizeof(TCHAR));
		// switch to windowed so the message box is visible, unless we already
		// tried that and failed
		if (!in_sys_error0)
		{
			in_sys_error0 = 1;
			VID_SetDefaultMode ();
			MessageBox(NULL, textW, _T("Quake Error"),
					   MB_OK | MB_SETFOREGROUND | MB_ICONSTOP);
		}
		else
		{
			MessageBox(NULL, textW, _T("Double Quake Error"),
					   MB_OK | MB_SETFOREGROUND | MB_ICONSTOP);
		}
	}

	if (!in_sys_error1)
	{
		in_sys_error1 = 1;
		Host_Shutdown ();
	}

// shut down QHOST hooks if necessary
	if (!in_sys_error2)
	{
		in_sys_error2 = 1;
	}

	exit (1);
}

void Sys_Printf (char *fmt, ...)
{
	va_list		argptr;
	char		text[1024];
	DWORD		dummy;
	
	if (isDedicated)
	{

		va_start (argptr,fmt);
		vsprintf (text, fmt, argptr);
		va_end (argptr);

		WriteFile(houtput, text, strlen (text), &dummy, NULL);	

	}
	else
	{
		unsigned short caca[100];

		va_start (argptr,fmt);
		vsprintf (text, fmt, argptr);
		va_end (argptr);

		
		wsprintf(caca,L"%S",text);


		OutputDebugString(caca);
	}
}

void Sys_Quit (void)
{

	Host_Shutdown();

	if (tevent)
		CloseHandle (tevent);

	exit (0);
}


/*
================
Sys_FloatTime
================
*/
double Sys_FloatTime (void)
{
	static int			sametimecount;
	static unsigned int	oldtime;
	static int			first = 1;
	LARGE_INTEGER		PerformanceCount;
	unsigned int		temp, t2;
	double				time;

	Sys_PushFPCW_SetHigh ();

	QueryPerformanceCounter (&PerformanceCount);

	temp = ((unsigned int)PerformanceCount.LowPart >> lowshift) |
		   ((unsigned int)PerformanceCount.HighPart << (32 - lowshift));

	if (first)
	{
		oldtime = temp;
		first = 0;
	}
	else
	{
	// check for turnover or backward time
		if ((temp <= oldtime) && ((oldtime - temp) < 0x10000000))
		{
			oldtime = temp;	// so we can't get stuck
		}
		else
		{
			t2 = temp - oldtime;

			time = (double)t2 * pfreq;
			oldtime = temp;

			curtime += time;

			if (curtime == lastcurtime)
			{
				sametimecount++;

				if (sametimecount > 100000)
				{
					curtime += 1.0;
					sametimecount = 0;
				}
			}
			else
			{
				sametimecount = 0;
			}

			lastcurtime = curtime;
		}
	}

	Sys_PopFPCW ();

    return curtime;
}


/*
================
Sys_InitFloatTime
================
*/
void Sys_InitFloatTime (void)
{
	int		j;

	Sys_FloatTime ();

	j = COM_CheckParm("-starttime");

	if (j)
	{
		curtime = (double) (Q_atof(com_argv[j+1]));
	}
	else
	{
		curtime = 0.0;
	}

	lastcurtime = curtime;
}


char *Sys_ConsoleInput (void)
{
	return NULL;
}

void Sys_Sleep (void)
{
	Sleep (1);
}

extern int vid_paused;

void Sys_SendKeyEvents (void)
{
    MSG        msg;

	for (;;) {
		while (PeekMessage (&msg, NULL, 0, 0, PM_NOREMOVE))
		{
		// we always update if there are any event, even if we're paused
			scr_skipupdate = 0;

			if (!GetMessage (&msg, NULL, 0, 0)) {
				Sys_Quit ();
				return;
			}
			//if (TranslateMessage (&msg));
      		DispatchMessage (&msg);
		}
		if (vid_paused) Sleep(250);
		else break;
	}
}


/*
==============================================================================

 WINDOWS CRAP

==============================================================================
*/


/*
==================
WinMain
==================
*/
void SleepUntilInput (int time)
{

	MsgWaitForMultipleObjects(1, &tevent, FALSE, time, QS_ALLINPUT);
}


/*
==================
WinMain
==================
*/
HINSTANCE	global_hInstance;
int			global_nCmdShow;
char		*argv[MAX_NUM_ARGVS];
static char *empty_string = "";
HWND		hwnd_dialog, hwndCB;

//This function (our main window function) is defined in vid_ppc.c
LRESULT CALLBACK MainWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

ATOM MyRegisterClass(HINSTANCE hInstance, LPTSTR szWindowClass)
{
	WNDCLASS	wc;

    wc.style			= CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc		= (WNDPROC) MainWndProc;
    wc.cbClsExtra		= 0;
    wc.cbWndExtra		= 0;
    wc.hInstance		= hInstance;
    wc.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_POCKETQUAKE));
    wc.hCursor			= 0;
    wc.hbrBackground	= (HBRUSH) GetStockObject(WHITE_BRUSH);
    wc.lpszMenuName		= 0;
    wc.lpszClassName	= szWindowClass;

	return RegisterClass(&wc);
}

HWND	hWnd = NULL;
double	win_time;

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	quakeparms_t	parms;
	double			oldtime, time;
	MEMORYSTATUS	lpBuffer;
	char	cwd[1024];
	int				t;
	RECT			rect;
	TCHAR			*curCmd;

	//Dan East: This contains untested UNICODE conversion of the command line args.
	//Because of the nature of Quake's handling of the command line string (never makes
	//a copy of the system provided parameters), the UNICODE conversion must allocate
	//strings to store the converted values.

    /* previous instances do not exist in Win32 */
    if (hPrevInstance)
        return 0;

	global_hInstance = hInstance;
	global_nCmdShow = nCmdShow;

	//If it is already running, then focus on the window
	hWnd = FindWindow(_T("POCKETQUAKE"), _T("Quake"));	
	if (hWnd) 
	{
		//Another Pocket Quake is already running, so give it focus and exit.
		SetForegroundWindow ((HWND) (((DWORD)hWnd) | 0x01));    
		return 0;
	} 

	MyRegisterClass(hInstance, _T("POCKETQUAKE"));
		
	hWnd = CreateWindow(_T("POCKETQUAKE"), _T("Quake"), WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);


	//Dan East: We dynamically load the Game API dll.  Why?  Because Windows CE error
	//messages reveal absolutely nothing to the user if a linked DLL can't be found.
	//Providing a detailed error message saves a lot of support effort.  We could
	//also provide non-game API support at runtime (use the window HDC), but the performance 
	//is so poor that I won't even let the user try it.  :)
	

	dxDllLib=LoadLibrary(_T("sd card\\quake\\gx.dll"));
	if (!dxDllLib)
	{
		dxDllLib=LoadLibrary(_T("\\SD Card\\quake\\gx.dll"));
	}

	if (dxDllLib) {
		int rc;
		GXOpenDisplay_=(GXOPENDISPLAY)GetProcAddress(dxDllLib, _T("?GXOpenDisplay@@YAHPAUHWND__@@K@Z"));
		GXCloseDisplay_=(FARPROC)GetProcAddress(dxDllLib, _T("?GXCloseDisplay@@YAHXZ"));
		GXGetDisplayProperties_=(GXGETDISPLAYPROPERTIES)GetProcAddress(dxDllLib, _T("?GXGetDisplayProperties@@YA?AUGXDisplayProperties@@XZ"));
		GXBeginDraw_=(GXBEGINDRAW)GetProcAddress(dxDllLib, _T("?GXBeginDraw@@YAPAXXZ"));
		GXEndDraw_=(FARPROC)GetProcAddress(dxDllLib, _T("?GXEndDraw@@YAHXZ"));
		GXOpenInput_=(FARPROC)GetProcAddress(dxDllLib, _T("?GXOpenInput@@YAHXZ"));
		GXCloseInput_=(FARPROC)GetProcAddress(dxDllLib, _T("?GXCloseInput@@YAHXZ"));
		GXGetDefaultKeys_=(GXGETDEFAULTKEYS)GetProcAddress(dxDllLib, _T("?GXGetDefaultKeys@@YA?AUGXKeyList@@H@Z"));

		rc=(*GXOpenDisplay_)(hWnd, GX_FULLSCREEN);
		if (rc) {
			g_dispProps=(*GXGetDisplayProperties_)();
			cbxPitch=g_dispProps.cbxPitch >> 1;	//We divide these values by two since we deal with only shorts
			cbyPitch=g_dispProps.cbyPitch >> 1;
			cbNewRowPitch240=cbyPitch-(240*cbxPitch);
			cbNewColPitch320=cbyPitch-(240*cbyPitch);
		}
		if (GXOpenInput_) rc=(*GXOpenInput_)();
		if (GXGetDefaultKeys_) (*GXGetDefaultKeys_)(GX_NORMALKEYS);
	} else {
#ifndef _X86_
		MessageBox(hWnd, _T("Unable to initialise Game API.\nYou need to place GX.DLL file in the \\windows\\ directory of this device."), _T("Pocket Quake"), MB_OK|MB_ICONSTOP);
		return 0;
#endif
	}
	

	lpBuffer.dwLength = sizeof(MEMORYSTATUS);
	GlobalMemoryStatus (&lpBuffer);

	strcpy(cwd,"/sd card/quake/");

	if (cwd[Q_strlen(cwd)-1] == '/')
		cwd[Q_strlen(cwd)-1] = 0;

	parms.basedir = cwd;
	parms.cachedir = NULL;

	parms.argc = 1;
	argv[0] = empty_string;

	while (*lpCmdLine!=_T('\0') && (parms.argc < MAX_NUM_ARGVS))
	{
		while (*lpCmdLine && *lpCmdLine==_T(' ')) //((*lpCmdLine <= 32) || (*lpCmdLine > 126)))
			lpCmdLine++;

		if (*lpCmdLine!=_T('\0'))
		{
			curCmd=lpCmdLine;

			while ((*lpCmdLine != _T('\0'))&& *lpCmdLine!=_T(' ')) //((*lpCmdLine > 32) && (*lpCmdLine <= 126)))
				lpCmdLine++;

			if (*lpCmdLine != _T('\0'))
			{
				*lpCmdLine = _T('\0');
				lpCmdLine++;
			}
			argv[parms.argc]=malloc(256);//_tcslen(curCmd)+1);
			WideCharToMultiByte(CP_ACP, 0, curCmd, -1, argv[parms.argc], _tcslen(curCmd)+1, NULL, NULL);
			parms.argc++;
		}
	}

	argv[parms.argc+1]=empty_string;;
	parms.argv = argv;

	COM_InitArgv (parms.argc, parms.argv);

	parms.argc = com_argc;
	parms.argv = com_argv;

	isDedicated = (COM_CheckParm ("-dedicated") != 0);

	if (!isDedicated)
	{
		hwnd_dialog = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, NULL);

		if (hwnd_dialog)
		{
			if (GetWindowRect (hwnd_dialog, &rect))
			{
				if (rect.left > (rect.top * 2))
				{
					SetWindowPos (hwnd_dialog, 0,
						(rect.left / 2) - ((rect.right - rect.left) / 2),
						rect.top, 0, 0,
						SWP_NOZORDER | SWP_NOSIZE);
				}
			}
			{
			//Dan: Here we center the dialog manually
			RECT dialogRect;
			int offset;

			GetWindowRect(hwnd_dialog, &dialogRect);

			offset=(GetSystemMetrics(SM_CXSCREEN)-(dialogRect.right-dialogRect.left))/2;
			dialogRect.right=offset+dialogRect.right-dialogRect.left;
			dialogRect.left=offset;
			offset=((160-(dialogRect.bottom-dialogRect.top))/2)+24;
			dialogRect.bottom=offset+dialogRect.bottom-dialogRect.top;
			dialogRect.top=offset;

			MoveWindow(hwnd_dialog, dialogRect.left, dialogRect.top, dialogRect.right-dialogRect.left, dialogRect.bottom-dialogRect.top, FALSE);
			ShowWindow (hwnd_dialog, SW_SHOW);
			UpdateWindow (hwnd_dialog);
			SetForegroundWindow (hwnd_dialog);
			}
		}
	}

//Dan: Ignore the following, see my comment a bit further down.

// take the greater of all the available memory or half the total memory,
// but at least 8 Mb and no more than 16 Mb, unless they explicitly
// request otherwise
	parms.memsize = lpBuffer.dwAvailPhys;

	if (parms.memsize < MINIMUM_WIN_MEMORY)
		parms.memsize = MINIMUM_WIN_MEMORY;

	if ((unsigned int) parms.memsize < (lpBuffer.dwTotalPhys >> 1))
		parms.memsize = lpBuffer.dwTotalPhys >> 1;

	if (parms.memsize > MAXIMUM_WIN_MEMORY)
		parms.memsize = MAXIMUM_WIN_MEMORY;

	if (COM_CheckParm ("-heapsize"))
	{
		t = COM_CheckParm("-heapsize") + 1;

		if (t < com_argc)
			parms.memsize = Q_atoi (com_argv[t]) * 1024;
	}

	//Dan: We take 1 MB more than the minimum needed by Quake for its heap
	//parms.memsize=MINIMUM_MEMORY+1000000;
	while (parms.memsize >= MINIMUM_MEMORY) {
		parms.membase = malloc (parms.memsize);
		if (!parms.membase) parms.memsize-=500000;
		else break;
	}

	if (!parms.membase)
		Sys_Error ("Not enough memory free; check disk space\n");

	//Dan: The original purpose of the following was to access all allocated mem, 
	//in order to force Windows to really provide it all up front. This is not necessary
	//with Windows CE (it just slows down the startup).
	//Sys_PageIn (parms.membase, parms.memsize);

	tevent = CreateEvent(NULL, FALSE, FALSE, NULL);

	if (!tevent)
		Sys_Error ("Couldn't create event");

	Sys_Init ();

	Sys_Printf ("Host_Init\n");
	Host_Init (&parms);

	oldtime = Sys_FloatTime ();

    /* main window message loop */
	while (1)
	{
		if (isDedicated)
		{
			win_time = Sys_FloatTime ();
			time = win_time - oldtime;

			while (time < sys_ticrate.value )
			{
				Sys_Sleep();
				win_time = Sys_FloatTime ();
				time = win_time - oldtime;
			}

			Host_Frame ((float)time);
		}
		else
		{
			if (!vid_paused) {
				if (cl.paused) {
					//Pocket Quake is paused, so sleep.
					Sleep(100);
					scr_skipupdate = 1;	// no point in bothering to draw (Dan: we don't render, we still blit to the display)
				}
				Host_Frame ((float)time);
			} else {
				//Pocket Quake is not active, so we process window events then sleep.
				Sys_SendKeyEvents();
				Sleep(100);		//We don't draw the frame if we aren't active.  Otherwise when
								//using direct screen access we will trash the active app's
								//display.
			}


			win_time = Sys_FloatTime ();
			time = win_time - oldtime;
		}

		oldtime = win_time;
	}

	//Dan: Deallocate the converted strings.
	//Dan: TODO: This never gets executed.  Clean it up elsewhere.
	while (parms.argc--)
		free(argv[parms.argc]);

    /* return success of application */
    return TRUE;
}

//Dan:
void Sys_HighFPPrecision (void)
{
}

void Sys_LowFPPrecision (void)
{
}
