/*++
Copyright (c) Microsoft Corporation

Module Name:   rcomhelper.h

Abstract:  
    RCOM Helper Functions
Functions:


Notes: 

--*/


#ifndef _RCOMHELPER_H_
#define _RCOMHELPER_H_

#ifdef UNICODE
#define RegisterObject     RegisterObjectW
#define RegisterProxyStub  RegisterProxyStubW
#else
#define RegisterObject     RegisterObjectA
#define RegisterProxyStub  RegisterProxyStubA
#endif

#ifdef __cplusplus
    extern "C"
    {
#endif

HRESULT RegisterObjectA(REFCLSID rclsid, const char *szFriendlyName, const char *szDllPath);
HRESULT RegisterObjectW(REFCLSID rclsid, const WCHAR *szFriendlyName, const WCHAR *szDllPath);
HRESULT UnregisterObject(REFCLSID rclsid);

HRESULT RegisterProxyStubA(REFIID riid, REFCLSID rclsid, const char *szFriendlyName, const char *szDLLPath);
HRESULT RegisterProxyStubW(REFIID riid, REFCLSID rclsid, const WCHAR *szFriendlyName, const WCHAR *szDLLPath);
HRESULT UnregisterProxyStub (REFIID riid);

#ifdef __cplusplus
    }
#endif

#endif //_RCOMHELPER_H_