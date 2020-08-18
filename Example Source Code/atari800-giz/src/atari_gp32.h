//#include <SDL/SDL.h>
#include "gp2xgp32compat.h"

#define DELTATIME (1.0/(tv_mode == TV_PAL ? 50.0 : 60.0))

// Main
extern volatile unsigned int rtcTick;
extern int gpNextTimer;
void Atari_Main();
enum {GPMHZ_67, GPMHZ_80, GPMHZ_99, GPMHZ_115, GPMHZ_132, GPMHZ_156, GPMHZ_165, GPMHZ_180, GPMHZ_200, GPMHZ_250};
void GP32_SetClock(int clock);
void GP32_SetClockMax(int onOff);

// Input
// Handled by menu code now (mostly...)
//void convertKey(int * code, int *shift);
extern int joyValue[];
extern int fireValue[];

// Sync
extern int timeDrawNextFrame;
int Atari_Time();
void Atari_Sync();
void Atari_ReSync();
void Atari_AutoFrameSkip(int enable);
int Atari_GetAutoFrameSkip();

extern unsigned int origPClk;

// Display
extern char * debugText;
extern char * debugTextBuffer;
extern unsigned char brightness;
extern unsigned char defaultBrightness;

void Atari_DisplayInitialise();
void * Atari_DisplayActiveBuffer();
void Atari_DisplayBrightness(int level);
int mapPal(int);
void gp2x_video_flip();
void gp2x_sound_init(int dsprate, int bits, int channels);
void gp2x_sound_play(int on);
int gp2x_sound_frame(void * userdata, void * streamIn, int lenIn);

// Menu
/*typedef struct MENU
{
	struct MENU * left;
	struct MENU * right;
	struct MENU * up;
	struct MENU * down;

	const char * name;
	int key;
} MENU;*/
extern unsigned char menuWidth;
extern unsigned char menuHeight;
/*MENU * Menu_Construct(MENU * parent, const char * name, int key);
void Menu_Connect(MENU * first, MENU * second);
void Menu_ConnectSub(MENU * parent, MENU * child);
void Menu_Enable(MENU * menu);*/
void Menu_Initialise();
void Menu_Frame();

