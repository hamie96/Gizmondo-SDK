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

 MODULE:    KTSubSampleDlg.cpp

 COMMENTS: N/A
***********************************************************************/

#include "stdafx.h"
#include "KTSubSample.h"
#include "KTSubSampleDlg.h"
#include "KTSub_i.c"

// Disable the zero-byte member of structure warning 
//
#pragma warning (disable : 4200)
#include "CELog.h"
#pragma warning (default : 4200)

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define ID_UPDATEKT 0x01

/////////////////////////////////////////////////////////////////////////////
// CELog Helper Functions
inline BOOL IsTimestamp(void *pv)
{
	return *(DWORD*)pv & 0x80000000; 
}

inline WORD GetType(void *pv)
{
	return (WORD) ((*(DWORD*)pv >> 16) & 0x7FFF); 
}

inline void* GetDataStart(void *pv)
{ 
	return (void*)((BYTE*)pv + sizeof(DWORD) + (IsTimestamp(pv)?sizeof(DWORD):0)); 
}

inline WORD GetSize(void *pv)
{
	// sum of the size of the actual packet, the header and optional timestamp
	WORD wLen = (WORD) (*(DWORD*)pv & 0xFFFF);
	wLen = (wLen + 3) & ~3;
	return wLen	+ sizeof(DWORD) + (IsTimestamp(pv)?sizeof(DWORD):0);
}

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKTSubSampleDlg dialog

CKTSubSampleDlg::CKTSubSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CKTSubSampleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CKTSubSampleDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CKTSubSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CKTSubSampleDlg)
	DDX_Control(pDX, IDC_OUTPUT, m_Output);
	DDX_Control(pDX, IDC_DISCONNECT, m_DisconnectButton);
	DDX_Control(pDX, IDC_CONNECT, m_ConnectButton);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CKTSubSampleDlg, CDialog)
	//{{AFX_MSG_MAP(CKTSubSampleDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CONNECT, OnConnect)
	ON_BN_CLICKED(IDC_DISCONNECT, OnDisconnect)
	ON_BN_CLICKED(ID_EXIT, OnExit)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_COLLECT, OnBnClickedCollect)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKTSubSampleDlg message handlers

BOOL CKTSubSampleDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CoInitializeEx (NULL, COINIT_MULTITHREADED);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CKTSubSampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CKTSubSampleDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CKTSubSampleDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CKTSubSampleDlg::OnConnect() 
{
	HRESULT hr;
	CString Connecting;

	Connecting.LoadString (IDS_CONNECTING);

	m_Output.SetWindowText (Connecting);

	hr = m_sub.CoCreateInstance(CLSID_KTSubscriber);
	if(FAILED(hr))
	{
		AfxMessageBox (IDS_UNABLETOCREATEINSTANCE);
		return;
	}

	hr = m_sub->Initialize (GUID_NULL, GUID_NULL);
	if (FAILED(hr))
	{
		m_sub.Release();
		AfxMessageBox (IDS_FAILEDTOCONNECT);
		return;
	}

	m_Output.SetSel(0, -1);
	m_Output.ReplaceSel(_T("Connected to device. Click on Collect Data to get CELOG data.\r\n"));

	m_fConnected = TRUE;

	EnableButtons();
}

void CKTSubSampleDlg::OnDisconnect() 
{
	if (m_fConnected)
	{
		if(m_sub)
		{
			HRESULT hr;

			hr = m_sub->ShutDown();
			if (FAILED(hr))
			{
				AfxMessageBox (IDS_FAILEDTOSHUTDOWN);
			}

			m_sub.Release();
		}

		m_fConnected = FALSE;
	}

	EnableButtons();
}

void CKTSubSampleDlg::OnExit() 
{
	EndDialog(IDOK);
}

//void CKTSubSampleDlg::OnTimer(UINT nIDEvent) 
void CKTSubSampleDlg::OnBnClickedCollect() 
{
	m_Output.SetSel(0, -1);
	m_Output.ReplaceSel(_T("Virtual Alloc/Copy/Free events in 10000 CELOG events:\r\n"));

	int nIndex = 0;
	{
		while (m_fConnected && (nIndex < 10000))
		{
			DWORD	dwBytesRead = 0;
			PBYTE	pbData		= NULL;
			HRESULT hr;

			hr = m_sub->ReadEvent (NULL, &dwBytesRead);
			if (dwBytesRead && (SUCCEEDED(hr) || (hr == HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER))))
			{
				// dwBytes now contains the required size to read a
				// single CELog Event
				//
				pbData = reinterpret_cast <PBYTE> (HeapAlloc(GetProcessHeap(), 0, dwBytesRead));
				if (pbData)
				{
					hr = m_sub->ReadEvent (pbData, &dwBytesRead);
					if (SUCCEEDED(hr))
					{
						DWORD	dwDataType = GetType(pbData);
						BOOL	fStringSet = TRUE;
						CString String;

						switch (dwDataType)
						{
							case CELID_VIRTUAL_ALLOC:
								{
									PCEL_VIRTUAL_ALLOC pVirtualAlloc;
									pVirtualAlloc = reinterpret_cast <PCEL_VIRTUAL_ALLOC> (GetDataStart(pbData));

									String.Format(IDS_VIRTUALALLOC, 
												  pVirtualAlloc->dwResult,
												  pVirtualAlloc->dwAddress,
												  pVirtualAlloc->dwType,
												  pVirtualAlloc->dwProtect);

								}
								break;

							case CELID_VIRTUAL_COPY:
								{
									PCEL_VIRTUAL_COPY pVirtualCopy;

									pVirtualCopy = reinterpret_cast <PCEL_VIRTUAL_COPY> (GetDataStart(pbData));

									String.Format(IDS_VIRTUALCOPY,
												  pVirtualCopy->dwDest,
												  pVirtualCopy->dwSource,
												  pVirtualCopy->dwSize,
												  pVirtualCopy->dwProtect);
								}
								break;

							case CELID_VIRTUAL_FREE:
								{
									PCEL_VIRTUAL_FREE pVirtualFree;

									pVirtualFree = reinterpret_cast <PCEL_VIRTUAL_FREE> (GetDataStart(pbData));

									String.Format(IDS_VIRTUALFREE,
												  pVirtualFree->dwAddress,
												  pVirtualFree->dwSize,
												  pVirtualFree->dwType);

								}
								break;

							default:
								fStringSet = FALSE;
								// Don't care about any other types
								//
								break;
						}

						if (fStringSet)
						{
							m_Output.SetSel(-1, -1);
							m_Output.ReplaceSel(String);
						}
					}

					HeapFree (GetProcessHeap(), 0, pbData);
				}
				else
					break;
				nIndex++;
			}
		}
	}
	m_Output.SetSel(-1, -1);
	m_Output.ReplaceSel(_T("Done.\r\n\n"));
}

void CKTSubSampleDlg::OnDestroy() 
{
	OnDisconnect();

	CDialog::OnDestroy();
}

void CKTSubSampleDlg::EnableButtons()
{
	m_DisconnectButton.EnableWindow (m_fConnected);
	GetDlgItem(IDC_COLLECT)->EnableWindow (m_fConnected);
	m_ConnectButton.EnableWindow(!m_fConnected);
}

