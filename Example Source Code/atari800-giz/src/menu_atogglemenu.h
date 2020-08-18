#include "menu_amenu.h"

#include <string>
#include <deque>

class AToggleMenu:
	public AMenu
{
	struct Keys
	{
		int d_key;
		int d_oper;
		int d_consol;
		int d_shift;
		int d_joy;
		int d_5200;

		Keys();
	};

	int d_repeatCount;

	std::deque<Keys> d_keys;
	int d_pos;

public:
	AToggleMenu(int driver, const std::deque<std::string> & tokens);
	virtual ~AToggleMenu() {}

	virtual std::string type()
	{ return "Toggle";}

	virtual void frame(int keysPressed);
	virtual void clean();
};

