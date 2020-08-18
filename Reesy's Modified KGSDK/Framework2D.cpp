/*

File:			Framework2D.cpp
Description:	Basic shared framework for setting up the DirectDraw interface
				for doing 2D work.

Copyright (c) Gizmondo Europe Ltd. All rights reserved.

*/
#include <windows.h>
#include <ddraw.h>
#include "KGSDK.h"
#include "framework.h"
#include "framework2D.h"

//-------------------------------------------------------------------------------------------------------------------------------------

static int					 Framework2D_Initialised = 0;
static int					 Framework2D_WhichLocked = 0; /* 1 for primary, 2 for secondary */
static IDirectDraw4			*Framework2D_DirectDraw = NULL;
static IDirectDrawSurface5	*Framework2D_PrimarySurface = NULL;
static IDirectDrawSurface5	*Framework2D_BackBuffer = NULL;
//-------------------------------------------------------------------------------------------------------------------------------------

int Framework2D_Init()
{
	IDirectDraw			*tempDirectDraw;
	IDirectDrawSurface4 *tempSurface4;
	DDSURFACEDESC2 desc;
	HWND hWndApp;
	HRESULT hr;

	if (Framework2D_Initialised)
		return 1;

	hWndApp = Framework_GethWnd();
	if (!hWndApp)
		return 0;

	DirectDrawCreate(NULL, &tempDirectDraw, NULL);
	tempDirectDraw->QueryInterface(IID_IDirectDraw4, (void**)&Framework2D_DirectDraw);
	tempDirectDraw->Release();


	
	hr = Framework2D_DirectDraw->SetCooperativeLevel(hWndApp, DDSCL_EXCLUSIVE | DDSCL_FULLSCREEN);
	//hr = Framework2D_DirectDraw->SetCooperativeLevel(hWndApp, DDSCL_NORMAL);
	if(hr != DD_OK) 
	{
		return 0;
	}

	/*hr = Framework2D_DirectDraw->SetDisplayMode(314,240,16,0,0);
	if(hr != DD_OK) 
	{
		return 0;
	}*/

	/*ZeroMemory(&desc, sizeof(desc));
	desc.dwSize = sizeof(desc);
	desc.dwFlags = DDSD_CAPS;
	desc.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;
	hr = Framework2D_DirectDraw->CreateSurface(&desc, &tempSurface4, NULL);
	if(hr != DD_OK) 
	{
		return 0;
	}
	tempSurface4->QueryInterface(IID_IDirectDrawSurface5, (void**)&Framework2D_PrimarySurface);
	tempSurface4->Release();

	ZeroMemory(&desc, sizeof(desc));
	desc.dwSize = sizeof(desc);
	desc.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;
	desc.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;
	desc.dwWidth = 320;
	desc.dwHeight = 240;
	hr = Framework2D_DirectDraw->CreateSurface(&desc, &tempSurface4, NULL);
	if(hr != DD_OK) 
	{
		return 0;
	}
	tempSurface4->QueryInterface(IID_IDirectDrawSurface5, (void**)&Framework2D_BackBuffer);
	tempSurface4->Release();*/

	
	ZeroMemory(&desc, sizeof(desc));
	desc.dwSize = sizeof(desc);
	desc.dwFlags = DDSD_CAPS | DDSD_BACKBUFFERCOUNT;
	desc.ddsCaps.dwCaps = DDSCAPS_STANDARDVGAMODE | DDSCAPS_PRIMARYSURFACE |
			DDSCAPS_FLIP | DDSCAPS_COMPLEX | DDSCAPS_VIDEOMEMORY;
	desc.dwBackBufferCount = 1;

	hr = Framework2D_DirectDraw->CreateSurface(&desc, &tempSurface4, NULL);
	if(hr != DD_OK) 
	{
		FILE *log = fopen("\\sd card\\log.txt", "ab");
		fprintf(log, "CreateSurface returned %08x (%i)\r\n", hr, hr & 0xffff);
		fclose(log);
		return 0;
	}
	tempSurface4->QueryInterface(IID_IDirectDrawSurface5, (void**)&Framework2D_PrimarySurface);
	tempSurface4->Release();

	//Framework2D_PrimarySurface->GetDC
	desc.ddsCaps.dwCaps = DDSCAPS_BACKBUFFER;
	hr = Framework2D_PrimarySurface->GetAttachedSurface(&desc.ddsCaps, &Framework2D_BackBuffer);
	if(hr != DD_OK) 
	{
		FILE *log = fopen("\\sd card\\log.txt", "ab");
		fprintf(log, "GetAttachedSurface returned %08x (%i)\r\n", hr, hr & 0xffff);
		fclose(log);
		return 0;
	}

	Framework2D_Initialised = 1;

	Sleep(1000);
	Framework_SetFocus();

	return 1;
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

	Framework2D_Initialised = 0;
}


//-------------------------------------------------------------------------------------------------------------------------------------

void Framework2D_WaitVSync()
{
	Framework2D_DirectDraw->WaitForVerticalBlank(DDWAITVB_BLOCKBEGIN, NULL);
}

//-------------------------------------------------------------------------------------------------------------------------------------

int Framework2D_Flip()
{
	/* doesn't seem to do vsync */
	return Framework2D_PrimarySurface->Flip(NULL, 0);
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

void *Framework2D_LockBuffer(int isPrimary)
{
	DDSURFACEDESC2 desc;

	if (Framework2D_WhichLocked)
		Framework2D_UnlockBuffer();
	
	if (isPrimary)
	{
		Framework2D_PrimarySurface->Lock(NULL, &desc, 0/*DDLOCK_WRITEONLY*/, NULL);
		Framework2D_WhichLocked = 1;
	}
	else
	{
		Framework2D_BackBuffer->Lock(NULL, &desc, 0/*DDLOCK_WRITEONLY*/, NULL);
		Framework2D_WhichLocked = 2;
	}

	return desc.lpSurface;
}


//-------------------------------------------------------------------------------------------------------------------------------------

void Framework2D_UnlockBuffer()
{
	if (Framework2D_WhichLocked == 1)
		Framework2D_PrimarySurface->Unlock(NULL);
	else if (Framework2D_WhichLocked == 2)
		Framework2D_BackBuffer->Unlock(NULL);
	Framework2D_WhichLocked = 0;
}
