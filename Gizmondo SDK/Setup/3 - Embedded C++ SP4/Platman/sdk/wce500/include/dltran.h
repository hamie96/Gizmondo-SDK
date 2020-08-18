/*++
THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.
Copyright (c) 1995-2000 Microsoft Corporation

Module Name:   DlTran.h

Abstract:  
    This contains declarations the KITL download transport routines.
Functions:


Notes: 

--*/
#ifndef _DOWNLOAD_TRANSPORT_H_
#define _DOWNLOAD_TRANSPORT_H_

#include "KitlTran.h"

#ifdef __cplusplus
extern "C" {
#endif

// typedefs
typedef void (* PFN_ProgressCB) (DWORD uCurrSize, DWORD uTotalSize, LPVOID pUserData);
typedef void (* PFN_BootCB) (LPCWSTR pszDevName, LPVOID pData);

// the types of all the transport export functions
typedef BOOL (* PFN_TRANWAITFORREBOOT) (TRANSPORTID id, DWORD dwTimeout);
typedef BOOL (* PFN_TRANDOWNLOADIMAGE) (TRANSPORTID id, LPCWSTR pszImagePath, PFN_ProgressCB pfnCB, LPVOID pUserData);
typedef BOOL (* PFN_TRANJUMPTOIMAGE) (TRANSPORTID id, DWORD dwJumpFlags);
typedef BOOL (* PFN_TRANSETBOOTCB) (PFN_BootCB pfnCB, LPVOID pUserData);
typedef DWORD (* PFN_TRANGETBOOTFLAG) (TRANSPORTID id);

// library initialization/deinitialization
BOOL DLInitLibrary (LPCWSTR pszRegKeyRoot);
BOOL DLDeInitLibrary (void);

// transport creation/deletion
TRANSPORTID DLCreate (LPCWSTR pszDeviceName);
BOOL DLDelete (TRANSPORTID id);

BOOL DLWaitForReboot (TRANSPORTID id, DWORD dwTimeout);
BOOL DLDownloadImage (TRANSPORTID id, LPCWSTR pszImagePath, PFN_ProgressCB pfnCB, LPVOID pUserData);
BOOL DLJumpToImage (TRANSPORTID id, DWORD dwJumpFlags);

#define	BOOTFLAG_FORCE_DOWNLOAD	0x0001	// always download image
DWORD DLGetBootFlags (TRANSPORTID id);

// device name service
BOOL TranSetBootCB (PFN_BootCB pfnCB, LPVOID pUserData);

// download transport configuration services
BOOL DLGetXMLParams(LPCWSTR *ppstrXML);

BOOL DLSetParam(LPCWSTR strName, LPCWSTR strValue, LPWSTR pstrError, long dwErrorStringSize);

#ifdef __cplusplus
}
#endif


#endif  // _DOWNLOAD_TRANSPORT_H_
