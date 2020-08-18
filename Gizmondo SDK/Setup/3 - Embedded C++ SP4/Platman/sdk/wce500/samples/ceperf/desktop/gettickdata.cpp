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

 MODULE:   GetTickData.cpp

 PURPOSE: Desktop component of sample application using ITL.

 COMMENTS: N/A
***********************************************************************/
//#define INITGUID
#include <windows.h>
#include <initguid.h>
#include <objbase.h>
#include <ocidl.h>
#include <ks.h>

#ifdef UNDER_CE
#include <commctrl.h>
#else
#include <commdlg.h>
#endif

// PerfMon
//----------------------------------------------------------------------
// TODO: include the header that defines the data strucuture that is
//       passed to the desktop and the header specific to this file.
//----------------------------------------------------------------------
#include "CETickStructs.h"
#include "GetTickData.h"
#include "TickStatCommon.h"

#include "cemgr.h"

extern IConnection *g_piConnection;
extern IConnectionStream *g_piStream;

//**********************************************************************
void UninitializeRemoteData()
//**********************************************************************
{
    if (g_piStream)
    {
        //--------------------------------------------------------------
        // Tell the device that we're done
        // NOTE: Don't wait for a response
        DWORD dwCmd = CMD_FINISHED;
        DWORD dwSizeSent = 0;
        g_piStream->Send(sizeof(DWORD), (BYTE *)&dwCmd, &dwSizeSent);

        //--------------------------------------------------------------
        // Close the stream
        //--------------------------------------------------------------
        g_piStream->Close();
        g_piStream->Release();
        g_piStream = NULL;
    }

    return;
}

//----------------------------------------------------------------------
//TODO: Create a function that gets the data from the device
//----------------------------------------------------------------------
//**********************************************************************
HRESULT GetTickPerf(TICK_STATS *pTickStats)
//**********************************************************************
{
    HRESULT hr = S_OK;
    DWORD dwCmd = CMD_NONE;
    DWORD dwSizeSent = 0;

    if (!g_piStream)
    {
        return E_POINTER;
    }

    pTickStats->dwTickCount = 0;

    //------------------------------------------------------------------
    // Send a command to get the tick count
    //------------------------------------------------------------------
    dwCmd = CMD_GET_DATA;
    g_piStream->Send(sizeof(DWORD), (BYTE *)&dwCmd, &dwSizeSent);

    //------------------------------------------------------------------
    // Wait for a response
    //------------------------------------------------------------------
    hr = g_piStream->Receive(&dwSizeSent);  // Find out how many bytes
                                            // are being sent
    if (SUCCEEDED(hr))
    {
        // Get the data from ITL
        hr = g_piStream->ReadBytes(sizeof(DWORD),
                                   (BYTE *)&(pTickStats->dwTickCount),
                                   &dwSizeSent);
    }

    return hr;
}


//**********************************************************************
HRESULT InitializeRemoteData (void)
//**********************************************************************
{
    HRESULT hr = S_OK;

	// device side package
    WCHAR wszDeviceExe[MAX_PATH];
    wcscpy(wszDeviceExe, L"TickStatsCE.exe");

	//------------------------------------------------------------------
    // Copy the package to the device
    //------------------------------------------------------------------
	DWORD dwTotalSize = 0;
	hr = g_piConnection->CopyPackage(TickViewerPkgID, L"\\Windows", TRUE, NULL, &dwTotalSize);
	if (FAILED(hr))
	{
		::OutputDebugString("Unable to copy package");
        goto Exit;
	}
	
    //------------------------------------------------------------------
    // Launch the Device side
    //------------------------------------------------------------------
    hr = g_piConnection->Launch(wszDeviceExe, NULL);
    if (FAILED(hr))
    {
        ::OutputDebugString("Unable to launch remote executable");
        goto Exit;
    }

    //------------------------------------------------------------------
    // Create the stream (Synchronous)
    //------------------------------------------------------------------
    g_piStream = NULL;
    hr = g_piConnection->CreateStream(TickViewerID,
                                      0,
                                      &g_piStream,
                                      NULL);
    if (FAILED(hr))
    {
        ::OutputDebugString("Unable to open stream to device");
        goto Exit;
    }

Exit:
    return hr;
}
