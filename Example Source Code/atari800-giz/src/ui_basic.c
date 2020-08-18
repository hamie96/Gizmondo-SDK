/*
 * ui_basic.c - main user interface
 *
 * Copyright (C) 1995-1998 David Firth
 * Copyright (C) 1998-2005 Atari800 development team (see DOC/CREDITS)
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

#include "config.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h> /* free() */
#ifdef HAVE_UNISTD_H
#include <unistd.h> /* getcwd() */
#endif
#ifdef HAVE_DIRECT_H
#include <direct.h> /* getcwd on MSVC*/
#endif
/* XXX: <sys/dir.h>, <ndir.h>, <sys/ndir.h> */
#ifdef HAVE_DIRENT_H
#include <dirent.h>
#endif
#ifdef HAVE_SYS_STAT_H
#include <sys/stat.h>
#endif
#ifdef WIN32
#include <windows.h>
#endif

#include "antic.h"
#include "atari.h"
#include "input.h"
#include "log.h"
#include "memory.h"
#include "platform.h"
#include "screen.h" /* atari_screen */
#include "ui.h"
#include "util.h"
#include "unzip.h"

#include "menu_c.h"
#include "sio.h"

#ifdef USE_CURSES
void curses_clear_screen(void);
void curses_clear_rectangle(int x1, int y1, int x2, int y2);
void curses_putch(int x, int y, int ascii, UBYTE fg, UBYTE bg);
#endif

static int initialised = FALSE;
static UBYTE charset[1024];

static const unsigned char key_to_ascii[256] =
{
	0x6C, 0x6A, 0x3B, 0x00, 0x00, 0x6B, 0x2B, 0x2A, 0x6F, 0x00, 0x70, 0x75, 0x9B, 0x69, 0x2D, 0x3D,
	0x76, 0x00, 0x63, 0x00, 0x00, 0x62, 0x78, 0x7A, 0x34, 0x00, 0x33, 0x36, 0x1B, 0x35, 0x32, 0x31,
	0x2C, 0x20, 0x2E, 0x6E, 0x00, 0x6D, 0x2F, 0x00, 0x72, 0x00, 0x65, 0x79, 0x7F, 0x74, 0x77, 0x71,
	0x39, 0x00, 0x30, 0x37, 0x7E, 0x38, 0x3C, 0x3E, 0x66, 0x68, 0x64, 0x00, 0x00, 0x67, 0x73, 0x61,

	0x4C, 0x4A, 0x3A, 0x00, 0x00, 0x4B, 0x5C, 0x5E, 0x4F, 0x00, 0x50, 0x55, 0x9B, 0x49, 0x5F, 0x7C,
	0x56, 0x00, 0x43, 0x00, 0x00, 0x42, 0x58, 0x5A, 0x24, 0x00, 0x23, 0x26, 0x1B, 0x25, 0x22, 0x21,
	0x5B, 0x20, 0x5D, 0x4E, 0x00, 0x4D, 0x3F, 0x00, 0x52, 0x00, 0x45, 0x59, 0x9F, 0x54, 0x57, 0x51,
	0x28, 0x00, 0x29, 0x27, 0x9C, 0x40, 0x7D, 0x9D, 0x46, 0x48, 0x44, 0x00, 0x00, 0x47, 0x53, 0x41,

	0x0C, 0x0A, 0x7B, 0x00, 0x00, 0x0B, 0x1E, 0x1F, 0x0F, 0x00, 0x10, 0x15, 0x9B, 0x09, 0x1C, 0x1D,
	0x16, 0x00, 0x03, 0x00, 0x00, 0x02, 0x18, 0x1A, 0x00, 0x00, 0x9B, 0x00, 0x1B, 0x00, 0xFD, 0x00,
	0x00, 0x20, 0x60, 0x0E, 0x00, 0x0D, 0x00, 0x00, 0x12, 0x00, 0x05, 0x19, 0x9E, 0x14, 0x17, 0x11,
	0x00, 0x00, 0x00, 0x00, 0xFE, 0x00, 0x7D, 0xFF, 0x06, 0x08, 0x04, 0x00, 0x00, 0x07, 0x13, 0x01,

	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

#define KB_DELAY       30
#define KB_AUTOREPEAT  3

static int isZip(char const * directory)
{
	int len = strlen(directory);
	int result =  
	(
	 	len >= 5 && 
		(
		 	(strncmp(directory+len-4, ".zip", 4)==0) ||
			(strncmp(directory+len-4, ".ZIP", 4)==0) ||
		 	(strncmp(directory+len-5, ".zip/", 5)==0) ||
			(strncmp(directory+len-5, ".ZIP/", 5)==0) ||
			(strncmp(directory+len-5, ".zip\\", 5)==0) ||
			(strncmp(directory+len-5, ".ZIP\\", 5)==0)
		)
	);
	//fprintf(stderr, "isZip returing %d for %s\n", result, directory);
	return result;
}

static int GetKeyPress(void)
{
	int keycode;

	if (alt_function >= 0)
		return 0x1b; /* escape - go to Main Menu */

	Atari_DisplayScreen();

	//while (UI_Keyboard()!=AKEY_NONE) usleep(1);

	for (;;) {
		static int rep = KB_DELAY;
		if (UI_Keyboard() == AKEY_NONE) {
			rep = KB_DELAY;
			break;
		}
		if (rep == 0) {
			rep = KB_AUTOREPEAT;
			break;
		}
		rep--;
		atari_sync();
	}

	do {
		atari_sync();
		keycode = UI_Keyboard();
		switch (keycode) {
		case AKEY_WARMSTART:
			alt_function = MENU_RESETW;
			return 0x1b; /* escape */
		case AKEY_COLDSTART:
			alt_function = MENU_RESETC;
			return 0x1b; /* escape */
		case AKEY_EXIT:
			alt_function = MENU_EXIT;
			return 0x1b; /* escape */
		case AKEY_UI:
			if (alt_function >= 0) /* Alt+letter, not F1 */
				return 0x1b; /* escape */
			break;
		case AKEY_SCREENSHOT:
			alt_function = MENU_PCX;
			return 0x1b; /* escape */
		case AKEY_SCREENSHOT_INTERLACE:
			alt_function = MENU_PCXI;
			return 0x1b; /* escape */
		default:
			alt_function = -1; /* forget previous Main Menu shortcut */
			break;
		}
	} while (keycode < 0);

	return key_to_ascii[keycode];
}

static void Plot(int fg, int bg, int ch, int x, int y)
{
#ifdef USE_CURSES
	curses_putch(x, y, ch, (UBYTE) fg, (UBYTE) bg);
#else /* USE_CURSES */
	const UBYTE *font_ptr = charset + (ch & 0x7f) * 8;
	UBYTE *ptr = (UBYTE *) atari_screen + 24 * ATARI_WIDTH + 32 + y * (8 * ATARI_WIDTH) + x * 8;
	int i;
	int j;

	for (i = 0; i < 8; i++) {
		UBYTE data = *font_ptr++;
		for (j = 0; j < 8; j++) {
#ifdef USE_COLOUR_TRANSLATION_TABLE
			video_putbyte(ptr++, (UBYTE) colour_translation_table[data & 0x80 ? fg : bg]);
#else
			video_putbyte(ptr++, (UBYTE) (data & 0x80 ? fg : bg));
#endif
			data <<= 1;
		}
		ptr += ATARI_WIDTH - 8;
	}
#endif /* USE_CURSES */
}

static void Print(int fg, int bg, const char *string, int x, int y, int maxwidth)
{
	char tmpbuf[40];
	if ((int) strlen(string) > maxwidth) {
		int firstlen = (maxwidth - 3) >> 1;
		int laststart = strlen(string) - (maxwidth - 3 - firstlen);
		sprintf(tmpbuf, "%.*s...%s", firstlen, string, string + laststart);
		string = tmpbuf;
	}
	while (*string != '\0')
		Plot(fg, bg, *string++, x++, y);
}

static void CenterPrint(int fg, int bg, const char *string, int y)
{
	int length = strlen(string);
	Print(fg, bg, string, (length < 38) ? (40 - length) >> 1 : 1, y, 38);
}

static void Box(int fg, int bg, int x1, int y1, int x2, int y2)
{
	int x;
	int y;

	for (x = x1 + 1; x < x2; x++) {
		Plot(fg, bg, 18, x, y1);
		Plot(fg, bg, 18, x, y2);
	}

	for (y = y1 + 1; y < y2; y++) {
		Plot(fg, bg, 124, x1, y);
		Plot(fg, bg, 124, x2, y);
	}

	Plot(fg, bg, 17, x1, y1);
	Plot(fg, bg, 5, x2, y1);
	Plot(fg, bg, 3, x2, y2);
	Plot(fg, bg, 26, x1, y2);
}

static void ClearRectangle(int bg, int x1, int y1, int x2, int y2)
{
#ifdef USE_CURSES
	curses_clear_rectangle(x1, y1, x2, y2);
#else
	UBYTE *ptr = (UBYTE *) atari_screen + ATARI_WIDTH * 24 + 32 + x1 * 8 + y1 * (ATARI_WIDTH * 8);
	int bytesperline = (x2 - x1 + 1) << 3;
	UBYTE *end_ptr = (UBYTE *) atari_screen + ATARI_WIDTH * 32 + 32 + y2 * (ATARI_WIDTH * 8);
	while (ptr < end_ptr) {
#ifdef USE_COLOUR_TRANSLATION_TABLE
		video_memset(ptr, (UBYTE) colour_translation_table[bg], bytesperline);
#else
		video_memset(ptr, (UBYTE) bg, bytesperline);
#endif
		ptr += ATARI_WIDTH;
	}
#endif /* USE_CURSES */
}

static void ClearScreen(void)
{
#ifdef USE_CURSES
	curses_clear_screen();
#else
#ifdef USE_COLOUR_TRANSLATION_TABLE
	video_memset((UBYTE *) atari_screen, colour_translation_table[0x00], ATARI_HEIGHT * ATARI_WIDTH);
#else
	video_memset((UBYTE *) atari_screen, 0x00, ATARI_HEIGHT * ATARI_WIDTH);
#endif
	ClearRectangle(0x94, 0, 0, 39, 23);
#endif /* USE_CURSES */
}

static void TitleScreen(const char *title)
{
	CenterPrint(0x9a, 0x94, title, 0);
}

void BasicUIMessage(const char *msg)
{
	ClearRectangle(0x94, 1, 22, 38, 22);
	CenterPrint(0x94, 0x9a, msg, 22);
	GetKeyPress();
}

static int Select(int default_item, int nitems, const char *item[],
                  const char *prefix[], const char *suffix[],
                  const char *tip[], const int nonselectable[],
                  int nrows, int ncolumns, int xoffset, int yoffset,
                  int itemwidth, int drag, const char *global_tip,
                  int *seltype)
{
	int offset = 0;
	int index = default_item;
	int localseltype;

	if (seltype == NULL)
		seltype = &localseltype;

	for (;;) {
		int col;
		int row;
		int i;
		const char *message = global_tip;

		while (index < offset)
			offset -= nrows;
		while (index >= offset + nrows * ncolumns)
			offset += nrows;

		ClearRectangle(0x94, xoffset, yoffset, xoffset + ncolumns * (itemwidth + 1) - 2, yoffset + nrows - 1);
		col = 0;
		row = 0;
		for (i = offset; i < nitems; i++) {
			char szbuf[40 + FILENAME_MAX]; /* allow for prefix and suffix */
			char *p = szbuf;
			if (prefix != NULL && prefix[i] != NULL)
				p = Util_stpcpy(szbuf, prefix[i]);
			p = Util_stpcpy(p, item[i]);
			if (suffix != NULL && suffix[i] != NULL) {
				char *q = szbuf + itemwidth - strlen(suffix[i]);
				while (p < q)
					*p++ = ' ';
				strcpy(p, suffix[i]);
			}
			else {
				while (p < szbuf + itemwidth)
					*p++ = ' ';
				*p = '\0';
			}
			if (i == index)
				Print(0x94, 0x9a, szbuf, xoffset + col * (itemwidth + 1), yoffset + row, itemwidth);
			else
				Print(0x9a, 0x94, szbuf, xoffset + col * (itemwidth + 1), yoffset + row, itemwidth);
			if (++row >= nrows) {
				if (++col >= ncolumns)
					break;
				row = 0;
			}
		}
		if (tip != NULL && tip[index] != NULL)
			message = tip[index];
		else if (itemwidth < 38 && (int) strlen(item[index]) > itemwidth)
			/* the selected item was shortened */
			message = item[index];
		if (message != NULL)
			CenterPrint(0x94, 0x9a, message, 22);

		for (;;) {
			int ascii;
			int tmp_index;
			ascii = GetKeyPress();
			switch (ascii) {
			case 0x1c:				/* Up */
				if (drag) {
					*seltype = USER_DRAG_UP;
					return index;
				}
				tmp_index = index;
				do
					tmp_index--;
				while (tmp_index >= 0 && nonselectable != NULL && nonselectable[tmp_index]);
				if (tmp_index >= 0) {
					index = tmp_index;
					break;
				}
				continue;
			case 0x1d:				/* Down */
				if (drag) {
					*seltype = USER_DRAG_DOWN;
					return index;
				}
				tmp_index = index;
				do
					tmp_index++;
				while (tmp_index < nitems && nonselectable != NULL && nonselectable[tmp_index]);
				if (tmp_index < nitems) {
					index = tmp_index;
					break;
				}
				continue;
			case 0x1e:				/* Left */
				if (drag)
					continue;		/* cannot drag left */
				index = (index > nrows) ? index - nrows : 0;
				break;
			case 0x1f:				/* Right */
				if (drag)
					continue;		/* cannot drag right */
				index = (index + nrows < nitems) ? index + nrows : nitems - 1;
				break;
			case 0x7f:				/* Tab (for exchanging disk directories) */
				return -2;			/* GOLDA CHANGED */
			case 0x20:				/* Space */
				*seltype = USER_TOGGLE;
				return index;
			case 0x7e:				/* Backspace */
				*seltype = USER_DELETE;
				return index;
			case 0x9b:				/* Return=Select */
				*seltype = USER_SELECT;
				return index;
			case 0x1b:				/* Esc=Cancel */
				return -1;
			default:
				if (drag || ascii <= 0x20 || ascii >= 0x7f)
					continue;
				tmp_index = index; /* old index */
				do {
					if (++index >= nitems)
						index = 0;
				} while (index != tmp_index && !Util_chrieq((char) ascii, item[index][0]));
				break;
			}
			break;
		}
		if (message != NULL)
			ClearRectangle(0x94, 1, 22, 38, 22);
	}
}

int BasicUISelect(const char *title, int flags, int default_item, const tMenuItem *menu, int *seltype)
{
	int nitems;
	int index;
	const tMenuItem *pmenu;
	static const char *prefix[100];
	static const char *item[100];
	static const char *suffix[100];
	static const char *tip[100];
	static int nonselectable[100];
	int w;
	int x1, y1, x2, y2;

	nitems = 0;
	index = 0;
	for (pmenu = menu; pmenu->item != NULL; pmenu++) {
		if (pmenu->flags != ITEM_HIDDEN) {
			prefix[nitems] = pmenu->prefix;
			item[nitems] = pmenu->item;
			if (pmenu->flags & ITEM_TIP) {
				suffix[nitems] = NULL;
				tip[nitems] = pmenu->suffix;
			}
			else {
				if ((pmenu->flags & ITEM_TYPE) == ITEM_CHECK) {
					if (pmenu->flags & ITEM_CHECKED)
						suffix[nitems] = "Yes";
					else
						suffix[nitems] = "No ";
				}
				else
					suffix[nitems] = pmenu->suffix;
				tip[nitems] = NULL;
			}
			nonselectable[nitems] = (pmenu->retval < 0);
			if (pmenu->retval == default_item)
				index = nitems;
			nitems++;
		}
	}

	if (nitems == 0)
		return -1; /* cancel immediately */

	if (flags & SELECT_POPUP) {
		int i;
		w = 0;
		for (i = 0; i < nitems; i++) {
			int ws = strlen(item[i]);
			if (prefix[i] != NULL)
				ws += strlen(prefix[i]);
			if (suffix[i] != NULL)
				ws += strlen(suffix[i]);
			if (ws > w)
				w = ws;
		}
		if (w > 38)
			w = 38;

		x1 = (40 - w) / 2 - 1;
		x2 = x1 + w + 1;
		y1 = (24 - nitems) / 2 - 1;
		y2 = y1 + nitems + 1;
	}
	else {
		ClearScreen();
		TitleScreen(title);
		w = 38;
		x1 = 0;
		y1 = 1;
		x2 = 39;
		y2 = 23;
	}

	Box(0x9a, 0x94, x1, y1, x2, y2);
	index = Select(index, nitems, item, prefix, suffix, tip, nonselectable,
	                nitems, 1, x1 + 1, y1 + 1, w,
	                (flags & SELECT_DRAG) ? TRUE : FALSE, NULL, seltype);
	if (index < 0)
		return index;
	for (pmenu = menu; pmenu->item != NULL; pmenu++) {
		if (pmenu->flags != ITEM_HIDDEN) {
			if (index == 0)
				return pmenu->retval;
			index--;
		}
	}
	/* shouldn't happen */
	return -1;
}

int BasicUISelectInt(int default_value, int min_value, int max_value)
{
	static char item_values[100][4];
	static const char *items[100];
	int value;
	int nitems;
	int nrows;
	int ncolumns;
	int x1, y1, x2, y2;
	if (min_value < 0 || max_value > 99 || min_value > max_value)
		return default_value;
	nitems = 0;
	for (value = min_value; value <= max_value; value++) {
		items[nitems] = item_values[nitems];
		sprintf(item_values[nitems], "%2d", value);
		nitems++;
	}
	if (nitems <= 10) {
		nrows = nitems;
		ncolumns = 1;
	}
	else {
		nrows = 10;
		ncolumns = (nitems + 9) / 10;
	}
	x1 = (39 - 3 * ncolumns) >> 1;
	y1 = (22 - nrows) >> 1;
	x2 = x1 + 3 * ncolumns;
	y2 = y1 + nrows + 1;
	Box(0x9a, 0x94, x1, y1, x2, y2);
	value = Select((default_value >= min_value && default_value <= max_value) ? default_value - min_value : 0,
		nitems, items, NULL, NULL, NULL, NULL, nrows, ncolumns, x1 + 1, y1 + 1, 2, FALSE, NULL, NULL);
	return value >= 0 ? value + min_value : default_value;
}

#ifdef WIN32

static WIN32_FIND_DATA wfd;
static HANDLE dh = INVALID_HANDLE_VALUE;

#ifdef _WIN32_WCE
/* WinCE's FindFirstFile/FindNext file don't return "." or "..". */
/* We check if the parent folder exists and add ".." if necessary. */
static char parentdir[FILENAME_MAX];
#endif

static int BasicUIOpenDir(const char *dirname)
{
#ifdef UNICODE
	WCHAR wfilespec[FILENAME_MAX];
	if (MultiByteToWideChar(CP_ACP, 0, dirname, -1, wfilespec, FILENAME_MAX - 4) <= 0)
		return FALSE;
	wcscat(wfilespec, (dirname[0] != '\0' && dirname[strlen(dirname) - 1] != '\\')
		? L"\\*.*" : L"*.*");
	dh = FindFirstFile(wfilespec, &wfd);
#else /* UNICODE */
	char filespec[FILENAME_MAX];
	Util_strlcpy(filespec, dirname, FILENAME_MAX - 4);
	strcat(filespec, (dirname[0] != '\0' && dirname[strlen(dirname) - 1] != '\\')
		? "\\*.*" : "*.*");
	dh = FindFirstFile(filespec, &wfd);
#endif /* UNICODE */
#ifdef _WIN32_WCE
	Util_splitpath(dirname, parentdir, NULL);
#endif
	if (dh == INVALID_HANDLE_VALUE) {
		/* don't raise error if the path is ok but has no entries:
		   Win98 returns ERROR_FILE_NOT_FOUND,
		   WinCE returns ERROR_NO_MORE_FILES */
		DWORD err = GetLastError();
		if (err != ERROR_FILE_NOT_FOUND && err != ERROR_NO_MORE_FILES)
			return FALSE;
	}
	return TRUE;
}

static int BasicUIReadDir(char *filename, int *isdir)
{
	if (dh == INVALID_HANDLE_VALUE) {
#ifdef _WIN32_WCE
		if (parentdir[0] != '\0' && Util_direxists(parentdir)) {
			strcpy(filename, "..");
			*isdir = TRUE;
			parentdir[0] = '\0';
			return TRUE;
		}
#endif /* _WIN32_WCE */
		return FALSE;
	}
#ifdef UNICODE
	if (WideCharToMultiByte(CP_ACP, 0, wfd.cFileName, -1, filename, FILENAME_MAX, NULL, NULL) <= 0)
		filename[0] = '\0';
#else
	Util_strlcpy(filename, wfd.cFileName, FILENAME_MAX);
#endif /* UNICODE */
#ifdef _WIN32_WCE
	/* just in case they will implement it some day */
	if (strcmp(filename, "..") == 0)
		parentdir[0] = '\0';
#endif
	*isdir = (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) ? TRUE : FALSE;
	if (!FindNextFile(dh, &wfd)) {
		FindClose(dh);
		dh = INVALID_HANDLE_VALUE;
	}
	return TRUE;
}

#define DO_DIR

#elif defined(HAVE_OPENDIR)

static char dir_path[FILENAME_MAX];
static DIR *dp = NULL;

static int BasicUIOpenDir(const char *dirname)
{
	Util_strlcpy(dir_path, dirname, FILENAME_MAX);
	dp = opendir(dir_path);
	return dp != NULL;
}

static int BasicUIReadDir(char *filename, int *isdir)
{
	struct dirent *entry;
	char fullfilename[FILENAME_MAX];
	struct stat st;
	entry = readdir(dp);
	if (entry == NULL) {
		closedir(dp);
		dp = NULL;
		return FALSE;
	}
	strcpy(filename, entry->d_name);
	Util_catpath(fullfilename, dir_path, entry->d_name);
	stat(fullfilename, &st);
	*isdir = (st.st_mode & S_IFDIR) ? TRUE : FALSE;
	return TRUE;
}

#define DO_DIR

#elif defined(PS2)

int Atari_OpenDir(const char *filename);

static int BasicUIOpenDir(const char *dirname)
{
	char filename[FILENAME_MAX];
	Util_catpath(filename, dirname, "*");
	return Atari_OpenDir(filename);
}

int Atari_ReadDir(char *fullpath, char *filename, int *isdir,
                  int *readonly, int *size, char *timetext);

#define BasicUIReadDir(filename, isdir)  Atari_ReadDir(NULL, filename, isdir, NULL, NULL, NULL)

#define DO_DIR

#endif /* defined(PS2) */


#ifdef DO_DIR

static const char **filenames;
#define FILENAMES_INITIAL_SIZE 256 /* preallocate 1 KB */
static int n_filenames;

/* filename must be malloc'ed or strdup'ed */
static void FilenamesAdd(const char *filename)
{
	if (n_filenames >= FILENAMES_INITIAL_SIZE && (n_filenames & (n_filenames - 1)) == 0) {
		/* n_filenames is a power of two: allocate twice as much */
		filenames = (const char **) Util_realloc((void *) filenames, 2 * n_filenames * sizeof(const char *));
	}
	filenames[n_filenames++] = filename;
}

static int FilenamesCmp(const char *filename1, const char *filename2)
{
	if (filename1[0] == '[') {
		if (filename2[0] != '[')
			return -1;
		if (filename1[1] == '.') {
			if (filename2[1] != '.')
				return -1;
			/* return Util_stricmp(filename1, filename2); */
		}
		else if (filename2[1] == '.')
			return 1;
		/* return Util_stricmp(filename1, filename2); */
	}
	else if (filename2[0] == '[')
		return 1;
	return Util_stricmp(filename1, filename2);
}

/* quicksort */
static void FilenamesSort(const char **start, const char **end)
{
	while (start + 1 < end) {
		const char **left = start + 1;
		const char **right = end;
		const char *pivot = *start;
		const char *tmp;
		while (left < right) {
			if (FilenamesCmp(*left, pivot) <= 0)
				left++;
			else {
				right--;
				tmp = *left;
				*left = *right;
				*right = tmp;
			}
		}
		left--;
		tmp = *left;
		*left = *start;
		*start = tmp;
		FilenamesSort(start, left);
		start = right;
	}
}

static void FilenamesFree(void)
{
	while (n_filenames > 0)
		free((void *) filenames[--n_filenames]);
	free((void *) filenames);
}

static void GetDirectory(const char *directory)
{
#ifdef __DJGPP__
	unsigned short s_backup = _djstat_flags;
	_djstat_flags = _STAT_INODE | _STAT_EXEC_EXT | _STAT_EXEC_MAGIC | _STAT_DIRSIZE |
		_STAT_ROOT_TIME | _STAT_WRITEBIT;
	/* we do not need any of those 'hard-to-get' informations */
#endif	/* DJGPP */

	filenames = (const char **) Util_malloc(FILENAMES_INITIAL_SIZE * sizeof(const char *));
	n_filenames = 0;

	if (isZip(directory))
	{
		unzFile handle = unzOpen(directory);
		if (handle)
		{
			FilenamesAdd(Util_strdup("[..]"));
			if (UNZ_OK == unzGoToFirstFile(handle))
			{
				do
				{
					char filenameBuffer[256];
					unzGetCurrentFileInfo(handle,NULL,filenameBuffer, 256, NULL,0,NULL,0);
					//fprintf(stderr, "In zip %s\n", filenameBuffer);
					FilenamesAdd(Util_strdup(filenameBuffer));
				}while (UNZ_OK == unzGoToNextFile(handle));
			}
			unzClose(handle);
			FilenamesSort(filenames, filenames + n_filenames);
		}
	}
	else if (BasicUIOpenDir(directory)) {
		char filename[FILENAME_MAX];
		int isdir;

		while (BasicUIReadDir(filename, &isdir)) {
			char *filename2;

			if (filename[0] == '\0' ||
				(filename[0] == '.' && filename[1] == '\0'))
				continue;

			if (isdir || isZip(filename)) {
				/* add directories as [dir] */
				size_t len = strlen(filename);
				filename2 = (char *) Util_malloc(len + 3);
				memcpy(filename2 + 1, filename, len);
				filename2[0] = '[';
				filename2[len + 1] = ']';
				filename2[len + 2] = '\0';
			}
			else
				filename2 = Util_strdup(filename);

			FilenamesAdd(filename2);
		}

		FilenamesSort(filenames, filenames + n_filenames);
	}
	else {
		Aprint("Error opening '%s' directory", directory);
	}
#ifdef PS2
	FilenamesAdd(Util_strdup("[mc0:]"));
#endif
#ifdef DOS_DRIVES
	/* in DOS/Windows, add all existing disk letters */
	{
		char letter;
#ifdef WIN32
		DWORD drive_mask = GetLogicalDrives();
		for (letter = 'A'; letter <= 'Z'; letter++) {
			if (drive_mask & 1) {
				static char drive2[5] = "[C:]";
				drive2[1] = letter;
				FilenamesAdd(Util_strdup(drive2));
			}
			drive_mask >>= 1;
		}
#else /* WIN32 */
		for (letter = 'A'; letter <= 'Z'; letter++) {
#ifdef __DJGPP__
			static char drive[3] = "C:";
			struct stat st;
			drive[0] = letter;
			/* don't check floppies - it's slow */
			if (letter < 'C' || (stat(drive, &st) == 0 && (st.st_mode & S_IXUSR) != 0))
#endif /* __DJGPP__ */
			{
				static char drive2[5] = "[C:]";
				drive2[1] = letter;
				FilenamesAdd(Util_strdup(drive2));
			}
		}
#endif /* WIN32 */
	}
#endif /* DOS_DRIVES */
#ifdef __DJGPP__
	_djstat_flags = s_backup;	/* restore the original state */
#endif
}

/* Select file or directory.
   The result is returned in path and path is where selection begins (i.e. it must be initialized).
   pDirectories are "favourite" directories (there are nDirectories of them). */
static int FileSelector(char *path, int select_dir, char pDirectories[][FILENAME_MAX], int nDirectories)
{
	char current_dir[FILENAME_MAX];
	char highlighted_file[FILENAME_MAX];
	highlighted_file[0] = '\0';
	if (path[0] == '\0' && nDirectories > 0)
		strcpy(current_dir, pDirectories[0]);
	else if (select_dir)
		strcpy(current_dir, path);
	else
		Util_splitpath(path, current_dir, highlighted_file);
#ifdef __DJGPP__
	{
		char help_dir[FILENAME_MAX];
		_fixpath(current_dir, help_dir);
		strcpy(current_dir, help_dir);
	}
#elif defined(HAVE_GETCWD)
	if (current_dir[0] == '\0' || (current_dir[0] == '.' && current_dir[1] == '\0'))
		getcwd(current_dir, FILENAME_MAX);
#else
	if (current_dir[0] == '\0') {
		current_dir[0] = '.';
		current_dir[1] = '\0';
	}
#endif
	for (;;) {
		int index = 0;
		int i;

#define NROWS 20
#define NCOLUMNS 2
#define MAX_FILES (NROWS * NCOLUMNS)

		/* The WinCE version may spend several seconds when there are many
		   files in the directory. */
		/* The extra spaces are needed to clear the previous window title. */
		TitleScreen("            Please wait...            ");
		Atari_DisplayScreen();

		GetDirectory(current_dir);

		if (n_filenames == 0)
		{
			getcwd(current_dir, FILENAME_MAX);
			GetDirectory(current_dir);
		}

		if (n_filenames == 0) {
			/* FIXME: change to a safe directory */
			FilenamesFree();
			BasicUIMessage("No files inside directory");
			return FALSE;
		}

		if (highlighted_file[0] != '\0') {
			for (i = 0; i < n_filenames; i++) {
				if (strcmp(filenames[i], highlighted_file) == 0) {
					index = i;
					break;
				}
			}
		}

		for (;;) {
			int seltype;
			const char *selected_filename;

			ClearScreen();
			TitleScreen(current_dir);
			Box(0x9a, 0x94, 0, 1, 39, 23);

			index = Select(index, n_filenames, filenames, NULL, NULL, NULL, NULL,
			               NROWS, NCOLUMNS, 1, 2, 37 / NCOLUMNS, FALSE,
			               select_dir ? "Select: select current directory" : NULL,
			               &seltype);

			if (index == -2) {
				/* Tab = next favourite directory */
				if (nDirectories > 0) {
					/* default: pDirectories[0] */
					int current_index = nDirectories - 1;
					/* are we in one of pDirectories? */
					for (i = 0; i < nDirectories; i++)
						if (strcmp(pDirectories[i], current_dir) == 0) {
							current_index = i;
							break;
						}
					i = current_index;
					do {
						if (++i >= nDirectories)
							i = 0;
						if (Util_direxists(pDirectories[i])) {
							strcpy(current_dir, pDirectories[i]);
							break;
						}
					} while (i != current_index);
				}
				break;
			}
			if (index < 0) {
				/* Esc = cancel */
				FilenamesFree();
				return FALSE;
			}
			if (seltype == USER_DELETE) {
				/* Backspace = parent directory */
				char new_dir[FILENAME_MAX];
				Util_splitpath(current_dir, new_dir, NULL);
				if (Util_direxists(new_dir)) {
					strcpy(current_dir, new_dir);
					break;
				}
				continue;
			}
			if (seltype == USER_TOGGLE && select_dir) {
				/* Space = select current directory */
				strcpy(path, current_dir);
				FilenamesFree();
				return TRUE;
			}
			selected_filename = filenames[index];
			if (selected_filename[0] == '[') {
				/* Change directory */
				char new_dir[FILENAME_MAX];

				if (strcmp(selected_filename, "[..]") == 0) {
					/* go up */
					Util_splitpath(current_dir, new_dir, NULL);
				}
#ifdef PS2
				else if (strcmp(selected_filename, "[mc0:]") == 0) {
					strcpy(new_dir, "mc0:/");
				}
#endif
#ifdef DOS_DRIVES
				else if (selected_filename[2] == ':' && selected_filename[3] == ']') {
					/* disk selected */
					new_dir[0] = selected_filename[1];
					new_dir[1] = ':';
					new_dir[2] = '\\';
					new_dir[3] = '\0';
				}
#endif
				else {
					/* directory selected */
					char *pbracket = strrchr(selected_filename, ']');
					if (pbracket == NULL)
						continue; /* XXX: regular file? */
					*pbracket = '\0';	/*cut ']' */
					Util_catpath(new_dir, current_dir, selected_filename + 1);
				}
				/* check if new directory is valid */
				if (Util_direxists(new_dir) || isZip(new_dir)) {
					strcpy(current_dir, new_dir);
					break;
				}
				continue;
			}
			if (!select_dir) {
				/* normal filename selected */
				Util_catpath(path, current_dir, selected_filename);
				FilenamesFree();
				return TRUE;
			}
		}

		FilenamesFree();
		highlighted_file[0] = '\0';
	}
}

#endif /* DO_DIR */

/* nDirectories >= 0 means we are editing a file name */
static int EditString(int fg, int bg, const char *title,
                      char *string, int size, int x, int y, int width,
                      char pDirectories[][FILENAME_MAX], int nDirectories)
{
	int caret = strlen(string);
	int offset = 0;
	for (;;) {
		int i;
		char *p;
		int ascii;
		Box(fg, bg, x, y, x + 1 + width, y + 2);
		Print(bg, fg, title, x + 1, y, width);
		if (caret - offset >= width)
			offset = caret - width + 1;
		else if (caret < offset)
			offset = caret;
		p = string + offset;
		for (i = 0; i < width; i++)
			if (offset + i == caret)
				Plot(bg, fg, *p != '\0' ? *p++ : ' ', x + 1 + i, y + 1);
			else
				Plot(fg, bg, *p != '\0' ? *p++ : ' ', x + 1 + i, y + 1);
		ascii = GetKeyPress();
		switch (ascii) {
		case 0x1e:				/* Cursor Left */
			if (caret > 0)
				caret--;
			break;
		case 0x1f:				/* Cursor Right */
			if (string[caret] != '\0')
				caret++;
			break;
		case 0x7e:				/* Backspace */
			if (caret > 0) {
				caret--;
				p = string + caret;
				do
					p[0] = p[1];
				while (*p++ != '\0');
			}
			break;
		case 0xfe:				/* Delete */
			if (string[caret] != '\0') {
				p = string + caret;
				do
					p[0] = p[1];
				while (*p++ != '\0');
			}
			break;
		case 0x7d:				/* Clear screen */
		case 0x9c:				/* Delete line */
			caret = 0;
			string[0] = '\0';
			break;
		case 0x9b:				/* Return */
			if (nDirectories >= 0) {
				/* check filename */
				char lastchar;
				if (string[0] == '\0')
					return FALSE;
				lastchar = string[strlen(string) - 1];
				return lastchar != '/' && lastchar != '\\';
			}
			return TRUE;
		case 0x1b:				/* Esc */
			return FALSE;
#ifdef DO_DIR
		case 0x7f:				/* Tab = select directory */
			if (nDirectories >= 0) {
				char temp_filename[FILENAME_MAX + 1];
				char temp_path[FILENAME_MAX];
				char temp_file[FILENAME_MAX];
				char *p;
				/* FIXME: now we append '*' and then discard it
				   just to workaround Util_splitpath() not recognizing
				   DIR_SEP_CHAR when it's the last character */
				strcpy(Util_stpcpy(temp_filename, string), "*");
				Util_splitpath(temp_filename, temp_path, temp_file);
				p = temp_file + strlen(temp_file) - 1;
				if (*p == '*') { /* XXX: should be always... */
					*p = '\0';
					if (FileSelector(temp_path, TRUE, pDirectories, nDirectories)) {
						Util_catpath(string, temp_path, temp_file);
						caret = strlen(string);
						offset = 0;
					}
				}
			}
			break;
#endif
		default:
			/* Insert character */
			i = strlen(string);
			if (i + 1 < size && ascii >= ' ' && ascii < 0x7f) {
				do
					string[i + 1] = string[i];
				while (--i >= caret);
				string[caret++] = (char) ascii;
			}
			break;
		}
	}
}

/* returns TRUE if accepted filename */
static int EditFilename(const char *title, char *filename, char directories[][FILENAME_MAX], int n_directories)
{
	char edited_filename[FILENAME_MAX];
	strcpy(edited_filename, filename);
	if (edited_filename[0] == '\0') {
		if (n_directories > 0)
			strcpy(edited_filename, directories[0]);
#ifdef HAVE_GETCWD
		if (edited_filename[0] == '\0') {
			getcwd(edited_filename, FILENAME_MAX);
			if (edited_filename[0] != '\0' && strlen(edited_filename) < FILENAME_MAX - 1) {
				char *p = edited_filename + strlen(edited_filename) - 1;
				if (*p != '/' && *p != '\\') {
					p[1] = DIR_SEP_CHAR;
					p[2] = '\0';
				}
			}
		}
#endif
	}
	if (!EditString(0x9a, 0x94, title, edited_filename, FILENAME_MAX, 1, 11, 36, directories, n_directories))
		return FALSE;
	strcpy(filename, edited_filename);
	return TRUE;
}

int BasicUIEditString(const char *title, char *string, int size)
{
	return EditString(0x9a, 0x94, title, string, size, 3, 11, 32, NULL, -1);
}

char * toSaveFilename(const char * basename)
{
	int slashPos;
	char * pFilename = (char *)malloc(FILENAME_MAX);

	if (basename)
	{
		int fileLen = strlen(basename);
		if ((fileLen>4) && (basename[fileLen-4]=='.'))
		{
			// Take part before extension
			strcpy(pFilename, basename);
			pFilename[fileLen-4] = 0;
		}
		else
		{
			strcpy(pFilename, basename);
		}
	}
	else
	{
		strcpy(pFilename, "default");
	}

	// Strip anything before a slash
	slashPos = strlen(pFilename);
	while (slashPos--) 
	{
		if ((pFilename[slashPos] == '\\') || (pFilename[slashPos] == '/'))	
		{
			strcpy(pFilename, pFilename + slashPos + 1);
			break;
		}
	}

#ifdef GP32
	// on GP32 we have 8.3, truncate first part to 7!
	if (strlen(pFilename)>7)
		pFilename[8] = 0;
#endif

	return pFilename;
}

int BasicUIGetSaveFilename(char * ext, char *pFilename, char directories[][FILENAME_MAX], int n_directories)
{
	/*
#ifdef DO_DIR
	return EditFilename("Save as ([Tab] = directory locator)", filename, directories, n_directories);
#else
	return EditFilename("Save as", filename, directories, n_directories);
#endif
*/
	static char menuTitle[256];
	static tMenuItem menu_array[] = 
	{
		MENU_ACTION('T', "Type name"),
		MENU_FILESEL_PREFIX('D', "Choose dir", NULL),
		MENU_LABEL("---"),
		MENU_ACTION(3,NULL), 
		MENU_ACTION(4,NULL),
		MENU_ACTION(5,NULL),
		MENU_ACTION(6,NULL),
		MENU_ACTION(7,NULL),
		MENU_ACTION(8,NULL),
		MENU_ACTION(9,NULL),
		MENU_LABEL("---"),
		MENU_ACTION(11,NULL), 
		MENU_ACTION(12,NULL),
		MENU_ACTION(13,NULL),
		MENU_ACTION(14,NULL),
		MENU_ACTION(15,NULL),
		MENU_ACTION(16,NULL),
		MENU_ACTION(17,NULL),

		MENU_END
	};

	char * filename1, * filename2;
	int i;
	int result;

	strcpy(pFilename, directories[0]);

	// Default filename is SIO mounted disk1 -> removed extension and added .as$n ([A]tari [S]tate with a number for which one -> so 10 per disk...)
	sprintf(menuTitle, "Save as:");

	filename1 = toSaveFilename(currentMenu);
	filename2 = toSaveFilename(sio_filename[0]);

	for (i=3; i<=9; ++i)
	{
		char * temp = malloc(FILENAME_MAX);
		int len;
		strcpy(temp, filename1);
		len = strlen(temp);
		temp[len] = (i-3)+'1';
		temp[len+1] = '.';
		temp[len+2] = '\0';
		strcat(temp, ext);
		menu_array[i].item = temp;
	}

	for (i=11; i<=17; ++i)
	{
		char * temp = malloc(FILENAME_MAX);
		int len;
		strcpy(temp, filename2);
		len = strlen(temp);
		temp[len] = (i-11)+'1';
		temp[len+1] = '.';
		temp[len+2] = '\0';
		strcat(temp, ext);
		menu_array[i].item = temp;
	}

	free(filename1);
	free(filename2);

	result = FALSE;

	while (result==FALSE)
	{
		int option;
		menu_array[1].item = pFilename;
		option = BasicUISelect(menuTitle, 0, '1', menu_array, NULL);
		if (option >=0)
		{
			if (option == 'T')
			{
				// Type in the name...
				char pFilename2[256];
				strcpy(pFilename2, pFilename);
#ifdef BACK_SLASH
				strcat(pFilename2, "\\");
#else
				strcat(pFilename2, "/");
#endif
				result = EditFilename("Save as ([Tab] = directory locator)", pFilename2, directories, n_directories);
				strcpy(pFilename,pFilename2);
			}
			else if (option == 'D')
			{
				FileSelector(pFilename, TRUE, directories, n_directories);
			}
			else
			{
				if (menu_array[option].item)
				{
#ifdef BACK_SLASH
					strcat(pFilename, "\\");
#else
					strcat(pFilename, "/");
#endif
					strcat(pFilename, menu_array[option].item);
					result = TRUE;
				}
			}
		}
		else
			break;
	}

	for (i=3; i<=9; ++i)
		free(menu_array[i].item);

	for (i=11; i<=17; ++i)
		free(menu_array[i].item);

	return result;
}

int BasicUIGetLoadFilename(char *filename, char directories[][FILENAME_MAX], int n_directories)
{
#ifdef DO_DIR
	return FileSelector(filename, FALSE, directories, n_directories);
#else
	return EditFilename("Filename", filename, directories, n_directories);
#endif
}

int BasicUIGetDirectoryPath(char *directory)
{
#ifdef DO_DIR
	return FileSelector(directory, TRUE, NULL, 0);
#else
	return EditFilename("Path", directory, NULL, -1);
#endif
}

void BasicUIInfoScreen(const char *title, const char *message)
{
	int y = 2;
	ClearScreen();
	TitleScreen(title);
	Box(0x9a, 0x94, 0, 1, 39, 23);
	while (*message != '\n') {
		CenterPrint(0x9a, 0x94, message, y++);
		while (*message++ != '\0');
	}
	BasicUIMessage("Press any key to continue");
}

void BasicUIInit(void)
{
	UI_Init(); // MWW: Still needed?
	if (!initialised) {
		get_charset(charset);
		initialised = TRUE;
	}
}

tUIDriver basic_ui_driver = {
	&BasicUISelect,
	&BasicUISelectInt,
	&BasicUIEditString,
	&BasicUIGetSaveFilename,
	&BasicUIGetLoadFilename,
	&BasicUIGetDirectoryPath,
	&BasicUIMessage,
	&BasicUIInfoScreen,
	&BasicUIInit
};