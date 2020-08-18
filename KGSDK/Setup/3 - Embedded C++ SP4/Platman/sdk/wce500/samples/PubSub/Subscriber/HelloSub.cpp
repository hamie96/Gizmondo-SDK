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

 MODULE:  HelloSub.cpp

 PURPOSE: Implementation of CHelloSub

 COMMENTS: N/A
***********************************************************************/

#include "stdafx.h"
#include "HelloSubscriber.h"
#include "HelloSub.h"
#include "CePubSub_i.c"

/////////////////////////////////////////////////////////////////////////////
// CHelloSub

//**********************************************************************
STDMETHODIMP CHelloSub::Write(DWORD dwBufSize,
                                  BYTE *pBuf)
//**********************************************************************
{
	BOOL rc = FALSE;
	DWORD pcbWritten = 0;

	rc = ::WriteFile(m_file,pBuf,dwBufSize,&pcbWritten,NULL);
	if(rc)
	{
		return S_OK;
	}
	else
	{
		return HRESULT_FROM_WIN32(GetLastError());
	}
}

        
//**********************************************************************
STDMETHODIMP CHelloSub::Notify( 
            DWORD dwEventCode,
            DWORD dwFlags)
//**********************************************************************
{
    return S_OK;
}


STDMETHODIMP CHelloSub::Close()
{
	::CloseHandle(m_file);
	m_file = NULL;
	return S_OK;
}

STDMETHODIMP CHelloSub::Open(LPCOLESTR filename)
{
	USES_CONVERSION;
    HRESULT hr = S_OK;

	if(m_file)
		Close();

    try
    {
        m_file = ::CreateFile(OLE2T(const_cast<unsigned short *>(filename)),GENERIC_WRITE,0,NULL,CREATE_ALWAYS,
            FILE_ATTRIBUTE_NORMAL, NULL);
    }
    catch (...)
    {
        m_file = INVALID_HANDLE_VALUE;
        hr = E_FAIL;
        _resetstkoflw();
    }

	if(SUCCEEDED(hr) && m_file == INVALID_HANDLE_VALUE)
		hr = HRESULT_FROM_WIN32(GetLastError());

    return hr;
}

HRESULT CHelloSub::FinalConstruct()
{
	m_file = NULL;
	return S_OK;
}

void CHelloSub::FinalRelease()
{
	Close();
}
