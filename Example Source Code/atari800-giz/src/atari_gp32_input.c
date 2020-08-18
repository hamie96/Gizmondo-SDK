#include "config.h"
#include "atari.h"
#include "input.h"

#include "atari_gp32.h"
#include "menu_c.h"
#include "platform.h"

#include "gp2xjoy.h"

int joyValue[4] = {0xff,0xff,0xff,0xff};
int fireValue[4] = {1,1,1,1};

///////////////////////////////////////////////////////////////////////
// Interface -> called externally
void Keyboard_Initialise()
{
	// Init keyboard
}

///////////
int UI_Init()
{
	menuActivateUi();
	menuClean();
	menuActivateMain();
	return 0;
}

int UI_Keyboard()
{
	int switches,x,y,keys;
	int code;
	int ch;

	menuActivateUi();
	menuHeight = 0;
	readAllJoy(&switches,&x,&y,&keys);
	menuFrame(x,y,keys);
	code = menuKey();
	ch = -1; // TODO(chatboard) pollKbdKey();
	if (ch>=0)
		code = ch;

	menuActivateMain();

	Atari_DisplayScreen();

	return code;
	//return AKEY_NONE;
}

int Atari_Keyboard()
{
	// Never called (menu handles keyboard...)
	return 0;
}

int Atari_PORT(int num)
{
	// Read joystick
/*	int keydata = GpKeyGet();
	
	if (keydata & GPC_VK_UP)
	{
		joyValue &= ~1;
	}
	if (keydata & GPC_VK_DOWN)
	{
		joyValue &= ~2;
	}
	if (keydata & GPC_VK_LEFT)
	{
		joyValue &= ~4;
	}
	if (keydata & GPC_VK_RIGHT)
	{
		joyValue &= ~8;
	}*/
	return joyValue[num];
}

int Atari_TRIG(int num)
{
	// Read fire button
/*	int keydata = GpKeyGet();

	if (keydata & GPC_VK_FA)
	{
		fireValue = 0;
	}*/

	return fireValue[num];
}

int Atari_POT(int num)
{
	return 228;
}

int Atari_CONSOL(void)
{
	// Never called
	return CONSOL_NONE;
}

int Atari_PEN(int vertical)
{
	return vertical ? 0xff : 0;
}

