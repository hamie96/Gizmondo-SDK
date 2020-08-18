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

 MODULE:   TimeViewer.h

 PURPOSE: Header for desktop component of sample application using ITL.

 COMMENTS: N/A
***********************************************************************/
#ifndef _TIMEVIEWER_H_
#define _TIMEVIEWER_H_

ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

BOOL ConnectToDevice(HWND hWnd);
LRESULT Refresh(HWND hWnd);
void DisconnectFromDevice(HWND hWnd);
void ConfigurePlatMan(HWND hWnd);
void UpdateMenu(HWND hWnd, BOOL bConnected);

#endif // _TIMEVIEWER_H_
