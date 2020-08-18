/*
 * atari_wince.c - WinCE port specific code
 *
 * Copyright (C) 2001 Vasyl Tsvirkunov
 * Copyright (C) 2001-2006 Atari800 development team (see DOC/CREDITS)
 *
 * This file is part of the Atari800 emulator project which emulates
 * the Atari 400, 800, 800XL, 130XE, and 5200 8-bit computers.
 *
 * Atari800 is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Atari800 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Atari800; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include <windows.h>
#include "gx.h"

extern "C"
{
#include "input.h"
#include "main.h"
#include "keyboard.h"
#include "ui.h"
#include "gp2xjoy.h"
#include "gp2xgp32compat.h"
};

static GXKeyList klist;

void hitbutton(short code)
{
	//klist.vkUp;
	//klist.vkDown;
	//klist.vkLeft;
	//klist.vkRight;
}

void releasebutton(short code)
{
}

int prockb(void)
{
#ifndef MULTITHREADED
	MsgPump();
#endif
	return 0;
}

void uninitinput(void)
{
	/* To prevent start key leak to OS */
	while(GetAsyncKeyState(klist.vkStart) & 0x8000)
#ifndef MULTITHREADED
		MsgPump();
#else
		Sleep(10);
#endif
	GXCloseInput();
}

int initinput(void)
{

	// FIXME - make sure this is called..
	GXOpenInput();
	klist = GXGetDefaultKeys(GX_NORMALKEYS);
	

	return 0;
}

#define GP2X_ST 1;
#define GP2X_SE 2;
#define GP2X_L 4;
#define GP2X_R 8;
#define GP2X_A 16;
#define GP2X_B 32;
#define GP2X_X 64;
#define GP2X_Y 128;

#define GP2XJOY_U 1
#define GP2XJOY_UL 2
#define GP2XJOY_L 4
#define GP2XJOY_DL 8
#define GP2XJOY_D 16
#define GP2XJOY_DR 32
#define GP2XJOY_R 64
#define GP2XJOY_UR 128

void readAllJoy(int * switches, int * x, int * y, int * buttons)
{
	*x = 0;
	*y = 0;
	*buttons = 0;
	//int count;
	//SDL_PumpEvents();
	prockb();

	int left = (GetAsyncKeyState(klist.vkLeft)&0x8000)!=0;
	int right = (GetAsyncKeyState(klist.vkRight)&0x8000)!=0;
	int up = (GetAsyncKeyState(klist.vkUp)&0x8000)!=0;
	int down = (GetAsyncKeyState(klist.vkDown)&0x8000)!=0;

	int ba = (GetAsyncKeyState(160)&0x8000)!=0;
	int bb = (GetAsyncKeyState(32)&0x8000)!=0;
	int by = (GetAsyncKeyState(162)&0x8000)!=0;
	int bx = (GetAsyncKeyState(13)&0x8000)!=0;
	int bl = (GetAsyncKeyState(9)&0x8000)!=0;
	int br = (GetAsyncKeyState(27)&0x8000)!=0;

	int bhome = (GetAsyncKeyState(112)&0x8000)!=0;
	int bvol = (GetAsyncKeyState(113)&0x8000)!=0;
	int bstar = (GetAsyncKeyState(114)&0x8000)!=0;
	int btri = (GetAsyncKeyState(115)&0x8000)!=0;
	int bpow = (GetAsyncKeyState(123)&0x8000)!=0;


	//int buffer[256];
	//int pressed = 0;
	//for (int i=0; i<255; ++i)
	//{
	//	buffer[i] = ((GetAsyncKeyState(i)&0x8000)!=0);
	//	if (buffer[i])
	//		pressed = i;
	//}

	int joy = 0;
	if (up)
	   {*y=-1;joy|=GP2XJOY_U;}
	if (down)
	   {*y=1; joy|=GP2XJOY_D;}
	if (left)
	   {*x=-1;joy|=GP2XJOY_L;}
	if (right)
	   {*x=1;joy|=GP2XJOY_R;}

    //tweaks for dpad
    if ((joy&(GP2XJOY_U|GP2XJOY_R)) == (GP2XJOY_U|GP2XJOY_R) )
            joy = GP2XJOY_UR;
    else if ((joy&(GP2XJOY_U|GP2XJOY_L)) == (GP2XJOY_U|GP2XJOY_L))
            joy = GP2XJOY_UL;
    else if ((joy&(GP2XJOY_D|GP2XJOY_R)) == (GP2XJOY_D|GP2XJOY_R))
            joy = GP2XJOY_DR;
    else if ((joy&(GP2XJOY_D|GP2XJOY_L)) == (GP2XJOY_D|GP2XJOY_L))
            joy = GP2XJOY_DL;

	*switches = joy;

	if (ba)
	   *buttons |= GPC_VK_FA;
	if (bb)
	   *buttons |= GPC_VK_FB;
	if (br)
	   *buttons |= GPC_VK_FR;
	if (by)
	   *buttons |= GPC_VK_FY;
	if (bx)
	   *buttons |= GPC_VK_FX;
	if (bl)
	   *buttons |= GPC_VK_FL;

	if (bhome)
		*buttons |= GPC_VK_HOME;
	if (bvol)
		*buttons |= GPC_VK_VOLUME;
	if (bstar)
		*buttons |= GPC_VK_ASTERISK;
	if (btri)
		*buttons |= GPC_VK_TRIANGLE;
	if (bpow)
		*buttons |= GPC_VK_POWER;

	//option...

	//printf("x:%d y:%d\n",*x,*y);
	return;
}

int joyPressed()
{
	int dummy,x,y,out;
	readAllJoy(&dummy,&x,&y,&out);
	return (out|(x!=0)|(y!=0));
}