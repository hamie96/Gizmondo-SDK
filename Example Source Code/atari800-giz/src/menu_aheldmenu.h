#include "menu_amenu.h"

#include <string>
#include <deque>

class AHeldMenu:
	public AMenu
{
	int d_key;
	int d_oper;
	int d_consol;
	int d_shift;
	int d_joy;
	int d_5200;

	int d_heldCount;
	int d_holdTime;

public:
	AHeldMenu(int driver, const std::deque<std::string> & tokens);

	virtual std::string type()
	{ return "Held";}

	virtual void frame(int keysPressed);
	virtual void clean();
	virtual bool mayBeBlocked() const {return false;}
};

