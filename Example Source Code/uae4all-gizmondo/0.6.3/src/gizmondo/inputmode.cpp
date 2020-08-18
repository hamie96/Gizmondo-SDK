#include<stdio.h>
#include<stdlib.h>
#include<SDL.h>
#include "gizmondo.h"
#include "inputmode.h"

extern char launchDir [300];

extern SDL_Surface *prSDLScreen;

static SDL_Surface *ksur;
static SDL_Surface *inputMode[3];

extern int gp2xMouseEmuOn, gp2xButtonRemappingOn, show_inputmode;

void inputmode_init(void)
{
	int i;
	char tmpchar[256];
	SDL_Surface* tmp;

	tmp = SDL_LoadBMP("\\SD Card\\uae4all\\data\\joystick.bmp");

	if (tmp)
	{
		inputMode[0] = SDL_DisplayFormat(tmp);
		SDL_FreeSurface(tmp);
	}
	
	tmp = SDL_LoadBMP("\\SD Card\\uae4all\\data\\mouse.bmp");

	if (tmp)
	{
		inputMode[1] = SDL_DisplayFormat(tmp);
		SDL_FreeSurface(tmp);
	}

	tmp = SDL_LoadBMP("\\SD Card\\uae4all\\data\\remapping.bmp");

	if (tmp)
	{
		inputMode[2] = SDL_DisplayFormat(tmp);
		SDL_FreeSurface(tmp);
	}

	show_inputmode = 0;
}


void inputmode_redraw(void)
{
	SDL_Rect r;
	SDL_Surface* surface;

	r.x=80;
	r.y=prSDLScreen->h-200;
	r.w=160;
	r.h=160;

	if (inputMode[0] && inputMode[1] && inputMode[2])
	{
		if (gp2xMouseEmuOn)
		{
			surface = inputMode[1];
		}
		else if (gp2xButtonRemappingOn)
		{
			surface = inputMode[2];
		}
		else
		{
			surface = inputMode[0];
		}

		SDL_BlitSurface(surface,NULL,prSDLScreen,&r);
	}
}

