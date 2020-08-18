#include "menu_amenumenu.h"

extern "C"
{
#include "menu_keymap.h"
#include "atari_gp32.h"
}

AMenuMenu::Menu::Menu():
	d_left(0), d_right(0), d_up(0), d_down(0),
	d_name("Blobby"),d_key(AKEY_NONE), d_oper(0), d_consol(0), d_shift(0), d_joy(0), d_5200(0)
{
}

AMenuMenu::AMenuMenu(int driver, const std::deque<std::string> & tokens):
	AMenu(driver), 
	d_lockCount(0), d_repeatCount(0), d_lastKeys(0), d_menu(0), d_firstMenu(0)
{
	if ((tokens.size()%3) != 0)
		return;

	std::deque<Menu *> stack;
	std::deque<std::string>::const_iterator i;
	Menu * lastMenu = 0;
	for (i=tokens.begin(); i!=tokens.end();)
	{
		std::string text, letter, code;
		code = *i++;
		text = *i++;
		letter = *i++;

		Menu * menu = new Menu;
		d_menus.push_back(menu);
		if (!d_firstMenu) d_firstMenu = menu;

		int dummy;
		//fprintf(stderr,"LETTER:%s:\n", letter.c_str());
		if (letter=="NONE")
		{
			menu->d_none=true;
		}
		else
		{
			toAtariKey(letter.c_str(), &menu->d_oper, &menu->d_key, &menu->d_consol, &menu->d_shift, &dummy,&menu->d_5200);
			menu->d_none=false;
		}
		menu->d_name = text;

		if (code.find("R") != std::string::npos) // First entry in submenu (GOSUB)
		{
			stack.push_back(lastMenu);
			if (lastMenu)
				lastMenu->d_right = menu;
		}

		else if (code.find("L") != std::string::npos) // Next entry in parent (RETURN!)
		{
			int numLeft = 0;
			for (std::string::const_iterator i=code.begin(), end=code.end(); i!=end; ++i)
				if (*i=='L')
					numLeft++;
			Menu * previous = lastMenu;
			while (numLeft--)
			{
				if (stack.empty())
					break;

				stack.pop_back();

				if (previous)
					previous = previous->d_left;
			}

			if (previous)
			{
				menu->d_up = previous;
				previous->d_down = menu;
			}	
		}
		else
		{
			if (lastMenu)
			{
				menu->d_up = lastMenu;
				lastMenu->d_down = menu;
			}
		}

		Menu * parent = (!stack.empty()) ? stack.back() : 0;
		menu->d_left = parent;

		if (code.find("D") != std::string::npos) // Default
		{
			if (!menu->d_left) // top level
				d_firstMenu = menu;
			else
				menu->d_left->d_right = menu;
		}

		lastMenu = menu;
	}
}

AMenuMenu::~AMenuMenu()
{
	std::deque<Menu *>::const_iterator i;
	for (i=d_menus.begin(); i!=d_menus.end(); ++i)
		delete *i;
}

void AMenuMenu::frame(int keysPressed)
{
	bool displayChanged = false;
	int width = 0;

	int joy = GPC_VK_UP|GPC_VK_DOWN|GPC_VK_LEFT|GPC_VK_RIGHT;
	int noJoyKeysPressed = keysPressed & (~joy);

	if ((noJoyKeysPressed & d_driver) == d_driver)
	{
		if (!d_menu)
			d_menu = d_firstMenu;

		if ((d_repeatCount==0) && d_menu)
		{
			Menu * oldMenu = d_menu;
			if (keysPressed&GPC_VK_UP) //Up
			{
				if (d_menu->d_up)
					d_menu = d_menu->d_up;
			}	
			else if (keysPressed&GPC_VK_DOWN)
			{
				if (d_menu->d_down)
					d_menu = d_menu->d_down;
			}
			else if (keysPressed&GPC_VK_LEFT)
			{
				if (d_menu->d_left)
					d_menu = d_menu->d_left;
			}
			else if (keysPressed&GPC_VK_RIGHT)
			{
				if (d_menu->d_right)
					d_menu = d_menu->d_right;
			}

			d_repeatCount = (d_lastKeys==keysPressed) ? 5 : 10;
			d_lastKeys = keysPressed;
			if ((oldMenu != d_menu) || (d_blockOthers == false))
				displayChanged = true;
		}
		
		d_blockOthers = true;
		d_lockCount = 5;
	}
	else
	{
		if (d_menu) // Was active -> press key
		{
			if (!d_menu->d_none)
			{
				d_keyPressed = d_menu->d_key;
				d_operPressed = d_menu->d_oper;
				d_consolPressed = d_menu->d_consol;
				d_shiftPressed = d_menu->d_shift;
				d_joyPressed = d_menu->d_joy;
				d_5200Pressed = d_menu->d_5200;
			}

			d_menu = 0;
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
	}

	if (d_repeatCount!=0)
		d_repeatCount--;

	if (d_lockCount!=0)
	{
		d_lockCount--;
		if (d_lockCount == 0)
			d_blockOthers = false;

		width = 80;
	}
		
	if (width && shouldDraw(displayChanged))
	{
		// Draw!
		GPDRAWSURFACE * surface = Atari_DisplayActiveBuffer();
		//GpLineDraw(surface, 0, 0, 0, 239, 0xff);
		//GpLineDraw(surface, 11, 0, 11, 239, 0xff);
		GpRectFill(NULL, surface, 0,0,1,240,0xff);
		GpRectFill(NULL, surface, 1,0, 39,240, 0x94);
		GpRectFill(NULL, surface, 40,0, 39,240, 0x94);
		GpRectFill(NULL, surface, 79,0,1,240,0xff);

		Menu * first = d_menu;
	
		if (!first)
			return;
		while (first->d_up) first = first->d_up;

		int pos = 5;
		for (Menu * iter=first; iter!=0; iter=iter->d_down)
		{
			if (iter == d_menu)
			{
				GpRectFill(NULL, surface, 1,pos,78,15,0x00);
			}
			std::string name = iter->d_name;
			if (iter->d_left)
				name = "<" + name;
			if (iter->d_right)
				name = name + ">";
			GpTextOut(0, surface, 1, pos, (char *)name.c_str() , (iter==d_menu) ? 0xff : 0x9a);			
			pos+=15;
		}

/*		int positions = d_keys.size();
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
			GpRectFill(NULL, surface, 2,(int)section,8,((int)sectionNext)-1, color);
			char * msg = "X";
			msg[0] = d_keys[positions].d_keyReal;
			GpTextOut(0, surface, 1, (int)section, msg, textCol);
			col+=colSize;
			section=sectionNext;
		}*/
	}

	menuWidth = width;
}

void AMenuMenu::clean()
{
	d_blockOthers = false;
	d_lockCount = 0;
	d_repeatCount = 0;

	d_menu = 0;
	d_lastKeys = 0;
}


