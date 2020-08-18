/*++

Copyright (c) 1999-2001 Microsoft Corporation.  All rights reserved.

Module Name: rds.h

Purpose: Master include file for RCOM.

--*/

#ifndef _RDS_H_
#define _RDS_H_

// {5B61A5CA-E71F-11d3-B0F6-00508B012095}
DEFINE_GUID(
    IID_IRDSDeviceManager,
    0x5b61a5ca, 0xe71f, 0x11d3, 0xb0, 0xf6, 0x0, 0x50, 0x8b, 0x1, 0x20, 0x95
    );

// Forward decl for IRDSProxy
interface IRDSProxy;

interface IRDSDeviceManager : public IUnknown
{
    virtual HRESULT DownloadPackage(GUID PackageID) = 0;
    virtual HRESULT RegisterFile(LPOLESTR fileName) = 0;
    virtual HRESULT Launch(LPCOLESTR pszRemotePath, LPCOLESTR pszCmdLine) = 0;
    virtual HRESULT CreateObject(
            REFCLSID rclsid,
            REFIID riid,
            LPVOID *ppv) = 0;
    virtual HRESULT GetConnectionIDs(GUID *pPlatformID, GUID *pDeviceID) = 0;
};


// {5B61A5C2-E71F-11d3-B0F6-00508B012095}
DEFINE_GUID(
    IID_IPSManager,
    0x5b61a5c2, 0xe71f, 0x11d3, 0xb0, 0xf6, 0x0, 0x50, 0x8b, 0x1, 0x20, 0x95
    );


#define FACILITY_PSMGR              512

#define PSMGR_INVALID_COOKIE_ERR    0x01
#define PSMGR_INVALID_BUFFER_ERR    0x02

#define PSMGR_E_INVALID_COOKIE      MAKE_HRESULT(1, FACILITY_PSMGR, PSMGR_INVALID_COOKIE_ERR)
#define PSMGR_E_INVALID_BUFFER      MAKE_HRESULT(1, FACILITY_PSMGR, PSMGR_INVALID_BUFFER_ERR)

interface IPSManager : public IUnknown
{
    virtual HRESULT CreateProxyStub(
            LPVOID  lpvCookie,
            REFIID  riid,
            LPVOID  pRemoteIFace,
            LPVOID  *ppv
            ) = 0;
    virtual HRESULT DeleteProxyStub (LPVOID lpvCookie) = 0;
    virtual HRESULT MakeRemoteMethodCall(
            LPVOID lpvCookie,
            REFIID riid,
            DWORD dwMethodId,
            LPVOID pvInBuf,
            DWORD dwInLen,
            LPVOID *ppvOutBuf,
            LPDWORD pdwOutLen
            ) = 0;
    virtual HRESULT GetDefaultImpl(
            REFIID riid,
            LPVOID *ppv
            ) = 0;
    virtual HRESULT ReleaseRemoteInterface (
            LPVOID  lpvCookie,
            IN IUnknown *pRemoteIFace,
            OUT ULONG *pulRefcount
            ) = 0;
    virtual LPVOID AllocInputBuffer(ULONG ulBufSize) = 0;
    virtual BOOL FreeInputBuffer(LPVOID lpv) = 0;
    virtual LPVOID AllocOutputBuffer(ULONG ulBufSize) = 0;
    virtual BOOL FreeOutputBuffer(LPVOID lpv) = 0;

    virtual HRESULT ProxyRelease (LPVOID pInterface,ULONG *pulRefCount) = 0;
    virtual HRESULT ProxyAddRef(LPVOID pInterface,ULONG *pulRefCount) = 0;
};


// {DAAC2F50-D4A6-11d3-B2D5-00D0B723357C}
DEFINE_GUID(
    IID_IRDSProxy,
    0xdaac2f50, 0xd4a6, 0x11d3, 0xb2, 0xd5, 0x0, 0xd0, 0xb7, 0x23, 0x35, 0x7c
    );

interface IRDSProxy
{
    virtual HRESULT STDMETHODCALLTYPE SetProxyInfo(IPSManager  *pPSManager,
                                                   LPVOID      pCookie) = 0;
    virtual HRESULT STDMETHODCALLTYPE ProxyQueryInterface(REFIID riid, void **ppv) = 0;
    virtual VOID STDMETHODCALLTYPE ReleaseObject() = 0;
};


// {DAAC2F51-D4A6-11d3-B2D5-00D0B723357C}
DEFINE_GUID(
    IID_IRDSStub,
    0xdaac2f51, 0xd4a6, 0x11d3, 0xb2, 0xd5, 0x0, 0xd0, 0xb7, 0x23, 0x35, 0x7c
    );

interface IRDSStub
{
    virtual HRESULT STDMETHODCALLTYPE SetStubInfo(IPSManager *pPSMgr,
                                                  LPVOID lpvCookie,
                                                  LPVOID pvTarget) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetTarget(LPVOID *ppvTarget) = 0;
    virtual VOID STDMETHODCALLTYPE MakeMethodCall (
            REFIID iid,
            DWORD dwMethodId,
            LPVOID pvInBuf,
            DWORD dwInBufSize,
            LPVOID *ppvOutBuf,
            PDWORD pdwOutBufSize
            ) = 0;
    virtual VOID STDMETHODCALLTYPE ReleaseObject() = 0;
};


// {642410D0-E651-11d3-B0F6-00508B012095}
DEFINE_GUID(
    IID_IDefUnknown,
    0x642410d0, 0xe651, 0x11d3, 0xb0, 0xf6, 0x0, 0x50, 0x8b, 0x1, 0x20, 0x95
    );

interface IDefUnknown
{
    virtual HRESULT STDMETHODCALLTYPE DefQueryInterface(
            LPVOID lpvCookie,
            REFIID riid,
            void **ppvObject
            ) = 0;
    virtual ULONG STDMETHODCALLTYPE DefAddRef(LPVOID lpv) = 0;
    virtual ULONG STDMETHODCALLTYPE DefRelease(LPVOID lpv) = 0;
};

#ifdef __cplusplus
    extern "C"
    {
#endif

HRESULT CreateDeviceManager(
        HWND hParentWnd,
        GUID *pguidPlatform,
        GUID *pguidDevice,
        IRDSDeviceManager **ppDeviceManager,
        WCHAR * wszRCOMSvr = NULL,
		WCHAR * wszCmdLine = NULL,
        GUID StreamGuid = GUID_NULL
        );

#ifdef __cplusplus
    }
#endif

#endif  // _RDS_H_
