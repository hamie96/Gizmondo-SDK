#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <sys/mman.h>
//#include <fcntl.h>

#include "global.h"
#include "gp2x_psp.h"

/* For internal use only */
# define GP2X_CTRL_UPRIGHT    0x10000
# define GP2X_CTRL_UPLEFT     0x20000
# define GP2X_CTRL_DOWNRIGHT  0x40000
# define GP2X_CTRL_DOWNLEFT   0x80000


static int    loc_Volume = 50;

//static int    loc_LastEventMask    = 0;
//static int    loc_CurrEventMask    = 0;
//static int    loc_CurrEventButtons = 0;
//static u32    loc_LastTimeStamp    = 0;
static u32    loc_CurrTimeStamp    = 0;

static int    loc_VolumeButtons = 0;
static int    loc_VolumePress   = 0;
static u32    loc_LastVolumeTimeStamp = 0;

# define GP2X_MIN_TIME_VOLUME  300000
# define GP2X_MIN_TIME_REPEAT  100000

void
gp2xTreatVolume(gp2xCtrlData* c)
{
  if ((c->Buttons & (GP2X_CTRL_VOLDOWN)) == (GP2X_CTRL_VOLDOWN)) {
	  c->Buttons = 0;
    /* Already down ? */
    if (! (loc_VolumeButtons & GP2X_CTRL_VOLDOWN)) {
      loc_LastVolumeTimeStamp = loc_CurrTimeStamp;
      loc_VolumeButtons = GP2X_CTRL_VOLDOWN;
      loc_VolumePress = 1;
      gp2xDecreaseVolume();
    } else 
    if ((((loc_CurrTimeStamp - loc_LastVolumeTimeStamp) > GP2X_MIN_TIME_VOLUME) && (loc_VolumePress == 1)) ||
        (((loc_CurrTimeStamp - loc_LastVolumeTimeStamp) > GP2X_MIN_TIME_REPEAT) && (loc_VolumePress  > 1))) {
      loc_LastVolumeTimeStamp = loc_CurrTimeStamp;
      loc_VolumePress++;
      gp2xDecreaseVolume();
    }

  } else
  if ((c->Buttons & (GP2X_CTRL_VOLUP)) == (GP2X_CTRL_VOLUP)) {
	  c->Buttons = 0;
    /* Already down ? */
    if (! (loc_VolumeButtons & GP2X_CTRL_VOLUP)) {
      loc_LastVolumeTimeStamp = loc_CurrTimeStamp;
      loc_VolumeButtons |= GP2X_CTRL_VOLUP;
      loc_VolumePress = 1;
      gp2xIncreaseVolume();
    } else 
    if ((((loc_CurrTimeStamp - loc_LastVolumeTimeStamp) > GP2X_MIN_TIME_VOLUME) && (loc_VolumePress == 1)) ||
        (((loc_CurrTimeStamp - loc_LastVolumeTimeStamp) > GP2X_MIN_TIME_REPEAT) && (loc_VolumePress  > 1))) {
      loc_LastVolumeTimeStamp = loc_CurrTimeStamp;
      loc_VolumePress++;
      gp2xIncreaseVolume();
    }

  } else {
    loc_VolumeButtons = 0;
  }
}

int  
gp2xCtrlPeekBufferPositive(gp2xCtrlData* c, int v)
{
	int left = (GetAsyncKeyState(37)&0x8000)!=0;
	int right = (GetAsyncKeyState(39)&0x8000)!=0;
	int up = (GetAsyncKeyState(38)&0x8000)!=0;
	int down = (GetAsyncKeyState(40)&0x8000)!=0;

	int brwnd = (GetAsyncKeyState(160)&0x8000)!=0;
	int bffwd = (GetAsyncKeyState(32)&0x8000)!=0;
	int bstop = (GetAsyncKeyState(162)&0x8000)!=0;
	int bplay = (GetAsyncKeyState(13)&0x8000)!=0;
	int bl = (GetAsyncKeyState(9)&0x8000)!=0;
	int br = (GetAsyncKeyState(27)&0x8000)!=0;

	int bhome = (GetAsyncKeyState(112)&0x8000)!=0;
	int bvol = (GetAsyncKeyState(113)&0x8000)!=0;
	int bstar = (GetAsyncKeyState(114)&0x8000)!=0;
	int btri = (GetAsyncKeyState(115)&0x8000)!=0;
	int bpow = (GetAsyncKeyState(123)&0x8000)!=0;

    int buttons = 0;

/*	int buffer[256];
	int pressed = 0;
	int i=0;
	for (i=0; i<255; ++i)
	{
		buffer[i] = ((GetAsyncKeyState(i)&0x8000)!=0);
		if (buffer[i])
			pressed = i;
	}*/


	memset(c, 0x0, sizeof(gp2xCtrlData));
	loc_CurrTimeStamp = Perf_GetTicks()*1000;

	if (up)
	   {buttons |= GP2X_CTRL_UP;}
	if (down)
	   {buttons |= GP2X_CTRL_DOWN;}
	if (left)
	   {buttons |= GP2X_CTRL_LEFT;}
	if (right)
	   {buttons |= GP2X_CTRL_RIGHT;}

	if (brwnd)
	   buttons |= GP2X_CTRL_RWND;
	if (bstop)
	   buttons |= GP2X_CTRL_STOP;
	if (bffwd)
	   buttons |= GP2X_CTRL_FFWD;
	if (bplay)
	   buttons |= GP2X_CTRL_PLAY;

	if (bl)
		buttons |= GP2X_CTRL_LTRIGGER;
	if (br)
	   buttons |= GP2X_CTRL_RTRIGGER;

	if (bhome)
		buttons |= GP2X_CTRL_HOME;

	if (bstar)
		buttons |= GP2X_CTRL_STAR;

	if (btri)
		buttons |= GP2X_CTRL_TRI;

	if (bpow)
		buttons |= GP2X_CTRL_POWER;

	if (bvol)
		buttons |= GP2X_CTRL_VOL;

    c->Buttons   = buttons;
    c->TimeStamp = loc_CurrTimeStamp;
  
  gp2xTreatVolume(c);

  return (c->Buttons != 0);
}

int
gp2xCtrlReadBufferPositive(gp2xCtrlData* c, int v)
{
  while (! gp2xCtrlPeekBufferPositive(c, v));
  return 1;
}


extern void set_speed_clock(int freq);
void
gp2xPowerSetClockFrequency(int freq)
{
# ifdef GP2X_MODE
  if ((freq >= 33) && (freq <= 266)) {
    set_speed_clock(freq);
  }
# endif
}

int
gp2xGetSoundVolume()
{
  return loc_Volume;
}

void
gp2xDecreaseVolume()
{
  loc_Volume -= 2;
  if (loc_Volume < 0) loc_Volume = 0;

	FrameworkAudio_SetVolume(loc_Volume, loc_Volume);
}

void
gp2xIncreaseVolume()
{
  loc_Volume += 2;
  if (loc_Volume > 100) loc_Volume = 100;

  FrameworkAudio_SetVolume(loc_Volume, loc_Volume);
}

int 
gp2xInsmodMMUhack(void)
{
# ifdef GP2X_MMU_HACK
	int mmufd = open("/dev/mmuhack", O_RDWR);
	if(mmufd < 0) {
		system("/sbin/insmod ./drivers/mmuhack.o");
		mmufd = open("/dev/mmuhack", O_RDWR);
	}
	if(mmufd < 0) return 0;
 	close(mmufd); 
# endif
	return 1;
}

int 
gp2xRmmodMMUhack(void)
{
# ifdef GP2X_MMU_HACK
  system("/sbin/rmmod mmuhack");
# endif
  return 0;
}  
