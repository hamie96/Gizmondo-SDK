//	TetrisGameOptionsPage.h - Tetris for Pocket PC (options game page)
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

#ifndef __TETRIS_GAME_OPTIONS_PAGE_H
#define __TETRIS_GAME_OPTIONS_PAGE_H


#include "Resource.h"
#include "PropSheet.h"
#include "TetrisOptions.h"


class CTetrisGameOptionsPage : public CPropertyPageImpl<CTetrisGameOptionsPage>
{
public:
	enum { IDD = IDD_OPTIONS_GAME };

public:
	CTetrisGameOptionsPage (CTetrisOptions& tetrisOptions)
		: m_tetrisOptions(tetrisOptions)
	{
	}

private:
	LRESULT OnInitDialog (UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		// Call base class
		DefWindowProc();

		// Create a bold font
		LOGFONT lf = {0};
		::GetObject(::GetStockObject(SYSTEM_FONT),sizeof(lf),&lf);
		lf.lfWeight = FW_BOLD;
		HFONT hfBold = ::CreateFontIndirect(&lf);


		// Set the bold font for all headers
		SendDlgItemMessage(IDC_GRP_LEVEL,  WM_SETFONT,WPARAM(hfBold),MAKELPARAM(TRUE,0));
		SendDlgItemMessage(IDC_GRP_OPTIONS,WM_SETFONT,WPARAM(hfBold),MAKELPARAM(TRUE,0));

		// Set the appropriate controls
		switch (m_tetrisOptions.GetLevel())
		{
		case CTetrisOptions::Easy:     CheckDlgButton(IDC_LEVEL_EASY    ,BST_CHECKED); break;
		case CTetrisOptions::Moderate: CheckDlgButton(IDC_LEVEL_MODERATE,BST_CHECKED); break;
		case CTetrisOptions::Hard:     CheckDlgButton(IDC_LEVEL_HARD    ,BST_CHECKED); break;
		default:                       ATLASSERT(0); break;
		}
		CheckDlgButton(IDC_SOUND,m_tetrisOptions.GetSound()?BST_CHECKED:BST_UNCHECKED);

		// Message handled
		bHandled = FALSE;
		return 0;
	}

	LRESULT OnDestroy (UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		// Determine the game level
		CTetrisOptions::Level level;
		if (IsDlgButtonChecked(IDC_LEVEL_EASY))				level = CTetrisOptions::Easy;
		else if (IsDlgButtonChecked(IDC_LEVEL_MODERATE))	level = CTetrisOptions::Moderate;
		else if (IsDlgButtonChecked(IDC_LEVEL_HARD))		level = CTetrisOptions::Hard;
		else ATLASSERT(0);

		// Set the options
		m_tetrisOptions.SetLevel(level);
		m_tetrisOptions.SetSound(IsDlgButtonChecked(IDC_SOUND)?true:false);

		// Call base class
		DefWindowProc();

		// Message handled
		bHandled = TRUE;
		return 0;
	}

private:
	CTetrisOptions& m_tetrisOptions;

private:
	BEGIN_MSG_MAP(CTetrisHighscoresDlg)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		MESSAGE_HANDLER(WM_DESTROY,    OnDestroy)
	END_MSG_MAP()
};

#endif // __TETRIS_GAME_OPTIONS_PAGE_H
