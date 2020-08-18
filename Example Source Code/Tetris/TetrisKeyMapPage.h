//	TetrisKeyMapPage.h - Tetris for Pocket PC (options key-map page)
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

#ifndef __TETRIS_KEY_MAP_PAGE_H
#define __TETRIS_KEY_MAP_PAGE_H


#include "Resource.h"
#include "PropSheet.h"
#include "TetrisOptions.h"
#include "KeyControl.h"


class CTetrisKeymapPage : public CPropertyPageImpl<CTetrisKeymapPage>
{
public:
	enum { IDD = IDD_OPTIONS_KEYMAP };

public:
	CTetrisKeymapPage (CTetrisOptions& tetrisOptions)
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
		SendDlgItemMessage(IDC_GRP_KEYMAPPING,WM_SETFONT,WPARAM(hfBold),MAKELPARAM(TRUE,0));
		SendDlgItemMessage(IDC_GRP_KEYREPEAT,WM_SETFONT,WPARAM(hfBold),MAKELPARAM(TRUE,0));

		// Set the tick-count
		SendDlgItemMessage(IDC_REPEAT_RATE,TBM_SETRANGE,WPARAM(false),MAKELPARAM(0,25));

		// Subclass key-controls
		m_keyMoveLeft   .SubclassWindow(GetDlgItem(IDC_MOVE_LEFT   ));
		m_keyMoveRight  .SubclassWindow(GetDlgItem(IDC_MOVE_RIGHT  ));
		m_keyRotateLeft .SubclassWindow(GetDlgItem(IDC_ROTATE_LEFT ));
		m_keyRotateRight.SubclassWindow(GetDlgItem(IDC_ROTATE_RIGHT));
		m_keySoftDrop   .SubclassWindow(GetDlgItem(IDC_SOFT_DROP   ));
		m_keyHardDrop   .SubclassWindow(GetDlgItem(IDC_HARD_DROP   ));
		m_keyPauseResume.SubclassWindow(GetDlgItem(IDC_PAUSE_RESUME));

		// Set the options
		m_keyMoveLeft   .SetVKCode(m_tetrisOptions.GetKeyCode(CTetrisOptions::ActionMoveLeft   ));
		m_keyMoveRight  .SetVKCode(m_tetrisOptions.GetKeyCode(CTetrisOptions::ActionMoveRight  ));
		m_keyRotateLeft .SetVKCode(m_tetrisOptions.GetKeyCode(CTetrisOptions::ActionRotateLeft ));
		m_keyRotateRight.SetVKCode(m_tetrisOptions.GetKeyCode(CTetrisOptions::ActionRotateRight));
		m_keySoftDrop   .SetVKCode(m_tetrisOptions.GetKeyCode(CTetrisOptions::ActionSoftDrop   ));
		m_keyHardDrop   .SetVKCode(m_tetrisOptions.GetKeyCode(CTetrisOptions::ActionHardDrop   ));
		m_keyPauseResume.SetVKCode(m_tetrisOptions.GetKeyCode(CTetrisOptions::ActionPauseResume));

		// Set repeat rate
		SendDlgItemMessage(IDC_REPEAT_RATE,TBM_SETPOS,WPARAM(true),LPARAM(m_tetrisOptions.GetRepeat()));

		// Message handled
		bHandled = FALSE;
		return 0;
	}

	LRESULT OnDestroy (UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		// Call base class
		DefWindowProc();

		// Set the options
		m_tetrisOptions.SetKeyCode(CTetrisOptions::ActionMoveLeft,   m_keyMoveLeft   .GetVKCode());
		m_tetrisOptions.SetKeyCode(CTetrisOptions::ActionMoveRight,  m_keyMoveRight  .GetVKCode());
		m_tetrisOptions.SetKeyCode(CTetrisOptions::ActionRotateLeft, m_keyRotateLeft .GetVKCode());
		m_tetrisOptions.SetKeyCode(CTetrisOptions::ActionRotateRight,m_keyRotateRight.GetVKCode());
		m_tetrisOptions.SetKeyCode(CTetrisOptions::ActionSoftDrop,   m_keySoftDrop   .GetVKCode());
		m_tetrisOptions.SetKeyCode(CTetrisOptions::ActionHardDrop,   m_keyHardDrop   .GetVKCode());
		m_tetrisOptions.SetKeyCode(CTetrisOptions::ActionPauseResume,m_keyPauseResume.GetVKCode());

		// Set repeat rate
		m_tetrisOptions.SetRepeat(SendDlgItemMessage(IDC_REPEAT_RATE,TBM_GETPOS,0,0));

		// Message handled
		bHandled = TRUE;
		return 0;
	}

	LRESULT OnKeyChanged (WORD wNotifyCode, WORD wIDChanged, HWND hWndCtl, BOOL& bHandled)
	{
		// Check if selection changed
		switch (wNotifyCode)
		{
		case CBN_SELENDOK:
			{
				// Check if the user selected a key
				CKeyControl* key = GetKeyFromId(wIDChanged);
				const UINT nVKCode = key->GetVKCode();
				if (nVKCode)
				{
					// Make sure other actions don't use the same key
					for (WORD wID=IDC_MOVE_LEFT; wID<=IDC_PAUSE_RESUME; ++wID)
					{
						if (wID != wIDChanged)
						{
							CKeyControl* key = GetKeyFromId(wID);
							if (key->GetVKCode() == nVKCode)
								key->SetVKCode(0);
						}
					}
				}
			}
			bHandled = TRUE;
			break;
		}

		return 0;
	}

private:
	// Internal helper functions
	CKeyControl* GetKeyFromId (const int iId)
	{
		switch (iId)
		{
		case IDC_MOVE_LEFT   : return &m_keyMoveLeft;
		case IDC_MOVE_RIGHT  : return &m_keyMoveRight;
		case IDC_ROTATE_LEFT : return &m_keyRotateLeft;
		case IDC_ROTATE_RIGHT: return &m_keyRotateRight;
		case IDC_SOFT_DROP   : return &m_keySoftDrop;
		case IDC_HARD_DROP   : return &m_keyHardDrop;
		case IDC_PAUSE_RESUME: return &m_keyPauseResume;
		}

		ATLASSERT(false);
		return 0;
	}

private:
	CTetrisOptions& m_tetrisOptions;

	CKeyControl		m_keyMoveLeft;
	CKeyControl		m_keyMoveRight;
	CKeyControl		m_keyRotateLeft;
	CKeyControl		m_keyRotateRight;
	CKeyControl		m_keySoftDrop;
	CKeyControl		m_keyHardDrop;
	CKeyControl		m_keyPauseResume;

private:
	BEGIN_MSG_MAP(CTetrisKeymapPage)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		MESSAGE_HANDLER(WM_DESTROY,    OnDestroy)
		COMMAND_RANGE_HANDLER(IDC_MOVE_LEFT,IDC_PAUSE_RESUME,OnKeyChanged)
	END_MSG_MAP()
};

#endif // __TETRIS_KEY_MAP_PAGE_H
