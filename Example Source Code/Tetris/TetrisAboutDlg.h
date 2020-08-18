//	TetrisAboutDlg.h - Tetris for Pocket PC (about dialog)
//
//	Copyright (C) 2000-2004 Ramon de Klein (Ramon.de.Klein@ict.nl)
//
//	This program is free software; you can redistribute it and/or modify
//	it under the terms of the GNU General Public License as published by
//	the Free Software Foundation; either version 2 of the License, or
//	(at your option) any later version.
//
//	This program is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//	GNU General Public License for more details.
//
//	You should have received a copy of the GNU General Public License
//	along with this program; if not, write to the Free Software
//	Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

#ifndef __TETRIS_ABOUT_DLG_H
#define __TETRIS_ABOUT_DLG_H


#include "Resource.h"


class CTetrisAboutDlg : public CDialogImpl<CTetrisAboutDlg>
{
public:
	enum { IDD = IDD_ABOUT };

private:
	LRESULT OnInitDialog (UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
#ifdef _WIN32_WCE
		// Switch to full-screen dialog (without menubar)
		SHINITDLGINFO shidi = {0};
		shidi.hDlg    = m_hWnd;
		shidi.dwMask  = SHIDIM_FLAGS;
		shidi.dwFlags = SHIDIF_SIPDOWN | SHIDIF_FULLSCREENNOMENUBAR;
		::SHInitDialog(&shidi);

		// There seems to be a bug in ATL for CE, because this handler
		// needs to return that it didn't handle the message, otherwise
		// ATL will call SHInitDialog again. Not handling OnInitDialog
		// doesn't work at all.
		bHandled = FALSE;
#else
		// Normal ATL version needs can report
		// that the message has been handled.
		bHandled = TRUE;
#endif
		return TRUE;
	}

#ifdef _WIN32_WCE
	LRESULT OnActivate (UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		// Hide taskbar and SIP during window activation
		if (LOWORD(wParam) != WA_INACTIVE)
		{
			::SHFullScreen(m_hWnd,SHFS_HIDETASKBAR);
			::SHFullScreen(m_hWnd,SHFS_HIDESIPBUTTON);
		}

		// Perform default handling as well
		bHandled = FALSE;
		return 0;
	}
#endif

	LRESULT OnLButtonUp (UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		// End the dialog
		EndDialog(IDOK);
		bHandled = TRUE;
		return 0;
	}

	LRESULT OnOk (WORD wNotifyCode, WORD nID, HWND hwndCtl, BOOL& bHandled)
	{
		// End the dialog
		EndDialog(IDOK);
		bHandled = TRUE;
		return 0;
	}

	BEGIN_MSG_MAP(CTetrisAboutDlg)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		MESSAGE_HANDLER(WM_LBUTTONUP,  OnLButtonUp)
		COMMAND_ID_HANDLER(IDOK, OnOk)

#ifdef _WIN32_WCE
		MESSAGE_HANDLER(WM_ACTIVATE,   OnActivate)
#endif
		
	END_MSG_MAP()
};


#endif // __TETRIS_ABOUT_DLG_H
