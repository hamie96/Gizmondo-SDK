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
// $Workfile: Keys.cpp $
// $Revision: 1 $
//     $Date: 21/10/04 12:09 $
//
// DESCRIPTION : Developer sample : Demonstrates reading front panel keys
//
///////////////////////////////////////////////////////////////////////////////
//
// MODIFICATION HISTORY
//
// $Log: /Gizmondo/Apps/Developer Samples/Keys/Keys.cpp $
// 
// 1     21/10/04 12:09 Deanw
// Created
// 
// 
// $NoKeywords: $
//
///////////////////////////////////////////////////////////////////////////////

// Keys.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Keys.h"
#include <commctrl.h>

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE			hInst;			// The current instance
HWND				hwndCB;			// The command bar handle

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass	(HINSTANCE, LPTSTR);
BOOL				InitInstance	(HINSTANCE, int);
LRESULT CALLBACK	WndProc			(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About			(HWND, UINT, WPARAM, LPARAM);

BOOL bVK_UP=FALSE;
BOOL bVK_RIGHT=FALSE;
BOOL bVK_DOWN=FALSE;
BOOL bVK_LEFT=FALSE;
BOOL bVK_CONTROL=FALSE;
BOOL bVK_SHIFT=FALSE;
BOOL bVK_RETURN=FALSE;
BOOL bVK_LSHIFT=FALSE;
BOOL bVK_TAB=FALSE;
BOOL bVK_ESCAPE=FALSE;
BOOL bVK_F1=FALSE;
BOOL bVK_F2=FALSE;
BOOL bVK_F3=FALSE;
BOOL bVK_F4=FALSE;
BOOL bVK_F11=FALSE;
BOOL bVK_SPACE = FALSE;

#define HT 12

int WINAPI WinMain(	HINSTANCE hInstance,
					HINSTANCE hPrevInstance,
					LPTSTR    lpCmdLine,
					int       nCmdShow)
{
	MSG msg;
	HACCEL hAccelTable;

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_KEYS);

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
    wc.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_KEYS));
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
	LoadString(hInstance, IDC_KEYS, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance, szWindowClass);

	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	hWnd = CreateWindow(szWindowClass, szTitle, WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{	
		return FALSE;
	}

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
	TCHAR *pMess;

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
		case WM_KEYUP:
			switch(wParam)
			{
				case VK_SPACE:
					bVK_SPACE = FALSE;
					break;
				case VK_UP:	RETAILMSG(1, (TEXT("VK_UP\r\n")));
					bVK_UP = FALSE;
					break;
				case VK_RIGHT:	RETAILMSG(1, (TEXT("VK_RIGHT\r\n")));
					bVK_RIGHT = FALSE;
					break;
				case VK_DOWN:	RETAILMSG(1, (TEXT("VK_DOWN\r\n")));
					bVK_DOWN = FALSE;
					break;
				case VK_LEFT:	RETAILMSG(1, (TEXT("VK_LEFT\r\n")));
					bVK_LEFT = FALSE;
					break;
				case VK_CONTROL:	RETAILMSG(1, (TEXT("VK_CONTROL\r\n")));
					bVK_CONTROL = FALSE;
					break;
				case VK_SHIFT:	RETAILMSG(1, (TEXT("VK_SHIFT\r\n")));
					bVK_SHIFT = FALSE;
					break;				
				case VK_RETURN:	RETAILMSG(1, (TEXT("VK_RETURN\r\n")));
					bVK_RETURN = FALSE;
					break;
				case VK_LSHIFT:	RETAILMSG(1, (TEXT("VK_SPACE\r\n")));
					bVK_LSHIFT = FALSE;
					break;
				case VK_TAB:	RETAILMSG(1, (TEXT("VK_TAB\r\n")));
					bVK_TAB = FALSE;
					break;
				case VK_ESCAPE:	RETAILMSG(1, (TEXT("VK_ESCAPE\r\n")));
					bVK_ESCAPE = FALSE;
					break;
				case VK_F1:	RETAILMSG(1, (TEXT("VK_F1\r\n")));
					bVK_F1 = FALSE;
					break;
				case VK_F2:	RETAILMSG(1, (TEXT("VK_F2\r\n")));
					bVK_F2 = FALSE;
					break;
				case VK_F3:	RETAILMSG(1, (TEXT("VK_F3\r\n")));
					bVK_F3 = FALSE;
					break;
				case VK_F4:	RETAILMSG(1, (TEXT("VK_F4\r\n")));
					bVK_F4 = FALSE;
					break;
				case VK_F11:	RETAILMSG(1, (TEXT("VK_F11\r\n")));
					bVK_F11 = FALSE;
					break;	
				default:
					RETAILMSG(1, (TEXT("NOT defined %x\r\n"),wParam));break;

			}
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case WM_KEYDOWN:
			switch(wParam)
			{
				case VK_SPACE:
					bVK_SPACE = TRUE;
					break;
				case VK_UP:	RETAILMSG(1, (TEXT("VK_UP\r\n")));
					bVK_UP = TRUE;
					break;
				case VK_RIGHT:	RETAILMSG(1, (TEXT("VK_RIGHT\r\n")));
					bVK_RIGHT = TRUE;
					break;
				case VK_DOWN:	RETAILMSG(1, (TEXT("VK_DOWN\r\n")));
					bVK_DOWN = TRUE;
					break;
				case VK_LEFT:	RETAILMSG(1, (TEXT("VK_LEFT\r\n")));
					bVK_LEFT = TRUE;
					break;
				case VK_CONTROL:	RETAILMSG(1, (TEXT("VK_CONTROL\r\n")));
					bVK_CONTROL = TRUE;
					break;
				case VK_SHIFT:	RETAILMSG(1, (TEXT("VK_SHIFT\r\n")));
					bVK_SHIFT = TRUE;
					break;				
				case VK_RETURN:	RETAILMSG(1, (TEXT("VK_RETURN\r\n")));
					bVK_RETURN = TRUE;
					break;
				case VK_LSHIFT:	RETAILMSG(1, (TEXT("VK_SPACE\r\n")));
					bVK_LSHIFT = TRUE;
					break;
				case VK_TAB:	RETAILMSG(1, (TEXT("VK_TAB\r\n")));
					bVK_TAB = TRUE;
					break;
				case VK_ESCAPE:	RETAILMSG(1, (TEXT("VK_ESCAPE\r\n")));
					bVK_ESCAPE = TRUE;
					break;
				case VK_F1:	RETAILMSG(1, (TEXT("VK_F1\r\n")));
					bVK_F1 = TRUE;
					break;
				case VK_F2:	RETAILMSG(1, (TEXT("VK_F2\r\n")));
					bVK_F2 = TRUE;
					break;
				case VK_F3:	RETAILMSG(1, (TEXT("VK_F3\r\n")));
					bVK_F3 = TRUE;
					break;
				case VK_F4:	RETAILMSG(1, (TEXT("VK_F4\r\n")));
					bVK_F4 = TRUE;
					break;
				case VK_F11:	RETAILMSG(1, (TEXT("VK_F11\r\n")));
					bVK_F11 = TRUE;
					break;	
				default:
					RETAILMSG(1, (TEXT("NOT defined %x\r\n"),wParam));break;

			}
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case WM_CREATE:
			//hwndCB = CommandBar_Create(hInst, hWnd, 1);			
		//	CommandBar_InsertMenubar(hwndCB, hInst, IDM_MENU, 0);
		//	CommandBar_AddAdornments(hwndCB, 0, 0);
			break;
		case WM_PAINT:
			RECT rt;
			hdc = BeginPaint(hWnd, &ps);
			GetClientRect(hWnd, &rt);
//			LoadString(hInst, IDS_HELLO, szHello, MAX_LOADSTRING);
//			DrawText(hdc, szHello, _tcslen(szHello), &rt, 
//				DT_SINGLELINE | DT_VCENTER | DT_CENTER);

			if (bVK_UP)
				pMess = L"UP Key";
			else
				pMess = L"";			
			ExtTextOut(hdc,0,0,0,NULL,pMess,_tcslen(pMess),0);
	
			if (bVK_RIGHT)
				pMess = L"Right Key";
			else
				pMess = L"";			
			ExtTextOut(hdc,0,HT*1,0,NULL,pMess,_tcslen(pMess),0);

			if (bVK_DOWN)
				pMess = L"Down Key";
			else
				pMess = L"";			
			ExtTextOut(hdc,0,HT*2,0,NULL,pMess,_tcslen(pMess),0);

			if (bVK_LEFT)
				pMess = L"Left Key";
			else
				pMess = L"";			
			ExtTextOut(hdc,0,HT*3,0,NULL,pMess,_tcslen(pMess),0);
			
			if (bVK_CONTROL)
				pMess = L"North Key";
			else
				pMess = L"";			
			ExtTextOut(hdc,0,HT*4,0,NULL,pMess,_tcslen(pMess),0);
		
			if (bVK_SHIFT)
				pMess = L"West Key";
			else
				pMess = L"";			
			ExtTextOut(hdc,0,HT*5,0,NULL,pMess,_tcslen(pMess),0);

			if (bVK_RETURN)
				pMess = L"South Key";
			else
				pMess = L"";			
			ExtTextOut(hdc,0,HT*6,0,NULL,pMess,_tcslen(pMess),0);

			if (bVK_SPACE)
				pMess = L"East Key";
			else
				pMess = L"";			
			ExtTextOut(hdc,0,HT*7,0,NULL,pMess,_tcslen(pMess),0);

			if (bVK_TAB)
				pMess = L"Left Shoulder";
			else
				pMess = L"";			
			ExtTextOut(hdc,0,HT*8,0,NULL,pMess,_tcslen(pMess),0);

			if (bVK_ESCAPE)
				pMess = L"Right Shoulder";
			else
				pMess = L"";			
			ExtTextOut(hdc,0,HT*9,0,NULL,pMess,_tcslen(pMess),0);

			if (bVK_F1)
				pMess = L"Piano 1";
			else
				pMess = L"";			
			ExtTextOut(hdc,0,HT*10,0,NULL,pMess,_tcslen(pMess),0);

			if (bVK_F2)
				pMess = L"Piano 2";
			else
				pMess = L"";			
			ExtTextOut(hdc,0,HT*11,0,NULL,pMess,_tcslen(pMess),0);

			if (bVK_F3)
				pMess = L"Piano 3";
			else
				pMess = L"";			
			ExtTextOut(hdc,0,HT*12,0,NULL,pMess,_tcslen(pMess),0);

			if (bVK_F4)
				pMess = L"Piano 4";
			else
				pMess = L"";			
			ExtTextOut(hdc,0,HT*13,0,NULL,pMess,_tcslen(pMess),0);

			if (bVK_F11)
				pMess = L"Piano 5";
			else
				pMess = L"";			
			ExtTextOut(hdc,0,HT*14,0,NULL,pMess,_tcslen(pMess),0);


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
