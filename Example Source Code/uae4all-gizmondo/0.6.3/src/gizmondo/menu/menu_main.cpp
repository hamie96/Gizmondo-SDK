#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "menu.h"
#include "sysconfig.h"
#include "sysdeps.h"
#include "uae.h"
#include "options.h"
#include "sound.h"

#include "gizmondo.h"

extern int emulating;
extern int flashLED;
extern int gp2xClockSpeed;

static char *text_str_title=    "----- UAE4ALL GIZMONDO -----";
static char *text_str_load=     "Select Image Disk (L)";
static char *text_str_flash_led="Drive LED";
static char *text_str_throttle= "Emu Bias CPU  -- -- -- --  CHIP";
//static char *text_str_cpu_clock="GP2X Overclock";
static char *text_str_frameskip="Frameskip";
static char *text_str_0="0";
static char *text_str_1="1";
static char *text_str_2="2";
static char *text_str_3="3";
static char *text_str_4="4";
static char *text_str_5="5";
static char *text_str_mouse_multiplier="Mouse speed";
static char *text_str_1x="1x";
static char *text_str_2x="2x";
static char *text_str_3x="3x";
static char *text_str_4x="4x";
static char *text_str_5x="5x";
static char *text_str_auto="auto";
static char *text_str_eject="Eject DF1 (Y)";
//static char *text_str_gp2x_clock="Clock MHz";
static char *text_str_gp2x_clock_none="none";
static char *text_str_gp2x_clock_200="200";
static char *text_str_gp2x_clock_250="250";
static char *text_str_gp2x_clock_275="275";
static char *text_str_sound="Sound";
static char *text_str_on="on";
static char *text_str_off="off";
static char *text_str_faked="faked";
static char *text_str_status_line="Status ln";
static char *text_str_separator="--------------------------------";
static char *text_str_reset="Reset";
static char *text_str_run="Run (R)";
static char *text_str_exit="Exit";

#if !defined(DEBUG_UAE4ALL) && !defined(PROFILER_UAE4ALL) && !defined(AUTO_RUN) && !defined(AUTO_FRAMERATE)
int mainMenu_throttle=3;
int mainMenu_frameskip=-1;
#else
#ifdef PROFILER_UAE4ALL
#ifndef AUTO_PROFILER
int mainMenu_frameskip=0;
#else
int mainMenu_frameskip=-1;
#endif
#ifndef AUTO_PROFILER_THROTTLE
int mainMenu_throttle=0;
#else
int mainMenu_throttle=3;
#endif
#else
#ifdef DEBUG_FRAMERATE
int mainMenu_frameskip=-1;
#ifndef AUTO_FRAMERATE_THROTTLE
int mainMenu_throttle=0;
#else
int mainMenu_throttle=3;
#endif
#else
int mainMenu_throttle=0;
int mainMenu_frameskip=0;
#endif
#endif
#endif

int mainMenu_showStatus=0;
int mainMenu_mouseMultiplier = 1;
int mainMenu_sound=0;
int mainMenu_case=-1;

// no auto-save for gp2x currently
int mainMenu_autosave = 0;

static void draw_mainMenu(int c)
{
	/* 0 = load
	1 = throttle
	2 = frameskip
	3 = mouse cursor speed
	4 = sound
	5 = show status line
	6 = eject df1
	7 = reset
	8 = run
	9 = exit
	*/
	static int b=0;
	int bb=(b%6)/3;
	int menuLine = 3;
	int leftMargin = 4;
	int tabstop1 = 17;
	int tabstop2 = 19;
	int tabstop3 = 21;
	int tabstop4 = 23;
	int tabstop5 = 25;
	int tabstop6 = 27;
	int tabstop7 = 29;
	int tabstop8 = 31;
	int tabstop9 = 33;


	text_draw_background();
	text_draw_window(20,18,300,220,text_str_title);

	write_text(leftMargin,menuLine,text_str_separator);

	menuLine++;

	if ((c==0)&&(bb))
		write_text_inv(leftMargin,menuLine,text_str_load);
	else
		write_text(leftMargin,menuLine,text_str_load);

	menuLine++;
	write_text(leftMargin,menuLine,text_str_separator);
	menuLine++;

	write_text(leftMargin,menuLine,text_str_throttle);

	if ((mainMenu_throttle==1)&&((c!=1)||(bb)))
		write_text_inv(tabstop1,menuLine,"O");
	else
		write_text(tabstop1,menuLine,"O");
	if ((mainMenu_throttle==2)&&((c!=1)||(bb)))
		write_text_inv(tabstop2+1,menuLine,"O");
	else
		write_text(tabstop2+1,menuLine,"O");
	if ((mainMenu_throttle==3)&&((c!=1)||(bb)))
		write_text_inv(tabstop3+2,menuLine,"O");
	else
		write_text(tabstop3+2,menuLine,"O");
	if ((mainMenu_throttle==4)&&((c!=1)||(bb)))
		write_text_inv(tabstop4+3,menuLine,"O");
	else
		write_text(tabstop4+3,menuLine,"O");
	if ((mainMenu_throttle==5)&&((c!=1)||(bb)))
		write_text_inv(tabstop5+4,menuLine,"O");
	else
		write_text(tabstop5+4,menuLine,"O");

	menuLine+=2;
	write_text(leftMargin,menuLine,text_str_frameskip);
	if ((mainMenu_frameskip==0)&&((c!=2)||(bb)))
		write_text_inv(tabstop1,menuLine,text_str_0);
	else
		write_text(tabstop1,menuLine,text_str_0);
	if ((mainMenu_frameskip==1)&&((c!=2)||(bb)))
		write_text_inv(tabstop2,menuLine,text_str_1);
	else
		write_text(tabstop2,menuLine,text_str_1);
	if ((mainMenu_frameskip==2)&&((c!=2)||(bb)))
		write_text_inv(tabstop3,menuLine,text_str_2);
	else
		write_text(tabstop3,menuLine,text_str_2);
	if ((mainMenu_frameskip==3)&&((c!=2)||(bb)))
		write_text_inv(tabstop4,menuLine,text_str_3);
	else
		write_text(tabstop4,menuLine,text_str_3);
	if ((mainMenu_frameskip==4)&&((c!=2)||(bb)))
		write_text_inv(tabstop5,menuLine,text_str_4);
	else
		write_text(tabstop5,menuLine,text_str_4);
	if ((mainMenu_frameskip==5)&&((c!=2)||(bb)))
		write_text_inv(tabstop6,menuLine,text_str_5);
	else
		write_text(tabstop6,menuLine,text_str_5);
	if ((mainMenu_frameskip==-1)&&((c!=2)||(bb)))
		write_text_inv(tabstop7,menuLine,text_str_auto);
	else
		write_text(tabstop7,menuLine,text_str_auto);

	menuLine+=2;

	
	write_text(leftMargin,menuLine,text_str_mouse_multiplier);

	if ((mainMenu_mouseMultiplier==1)&&((c!=3)||(bb)))
		write_text_inv(tabstop1,menuLine,text_str_1x);
	else
		write_text(tabstop1,menuLine,text_str_1x);

	if ((mainMenu_mouseMultiplier==2)&&((c!=3)||(bb)))
		write_text_inv(tabstop3,menuLine,text_str_2x);
	else
		write_text(tabstop3,menuLine,text_str_2x);

	if ((mainMenu_mouseMultiplier==3)&&((c!=3)||(bb)))
		write_text_inv(tabstop5,menuLine,text_str_3x);
	else
		write_text(tabstop5,menuLine,text_str_3x);

	if ((mainMenu_mouseMultiplier==4)&&((c!=3)||(bb)))
		write_text_inv(tabstop7,menuLine,text_str_4x);
	else
		write_text(tabstop7,menuLine,text_str_4x);

	if ((mainMenu_mouseMultiplier==5)&&((c!=3)||(bb)))
		write_text_inv(tabstop9,menuLine,text_str_5x);
	else
		write_text(tabstop9,menuLine,text_str_5x);

	menuLine+=2;

	write_text(leftMargin,menuLine,text_str_sound);
	if ((mainMenu_sound==0)&&((c!=4)||(bb)))
		write_text_inv(tabstop1,menuLine,text_str_off);
	else
		write_text(tabstop1,menuLine,text_str_off);

	if ((mainMenu_sound==1)&&((c!=4)||(bb)))
		write_text_inv(tabstop3,menuLine,text_str_on);
	else
		write_text(tabstop3,menuLine,text_str_on);

	if ((mainMenu_sound==2)&&((c!=4)||(bb)))
		write_text_inv(tabstop5,menuLine,text_str_faked);
	else
		write_text(tabstop5,menuLine,text_str_faked);


	menuLine+=2;

	write_text(leftMargin, menuLine,text_str_status_line);
	if ((!mainMenu_showStatus)&&((c!=5)||(bb)))
		write_text_inv(tabstop1,menuLine, text_str_off);
	else
		write_text(tabstop1, menuLine, text_str_off);
	if ((mainMenu_showStatus)&&((c!=5)||(bb)))
		write_text_inv(tabstop3, menuLine,text_str_on);
	else
		write_text(tabstop3, menuLine,text_str_on);

	menuLine+=2;

	if ((c==6)&&(bb))
		write_text_inv(leftMargin,menuLine,text_str_eject);
	else
		write_text(leftMargin, menuLine,text_str_eject);
	
	menuLine++;

	write_text(leftMargin,menuLine,text_str_separator);

	menuLine++;

	if ((c==7)&&(bb))
		write_text_inv(leftMargin,menuLine,text_str_reset);
	else
		write_text(leftMargin,menuLine,text_str_reset);

	menuLine++;
	write_text(leftMargin,menuLine,text_str_separator);
	menuLine++;

	if ((c==8)&&(bb))
		write_text_inv(leftMargin,menuLine,text_str_run);
	else
		write_text(leftMargin,menuLine,text_str_run);

	menuLine++;
	write_text(leftMargin,menuLine,text_str_separator);
	menuLine++;

	if ((c==9)&&(bb))
		write_text_inv(leftMargin,menuLine,text_str_exit);
	else
		write_text(leftMargin,menuLine,text_str_exit);

	menuLine++;
	write_text(leftMargin,menuLine,text_str_separator);

	text_flip();
	b++;
}

static int key_mainMenu(int *cp)
{
	int back_c = -1;
	int c=(*cp);
	int end=0;
	int left=0, right=0, up=0, down=0, hit0=0, hit1=0, hit2=0, hit3=0, hit4=0, hit5=0;
	SDL_Event event;

	while (SDL_PollEvent(&event) > 0)
	{
		if (event.type == SDL_QUIT)
		{
			mainMenu_case=MAIN_MENU_CASE_REBOOT;
			end=-1;
		}
		else if (event.type == SDL_JOYHATMOTION)
        {
	        if ( (event.jhat.value & SDL_HAT_UP) == SDL_HAT_UP )
		    {
				up=1;
			}
			if ( (event.jhat.value & SDL_HAT_RIGHT) == SDL_HAT_RIGHT )
			{
				right = 1;
			}
			if ( (event.jhat.value & SDL_HAT_DOWN) == SDL_HAT_DOWN )
			{
				down = 1;
			}
			if ( (event.jhat.value & SDL_HAT_LEFT) == SDL_HAT_LEFT )
			{
				left = 1;
			}
		}

		else if (event.type == SDL_JOYBUTTONDOWN)
		{
			switch (event.jbutton.button)
			{
			case GIZ_FORWARDS: hit0=1; break;
			case GIZ_BACK: hit1 = 1; break;
			case GIZ_STOP: hit5=1; break;
			case GIZ_LTRIG: hit3=1; break;
			case GIZ_RTRIG: hit4=1; break;
			}
		}
		else
			if (event.type == SDL_KEYDOWN)
			{
				uae4all_play_click();
				switch(event.key.keysym.sym)
				{
				case SDLK_RIGHT: right=1; break;
				case SDLK_LEFT: left=1; break;
				case SDLK_UP: up=1; break;
				case SDLK_DOWN: down=1; break;
				case SDLK_RETURN:
				case SDLK_LCTRL: hit0=1; break;
				case SDLK_LALT: hit1=1; break;
				}
			}

			if (hit1)
			{
				mainMenu_case=MAIN_MENU_CASE_CANCEL;
				end=1;
			}
			else if (hit2)
			{
				// ???
			}
			else if (hit3)
			{
				mainMenu_case=MAIN_MENU_CASE_LOAD;
				end=1;
			}
			else if (hit4)
			{
				// run
				back_c = c;
				hit0 = 1;
				c = 8;
			}
			else if (hit5)
			{
				// eject
				back_c = c;
				hit0 = 1;
				c = 6;
			}
			else if (up)
			{
				if (c>0) c=(c-1)%10;
				else c=9;
			}
			else if (down)
				c=(c+1)%10;
			
			switch(c)
			{
				case 0:
					if (hit0)
					{
						mainMenu_case=MAIN_MENU_CASE_LOAD;
						end=1;
					}
					break;
				case 1:
					if (left)
					{
						if (mainMenu_throttle>1)
							mainMenu_throttle--;
						else
							mainMenu_throttle=5;
					}
					else if (right)
					{
						if (mainMenu_throttle<5)
							mainMenu_throttle++;
						else
							mainMenu_throttle=1;
					}
					break;
				case 2:
					if (left)
					{
						if (mainMenu_frameskip>-1)
							mainMenu_frameskip--;
						else
							mainMenu_frameskip=5;
					}
					else if (right)
					{
						if (mainMenu_frameskip<5)
							mainMenu_frameskip++;
						else
							mainMenu_frameskip=-1;
					}
					break;
				case 3:
					if (left)
					{
						if (mainMenu_mouseMultiplier > 1)
							mainMenu_mouseMultiplier--;
					}
					else if (right)
					{
						if (mainMenu_mouseMultiplier < 5)
							mainMenu_mouseMultiplier++;
					}
					break;

				case 4:
					if (left)
					{
						if (mainMenu_sound == 1)
							mainMenu_sound = 0;
						else if (mainMenu_sound == 2)
							mainMenu_sound = 1;
						else if (mainMenu_sound == 0)
							mainMenu_sound = 2;
					}
					else if (right)
					{
						if (mainMenu_sound == 2)
							mainMenu_sound = 0;
						else if (mainMenu_sound == 0)
							mainMenu_sound = 1;
						else if (mainMenu_sound == 1)
							mainMenu_sound = 2;
					}
					break;
				case 5:
					if ((left)||(right))
						mainMenu_showStatus=~mainMenu_showStatus;
					break;
				case 6:
					// eject
					if (hit0)
					{
						mainMenu_case=MAIN_MENU_CASE_EJECT;
						end=1;
					}
					break;
				case 7:
					if (hit0)
					{
						mainMenu_case=MAIN_MENU_CASE_RESET;
						end=1;
					}
					break;
				case 8:
					if (hit0)
					{
						mainMenu_case=MAIN_MENU_CASE_RUN;
						end=1;
					}
					break;
				case 9:
					if (hit0)
					{
						mainMenu_case=MAIN_MENU_CASE_REBOOT;
						end=1;
					}
					break;
			}
			if (back_c>=0)
			{
				c=back_c;
				back_c=-1;
			}
			
	}


	(*cp)=c;
	return end;
}

static void raise_mainMenu()
{
	int i;

	text_draw_background();
	text_flip();
	for(i=0;i<10;i++)
	{
		text_draw_background();
		text_draw_window(40,(10-i)*24,260,200,text_str_title);
		text_flip();
	}
}

static void unraise_mainMenu()
{
	int i;

	for(i=9;i>=0;i--)
	{
		text_draw_background();
		text_draw_window(40,(10-i)*24,260,200,text_str_title);
		text_flip();
	}
	text_draw_background();
	text_flip();
}

int run_mainMenu()
{
#if defined(AUTO_RUN) || defined(AUTO_FRAMERATE) || defined(AUTO_PROFILER)
	return 1;
#else
#if !defined(DEBUG_UAE4ALL) && !defined(PROFILER_UAE4ALL) 
	static int c=0;
#else
	static int c=1;
#endif
	int end;
	mainMenu_case=-1;
	
	while(mainMenu_case<0)
	{
		raise_mainMenu();
		end=0;
		while(!end)
		{
			draw_mainMenu(c);
			end=key_mainMenu(&c);
		}
		unraise_mainMenu();
		switch(mainMenu_case)
		{
		case MAIN_MENU_CASE_LOAD:
			run_menuLoad();	
			mainMenu_case=-1;
			break;
		case MAIN_MENU_CASE_EJECT:
			mainMenu_case=3;
			break;
		case MAIN_MENU_CASE_CANCEL:
			if (emulating)
				mainMenu_case=1;
			else
				mainMenu_case=-1;
			break;
		case MAIN_MENU_CASE_RESET:
			if (emulating)
			{
				mainMenu_case=2;
				break;
			}
		case MAIN_MENU_CASE_RUN:
			mainMenu_case=1;
			break;
		case MAIN_MENU_CASE_REBOOT:
#ifdef DREAMCAST
			arch_reboot();
#else
			exit(0);
#endif
			break;
		default:
			mainMenu_case=-1;
		}
	}

	return mainMenu_case;
#endif
}
