//	TetrisOptionsGameDlg.h - Tetris for Pocket PC (game-options page)
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

#ifndef __TETRIS_OPTIONS_GAME_DLG_H
#define __TETRIS_OPTIONS_GAME_DLG_H


#include "Resource.h"
#include "TetrisOptions.h"


class CTetrisOptionsGameDlg : public CDialogImpl<CTetrisOptionsGameDlg>
{
public:
	enum { IDD = IDD_OPTIONS_GAME };

private:
	LRESULT OnInitDialog (UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		// Call base class
		DefWindowProc();

		// Obtain the group header's font
		HFONT hf = HFONT(SendDlgItemMessage(IDC_GRP_LEVEL,WM_GETFONT,0,0));

		// Create a bold font
		LOGFONT lf = {0};
		::GetObject(hf,sizeof(lf),&lf);
		lf.lfWeight = FW_BOLD;
		HFONT hfBold = ::CreateFontIndirect(&lf);

		// Set the bold font for all headers
		SendDlgItemMessage(IDC_GRP_LEVEL,  WM_SETFONT,WPARAM(hfBold),MAKELPARAM(TRUE,0));
		SendDlgItemMessage(IDC_GRP_OPTIONS,WM_SETFONT,WPARAM(hfBold),MAKELPARAM(TRUE,0));

		// Read the game options
		m_tetrisOptions.Load();

		// Set the appropriate controls
		switch (m_tetrisOptions.GetLevel())
		{
		case CTetrisOptions::Easy:     CheckDlgButton(IDC_LEVEL_EASY    ,BST_CHECKED); break;
		case CTetrisOptions::Moderate: CheckDlgButton(IDC_LEVEL_MODERATE,BST_CHECKED); break;
		case CTetrisOptions::Hard:     CheckDlgButton(IDC_LEVEL_HARD    ,BST_CHECKED); break;
		default:                       ATLASSERT(0); break;
		}
		CheckDlgButton(IDC_SOUND,m_tetrisOptions.GetSound()?BST_CHECKED:BST_UNCHECKED);

		// Proceed with default handling
		return FALSE;
	}

	LRESULT OnOk (WORD wNotifyCode, WORD nID, HWND hwndCtl, BOOL& bHandled)
	{
		// Determine the game level
		CTetrisOptions::Level level;
		if (IsDlgButtonChecked(IDC_LEVEL_EASY))				level = CTetrisOptions::Easy;
		else if (IsDlgButtonChecked(IDC_LEVEL_MODERATE))	level = CTetrisOptions::Moderate;
		else if (IsDlgButtonChecked(IDC_LEVEL_HARD))		level = CTetrisOptions::Hard;
		else ATLASSERT(0);

		// Set the options
		m_tetrisOptions.SetLevel(level);
		m_tetrisOptions.SetSound(IsDlgButtonChecked(IDC_SOUND   )?true:false);

		// Save options
		m_tetrisOptions.Save();

		// End the dialog
		EndDialog(IDOK);
		bHandled = TRUE;
		return 0;
	}

	LRESULT OnCancel (WORD wNotifyCode, WORD nID, HWND hwndCtl, BOOL& bHandled)
	{
		// End the dialog
		EndDialog(IDCANCEL);
		bHandled = TRUE;
		return 0;
	}

	BEGIN_MSG_MAP(CTetrisOptionsDlg)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		COMMAND_ID_HANDLER(IDOK,     OnOk)
		COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
	END_MSG_MAP()

private:
	CTetrisOptions m_tetrisOptions;
};

#endif // __TETRIS_OPTIONS_GAME_DLG_H