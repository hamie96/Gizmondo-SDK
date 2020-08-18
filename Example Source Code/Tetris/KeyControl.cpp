//	KeyControl.cpp - Tetris for Pocket PC (navigation key control)
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
#include "KeyControl.h"


#include "Resource.h"


const CKeyControl::KEYINFO CKeyControl::mg_aKeyInfo[] =
{
	{ IDS_KEY_NONE,  0,        0       },
	{ IDS_KEY_LEFT,  VK_LEFT,  0       },
	{ IDS_KEY_RIGHT, VK_RIGHT, 0       },
	{ IDS_KEY_UP,    VK_UP,    0       },
	{ IDS_KEY_DOWN,  VK_DOWN,  0       },
	{ IDS_KEY_ACTION,VK_F3,   0       },
	{ IDS_KEY_EXIT,  VK_F1,   0       },
	{ IDS_KEY_PROG1, VK_TAB,      0 },
	{ IDS_KEY_PROG2, VK_ESCAPE,   0 },
	{ IDS_KEY_PROG3, VK_RETURN,   0 },
	{ IDS_KEY_PROG4, VK_LSHIFT,   0 },
	{ IDS_KEY_PROG5, VK_LCONTROL, 0 },
	{ 0,             0,        0       }
};
