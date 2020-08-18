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
// $Workfile: SysMessages.cpp $
// $Revision: 1 $
//     $Date: 21/10/04 12:11 $
//
// DESCRIPTION : Developer sample : Demonstrates Shell Windows Messages
//
///////////////////////////////////////////////////////////////////////////////
//
// MODIFICATION HISTORY
//
// $Log: /Gizmondo/Apps/Developer Samples/SysMessages/SysMessages.cpp $
// 
// 1     21/10/04 12:11 Deanw
// Created
// 
// 
// $NoKeywords: $
//
///////////////////////////////////////////////////////////////////////////////

// SysMessages.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "SysMessages.h"
#include <commctrl.h>
#include "oeminc.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE			hInst;			// The current instance
HWND				hwndCB;			// The command bar handle
HWND				hWndApp;

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass	(HINSTANCE, LPTSTR);
BOOL				InitInstance	(HINSTANCE, int);
LRESULT CALLBACK	WndProc			(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About			(HWND, UINT, WPARAM, LPARAM);

UINT lowBatteryMsg;
UINT criticalBatteryMsg;
UINT switchToShellMsg;
UINT gprsConnectMsg; 
UINT gprsStatusMsg; 
UINT getStatusMsg;
UINT statusMsg;
UINT smsMsg;

BOOL gbFlightMode = FALSE;;
BOOL gbGPSState = FALSE;
BOOL gbGSMState = FALSE;
BOOL gbBTState = FALSE;
int giInternetMMSConnected=0;
int giActiveSyncConnected=0;
BOOL bGPRSConnected=FALSE;
BOOL bAlreadyInternetMMS = FALSE;
BOOL bAlreadyActiveSync = FALSE;
int iLowBatt;
int iCritBatt;
int iSMS = 0;
bool SDCardInserted = true;

void UpdateDisplay(HDC hdc);

#define HT 12

DWORD __cdecl SDCardThreadProc(void *aaaa)
{
	DWORD ret;
	HANDLE Events[2];

	Events[0] = CreateEvent(NULL, FALSE, FALSE, SDMMC_INSERT_EVENT);
	Events[1] = CreateEvent(NULL, FALSE, FALSE, SDMMC_REMOVE_EVENT);

	while (1)
	{
		ret = WaitForMultipleObjects(2, Events, FALSE, INFINITE);
		if (ret == WAIT_OBJECT_0)
		{
			SDCardInserted = true;
		}
		if (ret == WAIT_OBJECT_0 + 1)
		{
			SDCardInserted = false;
		}
		InvalidateRect(hWndApp, NULL, TRUE);
	}
}


int WINAPI WinMain(	HINSTANCE hInstance,
					HINSTANCE hPrevInstance,
					LPTSTR    lpCmdLine,
					int       nCmdShow)
{
	MSG msg;
	HACCEL hAccelTable;

	// Register windows messages
	lowBatteryMsg = RegisterWindowMessage(LOWBATERY_MSG);
	criticalBatteryMsg = RegisterWindowMessage(CRITICALBATERY_MSG);
	switchToShellMsg = RegisterWindowMessage(SWITCHTOSHELL_MSG);
	gprsConnectMsg = RegisterWindowMessage(GPRS_CONNECT_MSG);
	gprsStatusMsg = RegisterWindowMessage(GPRS_STATUS_MSG);
	getStatusMsg = RegisterWindowMessage(GT_GETSTATUS_MSG);
	statusMsg = RegisterWindowMessage(GT_STATUS_MSG);
	smsMsg = RegisterWindowMessage(SMS_MSG);

	CloseHandle(CreateThread(NULL, 0, SDCardThreadProc, NULL, NULL, NULL));

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_SYSMESSAGES);

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
    wc.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SYSMESSAGES));
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
	TCHAR	szTitle[MAX_LOADSTRING];			// The title bar text
	TCHAR	szWindowClass[MAX_LOADSTRING];		// The window class name

	hInst = hInstance;		// Store instance handle in our global variable
	// Initialize global strings
	LoadString(hInstance, IDC_SYSMESSAGES, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance, szWindowClass);

	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	hWndApp = CreateWindow(szWindowClass, szTitle, WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	if (!hWndApp)
	{	
		return FALSE;
	}

	ShowWindow(hWndApp, nCmdShow);
	UpdateWindow(hWndApp);
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
	TCHAR* sz1=L"Left Shoulder - Switch to shell";
	TCHAR* sz2=L"Piano 1 - Get Status ";
	TCHAR* sz3=L"Piano 2 - GPRS disconnect from MMS/Internet  ";
	TCHAR* sz4=L"Piano 3 - Connect to internet";
	TCHAR* sz5=L"East - Quit";

	TCHAR temp[256];
	wsprintf(temp, L"hwnd %08x message %08x wParam %08x lParam %08x\r\n", hWnd, message, wParam, lParam);
	OutputDebugString(temp);

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
			switch(wParam)
			{
				case VK_TAB:
					// Send message to shell to switch to full screen mode
					SendMessage(HWND_BROADCAST, switchToShellMsg,1,0);	
					break;
				case VK_F1:
					// Request status
					::SendMessage(HWND_BROADCAST, getStatusMsg,0,0);					
					break;
				case VK_F2:
					// GPRS disconnect from MMS/Internet
					::SendMessage(HWND_BROADCAST, gprsConnectMsg,0,0);	
					break;
				case VK_F3:
					// GPRS Connect to internet
					::SendMessage(HWND_BROADCAST, gprsConnectMsg,1,0);
					break;
				case VK_SPACE:
					DestroyWindow(hWnd);
					break;

			}
			break;
		case WM_CREATE:
			break;
		case WM_PAINT:
			RECT rt;
			hdc = BeginPaint(hWnd, &ps);
			GetClientRect(hWnd, &rt);
		
			//DrawText(hdc, sz1, _tcslen(sz1), &rt, 
			//	DT_SINGLELINE | DT_VCENTER | DT_CENTER);

			ExtTextOut(hdc,0,0,0,NULL,sz1,_tcslen(sz1),0);
			ExtTextOut(hdc,0,HT*1,0,NULL,sz2,_tcslen(sz2),0);
			ExtTextOut(hdc,0,HT*2,0,NULL,sz3,_tcslen(sz3),0);
			ExtTextOut(hdc,0,HT*3,0,NULL,sz4,_tcslen(sz4),0);
			ExtTextOut(hdc,0,HT*4,0,NULL,sz5,_tcslen(sz5),0);
                    
			UpdateDisplay(hdc);		

			EndPaint(hWnd, &ps);
			break;
	
		case WM_DESTROY:
			CommandBar_Destroy(hwndCB);
			PostQuitMessage(0);
			break;
		default:
			
			// GT_STATUS
			if (message == statusMsg)
			{
				if (wParam & (1<<0))
					gbFlightMode = TRUE;
				else
					gbFlightMode = FALSE;;

				if (wParam & (1<<1))
					gbGPSState = TRUE;
				else
					gbGPSState = FALSE;

				if (wParam & (1<<2))
					gbGSMState = TRUE;
				else
					gbGSMState = FALSE;
		
				if (wParam & (1<<3))
					gbBTState = TRUE;
				else
					gbBTState = FALSE;

				if (wParam & (1<<4))
					giInternetMMSConnected++;

				if (wParam & (1<<6))
					giActiveSyncConnected++;			
				InvalidateRect(hWnd, NULL, TRUE);
			}
			// GPRS Status
			else if (message == gprsStatusMsg)
			{	
				if (wParam == 8092)
					bGPRSConnected = TRUE;
				else if (wParam == 8093)
					bGPRSConnected = FALSE;

				if (lParam & (1<<0))
					bAlreadyInternetMMS = TRUE;
				else
					bAlreadyInternetMMS = FALSE;

				if (lParam & (1<<2))
					bAlreadyActiveSync = TRUE;
				else
					bAlreadyActiveSync = FALSE;
				InvalidateRect(hWnd, NULL, TRUE);
			}
			// SMS message
			else if (message == smsMsg)
			{
				iSMS++;
				InvalidateRect(hWnd, NULL, TRUE);			
			}
			else if (message == lowBatteryMsg)
			{
				iLowBatt++;
				InvalidateRect(hWnd, NULL, TRUE);			
			}
			else if (message == criticalBatteryMsg)
			{
				iCritBatt++;
				InvalidateRect(hWnd, NULL, TRUE);			
			}
			else
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


void UpdateDisplay(HDC hdc)
{
	TCHAR szTemp[MAX_PATH];
	TCHAR* szTemp1 = NULL;

	if (gbFlightMode)
		szTemp1 = L"Flight Mode : ON";
	else
		szTemp1 = L"Flight Mode : OFF";
	ExtTextOut(hdc,0,HT*5,0,NULL,szTemp1,_tcslen(szTemp1),0);
     
	if (gbGPSState)
		szTemp1 = L"GPS State : ON";
	else
		szTemp1 = L"GPS State : OFF";
	ExtTextOut(hdc,0,HT*6,0,NULL,szTemp1,_tcslen(szTemp1),0);
     
	if (gbGSMState)
		szTemp1 = L"GSM State : ON";
	else
		szTemp1 = L"GSM State : OFF";
	ExtTextOut(hdc,0,HT*7,0,NULL,szTemp1,_tcslen(szTemp1),0);

	if (gbBTState)
		szTemp1 = L"BT State : ON";
	else
		szTemp1 = L"BT State : OFF";
	ExtTextOut(hdc,0,HT*8,0,NULL,szTemp1,_tcslen(szTemp1),0);
			
	_stprintf(szTemp,_T("Int/MMS GPRS Cnt :%d"),giInternetMMSConnected);
	ExtTextOut(hdc,0,HT*9,0,NULL,szTemp,_tcslen(szTemp),0);

	_stprintf(szTemp,_T("Active Sync Cnt :%d"),giActiveSyncConnected);
	ExtTextOut(hdc,0,HT*10,0,NULL,szTemp,_tcslen(szTemp),0);

	if (bGPRSConnected)
		szTemp1 = L"GPRS Connected";
	else
		szTemp1 = L"GPRS Disconnected";
	ExtTextOut(hdc,0,HT*11,0,NULL,szTemp1,_tcslen(szTemp1),0);

	if (bAlreadyInternetMMS)
		szTemp1 = L"Internet MMS already Connected";
	else
		szTemp1 = L"Internet MMS not already Connected";
	ExtTextOut(hdc,0,HT*12,0,NULL,szTemp1,_tcslen(szTemp1),0);

	if (bAlreadyActiveSync)
		szTemp1 = L"Active Sync already Connected";
	else
		szTemp1 = L"Active Sync not already Connected";
	ExtTextOut(hdc,0,HT*13,0,NULL,szTemp1,_tcslen(szTemp1),0);

	_stprintf(szTemp,_T("SMS Message count :%d"),iSMS);
	ExtTextOut(hdc,0,HT*14,0,NULL,szTemp,_tcslen(szTemp),0);

	_stprintf(szTemp,_T("Low battery Message count :%d"),iLowBatt);
	ExtTextOut(hdc,0,HT*15,0,NULL,szTemp,_tcslen(szTemp),0);

	_stprintf(szTemp,_T("Critical battery Message count :%d"),iCritBatt);
	ExtTextOut(hdc,0,HT*16,0,NULL,szTemp,_tcslen(szTemp),0);

	_stprintf(szTemp,_T("SDCard Inserted :%d"), SDCardInserted);
	ExtTextOut(hdc,0,HT*17,0,NULL,szTemp,_tcslen(szTemp),0);
}