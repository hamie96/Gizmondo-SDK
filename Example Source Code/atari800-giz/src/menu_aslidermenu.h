#include "menu_amenu.h"

#include <string>
#include <deque>

class ASliderMenu:
	public AMenu
{
	struct Keys
	{
		char d_keyReal;
		int d_key;
		int d_oper;
		int d_consol;
		int d_shift;
		int d_joy;
		int d_5200;

		Keys();
	};

	int d_lockCount;
	int d_repeatCount;
	int d_lastKeys;

	std::deque<Keys> d_keys;
	int d_pos;

public:
	ASliderMenu(int driver, const std::deque<std::string> & tokens);
	virtual ~ASliderMenu() {}

	virtual std::string type()
	{ return "Slider";}

	virtual void frame(int keysPressed);
	virtual void clean();
};

