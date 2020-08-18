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

 MODULE:   TickViewerCE.cpp

 PURPOSE: Windows CE component of a sample CEPerfmon application using ITL.

 COMMENTS: N/A
***********************************************************************/
#define INITGUID
#include <windows.h>

#include "tldevice.h"

#include "TickStatCommon.h"
#include "TickStatsCE.h"


//**********************************************************************
int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrev,
                   LPTSTR lpCmdLine,
                   int nCmdShow)
//**********************************************************************
{
    CConnectionStream *pStream = NULL;
    BOOL bDone = FALSE;
    DWORD dwCmd = CMD_NONE;
    DWORD dwSizeSent = 0;
    HRESULT hr = S_OK;
	HMODULE hModule = NULL;
    DWORD dwTickCount = 0;


    // Initialize ITL and establish a stream
    bDone = InitializeITL(&hModule, &pStream);
    bDone = !bDone;

    // -----------------------------------------------------------------
    // This is the main processing loop.  It waits for a command to be
    // sent from the desktop and then performs the appropriate action.
    // -----------------------------------------------------------------
    while (!bDone)
    {
	    hr = pStream->ReadBytes((BYTE *)&dwCmd, sizeof(DWORD), &dwSizeSent);

        if (SUCCEEDED(hr))
        {
            switch (dwCmd)
            {
                case CMD_GET_DATA:
                    dwTickCount = ::GetTickCount();
                    hr = pStream->WriteBytes((BYTE *)&dwTickCount, sizeof(dwTickCount));
                    if (FAILED(hr))
                    {
                        bDone = TRUE;
                    }
                    break;

                case CMD_FINISHED:
                    bDone = TRUE;
                    break;

                default: // Unknown command
                    break;
            }
        }
        else
        {
            bDone = TRUE;
        }
    }

    // Cleanup and exit
    Cleanup(hModule, pStream);

    return 0;
}


//**********************************************************************
BOOL InitializeITL(HMODULE *phModule,
                   CConnectionStream **ppStream)
//**********************************************************************
{
    BOOL brc = FALSE;
    CREATESTREAMFUNC pfnCreateStream = NULL;

	// Load the Transport Library
	*phModule = LoadLibrary( L"CETLSTUB.DLL");

	if (*phModule)
    {
		pfnCreateStream = (CREATESTREAMFUNC)GetProcAddress(*phModule ,
                                                           L"CreateStream");

		/*--------------------------------------------------------------*/
		// Create the stream that matches up to the desktop (GUID)
		/*--------------------------------------------------------------*/
		*ppStream = NULL;
 		*ppStream = pfnCreateStream(TickViewerID, 0);

        if (*ppStream)
        {
            brc = TRUE;
        }
    }

    return brc;
}

//**********************************************************************
void Cleanup(HMODULE hModule,
             CConnectionStream *pStream)
//**********************************************************************
{
	pStream->Close();

	FreeLibrary( hModule);

	return;
}
