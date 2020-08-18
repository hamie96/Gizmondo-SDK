//	Tetris.cpp - Tetris for Pocket PC (main routine)
//  Converted To Gizmondo By TheReaper 2006
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

#include "StdAfx.h"
#include "Tetris.h"
#include "TetrisWindow.h"

CComModule _Module;

int WINAPI _tWinMain (HINSTANCE hinst, HINSTANCE hinstPrev, LPTSTR lpCmdLine, int nCmdShow)
{
	// Initialize the module
	_Module.Init(0,hinst);

	// Reactivate an existing window
	if (CTetrisWindow::Reactivate())
		return 0;

	// Initialize common controls
	INITCOMMONCONTROLSEX iccex;
	iccex.dwSize = sizeof(INITCOMMONCONTROLSEX);
	iccex.dwICC  = ICC_LISTVIEW_CLASSES | ICC_BAR_CLASSES | ICC_TAB_CLASSES;
	::InitCommonControlsEx(&iccex);

	// Create the window
	CTetrisWindow wndTetris; 
	wndTetris.Create();
	wndTetris.ShowWindow(nCmdShow);
	wndTetris.UpdateWindow();

	// Main message loop
	MSG msg;
	while (::GetMessage(&msg, NULL, 0, 0)) 
	{
		::TranslateMessage(&msg);
		::DispatchMessage(&msg);
	}

	// Return
	return msg.wParam;
}
