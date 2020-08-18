
#ifndef _FRAMEWORKAUDIO_H
#define _FRAMEWORKAUDIO_H

#ifdef __cplusplus
extern "C" {
#endif

//#include "KGSDK.h"

int FrameworkAudio_Init(int rate, int stereo, int hz);
int FrameworkAudio_GetCurrentBank(void);
short *FrameworkAudio_GetAudioBank(int bank);
void FrameworkAudio_Close(void);
void FrameworkAudio_SetVolume(int rightVolume, int leftVolume);
void FrameworkAudio_GetVolume(int *rightVolume, int *leftVolume);

/* Ends C function definitions when using C++ */
#ifdef __cplusplus
}
#endif


#endif // _FRAMEWORKAUDIO_H