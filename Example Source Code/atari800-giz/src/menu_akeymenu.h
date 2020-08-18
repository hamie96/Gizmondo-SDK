#include "menu_amenu.h"

#include <string>
#include <deque>

class AKeyMenu:
	public AMenu
{
	int d_key;
	int d_oper;
	int d_consol;
	int d_shift;
	int d_joy;
	int d_5200;

	bool d_unique;
	bool d_immediate;
	bool d_pressedLast;

public:
	AKeyMenu(int driver, const std::deque<std::string> & tokens, bool unique=false, bool immediate=true);

	virtual std::string type()
	{ return "Key";}

	virtual void frame(int keysPressed);
	virtual void clean();

private:
	void press();
	void unpress();
};

