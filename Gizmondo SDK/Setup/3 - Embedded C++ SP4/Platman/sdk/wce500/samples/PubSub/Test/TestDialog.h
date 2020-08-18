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

 MODULE:  TestDialog.h

 COMMENTS: N/A
***********************************************************************/

#ifndef _TESTDIALOG_H
#define _TESTDIALOG_H

#include "stdafx.h"
#include "device.h"
#include "..\\Subscriber\\HelloSubscriber.h"
#include "..\\Publisher\\HelloPublisher.h"
#include "..\\Publisher\\IHelloPublisher.h"
#include "CePubSub.h"

#include "resource.h"

// CTestDialog dialog

class CTestDialog : public CDialog
{
	DECLARE_DYNAMIC(CTestDialog)

public:
	CTestDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTestDialog();

// Dialog Data
	enum { IDD = IDD_PUBSUBTEST_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedConfigure();
	afx_msg void OnBnClickedConnect();
	afx_msg void OnBnClickedStopcollection();
	afx_msg void OnBnClickedShutdown();

private:
	GUID m_guidCookie;
	CDevice m_oDevice;
	CComPtr<IHelloSub> m_spSubscriber;
	CComPtr<IPublisher> m_spPublisher;
	CComPtr<IPublishSubscribeMgr> m_spPubSubMgr;
};

#endif
