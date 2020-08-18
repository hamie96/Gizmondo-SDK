#include "menu_akeyboardmenu.h"

extern "C"
{
#include "atari.h"
#include "menu_keymap.h"
#include "atari_gp32.h"
}

#define K(x,y,z) (helpK(row, x,y,z));
#define KW(x,y,z,w) (helpKW(row, x,y,z,w));

AKeyboardMenu::AKeyboardMenu(int driver, const std::deque<std::string> & tokens):
	AMenu(driver), 
	d_moveRepeatCount(0), d_lastKeys(0), d_disableCount(0), d_activeCount(0),
	d_x(6), d_y(2),
	d_shift(false), d_shiftUsed(false), d_shiftLock(false), d_control(false),
	d_lastCode(AKEY_NONE),
	d_keyQuickExit(GPC_VK_FL|GPC_VK_FR),
	d_keyPress(GPC_VK_FA),
	d_keyDelete(GPC_VK_FB),
	d_keyEnter(GPC_VK_FX),
	d_keyCursor(GPC_VK_FY),
	d_keyShift(GPC_VK_FL)
{
	if (tokens.size() == 6)
	{
		d_keyPress = toGpKey(tokens[0].c_str());
		d_keyQuickExit = toGpKey(tokens[1].c_str());
		d_keyDelete = toGpKey(tokens[2].c_str());
		d_keyEnter = toGpKey(tokens[3].c_str());
		d_keyCursor = toGpKey(tokens[4].c_str());
		d_keyShift = toGpKey(tokens[5].c_str());
	}

	// Ignore tokens...
	// For now anyway we"re just going to do
	// <ESC>1234567890<><del><brk>
	// <tab>qwertyuiop[=<return>
	// <control>asdfghjkl;+*<caps>
	// <shift>zxcvbnm,./<shift><atari>
	// <space>

	std::vector<Key> row;

	KW(AKEY_ESCAPE, "Esc","Esc",2);
	K(AKEY_1, "1", "!");
	K(AKEY_2, "2","\"");
	K(AKEY_3, "3","#");
	K(AKEY_4, "4","$");
	K(AKEY_5, "5","%");
	K(AKEY_6, "6","&");
	K(AKEY_7, "7","'");
	K(AKEY_8, "8","@");
	K(AKEY_9, "9","(");
	K(AKEY_0, "0",")");
	K(AKEY_LESS, "<","Cl");
	K(AKEY_GREATER, ">","In");
	K(AKEY_BACKSPACE, "Bs","Dl");
	K(AKEY_BREAK, "Bk","Bk");
	d_rows.push_back(row);
	row.clear();

	KW(AKEY_TAB, "Tab","STab",2);
	K(AKEY_q, "q", "Q");
	K(AKEY_w, "w", "W");
	K(AKEY_e, "e", "E");
	K(AKEY_r, "r", "R");
	K(AKEY_t, "t", "T");
	K(AKEY_y, "y", "Y");
	K(AKEY_u, "u", "U");
	K(AKEY_i, "i", "I");
	K(AKEY_o, "o", "O");
	K(AKEY_p, "p", "P");
	K(AKEY_MINUS, "-", "_");
	K(AKEY_EQUAL,"=", "|");
	KW(AKEY_RETURN,"Ret","Ret",2);
	d_rows.push_back(row);
	row.clear();

	KW(AKEY_CTRL, "Ctl","Ctl",2);
	K(AKEY_a, "a", "A");
	K(AKEY_s, "s", "S");
	K(AKEY_d, "d", "D");
	K(AKEY_f, "f", "F");
	K(AKEY_g, "g", "G");
	K(AKEY_h, "h", "H");
	K(AKEY_j, "j", "J");
	K(AKEY_k, "k", "K");
	K(AKEY_l, "l", "L");
	K(AKEY_SEMICOLON, ";", ":");
	K(AKEY_PLUS, "+", "\\");
	K(AKEY_ASTERISK,"*", "^");
	KW(AKEY_CAPSTOGGLE,"Cap","Cap",2);
	d_rows.push_back(row);
	row.clear();

	KW(AKEY_SHFT, "Sft","Sft",2);
	K(AKEY_z, "z","Z");
	K(AKEY_x, "x","X");
	K(AKEY_c, "c","C");
	K(AKEY_v, "v","V");
	K(AKEY_b, "b","B");
	K(AKEY_n, "n","N");
	K(AKEY_m, "m", "M");
	K(AKEY_COMMA, ",","[");
	K(AKEY_FULLSTOP, ".","]");
	K(AKEY_SLASH, "/","?");
	KW(AKEY_RSHIFT, "SftL","SftL",2);
	KW(AKEY_ATARI,"Atari","Atari",2);
	d_rows.push_back(row);
	row.clear();

	KW(AKEY_EXIT, "<exit>","<EXIT>", 3);
	KW(AKEY_SPACE, "          space          ","         SPACE          ",10);
	KW(AKEY_EXIT, "<exit>","<EXIT>", 3);
	d_rows.push_back(row);
	row.clear();
}

AKeyboardMenu::~AKeyboardMenu()
{
}

void AKeyboardMenu::frame(int keysPressed)
{
	bool displayChanged = false;
	int height = 0;
	int rawKeyPressed = AKEY_NONE;
	bool noModifiers = false;

	int joy = GPC_VK_UP|GPC_VK_DOWN|GPC_VK_LEFT|GPC_VK_RIGHT;
	int noJoyKeysPressed = keysPressed & (~joy);
	
	if (d_disableCount == 0)
	{
		if (d_lastCode!=AKEY_NONE) 
		{
			d_keyPressed = AKEY_NONE;
			d_shiftPressed = 0;
		}

		if (!d_blockOthers && (noJoyKeysPressed & d_driver) == d_driver) // If driver key pressed
		{
			// Activate
			clean();
			d_blockOthers = true;
			d_activeCount = 25;
			displayChanged = true;
		}
		else if (d_blockOthers && !d_activeCount)
		{
			d_shiftPressed = (noJoyKeysPressed&d_keyShift)!=0;

			if ((noJoyKeysPressed & d_keyPress & ~d_keyShift) == d_keyPress) // Press key pressed
			{
				// Press key we are over
				rawKeyPressed = d_keyPressed = getKey().d_code; // Adjust by shift/control if required
				d_operPressed = 0;
				d_consolPressed = 0;
				d_shiftPressed |= (d_keyPressed == AKEY_SHFT);
				d_joyPressed = 0;

				if (d_lastCode != d_keyPressed)
					displayChanged = true;

				if (d_keyPressed == AKEY_EXIT)
					d_disableCount = 25;
			}
			else if ((noJoyKeysPressed & d_keyDelete) == d_keyDelete) // Quick delete
			{
				rawKeyPressed = d_keyPressed = AKEY_BACKSPACE; 
				d_operPressed = 0;
				d_consolPressed = 0;
				d_shiftPressed = 0;
				d_joyPressed = 0;

				noModifiers = true;

				if (d_lastCode != d_keyPressed)
					displayChanged = true;
			}
			else if ((noJoyKeysPressed & d_keyEnter) == d_keyEnter) // Quick enter
			{
				rawKeyPressed = d_keyPressed = AKEY_RETURN; 
				d_operPressed = 0;
				d_consolPressed = 0;
				d_shiftPressed = 0;
				d_joyPressed = 0;

				noModifiers = true;

				if (d_lastCode != d_keyPressed)
					displayChanged = true;
			}
			else if ((noJoyKeysPressed & d_keyCursor) == d_keyCursor) // Quick cursor
			{
				// Press key we are over
				if (keysPressed&GPC_VK_LEFT)
					rawKeyPressed = d_keyPressed = AKEY_LEFT; 
				else if (keysPressed&GPC_VK_RIGHT)
					rawKeyPressed = d_keyPressed = AKEY_RIGHT; 
				else if (keysPressed&GPC_VK_UP) //Up
					rawKeyPressed = d_keyPressed = AKEY_UP; 
				else if (keysPressed&GPC_VK_DOWN)
					rawKeyPressed = d_keyPressed = AKEY_DOWN; 
				d_operPressed = 0;
				d_consolPressed = 0;
				d_shiftPressed = 0;
				d_joyPressed = 0;

				noModifiers = true;

				if (d_lastCode != d_keyPressed)
					displayChanged = true;
			}
			else if ((noJoyKeysPressed & d_keyQuickExit) == d_keyQuickExit) // Quick exit key pressed
			{
				d_disableCount = 25;
			}
			else
			{
				if (d_lastKeys!=keysPressed)
					d_moveRepeatCount = 0;

				if (d_moveRepeatCount==0)
				{
					int oldX = d_x;
					int oldY = d_y;
			
					if (keysPressed&GPC_VK_UP) //Up
					{
						d_y--;
						if (d_y<0)
							d_y = d_rows.size()-1;
					}	
					else if (keysPressed&GPC_VK_DOWN)
					{
						d_y++;
						if (d_y>=d_rows.size())
							d_y = 0;
					}
					else if (keysPressed&GPC_VK_LEFT)
					{
						const Key & key = getKey();
						do
						{
							if (d_x==0)	
								d_x = 16;

							d_x--;
						} while (key == getKey());
						d_x-=getKey().d_width;
						d_x++;
						d_x+=getKey().d_width/2;
					}
					else if (keysPressed&GPC_VK_RIGHT)
					{
						const Key & key = getKey();
						do
						{
							d_x++;
							if (d_x>=16)
								d_x = 0;
						} while (key == getKey());
						d_x+=getKey().d_width/2;
					}

					d_moveRepeatCount = (d_lastKeys==keysPressed) ? 4 : 9;
					d_lastKeys = keysPressed;

					if ((d_x!=oldX) || (d_y!=oldY) || (d_lastCode!=AKEY_NONE))
						displayChanged = true;
				}

				if (joy == 0)
					d_moveRepeatCount = 0;
			}
		}
	}

	if (d_disableCount!=0)
	{
		d_disableCount--;
		if (d_disableCount == 0)
			d_blockOthers = false;
	}

	if (d_moveRepeatCount!=0)
		d_moveRepeatCount--;

	if (d_activeCount!=0)
		d_activeCount--;

	if (d_blockOthers && d_disableCount==0)
		height = d_rows.size()*12;
	
	if (d_keyPressed == AKEY_EXIT)
	{
		d_keyPressed = AKEY_NONE;
	}
	else if (d_keyPressed == AKEY_NONE)
	{
		if (d_shiftUsed == true)
		{
			d_shift = false;
			d_shiftUsed = false;
		}

		switch (d_lastCode)
		{
		case AKEY_SHFT:
			d_shift^=1;
			break;

		case AKEY_RSHIFT:
			d_shiftLock^=1;
			break;

		case AKEY_CTRL:
			d_control^=1;
			break;
		}
	}

	d_lastCode = d_keyPressed;

	if (d_keyPressed==AKEY_SHFT || d_keyPressed==AKEY_CTRL || d_keyPressed==AKEY_RSHIFT)
	{
		d_keyPressed = AKEY_NONE;
	}

	if (d_keyPressed!=AKEY_NONE && !noModifiers)
	{
		if (d_control)
			d_keyPressed^=AKEY_CTRL;

		if (d_shift || d_shiftPressed)
		{
			d_keyPressed^=AKEY_SHFT;
			d_shiftUsed = true;
		}

		if (d_shiftLock)
		{
			d_keyPressed^=AKEY_SHFT;
		}
	}

	if (d_shift || d_shiftLock)
		d_shiftPressed = true;

	if (d_lastShift!=d_shiftPressed)
		displayChanged = true;

	d_lastShift = d_shiftPressed;

	if (height && shouldDraw(displayChanged)) 
	{
		// Draw!
		GPDRAWSURFACE * surface = Atari_DisplayActiveBuffer();
		int ystart = 240-height-1;
		GpRectFill(NULL, surface, 0,ystart+1,320,1,0xff);
		GpRectFill(NULL, surface, 160, ystart+2, 320, 240-(ystart+2), 0x94);
		GpRectFill(NULL, surface, 0,ystart+2, 160, 240-(ystart+2), 0x94);

		for (int y=0; y<d_rows.size(); ++y)
		{
			int vecX = 0;
			for(int x=0; x<16; vecX++)
			{
				const Key & key = d_rows[y][vecX];
				bool highlight = false;
				int highlightCol = 0x00;

				switch (key.d_code)
				{
				case AKEY_SHFT:
					if (d_shift)
					{
						highlightCol = 0x46; 
						highlight = true;
					}
					break;
				case AKEY_RSHIFT:
					if (d_shiftLock)
					{
						highlightCol = 0x46;
						highlight = true;
					}
					break;
				case AKEY_CTRL:
					if (d_control)
					{
						highlightCol = 0x46; 
						highlight = true;
					}
					break;
				}

				if (key.d_code == rawKeyPressed)
				{
					highlight = true;
					highlightCol = 0x00;
				}

				if (highlight)
					GpRectFill(NULL, surface, x*20, ystart+y*12, 20*key.d_width-2, 12, highlightCol);

				GpTextOut(0, surface, x*20, ystart+y*12, const_cast<char *>(d_shiftPressed ? key.d_displayShift.c_str() : key.d_display.c_str()), (d_x>=x && d_x<(x+key.d_width) && y==d_y) ? 0x00 : 0x9a);
				x+=key.d_width;
			}
		}
	}

	menuHeight = height;
}

void AKeyboardMenu::clean()
{
	d_lastKeys = 0;

	d_x = 6;
	d_y = 2;
	d_blockOthers = false;
	d_moveRepeatCount = 0;
	d_lastCode = AKEY_NONE;

	d_shift = false;
	d_shiftUsed = false;
	d_control = false;
}

const AKeyboardMenu::Key & AKeyboardMenu::getKey()
{
	const std::vector<Key> & row = d_rows[d_y];
	int count = d_x;
	int pos = -1;
	while (count>=0)
	{
		count-=row[++pos].d_width;
	}
	return row[pos];
}

void AKeyboardMenu::helpK(std::vector<Key> & row, int code, const std::string & display, const std::string & displayShift)
{
	row.push_back(Key(code, display, displayShift));
}
void AKeyboardMenu::helpKW(std::vector<Key> & row, int code, const std::string & display, const std::string & displayShift, int width)
{
	row.push_back(Key(code, display, displayShift, width));
}




