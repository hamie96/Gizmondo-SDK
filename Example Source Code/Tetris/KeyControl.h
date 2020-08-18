//	KeyControl.h - Tetris for Pocket PC (navigation key control)
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

#ifndef __KEY_CONTROL_H
#define __KEY_CONTROL_H


class CKeyControl : public CWindowImpl<CKeyControl>
{
private:
	typedef struct tagKEYINFO
	{
		UINT nResID;
		UINT nVKCode;
		UINT nMod;
	} 
	KEYINFO;

public:
	// Constructor/Destructor
	CKeyControl()
	{
	}

	~CKeyControl()
	{
	}

public:
	// Define the window class
	DECLARE_WND_SUPERCLASS(0,_T("COMBO"))

private:
	// Message map
	BEGIN_MSG_MAP(CKeyControl)
		MESSAGE_HANDLER(WM_SETFOCUS,  OnSetFocus )
		MESSAGE_HANDLER(WM_KILLFOCUS, OnKillFocus)
		MESSAGE_HANDLER(WM_HOTKEY,    OnHotKey   )
	END_MSG_MAP()

private:
	// Windows message handlers
	LRESULT OnSetFocus (UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		// Register hotkeys
		RegisterKeys();

		// Finished
		bHandled = FALSE;
		return 0;
	}

	LRESULT OnKillFocus (UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		// Unregister hotkeys
		UnregisterKeys();

		// Finished
		bHandled = FALSE;
		return 0;
	}

	LRESULT OnHotKey (UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		// Close the combobox
		SendMessage(CB_SHOWDROPDOWN,WPARAM(FALSE));

		// Check if the key-code changes
		if (wParam != GetVKCode())
		{
			// Set the new virtual key code
			SetVKCode(wParam);

			// Send selection change event
			SendMessage(GetParent(),WM_COMMAND,MAKEWPARAM(GetWindowLong(GWL_ID),CBN_SELENDOK),LPARAM(m_hWnd));
		}

		// Finished
		bHandled = TRUE;
		return 0;
	}


private:
	void RegisterKeys ()
	{
		for (int iIndex=0; mg_aKeyInfo[iIndex].nResID; ++iIndex)
		{
			const KEYINFO& ki = mg_aKeyInfo[iIndex];
			if (ki.nVKCode)
				::RegisterHotKey(m_hWnd,ki.nVKCode,ki.nMod,ki.nVKCode);
		}
	}

	void UnregisterKeys ()
	{
		for (int iIndex=0; mg_aKeyInfo[iIndex].nResID; ++iIndex)
		{
			const KEYINFO& ki = mg_aKeyInfo[iIndex];
			if (ki.nVKCode)
				::UnregisterHotKey(m_hWnd,ki.nVKCode);
		}
	}

	void LoadComboBox ()
	{
		for (int iIndex=0; mg_aKeyInfo[iIndex].nResID; ++iIndex)
		{
			TCHAR tszText[100];
			const KEYINFO& ki = mg_aKeyInfo[iIndex];
			::LoadString(_Module.GetResourceInstance(),ki.nResID,tszText,sizeof(tszText)/sizeof(*tszText));
			SendMessage(CB_ADDSTRING,0,LPARAM(tszText));
			SendMessage(CB_SETITEMDATA,WPARAM(iIndex),LPARAM(iIndex));
		}
	}

public:
	BOOL SubclassWindow (HWND hwnd)
	{
		// Call base class
		if (!CWindowImpl<CKeyControl>::SubclassWindow(hwnd))
			return FALSE;

		// Load the combo-box
		LoadComboBox();

		// Set selection to first key
		SendMessage(CB_SETCURSEL,0);
		return TRUE;
	}

	bool SetVKCode (const UINT vkCode)
	{
		// Check if virtual-key code is valid
		for (int iIndex=0; mg_aKeyInfo[iIndex].nResID; ++iIndex)
		{
			const KEYINFO& ki = mg_aKeyInfo[iIndex];
			if (vkCode == ki.nVKCode)
			{
				// Item found in the combo-box
				SendMessage(CB_SETCURSEL,WPARAM(iIndex));
				return true;
			}
		}
		return false;
	}

	UINT GetVKCode () const
	{
		// Get writable version of "this" pointer
		CKeyControl* pThis = const_cast<CKeyControl*>(this);

		// Obtain the current item
		const int iIndex = pThis->SendMessage(CB_GETCURSEL);
		if (iIndex == CB_ERR)
			return 0;

		// Obtain the index ini the key-info array
		const int iKeyIndex = pThis->SendMessage(CB_GETITEMDATA,WPARAM(iIndex));
		return mg_aKeyInfo[iKeyIndex].nVKCode;
	}

private:
	static const KEYINFO mg_aKeyInfo[];
};

#endif // __KEY_CONTROL_H
