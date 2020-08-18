#include "menu_atogglemenu.h"

extern "C"
{
#include "menu_keymap.h"
}

AToggleMenu::Keys::Keys():
	d_key(AKEY_NONE), d_oper(0), d_consol(0), d_shift(0), d_joy(0)
{
}

AToggleMenu::AToggleMenu(int driver, const std::deque<std::string> & tokens):
	AMenu(driver), 
	d_repeatCount(0), d_pos(0)
{
	std::deque<std::string>::const_iterator i;
	for (i=tokens.begin(); i!=tokens.end(); ++i)
	{
		Keys temp;
		toAtariKey((*i).c_str(), &temp.d_oper, &temp.d_key, &temp.d_consol, &temp.d_shift, &temp.d_joy, &temp.d_5200);
		d_keys.push_back(temp);
	}
}

void AToggleMenu::frame(int keysPressed)
{
	if ((keysPressed & d_driver) == d_driver)
	{
		if (d_repeatCount == 0)
		{
			d_keyPressed = d_keys[d_pos].d_key;
			d_operPressed = d_keys[d_pos].d_oper;
			d_consolPressed = d_keys[d_pos].d_consol;
			d_shiftPressed = d_keys[d_pos].d_shift;
			d_joyPressed = d_keys[d_pos].d_joy;
			d_5200Pressed = d_keys[d_pos].d_5200;

			d_pos ++;
			if (d_pos>=d_keys.size())
				d_pos = 0;
		}
		
		d_repeatCount = 5;
	}
	else
	{
		d_keyPressed = AKEY_NONE;
		d_operPressed = 0;
		d_consolPressed = 0;
		d_shiftPressed = 0;
		d_joyPressed = 0;
		//NOT CLEARED on purpose - d_5200Pressed = 0;
	}

	if (d_repeatCount!=0)
		d_repeatCount--;
}

void AToggleMenu::clean()
{
	d_repeatCount = 0;
}


