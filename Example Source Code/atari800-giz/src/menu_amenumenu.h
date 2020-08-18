#include "menu_amenu.h"

#include <string>
#include <deque>

class AMenuMenu:
	public AMenu
{
	struct Menu
	{
		struct Menu * d_left;
		struct Menu * d_right;
		struct Menu * d_up;
		struct Menu * d_down;

		std::string d_name;

		int d_key;
		int d_oper;
		int d_consol;
		int d_shift;
		int d_joy;
		int d_5200;

		bool d_none;

		Menu();
	};

	int d_lockCount;
	int d_repeatCount;
	int d_lastKeys;

	std::deque<Menu *> d_menus;
	Menu * d_menu;
	Menu * d_firstMenu;

public:
	AMenuMenu(int driver, const std::deque<std::string> & tokens);
	virtual ~AMenuMenu();

	virtual std::string type()
	{ return "Menu";}

	virtual void frame(int keysPressed);
	virtual void clean();
};

