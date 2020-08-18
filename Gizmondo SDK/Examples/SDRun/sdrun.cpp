///////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2004-2005 Gizmondo Ltd and
// Copyright (C) 2004-2005 Intrinsyc Europe Ltd.
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
// $Workfile: sdrun.cpp $
// $Revision: 3 $
//     $Date: 15/02/05 11:15 $
//
// DESCRIPTION : SD Application Launch Sample
//
///////////////////////////////////////////////////////////////////////////////
//
// MODIFICATION HISTORY
//
// $Log: /Gizmondo/Apps/Developer Samples/SDRun/sdrun.cpp $
// 
// 3     15/02/05 11:15 Martint
// Added comments
// 
// $NoKeywords: $
//
///////////////////////////////////////////////////////////////////////////////

#include <windows.h>

// SDCreateProcess() is exported by sdlaunch.dll
typedef BOOL (* SDCreateProcess_t)(LPCTSTR, LPCTSTR, DWORD, LPPROCESS_INFORMATION);

// Application to launch (must include file extension)
#define APPNAME		TEXT("\\SD Card\\autorun.exe")
#define PARAMS		TEXT("")

int WINAPI WinMain(	HINSTANCE hInstance,
					HINSTANCE hPrevInstance,
					LPTSTR    lpCmdLine,
					int       nCmdShow)
{
	SDCreateProcess_t pfnSDCreateProcess = NULL;
	HMODULE hModule = NULL;
	PROCESS_INFORMATION pi;
	BOOL bRet = FALSE;

	// Pick up function from sdlaunch DLL
	pfnSDCreateProcess = NULL;
	hModule = (HMODULE) LoadLibrary(TEXT("sdlaunch.dll"));
	if (hModule != NULL) {
		pfnSDCreateProcess = (SDCreateProcess_t) GetProcAddress(hModule, TEXT("SDCreateProcess"));
	}

	if (pfnSDCreateProcess) {
		// Use SDLaunch to create the process
		bRet = pfnSDCreateProcess (APPNAME, PARAMS, 0, &pi);
	} else {
		// Use CreateProcess, but it can't handle encrypted files
		bRet = CreateProcess (APPNAME, PARAMS, NULL, NULL, 0, 0, NULL, NULL, NULL, &pi);
	}

	if (bRet) {
		RETAILMSG(1, (TEXT("<SDRun> Started %s\r\n"), APPNAME));
		// This waits for application to complete (if required)
		WaitForSingleObject( pi.hProcess, INFINITE );
		CloseHandle( pi.hProcess );
		CloseHandle( pi.hThread );
		Sleep (100);
		RETAILMSG(1, (TEXT("<SDRun> Done %s\r\n"), APPNAME));
	} else {
		RETAILMSG(1, (TEXT("<SDRun> Failed to launch %s, error %u\r\n"), APPNAME, GetLastError()));
	}

	if (hModule != NULL) {
		FreeLibrary(hModule);
	}

	return 0;
}
