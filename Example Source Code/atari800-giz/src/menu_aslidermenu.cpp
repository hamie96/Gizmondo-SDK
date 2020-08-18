#include "menu_aslidermenu.h"

extern "C"
{
#include "menu_keymap.h"
#include "atari_gp32.h"
}

ASliderMenu::Keys::Keys():
	d_keyReal('x'),d_key(AKEY_NONE), d_oper(0), d_consol(0), d_shift(0), d_joy(0)
{
}

ASliderMenu::ASliderMenu(int driver, const std::deque<std::string> & tokens):
	AMenu(driver), 
	d_lockCount(0), d_repeatCount(0), d_lastKeys(0), d_pos(0)
{
	std::deque<std::string>::const_iterator i;
	for (i=tokens.begin(); i!=tokens.end(); ++i)
	{
		Keys temp;
		std::string keyRealStr = (*i);
		if (keyRealStr.length())
			temp.d_keyReal = keyRealStr.at(0);
		toAtariKey(keyRealStr.c_str(), &temp.d_oper, &temp.d_key, &temp.d_consol, &temp.d_shift, &temp.d_joy, &temp.d_5200);
		d_keys.push_back(temp);
	}
}

void ASliderMenu::frame(int keysPressed)
{
	bool displayChanged = false;
	int width = 0;
	
	int joy = GPC_VK_UP|GPC_VK_DOWN|GPC_VK_LEFT|GPC_VK_RIGHT;
	int noJoyKeysPressed = keysPressed & (~joy);

	if ((noJoyKeysPressed & d_driver) == d_driver)
	{
		if (d_lastKeys!=keysPressed)
			d_repeatCount = 0;

		if (d_repeatCount==0)
		{
			d_keyPressed = d_keys[d_pos].d_key;
			d_operPressed = d_keys[d_pos].d_oper;
			d_consolPressed = d_keys[d_pos].d_consol;
			d_shiftPressed = d_keys[d_pos].d_shift;
			d_joyPressed = d_keys[d_pos].d_joy;
			d_5200Pressed = d_keys[d_pos].d_5200;

			int oldPos = d_pos;
			if (keysPressed&GPC_VK_UP) //Up
			{
				d_pos ++;
				if (d_pos>=d_keys.size())
					d_pos=d_keys.size()-1;
			}	
			else if (keysPressed&GPC_VK_DOWN)
			{
				d_pos --;
				if (d_pos<0)
					d_pos=0;
			}

			d_repeatCount = (d_lastKeys==keysPressed) ? 5 : 9;
			d_lastKeys = keysPressed;
			if ((oldPos != d_pos) || (d_blockOthers == false))
				displayChanged = true;
		}
		
		d_blockOthers = true;
		d_lockCount = 5;
	}
	else
	{
		d_keyPressed = AKEY_NONE;
		d_operPressed = 0;
		d_consolPressed = 0;
		d_shiftPressed = 0;
		d_joyPressed = 0;
		// NOT CLEARED on purpose - d_5200Pressed = 0;
		d_lastKeys = 0;
	}

	if (d_repeatCount!=0)
		d_repeatCount--;

	if (d_lockCount!=0)
	{
		d_lockCount--;
		if (d_lockCount == 0)
			d_blockOthers = false;

		width = 12;
	}
		

	if (width && shouldDraw(displayChanged))
	{
		// Draw!
		GPDRAWSURFACE * surface = Atari_DisplayActiveBuffer();
		//GpLineDraw(surface, 0, 0, 0, 239, 0xff);
		//GpLineDraw(surface, 11, 0, 11, 239, 0xff);
		GpRectFill(NULL, surface, 0,0,1,240,0xff);
		GpRectFill(NULL, surface, 11,0,1,240,0xff);
		
		int positions = d_keys.size();
		float sectionSize = 240.0/(float)positions;
		float colSize = 12.0/(float)positions;
		float section = 0.0;
		float col = 4.0;
		while (positions--)
		{
			float sectionNext = section+sectionSize;
			int color = (int) col;
			int textCol = 0;
			if (positions == d_pos)
			{
				color = 0x0;	
				textCol = 0x9a;
			}
			GpRectFill(NULL, surface, 2,(int)section,8,sectionSize, color);
			char msg[2];
			msg[0] = d_keys[positions].d_keyReal;
			msg[1] = 0;
			GpTextOut(0, surface, 1, (int)section, msg, textCol);
			col+=colSize;
			section=sectionNext;
		}
	}

	menuWidth = width;
}

void ASliderMenu::clean()
{
	d_blockOthers = false;
	d_lockCount = 0;
	d_repeatCount = 0;
	d_lastKeys = 0;
}


