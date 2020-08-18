#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <mmsystem.h>
#include "KGSDK.h"
#include "frameworkAudio.h"


static unsigned char soundBuffer[0xf000]; // 44100/50*16*2*2 + some more for possible small overflows
static WAVEHDR wavebuf;
static HWAVEOUT sound = NULL;


short *FrameworkAudio_56448Buffer(void)
{
	return (short *) soundBuffer;
}


//int FrameworkAudio_Init(int rate, int len, int stereo)
int FrameworkAudio_Init(int rate, int buff_samples, int stereo)
{
	MMRESULT result;
	WAVEFORMATEX waveformat;

	sound = NULL;
	memset(&soundBuffer, 0, sizeof(soundBuffer));

	memset(&waveformat,0,sizeof(waveformat));
	waveformat.wFormatTag = WAVE_FORMAT_PCM;
	waveformat.nSamplesPerSec = rate;
	waveformat.wBitsPerSample = 16;
	waveformat.nChannels = (stereo?2:1);
	waveformat.nBlockAlign =
		waveformat.nChannels * (waveformat.wBitsPerSample/8);
	waveformat.nAvgBytesPerSec = 
		waveformat.nSamplesPerSec * waveformat.nBlockAlign;

	result = waveOutOpen(&sound,WAVE_MAPPER, &waveformat,
			0, 0, CALLBACK_NULL);
	if ( result != MMSYSERR_NOERROR )
		return result;

	memset(&wavebuf, 0, sizeof(wavebuf));
	wavebuf.lpData = (LPSTR) &soundBuffer[0];
	wavebuf.dwBufferLength = buff_samples*2;

	if (wavebuf.dwBufferLength > sizeof(soundBuffer))
		return -1;
	
	result = waveOutPrepareHeader(sound, &wavebuf,sizeof(wavebuf));
	if ( result != MMSYSERR_NOERROR )
		return result;

	wavebuf.dwFlags |= WHDR_BEGINLOOP | WHDR_ENDLOOP;
	wavebuf.dwLoops = 0xFFFFFFFF;
	result = waveOutWrite(sound, &wavebuf, sizeof(wavebuf));
	if ( result != MMSYSERR_NOERROR )
		return result;

	/* try to compensate audio/sys timer skew */
	result = waveOutSetPlaybackRate(sound, 0xfcb0);
	if ( result != MMSYSERR_NOERROR )
		return result;

	return 0;

}

int FrameworkAudio_BufferPos(void)
{
	MMRESULT result;
	MMTIME time;
	time.wType = TIME_BYTES; // only TIME_BYTES seems to be supported
	result = waveOutGetPosition(sound, &time, sizeof(time));
	if (result != MMSYSERR_NOERROR) time.u.cb = (DWORD) -1;
	return time.u.cb;
}

int FrameworkAudio_SetPause(int is_pause)
{
	if (is_pause)
	{
		return waveOutPause(sound);
	}
	else
	{
		return waveOutRestart(sound);
	}
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

