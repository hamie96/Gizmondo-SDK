
#ifndef _FRAMEWORKAUDIO_H
#define _FRAMEWORKAUDIO_H

#ifdef __cplusplus
extern "C" {
#endif

#include "KGSDK.h"

DECLSPEC int    FrameworkAudio_Init(int rate, int buff_samples, int stereo);
DECLSPEC short *FrameworkAudio_56448Buffer(void);
DECLSPEC int    FrameworkAudio_BufferPos(void);
DECLSPEC void   FrameworkAudio_Close(void);
DECLSPEC int    FrameworkAudio_SetPause(int is_pause);
DECLSPEC void   FrameworkAudio_SetVolume(int rightVolume, int leftVolume);

/* Ends C function definitions when using C++ */
#ifdef __cplusplus
}
#endif


#endif // _FRAMEWORKAUDIO_H
