//-------------------------------------------------------------------------------------------------

#include <windows.h>
#include <assert.h>
#include <tchar.h>
#include <ddraw.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

#include "Gameloop.h"
#include "Device.h"

//-------------------------------------------------------------------------------------------------

#define CLASS_NAME _T("Bluetooth Test")
#define WINDOW_NAME _T("Bluetooth Test")

//-------------------------------------------------------------------------------------------------

static HWND s_hWndMain;
static IDirectDraw4 *s_pDD;
static IDirectDrawSurface5 *s_pPrimSurf;
static IDirectDrawSurface5 *s_pBackBuf;
static int s_iKeyStatus = 0;
static int s_iKeyStatusDebounced = 0;

//-------------------------------------------------------------------------------------------------

HRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
		case WM_PAINT :
		{
			HDC hdc;
			PAINTSTRUCT ps;
			RECT rect;

			GetClientRect(s_hWndMain, &rect);
			hdc = BeginPaint(s_hWndMain, &ps);
			EndPaint(s_hWndMain, &ps);
		}
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}

//-------------------------------------------------------------------------------------------------

BOOL InitApp(HINSTANCE hInstance, int nCmdShow)
{
	WNDCLASS wc;
	memset(&wc, 0, sizeof(wc));
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.lpszClassName = CLASS_NAME;
	wc.lpfnWndProc = WindowProc;
	wc.hIcon = NULL;

	if (!RegisterClass(&wc))
	{
		return FALSE;
	}

	s_hWndMain = CreateWindow(	CLASS_NAME,
								WINDOW_NAME,
								WS_POPUP | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
								CW_USEDEFAULT,
								CW_USEDEFAULT,
								DEVICE_SCREENWIDTH,
								DEVICE_SCREENWIDTH,
								NULL,
								NULL,
								hInstance,
								NULL);

	if (!s_hWndMain)
	{
		return FALSE;
	}

	ShowWindow(s_hWndMain, nCmdShow);
	UpdateWindow(s_hWndMain);

	return TRUE;
}

//-------------------------------------------------------------------------------------------------

void Device_Init()
{
	// Create directdraw object
	IDirectDraw *pDDTemp;
	DirectDrawCreate(NULL, &pDDTemp, NULL);
	pDDTemp->QueryInterface(IID_IDirectDraw4, (void**)&s_pDD);
	pDDTemp->Release();

	// Go fullscreen
	s_pDD->SetCooperativeLevel(s_hWndMain, DDSCL_EXCLUSIVE | DDSCL_FULLSCREEN);

	// Alloc front buffer
	IDirectDrawSurface4 *pSurf4;
	DDSURFACEDESC2 desc;
	ZeroMemory(&desc, sizeof(desc));
	desc.dwSize = sizeof(desc);
	desc.dwFlags = DDSD_CAPS;
	desc.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;
	s_pDD->CreateSurface(&desc, &pSurf4, NULL);
	pSurf4->QueryInterface(IID_IDirectDrawSurface5, (void**)&s_pPrimSurf);
	pSurf4->Release();

	// Alloc back buffer
	ZeroMemory(&desc, sizeof(desc));
	desc.dwSize = sizeof(desc);
	desc.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;
	desc.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN;
	desc.dwWidth = 320;
	desc.dwHeight = 240;
	s_pDD->CreateSurface(&desc, &pSurf4, NULL);
	pSurf4->QueryInterface(IID_IDirectDrawSurface5, (void**)&s_pBackBuf);
	pSurf4->Release();

	s_iKeyStatus = 0;
	s_iKeyStatusDebounced = 0;
}

//-------------------------------------------------------------------------------------------------

void Device_Exit()
{
	s_pBackBuf->Release();
	s_pPrimSurf->Release();
	s_pDD->SetCooperativeLevel(s_hWndMain, DDSCL_NORMAL);
	s_pDD->Release();
}

//-------------------------------------------------------------------------------------------------

void *Device_BackBufferLock()
{
	DDSURFACEDESC2 desc;
	s_pBackBuf->Lock(NULL, &desc, DDLOCK_WRITEONLY, NULL);

	return desc.lpSurface;
}

//-------------------------------------------------------------------------------------------------

void Device_BackBufferUnlock()
{
	s_pBackBuf->Unlock(NULL);
}

//-------------------------------------------------------------------------------------------------
//
// Blit back buffer to front during vsync
//

void Device_Flip()
{
	s_pDD->WaitForVerticalBlank(DDWAITVB_BLOCKBEGIN, NULL);
	s_pPrimSurf->BltFast(0, 0, s_pBackBuf, NULL, DDBLTFAST_NOCOLORKEY);
}

//-------------------------------------------------------------------------------------------------

void Device_DrawText(unsigned short *pString, int iXPos, int iYPos)
{
	HDC hdc;
	s_pBackBuf->GetDC(&hdc);

	SetBkMode(hdc, TRANSPARENT);
	SetTextColor(hdc, RGB(255,255,155));
	ExtTextOutW(hdc, iXPos, iYPos, 0, NULL, pString, wcslen(pString), NULL);

	s_pBackBuf->ReleaseDC(hdc);
}

//-------------------------------------------------------------------------------------------------

int Device_GetKeyStatus()
{
	return s_iKeyStatus;
}

//-------------------------------------------------------------------------------------------------

int Device_GetKeyStatusDebounced()
{
	return s_iKeyStatusDebounced;
}

//-------------------------------------------------------------------------------------------------

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	if (!InitApp(hInstance, nCmdShow))
	{
		return 0;
	}

	Device_Init();
	Gameloop_Init();

	bool bQuit = false;

	while (!bQuit)
	{
		MSG msg;
		if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if(msg.message == WM_QUIT)
				break;

			if (msg.message == WM_KEYDOWN)
			{
				switch (msg.wParam)
				{
					case VK_UP:
						s_iKeyStatus |= DEVICE_KEY_UP;
						s_iKeyStatusDebounced  |= DEVICE_KEY_UP;
						break;
					case VK_DOWN:
						s_iKeyStatus |= DEVICE_KEY_DOWN;
						s_iKeyStatusDebounced  |= DEVICE_KEY_DOWN;
						break;
					case VK_LEFT:
						s_iKeyStatus |= DEVICE_KEY_LEFT;
						s_iKeyStatusDebounced  |= DEVICE_KEY_LEFT;
						break;
					case VK_RIGHT:
						s_iKeyStatus |= DEVICE_KEY_RIGHT;
						s_iKeyStatusDebounced  |= DEVICE_KEY_RIGHT;
						break;
					case VK_RETURN:
						s_iKeyStatus |= DEVICE_KEY_PLAY;
						s_iKeyStatusDebounced  |= DEVICE_KEY_PLAY;
						break;
					case VK_CONTROL:
						s_iKeyStatus |= DEVICE_KEY_STOP;
						s_iKeyStatusDebounced  |= DEVICE_KEY_STOP;
						break;
				}
			}
			else if (msg.message == WM_KEYUP)
			{
				switch (msg.wParam)
				{
					case VK_UP:
						s_iKeyStatus &= ~DEVICE_KEY_UP;
						break;
					case VK_DOWN:
						s_iKeyStatus &= ~DEVICE_KEY_DOWN;
						break;
					case VK_LEFT:
						s_iKeyStatus &= ~DEVICE_KEY_LEFT;
						break;
					case VK_RIGHT:
						s_iKeyStatus &= ~DEVICE_KEY_RIGHT;
						break;
					case VK_RETURN:
						s_iKeyStatus &= ~DEVICE_KEY_PLAY;
						break;
					case VK_CONTROL:
						s_iKeyStatus &= ~DEVICE_KEY_STOP;
						break;
				}
			}

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			bQuit = Gameloop_Update();
			Gameloop_Render();
			Device_Flip();

			s_iKeyStatusDebounced = 0;
		}
	}

	Gameloop_Exit();
	Device_Exit();

	DestroyWindow(s_hWndMain);

	return 0;
}

//-------------------------------------------------------------------------------------------------
