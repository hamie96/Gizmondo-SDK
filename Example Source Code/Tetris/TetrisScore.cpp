//	TetrisScore.cpp - Tetris for Pocket PC (game score logic)
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
#include "TetrisScore.h"
#include "Registry.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


CTetrisScore::CTetrisScore()
	: m_level(CTetrisOptions::Unknown)
{
	// Clear the array
	memset(m_asi,0,sizeof(m_asi));
}

bool CTetrisScore::Load (const CTetrisOptions::Level level)
{
	// Set internal data
	m_level = level;

	// Clear the array
	memset(m_asi,0,sizeof(m_asi));

	// Determine the registry key
	TCHAR tszKey[_MAX_PATH+1];
	wsprintf(tszKey,REGKEY_SCORE _T("\\%d"),m_level);

	// Try to open the registry key for the current settings
	CRegistry reg;
	if (!reg.Open(HKEY_CURRENT_USER,tszKey,false))
		return false;

	// Enumerate through all items in the registry
	for (DWORD dwIndex=0; dwIndex<MaxScores; ++dwIndex)
	{
		// Create alias
		SCOREITEM& si = m_asi[dwIndex];

		// Create the key/value strings
		TCHAR tszKey[_MAX_PATH+1];
		wsprintf(tszKey,_T("%d"), dwIndex);

		// Write the score string
		TCHAR tszValue[8+1+8+1+MaxNameLen+1];
		if (!reg.Read(tszKey,tszValue,sizeof(tszValue)))
			return false;

		// Parse the string
		LPTSTR lptsz = tszValue;
		si.fImported = (*lptsz++ != _T('0'))?true:false;
		si.dwTimeStamp = _tcstoul(++lptsz,&lptsz,16);
		si.dwScore = _tcstoul(++lptsz,&lptsz,16) ^ si.dwTimeStamp;
		_tcsncpy(si.tszName,++lptsz,MaxNameLen);
		si.tszName[MaxNameLen] = _T('\0');
	}

	return true;
}

bool CTetrisScore::Save () const
{
	// Check if scores have been loaded
	ATLASSERT(m_level != CTetrisOptions::Unknown);

	// Determine the registry key
	TCHAR tszKey[_MAX_PATH+1];
	wsprintf(tszKey,REGKEY_SCORE _T("\\%d"),m_level);

	// Try to (re)create the registry key for the current settings
	CRegistry reg;
	if (!reg.Open(HKEY_CURRENT_USER,tszKey,true))
		return false;

	// Enumerate through all items in the registry
	for (DWORD dwIndex=0; (dwIndex<MaxScores) && m_asi[dwIndex].dwScore; ++dwIndex)
	{
		// Create alias
		const SCOREITEM& si = m_asi[dwIndex];

		// Create the key/value strings
		TCHAR tszKey[_MAX_PATH+1], tszValue[8+1+8+1+MaxNameLen+1];
		wsprintf(tszKey,_T("%d"), dwIndex);
		wsprintf(tszValue,_T("%d;%08X;%08X;%s"),
				 si.fImported?1:0,
				 si.dwTimeStamp,
			     si.dwScore ^ si.dwTimeStamp,
				 si.tszName);

		// Write the score string
		if (!reg.Write(tszKey,tszValue))
			return false;
	}

	return true;
}

bool CTetrisScore::Clear ()
{
	// Check if scores have been loaded
	ATLASSERT(m_level != CTetrisOptions::Unknown);

	// Clear the array
	memset(m_asi,0,sizeof(m_asi));

	// Determine the registry key
	TCHAR tszKey[_MAX_PATH+1];
	wsprintf(tszKey, _T("%d"),m_level);

	// Open the key
	CRegistry reg;
	if (!reg.Open(HKEY_CURRENT_USER,REGKEY_SCORE,false))
		return false;

	// Delete the key
	if (!reg.DeleteKey(tszKey))
		return false;

	// Close key and exit
	reg.Close();
	return true;
}

DWORD CTetrisScore::GetScoreIndex (const DWORD dwScore) const
{
	// Check if scores have been loaded
	ATLASSERT(m_level != CTetrisOptions::Unknown);

	// Make sure the parameters are valid
	ATLASSERT(dwScore>0);

	// Check if the score should be in the list
	for (DWORD dwIndex=0; dwIndex<MaxScores; ++dwIndex)
	{
		// Check if we should be at this position
		if (dwScore>m_asi[dwIndex].dwScore)
			return dwIndex;
	}

	// No high score
	return MaxScores;
}

bool CTetrisScore::InsertScore (const DWORD dwScore, LPCTSTR lptszName, const DWORD dwTimeStamp, const bool fImported)
{
	// Check if scores have been loaded
	ATLASSERT(m_level != CTetrisOptions::Unknown);

	// Make sure the parameters are valid
	ATLASSERT(dwScore>0);
	ATLASSERT(lptszName && _tcslen(lptszName)<=MaxNameLen);

	// Try to insert the score
	for (DWORD dwIndex=0; dwIndex<MaxScores; ++dwIndex)
	{
		// Create alias
		SCOREITEM& si = m_asi[dwIndex];

		// Check if the same score is added twice
		if ((dwScore == si.dwScore) && (dwTimeStamp == si.dwTimeStamp))
			return false;

		// Check if we should be at this position
		if (dwScore>si.dwScore)
		{
			// Shift other scores
			for (DWORD dwShiftIndex=MaxScores-1; dwShiftIndex>dwIndex; --dwShiftIndex)
			{
				m_asi[dwShiftIndex] = m_asi[dwShiftIndex-1];
			}

			// Set new score
			si.dwScore     = dwScore;
			si.dwTimeStamp = dwTimeStamp;
			si.fImported   = fImported;
			_tcscpy(si.tszName,lptszName);
			return true;
		}
	}

	// Score not added to the list
	return false;
}

bool CTetrisScore::AddScore (const DWORD dwScore, LPCTSTR lptszName)
{
	// Determine the current time
	SYSTEMTIME st = {0};
	::GetSystemTime(&st);

	// Calculate the timestamp (fits in 32-bit DWORD)
	const DWORD dwStamp = ((((((st.wYear-2000)*100+st.wMonth)*12)+st.wDay)*31+st.wHour)*24+st.wMinute)*60+st.wSecond;

	// Insert the score into the list
	if (!InsertScore(dwScore,lptszName,dwStamp,false))
		return false;

	// Score successfully added
	return true;
}
