/*++
THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.
Copyright (c) 1995-2000 Microsoft Corporation

Module Name:   KitlClnt.h

Abstract:  
    This contains declarations the KITL client routines.
Functions:


Notes: 

--*/
#ifndef _KITLCLNT_H_
#define _KITLCLNT_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef UINT KITLID;
#define INVALID_KITLID  ((KITLID) -1)

//////////////////////////////////
// global initializations
//
BOOL KITLInitLibrary (LPCWSTR pszRegKeyRoot);
BOOL KITLDeInitLibrary (void);

//////////////////////////////////
// KITL client functions
//

// client registration/de-registration
KITLID KITLRegisterClient (LPCWSTR pszDevName, LPCWSTR pszSvcName, DWORD dwTimeout, DWORD dwFlags);
BOOL KITLDeRegisterClient (KITLID id);

// send/recv data
BOOL KITLSend (KITLID id, LPCVOID pData, DWORD cbData, DWORD dwTimeout);
BOOL KITLRecv (KITLID id, LPVOID pBuffer, DWORD *pcbBuffer, DWORD dwTimeout);

// config related
BOOL KITLWaitForSvcConnect (KITLID id, DWORD dwTimeout);

// data availability
BOOL KITLIsDataAvailable (KITLID id, DWORD *pcbBuffer);

#ifdef __cplusplus
}
#endif

#endif _KITLCLNT_H_
