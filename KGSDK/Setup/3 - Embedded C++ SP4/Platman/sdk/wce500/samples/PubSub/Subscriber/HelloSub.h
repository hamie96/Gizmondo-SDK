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

 MODULE:  HelloSub.h

 COMMENTS: N/A
***********************************************************************/


#ifndef __HELLOSUB_H_
#define __HELLOSUB_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CHelloSub
class ATL_NO_VTABLE CHelloSub : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CHelloSub, &CLSID_HelloSub>,
	public IHelloSub
{
public:
	CHelloSub()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_HELLOSUB)
DECLARE_NOT_AGGREGATABLE(CHelloSub)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CHelloSub)
	COM_INTERFACE_ENTRY(ISubscriber)
	COM_INTERFACE_ENTRY(IHelloSub)
END_COM_MAP()

// IHelloSub
public:
    STDMETHOD(Write)( 
            /* [in] */ DWORD dwBufSize,
            /* [size_is][in] */ BYTE /*__RPC_FAR */ *pbData);
        
    STDMETHOD(Notify)( 
            DWORD dwEventCode,
            DWORD dwFlags);
	
	STDMETHOD(Close)();
	STDMETHOD(Open)(LPCOLESTR filename);

	HRESULT FinalConstruct();
	void FinalRelease();

private:
	HANDLE m_file;
};

#endif //__HELLOSUB_H_
