extern "C"
{
#include "menu_c.h"
#include "input.h"
#include <stdio.h>
#include <string.h>
#include "atari_gp32.h"
}

#include "menu_container.h"
#include "menu_amenu.h"

char currentMenu[FILENAME_MAX];

static MenuContainer ** container = 0;
static MenuContainer * uiContainer = 0;
static MenuContainer * mainContainer = 0;

void menuActivateUi()
{
	container = &uiContainer;
}

void menuActivateMain()
{
	container = &mainContainer;
}

int menuLoad(const char * filename)
{
	if (*container)
		delete (*container);
	(*container) = new MenuContainer;

	int success = (*container)->loadMenu(filename);
	if (!success)
	{
//		printf("Menu load failed, setting default\n");
		if (*container == uiContainer)
		{
			(*container)->addMenuEntry("K:L|R:A:L|R:B:X:Y:R");
			(*container)->addMenuEntry("A:UP:UP");
			(*container)->addMenuEntry("A:DOWN:DOWN");
			(*container)->addMenuEntry("A:LEFT:LEFT");
			(*container)->addMenuEntry("A:RIGHT:RIGHT");
			(*container)->addMenuEntry("D:A:RETURN");
			(*container)->addMenuEntry("D:B:BACKSPACE");
			(*container)->addMenuEntry("D:L:ESCAPE");
			(*container)->addMenuEntry("D:R:TAB");
			(*container)->addMenuEntry("D:Y:TAB");
			(*container)->addMenuEntry("D:X:SPACE");
		}
		else
		{
			(*container)->addMenuEntry("K:L|R:A:L|R:B:X:Y:R");
			(*container)->addMenuEntry("H:L|R|POWER:REBOOT:60");
			(*container)->addMenuEntry("H:R|POWER:RESET:60");
			(*container)->addMenuEntry("H:L|POWER:RESET:60");
			(*container)->addMenuEntry("U:HOME:UI");
			(*container)->addMenuEntry("D:ASTERISK:START");
			(*container)->addMenuEntry("D:TRIANGLE:SELECT");
			(*container)->addMenuEntry("D:POWER:OPTION");
			(*container)->addMenuEntry("D:L:FASTFORWARDON");
			(*container)->addMenuEntry("U:L:FASTFORWARDOFF");
			(*container)->addMenuEntry("D:A:STICK_0_FIRE");
			(*container)->addMenuEntry("D:UP:STICK_0_UP");
			(*container)->addMenuEntry("D:DOWN:STICK_0_DOWN");
			(*container)->addMenuEntry("D:LEFT:STICK_0_LEFT");
			(*container)->addMenuEntry("D:RIGHT:STICK_0_RIGHT");
			(*container)->addMenuEntry("D:VOLUME|DOWN:VOLUMEDOWN");
			(*container)->addMenuEntry("D:VOLUME|UP:VOLUMEUP");
			(*container)->addMenuEntry("M:B: :a-i:NONE:R:abc:NONE:R:a:a:D:b:b: :c:c:LD:def:NONE:R:d:d:D:e:e: :f:f:L:ghi:NONE:R:g:g:D:h:h: :i:i:LLD:j-r:NONE:R:jkl:NONE:R:j:j:D:k:k: :l:l:LD:mno:NONE:R:m:m:D:n:n: :o:o:L:pqr:NONE:R:p:p:D:q:q: :r:r:LL:s-z:NONE:R:stu:NONE:R:s:s:D:t:t: :u:u:LD:vwx:NONE:R:v:v:D:w:w: :x:x:L:yz:NONE:R:y:y:D:z:z:LL:0-9:NONE:R:0-3:NONE:R:0:0:D:1:1: :2:2: :3:3:L:4-6:NONE:R:4:4:D:5:5: :6:6:L:7-9:NONE:R:7:7:D:8:8: :9:9:LL:Shift:SHIFT: :Space:SPACE: :Tab:TAB: :Return:RETURN: :Option:OPTION: :Help:HELP: :-----:NONE: :Reset:RESET: :Reboot:REBOOT");
			(*container)->addMenuEntry("M:X: :5200 keys:NONE:R:1:5200_1: :2:5200_2: :3:5200_3: :4:5200_4: :5:5200_5: :6:5200_6: :7:5200_7: :8:5200_8: :9:5200_9: :#:5200_#: :*:5200_*:L:5200 joy:NONE:RD:Slow:5200POWER_2: :Default:5200POWER_O: :Medium:5200POWER_30: :Fast:5200POWER_60: :Turbo:5200POWER_100:L:-----:NONE: :Reset:RESET: :Reboot:REBOOT");
			(*container)->addMenuEntry("D:Y:5200POWER_100");
		}
	}
	//menuDump();
//	printf("Filename:%s\n", filename);
	if (container == &mainContainer)
		strcpy(currentMenu, filename);

	return success;
}	

void menuFrame(int x, int y, int buttons)
{
	if (!(*container))
		return;

	// convert buttons to gp32 stylee
	switch (x)
	{
	case -1:
		x=1;
		break;
	case 1:
		x=2;
		break;
	}
	switch (y)
	{
	case -1:
		y=1;
		break;
	case 1:
		y=2;
		break;
	}
	int keysPressed = buttons | (y<<8) | (x<<10);

	menuWidth = 0;
	menuHeight = 0;

	MenuContainer::const_iterator i;
	for (i=(*container)->begin(); i!=(*container)->end(); ++i)
	{
		AMenu * amenu = *i;
		if (amenu==(*container)->d_blocking || !(*container)->d_blocking || !amenu->mayBeBlocked())
		{
			amenu->frame(keysPressed);
			if (amenu->blockOthers())
				(*container)->d_blocking = amenu;
		}
		else
			amenu->clean();
	}

	if ((*container)->d_blocking && !(*container)->d_blocking->blockOthers())
		(*container)->d_blocking = 0;
}

void menuClean()
{
	if (!(*container))
		return;

	MenuContainer::const_iterator i;
	for (i=(*container)->begin(); i!=(*container)->end(); ++i)
	{
		AMenu * amenu = *i;
		amenu->clean();
	}

	(*container)->d_blocking = 0;
}

int menuOper()
{
	if (!(*container))
		return 0;

	int oper = 0;
	if ((*container)->d_blocking)
		oper = (*container)->d_blocking->oper();

	MenuContainer::const_iterator i;
	for (i=(*container)->begin(); i!=(*container)->end(); ++i)
	{
		AMenu * amenu = *i;
		if ((*container)->d_blocking)
		{
			if ((*container)->d_blocking!=amenu && !amenu->mayBeBlocked())
			{
				int tempOper = amenu->oper();
				if (tempOper!=0)
					oper = tempOper;
			}
		}
		else
		{
			int tempOper = amenu->oper();
			if (tempOper!=0)
				oper = tempOper;
		}
	}

	return oper;
}

int menuKey()
{
	if (!(*container))
		return AKEY_NONE;

	int key = AKEY_NONE;
	if ((*container)->d_blocking)
		key = (*container)->d_blocking->key();

	MenuContainer::const_iterator i;
	for (i=(*container)->begin(); i!=(*container)->end(); ++i)
	{
		AMenu * amenu = *i;
		if ((*container)->d_blocking)
		{
			if ((*container)->d_blocking!=amenu && !amenu->mayBeBlocked())
			{
				int tempKey = amenu->key();
				if (tempKey!=AKEY_NONE)
					key = tempKey;
			}
		}
		else
		{
			int tempKey = amenu->key();
			if (tempKey!=AKEY_NONE)
				key = tempKey;
		}
	}

	return key;
}

int menuConsol()
{
	if (!(*container))
		return CONSOL_NONE;

	int consol = CONSOL_NONE;
	if ((*container)->d_blocking)
		consol &= ~(*container)->d_blocking->consol();

	MenuContainer::const_iterator i;
	for (i=(*container)->begin(); i!=(*container)->end(); ++i)
	{
		AMenu * amenu = *i;
		if ((*container)->d_blocking)
		{
			if ((*container)->d_blocking!=amenu && !amenu->mayBeBlocked())
			{
				int tempConsol = amenu->consol();
				if (tempConsol!=CONSOL_NONE)
					consol &= ~tempConsol;
			}
		}
		else
		{
			int tempConsol = amenu->consol();
			if (tempConsol!=CONSOL_NONE)
				consol &= ~tempConsol;
		}
	}

	return consol;
}

int menuShift()
{
	if (!(*container))
		return 0;

	bool shift = false;

	MenuContainer::const_iterator i;
	for (i=(*container)->begin(); i!=(*container)->end(); ++i)
	{
		AMenu * amenu = *i;
		shift |= amenu->shift()!=0;
	}

	return shift;
}

int menu5200Power()
{
	int none = 0;
	if (!(*container))
		return none;

	int power = none;
	if ((*container)->d_blocking)
		power = (*container)->d_blocking->power5200();

	MenuContainer::const_iterator i;
	for (i=(*container)->begin(); i!=(*container)->end(); ++i)
	{
		AMenu * amenu = *i;
		if ((*container)->d_blocking)
		{
			if ((*container)->d_blocking!=amenu && !amenu->mayBeBlocked())
			{
				int tempKey = amenu->power5200();
				if (tempKey!=none)
					power = tempKey;
			}
		}
		else
		{
			int tempKey = amenu->power5200();
			if (tempKey!=none)
				power = tempKey;
		}
	}

	return power;
}

void menuJoy(int stick[], int fire[])
{
	int count = 4;
	int j = 0;

	// Init to defaults
	for (j=0; j<count; ++j)
	{
		stick[j] = 0xff;
		fire[j] = 1;
	}	

	// Ignore if no container!
	if (!(*container) || (*container)->d_blocking)
		return;

	// Loop through combining key values
	MenuContainer::const_iterator i;
	for (i=(*container)->begin(); i!=(*container)->end(); ++i)
	{
		AMenu * amenu = *i;
		int joy = amenu->joy();

		if (joy&1)
			fire[0] = 0;
		if (joy&(1<<5))
			fire[1] = 0;

		stick[0]&=~(0xf&(joy>>1));
		stick[1]&=~(0xf&(joy>>6));
	}

	return;
}

void menuDump()
{
	if (!(*container))
		return;

	MenuContainer::const_iterator i;
	for (i=(*container)->begin(); i!=(*container)->end(); ++i)
	{
		AMenu * amenu = *i;
		printf("Type: %s Driver: %x\n", amenu->type().c_str(), amenu->driver());
	}
}

