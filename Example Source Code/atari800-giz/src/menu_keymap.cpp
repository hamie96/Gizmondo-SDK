// Map from keys as specified in a file to atari keycodes
#include "menu_utils.h"

extern "C"
{
#include "input.h"
#include "atari.h"
#include "atari_gp32.h"
#include "menu_keymap.h"
}

#include <map>
#include <string>
#include <deque>

typedef std::map<std::string, int> STRTOATARI;
static STRTOATARI * strToAtariKey;
static STRTOATARI * strToAtariOper;
static STRTOATARI * strToAtariConsol;
static STRTOATARI * strToAtariShift;
static STRTOATARI * strToAtariJoy;
static STRTOATARI * strToAtari5200Power;

void setKey(STRTOATARI * map, const char * key, int val)
{
	(*map)[key] = val;
}

void initKeymap()
{
	strToAtariKey = new STRTOATARI;
	strToAtariOper = new STRTOATARI;
	strToAtariConsol = new STRTOATARI;
	strToAtariShift = new STRTOATARI;
	strToAtariJoy = new STRTOATARI;
	strToAtari5200Power = new STRTOATARI;

	// Ordinary keys
	setKey(strToAtariKey,"0",AKEY_0);
	setKey(strToAtariKey,"1",AKEY_1);
	setKey(strToAtariKey,"2",AKEY_2);
	setKey(strToAtariKey,"3",AKEY_3);
	setKey(strToAtariKey,"4",AKEY_4);
	setKey(strToAtariKey,"5",AKEY_5);
	setKey(strToAtariKey,"6",AKEY_6);
	setKey(strToAtariKey,"7",AKEY_7);
	setKey(strToAtariKey,"8",AKEY_8);
	setKey(strToAtariKey,"9",AKEY_9);

	setKey(strToAtariKey,"a",AKEY_a);
	setKey(strToAtariKey,"b",AKEY_b);
	setKey(strToAtariKey,"c",AKEY_c);
	setKey(strToAtariKey,"d",AKEY_d);
	setKey(strToAtariKey,"e",AKEY_e);
	setKey(strToAtariKey,"f",AKEY_f);
	setKey(strToAtariKey,"g",AKEY_g);
	setKey(strToAtariKey,"h",AKEY_h);
	setKey(strToAtariKey,"i",AKEY_i);
	setKey(strToAtariKey,"j",AKEY_j);
	setKey(strToAtariKey,"k",AKEY_k);
	setKey(strToAtariKey,"l",AKEY_l);
	setKey(strToAtariKey,"m",AKEY_m);
	setKey(strToAtariKey,"n",AKEY_n);
	setKey(strToAtariKey,"o",AKEY_o);
	setKey(strToAtariKey,"p",AKEY_p);
	setKey(strToAtariKey,"q",AKEY_q);
	setKey(strToAtariKey,"r",AKEY_r);
	setKey(strToAtariKey,"s",AKEY_s);
	setKey(strToAtariKey,"t",AKEY_t);
	setKey(strToAtariKey,"u",AKEY_u);
	setKey(strToAtariKey,"v",AKEY_v);
	setKey(strToAtariKey,"w",AKEY_w);
	setKey(strToAtariKey,"x",AKEY_x);
	setKey(strToAtariKey,"y",AKEY_y);
	setKey(strToAtariKey,"z",AKEY_z);

	setKey(strToAtariKey,"A",AKEY_A);
	setKey(strToAtariKey,"B",AKEY_B);
	setKey(strToAtariKey,"C",AKEY_C);
	setKey(strToAtariKey,"D",AKEY_D);
	setKey(strToAtariKey,"E",AKEY_E);
	setKey(strToAtariKey,"F",AKEY_F);
	setKey(strToAtariKey,"G",AKEY_G);
	setKey(strToAtariKey,"H",AKEY_H);
	setKey(strToAtariKey,"I",AKEY_I);
	setKey(strToAtariKey,"J",AKEY_J);
	setKey(strToAtariKey,"K",AKEY_K);
	setKey(strToAtariKey,"L",AKEY_L);
	setKey(strToAtariKey,"M",AKEY_M);
	setKey(strToAtariKey,"N",AKEY_N);
	setKey(strToAtariKey,"O",AKEY_O);
	setKey(strToAtariKey,"P",AKEY_P);
	setKey(strToAtariKey,"Q",AKEY_Q);
	setKey(strToAtariKey,"R",AKEY_R);
	setKey(strToAtariKey,"S",AKEY_S);
	setKey(strToAtariKey,"T",AKEY_T);
	setKey(strToAtariKey,"U",AKEY_U);
	setKey(strToAtariKey,"V",AKEY_V);
	setKey(strToAtariKey,"W",AKEY_W);
	setKey(strToAtariKey,"X",AKEY_X);
	setKey(strToAtariKey,"Y",AKEY_Y);
	setKey(strToAtariKey,"Z",AKEY_Z);

	setKey(strToAtariKey,"CTRL0",AKEY_CTRL_0);
	setKey(strToAtariKey,"CTRL1",AKEY_CTRL_1);
	setKey(strToAtariKey,"CTRL2",AKEY_CTRL_2);
	setKey(strToAtariKey,"CTRL3",AKEY_CTRL_3);
	setKey(strToAtariKey,"CTRL4",AKEY_CTRL_4);
	setKey(strToAtariKey,"CTRL5",AKEY_CTRL_5);
	setKey(strToAtariKey,"CTRL6",AKEY_CTRL_6);
	setKey(strToAtariKey,"CTRL7",AKEY_CTRL_7);
	setKey(strToAtariKey,"CTRL8",AKEY_CTRL_8);
	setKey(strToAtariKey,"CTRL9",AKEY_CTRL_9);

	setKey(strToAtariKey,"CTRLa",AKEY_CTRL_a);
	setKey(strToAtariKey,"CTRLb",AKEY_CTRL_b);
	setKey(strToAtariKey,"CTRLc",AKEY_CTRL_c);
	setKey(strToAtariKey,"CTRLd",AKEY_CTRL_d);
	setKey(strToAtariKey,"CTRLe",AKEY_CTRL_e);
	setKey(strToAtariKey,"CTRLf",AKEY_CTRL_f);
	setKey(strToAtariKey,"CTRLg",AKEY_CTRL_g);
	setKey(strToAtariKey,"CTRLh",AKEY_CTRL_h);
	setKey(strToAtariKey,"CTRLi",AKEY_CTRL_i);
	setKey(strToAtariKey,"CTRLj",AKEY_CTRL_j);
	setKey(strToAtariKey,"CTRLk",AKEY_CTRL_k);
	setKey(strToAtariKey,"CTRLl",AKEY_CTRL_l);
	setKey(strToAtariKey,"CTRLm",AKEY_CTRL_m);
	setKey(strToAtariKey,"CTRLn",AKEY_CTRL_n);
	setKey(strToAtariKey,"CTRLo",AKEY_CTRL_o);
	setKey(strToAtariKey,"CTRLp",AKEY_CTRL_p);
	setKey(strToAtariKey,"CTRLq",AKEY_CTRL_q);
	setKey(strToAtariKey,"CTRLr",AKEY_CTRL_r);
	setKey(strToAtariKey,"CTRLs",AKEY_CTRL_s);
	setKey(strToAtariKey,"CTRLt",AKEY_CTRL_t);
	setKey(strToAtariKey,"CTRLu",AKEY_CTRL_u);
	setKey(strToAtariKey,"CTRLv",AKEY_CTRL_v);
	setKey(strToAtariKey,"CTRLw",AKEY_CTRL_w);
	setKey(strToAtariKey,"CTRLx",AKEY_CTRL_x);
	setKey(strToAtariKey,"CTRLy",AKEY_CTRL_y);
	setKey(strToAtariKey,"CTRLz",AKEY_CTRL_z);

	setKey(strToAtariKey,"CTRLA",AKEY_CTRL_A);
	setKey(strToAtariKey,"CTRLB",AKEY_CTRL_B);
	setKey(strToAtariKey,"CTRLC",AKEY_CTRL_C);
	setKey(strToAtariKey,"CTRLD",AKEY_CTRL_D);
	setKey(strToAtariKey,"CTRLE",AKEY_CTRL_E);
	setKey(strToAtariKey,"CTRLF",AKEY_CTRL_F);
	setKey(strToAtariKey,"CTRLG",AKEY_CTRL_G);
	setKey(strToAtariKey,"CTRLH",AKEY_CTRL_H);
	setKey(strToAtariKey,"CTRLI",AKEY_CTRL_I);
	setKey(strToAtariKey,"CTRLJ",AKEY_CTRL_J);
	setKey(strToAtariKey,"CTRLK",AKEY_CTRL_K);
	setKey(strToAtariKey,"CTRLL",AKEY_CTRL_L);
	setKey(strToAtariKey,"CTRLM",AKEY_CTRL_M);
	setKey(strToAtariKey,"CTRLN",AKEY_CTRL_N);
	setKey(strToAtariKey,"CTRLO",AKEY_CTRL_O);
	setKey(strToAtariKey,"CTRLP",AKEY_CTRL_P);
	setKey(strToAtariKey,"CTRLQ",AKEY_CTRL_Q);
	setKey(strToAtariKey,"CTRLR",AKEY_CTRL_R);
	setKey(strToAtariKey,"CTRLS",AKEY_CTRL_S);
	setKey(strToAtariKey,"CTRLT",AKEY_CTRL_T);
	setKey(strToAtariKey,"CTRLU",AKEY_CTRL_U);
	setKey(strToAtariKey,"CTRLV",AKEY_CTRL_V);
	setKey(strToAtariKey,"CTRLW",AKEY_CTRL_W);
	setKey(strToAtariKey,"CTRLX",AKEY_CTRL_X);
	setKey(strToAtariKey,"CTRLY",AKEY_CTRL_Y);
	setKey(strToAtariKey,"CTRLZ",AKEY_CTRL_Z);

	setKey(strToAtariKey," ",AKEY_SPACE);
	setKey(strToAtariKey,"SPACE",AKEY_SPACE);
	setKey(strToAtariKey,"ESCAPE",AKEY_ESCAPE);
	setKey(strToAtariKey,",",AKEY_COMMA);
	setKey(strToAtariKey,".",AKEY_FULLSTOP);
	setKey(strToAtariKey,"/",AKEY_SLASH);
	setKey(strToAtariKey,"\\",AKEY_BACKSLASH);
	setKey(strToAtariKey,";",AKEY_SEMICOLON);
	setKey(strToAtariKey,":",AKEY_COLON);
	setKey(strToAtariKey,"TAB",AKEY_TAB);
	setKey(strToAtariKey,"<",AKEY_LESS);
	setKey(strToAtariKey,">",AKEY_GREATER);
	setKey(strToAtariKey,"?",AKEY_QUESTION);
	setKey(strToAtariKey,"DEL",AKEY_DELETE_CHAR);
	setKey(strToAtariKey, "BACKSPACE", AKEY_BACKSPACE);
	setKey(strToAtariKey,"ATARI",AKEY_ATARI);
	setKey(strToAtariKey,"BREAK",AKEY_BREAK);
	setKey(strToAtariKey,"HELP",AKEY_HELP);
	setKey(strToAtariKey,"RETURN",AKEY_RETURN);

	setKey(strToAtariKey,"UP",AKEY_UP);
	setKey(strToAtariKey,"DOWN",AKEY_DOWN);
	setKey(strToAtariKey,"LEFT",AKEY_LEFT);
	setKey(strToAtariKey,"RIGHT",AKEY_RIGHT);
	setKey(strToAtariKey,"=",AKEY_EQUAL);
	setKey(strToAtariKey,"-",AKEY_MINUS);
	setKey(strToAtariKey,"+",AKEY_PLUS);
	setKey(strToAtariKey,"*",AKEY_ASTERISK);

	setKey(strToAtariKey,"",AKEY_NONE);
	setKey(strToAtariKey,"NONE",AKEY_NONE);

	setKey(strToAtariKey,"5200_START",AKEY_5200_START);
	setKey(strToAtariKey,"5200_PAUSE",AKEY_5200_PAUSE);
	setKey(strToAtariKey,"5200_RESET",AKEY_5200_RESET);
	setKey(strToAtariKey,"5200_0",AKEY_5200_0);
	setKey(strToAtariKey,"5200_1",AKEY_5200_1);
	setKey(strToAtariKey,"5200_2",AKEY_5200_2);
	setKey(strToAtariKey,"5200_3",AKEY_5200_3);
	setKey(strToAtariKey,"5200_4",AKEY_5200_4);
	setKey(strToAtariKey,"5200_5",AKEY_5200_5);
	setKey(strToAtariKey,"5200_6",AKEY_5200_6);
	setKey(strToAtariKey,"5200_7",AKEY_5200_7);
	setKey(strToAtariKey,"5200_8",AKEY_5200_8);
	setKey(strToAtariKey,"5200_9",AKEY_5200_9);
	setKey(strToAtariKey,"5200_HASH",AKEY_5200_HASH);
	setKey(strToAtariKey,"5200_ASTERISK",AKEY_5200_ASTERISK);
	// fire2?! must read up but it says its same as shift + break
	// which we can map here
	// note also that CONSOL_START now maps to 5200_START
	// CONSOL_SELECT to 5200_PAUSE
	// and WARMSTART to 5200_RESET
	// +joystick is 16 way on gp2x, will be 8 way on gp32

	// operations
	setKey(strToAtariOper,"RESET",AKEY_WARMSTART);
	setKey(strToAtariOper,"REBOOT",AKEY_COLDSTART);
	setKey(strToAtariOper,"UI",AKEY_UI);
	setKey(strToAtariOper,"FASTFORWARDON", AKEY_FASTFORWARDON);
	setKey(strToAtariOper,"FASTFORWARDOFF", AKEY_FASTFORWARDOFF);
	setKey(strToAtariOper,"FASTFORWARDTOGGLE", AKEY_FASTFORWARDTOGGLE);

	setKey(strToAtariOper,"VOLUMEUP", AKEY_VOLUMEUP);
	setKey(strToAtariOper,"VOLUMEDOWN", AKEY_VOLUMEDOWN);

	// consol
	setKey(strToAtariConsol,"START",CONSOL_START);
	setKey(strToAtariConsol,"SELECT",CONSOL_SELECT);
	setKey(strToAtariConsol,"OPTION",CONSOL_OPTION);
	
	// shift
	setKey(strToAtariShift,"SHIFT",1);

	// stick
	// PORT0, JOY0, PORT1, JOY1 (1,4,1,4 bits) 
	setKey(strToAtariJoy,"STICK_0_FIRE",1);
	setKey(strToAtariJoy,"STICK_0_UP",1 << 1);
	setKey(strToAtariJoy,"STICK_0_DOWN",2 << 1);
	setKey(strToAtariJoy,"STICK_0_LEFT",4 << 1);
	setKey(strToAtariJoy,"STICK_0_RIGHT",8 << 1);
	setKey(strToAtariJoy,"STICK_1_FIRE",1 << 5);
	setKey(strToAtariJoy,"STICK_1_UP",1 << 6);
	setKey(strToAtariJoy,"STICK_1_DOWN",2 << 6);
	setKey(strToAtariJoy,"STICK_1_LEFT",4 << 6);
	setKey(strToAtariJoy,"STICK_1_RIGHT",8 << 6);

	// 5200 power
	for (int i=1;i<108; ++i)
	{
		char buffer[256];
		_snprintf(buffer,256,"5200POWER_%d",i);
		setKey(strToAtari5200Power,buffer,i);
	}
	setKey(strToAtari5200Power,"5200DIGITAL",-1);
}

void toAtariKey(const char * str, int * oper, int * key, int * consol, int * shift, int * joy, int * power5200)
{
	STRTOATARI::const_iterator sa_i;

	sa_i = (*strToAtari5200Power).find(str);
	if (sa_i == (*strToAtari5200Power).end())
		*power5200 = 0;
	else
		*power5200 = (*sa_i).second;

	sa_i = (*strToAtariKey).find(str);
	if (sa_i == (*strToAtariKey).end())
		*key = AKEY_NONE;
	else
		*key = (*sa_i).second;

	sa_i = (*strToAtariOper).find(str);
	if (sa_i == (*strToAtariOper).end())
		*oper = 0;
	else
		*oper = (*sa_i).second;

	sa_i = (*strToAtariConsol).find(str);
	if (sa_i == (*strToAtariConsol).end())
		*consol = 0;
	else
		*consol = (*sa_i).second;

	sa_i = (*strToAtariShift).find(str);
	if (sa_i == (*strToAtariShift).end())
		*shift = 0;
	else
		*shift = (*sa_i).second;

	sa_i = (*strToAtariJoy).find(str);
	if (sa_i == (*strToAtariJoy).end())
		*joy = 0;
	else
		*joy = (*sa_i).second;
}

int toGpKey(const char * str)
{
	std::deque<std::string> tokens;
	tokenise(str, '|', &tokens);
	
	int result = 0;
	std::deque<std::string>::const_iterator tk_i;
	for (tk_i=tokens.begin(); tk_i!=tokens.end(); ++tk_i)
	{
		std::string tk = *tk_i;
		if (tk == "L")
		{
			result |= GPC_VK_FL;	
		}
		else if (tk == "R")
		{
			result |= GPC_VK_FR;
		}
		else if (tk == "A")
		{
			result |= GPC_VK_FA;
		}
		else if (tk == "B")
		{
			result |= GPC_VK_FB;
		}
#ifdef GP2X
		else if (tk == "X")
		{
			result |= GPC_VK_FX;
		}
		else if (tk == "Y")
		{
			result |= GPC_VK_FY;
		}
#endif
		else if (tk == "HOME")
		{
			result |= GPC_VK_HOME;
		}
		else if (tk == "VOLUME")
		{
			result |= GPC_VK_VOLUME;
		}
		else if (tk == "ASTERISK")
		{
			result |= GPC_VK_ASTERISK;
		}
		else if (tk == "TRIANGLE")
		{
			result |= GPC_VK_TRIANGLE;
		}
		else if (tk == "POWER")
		{
			result |= GPC_VK_POWER;
		}
		else if (tk == "UP")
		{
			result |= GPC_VK_UP;
		}
		else if (tk == "DOWN")
		{
			result |= GPC_VK_DOWN;
		}
		else if (tk == "LEFT")
		{
			result |= GPC_VK_LEFT;
		}
		else if (tk == "RIGHT")
		{
			result |= GPC_VK_RIGHT;
		}
		else
		{
			fprintf(stderr, "WARNING - unrecognised token:%s\n", tk.c_str());
		}
	}

	return result;
	return 0;
}



