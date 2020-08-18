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

 MODULE:  TestDialog.cpp

 COMMENTS: N/A
***********************************************************************/

#include "stdafx.h"
#include "TestDialog.h"

#include "..\\Subscriber\\HelloSubscriber_i.c"
#include "CePubSub_i.c"

// global defines
const GUID g_publisherID = CLSID_HelloPublisher;

// CTestDialog dialog

IMPLEMENT_DYNAMIC(CTestDialog, CDialog)
CTestDialog::CTestDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CTestDialog::IDD, pParent)
{
	m_spSubscriber = NULL;
	m_spPubSubMgr = NULL;
	m_spPublisher = NULL;
}

CTestDialog::~CTestDialog()
{
	if (m_spPubSubMgr)
	{
		m_spPubSubMgr->Unsubscribe(m_guidCookie);
		m_spPubSubMgr.Release();
	}
	if (m_spPublisher)
		m_spPublisher.Release();
	if (m_spSubscriber)
		m_spSubscriber.Release();
}

void CTestDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTestDialog, CDialog)
	ON_BN_CLICKED(IDCONFIGURE, OnBnClickedConfigure)
	ON_BN_CLICKED(IDCONNECT, OnBnClickedConnect)
	ON_BN_CLICKED(IDSTOPCOLLECTION, OnBnClickedStopcollection)
	ON_BN_CLICKED(IDSHUTDOWN, OnBnClickedShutdown)
END_MESSAGE_MAP()


// CTestDialog message handlers

void CTestDialog::OnBnClickedConfigure()
{
	// TODO: Add your control notification handler code here
	m_oDevice.ConfigureDevice(NULL);
}

void CTestDialog::OnBnClickedConnect()
{
	// TODO: Add your control notification handler code here

	// bring up the connect dialog
	GUID platformGuid, deviceGuid;
	HRESULT hr = m_oDevice.SelectDevice(platformGuid,deviceGuid);
	
	// create the subscriber
	if (SUCCEEDED(hr))
	{
		hr = m_spSubscriber.CoCreateInstance(CLSID_HelloSub);
	}

	// open the data file; subscribed data will be written to this file
	if (SUCCEEDED(hr))
	{
			hr = m_spSubscriber->Open(L"PubSubTest.dat");
	}

	// create the pub sub manager
	if(SUCCEEDED(hr))
	{
		hr = m_spPubSubMgr.CoCreateInstance(CLSID_PublishSubscribeMgr);
	}

	// register the publisher
	if(SUCCEEDED(hr))
	{
		hr = m_oDevice.RegisterFile(L"\\Windows\\HelloPublisher.dll");
	}

	if(SUCCEEDED(hr))
	{
		GetDlgItem(IDCSTATUS)->SetWindowText(_T("Subscribing to data from device..."));
		hr = m_spPubSubMgr->Subscribe(platformGuid, deviceGuid, g_publisherID, 
								m_spSubscriber, &m_spPublisher,&m_guidCookie);
	}

	if (FAILED(hr))
	{
		GetDlgItem(IDCSTATUS)->SetWindowText(_T("Failed to subscribe data"));

		if (m_spSubscriber)
			m_spSubscriber.Release();
		if (m_spPubSubMgr)
			m_spPubSubMgr.Release();
		if (m_spPublisher)
			m_spPublisher.Release();
	}

	if (SUCCEEDED(hr))
	{
		GetDlgItem(IDCSTATUS)->SetWindowText(_T("Collecting data from device..."));
		GetDlgItem(IDCONFIGURE)->EnableWindow(FALSE);
		GetDlgItem(IDCONNECT)->EnableWindow(FALSE);
		GetDlgItem(IDSTOPCOLLECTION)->EnableWindow(TRUE);
	}
}

void CTestDialog::OnBnClickedStopcollection()
{
	// TODO: Add your control notification handler code here
	
	// cleanup
	if (m_spPubSubMgr)
	{
		m_spPubSubMgr->Unsubscribe(m_guidCookie);
		m_spPubSubMgr.Release();
	}
	if (m_spSubscriber)
		m_spSubscriber.Release();
	if (m_spPublisher)
		m_spPublisher.Release();

	// disable this button
	GetDlgItem(IDSTOPCOLLECTION)->EnableWindow(FALSE);
	GetDlgItem(IDCONFIGURE)->EnableWindow(TRUE);
	GetDlgItem(IDCONNECT)->EnableWindow(TRUE);

	GetDlgItem(IDCSTATUS)->SetWindowText(_T("Collected data is saved in TestApp.dat file in the current folder."));
}

void CTestDialog::OnBnClickedShutdown()
{
	// TODO: Add your control notification handler code here
	DestroyWindow();
}
