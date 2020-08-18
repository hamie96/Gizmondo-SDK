#include "atari.h"
#include "config.h"
#include "input.h"
#include "ui.h"
#include "atari.h"
#include "platform.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "atari_gp32.h"
#include "sound.h"
#include "pokey.h"
#include "menu_c.h"
#include "menu_keymap.h"
#include "gp2xjoy.h"

//#include "gp2xminlib.h"

#include "log.h"
#include "util.h"

#include <math.h>

#ifndef M_PI
#define M_PI 3.1415926535
#define M_PI_4 (M_PI/4)
#endif

unsigned char menuWidth = 0; //Either height or width at present...
unsigned char menuHeight = 0;
int fastForward = 0;
static int brokenUI = 0;
static int brokenNormal = 0;
static int keymapInit = 0;

char atari_menu_filename[FILENAME_MAX] = FILENAME_NOT_SET;
char atari_uimenu_filename[FILENAME_MAX] = FILENAME_NOT_SET;

void setFastForward(int onOff)
{
	if (onOff == fastForward)
		return;
	if (onOff)
	{
		// Set to max known possible clock speed
		Sound_Pause();
		GP32_SetClockMax(1);
		fastForward = 1;
	}
	else
	{
		GP32_SetClockMax(0);
		Sound_Continue();
		fastForward = 0;
	}
}

///////////////////////////////////////////////////////////////////////
// Interface -> called externally
void Menu_Initialise()
{
	char * menuFile;

	if (!keymapInit)
	{
		initKeymap();
		keymapInit = 1;
	}

	menuFile = malloc(FILENAME_MAX);

	brokenUI = 0;
	brokenNormal = 0;

	menuActivateUi();
	if (!menuLoad(atari_uimenu_filename))
	{
		brokenUI = 1;
	}

	menuActivateMain();
	if (!menuLoad(atari_menu_filename))
	{
		brokenNormal = 1;
	}

	free(menuFile);

	// Init chatboard listener
	//TODO preInitKbd(9600, GpPClkGet());
}

void Menu_Frame()
{
	int joyswitches,x,y,buttons;
	int operation;
	int key_5200power;
	int i;
	static int power = 0;
	int key_break;
	static int ctrl = 0;
	int ch;

	if (brokenUI || brokenNormal)
	{
		Sound_Pause();
		GpRectFill(0, Atari_DisplayActiveBuffer(), 0, 0,320,240,0);
		GpTextOut(0,Atari_DisplayActiveBuffer(),20,50,"Unable to load input cfg, need", 0x48);
		GpTextOut(0,Atari_DisplayActiveBuffer(),20,60,"ui.men(UIMENU in cfg)", 0x0f);
		GpTextOut(0,Atari_DisplayActiveBuffer(),20,90,"default.men(MENU in cfg)", 0x0f);
		GpTextOut(0,Atari_DisplayActiveBuffer(),20,150,"Used built in defaults", 0x0f);
		gp2x_video_flip();
		while (!joyPressed()) Sleep(1);
		while (joyPressed()) Sleep(1);
		Sound_Continue();
		brokenUI = brokenNormal = 0;
	}
		
	readAllJoy(&joyswitches, &x,&y,&buttons);
	menuFrame(x,y,buttons);

	operation = menuOper();
	key_code = menuKey();
	key_consol = menuConsol();
	key_shift = menuShift();
	key_5200power = menu5200Power();
	//if (key_5200power!=0)
	//	fprintf(stderr, "Power:%d\n",key_5200power);
	menuJoy(joyValue, fireValue);

	// Not allowed to remap joy on 5200, so there!
	// Hardcoded...
	i=0;
    if (machine_type == MACHINE_5200) 
	{
		int x5200_mid = 120;
		int y5200_mid = 114;
		int x5200 = x5200_mid;
		int y5200 = y5200_mid;
		if (!(key_consol&CONSOL_START))
			key_code = AKEY_5200_START;
		else if (!(key_consol&CONSOL_SELECT))
			key_code = AKEY_5200_PAUSE;
		else if (key_code == AKEY_WARMSTART)
			key_code = AKEY_5200_RESET;
		
		if (key_5200power!=-1)//not digital)
		{
			// work out angle
			// yeah I know I have no fpu, but I'm too lazy for int maths here (and its only once per frame so it doesn't matter anyway)
			// only called once per frame
			double angle = 0;
			double length;
			if (joyswitches == 0)
			{
				angle = 0.0;
				length = 0.0;
			}
			else if ((joyswitches&(joyswitches-1)) == 0)
			{
				// single bit
				for (i=1; i!=joyswitches; i<<=1)angle-=M_PI_4;
				length = 1.0;
			}
			else
			{
				unsigned char j;
				angle = -(M_PI/8.0);

				// two bits
				j=0;
				for (j=3; j!=joyswitches; j&128 ? (j=(j<<1)|1) : (j<<=1))angle-=M_PI_4;
				length = 1.0;
			}

			// Adjust power if modifier keys pressed
			// Note they may be toggled to hold them on
//			if (power != key_5200power)
//				fprintf(stderr, "POWER:%d\n", key_5200power);
			power =key_5200power;
			if (key_5200power!=0)
				length*=(double)key_5200power;
			else
				length*=40.0;// default...

			x5200 = (length*sin(angle) + x5200_mid ) + 0.5;
			y5200 = (-length*cos(angle) + y5200_mid) + 0.5;
		}
		else
		{
			x5200 += x*100;
			y5200 += y*100;
		}
		
                for (i = 0; i < 4; i++) {
			// x - from 2*i from min to max via center
                        POT_input[2 * i] = x5200;

			// y from 2*i from min to max via center
                        POT_input[2 * i + 1] = y5200;
                }
        }

	// Override key with chatboard for now!
	key_break = 0;
	ch = -1; //TODO (chatboard)pollKbdKey();
	if (ch >=0)
	{
//		debugText = debugTextBuffer;
//		sprintf(debugTextBuffer,"Key: %d\n", key_code);

		if (ch == 0x7f)
			key_break = 1;
		else if (ch == 0x7e)
			ctrl = 1;
		else
		{
			key_code = ch;

			if (ctrl)
			{
				ctrl = 0;
				key_code |= AKEY_CTRL;
			}
		}
	}	
	else if (key_code == AKEY_BREAK)
	{
		key_break = 1;
	}

	switch(operation)
	{
	case AKEY_FASTFORWARDON:
		setFastForward(1);
		break;
	case AKEY_FASTFORWARDOFF:
		setFastForward(0);
		break;
	case AKEY_FASTFORWARDTOGGLE:
		setFastForward(!fastForward);
		while (joyPressed());
		break;
	case AKEY_VOLUMEUP:
		{
			int l,r;
			FrameworkAudio_GetVolume(&l,&r);
			l+=1;
			r+=1;
			FrameworkAudio_SetVolume(l,r);
		}
		break;
	case AKEY_VOLUMEDOWN:
		{
			int l,r;
			FrameworkAudio_GetVolume(&l,&r);
			l-=1;
			r-=1;
			FrameworkAudio_SetVolume(l,r);
		}
		break;
	case AKEY_COLDSTART:
		menuClean();
		Coldstart();
		break;
	case AKEY_WARMSTART:
		menuClean();
		Aprint("Warmstart\n");
		Warmstart();
		Aprint("Warmstart done\n");
		break;

	case  AKEY_UI:
		if (fastForward) //Hack...
		{
			setFastForward(0);
			break;
		}
		setFastForward(0);
		Sound_Pause();
		menuWidth = 0;
		menuHeight = 0;
		ui();
		while (joyPressed()) Sleep(1);
		menuClean();
		menuWidth = 0;
		menuHeight = 0;
		Sound_Continue();
		break;
	}
}

