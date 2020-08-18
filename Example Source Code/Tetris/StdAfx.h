//	StdAfx.h - Bubbles for Pocket PC (precompiled header)
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

#ifndef __STDAFX_H
#define __STDAFX_H


#define WIN32_LEAN_AND_MEAN

#define IRDA_SUPPORT

#include <windows.h>
#include <commctrl.h>
#include <atlbase.h>

extern CComModule _Module;

#include <atlwin.h>

#ifndef _WIN32_WCE
#include <mmsystem.h>
#endif

#ifdef IRDA_SUPPORT
#include <winsock.h>
#include <af_irda.h>
#endif

#endif // __STDAFX_H
