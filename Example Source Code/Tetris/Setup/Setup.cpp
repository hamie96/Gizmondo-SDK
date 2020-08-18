#include "StdAfx.h"
#include "Resource.h"

CComModule _Module;

class CInstallDlg : public CDialogImpl<CInstallDlg>
{
public:
	enum { IDD = IDD_INSTALL };

private:
	LRESULT OnInitDialog (UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		HICON hiconSmall = HICON(::LoadImage(_Module.GetResourceInstance(),MAKEINTRESOURCE(IDI_TETRIS),IMAGE_ICON,16,16,0));
		HICON hiconLarge = HICON(::LoadImage(_Module.GetResourceInstance(),MAKEINTRESOURCE(IDI_TETRIS),IMAGE_ICON,0,0,LR_DEFAULTSIZE));

		// Set the window icon
		SetIcon(hiconSmall,FALSE);
		SetIcon(hiconLarge,TRUE );

		// TODO: Add palette handling for 256 colors

		// Call base class
		DefWindowProc();
		return TRUE;
	}

	LRESULT OnButton (WORD wNotifyCode, WORD nID, HWND hwndCtl, BOOL& bHandled)
	{
		// End the dialog
		EndDialog(nID);
		bHandled = TRUE;
		return 0;
	}

	BEGIN_MSG_MAP(CInstallDlg)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		COMMAND_ID_HANDLER(IDCANCEL, OnButton)
		COMMAND_ID_HANDLER(IDOK,     OnButton)
	END_MSG_MAP()
};

bool WriteResource (int iResource, LPCTSTR lptszFilename)
{
	// Determine resource module handle
	HMODULE hmodRes = _Module.GetResourceInstance();

	// Load the binary resources and write them to a temporary directory
	HRSRC hrsrc = ::FindResource(hmodRes,MAKEINTRESOURCE(iResource),_T("BINARY"));
	if (hrsrc == 0)
	{
		ATLTRACE(_T("Unable to find binary resource %d.\n"),iResource);
		return false;
	}

	// Obtain the size of the resource
	const DWORD dwSize = ::SizeofResource(hmodRes,hrsrc);
	if (dwSize == 0)
	{
		ATLTRACE(_T("Unable to determine size of resource %d.\n"),iResource);
		return false;
	}

	// Load the resource
	HGLOBAL hRes = ::LoadResource(hmodRes,hrsrc);
	if (hRes == 0)
	{
		ATLTRACE(_T("Unable to load resource %d.\n"),iResource);
		return false;
	}

	// Lock the resource into memory
	LPCVOID lpResource = ::LockResource(hRes);
	if (hRes == 0)
	{
		ATLTRACE(_T("Unable to load resource %d.\n"),iResource);
		return false;
	}

	// Create the file
	HANDLE hFile = ::CreateFile(lptszFilename,GENERIC_WRITE,0,0,CREATE_ALWAYS,FILE_ATTRIBUTE_TEMPORARY,0);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		ATLTRACE(_T("Unable to create file %s.\n"), lptszFilename);
		return false;
	}

	// Write the resource data to the file
	DWORD dwWritten = 0;
	if ((::WriteFile(hFile,lpResource,dwSize,&dwWritten,0) == 0) || (dwSize != dwWritten))
	{
		ATLTRACE(_T("Unable to write to file %s.\n"), lptszFilename);
		::CloseHandle(hFile);
		return false;
	}

	// Close the file and return successfully
	::CloseHandle(hFile);
	return true;
}

int WINAPI _tWinMain (HINSTANCE hinst, HINSTANCE hinstPrev, LPTSTR lpCmdLine, int nCmdShow)
{
	// Initialize the module
	_Module.Init(0,hinst);

	// Display the install dialog
	CInstallDlg dlgInstall;
	if (dlgInstall.DoModal() != IDOK)
		return 0;

	// Determine the path of the CE application manager
	TCHAR tszAppMgrPath[_MAX_PATH+1];
	long cbPath = sizeof(tszAppMgrPath);
	if (FAILED(::RegQueryValue(HKEY_LOCAL_MACHINE,_T("Software\\Microsoft\\Windows\\CurrentVersion\\App Paths\\CEAppMgr.exe"),tszAppMgrPath,&cbPath)))
	{
		ATLTRACE(_T("Microsoft ActiveSync not installed.\n"));
		return 1;
	}

	// Determine the installation directory
	TCHAR tszInstallPath[_MAX_PATH+1];
	_tcscpy(tszInstallPath,tszAppMgrPath);
	::PathRemoveFileSpec(tszInstallPath);
	::PathAppend(tszInstallPath,_T("Tetris"));

	// Create the installation directory
	if (FAILED(::CreateDirectory(tszInstallPath,0)))
	{
		ATLTRACE(_T("Unable to create destionation directory \"%s\".\n"),tszInstallPath);
		return 2;
	}

	// Determine the name of the INI-file
	TCHAR tszINI[_MAX_PATH+1];
	_tcscpy(tszINI,tszInstallPath);
	::PathAppend(tszINI,_T("Tetris.PPC30_ARM.ini"));

	// Determine the name of the cabinet-file (ARM)
	TCHAR tszCAB_ARM[_MAX_PATH+1];
	_tcscpy(tszCAB_ARM,tszInstallPath);
	::PathAppend(tszCAB_ARM,_T("Tetris.PPC30_ARM.cab"));

	// Determine the name of the cabinet-file (MIPS)
	TCHAR tszCAB_MIPS[_MAX_PATH+1];
	_tcscpy(tszCAB_MIPS,tszInstallPath);
	::PathAppend(tszCAB_MIPS,_T("Tetris.PPC30_MIPS.cab"));

	// Determine the name of the cabinet-file (SH3)
	TCHAR tszCAB_SH3[_MAX_PATH+1];
	_tcscpy(tszCAB_SH3,tszInstallPath);
	::PathAppend(tszCAB_SH3,_T("Tetris.PPC30_SH3.cab"));

	// Write resources
	WriteResource(IDR_TETRIS_PPC30_INI,tszINI);
	WriteResource(IDR_TETRIS_PPC30_CAB_ARM ,tszCAB_ARM );
	WriteResource(IDR_TETRIS_PPC30_CAB_MIPS,tszCAB_MIPS);
	WriteResource(IDR_TETRIS_PPC30_CAB_SH3 ,tszCAB_SH3 );

	// Start the CE application manager
	TCHAR tszCmdLine[2*_MAX_PATH+6];
	wsprintf(tszCmdLine,_T("\"%s\" \"%s\""),tszAppMgrPath,tszINI);

	STARTUPINFO si = {0};
	PROCESS_INFORMATION pi = {0};
	si.cb = sizeof(si);
	if (::CreateProcess(0,tszCmdLine,0,0,FALSE,0,0,0,&si,&pi) == 0)
	{
		ATLTRACE(_T("Unable to start the CE Application manager.\n"));
		return 3;
	}

	// Wait until the CE application manager has ended
	::WaitForSingleObject(pi.hProcess,INFINITE);
	return 0;
}
