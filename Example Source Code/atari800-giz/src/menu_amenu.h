#ifndef AMENU_H
#define AMENU_H

extern "C"
{
	#include "input.h"
}

#include <string>

class AMenu
{
protected:
	int d_driver;

	int d_keyPressed;
	int d_operPressed;
	int d_consolPressed;
	int d_shiftPressed;
	int d_5200Pressed;
	int d_joyPressed;

	bool d_blockOthers;

private:
	int d_doubleBufferA, d_doubleBufferB;

public:
	AMenu(int driver):
		d_driver(driver),
		d_keyPressed(AKEY_NONE), d_operPressed(0), d_consolPressed(0), d_shiftPressed(0), d_5200Pressed(0), d_joyPressed(0), d_blockOthers(false),
		d_doubleBufferA(0), d_doubleBufferB(0)
		{}
	virtual ~AMenu() {};

	virtual std::string type()=0;

	virtual int driver()
		{ return d_driver; }
	virtual void frame(int keysPressed)=0;
	virtual void clean()=0; // clears state...
	virtual bool mayBeBlocked() const {return true;}

	virtual int oper() const
		{ return d_operPressed; }
	virtual int key() const 
		{ return d_keyPressed; }
	virtual int consol() const
		{ return d_consolPressed; }
	virtual int shift() const
		{ return d_shiftPressed; }
	virtual int power5200() const
		{ return d_5200Pressed; }
	virtual int joy() const
		{ return d_joyPressed; }
	virtual bool blockOthers() const
		{ return d_blockOthers; }

protected:
	bool shouldDraw(bool displayChanged);
};

#endif
