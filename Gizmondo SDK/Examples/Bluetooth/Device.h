
#ifndef _DEVICE_H
#define _DEVICE_H

//-------------------------------------------------------------------------------------------------

#include <windows.h>

//-------------------------------------------------------------------------------------------------

#define	DEVICE_SCREENWIDTH	320
#define	DEVICE_SCREENHEIGHT	240

#define DEVICE_KEY_UP		1
#define DEVICE_KEY_DOWN		2
#define DEVICE_KEY_LEFT		4
#define DEVICE_KEY_RIGHT	8
#define DEVICE_KEY_PLAY		16
#define DEVICE_KEY_STOP		32

void *Device_BackBufferLock();
void Device_BackBufferUnlock();
void Device_DrawText(unsigned short *pString, int iXPos, int iYPos);

int Device_GetKeyStatus();
int Device_GetKeyStatusDebounced();

//-------------------------------------------------------------------------------------------------

#endif
