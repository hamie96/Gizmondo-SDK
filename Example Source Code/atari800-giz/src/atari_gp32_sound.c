#include "atari.h"
#include "config.h"
#include "monitor.h"
#include "pokeysnd.h"
#include "sound.h"

#include <stdlib.h>
#include <string.h>
//#include <unistd.h>
//#include <pthread.h>

#include "atari_gp32.h"

//#include "gp2xminlib.h"

// We have dual sound buffers
// i) Controlled by gpsoundbuffer.c. Callback when we need more data to play.
// ii) Controlled by emulator. Filled every frame.
//
// Strategy: Fill emulator buffer in main code. Copy into play buffer on callback.
//
// Reason: Emulator does not like callbacks on interrupt into the sound code.
// Mostly works, but volume only seems broken among other things.
// Quite interesting really since the SDL port appears to use the callback method only.
// Another reason: Decouples emulator time from GP32 time

int soundBufferSamplesStored = 0;

#define DEFDSPRATE 22050
static int soundPlaying = FALSE;

//#define TIMESOUND

#ifdef STEREO
	#define SNDBUFSIZE 8192
#else
	#define SNDBUFSIZE 4096
#endif
static unsigned char * atariSoundBuffer = 0;
static int atariSoundBufferStart = 0;
static int atariSoundBufferEnd = 0;

//static HANDLE soundThread;
//static CRITICAL_SECTION soundMutex;

//////////////////////////////////////////////////////////////////////////
// Forward declarations of some internal functions
static int soundBufferRollingDistance(int start, int end, int length);
//static DWORD soundThreadCode(LPVOID);

//////////////////////////////////////////////////////////////////////////
// Functions called externally by the emulator code...
void Sound_Initialise(int *argc, char *argv[])
{
	atariSoundBuffer = (char *)malloc(SNDBUFSIZE);

	// And sound
#ifdef STEREO
	stereo_enabled = 0;
#endif

	atariSoundBuffer = (char *)malloc(SNDBUFSIZE);
#ifdef STEREO
        //GpPcmInit(PCM_S22, PCM_8BIT);
//	fprintf(stderr, "Pokey sound init\n");
	Pokey_sound_init(FREQ_17_EXACT, DEFDSPRATE, 2); // While they support 16-bit it doesn't work (I know why, but...)
//	fprintf(stderr, "GP2x sound init\n");
	gp2x_sound_init(22050,16,1);
//	fprintf(stderr, "Pthread fiddling\n");
#else
        //GpPcmInit(PCM_M22, PCM_8BIT);
	Pokey_sound_init(FREQ_17_EXACT, DEFDSPRATE, 1);
	gp2x_sound_init(22050,16,0);
#endif
	//pthread_attr_t attr;
	//struct sched_param param;
	//param.sched_priority = 80;
	//pthread_attr_init(&attr);
	//pthread_attr_setschedpolicy(&attr,SCHED_RR);
	//pthread_attr_setschedparam(&attr, &param);
#ifndef NATY
	//nice(-20);
#endif

	//InitializeCriticalSection(&soundMutex);
	//soundThread = CreateThread(NULL,0,soundThreadCode, 0,0,NULL);
	//CeSetThreadPriority(GetCurrentThread(), 0);
	//CeSetThreadPriority(soundThread, 0);
	//pthread_create(&soundThread, &attr, soundThreadCode, 0);
}

void Sound_Pause(void)
{
	if (!soundPlaying)
		return;

	gp2x_sound_play(0);

	soundPlaying = FALSE;
}

void Sound_Continue(void)
{
	if (soundPlaying)
		return;

	soundPlaying = TRUE;	
}

void Sound_Exit(void)
{
	Sound_Pause();
}

void Sound_Update()
{
	if (soundPlaying)
	{
		int bytesToGet = 0;
		int bytesLeft = 0;
		//static int last;
		//static int next;
		int spaceLeft;

#ifdef TIMESOUND
		struct timeval start,end;
		gettimeofday(&start,0);
#endif
		//EnterCriticalSection(&soundMutex);
			
		// Fill buffer
		bytesLeft = soundBufferRollingDistance(atariSoundBufferStart, atariSoundBufferEnd, SNDBUFSIZE);

#ifdef STEREO
		bytesToGet = 22050*DELTATIME*2*2; // 22050/50 *2 approx
#else
		bytesToGet = 22050*DELTATIME*2;
#endif
	//	gettimeofday(&next, 0);

		spaceLeft = SNDBUFSIZE-bytesLeft;
	//	fprintf (stderr, "diff:%d fetching:%d bytesLeft:%d spaceLeft:%d\n",next.tv_usec-last.tv_usec, bytesToGet, bytesLeft,spaceLeft);
//		last = next;
		

		if (bytesToGet > spaceLeft) // not enough room
		{
			bytesToGet = spaceLeft-1;
		}
		else if (bytesLeft < (bytesToGet*1.1)) // running low
		{
			bytesToGet = bytesToGet*1.1 - 1; 
		}
		bytesToGet&=0xfffffff8;

		//fprintf(stderr, "Fetching:%d\n", bytesToGet);

		if (bytesToGet > 0)
		{
			if ((atariSoundBufferEnd + bytesToGet) > SNDBUFSIZE) //overflow
			{
				char tempbuffer[SNDBUFSIZE];
				int remaining = SNDBUFSIZE - atariSoundBufferEnd;
				Pokey_process(tempbuffer, bytesToGet/2);
				memcpy(atariSoundBuffer+atariSoundBufferEnd, tempbuffer, remaining);
				//Pokey_process(atariSoundBuffer + atariSoundBufferEnd, remaining);
				memcpy(atariSoundBuffer, tempbuffer+remaining, bytesToGet-remaining);
				//Pokey_process(atariSoundBuffer, bytesToGet-remaining);
				atariSoundBufferEnd = bytesToGet-remaining;
			}
			else
			{
				Pokey_process(atariSoundBuffer + atariSoundBufferEnd, bytesToGet/2);
				atariSoundBufferEnd += bytesToGet;
			}
		}

		//LeaveCriticalSection(&soundMutex);
		
#ifdef TIMESOUND
		gettimeofday(&end,0);
		double taken = (end.tv_sec-start.tv_sec)*1e3 + (end.tv_usec-start.tv_usec)/1e3;
		fprintf(stderr,"Sound update took:%fms\n",taken);
#endif
	}

	gp2x_sound_play(1);
}

//////////////////////////////////////////////////////////////////////////
// Helper function for sound circular buffer
static int soundBufferRollingDistance(int start, int end, int length)
{
	if (end > start)
		return (end-start);
	if (end < start)
		return (length-start + end);

	return 0;
}

// Thread, which calls "interrupt driven callback"
/*static DWORD soundThreadCode (LPVOID a)
{
	while (1)
	{
		gp2x_sound_play();
	}
	return 0;
}
*/
// Interrupt driven callback from the sound buffer code - well not quite...
int gp2x_sound_frame(void * userdata, void * streamIn, int lenIn)
{
	int success = 0;
	
	static int last = 0;
	unsigned char * stream = (unsigned char *) streamIn;
	int len=lenIn;

	int samplesAvailable;

	//EnterCriticalSection(&soundMutex);


	if (soundPlaying)
	{
		samplesAvailable = soundBufferRollingDistance(atariSoundBufferStart,atariSoundBufferEnd, SNDBUFSIZE);

		if (samplesAvailable>len)
		{
			if ((atariSoundBufferStart+len) < SNDBUFSIZE)
			{
				memcpy(stream, atariSoundBuffer+atariSoundBufferStart, len);
				atariSoundBufferStart+=len;
			}
			else
			{
				int remaining = SNDBUFSIZE - atariSoundBufferStart;
				int fromStart;
				memcpy(stream, atariSoundBuffer+atariSoundBufferStart, remaining);

				fromStart = len-remaining;
				if (fromStart)
				{
					memcpy(stream+remaining, atariSoundBuffer, fromStart);
				}
				atariSoundBufferStart = fromStart;
			}
	//	}
	//	else
	//	{
	//		memset(stream, last, len);
	//	}

			last = stream[len-1];

			// Store count of samples -> for external use in display status text
			soundBufferSamplesStored = samplesAvailable;

			success = 1;
		}
	}
	else
	{
		memset(streamIn, 0, lenIn);
	}

	//LeaveCriticalSection(&soundMutex);
	
//	debugText = debugTextBuffer;
//	sprintf(debugTextBuffer,"%4d           ", soundBufferSamplesStored);
	
//	if (soundBufferSamplesStored < 500)
//		sprintf(debugTextBuffer+6, "ALERT");
//

	return success;
}
