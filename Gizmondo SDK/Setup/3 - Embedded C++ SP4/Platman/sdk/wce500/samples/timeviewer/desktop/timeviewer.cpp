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

 MODULE:   TimeViewer.cpp

 PURPOSE: Desktop component of sample application using ITL.

 COMMENTS: N/A
***********************************************************************/
#define INITGUID
#include <windows.h>
#include <objbase.h>

#include "cemgr.h"
#include "cemgrui.h"

#include "resource.h"

#include "..\include\TvCommon.h"
#include "TimeViewer.h"

#include <cemgr_i.c>
#include <cemgrui_i.c>

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
TCHAR g_szTitle[MAX_LOADSTRING];                  // The title bar text
TCHAR g_szWindowClass[MAX_LOADSTRING];            // The title bar text

IPlatformManager *g_piMgr = NULL;

IConnectionStream *g_piStream;
char g_szMessage[80];

//**********************************************************************
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
//**********************************************************************
{
    MSG msg;
    HACCEL hAccelTable;

    // Initialize global strings
    LoadString(hInstance, IDS_APP_TITLE, g_szTitle, MAX_LOADSTRING);
    LoadString(hInstance, IDC_TIMEVIEWER, g_szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_TIMEVIEWER);

    // Main message loop:
    while (GetMessage(&msg, NULL, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    if (g_piStream)
    {
        DisconnectFromDevice(NULL);
    }

    CoUninitialize();

    return msg.wParam;
}

//**********************************************************************
ATOM MyRegisterClass(HINSTANCE hInstance)
//**********************************************************************
{
    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = (WNDPROC)WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, (LPCTSTR)IDI_TIMEVIEWER);
    wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = (LPCSTR)IDC_TIMEVIEWER;
    wcex.lpszClassName  = g_szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

    return RegisterClassEx(&wcex);
}

//**********************************************************************
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
//**********************************************************************
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(g_szWindowClass, g_szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, 450, 500, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   UpdateMenu(hWnd, FALSE);
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

    HRESULT hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);
    if (FAILED(hr))
    {
        ::MessageBox(hWnd,
                     "CoInitializeEx Failed",
                     "Add Connection",
                     MB_OK);
    }

   return TRUE;
}

//**********************************************************************
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//**********************************************************************
{
    int wmId, wmEvent;
    PAINTSTRUCT ps;
    HDC hdc;

    switch (message)
    {
        case WM_COMMAND:
            wmId    = LOWORD(wParam);
            wmEvent = HIWORD(wParam);

            // Parse the menu selections:
            switch (wmId)
            {
                case ID_CONNECTION_CONNECTTODEVICE:
                    ConnectToDevice(hWnd);
                    Refresh(hWnd);
                    break;

                case ID_CONNECTION_DISCONNECTFROMDEVICE:
                    DisconnectFromDevice(hWnd);
                    break;

                case ID_CONNECTION_REFRESH:
                    Refresh(hWnd);
                    break;

                case ID_CONNECTION_CONFIGUREPLATFORMMANAGER:
                    ConfigurePlatMan(hWnd);
                    break;

                case IDM_ABOUT:
                   DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
                   break;

                case IDM_EXIT:
                    DisconnectFromDevice(NULL);
                    DestroyWindow(hWnd);
                    break;

                default:
                   return DefWindowProc(hWnd, message, wParam, lParam);
            }
            break;

        case WM_PAINT:
            hdc = BeginPaint(hWnd, &ps);

            RECT rt;
            GetClientRect(hWnd, &rt);
            DrawText(hdc,
                     g_szMessage,
                     strlen(g_szMessage),
                     &rt,
                     DT_SINGLELINE | DT_VCENTER | DT_CENTER);
            EndPaint(hWnd, &ps);
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}

//**********************************************************************
LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
//**********************************************************************
{
    switch (message)
    {
        case WM_INITDIALOG:
                return TRUE;

        case WM_COMMAND:
            if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
            {
                EndDialog(hDlg, LOWORD(wParam));
                return TRUE;
            }
            break;
    }
    return FALSE;
}

//**********************************************************************
BOOL ConnectToDevice(HWND hWnd)
//**********************************************************************
{
    IPlatformManagerUI *piMgrUI = NULL;
    IRemoteDevice *piDevice = NULL;
    IConnection *piConnection = NULL;
    IPlatformCE *piPlatform = NULL;

    HMENU hMenu = NULL;
    size_t stRet = 0;
    TCHAR szText[80];
    DWORD dwSize = 0;

    BOOL bConnected = FALSE;


    //------------------------------------------------------------------
    // Instantiate the IPlatformManager COM object
    //------------------------------------------------------------------
    HRESULT hr = CoCreateInstance(CLSID_PlatformManager,
                                  NULL,
                                  CLSCTX_LOCAL_SERVER,
                                  IID_IPlatformManager,
                                  (void**)&g_piMgr);
    if (FAILED(hr))
    {
        ::MessageBox(hWnd,
                     "Unable to instantiate Platform Manager",
                     "Connect To Device",
                     MB_OK);
        goto Exit;
    }

    //------------------------------------------------------------------
    // Instantiate the IPlatformManagerUI COM object
    //------------------------------------------------------------------
    hr = CoCreateInstance(CLSID_PlatformManagerUI,
                          NULL,
                          CLSCTX_INPROC_SERVER,
                          IID_IPlatformManagerUI,
                          (void**)&piMgrUI) ;
    if (FAILED(hr))
    {
        ::MessageBox(hWnd,
                     "Unable to instantiate Platform Manager UI",
                     "Connect To Device",
                     MB_OK);
        goto Exit;
    }

    //------------------------------------------------------------------
    // Popup a dialog to allow the user to select the device
    //------------------------------------------------------------------
    hr = piMgrUI->GetDevice(hWnd, g_piMgr, &piPlatform, &piDevice);
    if (FAILED(hr) || !piDevice)
    {
        goto Exit;
    }

    lstrcpy(g_szMessage, "Attempting to connect to the device");
    ::InvalidateRect(hWnd, NULL, TRUE);


    //------------------------------------------------------------------
    // Connect to the device
    //------------------------------------------------------------------
    hr = piMgrUI->Connect(hWnd, piDevice, &piConnection);
    if (FAILED(hr) || !piConnection)
    {
        MessageBox(hWnd,
                   "Unable to connect",
                   "Connect To Device",
                   MB_OK);
        goto Exit;
    }

    //------------------------------------------------------------------
    // Queue up the the package
    //------------------------------------------------------------------
    hr = piConnection->QueuePackage(TimeViewerID, L"\\Windows", FALSE);
    if (FAILED(hr))
    {
        MessageBox(hWnd,
                   "Unable to Queue Package",
                   "Connect To Device",
                   MB_OK);
        goto Exit;
    }

    //------------------------------------------------------------------
    // Copy the package file(s) to the device
    //------------------------------------------------------------------
    hr = piConnection->CopyQueuedFiles(NULL, &dwSize);
    if (FAILED(hr) && hr != STG_E_FILEALREADYEXISTS)
    {
        MessageBox(hWnd,
                   "Unable to copy TimeViewerCE.exe to device",
                   "Connect To Device",
                   MB_OK);
        goto Exit;
    }

    //------------------------------------------------------------------
    // Update the Window Title to show the connection
    //------------------------------------------------------------------
    LPOLESTR pszName;
    char szDeviceName[80];

    piPlatform->GetPlatformName(&pszName);
    stRet = wcstombs(szDeviceName, pszName, sizeof szDeviceName);

    char szTitle[128];
    strcpy(szTitle, "TimeViewer : ");
    strcat(szTitle, szDeviceName);
    SetWindowText(hWnd, szTitle);

    //------------------------------------------------------------------
    // Start up the device side executable
    //------------------------------------------------------------------
    WCHAR wszDeviceExe[MAX_PATH];
    wcscpy(wszDeviceExe, L"\\Windows\\TimeViewerCE.exe");

    hr = piConnection->Launch(wszDeviceExe, NULL);
    if (FAILED(hr))
    {
        MessageBox(hWnd,
                   "Unable to launch device EXE",
                   "Connect To Device",
                   MB_OK);
        goto Exit;
    }

    //------------------------------------------------------------------
    // Create the stream (Synchronous)
    //------------------------------------------------------------------
    g_piStream = NULL;

    hr = piConnection->CreateStream(TimeViewerID,
                                    0,
                                    &g_piStream,
                                    NULL);
    if (FAILED(hr))
    {
        MessageBox(hWnd,
                   "Unable to create a stream",
                   "Connect",
                   MB_OK);
        goto Exit;
    }

    //------------------------------------------------------------------
    // Pop up a dialog to inform the user that we are connected
    //------------------------------------------------------------------
    wsprintf(szText, "We are connected to %s", szDeviceName);
    ::MessageBox(hWnd, szText, "Connect To Device", MB_OK | MB_ICONEXCLAMATION);

    bConnected = TRUE;

Exit:
    //------------------------------------------------------------------
    // Cleanup
    //------------------------------------------------------------------
    if (piConnection)
        piConnection->Release();

    if (piDevice)
        piDevice->Release();

    if (piPlatform)
        piPlatform->Release();

    if (piMgrUI)
        piMgrUI->Release();

    // Update the menu items
    UpdateMenu(hWnd, bConnected);

    return bConnected;
}

//**********************************************************************
HRESULT Refresh(HWND hWnd)
//**********************************************************************
{
    DWORD dwCmd = CMD_NONE;
    DWORD dwSizeSent = 0;
    HRESULT hr = E_FAIL;
    SYSTEMTIME systemTime;


    if (!g_piStream)
    {
        MessageBox(hWnd, "Not Connected", "Refresh", MB_OK);
        return hr;
    }

    lstrcpy(g_szMessage, "Error trying to read data");

    //------------------------------------------------------------------
    // Send a command to get the device system time
    //------------------------------------------------------------------
    dwCmd = CMD_GET_DATA;
    dwSizeSent = sizeof(DWORD);
    hr = g_piStream->Send(sizeof(DWORD), (BYTE *)&dwCmd, &dwSizeSent);

    if (FAILED(hr))
    {
        char szText[80];
        wsprintf(szText, "Error occurred when trying to send the get command: 0x%x", hr);
        MessageBox(hWnd, szText, "Refresh", MB_OK);
        return hr;
    }

    //------------------------------------------------------------------
    // Wait for a response
    //------------------------------------------------------------------
    dwSizeSent = sizeof(SYSTEMTIME);
    hr = g_piStream->Receive(&dwSizeSent);  // Find out how many bytes
                                            // are being sent
    if (SUCCEEDED(hr))
    {
        // Get the data from ITL
        hr = g_piStream->ReadBytes(sizeof(SYSTEMTIME),
                                   (BYTE *)&systemTime,
                                   &dwSizeSent);
        if (SUCCEEDED(hr))
        {
            // Format the time for display
            wsprintf(g_szMessage, "The CE time is %2d:%2.2d:%2.2d",
                     systemTime.wHour, systemTime.wMinute, systemTime.wSecond);
            ::InvalidateRect(hWnd, NULL, TRUE);
        }
    }
    else
    {
        char szText[80];
        wsprintf(szText, "Unable to obtain data from the device: hr = 0x%x", hr);
        ::MessageBox(hWnd, szText, "Refresh", MB_OK);
    }

    return hr;
}

//**********************************************************************
void DisconnectFromDevice(HWND hWnd)
//**********************************************************************
{
    if (g_piStream)     // We have an open connection
    {
        //--------------------------------------------------------------
        // Tell the device that we're done
        // NOTE: Don't wait for a response
        //--------------------------------------------------------------
        DWORD dwCmd = CMD_FINISHED;
        DWORD dwSizeSent = 0;
        g_piStream->Send(sizeof(DWORD), (BYTE *)&dwCmd, &dwSizeSent);

        //--------------------------------------------------------------
        // Close the stream
        //--------------------------------------------------------------
        g_piStream->Close();
        g_piStream->Release();
        g_piStream = NULL;

        if (hWnd)
        {
            lstrcpy(g_szMessage, "Disconnected!");
            ::InvalidateRect(hWnd, NULL, TRUE);

            UpdateMenu(hWnd, FALSE);
        }
    }
    else
    {
        ::MessageBox(hWnd,
                     "Not connected to device",
                     "Disconnect",
                     MB_OK | MB_ICONEXCLAMATION);
    }

    if (g_piMgr)    // Platform Manager exists
    {
        g_piMgr->Release();
        g_piMgr = NULL;
    }

    return;
}

//**********************************************************************
void ConfigurePlatMan(HWND hWnd)
//**********************************************************************
{
    IPlatformManagerUI *piMgrUI;

    //------------------------------------------------------------------
    // Instantiate PlatformManagerUI
    //------------------------------------------------------------------
    HRESULT hr = CoCreateInstance(CLSID_PlatformManagerUI,
                                  NULL,
                                  CLSCTX_INPROC_SERVER,
                                  IID_IPlatformManagerUI,
                                  (void**)&piMgrUI) ;
    if (SUCCEEDED(hr))
    {
        // Use the built-in configuration dialogs
        piMgrUI->Configure(hWnd);
        piMgrUI->Release();
    }

    return;
}

//**********************************************************************
void UpdateMenu(HWND hWnd, BOOL bConnected)
//**********************************************************************
{
    HMENU hMenu = GetMenu(hWnd);

    if (bConnected)
    {
        EnableMenuItem(hMenu, ID_CONNECTION_CONNECTTODEVICE, MF_GRAYED);
        EnableMenuItem(hMenu, ID_CONNECTION_REFRESH, MF_ENABLED);
        EnableMenuItem(hMenu, ID_CONNECTION_DISCONNECTFROMDEVICE, MF_ENABLED);
    }
    else
    {
        EnableMenuItem(hMenu, ID_CONNECTION_CONNECTTODEVICE, MF_ENABLED);
        EnableMenuItem(hMenu, ID_CONNECTION_REFRESH, MF_GRAYED);
        EnableMenuItem(hMenu, ID_CONNECTION_DISCONNECTFROMDEVICE, MF_GRAYED);
    }

    return;
}
