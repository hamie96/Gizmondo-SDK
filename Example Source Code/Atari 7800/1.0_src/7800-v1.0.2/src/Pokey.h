// ----------------------------------------------------------------------------
//   ___  ___  ___  ___       ___  ____  ___  _  _
//  /__/ /__/ /  / /__  /__/ /__    /   /_   / |/ /
// /    / \  /__/ ___/ ___/ ___/   /   /__  /    /  emulator
//
// ----------------------------------------------------------------------------
// Copyright 2005 Greg Stanton
// 
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
// ----------------------------------------------------------------------------
// PokeySound is Copyright(c) 1997 by Ron Fries
//                                                                           
// This library is free software; you can redistribute it and/or modify it   
// under the terms of version 2 of the GNU Library General Public License    
// as published by the Free Software Foundation.                             
//                                                                           
// This library is distributed in the hope that it will be useful, but       
// WITHOUT ANY WARRANTY; without even the implied warranty of                
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library 
// General Public License for more details.                                  
// To obtain a copy of the GNU Library General Public License, write to the  
// Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.   
//                                                                           
// Any permitted reproduction of these routines, in whole or in part, must   
// bear this legend.                                                         
// ----------------------------------------------------------------------------
// Pokey.h
// ----------------------------------------------------------------------------
#ifndef POKEY_H
#define POKEY_H
#define POKEY_BUFFER_SIZE 624
#define POKEY_AUDF1 0x4000
#define POKEY_AUDC1 0x4001
#define POKEY_AUDF2 0x4002
#define POKEY_AUDC2 0x4003
#define POKEY_AUDF3 0x4004
#define POKEY_AUDC3 0x4005
#define POKEY_AUDF4 0x4006
#define POKEY_AUDC4 0x4007
#define POKEY_AUDCTL 0x4008

typedef unsigned char byte;
typedef unsigned short word;
typedef unsigned int uint;

extern void pokey_Reset( );
extern void pokey_SetRegister(word address, byte value);
extern void pokey_Process(uint length);
extern void pokey_Clear( );
extern "C" unsigned char pokey_buffer[];
extern uint pokey_size;

#endif
