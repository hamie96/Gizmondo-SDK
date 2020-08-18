/*
 * sound.c - WinCE port specific code
 *
 * Copyright (C) 2000 Krzysztof Nikiel
 * Copyright (C) 2000-2006 Atari800 development team (see DOC/CREDITS)
 *
 * This file is part of the Atari800 emulator project which emulates
 * the Atari 400, 800, 800XL, 130XE, and 5200 8-bit computers.
 *
 * Atari800 is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Atari800 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Atari800; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

//#include "config.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "FrameworkAudio.h"

/*int FrameworkAudio_Init(int rate, int stereo, int hz);
int FrameworkAudio_GetCurrentBank(void);
short *FrameworkAudio_GetAudioBank(int bank);
void FrameworkAudio_Close(void);
void FrameworkAudio_SetVolume(int rightVolume, int leftVolume);*/

//int pos=0;
//char buffer[1024];

int nextBuffer = 0;
void gp2x_sound_play(int on)
{
	int len = (int)FrameworkAudio_GetAudioBank(1)-(int)FrameworkAudio_GetAudioBank(0);

	if (!on)
	{
		memset(FrameworkAudio_GetAudioBank(0), 0, len*16);
		return;
	}

	while (1)
	{
		int playing = FrameworkAudio_GetCurrentBank();
		if (playing<0)
			playing+=16;
		//buffer[pos++] = playing;
		//if (pos>1000)
		//	pos = 0; 

		if (playing == nextBuffer)
			return;
		else
		{
			unsigned short * bank = FrameworkAudio_GetAudioBank(nextBuffer);
			nextBuffer++;
			if (nextBuffer==16)
				nextBuffer = 0;

			gp2x_sound_frame(0, bank, len);
		}
	}
}

void gp2x_sound_init(int dsprate, int bits, int stereo)
{
	FrameworkAudio_Init(dsprate, stereo, 60);
	//FrameworkAudio_SetVolume(50,50);
}

/*
//#define WAVSHIFT	11
//#define WAVSIZE		(1 << WAVSHIFT)
int buffers = 0;

enum {SOUND_NONE, SOUND_WAV};

static int issound = SOUND_NONE;
//static int snddelaywav = 20;

static HWAVEOUT wout;
static WAVEHDR *waves; 

static HANDLE event;

void moreSoundData()
{
  WAVEHDR *wh;
  int i;

  if (issound == SOUND_WAV)
  {
	for (i=0; i<buffers; i++)
		if (waves[i].dwFlags & WHDR_DONE)
		{
			wh = &waves[i];
			//int gp2x_sound_frame(void * userdata, void * streamIn, int lenIn)
			gp2x_sound_frame(0, wh->lpData, wh->dwBufferLength);
			waveOutWrite(wout, wh, sizeof(*wh));
		}
  }
}

void gp2x_sound_play()
{
	WaitForSingleObject(event, INFINITE);
	moreSoundData();
}

void gp2x_sound_init(int dsprate, int bits, int channels)
{
	int length;
  int i;
  WAVEFORMATEX wf;
  MMRESULT err;

  event = CreateEvent(NULL, FALSE, FALSE, NULL);

  memset(&wf, 0, sizeof(wf));

  wf.wFormatTag = WAVE_FORMAT_PCM;
  wf.nChannels = channels;
  wf.nSamplesPerSec = dsprate;
  wf.nAvgBytesPerSec = dsprate * wf.nChannels;
  wf.nBlockAlign = 2;
  wf.wBitsPerSample = bits;
  wf.cbSize = 0;

  err = waveOutOpen(&wout, WAVE_MAPPER, &wf, event, 0, CALLBACK_EVENT);
  if (err == WAVERR_BADFORMAT)
    {
      Aprint("wave output parameters unsupported\n");
      return 1;
    }
  if (err != MMSYSERR_NOERROR)
    {
      Aprint("cannot open wave output (%x)\n", err);
      return 1;
    }

  waveOutSetVolume(wout, 0xffffffff);
 
  //22000 00 / 1000 => 2200>>9 
  buffers = 4; //((wf.nAvgBytesPerSec * snddelaywav / 1000) >> WAVSHIFT) + 1;
  length = 1024; //1024*8/4 -> 2048 -> 50ms
  waves = malloc(buffers * sizeof(*waves));
  for (i = 0; i < buffers; i++)
    {
      memset(&waves[i], 0, sizeof (waves[i]));
      if (!(waves[i].lpData = (uint8 *)malloc(length)))
	{
	  Aprint("could not get wave buffer memory\n");
	  return 1;
	}
      waves[i].dwBufferLength = length;
      err = waveOutPrepareHeader(wout, &waves[i], sizeof(waves[i]));
      if (err != MMSYSERR_NOERROR)
	{
	  Aprint("cannot prepare wave header (%x)\n", err);
	  return 1;
	}
	  memset(waves[i].lpData, 0, length);	// kill clicking sounds at startup
      waves[i].dwFlags |= WHDR_DONE;
    }

  issound = SOUND_WAV;
  moreSoundData();
  return 0;
}
*/