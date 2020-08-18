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
//**********************************************************************
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// MODULE: cetickstats.cpp
//**********************************************************************

#include <windows.h>
//----------------------------------------------------------------------
// TODO: Enter the list aliases for standard function names
//----------------------------------------------------------------------
const PTCHAR szSetITLConnection = TEXT("SetITLConnectionCETickStats");
const PTCHAR szOpen             = TEXT("OpenCETickStats");
const PTCHAR szCollect          = TEXT("CollectCETickStats");
const PTCHAR szClose            = TEXT("CloseCETickStats");

HINSTANCE g_hLibModule;

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    g_hLibModule = (HINSTANCE)hModule;// save the library module
    return TRUE;
}

STDAPI DllRegisterServer(void)
{
    HRESULT hr = S_OK;                  // function return value
    HKEY hKey = NULL;
    DWORD dwDisp = 0;
    DWORD cbData = 0;
    TCHAR szLibPath[MAX_PATH];

    //------------------------------------------------------------------
    // TODO: Replace the second parameter with the appropriate
    //       subkey name
    //------------------------------------------------------------------
    hr = RegCreateKeyEx(HKEY_LOCAL_MACHINE,// handle to open key
                       TEXT("System\\CurrentControlSet\\Services\\CETickStats_420\\Performance"),// subkey name
                        0,// reserved
                        NULL,// class string
                        0,// special options
                        KEY_ALL_ACCESS,// desired security access
                        NULL,// inheritance
                        &hKey,// key handle
                        &dwDisp); // disposition value buffer

    if(hr == S_OK)
    {
        // Get Library path
        if(!GetModuleFileName(g_hLibModule,szLibPath,MAX_PATH))
        {
            hr = E_FAIL;
        }
    }

    if(hr == S_OK)
    {
        cbData = strlen(szLibPath)*sizeof(TCHAR);
        hr = RegSetValueEx( hKey,           // handle to key
                            TEXT("CEPerfLibrary_420"), // value name
                            0,      // reserved
                            REG_SZ,// value type
                            (LPBYTE)szLibPath,// value data
                            cbData);// size of value data
    }



    if(hr == S_OK)
    {
        cbData = strlen(szSetITLConnection)*sizeof(TCHAR);
        hr = RegSetValueEx( hKey,           // handle to key
                            TEXT("SetDeviceConnection"), // value name
                            0,      // reserved
                            REG_SZ,// value type
                            (LPBYTE)szSetITLConnection,// value data
                            cbData);// size of value data


    }

    if(hr == S_OK)
    {
        cbData = strlen(szOpen)*sizeof(TCHAR);
        hr = RegSetValueEx( hKey,           // handle to key
                            TEXT("Open"), // value name
                            0,      // reserved
                            REG_SZ,// value type
                            (LPBYTE)szOpen,// value data
                            cbData);// size of value data


    }

    if(hr == S_OK)
    {
        cbData = strlen(szCollect)*sizeof(TCHAR);
        hr = RegSetValueEx( hKey,           // handle to key
                            TEXT("Collect"), // value name
                            0,      // reserved
                            REG_SZ,// value type
                            (LPBYTE)szCollect,// value data
                            cbData);// size of value data


    }

    if(hr == S_OK)
    {
        cbData = strlen(szClose)*sizeof(TCHAR);
        hr = RegSetValueEx( hKey,           // handle to key
                            TEXT("Close"), // value name
                            0,      // reserved
                            REG_SZ,// value type
                            (LPBYTE)szClose,// value data
                            cbData);// size of value data

    }

    if(hKey) RegCloseKey(hKey);


    return hr;

}


STDAPI DllUnregisterServer(void)
{

    HRESULT hr = S_OK;

    //------------------------------------------------------------------
    // TODO: Replace the text with the appropriate subkey names
    //------------------------------------------------------------------
    RegDeleteKey(HKEY_LOCAL_MACHINE,TEXT("System\\CurrentControlSet\\Services\\CETickStats_420\\Performance"));
    RegDeleteKey(HKEY_LOCAL_MACHINE,TEXT("System\\CurrentControlSet\\Services\\CETickStats_420"));

    return hr;

}
