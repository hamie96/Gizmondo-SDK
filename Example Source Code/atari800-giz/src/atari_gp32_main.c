#include <stdlib.h>
//#include <sched.h>
//#include <unistd.h>

#include "atari.h"
#include "config.h"
#include "monitor.h"
#include "colours.h"
#include "pokeysnd.h"
#include "input.h"

#include "sound.h"
#include "platform.h"
#include "antic.h"
#include "gtia.h"
#include "pokey.h"
#include "devices.h"
#include "log.h"
#include "pia.h"
#include "ui.h"
#include "statesav.h"
#include "keyboard.h"

#include "atari_gp32.h"
#include "splash.h"

#include "menu_keymap.h"
#include "menu_c.h"

//#include "gp2xminlib.h"


#include <stdio.h>
#include <string.h>

//#include <sys/stat.h>

void dumpTimerRegs();
int gpNextTimer = 0;

#ifdef NEW_CYCLE_EXACT
int gp32ClockEnum = GPMHZ_200;
static int gp32ClockEnumMax = GPMHZ_250;
#else
int gp32ClockEnum = GPMHZ_200;
static int gp32ClockEnumMax = GPMHZ_250;
#endif
extern int fastForward;

void Screen_DrawAtariSpeed();
void Screen_DrawDiskLED();

int main(int argc, char * argv[])
{
	int loadedState;
	char statename[FILENAME_MAX+1];
	int fastForwardFrameCount;
//	struct sched_param param;
//	param.sched_priority=50;

	//sched_setscheduler(0, SCHED_FIFO, &param);
#ifndef NATY
	//nice(-10);
#endif

//	SDL_Init(SDL_INIT_TIMER|SDL_INIT_NOPARACHUTE);
//	SDL_ShowCursor(0);

//	gp2x_reg_init();

/*	SDL_Surface * s = SDL_SetVideoMode(320,240,32,SDL_HWSURFACE);
	SDL_Rect rect;
	rect.x = 5;
	rect.y = 5;
	rect.w = 100;
	rect.h = 100;

	SDL_FillRect(s, &rect, 0xff);
	SDL_UpdateRect(s,0,0,0,0);
	for (;;);
*/	
	// Display splash screen
	//fprintf(stderr,"Setting up splash\n");
	initSplash();
	
	// Initialise emulator (this will call us back in Atari_Initialise)
//	fprintf(stderr,"Calling Atari800_Initialise\n");

	if (!Atari800_Initialise(&argc, argv))
	{
		Atari_Exit(0);
		return 0;
	}
	//fprintf(stderr,"Atari800_Initialise returned\n");

	// Start in ui so user can load a game - unless autorun exists
	loadedState = 0;
	strcpy(statename, saved_files_dir[0]);
#ifdef BACK_SLASH
	strcat(statename, "\\autorun");
#else
	strcat(statename, "/autorun");
#endif

	//struct stat statBuf;
	if (strlen(statename)>0)
	{
		loadedState = ReadAtariState(statename, "rb");
	        consol_table[1] = consol_table[2] = 0xf;
	}

	cleanupSplash(); 
	//fprintf(stderr, "Cleaned up splash\n");
	Atari_DisplayInitPhase2();

	// If autorun exists load it, else go to ui
	//fprintf(stderr, "Going to ui\n");
	if (!loadedState)
		ui();

	Sound_Continue();

	// Main loop

	fastForwardFrameCount = 0;
	while (key_code != AKEY_EXIT) {
#ifdef TIMESECTIONS
		int frameStart = GpTickCountGet();
#endif

		INPUT_Frame();
			
#ifdef TIMESECTIONS
		int inputFrame = GpTickCountGet();
#endif

		Device_Frame();
#ifdef TIMESECTIONS
		int deviceFrame = GpTickCountGet();	
#endif

		GTIA_Frame();
#ifdef TIMESECTIONS
		int gtiaFrame = GpTickCountGet();	
#endif

		if (!fastForward)
		{
			Sound_Update();
		}
#ifdef TIMESECTIONS
		int soundFrame = GpTickCountGet();	
#endif

		//timeDrawNextFrame = 1;
		if (fastForward)
		{
			fastForwardFrameCount++;
			fastForwardFrameCount&=0xf;
			timeDrawNextFrame = (fastForwardFrameCount==0);
		}

		ANTIC_Frame(timeDrawNextFrame);
#ifdef TIMESECTIONS
		int anticFrame = GpTickCountGet();	
#endif
                INPUT_DrawMousePointer();
                Screen_DrawAtariSpeed();
                Screen_DrawDiskLED();

		POKEY_Frame();
#ifdef TIMESECTIONS
		int pokeyFrame = GpTickCountGet();	
#endif

		Menu_Frame();
#ifdef TIMESECTIONS
		int menuFrame = GpTickCountGet();
#endif

		Atari_DisplayScreen();
#ifdef TIMESECTIONS
		int displayFrame = GpTickCountGet();	
#endif

#ifdef TIMESECTIONS
		char arse[256];
		debugText = arse;
		sprintf(arse, "D%3d G%3d S:%3d A:%3d P:%3d A:%3d", deviceFrame-frameStart, gtiaFrame-deviceFrame, soundFrame-gtiaFrame, anticFrame-soundFrame, pokeyFrame-anticFrame, displayFrame-pokeyFrame);
#endif

		nframes++;

		/*if (timeDrawNextFrame)
		{
			GpSurfaceFlip(&gpDraw[backbuf]);
			backbuf ^= 1;
		}*/

		//atari_sync();
		if (!fastForward)
			Atari_Sync();

		{
			//static struct timeval last;
			//static struct timeval next;
			static int last;
			int next;
			double diff;

			next = GpTickCountGet();
			diff = ((double)(next-last))/1000.0;
			percent_atari_speed = (int) (100.0 * (double)DELTATIME / diff + 0.5);
	//		fprintf(stderr,"Diff:%f\n", diff);

			last = next;
	        }

	}
	Atari800_Exit(FALSE);
	Aflushlog();
	return 0;
}

void Atari_Initialise(int *argc, char *argv[])
{
	//fprintf(stderr,"AIDisplay\n");
	Atari_DisplayInitialise();
	//fprintf(stderr,"AIKey\n");
	Keyboard_Initialise();
	//fprintf(stderr,"AISound\n");
	Sound_Initialise(0,0);

	// Menu
	//fprintf(stderr,"AIMenu\n");
	Menu_Initialise();

	if(initinput())
	{
		perror("Input initialization failed");
		exit(1);
	}
}

static char platform[] = "GP32";

void PlatformStateSave()
{
	unsigned char bstore;
	unsigned char frameSkip;
	unsigned char artifMode;
	unsigned char clkenum;

	SaveUBYTE(platform, strlen(platform)); 

	// Brightness
	bstore = brightness;
	if (bstore == defaultBrightness)
		bstore = 255;
	SaveUBYTE(&bstore, 1);

	// Menu
	SaveUBYTE(currentMenu, strlen(currentMenu)+1);

	// Frame skip
	frameSkip = Atari_GetAutoFrameSkip();
	SaveUBYTE(&frameSkip, 1);

	// Artifacting
	artifMode = global_artif_mode;
	SaveUBYTE(&artifMode, 1);
	
	// Clock speed
	clkenum = gp32ClockEnum;
	SaveUBYTE(&clkenum, 1);
}

void PlatformStateRead()
{
	char temp[FILENAME_MAX];
	char menuTemp;
	int iter;
	unsigned char frameSkip;
	unsigned char artifMode;
	unsigned char lgp32ClockEnum;

	strcpy(temp, platform);
	temp[0] = '\0';
	ReadUBYTE(temp, strlen(platform));
	if (strcmp(temp, platform) != 0)
		return;

	// Brightness
	ReadUBYTE(&brightness, 1);
	if (brightness == 255)
		brightness = defaultBrightness;
	Atari_DisplayBrightness(brightness);

	// Menu
	menuTemp = 1;
	iter = 0;
	do
	{
		ReadUBYTE(&menuTemp, 1);
		temp[iter++] = menuTemp;
	} while (menuTemp!=0);

	menuLoad(temp);

	// Frame skip
	frameSkip = 0xff;
	ReadUBYTE(&frameSkip, 1);
	if (frameSkip != 0xff)
		Atari_AutoFrameSkip(frameSkip);

	// Artifacting
	artifMode = 0xff;
	ReadUBYTE(&artifMode, 1);
	if (artifMode != 0xff)
	{	
		global_artif_mode = artifMode;
		ANTIC_UpdateArtifacting();
	}

	// Clock speed
	lgp32ClockEnum = 0xff;
	ReadUBYTE(&lgp32ClockEnum, 1);
	if (lgp32ClockEnum != 0xff)
		GP32_SetClock(lgp32ClockEnum);
}

void GP32_SetClockMax(int onOff)
{
	if (onOff)
	{
		int gp32ClockEnumStore = gp32ClockEnum;
		GP32_SetClock(gp32ClockEnumMax);
		gp32ClockEnum = gp32ClockEnumStore;
	}
	else
	{
		GP32_SetClock(gp32ClockEnum|0x80); //Force...
	}
}

void GP32_SetClock(int clock)
{
	// FIXME - no point here, can't change Giz clock??
	int freq=0;
	char buffer[512];
	
	if (clock == gp32ClockEnum)
		return;
	clock &= 0x7f;
	gp32ClockEnum = clock;
	if (clock > gp32ClockEnumMax)
		gp32ClockEnumMax = clock;

	switch(clock)
	{
//	case GPMHZ_40: GpClockSpeedChange (40000000, 0x48013, 1); break;
//	case GPMHZ_59: GpClockSpeedChange (59250000, 0x47022, 1); break;
	case GPMHZ_67: freq=66; break; 
	case GPMHZ_80: freq=80; break;
	case GPMHZ_99: freq=100; break;
	case GPMHZ_115: freq=120; break; 
	case GPMHZ_132: freq=133; break;
	case GPMHZ_156: freq=150; break;
	case GPMHZ_165: freq=166; break;
	case GPMHZ_180: freq=180; break;
	case GPMHZ_200: freq=200; break;
	case GPMHZ_250: freq=250; break;
	default:exit(0);
	}

	_snprintf(buffer, 512, "%s %d", atari_clockcommand_filename, freq);
//	fprintf(stderr, "\nAbout to run %s\n", buffer);
	//_system(buffer);
	//gp2x_video_init(8);

/*	GpClockSpeedChange(freq, magic, div);
	Aprint("Clock M:%d H:%d P:%d\n", GpMClkGet(), GpHClkGet(), GpPClkGet());
	unsigned int pclk = GpPClkGet();

	// Repair SDK timer - it forgets to set prescaler
	//pclk/(x+1) ~= 8000*40
	//x= (pclk/(8000*40)) -1
	unsigned int prescaler0 = (pclk/(8000*40))-1;
	rTCFG0 = (rTCFG0&0xFFFFFF00)|prescaler0;
	rTCFG1 = 0x30033;

	// Repair GpTickCountGet
	// pclk/(100x) = 16
	// x = pclk/1600
	rTCNTB4 = pclk/1600;
 //	rTCON  = (0x1<<22) | (0x1<<20);

	// Repair display - driven off hclk
	// HMM - looks like the sdk doesn't tweak clkval and I can't find anything else. Worst case we'll get < 2x lcd framerate (49.. vs 80 hck)

	// Repair sound
#ifdef STEREO
	GpPcmInit(PCM_S22, PCM_8BIT);
#else
	GpPcmInit(PCM_M22, PCM_8BIT);
#endif

	// Repair chatboard
	preInitKbd(9600, GpPClkGet());

	dumpTimerRegs();
*/
//	if (div>1)
//		div = 2<<(div-2);
//	clockSpeed = freq/ div;
}



