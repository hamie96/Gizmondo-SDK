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

 MODULE:    HelloPublisher.cpp

 COMMENTS: N/A
***********************************************************************/

// HelloPublisher.cpp: implementation of the CHelloPublisher class.
//
//////////////////////////////////////////////////////////////////////

#include <windows.h>
#include "rcomhelper.h"

#ifdef UNDER_CE
#include "CePubSubPS.h"
#else
#include "CePubSub.h"
#endif

#include "HelloPublisher.h"
const DWORD failed = 0xFFFFFFFF;
extern BOOL g_fDllCanUnload;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CHelloPublisher::CHelloPublisher()
{
    m_lRefCount     = 0;
	m_subscriber	= NULL;
}

CHelloPublisher::~CHelloPublisher()
{
	StopPublishing();
}

//**********************************************************************
HRESULT CHelloPublisher::RegisterServer(
    LPCTSTR szDllName  // Dll name that contains this object
    )
//----------------------------------------------------------------------
//----------------------------------------------------------------------
{
    return RegisterObject(CLSID_HelloPublisher,
                              _T("HelloPublisher: Sample Publisher"),
                              szDllName);
}

//**********************************************************************
HRESULT CHelloPublisher::UnregisterServer(void)
//----------------------------------------------------------------------
//----------------------------------------------------------------------
{
    return UnregisterObject(CLSID_HelloPublisher);
}

//**********************************************************************
HRESULT CHelloPublisher::CreateInstance(
    IUnknown *pUnkOuter,
    REFIID riid,
    void **ppv
    )
//----------------------------------------------------------------------
//----------------------------------------------------------------------
{
    HRESULT hr = E_OUTOFMEMORY;

#ifdef DEBUG
	OutputDebugString(L"*** CHelloPublisher::CreateInstance called");
#endif

    IPublisher *pPub = new CHelloPublisher;

    if (pPub != NULL)
    {
        hr = pPub->QueryInterface(riid, ppv);

        if (FAILED(hr))
        {
#ifdef DEBUG
			OutputDebugString(L"*** CHelloPublisher::CreateInstance failed");
#endif
            delete pPub;
        }
		else
		{
#ifdef DEBUG
			OutputDebugString(L"*** CHelloPublisher::CreateInstance passed");
#endif
		}
    }

    return hr;
}


//**********************************************************************
STDMETHODIMP CHelloPublisher::QueryInterface(
    REFIID riid,
    void **ppv
    )
//----------------------------------------------------------------------
//----------------------------------------------------------------------
{
    HRESULT hr = S_OK;

    if (riid == IID_IUnknown)
	{
#ifdef DEBUG
		OutputDebugString(L"*** CHelloPublisher::QueryInterface IID_IUnknown");
#endif
        *ppv = static_cast<IPublisher *>(this);
	}
    else if (riid == IID_IHelloPublisher)
	{
#ifdef DEBUG
		OutputDebugString(L"*** CHelloPublisher::QueryInterface IID_IHelloPublisher");
#endif
        *ppv = static_cast<IPublisher *>(this);
	}
    else if (riid == IID_IPublisher)
	{
#ifdef DEBUG
		OutputDebugString(L"*** CHelloPublisher::QueryInterface IID_IPublisher");
#endif
        *ppv = static_cast<IPublisher *>(this);
	}
    else if (riid == IID_IPublisherManagement)
	{
#ifdef DEBUG
		OutputDebugString(L"*** CHelloPublisher::QueryInterface IID_IPublisherManagement");
#endif
        *ppv = static_cast<IPublisherManagement *>(this);
	}
    else
	{
#ifdef DEBUG
		OutputDebugString(L"*** CHelloPublisher::QueryInterface E_NOINTERFACE");
#endif
        hr = E_NOINTERFACE;
	}

    if (SUCCEEDED(hr))
    {
        this->AddRef();
    }

    return hr;
}

//**********************************************************************
STDMETHODIMP_ (ULONG) CHelloPublisher::AddRef(void)
//----------------------------------------------------------------------
//----------------------------------------------------------------------
{
    return InterlockedIncrement(&m_lRefCount);
}

//**********************************************************************
STDMETHODIMP_ (ULONG) CHelloPublisher::Release(void)
//----------------------------------------------------------------------
//----------------------------------------------------------------------
{
    ASSERT(m_lRefCount > 0);

    LONG rc = InterlockedDecrement(&m_lRefCount);

    if (rc == 0)
    {
#ifdef DEBUG
		OutputDebugString(L"CHelloPublisher::Release called refcount == 0");
#endif
        delete this;
    }

    return rc;
}

//**********************************************************************
STDMETHODIMP CHelloPublisher::Control(DWORD dwControl, DWORD dwBufSize,BYTE *pbData)
//**********************************************************************
{
	return S_OK;
}

//**********************************************************************
STDMETHODIMP CHelloPublisher::Initialize(ISubscriber *pSubscriber,
                               BOOL *bUseBuffering,
                               DWORD *pdwBufSize)
//**********************************************************************
{
	// Tell the SubscriberManager to use a 1k buffer
    *bUseBuffering = TRUE;
    *pdwBufSize    = 1024;

#ifdef DEBUG
	OutputDebugString(L"*** CHelloPublisher::Initialize called");
#endif

	pSubscriber->AddRef();
	m_subscriber = pSubscriber;

    return S_OK;
}

//**********************************************************************
STDMETHODIMP CHelloPublisher::StartPublishing(void)
//**********************************************************************
{
	HRESULT hr = S_OK;

#ifdef DEBUG
	OutputDebugString(L"*** CHelloPublisher::StartPublishing called");
#endif
	
	StartThread();
	return hr;
}

//**********************************************************************
STDMETHODIMP CHelloPublisher::StopPublishing(void)
//**********************************************************************
{
    HRESULT hr = S_OK;

#ifdef DEBUG
	OutputDebugString(L"*** CHelloPublisher::StopPublishing called");
#endif
	
	KillThread();
	g_fDllCanUnload = TRUE;
    return hr;
}


HRESULT CHelloPublisher::StartThread()
{
	DWORD tid;

	m_thread = (HANDLE)CreateThread(NULL, 0, CHelloPublisher::UploadProc, 
										this, CREATE_SUSPENDED, &tid);

	if(ResumeThread(m_thread) == failed)
			return E_FAIL;

	return S_OK;
}

HRESULT CHelloPublisher::KillThread()
{
	DWORD exitCode;

	(void)WaitForSingleObject(m_thread,INFINITE);

	CloseHandle(m_thread);
	GetExitCodeThread(m_thread,&exitCode);
	return exitCode;
}

DWORD WINAPI CHelloPublisher::UploadProc(LPVOID pParam)
{
	CHelloPublisher *buf;

	WCHAR hello[24];
	HRESULT hr = S_OK;
	DWORD rc = 0;

	buf = (CHelloPublisher *)pParam;
	for(short x = 0;x < 25;x++) 
	{

		// prepare the data
		wsprintf(&hello[0], L"Hello%d\n", x);
		DWORD dataSize = wcslen(hello) * sizeof(WCHAR);
		BYTE* data = (BYTE*)hello;

		// send it to the desktop
		hr = buf->m_subscriber->Write(dataSize,data);

		if(FAILED(hr))
		{
			rc = -1;
			break;
		}
	}

	return rc;
}
