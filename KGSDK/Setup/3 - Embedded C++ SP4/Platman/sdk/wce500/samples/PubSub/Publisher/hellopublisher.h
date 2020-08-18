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

 MODULE:    HelloPublisher.h

 PURPOSE:   HelloPublisher.h: interface for the CHelloPublisher class

 COMMENTS: N/A
***********************************************************************/

#if !defined(AFX_HELLOPUBLISHER_H__F329BFF2_0897_47F0_9E72_1B341C8C2BB0__INCLUDED_)
#define AFX_HELLOPUBLISHER_H__F329BFF2_0897_47F0_9E72_1B341C8C2BB0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef _IHelloPublisher_H
#include "IHelloPublisher.h"
#endif

// {3D516500-698D-47e2-8090-E410951BBA0B}
DEFINE_GUID(CLSID_HelloPublisher, 
0x3d516500, 0x698d, 0x47e2, 0x80, 0x90, 0xe4, 0x10, 0x95, 0x1b, 0xba, 0xb);

class CHelloPublisher : public IHelloPublisher  
{
public:
	CHelloPublisher();
	virtual ~CHelloPublisher();

    // IUnknown Methods
    STDMETHOD  (QueryInterface)(REFIID riid, void **ppv);
    STDMETHOD_ (ULONG, AddRef)(void);
    STDMETHOD_ (ULONG, Release)(void);

    // IPublisher Method
    STDMETHOD (Control)(DWORD dwControl, DWORD dwBufSize,BYTE *pbData);

    // IPublisherManagement Method
    virtual HRESULT STDMETHODCALLTYPE Initialize(
            ISubscriber *pSubscriber,
            BOOL *bUseBuffering,
            DWORD *pdwBufSize);
    STDMETHOD (StopPublishing)(void);
    STDMETHOD (StartPublishing)(void);

    // Support Methods
    static HRESULT RegisterServer(LPCTSTR szDllName);
    static HRESULT UnregisterServer(void);
    static HRESULT CreateInstance(IUnknown *pUnkOuter,
                                  REFIID riid,
                                  void **ppv);

private:
    ISubscriber *m_subscriber;
    LONG        m_lRefCount;
	HANDLE m_thread;

	HRESULT KillThread();
	HRESULT StartThread();
    static DWORD WINAPI UploadProc(LPVOID pParam);
};

#endif // !defined(AFX_HELLOPUBLISHER_H__F329BFF2_0897_47F0_9E72_1B341C8C2BB0__INCLUDED_)
