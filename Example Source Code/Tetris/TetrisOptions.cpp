//	TetrisOptions.cpp - Tetris for Pocket PC (game options logic)
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
#include "TetrisOptions.h"
#include "Registry.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


const CTetrisOptions::LEVELINFO CTetrisOptions::mg_aLevelInfo[] =
{
	{ 1000 },	// Easy level:     [1000ms delay]
	{  500 },	// Moderate level: [ 500ms delay]
	{  250 }	// Hard level:     [ 250ms delay]
};


bool CTetrisOptions::Load ()
{
	// Set default values
	m_level      = Easy;
	m_fSound     = true;
	m_iRepeat    = 10;

	// Set default key-mapping
	m_avkCodes[ActionMoveLeft   ] = VK_LEFT;
	m_avkCodes[ActionMoveRight  ] = VK_RIGHT;
	m_avkCodes[ActionRotateLeft ] = VK_TAB;
	m_avkCodes[ActionRotateRight] = VK_ESCAPE;
	m_avkCodes[ActionSoftDrop   ] = VK_RETURN;
	m_avkCodes[ActionHardDrop   ] = VK_LSHIFT;
	m_avkCodes[ActionPauseResume] = VK_F1;
    m_avkCodes[ActionNewGame    ] = VK_F2;

	// Try to open the registry
	CRegistry reg;
	if (!reg.Open(HKEY_CURRENT_USER,REGKEY_OPTIONS,false))
		return false;

	// Get the settings
	DWORD dwLevel, dwSound, dwRepeat;
	reg.Read(_T("Level"),  dwLevel );
	reg.Read(_T("Sound"),  dwSound );
	reg.Read(_T("Repeat"), dwRepeat);

	// Get key-map settings
	for (int iAction=0; iAction<ActionMax; ++iAction)
	{
		DWORD dwKeyCode;
		TCHAR tszAction[10];
		wsprintf(tszAction,_T("Key%c"),iAction+'A');
		if (reg.Read(tszAction,dwKeyCode))
			m_avkCodes[iAction] = dwKeyCode;
	}

	// Close registry
	reg.Close();

	// Check if level is valid
	if ((dwLevel<CTetrisOptions::Easy) || (dwLevel>CTetrisOptions::Hard))
		return false;

	// Check if repeat count is valid
	if (dwRepeat>25)
		return false;

	// Convert level to enumeration
	m_level   = Level(dwLevel);
	m_fSound  = dwSound?true:false;
	m_iRepeat = int(dwRepeat);
	
	// Return successfully
	return true;
}	

bool CTetrisOptions::Save () const
{
	// Try to open the registry
	CRegistry reg;
	if (!reg.Open(HKEY_CURRENT_USER,REGKEY_OPTIONS,true))
		return false;

	// Obtain the values from the internal data
	DWORD dwLevel  = m_level;
	DWORD dwSound  = m_fSound?1:0;
	DWORD dwRepeat = m_iRepeat;

	// Save the settings
	reg.Write(_T("Level"),  dwLevel );
	reg.Write(_T("Sound"),  dwSound );
	reg.Write(_T("Repeat"), dwRepeat);

	// Save key-map settings
	for (int iAction=0; iAction<ActionMax; ++iAction)
	{
		TCHAR tszAction[10];
		wsprintf(tszAction,_T("Key%c"),iAction+'A');
		reg.Write(tszAction,m_avkCodes[iAction]);
	}

	// Close registry
	reg.Close();

	// Return successfully
	return true;
}
