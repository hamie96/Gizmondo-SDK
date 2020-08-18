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

/* Based on Win32 port by  Krzysztof Nikiel */

#include "config.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "atari.h"
#include "input.h"
#include "platform.h"
#include "screen.h"
#include "sound.h"
#include "ui.h"
#include "pokeysnd.h"

#include "keyboard.h"
#include "main.h"
//#include "screen_wince.h"

static int kbjoy = 1;

/* WinCE port does not have console, no log either */
void Aprint(char *format, ... ) {}
void Aflushlog(void) {}

/*OFF int Atari_Keyboard(void)
{
	int keycode;

	prockb();
	keycode = get_last_key();

	return keycode;
}*/

void groff();
int Atari_Exit(int run_monitor)
{
	/* monitor is not avaliable in this port */
	if(run_monitor)
		return 1;

#ifdef BUFFERED_LOG
	Aflushlog();
#endif

	uninitinput();
	groff();

#ifdef SOUND
	Sound_Exit();
#endif

	return 0;
}

/*OFF
int Atari_PORT(int num)
{
	if (num == 0)
		return stick0;
	else
		return 0xff;
}


int Atari_TRIG(int num)
{
	if (num == 0)
		return trig0;
	else
		return 1;
}
*/

void Atari_ConfigInit(void)
{
	enable_new_pokey = 0;
	screen_visible_x1 = 24;
	screen_visible_y1 = 10;
	screen_visible_x2 = 344;
	screen_visible_y2 = 230;
	show_disk_led = 1;
	show_sector_counter = 1;
	show_atari_speed = 1;
}

void AboutPocketAtari(void)
{
	ui_driver->fInfoScreen("About Pocket Atari", issmartphone ?
		"Pocket Atari for Smartphones\0"
		"Built on: " __DATE__ "\0"
		"\0"
		"Ported by Kostas Nakos\0"
		"(knakos@gmail.com)\0"
		"http://pocketatari.atari.org"
		"\0"
		"\0"
		"\0"
		"Based on the PocketPC/WinCE port\0"
		"by Vasyl Tsvirkunov\0"
		"http://pocketatari.retrogames.com\0"
		"\0"
		"\0"
		"Atari core for this version\0"
		ATARI_TITLE "\0"
		"http://atari800.sf.net\0"
		"\n"
	:
		"Pocket Atari v.1.2 (" __DATE__ ")\0"
		"by Vasyl Tsvirkunov (C) 2002\0"
		"http://pocketatari.retrogames.com\0"
		"\0"
		"\0"
		"This port is based on\0"
		ATARI_TITLE "\0"
		"http://atari800.sf.net\0"
		"\0"
		"PocketPC port update and\0"
		"Smartphone port by Kostas Nakos\0"
		"(knakos@gmail.com)\0"
		"http://pocketatari.atari.org"
		"\0"
		"\n"
	);
}

