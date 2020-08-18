#include <stdlib.h>
#include <string.h>

#include "psp_sound.h"

int soundBufferSamplesStored = 0;

static int soundPlaying = 0;

//#define TIMESOUND

  /*wanted.freq     = 44100;
  wanted.format   = AUDIO_S8;
  wanted.channels = 1;
  */

#define SNDBUFSIZE 4096

static unsigned char * atariSoundBuffer = 0;
static int atariSoundBufferStart = 0;
static int atariSoundBufferEnd = 0;

//////////////////////////////////////////////////////////////////////////
// Forward declarations of some internal functions
static int soundBufferRollingDistance(int start, int end, int length);

//////////////////////////////////////////////////////////////////////////
// Functions called externally by the emulator code...
//FILE * soundlog = 0;
int psp_sound_init()
{
//	soundlog = fopen("\\SD Card\\ProSystem_Giz_Opt\\sound.log","w");

	atariSoundBuffer = (char *)malloc(SNDBUFSIZE);
	gp2x_sound_init(44100,8,0);

	return 1;
}

void psp_sound_pause(void)
{
	if (!soundPlaying)
		return;

	gp2x_sound_play(0);

	soundPlaying = 0;
}

void psp_sound_resume(void)
{
	if (soundPlaying)
		return;

	soundPlaying = 1;	
}

void Sound_Exit(void)
{
	psp_sound_pause();
}


void 
sound_Resample(const unsigned char* source, unsigned char* target, int length);

unsigned char pokey_buffer[624/*POKEY_BUFFER_SIZE*/] = {0};
unsigned char tia_buffer[624/*TIA_BUFFER_SIZE*/] = {0};

int cartridge_pokey;

unsigned short prosystem_frequency = 80;

void
Sound_process(unsigned char * sample, int length) 
{
  sound_Resample(tia_buffer, sample, length);

  if(cartridge_pokey) {
    unsigned char pokeySample[SNDBUFSIZE];
	int index;
    sound_Resample(pokey_buffer, pokeySample, length);
    for(index = 0; index < length; index++) {
      sample[index] = (sample[index] + pokeySample[index]) / 2;
    }
  }
}
 
 FILE * timelog;

void sound_Store()
{
	if (soundPlaying)
	{
		int bytesToGet = 0;
		int bytesLeft = 0;
		int spaceLeft;
			
		// Fill buffer
		bytesLeft = soundBufferRollingDistance(atariSoundBufferStart, atariSoundBufferEnd, SNDBUFSIZE);

		bytesToGet = 44100/prosystem_frequency;

		spaceLeft = SNDBUFSIZE-bytesLeft;

		//fprintf(soundlog, "tick:%d BytesToGet:%d SpaceLeft:%d\n", Perf_GetTicks(), bytesToGet, spaceLeft);

		if (spaceLeft < (SNDBUFSIZE/2)) // filling up
		{
			bytesToGet = bytesToGet-2; 
		}
		else if (bytesLeft < (SNDBUFSIZE/2)) // running low
		{
			bytesToGet = bytesToGet+2; 
		}

		if (bytesToGet > spaceLeft) // not enough room
		{
			bytesToGet = spaceLeft-1;
		}

		fprintf(timelog, "Sound from emu:%d\n", bytesToGet);

		bytesToGet&=0xfffffff8;

		//fprintf(soundlog, "tick:%d Fetching:%d\n", Perf_GetTicks(), bytesToGet);
			
		if (bytesToGet > 0) 
		{
			if ((atariSoundBufferEnd + bytesToGet) > SNDBUFSIZE) //overflow
			{
				char tempbuffer[SNDBUFSIZE];
				int remaining = SNDBUFSIZE - atariSoundBufferEnd;
				Sound_process(tempbuffer, bytesToGet);
				memcpy(atariSoundBuffer+atariSoundBufferEnd, tempbuffer, remaining);
				//Pokey_process(atariSoundBuffer + atariSoundBufferEnd, remaining);
				memcpy(atariSoundBuffer, tempbuffer+remaining, bytesToGet-remaining);
				//Pokey_process(atariSoundBuffer, bytesToGet-remaining);
				atariSoundBufferEnd = bytesToGet-remaining;
			}
			else
			{
				Sound_process(atariSoundBuffer + atariSoundBufferEnd, bytesToGet);
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

// Interrupt driven callback from the sound buffer code - well not quite...
int gp2x_sound_frame(void * userdata, void * streamIn, int lenIn)
{
	int success = 0;
	
	static int last = 0;
	unsigned char * stream = (unsigned char *) streamIn;
	int len=lenIn;

	int samplesAvailable;

	if (soundPlaying)
	{
		samplesAvailable = soundBufferRollingDistance(atariSoundBufferStart,atariSoundBufferEnd, SNDBUFSIZE);

		//fprintf(soundlog, "tick:%d Available:%d Len:%d\n", Perf_GetTicks(), samplesAvailable, lenIn);

		if (samplesAvailable>len)
		{
			fprintf(timelog, "Soundgrab:%d Avail:%d\n", len, samplesAvailable);

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

			last = stream[len-1];

			// Store count of samples -> for external use in display status text
			soundBufferSamplesStored = samplesAvailable;

			success = 1;
		}
		else
		{
			memset(streamIn, 0, lenIn);
			//fprintf(soundlog, "tick:%d Not enough samples\n");
		}
	}
	else
	{
		memset(streamIn, 0, lenIn);
	}

	return success;
}
