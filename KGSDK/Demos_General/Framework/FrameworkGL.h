/*

File:			FrameworkGL.h
Description:	FrameworkGL header file.

Copyright (c) Gizmondo Europe Ltd. All rights reserved.

*/

#ifndef _FRAMEWORKGL_H
#define _FRAMEWORKGL_H

#include <GLES\egl.h>

//----------------------------------------------------------------------------------------------------------------------------

bool		FrameworkGL_Init				();
void		FrameworkGL_Close				();
void		FrameworkGL_CheckForGLError		();
void		FrameworkGL_CheckForEGLError	();
EGLDisplay	FrameworkGL_GetDisplay			();
EGLSurface	FrameworkGL_GetSurface			();

//----------------------------------------------------------------------------------------------------------------------------


#endif // _FRAMEWORKGL_H