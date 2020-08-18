#include <windows.h>
#include <assert.h>
#include <tchar.h>
#include <ddraw.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <malloc.h>

/**************************************************************/

#define CLASS_NAME _T("DDSampleClass")
#define WINDOW_NAME _T("DDSample")

#define	GLTEST_XRES		320
#define	GLTEST_YRES		240

/**************************************************************/

HWND main_hwnd;

/**************************************************************/

HRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	switch(message)
	{
	case WM_PAINT :
		{
			HDC hdc;
			PAINTSTRUCT ps;
			RECT rect;

			GetClientRect(main_hwnd, &rect);
			hdc = BeginPaint(main_hwnd, &ps);
			EndPaint(main_hwnd, &ps);
		}
	}
	return DefWindowProc(hwnd, message, wparam, lparam);
}

/**************************************************************/

BOOL InitApp(HINSTANCE me, int show)
{
	WNDCLASS wc;

	memset(&wc, 0, sizeof(wc));

	wc.hInstance = me;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.lpszClassName = CLASS_NAME;
	wc.lpfnWndProc = WindowProc;
	wc.hIcon = NULL;

	if(!RegisterClass(&wc))
		return FALSE;

	main_hwnd = CreateWindow(CLASS_NAME,
		WINDOW_NAME,
		WS_POPUP | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		GLTEST_XRES,
		GLTEST_YRES,
		NULL,
		NULL,
		me,
		NULL);

	if(!main_hwnd)
		return FALSE;

	ShowWindow(main_hwnd, show);
	UpdateWindow(main_hwnd);

	return TRUE;
}

/**************************************************************/

// Simple DirectDraw sample that create front and back buffers
// and blits the back buffer to the front.
// Better performance may be possible by setting up a flip chain,
// the implementation of this is left as an exercise for the reader.

void DirectDrawSample()
{
	IDirectDraw *pDDTemp;
	IDirectDraw4 *pDD;
	IDirectDrawSurface4 *pSurf4;
	IDirectDrawSurface5 *pPrimSurf, *pBackBuf;
	DDSURFACEDESC2 desc;

	// Create directdraw object
	DirectDrawCreate(NULL, &pDDTemp, NULL);
	// the basic DD object isn't that useful so query for DD4
	pDDTemp->QueryInterface(IID_IDirectDraw4, (void**)&pDD);
	pDDTemp->Release();

	// Go fullscreen
	pDD->SetCooperativeLevel(main_hwnd, DDSCL_EXCLUSIVE | DDSCL_FULLSCREEN);

	// Alloc front buffer
	ZeroMemory(&desc, sizeof(desc));
	desc.dwSize = sizeof(desc);
	desc.dwFlags = DDSD_CAPS;
	desc.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;
	pDD->CreateSurface(&desc, &pSurf4, NULL);

	// Get Surface5 interface for better functionality
	pSurf4->QueryInterface(IID_IDirectDrawSurface5, (void**)&pPrimSurf);
	pSurf4->Release();

	// Alloc back buffer
	ZeroMemory(&desc, sizeof(desc));
	desc.dwSize = sizeof(desc);
	desc.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;
	desc.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN;
	desc.dwWidth = 320;
	desc.dwHeight = 240;
	pDD->CreateSurface(&desc, &pSurf4, NULL);

	pSurf4->QueryInterface(IID_IDirectDrawSurface5, (void**)&pBackBuf);
	pSurf4->Release();

	// Lock back buffer
	pBackBuf->Lock(NULL, &desc, DDLOCK_WRITEONLY, NULL);

	// Draw code goes here, just a simple clear to black for now.
	// Note use of pitch not width*2 in case of padding.
	memset(desc.lpSurface, 0, desc.lPitch * desc.dwHeight);

	pBackBuf->Unlock(NULL);

	// Blit back buffer to front during vsync
	pDD->WaitForVerticalBlank(DDWAITVB_BLOCKBEGIN, NULL);
	pPrimSurf->BltFast(0, 0, pBackBuf, NULL, DDBLTFAST_NOCOLORKEY);

	// Cleanup
	pBackBuf->Release();
	pPrimSurf->Release();

	pDD->SetCooperativeLevel(main_hwnd, DDSCL_NORMAL);

	pDD->Release();
}

/**************************************************************/

int WINAPI WinMain(HINSTANCE me, HINSTANCE prev, LPTSTR cmdline, int showstate)
{
	if(!InitApp(me, showstate))
	{
		return 0;
	}

	DirectDrawSample();

	return 0;
}

