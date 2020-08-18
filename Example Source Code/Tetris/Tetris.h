//	Tetris.h - Tetris for Pocket PC (global definitions)
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

#ifndef __TETRIS_H
#define __TETRIS_H

// Definition of registry keys
#define REGKEY_BASE				_T("Software\\Ramon de Klein\\Tetris")
#define REGKEY_OPTIONS			REGKEY_BASE _T("\\Options")
#define REGKEY_SCORE			REGKEY_BASE _T("\\Score")

#ifdef IRDA_SUPPORT
#define IRDA_SERVICENAME		"TetrisScores"
#endif

#endif	// __TETRIS_H
