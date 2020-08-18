//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
//
// Use of this source code is subject to the terms of the Microsoft end-user
// license agreement (EULA) under which you licensed this SOFTWARE PRODUCT.
// If you did not accept the terms of the EULA, you are not authorized to use
// this source code. For a copy of the EULA, please see the LICENSE.RTF on your
// install media.
//
/***********************************************************************
 THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
 ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
 PARTICULAR PURPOSE.

 MODULE:  Callcap.cpp

 PURPOSE: Sample for Remote Call Profiler

***********************************************************************/

#include "stdafx.h"
#include "Callcap.h"
#include <commctrl.h>
#include <stdlib.h> // for rand()

#include "cecap.h"

// Uncomment the following line if you dont want to insert 
// Refer to DoHand()
//
//#define ENABLE_PROFILING

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE			hInst;			// The current instance
HWND				hwndCB;			// The command bar handle

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass	(HINSTANCE, LPTSTR);
BOOL				InitInstance	(HINSTANCE, int);
LRESULT CALLBACK	WndProc			(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About			(HWND, UINT, WPARAM, LPARAM);



void DoWork5()
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	for(int i = 0; i < 10;i++)
	{
		srand(GetTickCount());
		x = rand();
		y = rand();
		z = x*y;

	}

}

void DoWork4()
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	for(int i = 0; i < 10;i++)
	{
		srand(GetTickCount());
		x = rand();
		y = rand();
		z = x*y;

		DoWork5();
	}


}

void DoWork3()
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	for(int i = 0; i < 10;i++)
	{
		srand(GetTickCount());
		x = rand();
		y = rand();
		z = x*y;

		DoWork4();
	}
}

// Do some simple work.
// 
void DoWork()
{
	SetCursor(LoadCursor(NULL, IDC_WAIT));
	WCHAR wszOutput[MAX_PATH] = {0};
	double x = 1.234;
	double y = 5.678;
	double z = 0.0;
	DWORD dwTicks = GetTickCount();
	for (long j=0; j<500; j++)
	{
		x = 1.234;
		y = 5.678;
		z = x * y;
		x *= y;
		y *= x;
		DoWork3();
	}
	Sleep(10);
	_snwprintf(wszOutput, MAX_PATH, L"DoWork() completed in %d milliseconds", GetTickCount() - dwTicks);
	wszOutput[MAX_PATH-1] = '\0';
	SetCursor(LoadCursor(NULL, IDC_ARROW));
	MessageBox(0, wszOutput, L"Done", 0);
}

// Demonstrates the use of labels in an application.  We are using only
// one of the several marker functions available.  For a complete list of 
// functions and what they do, refer to the documentation under the Remote
// Call Profiler API functions heading. 
// 
void DoLabel()
{
	SetCursor(LoadCursor(NULL, IDC_WAIT));
	double x = 0;
	CommentMarkProfile(10, "+DoLabel");
	for (int i=0; i<5; i++)
	{
		for (int j=0; j<100; j++)
		{
			DoWork3();
		}
		CommentMarkProfile(i, "Iteration");
	}
	CommentMarkProfile(10, "-DoLabel");
	SetCursor(LoadCursor(NULL, IDC_ARROW));
	MessageBox(0, L"DoLabel() Completed", L"Done", 0);
}

// Demonstrates how you can manually insert calls to profile data.  This technique
// can be used to add these calls to crucial areas of your application to profile.
// You shouldn't compile the code with /callcap or /fastcap when making these calls
// as it may result in unexpected results.
// The following sample code can be used by any code which links to cecap.lib and the
// Cecap header.
// 
void DoHand()
{
	SetCursor(LoadCursor(NULL, IDC_WAIT));
	for (int i=0; i<10; i++)
	{
// You can #ifdef a flag that can be turned off when you dont want to profile, since 
// profiling can slow down your application.
//
#ifdef ENABLE_PROFILING
			// The first parameter is the address of the current function and the second
			// parameter is the target function -- the function we are going into.  For more
			// information, please refer to the documentation.
			//
			_CAP_Start_Profiling(DoHand, Sleep);
#endif
			Sleep(100); // We should be able to see time spent in this call when the probes are enabled.
#ifdef ENABLE_PROFILING
			_CAP_End_Profiling(WinMain);
#endif
	}
	SetCursor(LoadCursor(NULL, IDC_ARROW));
	MessageBox(0, L"DoHand() Completed", L"Done", 0);
}

// Thread Function used by DoMultiThread
//
DWORD ThreadFunc(LPVOID lpvoid)
{
	SetCursor(LoadCursor(NULL, IDC_WAIT));
    HANDLE hCloseEvent = (HANDLE)lpvoid;

    while(true)
    {
        // Check to see if we need to exit
        if(WaitForSingleObject(hCloseEvent,100) == WAIT_OBJECT_0)
        {
            break;
        }
		// Call worker function.
        DoWork3();
    }
	SetCursor(LoadCursor(NULL, IDC_ARROW));
    return 0;
}

// Creates five threads to demonstrate profiling in multithreaded scenarios.
//
void DoMultiThread()
{
    HANDLE Handles[5] = {0};
    HANDLE hCloseEvent = CreateEvent(NULL,FALSE,FALSE,NULL);
    DWORD dwThreadId;

    for(int i = 0; i < 5; i++)
    {
		// Create thread
        Handles[i] = CreateThread(NULL,0,ThreadFunc,(LPVOID)hCloseEvent,0,&dwThreadId);
    }

    SetEvent(hCloseEvent);

	// Wait for all the threads to complete their work.
	//
    WaitForMultipleObjects(5,Handles,TRUE,INFINITE);

	// Close all the handles.
	//
    for(i = 0; i < 5; i++)
    {
        if(Handles[i]) CloseHandle(Handles[i]);
    }
	MessageBox(0, L"DoMultiThread() Completed", L"Done", 0);
}

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

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_CALLCAP);

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
    wc.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CALLCAP));
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
	LoadString(hInstance, IDC_CALLCAP, szWindowClass, MAX_LOADSTRING);
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
	TCHAR szHello[MAX_LOADSTRING];

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
				case IDM_WORK:
					DoWork();
					break;
				case IDM_LABEL:
					DoLabel();
					break;
				case IDM_MT:
					DoMultiThread();
					break;
				default:
				   return DefWindowProc(hWnd, message, wParam, lParam);
			}
			break;
		case WM_CREATE:
			hwndCB = CommandBar_Create(hInst, hWnd, 1);			
			CommandBar_InsertMenubar(hwndCB, hInst, IDM_MENU, 0);
			CommandBar_AddAdornments(hwndCB, 0, 0);
			break;
		case WM_PAINT:
			RECT rt;
			hdc = BeginPaint(hWnd, &ps);
			GetClientRect(hWnd, &rt);
			LoadString(hInst, IDS_HELLO, szHello, MAX_LOADSTRING);
			DrawText(hdc, szHello, _tcslen(szHello), &rt, 
				DT_SINGLELINE | DT_VCENTER | DT_CENTER);
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

