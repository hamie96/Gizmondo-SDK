#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include "SDL.h"
#include "gizmondo.h"

extern int uae4all_keystate[256];
extern void record_key(int);

int vol = 100;
//volatile unsigned short *MEM_REG;

unsigned long soundDev;
//unsigned long memDev;
int soundVolume = 100;
int flashLED;

int gp2xMouseEmuOn;
int gp2xButtonRemappingOn;
int hasGp2xButtonRemapping;
//int gp2xClockSpeed;
char launchDir [300];

void gizmondo_init()
{
	soundVolume=100;
	flashLED = 0;

	SDL_ShowCursor(SDL_DISABLE);
	getcwd(launchDir, 250);
}

int is_overridden_button(int button)
{
	// TODO: load from file
	return false;
	/*return button == GIZ_LTRIG || button == GIZ_RTRIG || 
		   button == GP2X_BUTTON_A || button == GP2X_BUTTON_B ||
		   button == GP2X_BUTTON_X || button == GP2X_BUTTON_Y;*/
}

int get_key_for_button(int button)
{
	// TODO: load from file
	/*if (button == GP2X_BUTTON_L)
	{
		return 0x66; // left amiga
	}
	else if (button == GP2X_BUTTON_R)
	{
		return 0x67; // right amiga
	}
	else if (button == GP2X_BUTTON_A)
	{
		return 0x50; // f1
	}
	else if (button == GP2X_BUTTON_B)
	{
		return 0x4d; // down arrow
	}
	else if (button == GP2X_BUTTON_X)
	{
		return 0x40; // space
	}
	else if (button == GP2X_BUTTON_Y)
	{
		return 0x40; // space
	}*/
	return 0;
}

// apply the remapped button keystroke
void handle_remapped_button_down(int button)
{
	int key = get_key_for_button(button);
	if (!uae4all_keystate[key])
	{
		uae4all_keystate[key] = 1;
		record_key(key << 1);
	}
}

void handle_remapped_button_up(int button)
{
	int key = get_key_for_button(button);

	if (uae4all_keystate[key])
	{
		uae4all_keystate[key] = 0;
		record_key((key << 1) | 1);
	}
}


