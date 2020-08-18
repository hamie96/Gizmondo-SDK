//	TetrisScore.h - Tetris for Pocket PC (game score logic)
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

#ifndef __TETRIS_SCORE_H
#define __TETRIS_SCORE_H


#include "TetrisOptions.h"


class CTetrisScore
{
public:
 	// Constant definitions
	enum { MaxScores  =  8 };
	enum { MaxNameLen = 40 };

public:
	typedef struct tagSCOREITEM
	{
		TCHAR tszName[MaxNameLen+1];
		DWORD dwScore;
		DWORD dwTimeStamp;
		bool  fImported;
	}
	SCOREITEM;

public:
	// Constructor/Destructor
	CTetrisScore ();

public:
	// Load and save scores
	bool Load (const CTetrisOptions::Level level);
	bool Save () const;

	// Clear scores
	bool Clear ();

	// Check if a score is a highscore
	DWORD GetScoreIndex (const DWORD dwScore) const;

	// Add highscore (or import highscore)
	bool AddScore (const DWORD dwScore, LPCTSTR lptszName);
	bool InsertScore (const DWORD dwScore, LPCTSTR lptszName, const DWORD dwTimeStamp, const bool fImported);

	// Get highscore list
	const SCOREITEM& GetScore (const DWORD dwIndex) const
	{ 
		ATLASSERT(dwIndex < MaxScores);
		return m_asi[dwIndex]; 
	}

	SCOREITEM& GetScore (const DWORD dwIndex)
	{ 
		ATLASSERT(dwIndex < MaxScores);
		return m_asi[dwIndex]; 
	}

private:
	// Current settings for the score list
	CTetrisOptions::Level m_level;

	// Scorelist
	SCOREITEM m_asi[MaxScores];
};


#endif // __TETRIS_SCORE_H