//	TetrisOptions.h - Tetris for Pocket PC (game options logic)
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

#ifndef __TETRIS_OPTIONS_H
#define __TETRIS_OPTIONS_H


#include "TetrisMatrix.h"


class CTetrisOptions  
{
public:
	// Level definitions
	enum Level { Unknown=-1, Easy, Moderate, Hard };
	enum Action
	{ 
		ActionMoveLeft, 
		ActionMoveRight, 
		ActionRotateLeft,
		ActionRotateRight,
		ActionSoftDrop,
		ActionHardDrop,
		ActionPauseResume,
		ActionMax,
		ActionNewGame
	};

public:
	// Constructor
	CTetrisOptions();

public:
	// Load/save options
	bool Load ();
	bool Save () const;

	// Options (read)
	CTetrisOptions::Level GetLevel() const;
	int                   GetDelay() const;
	bool                  GetSound() const;
	int					  GetRepeat() const;
	UINT                  GetKeyCode (const Action action) const;

	// Game options (write)
	void SetLevel    (const Level level);
	void SetSound    (const bool fSound);
	void SetRepeat   (const int iRepeat);
	void SetKeyCode  (const Action action, const UINT vkCode);

private:
	Level	m_level;
	bool	m_fSound;
	int		m_iRepeat;
	UINT    m_avkCodes[ActionMax];

private:	
	typedef struct tagLEVELINFO
	{
		int iDelay;
	}
	LEVELINFO;

private:
	static const LEVELINFO mg_aLevelInfo[];
};


inline CTetrisOptions::CTetrisOptions()
	: m_level(Unknown)
	, m_fSound(true)
	, m_iRepeat(100)
{
	// Load the settings
	Load();
}

inline CTetrisOptions::Level CTetrisOptions::GetLevel() const
{
	return m_level;
}

inline int CTetrisOptions::GetDelay() const
{
	ATLASSERT(m_level != Unknown);
	return mg_aLevelInfo[m_level].iDelay;
}

inline bool CTetrisOptions::GetSound() const
{
	return m_fSound;
}

inline int CTetrisOptions::GetRepeat() const
{
	return m_iRepeat;
}

inline UINT CTetrisOptions::GetKeyCode  (const Action action) const
{
	ATLASSERT(action>=0 && action<ActionMax);
	return m_avkCodes[action];
}

inline void CTetrisOptions::SetLevel (const Level level)
{
	ATLASSERT(level != Unknown);
	m_level = level;
}

inline void CTetrisOptions::SetSound (const bool fSound)
{
	m_fSound = fSound;
}

inline void CTetrisOptions::SetRepeat (const int iRepeat)
{
	ATLASSERT(iRepeat>=0 && iRepeat<100);
	m_iRepeat = iRepeat;
}

inline void CTetrisOptions::SetKeyCode  (const Action action, const UINT vkCode)
{
	ATLASSERT(action>=0 && action<ActionMax);
	m_avkCodes[action] = vkCode;
}

#endif // __TETRIS_OPTIONS_H
