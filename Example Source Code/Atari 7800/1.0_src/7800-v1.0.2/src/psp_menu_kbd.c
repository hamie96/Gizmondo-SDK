/*
 *  Copyright (C) 2006 Ludovic Jacomme (ludovic.jacomme@gmail.com)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <stdio.h>
#include <stdlib.h>
//#include <signal.h>
//#include <unistd.h>
#include <string.h>
//#include <errno.h>
//#include <sys/time.h>
//#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "global.h"
#include "psp_sdl.h"
#include "psp_kbd.h"
#include "psp_menu.h"
#include "psp_fmgr.h"
#include "psp_menu_kbd.h"

# define MENU_KBD_UP         0
# define MENU_KBD_DOWN       1
# define MENU_KBD_LEFT       2
# define MENU_KBD_RIGHT      3
# define MENU_KBD_STOP      4
# define MENU_KBD_PLAY     5
# define MENU_KBD_RWND   6
# define MENU_KBD_FFWD    7
# define MENU_KBD_LTRIGGER  8
# define MENU_KBD_RTRIGGER  9
# define MENU_KBD_STAR    10
# define MENU_KBD_TRI  11
# define MENU_KBD_POWER  12

# define MENU_KBD_LOAD      13
# define MENU_KBD_SAVE      14
# define MENU_KBD_RESET     15

# define MENU_KBD_BACK      16

# define MAX_MENU_KBD_ITEM (MENU_KBD_BACK + 1)

  static menu_item_t menu_list[] =
  { 
    "Up       :",
    "Down     :",
    "Left     :",
    "Right    :",
    "Stop     :",
    "Play     :",
    "Rewind   :",
    "Fst Fward:",
    "LTrigger :",
    "RTrigger :",
    "Asterisk :",
    "Triangle :",
    "Power    :",

    "Load Keyboard",
    "Save Keyboard",
    "Reset Keyboard",
    "Back to Menu" 
  };

  static int cur_menu_id = MENU_KBD_LOAD;

  static int loc_kbd_mapping[ KBD_ALL_BUTTONS ];

  static int psp_menu_dirty = 1;

  int menu_kbd_selected = -1;
  
static int
psp_kbd_menu_id_to_key_id(int menu_id)
{
  int kbd_id = 0;

  switch ( menu_id ) 
  {
    case MENU_KBD_UP        : kbd_id = KBD_UP;        break;
    case MENU_KBD_DOWN      : kbd_id = KBD_DOWN;      break;
    case MENU_KBD_LEFT      : kbd_id = KBD_LEFT;      break;
    case MENU_KBD_RIGHT     : kbd_id = KBD_RIGHT;     break;
    case MENU_KBD_STOP      : kbd_id = KBD_STOP;      break;
    case MENU_KBD_PLAY      : kbd_id = KBD_PLAY;      break;
    case MENU_KBD_RWND      : kbd_id = KBD_RWND;      break;
    case MENU_KBD_FFWD      : kbd_id = KBD_FFWD;      break;
    case MENU_KBD_LTRIGGER  : kbd_id = KBD_LTRIGGER;  break;
    case MENU_KBD_RTRIGGER  : kbd_id = KBD_RTRIGGER;  break;
    case MENU_KBD_STAR      : kbd_id = KBD_STAR;      break;
    case MENU_KBD_TRI       : kbd_id = KBD_TRI;       break;
    case MENU_KBD_POWER     : kbd_id = KBD_POWER;     break;
  }
  return kbd_id;
}

static void 
psp_display_screen_kbd_menu(void)
{
  char buffer[32];
  char *scan;
  int menu_id = 0;
  int kbd_id  = 0;
  int atari_key = 0;
  int color   = 0;
  int x       = 0;
  int y       = 0;
  int y_step  = 0;

  if (psp_menu_dirty) 
  {
    psp_sdl_blit_background();
    //psp_menu_dirty = 0;
  }
  
  x      = 10;
  y      = 15;
  y_step = 10;
  
  for (menu_id = 0; menu_id < MAX_MENU_KBD_ITEM; menu_id++) 
  {
    if (cur_menu_id == menu_id) color = PSP_MENU_SEL_COLOR;
    else 
		color = PSP_MENU_TEXT_COLOR;

    psp_sdl_back2_print(x, y, menu_list[menu_id].title, color);

    if ((menu_id >= MENU_KBD_UP       ) && 
        (menu_id <= MENU_KBD_POWER)) 
    {
      kbd_id  = psp_kbd_menu_id_to_key_id(menu_id);

      atari_key = loc_kbd_mapping[kbd_id];

      if ((atari_key >= 0) && (atari_key < ATARI_MAX_KEY)) {
        strcpy(buffer, psp_atari_key_info[atari_key].name);
      } else 
      if (atari_key == KBD_UNASSIGNED) {
        sprintf(buffer, "UNASSIGNED");
      } else
	  {
        sprintf(buffer, "KEY %d", atari_key);
      }
      string_fill_with_space(buffer, 12);
      psp_sdl_back2_print(80, y, buffer, color);

      if (menu_id == MENU_KBD_POWER) {
        y += y_step;
      }
    }
    y += y_step;
  }

  psp_menu_display_save_name();
}

static void
psp_keyboard_menu_reset_kbd(void)
{
  psp_display_screen_kbd_menu();
  psp_sdl_back2_print(180, 80, "Reset Keyboard !", 
                     PSP_MENU_WARNING_COLOR);
  psp_menu_dirty = 1;
  psp_sdl_flip();
  psp_kbd_reset_mapping();
  sleep(1);

  memcpy(loc_kbd_mapping, psp_kbd_mapping, sizeof(psp_kbd_mapping));
}

static void
psp_keyboard_menu_load()
{
  int ret;

  ret = psp_fmgr_menu(FMGR_FORMAT_KBD);
  if (ret ==  1) /* load OK */
  {
    psp_display_screen_kbd_menu();
    psp_sdl_back2_print(180, 80, "File loaded !", 
                       PSP_MENU_NOTE_COLOR);
    psp_menu_dirty = 1;
    psp_sdl_flip();
    sleep(1);
  }
  else 
  if (ret == -1) /* Load Error */
  {
    psp_display_screen_kbd_menu();
    psp_sdl_back2_print(180, 80, "Can't load file !", 
                       PSP_MENU_WARNING_COLOR);
    psp_menu_dirty = 1;
    psp_sdl_flip();
    sleep(1);
  }

  memcpy(loc_kbd_mapping  , psp_kbd_mapping, sizeof(psp_kbd_mapping));
}

static void
psp_keyboard_menu_mapping(int kbd_id, int step)
{
  int *ploc_kbd_mapping;

  ploc_kbd_mapping = loc_kbd_mapping;

  if (step < 0) ploc_kbd_mapping[kbd_id]--;
  else
  if (step > 0) ploc_kbd_mapping[kbd_id]++;

  if (ploc_kbd_mapping[kbd_id] <  -1) ploc_kbd_mapping[kbd_id] = ATARI_MAX_KEY-1;
  else
  if (ploc_kbd_mapping[kbd_id] >= ATARI_MAX_KEY) ploc_kbd_mapping[kbd_id] = -1;
}

static void
psp_keyboard_menu_save()
{
  int error;

  memcpy(psp_kbd_mapping  , loc_kbd_mapping  , sizeof(psp_kbd_mapping));

  error = atari_kbd_save();

  if (! error) /* save OK */
  {
    psp_display_screen_kbd_menu();
    psp_sdl_back2_print(180, 80, "File saved !", 
                       PSP_MENU_NOTE_COLOR);
    psp_menu_dirty = 1;
    psp_sdl_flip();
    sleep(1);
  }
  else 
  {
    psp_display_screen_kbd_menu();
    psp_sdl_back2_print(180, 80, "Can't save file !", 
                       PSP_MENU_WARNING_COLOR);
    psp_menu_dirty = 1;
    psp_sdl_flip();
    sleep(1);
  }
}

void 
psp_keyboard_menu(void)
{
  long new_pad;
  long old_pad;
  int  last_time;
  int  end_menu;
  int  kbd_id;
  int  atari_key;
  int  danzeff_mode;
  int  danzeff_key;

  psp_menu_dirty = 1;

  psp_kbd_wait_no_button();

  old_pad      = 0;
  last_time    = 0;
  end_menu     = 0;
  kbd_id       = 0;

  danzeff_key  = 0;
  danzeff_mode = 0;

  memcpy(loc_kbd_mapping  , psp_kbd_mapping  , sizeof(psp_kbd_mapping));

  while (! end_menu)
  {
	gp2xCtrlData c;
    psp_display_screen_kbd_menu();

//    if (danzeff_mode) {
 //     danzeff_moveTo(-10, -50);
 //     danzeff_render();
 //   }
    psp_sdl_flip();

    gp2xCtrlPeekBufferPositive(&c, 1);
    c.Buttons &= PSP_ALL_BUTTON_MASK;

    new_pad = c.Buttons;

    if ((old_pad != new_pad) || ((c.TimeStamp - last_time) > PSP_MENU_KBD_MIN_TIME)) {
      last_time = c.TimeStamp;
      old_pad = new_pad;

    } else continue;

    if ((new_pad & GP2X_CTRL_PLAY ) || 
        (new_pad & GP2X_CTRL_FFWD) || 
        (new_pad & GP2X_CTRL_RWND)
	)
    {
      int step;

      if (new_pad & GP2X_CTRL_RWND)  step = -1;
      else 
      if (new_pad & GP2X_CTRL_FFWD) step =  1;
      else                            step =  0;

      if ((cur_menu_id >= MENU_KBD_UP       ) && 
          (cur_menu_id <= MENU_KBD_POWER)) 
      {
        kbd_id = psp_kbd_menu_id_to_key_id(cur_menu_id);
        psp_keyboard_menu_mapping(kbd_id, step); 
      }
      else
      {
        switch (cur_menu_id ) 
        {
          case MENU_KBD_LOAD  : psp_menu_dirty = 1;
                                psp_keyboard_menu_load();
                                psp_menu_dirty = 1;
                                old_pad = new_pad = 0;
                                menu_kbd_selected = -1;
          break;
          case MENU_KBD_SAVE  : psp_keyboard_menu_save();
          break;
          case MENU_KBD_RESET : psp_keyboard_menu_reset_kbd();
          break;
  
          case MENU_KBD_BACK  : end_menu = 1;
          break;
        }
      }

    } else
    if(new_pad & GP2X_CTRL_UP) {

      if (cur_menu_id > 0) cur_menu_id--;
      else                 cur_menu_id = MAX_MENU_KBD_ITEM-1;

    } else
    if(new_pad & GP2X_CTRL_DOWN) {

      if (cur_menu_id < (MAX_MENU_KBD_ITEM-1)) cur_menu_id++;
      else                                     cur_menu_id = 0;

    } else  
    if(new_pad & GP2X_CTRL_STOP) {
      /* Cancel */
      end_menu = -1;
    } else 
    if(new_pad & GP2X_CTRL_HOME) {
      /* Back to Main Menu */
      end_menu = 1;
    }
  }
 
  if (end_menu > 0) {
    /* Validate */
    memcpy(psp_kbd_mapping  , loc_kbd_mapping  , sizeof(psp_kbd_mapping));
  }

  psp_kbd_wait_no_button();
}

