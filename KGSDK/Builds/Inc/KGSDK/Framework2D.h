/*

File:			Framework2D.h
Description:	Frameword2D header file.

Copyright (c) Gizmondo Europe Ltd. All rights reserved.

*/

#ifndef _FRAMEWORK2D_H
#define _FRAMEWORK2D_H


//----------------------------------------------------------------------------------------------------------------------------

bool Framework2D_Init			();
void Framework2D_Close			();

void Framework2D_Begin			(bool clear = true);
void Framework2D_End			(bool waitforvync = true);
void Framework2D_DrawText		(TCHAR *pString, int iXPos, int iYPos, unsigned int colour = 0x00ffffff);
void *Framework2D_LockBuffer	();
void Framework2D_UnlockBuffer	();

//----------------------------------------------------------------------------------------------------------------------------


#endif // _FRAMEWORKGL_H