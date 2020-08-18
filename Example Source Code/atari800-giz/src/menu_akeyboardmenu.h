#include "menu_amenu.h"

#include <string>
#include <vector>
#include <deque>

class AKeyboardMenu:
	public AMenu
{
	int d_moveRepeatCount; //Repeat count for moving
	int d_lastKeys;
	int d_disableCount; // Delay after we are disabled
	int d_activeCount; // Delay after active before we can press a key

	struct Key
	{
		int d_code;
		std::string d_display;
		std::string d_displayShift;
		int d_width;
		Key(int code, const std::string & display, const std::string & displayShift, int width=1):
			d_code(code), d_display(display), d_displayShift(displayShift), d_width(width)
			{}
		bool operator==(const struct Key & rhs) const
		{
			return (this == &rhs);
		}
	};

	std::vector<std::vector<Key> > d_rows;

	int d_x;
	int d_y;

	bool d_shift;
	bool d_shiftLock;
	bool d_shiftUsed;
	bool d_control;

	int d_lastCode;
	bool d_lastShift;

	// Quick ways of doing common things
	int d_keyQuickExit;
	int d_keyPress;
	int d_keyDelete;
	int d_keyEnter;
	int d_keyCursor;
	int d_keyShift;

public:
	AKeyboardMenu(int driver, const std::deque<std::string> & tokens);
	virtual ~AKeyboardMenu();

	virtual std::string type()
	{ return "Keyboard";}

	virtual void frame(int keysPressed);
	virtual void clean();

private:
	const Key & getKey();

	void helpK(std::vector<Key> & row, int code, const std::string & display, const std::string & displayShift);
	void helpKW(std::vector<Key> & row, int code, const std::string & display, const std::string & displayShift, int width);
};

