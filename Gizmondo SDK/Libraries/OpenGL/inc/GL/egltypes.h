/* Copyright 2004, NVIDIA corporation.  All rights reserved.

   NVIDIA veneer edition of the egltypes.h
*/

#ifndef _EGLTYPES_H_
#define _EGLTYPES_H_

#if defined(_WIN32)
#define _EGL_WIN32
#endif

#ifdef _EGL_WIN32
#define WIN32_LEAN_AND_MEAN 1
#include <windows.h>
#undef WIN32_LEAN_AND_MEAN
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
** Types and resources
*/
typedef int EGLBoolean;
typedef int EGLint;

#ifdef _EGL_WIN32

typedef int EGLObjectID;
typedef EGLObjectID EGLSurface;
typedef EGLObjectID EGLContext;
typedef EGLObjectID EGLDisplay;
typedef EGLint EGLConfig;

typedef int NativeDisplayType;
typedef HWND NativeWindowType;
typedef HDC NativePixmapType;

#else

typedef struct _t_EGLSurface *EGLSurface;
typedef void *EGLContext;

typedef struct _EGL_DISPLAY *EGLDisplay;
typedef void *EGLConfig;

typedef struct _NATIVE_DISPLAY *NativeDisplayType;
typedef struct _NATIVE_WINDOW *NativeWindowType;
typedef void *NativePixmapType;

#endif

/*
** EGL and native handle values
*/
#define EGL_DEFAULT_DISPLAY ((NativeDisplayType) 0)
#define EGL_NO_CONTEXT ((EGLContext)0)
#define EGL_NO_DISPLAY ((EGLDisplay)0)
#define EGL_NO_SURFACE ((EGLSurface)0)

/* -------------------- */
/* Closure interface -- fill in functionality that EGL left out. */

GLAPI EGLint APIENTRY eglDisplayWidthNV(EGLDisplay ed, EGLConfig ctx);
GLAPI EGLint APIENTRY eglDisplayHeightNV(EGLDisplay ed, EGLConfig ctx);

/*
** EGL extensions 
*/

/* EGL_NV_swap_control */
GLAPI EGLBoolean APIENTRY eglSwapIntervalNV(EGLint interval);
GLAPI EGLint APIENTRY eglGetSwapIntervalNV(void);

#ifdef __cplusplus
}
#endif

#endif  // #ifndef _EGLTYPES_H_
