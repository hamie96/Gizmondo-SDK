/*

File:			Framework2D.cpp
Description:	Basic shared framework for setting up the DirectDraw interface
				for doing 2D work.

Copyright (c) Gizmondo Europe Ltd. All rights reserved.

*/

#include <windows.h>
#include <ddraw.h>
#include "framework.h"
#include "framework2D.h"


//-------------------------------------------------------------------------------------------------------------------------------------

static bool					 Framework2D_Initialised = false;
static IDirectDraw4			*Framework2D_DirectDraw = NULL;
static IDirectDrawSurface5	*Framework2D_PrimarySurface = NULL;
static IDirectDrawSurface5	*Framework2D_BackBuffer = NULL;


//-------------------------------------------------------------------------------------------------------------------------------------

bool Framework2D_Init()
{
	IDirectDraw			*tempDirectDraw;
	IDirectDrawSurface4 *tempSurface4;
	DDSURFACEDESC2 desc;
	HWND hWndApp;
	HRESULT hr;

	if (Framework2D_Initialised)
		return true;

	hWndApp = Framework_GethWnd();
	if (!hWndApp)
		return false;

	DirectDrawCreate(NULL, &tempDirectDraw, NULL);
	tempDirectDraw->QueryInterface(IID_IDirectDraw4, (void**)&Framework2D_DirectDraw);
	tempDirectDraw->Release();

//	Framework2D_DirectDraw->SetCooperativeLevel(hWndApp, DDSCL_EXCLUSIVE | DDSCL_FULLSCREEN);
	Framework2D_DirectDraw->SetCooperativeLevel(hWndApp, DDSCL_NORMAL);

	ZeroMemory(&desc, sizeof(desc));
	desc.dwSize = sizeof(desc);
	desc.dwFlags = DDSD_CAPS;
	desc.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;
	hr = Framework2D_DirectDraw->CreateSurface(&desc, &tempSurface4, NULL);
	tempSurface4->QueryInterface(IID_IDirectDrawSurface5, (void**)&Framework2D_PrimarySurface);
	tempSurface4->Release();

	ZeroMemory(&desc, sizeof(desc));
	desc.dwSize = sizeof(desc);
	desc.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;
	desc.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN;
	desc.dwWidth = 320;
	desc.dwHeight = 240;
	Framework2D_DirectDraw->CreateSurface(&desc, &tempSurface4, NULL);
	tempSurface4->QueryInterface(IID_IDirectDrawSurface5, (void**)&Framework2D_BackBuffer);
	tempSurface4->Release();

	Framework2D_Initialised = true;

	return true;
}


//-------------------------------------------------------------------------------------------------------------------------------------

void Framework2D_Close()
{
	HWND hWndApp;

	if (!Framework2D_Initialised)
		return;

	hWndApp = Framework_GethWnd();

	Framework2D_BackBuffer->Release();
	Framework2D_PrimarySurface->Release();
	Framework2D_DirectDraw->Release();

	Framework2D_Initialised = false;
}


//-------------------------------------------------------------------------------------------------------------------------------------

void Framework2D_Begin(bool clear)
{
	void *backbuf;

	if (clear)
	{
		backbuf = Framework2D_LockBuffer();
		memset(backbuf, 0, 320*240*2);
		Framework2D_UnlockBuffer();
	}
}


//-------------------------------------------------------------------------------------------------------------------------------------

void Framework2D_End(bool waitforvsync)
{
	if (waitforvsync)
		Framework2D_DirectDraw->WaitForVerticalBlank(DDWAITVB_BLOCKBEGIN, NULL);

	Framework2D_PrimarySurface->BltFast(0, 0, Framework2D_BackBuffer, NULL, DDBLTFAST_NOCOLORKEY);
}


//-------------------------------------------------------------------------------------------------------------------------------------

void Framework2D_DrawText(TCHAR *pString, int iXPos, int iYPos, unsigned int colour)
{

	HDC hdc;
	Framework2D_BackBuffer->GetDC(&hdc);

	SetBkMode(hdc, TRANSPARENT);
	SetTextColor(hdc, colour);
	ExtTextOutW(hdc, iXPos, iYPos, 0, NULL, pString, wcslen(pString), NULL);

	Framework2D_BackBuffer->ReleaseDC(hdc);
}


//-------------------------------------------------------------------------------------------------------------------------------------

void *Framework2D_LockBuffer()
{

	DDSURFACEDESC2 desc;
	
	Framework2D_BackBuffer->Lock(NULL, &desc, DDLOCK_WRITEONLY, NULL);

	return desc.lpSurface;
}


//-------------------------------------------------------------------------------------------------------------------------------------

void Framework2D_UnlockBuffer()
{
	Framework2D_BackBuffer->Unlock(NULL);
}
