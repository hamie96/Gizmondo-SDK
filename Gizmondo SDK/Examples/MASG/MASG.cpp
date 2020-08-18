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
// $Workfile: MASG.cpp $
// $Revision: 1 $
//     $Date: 17/01/05 12:25 $
//
// DESCRIPTION : MASG Synthesiser MIDI/MP3 Playback Sample
//
///////////////////////////////////////////////////////////////////////////////
//
// MODIFICATION HISTORY
// 
// $NoKeywords: $
//
///////////////////////////////////////////////////////////////////////////////

#include <windows.h>
#include <winioctl.h>
#include "oeminc.h"

#define BUFSIZE 	32768		// MIDI/MP3 file buffer size

///////////////////////////////////////////////////////////////////////////////

static BOOL MasgPlayFile (HANDLE hFile, BOOL bTest);
static DWORD FillBuffer (HANDLE hFile, PUCHAR pBuf, ULONG ulFilePos, ULONG ulFileLen);

// MASG control and playback
static BOOL MasgStart (PUCHAR pBuf, DWORD cbBuf, PHANDLE phevCallback);
static BOOL MasgWrite (PUCHAR pBuf, DWORD cbBuf);
static BOOL MasgStop (void);
static BOOL MasgPause (void);
static BOOL MasgResume (void);
static DWORD MasgState (void);
static DWORD MasgGetPosition (void);
static DWORD MasgGetVolume (void);
static BOOL MasgSetVolume (DWORD dwVolume);
static BOOL MasgHasMP3 (void);

///////////////////////////////////////////////////////////////////////////////

static HANDLE g_hMasgDrv;

///////////////////////////////////////////////////////////////////////////
//
//	WinMain() - MIDI/MP3 file playback using MASG synthesiser
//
int WINAPI WinMain (HINSTANCE hInst, HINSTANCE hPrev, LPTSTR pCmdLine, int nCmdShow)
{
	TCHAR szPath[_MAX_PATH];
	LPTSTR szFileName;
	HANDLE hFile = INVALID_HANDLE_VALUE;
	ULONG ulFileLen;

	RETAILMSG(1, (TEXT("<MasgPlay> pCmdLine:0x%X\r\n"), pCmdLine));

	// Use default file if not supplied by caller
	if (*pCmdLine) {
		szFileName = pCmdLine;
		RETAILMSG(1, (TEXT("<MasgPlay> File:%s\r\n"), szFileName));
	} else {
		RETAILMSG(1, (TEXT("Usage: MasgPlay <filename>\r\n")));
		return (0);
	}
	if ( _tcschr(szFileName,(TCHAR)'\\') == NULL) {
		// Default location is in \windows folder
		wsprintf (szPath, TEXT("\\windows\\%s"), szFileName);
	} else {
		// Use supplied path
		_tcscpy (szPath, szFileName);
	}

	// Open the file
	hFile = CreateFile (szPath, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		RETAILMSG(1, (TEXT("<MasgPlay> CreateFile(%s) failed, error %u\r\n"), szPath, GetLastError()));
	} else {
		ulFileLen = SetFilePointer (hFile, 0, NULL, FILE_END);
		RETAILMSG(1, (TEXT("<MasgPlay> Found file %s, length %u bytes\r\n"), szPath, ulFileLen));
		SetFilePointer (hFile, 0, NULL, FILE_BEGIN);

		// Open MASG driver
		g_hMasgDrv = CreateFile (TEXT("MAS1:"), GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
		if (g_hMasgDrv == INVALID_HANDLE_VALUE) {
			RETAILMSG(1, (TEXT("<MasgPlay> Failed to open MASG driver\r\n")));
		} else {
			if ( MasgHasMP3() ) {
				RETAILMSG(1, (TEXT("<MasgPlay> MASG supports MP3\r\n")));
			} else {
				RETAILMSG(1, (TEXT("<MasgPlay> MASG does NOT support MP3\r\n")));
			}
#if 1
			// Play it straight through
			if ( !MasgPlayFile(hFile,FALSE) ) {
				RETAILMSG(1, (TEXT("<MasgPlay> MasgPlayFile() failed\r\n")));
			}
#else
			// Play file & test pause, resume & stop
			if ( !MasgPlayFile(hFile,TRUE) ) {
				RETAILMSG(1, (TEXT("<MasgPlay> MasgPlayFile() failed\r\n")));
			}
#endif
		}
		// Close MASG driver
		CloseHandle(g_hMasgDrv);
	}

	// Close MASG flie
	CloseHandle (hFile);

	RETAILMSG(1, (TEXT("<MasgPlay> done!\r\n")));

	return (0);
}


///////////////////////////////////////////////////////////////////////////
//
// MasgPlayFile() - plays MIDI/MP3 file
//
BOOL MasgPlayFile (HANDLE hFile, BOOL bTest)
{
	PUCHAR pBuf, pPlayBuf[2];
	HANDLE hevCallback;
	ULONG ulFileLen, ulFilePos;
	ULONG cbRead, ulWaitRet, ulState, ulStart, ulSecs;
	ULONG ulVolume = 0xFFFFFFFF;
	BOOL bDonePause, bDoneResume;
	BOOL bRet = TRUE;

	RETAILMSG(1, (TEXT("<MasgPlay> +MasgPlayFile(%u)\r\n"), bTest));

	// Create completion callback event
	hevCallback = CreateEvent (NULL, FALSE, FALSE, NULL);
	if (hevCallback == NULL) {
		RETAILMSG(1, (TEXT("<MasgPlay> Cellback event creation error %u\r\n"), GetLastError()));
		return (FALSE);
	}

	// Allocate file buffer
	pPlayBuf[0] = (PUCHAR) LocalAlloc (LPTR, 2*BUFSIZE);
	if (pPlayBuf[0] == NULL) {
		RETAILMSG(1, (TEXT("<MasgPlay> File buffer allocation error %u\r\n"), GetLastError()));
		CloseHandle (hevCallback);
		return (FALSE);
	}
	pPlayBuf[1] = pPlayBuf[0] + BUFSIZE;
	RETAILMSG(1, (TEXT("<MasgPlay> pPlayBuf[0] : %X\r\n"), pPlayBuf[0]));
	RETAILMSG(1, (TEXT("<MasgPlay> pPlayBuf[1] : %X\r\n"), pPlayBuf[1]));

	// Get file length & return to start of file
	ulFileLen = SetFilePointer (hFile, 0, NULL, FILE_END);
	ulFilePos = SetFilePointer (hFile, 0, NULL, FILE_BEGIN);

	RETAILMSG(1, (TEXT("<MasgPlay> ulFileLen: %u\r\n"), ulFileLen));
	RETAILMSG(1, (TEXT("<MasgPlay> ulFilePos: %u\r\n"), ulFilePos));

	// Fill first buffer
	pBuf = pPlayBuf[0];
	cbRead = FillBuffer (hFile, pBuf, ulFilePos, ulFileLen);
	if (!cbRead) {
		RETAILMSG(1, (TEXT("<MasgPlay> File read error %u\r\n"), GetLastError()));
		LocalFree (pPlayBuf[0]);
		CloseHandle (hevCallback);
		return (FALSE);
	}
	ulFilePos += cbRead;

	// Start playback
	if ( !MasgStart(pBuf,cbRead,&hevCallback) ) {
		RETAILMSG(1, (TEXT("<MasgPlay> MASG start error\r\n")));
		bRet = FALSE;
	} else {

		if (ulFilePos < ulFileLen) {
			// Fill next buffer & pass to driver
			pBuf = (pBuf == pPlayBuf[0])? pPlayBuf[1]: pPlayBuf[0];
			cbRead = FillBuffer (hFile, pBuf, ulFilePos, ulFileLen);
			if (!cbRead) {
				RETAILMSG(1, (TEXT("<MasgPlay> File read error %u\r\n"), GetLastError()));
				LocalFree (pPlayBuf[0]);
				CloseHandle (hevCallback);
				return (FALSE);
			}
			ulFilePos += cbRead;
			// Pass to driver
			if ( !MasgWrite(pBuf,cbRead) ) {
				RETAILMSG(1, (TEXT("<MasgPlay> MASG write error\r\n")));
				bRet = FALSE;
			}
		}

		// Pass audio data until completion
		ulStart = GetTickCount();
		ulSecs = 0;
		bDonePause = FALSE;
		bDoneResume = FALSE;
		while (TRUE) {
			ulWaitRet = WaitForSingleObject (hevCallback, 2000);

			ulState = MasgState();
			RETAILMSG(1, (TEXT("<MasgPlay> MASG state %u, %d ms, position %u of %u\r\n"), 
				ulState, GetTickCount()-ulStart, MasgGetPosition(), ulFileLen));

			if (ulWaitRet == WAIT_OBJECT_0) {
				if (ulState < MASG_DONE) {
					// Driver has swapped buffers
					if (ulFilePos < ulFileLen) {
						// Fill next buffer & pass to driver
						pBuf = (pBuf == pPlayBuf[0])? pPlayBuf[1]: pPlayBuf[0];
						cbRead = FillBuffer (hFile, pBuf, ulFilePos, ulFileLen);
						if (!cbRead) {
							RETAILMSG(1, (TEXT("<MasgPlay> File read error %u\r\n"), GetLastError()));
							LocalFree (pPlayBuf[0]);
							CloseHandle (hevCallback);
							return (FALSE);
						}
						ulFilePos += cbRead;
						// Pass to driver
						if ( !MasgWrite(pBuf,cbRead) ) {
							RETAILMSG(1, (TEXT("<MasgPlay> MASG write error\r\n")));
							bRet = FALSE;
						}
					}
				} else {
					RETAILMSG(1, (TEXT("<MasgPlay> MASG finished\r\n")));
					break;
				}
			}
			if (bTest) {
				// Test pause, resume and stop
				if (ulState < MASG_PLAYING) {
					ulStart = GetTickCount();
				} else if ( (GetTickCount()-ulStart)/1000 != ulSecs) {
					ulSecs = (GetTickCount() - ulStart) / 1000;
					if (ulSecs > 2 && !bDonePause) {
						RETAILMSG(1, (TEXT("<MasgPlay> Pausing...\r\n")));
						MasgPause();
						bDonePause = TRUE;
					} else if (ulSecs > 4 && !bDoneResume) {
						RETAILMSG(1, (TEXT("<MasgPlay> Resuming...\r\n")));
						MasgResume();
						bDoneResume = TRUE;
					} else if (ulSecs > 6) {
						RETAILMSG(1, (TEXT("<MasgPlay> Stopping...\r\n")));
						MasgStop();
					}
				}
				// Modify volume
				if (ulVolume > 0) {
					ulVolume -= 0x33333333;
					MasgSetVolume (ulVolume);
					if (ulVolume == 0) {
						ulVolume = 0xFFFFFFFF;
					}
					RETAILMSG(1, (TEXT("<MasgPlay> GetVolume = %X\r\n"), MasgGetVolume()));
				}
			}
		}
	}

	// Free event & buffer
	CloseHandle (hevCallback);
	LocalFree (pPlayBuf[0]);

	return (bRet);
}


///////////////////////////////////////////////////////////////////////////
//
// FillBuffer() - read file data to buffer
//
DWORD FillBuffer (HANDLE hFile, PUCHAR pBuf, ULONG ulFilePos, ULONG ulFileLen)
{
	DWORD cbToRead, cbRead;

	cbToRead = min (BUFSIZE, ulFileLen-ulFilePos);
	if ( !ReadFile (hFile,pBuf,cbToRead,&cbRead,NULL) ) {
		RETAILMSG(1, (TEXT("<MasgPlay> File read error %u\r\n"), GetLastError()));
		cbRead = 0;
	}
	RETAILMSG(1, (TEXT("<MasgPlay> Read %u bytes to buffer %X\r\n"), cbRead, pBuf));

	return (cbRead);
}


///////////////////////////////////////////////////////////////////////////
//
// MasgStart() - start MASG playback
//
BOOL MasgStart (PUCHAR pBuf, DWORD cbBuf, PHANDLE phevCallback)
{
	BOOL bRet = TRUE;

	// Pass buffer to MASG driver for playback
	if ( !DeviceIoControl(g_hMasgDrv,IOCTL_OEM_MASG_START,pBuf,cbBuf,(PBYTE)phevCallback,sizeof(HANDLE),NULL,NULL) ) {
		RETAILMSG(1, (TEXT("<MasgPlay> MasgStart error\r\n")));
		bRet = FALSE;
	}

	return (bRet);
}


///////////////////////////////////////////////////////////////////////////
//
// MasgWrite() - write next buffer to MASG
//
BOOL MasgWrite (PUCHAR pBuf, DWORD cbBuf)
{
	BOOL bRet = TRUE;

	// Pass buffer to MASG driver for playback
	if ( !DeviceIoControl(g_hMasgDrv,IOCTL_OEM_MASG_WRITE,pBuf,cbBuf,NULL,0,NULL,NULL) ) {
		RETAILMSG(1, (TEXT("<MasgPlay> MasgWrite error\r\n")));
		bRet = FALSE;
	}

	return (bRet);
}


///////////////////////////////////////////////////////////////////////////
//
// MasgStop() - stop MASG playback
//
BOOL MasgStop (void)
{
	BOOL bRet = TRUE;

	// Stop MASG playback
	if ( !DeviceIoControl(g_hMasgDrv,IOCTL_OEM_MASG_STOP,NULL,0,NULL,0,NULL,NULL) ) {
		RETAILMSG(1, (TEXT("<MasgPlay> MasgStop error\r\n")));
		bRet = FALSE;
	}

	return (bRet);
}


///////////////////////////////////////////////////////////////////////////
//
// MasgPause() - pause MASG playback
//
BOOL MasgPause (void)
{
	BOOL bRet = TRUE;

	// Pause MASG playback
	if ( !DeviceIoControl(g_hMasgDrv,IOCTL_OEM_MASG_PAUSE,NULL,0,NULL,0,NULL,NULL) ) {
		RETAILMSG(1, (TEXT("<MasgPlay> MasgPause error\r\n")));
		bRet = FALSE;
	}

	return (bRet);
}


///////////////////////////////////////////////////////////////////////////
//
// MasgResume() - resume MASG playback
//
BOOL MasgResume (void)
{
	BOOL bRet = TRUE;

	// Resume MASG playback
	if ( !DeviceIoControl(g_hMasgDrv,IOCTL_OEM_MASG_RESUME,NULL,0,NULL,0,NULL,NULL) ) {
		RETAILMSG(1, (TEXT("<MasgPlay> MasgResume error\r\n")));
		bRet = FALSE;
	}

	return (bRet);
}


///////////////////////////////////////////////////////////////////////////
//
// MasgState() - gets MASG state
//
DWORD MasgState (void)
{
	DWORD dwState;

	// Get MASG state
	if ( !DeviceIoControl(g_hMasgDrv,IOCTL_OEM_MASG_STATE,NULL,0,(PBYTE)&dwState,sizeof(dwState),NULL,NULL) ) {
		RETAILMSG(1, (TEXT("<MasgPlay> MasgState error\r\n")));
		dwState = MASG_UNKNOWN;
	}

	return (dwState);
}


///////////////////////////////////////////////////////////////////////////
//
// MasgGetPosition() - gets MASG playback position (bytes)
//
DWORD MasgGetPosition (void)
{
	DWORD dwBytePos;

	// Get MASG volume
	if ( !DeviceIoControl(g_hMasgDrv,IOCTL_OEM_MASG_GETPOSITION,NULL,0,(PBYTE)&dwBytePos,sizeof(dwBytePos),NULL,NULL) ) {
		RETAILMSG(1, (TEXT("<MasgPlay> MasgGetPosition error\r\n")));
		dwBytePos = 0;
	}

	return (dwBytePos);
}


///////////////////////////////////////////////////////////////////////////
//
// MasgGetVolume() - gets MASG volume
//
DWORD MasgGetVolume (void)
{
	DWORD dwVolume;

	// Get MASG volume
	if ( !DeviceIoControl(g_hMasgDrv,IOCTL_OEM_MASG_GETVOLUME,NULL,0,(PBYTE)&dwVolume,sizeof(dwVolume),NULL,NULL) ) {
		RETAILMSG(1, (TEXT("<MasgPlay> MasgGetVolume error\r\n")));
		dwVolume = 0;
	}

	return (dwVolume);
}


///////////////////////////////////////////////////////////////////////////
//
// MasgSetVolume() - sets MASG volume
//
BOOL MasgSetVolume (DWORD dwVolume)
{
	BOOL bRet = TRUE;

	RETAILMSG(1, (TEXT("<MasgPlay> MasgSetVolume(%X)\r\n"), dwVolume));

	// Set MASG volume
	if ( !DeviceIoControl(g_hMasgDrv,IOCTL_OEM_MASG_SETVOLUME,(PBYTE)&dwVolume,sizeof(dwVolume),NULL,0,NULL,NULL) ) {
		RETAILMSG(1, (TEXT("<MasgPlay> MasgSetVolume error\r\n")));
		bRet = FALSE;
	}

	return (bRet);
}


///////////////////////////////////////////////////////////////////////////
//
// MasgHasMP3() - returns TRUE if MASG supports MP3 decode
//
BOOL MasgHasMP3 (void)
{
	BOOL bRet = TRUE;

	// Pass buffer to MASG driver for playback
	if ( !DeviceIoControl(g_hMasgDrv,IOCTL_OEM_MASG_HAS_MP3,NULL,0,&bRet,sizeof(bRet),NULL,NULL) ) {
		RETAILMSG(1, (TEXT("<MasgPlay> MasgHasMP3 error\r\n")));
		bRet = FALSE;
	}

	return (bRet);
}
