/*

File:			Framework2D.h
Description:	Frameword2D header file.

Copyright (c) Gizmondo Europe Ltd. All rights reserved.

*/

#ifndef _FRAMEWORK2D_H
#define _FRAMEWORK2D_H

#ifdef __cplusplus
extern "C" {
#endif

#include "KGSDK.h"

//----------------------------------------------------------------------------------------------------------------------------

DECLSPEC int  Framework2D_Init			();
DECLSPEC void Framework2D_Close			();
DECLSPEC void Framework2D_WaitVSync		();
DECLSPEC int  Framework2D_Flip			();
DECLSPEC void Framework2D_DrawText		(TCHAR *pString, int iXPos, int iYPos, unsigned int colour);
DECLSPEC void *Framework2D_LockBuffer	(int isPrimary);
DECLSPEC void Framework2D_UnlockBuffer	();

//----------------------------------------------------------------------------------------------------------------------------

/* Ends C function definitions when using C++ */
#ifdef __cplusplus
}
#endif


#endif // _FRAMEWORK2D_H


