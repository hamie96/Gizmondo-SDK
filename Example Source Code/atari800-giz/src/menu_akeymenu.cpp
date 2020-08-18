#include "menu_akeymenu.h"

extern "C"
{
#include "menu_keymap.h"
}

AKeyMenu::AKeyMenu(int driver, const std::deque<std::string> & tokens, bool unique, bool immediate):
	AMenu(driver), 
	d_key(AKEY_NONE), d_oper(0), d_consol(0), d_shift(0), d_joy(0), d_5200(0),
	d_unique(unique), d_immediate(immediate), d_pressedLast(false)
{
	if (tokens.size() == 1)
		toAtariKey(tokens[0].c_str(), &d_oper, &d_key, &d_consol, &d_shift, &d_joy, &d_5200);
}

void AKeyMenu::frame(int keysPressed)
{
	bool pressed = false;
	if (d_unique)
		pressed = (keysPressed == d_driver);
	else
		pressed = ((keysPressed & d_driver) == d_driver);
	
	if (pressed)
	{
		d_pressedLast = true;

		if (d_immediate) // now or on release?
			press();
	}
	else
	{
		if (d_pressedLast && !d_immediate)
			press();
		else
			unpress();
	
		d_pressedLast = false;
	}
}

void AKeyMenu::clean()
{
	unpress();
	d_pressedLast = false;
}

void AKeyMenu::press()
{
	d_keyPressed = d_key;
	d_operPressed = d_oper;
	d_consolPressed = d_consol;
	d_shiftPressed = d_shift;
	d_joyPressed = d_joy;
	d_5200Pressed = d_5200;
}

void AKeyMenu::unpress()
{
	d_keyPressed = AKEY_NONE;
	d_operPressed = 0;
	d_consolPressed = 0;
	d_shiftPressed = 0;
	d_joyPressed = 0;
	d_5200Pressed = 0;
}


