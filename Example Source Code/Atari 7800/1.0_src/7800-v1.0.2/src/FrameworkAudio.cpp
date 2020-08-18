

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <mmsystem.h>
//#include "KGSDK.h"
#include "frameworkAudio.h"

#define NUM_BUFFERS	(16)
#define MAX_FREQ	(44100)

static unsigned char soundBuffer[(MAX_FREQ*4)*NUM_BUFFERS];
static volatile int currentSoundBank=0;
static WAVEHDR wavebuf;
static HWAVEOUT sound = NULL;
static short *SoundBanks[NUM_BUFFERS];
static int bufferSize=0;

int FrameworkAudio_GetCurrentBank(void)
{
	MMTIME time;
	time.wType = TIME_BYTES;
	waveOutGetPosition(sound,&time,sizeof(time));
	return (time.u.cb/(bufferSize))&15;
}

short *FrameworkAudio_GetAudioBank(int bank)
{
	if ((bank<0)||(bank>NUM_BUFFERS)) return SoundBanks[0];

	return SoundBanks[bank];

}


int FrameworkAudio_Init(int rate, int stereo, int hz)
{
	MMRESULT result;
	WAVEFORMATEX waveformat;
	int bank=0;

	//stereo = 1;
	//rate = 44100;

	bufferSize = (rate/hz)<<(/*1+*/stereo);

	int i=0;

	if (rate > 44100)
	{
		return 1;
	}

	sound = NULL;

	memset(&soundBuffer,0,(MAX_FREQ*4)*NUM_BUFFERS);

	memset(&waveformat,0,sizeof(waveformat));
	waveformat.wFormatTag = WAVE_FORMAT_PCM;
	waveformat.nSamplesPerSec = rate;
	waveformat.wBitsPerSample = 8;
	waveformat.nChannels = (stereo==1?2:1);
	waveformat.nBlockAlign =
		waveformat.nChannels * (waveformat.wBitsPerSample/8);
	waveformat.nAvgBytesPerSec = 
		waveformat.nSamplesPerSec * waveformat.nBlockAlign;

	result = waveOutOpen(&sound,WAVE_MAPPER, &waveformat,
			0, 0, CALLBACK_NULL);
	if ( result != MMSYSERR_NOERROR ) {
		return(2);
	}

	for ( i = 0; i < NUM_BUFFERS; ++i ) {
		SoundBanks[i] = (short*)&soundBuffer[i*bufferSize];
	}	


	memset(&wavebuf, 0, sizeof(wavebuf));

	wavebuf.lpData = (LPSTR) &soundBuffer[0];
	wavebuf.dwBufferLength = bufferSize * NUM_BUFFERS;
	wavebuf.dwFlags = WHDR_BEGINLOOP | WHDR_ENDLOOP | WHDR_DONE;
	
	result = waveOutPrepareHeader(sound, &wavebuf,sizeof(wavebuf));
		if ( result != MMSYSERR_NOERROR ) {
			return(3);
		}

	wavebuf.dwLoops = 0xFFFFFFFF;
	result = waveOutWrite(sound, &wavebuf, sizeof(wavebuf));
	if ( result != MMSYSERR_NOERROR ) {
			return(result);
		}
	


	return 0;

}

void FrameworkAudio_Close(void)
{
	int bank=0;
	if (sound==NULL) return;  // no sound ref so we have not been inited
	
	waveOutBreakLoop(sound);
	while(!(wavebuf.dwFlags&WHDR_DONE))
	{
		Sleep(50);
	}
	waveOutUnprepareHeader(sound, &wavebuf,sizeof(wavebuf));

	waveOutClose(sound);
	sound = NULL;
}

void FrameworkAudio_SetVolume(int rightVolume, int leftVolume)
{
	if (sound==NULL) return;  // no sound ref so we have not been inited
	
	if(rightVolume<0) rightVolume =0;
	if(rightVolume>100) rightVolume = 100;
	if(leftVolume<0) leftVolume =0;
	if(leftVolume>100) leftVolume = 100;

	leftVolume*=655;
	rightVolume*=655;
	DWORD l=leftVolume|(rightVolume<<16);
	waveOutSetVolume(sound,l);

}

void FrameworkAudio_GetVolume(int *rightVolume, int *leftVolume)
{
	*rightVolume = 0;
	*leftVolume = 0;
	if (sound==NULL) return;  // no sound ref so we have not been inited
	
	DWORD l=0;
	waveOutGetVolume(sound,&l);

	*leftVolume = (l&0xffff)/655;
	*rightVolume = ((l>>16)&0xffff)/655;
}
