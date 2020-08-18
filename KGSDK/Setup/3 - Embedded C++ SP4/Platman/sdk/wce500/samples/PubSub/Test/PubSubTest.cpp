// PubSubTest.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "PubSubTest.h"
#include "TestDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPubSubTestApp

BEGIN_MESSAGE_MAP(CPubSubTestApp, CWinApp)
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()


// CPubSubTestApp construction

CPubSubTestApp::CPubSubTestApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CPubSubTestApp object

CPubSubTestApp theApp;


// CPubSubTestApp initialization

BOOL CPubSubTestApp::InitInstance()
{
	CWinApp::InitInstance();

	HRESULT hr = CoInitialize(NULL);

	if (SUCCEEDED(hr))
	{
		CTestDialog dlg;
		m_pMainWnd = &dlg;
		dlg.DoModal();

		CoUninitialize();
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
