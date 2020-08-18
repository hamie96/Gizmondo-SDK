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

 MODULE:    KTSubSampleDlg.h

 COMMENTS: N/A
***********************************************************************/


#if !defined(AFX_KTSUBSAMPLEDLG_H__35D9CF6E_EEA0_49DE_9449_23A105FC3BDE__INCLUDED_)
#define AFX_KTSUBSAMPLEDLG_H__35D9CF6E_EEA0_49DE_9449_23A105FC3BDE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "KTSub.h"

/////////////////////////////////////////////////////////////////////////////
// CKTSubSampleDlg dialog

class CKTSubSampleDlg : public CDialog
{
// Construction
public:
	CKTSubSampleDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CKTSubSampleDlg)
	enum { IDD = IDD_KTSUBSAMPLE_DIALOG };
	CEdit	m_Output;
	CButton	m_DisconnectButton;
	CButton	m_ConnectButton;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKTSubSampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CKTSubSampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnConnect();
	afx_msg void OnDisconnect();
	afx_msg void OnExit();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void EnableButtons (void);
	BOOL							m_fConnected;
	CComPtr<IKTSubscriber>			m_sub;
public:
	afx_msg void OnBnClickedCollect();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KTSUBSAMPLEDLG_H__35D9CF6E_EEA0_49DE_9449_23A105FC3BDE__INCLUDED_)
