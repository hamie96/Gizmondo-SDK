/*

File:			FrameworkGL.cpp
Description:	Basic shared framework for setting up the OpenGL interface
				for 3D applications

Copyright (c) Gizmondo Europe Ltd. All rights reserved.

*/

#include <windows.h>
#include <assert.h>
#include <gles\egl.h>
#include <gles\egltypes.h>
#include <gles\gl.h>
#include <gles\glext.h>
#include "framework.h"

static bool			FrameworkGL_Initialised = false;
static EGLDisplay	FrameworkGL_Display;
static EGLConfig    FrameworkGL_Config;
static EGLContext   FrameworkGL_Context;
static EGLSurface   FrameworkGL_WindowSurface;


//----------------------------------------------------------------------------------------------------------------------------

void FrameworkGL_CheckForGLError()
{
	GLenum glerr = glGetError();

	assert(glerr == GL_NO_ERROR);
}


//----------------------------------------------------------------------------------------------------------------------------

void FrameworkGL_CheckForEGLError()
{
	EGLint eglerr = eglGetError();

	assert(eglerr == EGL_SUCCESS);
}


//----------------------------------------------------------------------------------------------------------------------------

bool FrameworkGL_Init()
{
	EGLint configAttribs[] =
	{
		EGL_ALPHA_SIZE,     0,
		EGL_RED_SIZE,		5,
		EGL_GREEN_SIZE,     6,
		EGL_BLUE_SIZE,		5,
		EGL_DEPTH_SIZE,     16,
		EGL_STENCIL_SIZE,   EGL_DONT_CARE,
		EGL_SURFACE_TYPE,   EGL_PBUFFER_BIT,
		EGL_NONE
	};

	const GLubyte *vendor;
	const GLubyte *renderer;
	const GLubyte *version;
	const GLubyte *extensions;
	EGLint numConfigs;
	EGLint majorVersion;
	EGLint minorVersion;
	HWND   hWndApp;

	if (FrameworkGL_Initialised)
		return true;

	hWndApp = Framework_GethWnd();
	if (!hWndApp)
		return false;

	FrameworkGL_Display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
	FrameworkGL_CheckForEGLError();

	eglInitialize(FrameworkGL_Display, &majorVersion, &minorVersion);
	FrameworkGL_CheckForEGLError();

	eglGetConfigs(FrameworkGL_Display, NULL, 0, &numConfigs);
	FrameworkGL_CheckForEGLError();

	eglChooseConfig(FrameworkGL_Display, configAttribs, &FrameworkGL_Config, 1, &numConfigs);
	FrameworkGL_CheckForEGLError();

	FrameworkGL_Context = eglCreateContext(FrameworkGL_Display, FrameworkGL_Config, EGL_NO_CONTEXT, NULL);
	FrameworkGL_CheckForEGLError();

	FrameworkGL_WindowSurface = eglCreateWindowSurface(FrameworkGL_Display, FrameworkGL_Config, hWndApp, NULL);
	FrameworkGL_CheckForEGLError();

	eglMakeCurrent(FrameworkGL_Display, FrameworkGL_WindowSurface, FrameworkGL_WindowSurface, FrameworkGL_Context);
	FrameworkGL_CheckForEGLError();

	vendor = glGetString(GL_VENDOR);
	FrameworkGL_CheckForGLError();

	renderer = glGetString(GL_RENDERER);
	FrameworkGL_CheckForGLError();

	version = glGetString(GL_VERSION);
	FrameworkGL_CheckForGLError();

	extensions = glGetString(GL_EXTENSIONS);
	FrameworkGL_CheckForGLError();

	glDisable(GL_ALPHA_TEST);
	glDisable(GL_BLEND);
	glDisable(GL_COLOR_LOGIC_OP);
	glDisable(GL_COLOR_MATERIAL);
	glEnable (GL_CULL_FACE);
	glEnable (GL_DEPTH_TEST);
	glEnable (GL_DITHER);
	glDisable(GL_FOG);
	glDisable(GL_LIGHTING);
	glDisable(GL_LINE_SMOOTH);
	glDisable(GL_MULTISAMPLE);
	glDisable(GL_NORMALIZE);
	glDisable(GL_POINT_SMOOTH);
	glDisable(GL_POLYGON_OFFSET_FILL);
	glDisable(GL_RESCALE_NORMAL);
	glDisable(GL_SAMPLE_ALPHA_TO_COVERAGE);
	glDisable(GL_SAMPLE_ALPHA_TO_ONE);
	glDisable(GL_SAMPLE_COVERAGE);
	glDisable(GL_SCISSOR_TEST);
	glDisable(GL_STENCIL_TEST);
	glDisable(GL_TEXTURE_2D);
	glCullFace(GL_FRONT);
	glDepthFunc(GL_LEQUAL);
	glDepthMask(GL_TRUE);
	glDepthRangef(0.0f, 1.0f);

	glTexEnvf(GL_TEXTURE_FILTER_CONTROL_EXT, GL_TEXTURE_LOD_BIAS_EXT, 1.0f);

	FrameworkGL_Initialised = true;

	return true;
}


//----------------------------------------------------------------------------------------------------------------------------

void FrameworkGL_Close()
{
	if (!FrameworkGL_Initialised)
		return;

	eglDestroyContext( FrameworkGL_Display, FrameworkGL_Context );
	eglDestroySurface( FrameworkGL_Display, FrameworkGL_WindowSurface );
    eglTerminate     ( FrameworkGL_Display );

	FrameworkGL_Initialised = false;
}


//----------------------------------------------------------------------------------------------------------------------------

EGLDisplay FrameworkGL_GetDisplay()
{
	return FrameworkGL_Display;
}


//----------------------------------------------------------------------------------------------------------------------------

EGLSurface FrameworkGL_GetSurface()
{
	return FrameworkGL_WindowSurface;
}