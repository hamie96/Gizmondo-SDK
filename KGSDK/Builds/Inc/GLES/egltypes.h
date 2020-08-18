/******************************************************************************

 @File         egltypes.h

 @Title        

 @Copyright    Copyright (C) 2000 - 2006 by Imagination Technologies Limited.

 @Platform     Windows XP/Windows CE/PocketPC

 @Description   Native egltypes.h as required by Khronos OpenGL ES egl.h

******************************************************************************/
#ifndef _egltypes_h_
#define _egltypes_h_

/* Types */
typedef int EGLBoolean;
#define EGL_FALSE 0
#define EGL_TRUE  1

/* An integer of at least 32 bits */
typedef int EGLint;

/* Resources */
typedef EGLint EGLDisplay;
typedef EGLint EGLConfig;
typedef struct _KEGL_SURFACE_ *EGLSurface;
typedef struct _KEGL_CONTEXT_ *EGLContext;

/* Windowing system: Windows */
#undef UNREFERENCED_PARAMETER
#include <windows.h>

typedef HDC   NativeDisplayType;
typedef HWND  NativeWindowType;
typedef void *NativePixmapType;

/* May need to export on some platforms */
#define GLAPI_EXT

/* EGL and native handle values */
#define EGL_DEFAULT_DISPLAY ((NativeDisplayType)0)
#define EGL_NO_CONTEXT ((EGLContext)0)
#define EGL_NO_DISPLAY ((EGLDisplay)0)
#define EGL_NO_SURFACE ((EGLSurface)0)

#endif
