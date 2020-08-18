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

#include "global.h"
#include "psp_kbd.h"
#include "psp_menu.h"
#include "psp_sdl.h"

#include "gp2x_psp.h"

# define KBD_MIN_ANALOG_TIME  150000
# define KBD_MIN_START_TIME   800000
# define KBD_MAX_EVENT_TIME   500000
# define KBD_MIN_PENDING_TIME 300000
# define KBD_MIN_COMMAND_TIME 100000
# define KBD_MIN_BATTCHECK_TIME 90000000 

 static gp2xCtrlData    loc_button_data;
 static unsigned int   loc_last_event_time = 0;
 static unsigned int   loc_last_analog_time = 0;
 static long           first_time_stamp = -1;
 static char           loc_button_press[ KBD_MAX_BUTTONS ]; 
 static char           loc_button_release[ KBD_MAX_BUTTONS ]; 
 static unsigned int   loc_button_mask[ KBD_MAX_BUTTONS ] =
 {
   GP2X_CTRL_UP         ,
   GP2X_CTRL_RIGHT      ,
   GP2X_CTRL_DOWN       ,
   GP2X_CTRL_LEFT       ,
   GP2X_CTRL_STOP   ,
   GP2X_CTRL_PLAY     ,
   GP2X_CTRL_RWND      ,
   GP2X_CTRL_FFWD     ,
   GP2X_CTRL_LTRIGGER     ,
   GP2X_CTRL_RTRIGGER      ,
   GP2X_CTRL_HOME,
   GP2X_CTRL_STAR   ,
   GP2X_CTRL_TRI,  
   GP2X_CTRL_POWER 
 };

  static char loc_button_name[ KBD_ALL_BUTTONS ][10] =
  {
   "UP",
   "RIGHT",
   "DOWN",
   "LEFT",
   "STOP",
   "PLAY",
   "REWIND",
   "FFORWARD",
   "LTRIGGER",
   "RTRIGGER",
   "HOME",
	"STAR",
	"TRI"
	"POWER"
 };

  struct atari_key_trans psp_atari_key_info[ATARI_MAX_KEY]=
  {
    { ATARI_JOY1_RIGHT, "J1 RIGHT" },
    { ATARI_JOY1_LEFT , "J1 LEFT" },
    { ATARI_JOY1_DOWN , "J1 DOWN" },
    { ATARI_JOY1_UP   , "J1 UP" },
    { ATARI_JOY1_FIRE1, "J1 FIRE1" },
    { ATARI_JOY1_FIRE2, "J1 FIRE2" },

    { ATARI_JOY2_RIGHT, "J2 RIGHT" },
    { ATARI_JOY2_LEFT,  "J2 LEFT" },
    { ATARI_JOY2_DOWN,  "J2 DOWN" },
    { ATARI_JOY2_UP,    "J2 UP" },
    { ATARI_JOY2_FIRE1, "J2 FIRE1" },
    { ATARI_JOY2_FIRE2, "J2 FIRE2" },

    { ATARI_RESET,     "RESET" },
    { ATARI_SELECT,    "SELECT" },
    { ATARI_PAUSE,     "PAUSE" },
	{ ATARI_LDIFF,     "L DIFCULTY" },
	{ ATARI_RDIFF,     "R DIFCULTY" },
  };

/*   GP2X_CTRL_UP         ,
   GP2X_CTRL_RIGHT      ,
   GP2X_CTRL_DOWN       ,
   GP2X_CTRL_LEFT       ,
   GP2X_CTRL_STOP   ,
   GP2X_CTRL_PLAY     ,
   GP2X_CTRL_RWND      ,
   GP2X_CTRL_FFWD     ,
   GP2X_CTRL_LTRIGGER     ,
   GP2X_CTRL_RTRIGGER      ,
   GP2X_CTRL_STAR   ,
   GP2X_CTRL_TRI,  
   GP2X_CTRL_POWER 
*/

 static int loc_default_mapping[ KBD_ALL_BUTTONS ] = {
    ATARI_JOY1_UP          ,
    ATARI_JOY1_RIGHT       ,
    ATARI_JOY1_DOWN        ,
    ATARI_JOY1_LEFT        ,
    ATARI_JOY1_FIRE1            ,
    ATARI_JOY1_FIRE2            ,
    ATARI_JOY1_FIRE1       ,
    ATARI_JOY1_FIRE2       ,
    ATARI_LDIFF                     ,
    ATARI_RDIFF                     ,
	-1,
    ATARI_PAUSE       ,
    ATARI_SELECT          ,
    ATARI_RESET       
  };

 int psp_kbd_mapping[ KBD_ALL_BUTTONS ];
 int psp_kbd_mapping_L[ KBD_ALL_BUTTONS ];
 int psp_kbd_mapping_R[ KBD_ALL_BUTTONS ];
 int psp_kbd_presses[ KBD_ALL_BUTTONS ];
 int kbd_ltrigger_mapping_active;
 int kbd_rtrigger_mapping_active;

        int psp_kbd_mapping[ KBD_ALL_BUTTONS ];
int
atari_key_event(int atari_idx, int button_press)
{
  if (ATARI.psp_active_joystick) {
    if ((atari_idx >= ATARI_JOY1_RIGHT) && 
        (atari_idx <= ATARI_JOY1_FIRE2)) {
      /* Convert Joystick Player 1 -> Player 2 ? */
      atari_idx = atari_idx - ATARI_JOY1_RIGHT + ATARI_JOY2_RIGHT;
    }
  }

  if ((atari_idx >=            0) && 
      (atari_idx < ATARI_MAX_KEY)) {

    if (button_press) {
      ATARI.keyboard_data[atari_idx] = 1;
    } else {
      ATARI.keyboard_data[atari_idx] = 0;
    }
  }
  return 0;
}
int 
atari_kbd_reset()
{
  memset(ATARI.keyboard_data, 0, sizeof(ATARI.keyboard_data));
  return 0;
}

int
psp_kbd_reset_mapping(void)
{
  memcpy(psp_kbd_mapping, loc_default_mapping, sizeof(loc_default_mapping));
  return 0;
}

int
psp_kbd_load_mapping(char *kbd_filename)
{
  FILE    *KbdFile;
  int      error = 0;
  
  KbdFile = fopen(kbd_filename, "r");
  error   = 1;

  if (KbdFile != (FILE*)0) {
  psp_kbd_load_mapping_file(KbdFile);
  error = 0;
    fclose(KbdFile);
  }
    
  return error;
}

int
psp_kbd_load_mapping_file(FILE *KbdFile)
{
  char     Buffer[512];
  char    *Scan;
  int      tmp_mapping[KBD_ALL_BUTTONS];
  int      atari_key_id = 0;
  int      kbd_id = 0;

  memcpy(tmp_mapping, loc_default_mapping, sizeof(loc_default_mapping));

  while (fgets(Buffer,512,KbdFile) != (char *)0) {
      
      Scan = strchr(Buffer,'\n');
      if (Scan) *Scan = '\0';
      /* For this #@$% of windows ! */
      Scan = strchr(Buffer,'\r');
      if (Scan) *Scan = '\0';
      if (Buffer[0] == '#') continue;

      Scan = strchr(Buffer,'=');
      if (! Scan) continue;
    
      *Scan = '\0';
      atari_key_id = atoi(Scan + 1);

      for (kbd_id = 0; kbd_id < KBD_ALL_BUTTONS; kbd_id++) {
        if (!strcasecmp(Buffer,loc_button_name[kbd_id])) {
          tmp_mapping[kbd_id] = atari_key_id;
          //break;
        }
      }
  }

  memcpy(psp_kbd_mapping, tmp_mapping, sizeof(psp_kbd_mapping));
  
  return 0;
}

int
psp_kbd_save_mapping(char *kbd_filename)
{
  FILE    *KbdFile;
  int      kbd_id = 0;
  int      error = 0;

  KbdFile = fopen(kbd_filename, "w");
  error   = 1;

  if (KbdFile != (FILE*)0) {

    for (kbd_id = 0; kbd_id < KBD_ALL_BUTTONS; kbd_id++)
    {
      fprintf(KbdFile, "%s=%d\n", loc_button_name[kbd_id], psp_kbd_mapping[kbd_id]);
    }
    error = 0;
    fclose(KbdFile);
  }

  return error;
}

int
atari_decode_key(int psp_b, int button_pressed)
{
  int wake = 0;

  if (psp_b == KBD_HOME) {
    if (button_pressed) {
      psp_main_menu();
      psp_init_keyboard();
    }
  } else  
    if (psp_kbd_mapping[psp_b] >= 0) {
      wake = 1;
      if (button_pressed) {
          // Use standard mapping
          psp_kbd_presses[psp_b] = psp_kbd_mapping[psp_b];
          atari_key_event(psp_kbd_presses[psp_b], button_pressed);
      } else {
          // Determine which button to release (ie what was pressed before)
          atari_key_event(psp_kbd_presses[psp_b], button_pressed);
      }
  }
  return 0;
}

static int 
kbd_reset_button_status(void)
{
  int b = 0;
  /* Reset Button status */
  for (b = 0; b < KBD_MAX_BUTTONS; b++) {
    loc_button_press[b]   = 0;
    loc_button_release[b] = 0;
  }
  psp_init_keyboard();
  return 0;
}

int
kbd_scan_keyboard(void)
{
  gp2xCtrlData c;
  long        delta_stamp;
  int         event;
  int         b;

  int new_Lx;
  int new_Ly;
  int old_Lx;
  int old_Ly;

  event = 0;
  gp2xCtrlPeekBufferPositive( &c, 1 );

  for (b = 0; b < KBD_MAX_BUTTONS; b++) 
  {
    if (c.Buttons & loc_button_mask[b]) {
      if (!(loc_button_data.Buttons & loc_button_mask[b])) {
        loc_button_press[b] = 1;
        event = 1;
      }
    } else {
      if (loc_button_data.Buttons & loc_button_mask[b]) {
        loc_button_release[b] = 1;
        event = 1;
      }
    }
  }
  memcpy(&loc_button_data,&c,sizeof(gp2xCtrlData));

  return event;
}

void
psp_init_keyboard(void)
{
  atari_kbd_reset();
  kbd_ltrigger_mapping_active = 0;
  kbd_rtrigger_mapping_active = 0;
}

void
psp_kbd_wait_no_button(void)
{
  gp2xCtrlData c;

  do {
   gp2xCtrlPeekBufferPositive(&c, 1);
  } while (c.Buttons != 0);
} 

void
psp_kbd_wait_button(void)
{
  gp2xCtrlData c;

  do {
   gp2xCtrlReadBufferPositive(&c, 1);
  } while (c.Buttons == 0);
} 

int
psp_update_keys(void)
{
  int         b;

  static char first_time = 1;
  static int release_pending = 0;

  if (first_time) {
    gp2xCtrlData c;

    memcpy(psp_kbd_mapping, loc_default_mapping, sizeof(loc_default_mapping));

    atari_kbd_load();

    gp2xCtrlPeekBufferPositive(&c, 1);

    if (first_time_stamp == -1) first_time_stamp = c.TimeStamp;
    if ((! c.Buttons) && ((c.TimeStamp - first_time_stamp) < KBD_MIN_START_TIME)) return 0;

    first_time      = 0;
    release_pending = 0;

    for (b = 0; b < KBD_MAX_BUTTONS; b++) {
      loc_button_release[b] = 0;
      loc_button_press[b] = 0;
    }
    gp2xCtrlPeekBufferPositive(&loc_button_data, 1);

    psp_main_menu();
    psp_init_keyboard();

    return 0;
  }

  if (release_pending)
  {
    release_pending = 0;
    for (b = 0; b < KBD_MAX_BUTTONS; b++) {
      if (loc_button_release[b]) {
        loc_button_release[b] = 0;
        loc_button_press[b] = 0;
        atari_decode_key(b, 0);
      }
    }
  }

  kbd_scan_keyboard();

  /* check press event */
  for (b = 0; b < KBD_MAX_BUTTONS; b++) {
    if (loc_button_press[b]) {
      loc_button_press[b] = 0;
      release_pending     = 0;
      atari_decode_key(b, 1);
    }
  }
  /* check release event */
  for (b = 0; b < KBD_MAX_BUTTONS; b++) {
    if (loc_button_release[b]) {
      release_pending = 1;
      break;
    }
  }

  return 0;
}
