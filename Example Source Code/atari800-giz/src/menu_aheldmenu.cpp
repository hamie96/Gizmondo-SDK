#include "menu_aheldmenu.h"

extern "C"
{
#include "menu_keymap.h"
}

AHeldMenu::AHeldMenu(int driver, const std::deque<std::string> & tokens):
	AMenu(driver), 
	d_key(AKEY_NONE), d_oper(0), d_consol(0), d_shift(0), d_joy(0), d_5200(0),
	d_heldCount(0)
{
	if (tokens.size() == 2)
	{
		toAtariKey(tokens[0].c_str(), &d_oper, &d_key, &d_consol, &d_shift, &d_joy, &d_5200);
		d_holdTime = atoi(tokens[1].c_str());
	}
}

void AHeldMenu::frame(int keysPressed)
{
	if ((keysPressed & d_driver) == d_driver)
	{
		d_heldCount++;
		if (d_heldCount>d_holdTime)
		{
			d_keyPressed = d_key;
			d_operPressed = d_oper;
			d_consolPressed = d_consol;
			d_shiftPressed = d_shift;
			d_joyPressed = d_joy;
			d_5200Pressed = d_5200;
		}
	}
	else
	{
		d_keyPressed = AKEY_NONE;
		d_operPressed = 0;
		d_consolPressed = 0;
		d_shiftPressed = 0;
		d_joyPressed = 0;
		d_5200Pressed = 0;

		d_heldCount = 0;
	}
}

void AHeldMenu::clean()
{
	d_heldCount = 0;
}	


