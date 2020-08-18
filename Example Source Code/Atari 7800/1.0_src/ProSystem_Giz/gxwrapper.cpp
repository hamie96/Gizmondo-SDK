
#include <windows.h>
#include "gx.h"

HWND hWndMain;

static BOOL initwin(HINSTANCE hInstance, int nCmdShow)
{
        WNDCLASS wc;

        wc.style = CS_HREDRAW | CS_VREDRAW;
        wc.lpfnWndProc = DefWindowProc;
        wc.cbClsExtra = 0;
        wc.cbWndExtra = 0;
        wc.hInstance = hInstance;
        wc.hIcon = NULL;
        wc.hCursor = NULL;
        wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
        wc.lpszMenuName = NULL;
        wc.lpszClassName = _T("Bob");
        RegisterClass(&wc);

        hWndMain = CreateWindow(_T("Bob"),
                _T("Bob"),
                WS_VISIBLE,
                0,
                0,
                GetSystemMetrics(SM_CXSCREEN),
                GetSystemMetrics(SM_CYSCREEN),
                NULL,
                NULL,
                hInstance,
                NULL);

        if(!hWndMain)
                return 1;

        SetWindowPos(hWndMain, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE);
        UpdateWindow(hWndMain);
        return 0;
}

extern "C" void * giz_screen()
{
	static void * screen =0;
	if (!screen)
	{
		initwin(GetModuleHandle(NULL), 0);

		GXOpenDisplay(hWndMain, GX_FULLSCREEN);
		screen = GXBeginDraw();
	}
	return screen;
}