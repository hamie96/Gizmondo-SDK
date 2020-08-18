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
// $Workfile: Camera.cpp $
// $Revision: 1 $
//     $Date: 21/10/04 12:07 $
//
// DESCRIPTION : Developer sample : Demonstrates using camera driver
//
///////////////////////////////////////////////////////////////////////////////
//
// MODIFICATION HISTORY
//
// $Log: /Gizmondo/Apps/Developer Samples/Camera/Camera.cpp $
// 
// 1     21/10/04 12:07 Deanw
// Created
// 
// 
// $NoKeywords: $
//
///////////////////////////////////////////////////////////////////////////////

// Camera.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Camera.h"
#include <commctrl.h>
#include <winioctl.h>
#include "oeminc.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE			hInst;			// The current instance
HWND				hwndCB;			// The command bar handle

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass	(HINSTANCE, LPTSTR);
BOOL				InitInstance	(HINSTANCE, int);
LRESULT CALLBACK	WndProc			(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About			(HWND, UINT, WPARAM, LPARAM);
static BOOL InitCamera (void);

static HANDLE ghCam;
static DIBBUF m_bufPreview;			// Preview buffers
static YUVBUF m_bufCapture;			// Captured image buffers

static int gsizeX;
static int gsizeY;
static BOOL m_bAllocatedDIBs=FALSE;
static m_posX;
static m_posY;
static BOOL gbDisplayPreview = FALSE;
static int giActions =0;
static void Paint(HDC hDC, RECT& rt, int x, int y);
static void PerformActions(HWND hWnd);
static BOOL AllocateYUV(PYUVBUF pBuf, DWORD cx, DWORD cy);
static BOOL GetStill (void);
static BOOL GetPreview (void);


int WINAPI WinMain(	HINSTANCE hInstance,
					HINSTANCE hPrevInstance,
					LPTSTR    lpCmdLine,
					int       nCmdShow)
{
	MSG msg;
	HACCEL hAccelTable;


    InitCamera();

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_CAMERA);

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
    wc.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CAMERA));
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
	LoadString(hInstance, IDC_CAMERA, szWindowClass, MAX_LOADSTRING);
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
	TCHAR* szMess = L"Press any key preview camera.";
	
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
			PerformActions(hWnd);
			break;
		case WM_CREATE:
			break;
		case WM_PAINT:
			RECT rt;
			hdc = BeginPaint(hWnd, &ps);
			GetClientRect(hWnd, &rt);
		
			Paint(hdc,rt,0,0);
			if (giActions == 0)
				DrawText(hdc, szMess, _tcslen(szMess), &rt, 
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

///////////////////////////////////////////////////////////////////////////
//
// InitCamera() - sets camera input format & adjusts size to compensate
//
BOOL InitCamera (void)
{
	SIZE	imgSize[2];
	DWORD	cbRet;
	SIZE	szCapture,szPreview;

	// Zero the camera structures
	memset(&m_bufPreview, 0, sizeof(m_bufPreview));
	memset(&m_bufCapture, 0, sizeof(m_bufCapture));

	gsizeX = 320;
	gsizeY = 240;

	m_posX = 0;
	m_posY = 0;

	// Attempt to open the camera driver
	ghCam = CreateFile (TEXT("CAM1:"), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
    if (ghCam == INVALID_HANDLE_VALUE) 
	{
	    MessageBox(NULL,L"Failed to open camera driver",L"Error",MB_OK);
        return FALSE;
	}

	// First stop and set up camera 
	if ( !DeviceIoControl(ghCam,IOCTL_OEM_CAM_STOP,NULL,0,NULL,0,&cbRet,NULL) ) 
	{
		RETAILMSG(1,(TEXT("<CamTest>: IOCTL_OEM_CAM_STOP failed (%u)\r\n"), GetLastError()));
		return (FALSE);
	}

	// Set capture image size
	szCapture.cx = CAM_CAPTURE_CX;
	szCapture.cy = CAM_CAPTURE_CY;

	// Set preview image size
	szPreview.cx = gsizeX;
	szPreview.cy = gsizeY;

	// Pass format as an array of capture and preview window sizes
	imgSize[0] = szCapture;
	imgSize[1] = szPreview;

	if ( !DeviceIoControl(ghCam,IOCTL_OEM_CAM_SETFORMAT,&imgSize,sizeof(imgSize),NULL,0,&cbRet,NULL) ) 
	{
		RETAILMSG(1,(TEXT("<CamTest>: IOCTL_OEM_CAM_SETFORMAT failed (%u)\r\n"), GetLastError()));
		return (FALSE);
	}

	GetPreview();

	return (TRUE);
}

///////////////////////////////////////////////////////////////////////////
//
// GetPreview() - capture a single preview frame from the camera driver
//
BOOL GetPreview (void)
{
	VINFRAMEINFO vinFrame;
	DWORD cbRet;

	// Start grabbing frames
	if ( !DeviceIoControl(ghCam,IOCTL_OEM_CAM_START,NULL,0,NULL,0,&cbRet,NULL) ) 
	{
		RETAILMSG(1,(TEXT("<CamTest>: IOCTL_OEM_CAM_START failed (%u)\r\n"), GetLastError()));
		return FALSE;
	}

	// Set up frame information structure
	memset (&vinFrame, 0, sizeof(VINFRAMEINFO));
	vinFrame.dwTimeout = CAM_TIMEOUT;	// no timeout we want the image straight away
	vinFrame.dwWidth = m_bufPreview.cx;
	vinFrame.dwHeight = m_bufPreview.cy;

	if (DeviceIoControl (ghCam, IOCTL_OEM_CAM_PREVIEW, &vinFrame, sizeof(VINFRAMEINFO), 
			m_bufPreview.pBitmap[0], m_bufPreview.cbBuf, &cbRet, NULL)) 
	{
		RETAILMSG(1,(TEXT("ViewFinder::GetPreview: Grabbed frame %u to pBitmap = %08X\r\n"), 
			vinFrame.dwFrameCount, m_bufPreview.pBitmap[0]));

	
		RETAILMSG(1,(TEXT("ViewFinder::GetPreview: dwDispBuf:%u, dwCurBuf:%u\r\n"), m_bufPreview.dwDispBuf, m_bufPreview.dwCurBuf));
	}

	return (0);
}

///////////////////////////////////////////////////////////////////////////
//
// CreateBltDIB() - create DIB section for GDI rendering
//
HBITMAP CreateBltDIB (HDC hdc, LONG cx, LONG cy, PVOID *ppvBits)
{
	PBITMAPINFO	pBMI;
	HBITMAP	hBitmap;
	DWORD	*pdwMasks;

	cy = 1 - cy - 1;

	pBMI = (PBITMAPINFO) LocalAlloc (LPTR, sizeof(BITMAPINFO) + 3*sizeof(DWORD) );
	pBMI->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	pBMI->bmiHeader.biWidth = cx;
	pBMI->bmiHeader.biHeight = cy;
	pBMI->bmiHeader.biPlanes = 1;
	pBMI->bmiHeader.biBitCount = 16;
	pBMI->bmiHeader.biCompression = BI_BITFIELDS; 
	// Specify RGB 5:6:5 colour masks
	pdwMasks = (PDWORD)pBMI->bmiColors;
	*pdwMasks++ = 0xF800;			// red mask
	*pdwMasks++ = 0x07E0;			// green mask
	*pdwMasks++ = 0x001F;			// blue mask

	hBitmap = CreateDIBSection (hdc, pBMI, DIB_RGB_COLORS, ppvBits, NULL, 0);
	LocalFree (pBMI);

	return (hBitmap);
}

///////////////////////////////////////////////////////////////////////////
//
// AllocateYUVs() - allocates planar YUV 4:2;0 buffer(s)
//
BOOL AllocateYUV(PYUVBUF pBuf, DWORD cx, DWORD cy)
{
	// Calculate required capture buffer sizes
	pBuf->cx = cx;
	pBuf->cy = cy;
	pBuf->cbBuf = (3 * pBuf->cx * pBuf->cy) >> 1;	// 4:2:0
	RETAILMSG(1,(TEXT("<CamTest>: Allocating YUV buffers x (%ux%u)\r\n"), pBuf->cx, pBuf->cy));

	// Allocate the required number of YUV buffers
	pBuf->pBuf = (PBYTE) LocalAlloc (LPTR, pBuf->cbBuf);
	if (pBuf->pBuf == 0) 
	{
		RETAILMSG(1,(TEXT("<CamTest>: Capture YUV alloc failed (%u)\r\n"), GetLastError()));
		return (FALSE);
	}
	
	// Start with first YUV buffer
	pBuf->dwCurBuf = 0;
	pBuf->dwDispBuf = 1;

	return (TRUE);
}



///////////////////////////////////////////////////////////////////////////
//
// AllocateDIBs() - allocates 16-bpp DIB buffer(s)
//
BOOL AllocateDIB(HDC hDC, PDIBBUF pBuf, DWORD cx, DWORD cy)
{
	// get a compatible DC
	m_bufPreview.hImageCache = CreateCompatibleDC(hDC);

	// Calculate required capture buffer sizes
	pBuf->cx = cx;
	pBuf->cy = cy;
	pBuf->cbBuf = pBuf->cx * pBuf->cy * 2;	// 16bpp
	
	RETAILMSG(1,(TEXT("<CamTest>: Allocating DIB buffer x (%ux%u)\r\n"), pBuf->cx, pBuf->cy));

	DWORD inverseHeight = 0 - pBuf->cy;

	for(int loop=0;loop<NUM_BUFFERS;loop++)
	{
		// Allocate the required number of DIB buffers
		pBuf->hBitmap[loop] = CreateBltDIB (hDC, pBuf->cx, inverseHeight, (PVOID *)&pBuf->pBitmap[loop]);
		if (pBuf->hBitmap[loop] == 0) 
		{
			RETAILMSG(1,(TEXT("<CamTest>: Capture DIB CreateBltDIB failed (%u)\r\n"), GetLastError()));
			return (FALSE);
		}
	}
	
	// Start with first DIB buffer
	pBuf->dwCurBuf = 0;
	pBuf->dwDispBuf = 1;

	return (TRUE);
}


/////////////////////////////////////////////////////////////////////////////////////
//Paint Scrolling Text
//
void Paint(HDC hDC, RECT& rt, int x, int y)
{
	// Allocate memory for DIBS if not already done so
	//
	if (!m_bAllocatedDIBs)
	{
		RETAILMSG(1, (TEXT("Allocating more memory!\r\n")));

		if ( !AllocateDIB (hDC, &m_bufPreview,gsizeX,gsizeY) ) 
		{
			RETAILMSG(1,(TEXT("ViewFinder: AllocateDIBs() failed\r\n")));
			//FreeResources();
			return;
		}

		// Allocate YUV image buffer(s)
		if ( !AllocateYUV(&m_bufCapture,CAM_CAPTURE_CX,CAM_CAPTURE_CY) ) 
		{
			RETAILMSG(1,(TEXT("ViewFinder: AllocateYUVs() failed\r\n")));
			//FreeResources();
			return;
		}

		// dibs allocated now
		m_bAllocatedDIBs = TRUE;
	}

	// paint the frame
			
	// Select cached bitmap into DC
	SelectObject(m_bufPreview.hImageCache, m_bufPreview.hBitmap[0]);

	//RETAILMSG(1, (TEXT("Printing preview! \r\n")));
	// blt the image onto the screen
	BitBlt(hDC, 
			m_posX, m_posY,	   
			gsizeX,			// width,
			gsizeY,			// height,
			m_bufPreview.hImageCache,			// bitmap cache for mask
			0,0, SRCCOPY);
	

	// unselect image
	SelectObject(m_bufPreview.hImageCache, NULL);
}


void PerformActions(HWND hWnd)
{
	switch(giActions++)
	{
		case 0:
		case 1:
		case 2:
			GetPreview();					// Get Preview image
			gbDisplayPreview = TRUE;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case 3:
			GetStill();
			break;
		case 4:   
			DestroyWindow(hWnd);
			break;
	}
}

///////////////////////////////////////////////////////////////////////////
//
// GetStill() - get a single image capture frame
//
BOOL GetStill (void)
{
	VINFRAMEINFO vinFrame;
	DWORD cbRet;
	BOOL bHaveFrame = FALSE;

	if ( !DeviceIoControl(ghCam,IOCTL_OEM_CAM_START,NULL,0,NULL,0,&cbRet,NULL) ) 
	{
		RETAILMSG(1,(TEXT("<CamTest>: IOCTL_OEM_CAM_START failed (%u)\r\n"), GetLastError()));
		return (FALSE);
	}

	// Set up frame information structure
	memset (&vinFrame, 0, sizeof(VINFRAMEINFO));
	vinFrame.dwTimeout = 10000;
	vinFrame.dwWidth = m_bufCapture.cx;
	vinFrame.dwHeight = m_bufCapture.cy;

	if (DeviceIoControl (ghCam, IOCTL_OEM_CAM_CAPTURE, &vinFrame, sizeof(VINFRAMEINFO), 
			m_bufCapture.pBuf, m_bufCapture.cbBuf, &cbRet, NULL)) 
	{
		bHaveFrame = TRUE;

		RETAILMSG(1,(TEXT("<CamTest>: dwDispBuf:%u, dwCurBuf:%u\r\n"), m_bufCapture.dwDispBuf, m_bufCapture.dwCurBuf));
	}

	return (bHaveFrame);
}
