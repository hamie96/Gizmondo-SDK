///////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2004-2005 Gizmondo Ltd and
// All rights reserved.
//
///////////////////////////////////////////////////////////////////////////////

#include <windows.h>

void APP_FindDataDir( const LPTSTR pProductCode, const LPTSTR pIdentFile, LPTSTR pAppPath );

int WINAPI WinMain(	HINSTANCE hInstance,
					HINSTANCE hPrevInstance,
					LPTSTR    lpCmdLine,
					int       nCmdShow)
{
	TCHAR AppDir[256];

	APP_FindDataDir(TEXT("GZGA200000"), TEXT("uniquefile.dat"), AppDir);

	RETAILMSG(1, (TEXT("App Data Directory: %s\r\n"), AppDir));

	return 0;
}


// -----------------------------------------------------------------------------------------------------------------------------------------------------------
// APP_FindDataDir() - Determines which directory to use as the base for reading data files.
// -----------------------------------------------------------------------------------------------------------------------------------------------------------
// pProductCode		Should be the 6 character product code for this product E.G. "GIZ001"
// pIdentFile		A unique identifying file for this product found in the data directory root E.G. "GIZ001.IMG". Do not use the EXE as the identifier.
// pAppPath			Space (should be at least _MAX_PATH) to return the required data directory root.
// -----------------------------------------------------------------------------------------------------------------------------------------------------------

void APP_FindDataDir( const LPTSTR pProductCode, const LPTSTR pIdentFile, LPTSTR pAppPath )
{
	DWORD moduleFileLen;
	TCHAR moduleFileName[_MAX_PATH];
	TCHAR findFileName[_MAX_PATH];
	HANDLE hFile;

	moduleFileLen = GetModuleFileName(NULL,moduleFileName,_MAX_PATH);
	if(moduleFileLen)
	{
		_tcscpy( findFileName, moduleFileName );
		_tcscpy( _tcsrchr(findFileName,TCHAR('\\'))+1, pIdentFile );

		hFile = CreateFile(findFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		if(hFile==INVALID_HANDLE_VALUE)
		{
			_tcscpy( _tcsrchr(findFileName,TCHAR('\\'))+1, pProductCode );
			_tcscat(findFileName,TEXT("\\"));
			_tcscat(findFileName,pIdentFile);
			hFile = CreateFile(findFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		}
		if(hFile!=INVALID_HANDLE_VALUE)
		{
			CloseHandle(hFile);
			_tcscpy( pAppPath, findFileName );
			*(_tcsrchr(pAppPath,TCHAR('\\'))+1) = TCHAR(0);
			return;
		}
	}

	_tcscpy(pAppPath,TEXT("\\SD Card\\"));
	_tcscat(pAppPath,pProductCode);
	_tcscat(pAppPath,TEXT("\\"));
}
