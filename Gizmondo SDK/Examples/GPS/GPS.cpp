///////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2004 Gizmondo Ltd and
// Copyright (C) 2004 Intrinsyc Europe Ltd.
// All rights reserved.
// No use or disclosure of this information in any form without the
// written permission of the author Intrinsyc Europe Ltd.
// http://www.intrinsyc.com
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
// FILE INFORMATION
//
//   Project: Gizmondo Terminal WinCE Port
//      Unit: Developer Sample
// $Workfile: GPS.cpp $
// $Revision: 1 $
//     $Date: 21/10/04 12:08 $
//
// DESCRIPTION : Developer Sample : Demonstrates reading GPS location
//
///////////////////////////////////////////////////////////////////////////////
//
// MODIFICATION HISTORY
//
// $Log: /Gizmondo/Apps/Developer Samples/GPS/GPS.cpp $
// 
// 1     21/10/04 12:08 Deanw
// Created
// 
// 
// $NoKeywords: $
//
///////////////////////////////////////////////////////////////////////////////


// GPS.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "GPS.h"
#include <commctrl.h>
#include "GPSDefs.h"

#define MAX_LOADSTRING 100
#define MAX_GPS_INSTANCES 10
#define SECONDS_PER_DAY			(3600*24)

#undef UTC_EPOCH
#define UTC_EPOCH				2440588

#define FORCE_ONSTATE	L"PowerManager/ActivityTimer/UserActivity"	// Asking shell to keep system full on

// Global Variables:
HINSTANCE			hInst;			// The current instance
HWND				hwndCB;			// The command bar handle

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass	(HINSTANCE, LPTSTR);
BOOL				InitInstance	(HINSTANCE, int);
LRESULT CALLBACK	WndProc			(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About			(HWND, UINT, WPARAM, LPARAM);
static void FormatGPSData();

static HANDLE g_handle;
static TCHAR szMessage[2048];
static int iTimer;
HANDLE m_onEvent;


int WINAPI WinMain(	HINSTANCE hInstance,
					HINSTANCE hPrevInstance,
					LPTSTR    lpCmdLine,
					int       nCmdShow)
{
	MSG msg;
	HACCEL hAccelTable;

	m_onEvent = OpenEvent(EVENT_ALL_ACCESS, FALSE, FORCE_ONSTATE); 


	// Open GPS driver
	g_handle = CreateFile(L"GPS1:", GENERIC_READ,
							0, NULL,
							OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL,
							NULL);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_GPS);

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) 
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return msg.wParam;
}

//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    It is important to call this function so that the application 
//    will get 'well formed' small icons associated with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance, LPTSTR szWindowClass)
{
	WNDCLASS	wc;

    wc.style			= CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc		= (WNDPROC) WndProc;
    wc.cbClsExtra		= 0;
    wc.cbWndExtra		= 0;
    wc.hInstance		= hInstance;
    wc.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GPS));
    wc.hCursor			= 0;
    wc.hbrBackground	= (HBRUSH) GetStockObject(WHITE_BRUSH);
    wc.lpszMenuName		= 0;
    wc.lpszClassName	= szWindowClass;

	return RegisterClass(&wc);
}

//
//  FUNCTION: InitInstance(HANDLE, int)
//
//  PURPOSE: Saves instance handle and creates main window
//
//  COMMENTS:
//
//    In this function, we save the instance handle in a global variable and
//    create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND	hWnd;
	TCHAR	szTitle[MAX_LOADSTRING];			// The title bar text
	TCHAR	szWindowClass[MAX_LOADSTRING];		// The window class name

	hInst = hInstance;		// Store instance handle in our global variable
	// Initialize global strings
	LoadString(hInstance, IDC_GPS, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance, szWindowClass);

	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	hWnd = CreateWindow(szWindowClass, szTitle, WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{	
		return FALSE;
	}

	iTimer = SetTimer(hWnd, 1,1000, NULL);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	if (hwndCB)
		CommandBar_Show(hwndCB, TRUE);

	return TRUE;
}

//
//  FUNCTION: WndProc(HWND, unsigned, WORD, LONG)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	int wmId, wmEvent;
	PAINTSTRUCT ps;

	switch (message) 
	{
		case WM_COMMAND:
			wmId    = LOWORD(wParam); 
			wmEvent = HIWORD(wParam); 
			// Parse the menu selections:
			switch (wmId)
			{
				case IDM_HELP_ABOUT:
				   DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
				   break;
				case IDM_FILE_EXIT:
				   DestroyWindow(hWnd);
				   break;
				default:
				   return DefWindowProc(hWnd, message, wParam, lParam);
			}
			break;
		case WM_KEYDOWN:
			if ( wParam == VK_F1)
			{
				KillTimer(hWnd, iTimer);
				CloseHandle(g_handle);
				DestroyWindow(hWnd);
			}
			break;
		case WM_TIMER:			
			SetEvent(m_onEvent);
			FormatGPSData();
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case WM_CREATE:
			//hwndCB = CommandBar_Create(hInst, hWnd, 1);			
			//CommandBar_InsertMenubar(hwndCB, hInst, IDM_MENU, 0);
			//CommandBar_AddAdornments(hwndCB, 0, 0);
			break;
		case WM_PAINT:
			RECT rt;
			
			hdc = BeginPaint(hWnd, &ps);
			GetClientRect(hWnd, &rt);
			DrawText(hdc, szMessage, _tcslen(szMessage), &rt, DT_LEFT);
			EndPaint(hWnd, &ps);
			break;
		case WM_DESTROY:
			CommandBar_Destroy(hwndCB);
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}

// Mesage handler for the About box.
LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	RECT rt, rt1;
	int DlgWidth, DlgHeight;	// dialog width and height in pixel units
	int NewPosX, NewPosY;

	switch (message)
	{
		case WM_INITDIALOG:
			// trying to center the About dialog
			if (GetWindowRect(hDlg, &rt1)) {
				GetClientRect(GetParent(hDlg), &rt);
				DlgWidth	= rt1.right - rt1.left;
				DlgHeight	= rt1.bottom - rt1.top ;
				NewPosX		= (rt.right - rt.left - DlgWidth)/2;
				NewPosY		= (rt.bottom - rt.top - DlgHeight)/2;
				
				// if the About box is larger than the physical screen 
				if (NewPosX < 0) NewPosX = 0;
				if (NewPosY < 0) NewPosY = 0;
				SetWindowPos(hDlg, 0, NewPosX, NewPosY,
					0, 0, SWP_NOZORDER | SWP_NOSIZE);
			}
			return TRUE;

		case WM_COMMAND:
			if ((LOWORD(wParam) == IDOK) || (LOWORD(wParam) == IDCANCEL))
			{
				EndDialog(hDlg, LOWORD(wParam));
				return TRUE;
			}
			break;
	}
    return FALSE;
}

// Get current GPS info
//
BOOL DriverGetGeofenceLocation(LATEST_GPS_DATA* pPacket)
{
	DWORD read=0;
	BOOL result=FALSE;

	if (!g_handle)
		return result;

	// read location
	if (ReadFile(g_handle, pPacket, sizeof(*pPacket), &read, NULL))
	{
		if (read != sizeof(*pPacket))
		{
			RETAILMSG(1, (TEXT("GPS::Update Read incorrect number of bytes! \r\n")));
			result = FALSE;
		}
		else
		{
			result = TRUE;				
		}
	}
	else
	{
#ifndef _X86_
		RETAILMSG(1, (TEXT("GPS::Update Failed! \r\n")));
#endif
		result = FALSE;
	}
	return result;
}

INT32 GregorianDateToUtcDay(WORD wYear, WORD wMonth, WORD wDay)
{

	// Magic formula - see http://www.hermetic.ch/cal_stud/jdn.htm
	return (( 1461 * ( wYear + 4800 + ( wMonth - 14 ) / 12 ) ) / 4 +
          ( 367 * ( wMonth - 2 - 12 * ( ( wMonth - 14 ) / 12 ) ) ) / 12 -
          ( 3 * ( ( wYear + 4900 + ( wMonth - 14 ) / 12 ) / 100 ) ) / 4 +
          wDay - 32075 - UTC_EPOCH);
}

void UtcDayToGregorianDate(INT32 iDayNo, WORD *pwYear, WORD *pwMonth, WORD *pwDay)
{
	// Magic formula - see http://www.hermetic.ch/cal_stud/jdn.htm
	INT32 l, n, i, j;
	l = iDayNo + 68569 + UTC_EPOCH;
    n = ( 4 * l ) / 146097;
    l = l - ( 146097 * n + 3 ) / 4;
    i = ( 4000 * ( l + 1 ) ) / 1461001;
    l = l - ( 1461 * i ) / 4 + 31;
    j = ( 80 * l ) / 2447;
    *pwDay = (WORD)(l - ( 2447 * j ) / 80);
    l = j / 11;
    *pwMonth = (WORD)(j + 2 - ( 12 * l ));
    *pwYear = (WORD)(100 * ( n - 49 ) + i + l);
}


UTCTIME SystemTimeToUTCTime(SYSTEMTIME SystemTime)
{
	UTCTIME UtcTime;

	UtcTime = GregorianDateToUtcDay(SystemTime.wYear, SystemTime.wMonth, SystemTime.wDay);
	UtcTime *= SECONDS_PER_DAY;	// Convert from day number to seconds
	// Now add on the hours minutes and seconds
	UtcTime = UtcTime + (SystemTime.wHour * 3600) + (SystemTime.wMinute * 60) + 
		(SystemTime.wSecond);

	return UtcTime;
}

SYSTEMTIME UTCTimeToSystemTime(UTCTIME Timestamp)
{
	SYSTEMTIME SysTime;

	memset(&SysTime, 0, sizeof(SYSTEMTIME));

	// First extract the day, month and year
	UtcDayToGregorianDate(Timestamp/SECONDS_PER_DAY, &SysTime.wYear, &SysTime.wMonth, &SysTime.wDay);
	// Now fill in the hours, minutes and seconds.
	Timestamp %= SECONDS_PER_DAY;

	SysTime.wSecond = Timestamp % 60;
	Timestamp /= 60;

	SysTime.wMinute = Timestamp % 60;
	Timestamp /= 60;

	SysTime.wHour = Timestamp % 24;
	
	return SysTime;
}

UTCTIME CurrentUTCTime(void)
{
	SYSTEMTIME SystemTime;

	GetSystemTime(&SystemTime);
	// Convert the time into a timestamp
	return SystemTimeToUTCTime(SystemTime);
}

void FormatGPSData()
{
	TCHAR timebuf[40];
	TCHAR datebuf[40];
	TCHAR systimebuf[40];
	TCHAR sysdatebuf[40];
	TCHAR tstamptime[40];
	TCHAR tstampdate[40];
	LATEST_GPS_DATA Packet;

	DriverGetGeofenceLocation(&Packet);

	SYSTEMTIME TStamp = UTCTimeToSystemTime(Packet.Timestamp);
	SYSTEMTIME CurrentTime;
	GetSystemTime(&CurrentTime);

	GetTimeFormat(LOCALE_SYSTEM_DEFAULT, 0, &CurrentTime, NULL, timebuf, sizeof(timebuf));
	GetDateFormat(NULL, DATE_LONGDATE, &CurrentTime, NULL, datebuf, sizeof(datebuf));

	GetTimeFormat(LOCALE_SYSTEM_DEFAULT, 0, NULL, NULL, systimebuf, sizeof(systimebuf));
	GetDateFormat(NULL, DATE_LONGDATE, NULL, NULL, sysdatebuf, sizeof(sysdatebuf));

	GetTimeFormat(LOCALE_SYSTEM_DEFAULT, 0, &TStamp, NULL, tstamptime, sizeof(tstamptime));
	GetDateFormat(NULL, DATE_LONGDATE, &TStamp, NULL, tstampdate, sizeof(tstampdate));
		
	_stprintf(szMessage,_T(
"UTC date/time: %s %s\n\r\
Local date/time: %s %s\n\r\
Fix/Val: %d/%x on %s %s\n\r\
Lat: %d.%07d, Lng: %d.%07d, Err: %d, Sats: %d\n\r\
[01] ID: %02d Az: %03d, El:%02d State: %02x C/No: %02d Used: %d\n\r\
[02] ID: %02d Az: %03d, El:%02d State: %02x C/No: %02d Used: %d\n\r\
[03] ID: %02d Az: %03d, El:%02d State: %02x C/No: %02d Used: %d\n\r\
[04] ID: %02d Az: %03d, El:%02d State: %02x C/No: %02d Used: %d\n\r\
[05] ID: %02d Az: %03d, El:%02d State: %02x C/No: %02d Used: %d\n\r\
[06] ID: %02d Az: %03d, El:%02d State: %02x C/No: %02d Used: %d\n\r\
[07] ID: %02d Az: %03d, El:%02d State: %02x C/No: %02d Used: %d\n\r\
[08] ID: %02d Az: %03d, El:%02d State: %02x C/No: %02d Used: %d\n\r\
[09] ID: %02d Az: %03d, El:%02d State: %02x C/No: %02d Used: %d\n\r\
[10] ID: %02d Az: %03d, El:%02d State: %02x C/No: %02d Used: %d\n\r\
[11] ID: %02d Az: %03d, El:%02d State: %02x C/No: %02d Used: %d\n\r\
[12] ID: %02d Az: %03d, El:%02d State: %02x C/No: %02d Used: %d\n\r\
"),
			datebuf,
			timebuf,
			sysdatebuf,
			systimebuf,
			Packet.FixSincePowerUp,
			Packet.FixValidated,
			tstampdate,
			tstamptime,
			Packet.Latitude / LAT_LONG_RESOLUTION,
			abs(Packet.Latitude % LAT_LONG_RESOLUTION),
			Packet.Longitude / LAT_LONG_RESOLUTION,
			abs(Packet.Longitude % LAT_LONG_RESOLUTION),
			Packet.EstHorizError,
			Packet.NumSatsVisible,
			Packet.VisibleSats[0].SatVehicleID,
			Packet.VisibleSats[0].Azimuth/2*3,
			Packet.VisibleSats[0].Elevation/2,
			Packet.VisibleSats[0].State,
			Packet.VisibleSats[0].C_NO,
			Packet.VisibleSats[0].InFix,
			Packet.VisibleSats[1].SatVehicleID,
			Packet.VisibleSats[1].Azimuth/2*3,
			Packet.VisibleSats[1].Elevation/2,
			Packet.VisibleSats[1].State,
			Packet.VisibleSats[1].C_NO,
			Packet.VisibleSats[1].InFix,
			Packet.VisibleSats[2].SatVehicleID,
			Packet.VisibleSats[2].Azimuth/2*3,
			Packet.VisibleSats[2].Elevation/2,
			Packet.VisibleSats[2].State,
			Packet.VisibleSats[2].C_NO,
			Packet.VisibleSats[2].InFix,
			Packet.VisibleSats[3].SatVehicleID,
			Packet.VisibleSats[3].Azimuth/2*3,
			Packet.VisibleSats[3].Elevation/2,
			Packet.VisibleSats[3].State,
			Packet.VisibleSats[3].C_NO,
			Packet.VisibleSats[3].InFix,
			Packet.VisibleSats[4].SatVehicleID,
			Packet.VisibleSats[4].Azimuth/2*3,
			Packet.VisibleSats[4].Elevation/2,
			Packet.VisibleSats[4].State,
			Packet.VisibleSats[4].C_NO,
			Packet.VisibleSats[4].InFix,
			Packet.VisibleSats[5].SatVehicleID,
			Packet.VisibleSats[5].Azimuth/2*3,
			Packet.VisibleSats[5].Elevation/2,
			Packet.VisibleSats[5].State,
			Packet.VisibleSats[5].C_NO,
			Packet.VisibleSats[5].InFix,
			Packet.VisibleSats[6].SatVehicleID,
			Packet.VisibleSats[6].Azimuth/2*3,
			Packet.VisibleSats[6].Elevation/2,
			Packet.VisibleSats[6].State,
			Packet.VisibleSats[6].C_NO,
			Packet.VisibleSats[6].InFix,
			Packet.VisibleSats[7].SatVehicleID,
			Packet.VisibleSats[7].Azimuth/2*3,
			Packet.VisibleSats[7].Elevation/2,
			Packet.VisibleSats[7].State,
			Packet.VisibleSats[7].C_NO,
			Packet.VisibleSats[7].InFix,
			Packet.VisibleSats[8].SatVehicleID,
			Packet.VisibleSats[8].Azimuth/2*3,
			Packet.VisibleSats[8].Elevation/2,
			Packet.VisibleSats[8].State,
			Packet.VisibleSats[8].C_NO,
			Packet.VisibleSats[8].InFix,
			Packet.VisibleSats[9].SatVehicleID,
			Packet.VisibleSats[9].Azimuth/2*3,
			Packet.VisibleSats[9].Elevation/2,
			Packet.VisibleSats[9].State,
			Packet.VisibleSats[9].C_NO,
			Packet.VisibleSats[9].InFix,
			Packet.VisibleSats[10].SatVehicleID,
			Packet.VisibleSats[10].Azimuth/2*3,
			Packet.VisibleSats[10].Elevation/2,
			Packet.VisibleSats[10].State,
			Packet.VisibleSats[10].C_NO,
			Packet.VisibleSats[10].InFix,
			Packet.VisibleSats[11].SatVehicleID,
			Packet.VisibleSats[11].Azimuth/2*3,
			Packet.VisibleSats[11].Elevation/2,
			Packet.VisibleSats[11].State,
			Packet.VisibleSats[11].C_NO,
			Packet.VisibleSats[11].InFix
			);
}