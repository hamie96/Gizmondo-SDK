//	TetrisOptionsDlg.h - Tetris for Pocket PC (options dialog)
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

#ifndef __TETRIS_OPTIONS_DLG_H
#define __TETRIS_OPTIONS_DLG_H


#include "Resource.h"
#include "PropSheet.h"
#include "TetrisOptions.h"
#include "TetrisGameOptionsPage.h"
#include "TetrisKeyMapPage.h"


class CTetrisOptionsDlg : public CPropertySheetImpl<CTetrisOptionsDlg>
{
public:
	CTetrisOptionsDlg (HWND hwndParent = 0, const int nStartPage = 0)
		: CPropertySheetImpl<CTetrisOptionsDlg>(_T("Options"),nStartPage,hwndParent)
		, m_pageGameOptions(m_tetrisOptions)
		, m_pageKeymap(m_tetrisOptions)
	{
		// Add property pages
		AddPage(m_pageGameOptions);
		AddPage(m_pageKeymap);
	}
	
	~CTetrisOptionsDlg ()
	{
		// Save game options
		m_tetrisOptions.Save();
	}

private:
	BEGIN_MSG_MAP(CTetrisOptionsDlg)
		COMMAND_HANDLER(IDOK, 0, OnOk)
	END_MSG_MAP()

private:
	LRESULT OnOk (WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		bHandled = TRUE;
		return 0;
	}

private:
	CTetrisGameOptionsPage		m_pageGameOptions;
	CTetrisKeymapPage			m_pageKeymap;

	CTetrisOptions				m_tetrisOptions;
};


#endif // __TETRIS_OPTIONS_DLG_H
