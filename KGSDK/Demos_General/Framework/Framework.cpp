/*

File:			Framework.cpp
Description:	Basic shared framework for creating an application on the Gizmondo. Deals
				with registering the app, creating the window and processing the window
				messages.

Copyright (c) Gizmondo Europe Ltd. All rights reserved.

*/

#include <windows.h>
#include "framework.h"
#include "oeminc.h"


//-------------------------------------------------------------------------------------------------------------------------------------
// Strings for the Gizmondo's global events and messages

#define SYSEVENT_FORCE_ONSTATE		L"PowerManager/ActivityTimer/UserActivity"
#define SYSMESSAGE_LOWBATERY		L"LOWBATERY_MSG"			// Sent when battery is low
#define SYSMESSAGE_CRITICALBATERY	L"CRITICALBATERY_MSG"		// Sent when battery is critical
#define SYSMESSAGE_SMS				L"SMS_MSG"					// Sent when a SMS/MMS is received
#define SYSMESSAGE_SWITCHTOSHELL	L"SWITCHTOSHELL_MSG"		// Sent when wanting to switch to the shell
#define SYSMESSAGE_GPRS_CONNECT		L"GPRS_CONNECT"				// Game requesting GRPS connection
#define SYSMESSAGE_GPRS_STATUS		L"GPRS_STATUS"				// GRPS connection status
#define SYSMESSAGE_GT_GETSTATUS		L"GT_GETSTATUS"				// Game asking for shell status
#define SYSMESSAGE_GT_STATUS		L"GT_STATUS"				// Shell status (flight mode etc)


//-------------------------------------------------------------------------------------------------------------------------------------
// Static variables

static bool		 Framework_Initialised = false;
static HWND		 Framework_hWndApp = NULL;
static HINSTANCE Framework_hInstance = NULL;
static bool		 Framework_ButtonsPressed[FRAMEWORK_BUTTON_COUNT];
static HANDLE	 Framework_OnEvent;

static UINT		 Framework_LowBatteryMsg		= 0;
static UINT		 Framework_CriticalBatteryMsg	= 0;
static UINT		 Framework_SwitchToShellMsg		= 0;
static UINT		 Framework_GPRSConnectMsg		= 0;
static UINT		 Framework_GPRSStatusMsg		= 0;
static UINT		 Framework_GetStatusMsg			= 0;
static UINT		 Framework_StatusMsg			= 0;
static UINT		 Framework_SMSReceivedMsg		= 0;

static FRAMEWORK_STATUS Framework_Status;
static bool		 Framework_AppActive			= false;


//-------------------------------------------------------------------------------------------------------------------------------------
// Parse the wParam from WM_KEYUP and WM_KEYDOWN into the equivalent Gizmondo button.
// Args:	wParam - WM_KEYUP/WM_KEYDOWN key
// Returns:	Gizmondo button if valid, -1 otherwise.

static int Framework_ParseKey(WPARAM wParam)
{
	switch (wParam)
	{
		case VK_LEFT:    return FRAMEWORK_BUTTON_DPAD_LEFT;
		case VK_RIGHT:   return FRAMEWORK_BUTTON_DPAD_RIGHT;
		case VK_UP:      return FRAMEWORK_BUTTON_DPAD_UP;
		case VK_DOWN:    return FRAMEWORK_BUTTON_DPAD_DOWN;
		case VK_CONTROL: return FRAMEWORK_BUTTON_STOP;
		case VK_RETURN:  return FRAMEWORK_BUTTON_PLAY;
		case VK_SPACE:   return FRAMEWORK_BUTTON_FORWARD;
		case VK_SHIFT:   return FRAMEWORK_BUTTON_REWIND;
		case VK_TAB:     return FRAMEWORK_BUTTON_LEFT_SHOULDER;
		case VK_ESCAPE:  return FRAMEWORK_BUTTON_RIGHT_SHOULDER;
		case VK_F1:      return FRAMEWORK_BUTTON_HOME;
		case VK_F2:      return FRAMEWORK_BUTTON_VOLUME;
		case VK_F3:      return FRAMEWORK_BUTTON_BRIGHTNESS;
//		case VK_F4:      return FRAMEWORK_BUTTON_ALARM;		// do not parse this button!
		case VK_F11:     return FRAMEWORK_BUTTON_POWER;
	}

	return -1;
}


//-------------------------------------------------------------------------------------------------------------------------------------
// Returns whether given Gizmondo button is depressed.
//
// Args:	button - Gizmondo button.
// Returns:	true if button is pressed, false if button is not or button value is invalid.

bool Framework_IsButtonPressed(FRAMEWORK_BUTTONTYPES button)
{
	if (button >= 0 && button < FRAMEWORK_BUTTON_COUNT)
	{
		return Framework_ButtonsPressed[button];
	}

	return false;
}


//-------------------------------------------------------------------------------------------------------------------------------------
// Clears the pressed status of a Gizmondo button.
//
// Args:	button - Gizmondo button.

void Framework_ClearButtonPressed(FRAMEWORK_BUTTONTYPES button)
{
	if (button >= 0 && button < FRAMEWORK_BUTTON_COUNT)
	{
		Framework_ButtonsPressed[button] = false;
	}
}


//-------------------------------------------------------------------------------------------------------------------------------------
// Internal. Parses the wParam and lParam arguments from a Gizmondo GRPS global window message.

static void Framework_ProcessGPRSStatus(WPARAM wParam, LPARAM lParam)
{
	if (wParam == 8092)
		Framework_Status.GPRSConnected = true;

	if (wParam == 8093)
		Framework_Status.GPRSConnected = false;

	if (lParam & (1<<0))
		Framework_Status.AlreadyInternetMMS = true;
	else
		Framework_Status.AlreadyInternetMMS = false;

	if (lParam & (1<<2))
		Framework_Status.AlreadyActiveSync = true;
	else
		Framework_Status.AlreadyActiveSync = false;
}


//-------------------------------------------------------------------------------------------------------------------------------------
// Internal. Parses the wParam argument from a Gizmondo status global window message.

static void Framework_ProcessStatus(WPARAM wParam)
{
	if (wParam & (1<<0))
		Framework_Status.FlightMode = true;
	else
		Framework_Status.FlightMode = false;

	if (wParam & (1<<1))
		Framework_Status.GPSState = true;
	else
		Framework_Status.GPSState = false;

	if (wParam & (1<<2))
		Framework_Status.GSMState = true;
	else
		Framework_Status.GSMState = false;

	if (wParam & (1<<3))
		Framework_Status.BTState = true;
	else
		Framework_Status.BTState = false;

	if (wParam & (1<<4))
		Framework_Status.InternetMMSConnected++;

	if (wParam & (1<<6))
		Framework_Status.ActiveSyncConnected++;
}


//-------------------------------------------------------------------------------------------------------------------------------------
// Internal. Callback function for the window messages.

static LRESULT CALLBACK Framework_WndProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC         hdc;
	RECT		rect;
	int			button;

//	TCHAR message[256];
//	wsprintf(message, L"message: %08x  wParam: %08x  lParam: %08x\r\n", uMessage, wParam, lParam);
//	OutputDebugString(message);

//	static FILE *log = NULL;
//	if (!log)
//		log = fopen("\\sd card\\log.txt", "wb");
//	else
//		log = fopen("\\sd card\\log.txt", "ab");
//	fprintf(log, "message: %08x  wParam: %08x  lParam: %08x\r\n", uMessage, wParam, lParam);
//	fclose(log);

	switch (uMessage)
	{
		case WM_PAINT:
			GetClientRect(hWnd, &rect);
			hdc = BeginPaint( hWnd, &ps );
			EndPaint( hWnd, &ps );
			return 1;

		case WM_DESTROY:
			PostQuitMessage(0);
			return 0L;

		case WM_ACTIVATE:
			if (LOWORD(wParam))
			{
				SetCursor( NULL );
				ShowCursor( FALSE );

				Framework_AppActive   = true;
			}
			else
			{
				Framework_AppActive   = false;
			}
			return 0;
			break;

		case WM_SETCURSOR:
			SetCursor( NULL );
			ShowCursor( FALSE );
			return 1;

		case WM_KEYDOWN:
			button = Framework_ParseKey(wParam);
			if (button != -1)
			{
				Framework_ButtonsPressed[button] = true;
			}
			return 0;

		case WM_KEYUP:
			button = Framework_ParseKey(wParam);
			if (button != -1)
			{
				if (button != FRAMEWORK_BUTTON_POWER)
				{
					Framework_ButtonsPressed[button] = false;
				}
				else
				{
					Framework_ButtonsPressed[button] = true;
				}
			}

			return 0;
	} 

	if (uMessage == Framework_StatusMsg)
	{
		Framework_ProcessStatus(wParam);
		return 0;
	}

	if (uMessage == Framework_GPRSStatusMsg)
	{
		Framework_ProcessGPRSStatus(wParam, lParam);
		return 0;
	}

	if (uMessage == Framework_SMSReceivedMsg)
	{
		Framework_Status.SMS++;
		return 0;
	}

	if (uMessage == Framework_LowBatteryMsg)
	{
		Framework_Status.LowBatt++;
		return 0;
	}

	if (uMessage == Framework_CriticalBatteryMsg)
	{
		Framework_Status.CritBatt++;
		return 0;
	}

	return DefWindowProc( hWnd, uMessage, wParam, lParam );
}


//-------------------------------------------------------------------------------------------------------------------------------------
// Framework update function to be called once a frame by the application.
// Processes any waiting window messages, sets the global event to stop the
// Gizmondo going into sleep mode and call Sleep(0) to allow Window's
// housekeeping.
//
// Returns:	true if application still running, false if application quit.

bool Framework_ProcessMessages()
{
	MSG msg;

	SetEvent(Framework_OnEvent);
	Sleep(0);

	while (PeekMessage (&msg, NULL, 0, 0, PM_REMOVE))
	{
		if ( msg.message == WM_QUIT )
		{
			return( 0 );
		}

		TranslateMessage( &msg ); 
		DispatchMessage( &msg );
	}

	if (Framework_IsButtonPressed(FRAMEWORK_BUTTON_POWER))
	{
		Framework_ClearButtonPressed(FRAMEWORK_BUTTON_POWER);
		Framework_SwitchToPower();
	}

	return( 1 );
}


//-------------------------------------------------------------------------------------------------------------------------------------
// Initialises the appliaction. Registers the class, creates the window and sets
// up various static variables.
//
// Args:	hInstance - hInstance passed into WinMain.
//			hPrevInstance - hPrevInstance passed into WinMain.
//			lpAppName - Application name.
// Returns:	true if initialisation worked, false if initialisation failed.

bool Framework_Init(HINSTANCE hInstance, HINSTANCE hPrevInstance )
{
    WNDCLASS  cls;          

	if (Framework_Initialised)
		return true;

    if (!hPrevInstance)
    {
		cls.hCursor			= LoadCursor( NULL, IDC_ARROW );
		cls.hIcon			= NULL;
        cls.lpszMenuName	= NULL;
		cls.hbrBackground	= (HBRUSH) GetStockObject( BLACK_BRUSH );
        cls.hInstance		= hInstance;
        cls.lpszClassName	= L"Test App";
        cls.lpfnWndProc		= Framework_WndProc;
		cls.style			= CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
        cls.cbWndExtra		= 0;
        cls.cbClsExtra		= 0;

        if (!RegisterClass(&cls))
		{
            return false;
		}
    }

	Framework_hWndApp = CreateWindow(L"Test App",
									 L"Test App",
									 WS_POPUP | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
									 0,
									 0,
									 320,
									 240,
									 NULL,
									 NULL,
									 hInstance,
									 NULL);

	if (!Framework_hWndApp)
		return false;

	ShowWindow(Framework_hWndApp, true);
	UpdateWindow(Framework_hWndApp);

	Framework_hInstance = hInstance;
	memset(Framework_ButtonsPressed, 0, sizeof(Framework_ButtonsPressed));
	Framework_Initialised = true;
	Framework_OnEvent = OpenEvent(EVENT_ALL_ACCESS, FALSE, SYSEVENT_FORCE_ONSTATE);

	// Register windows messages
	Framework_LowBatteryMsg			= RegisterWindowMessage(SYSMESSAGE_LOWBATERY);
	Framework_CriticalBatteryMsg	= RegisterWindowMessage(SYSMESSAGE_CRITICALBATERY);
	Framework_SwitchToShellMsg		= RegisterWindowMessage(SYSMESSAGE_SWITCHTOSHELL);
	Framework_GPRSConnectMsg		= RegisterWindowMessage(SYSMESSAGE_GPRS_CONNECT);
	Framework_GPRSStatusMsg			= RegisterWindowMessage(SYSMESSAGE_GPRS_STATUS);
	Framework_GetStatusMsg			= RegisterWindowMessage(SYSMESSAGE_GT_GETSTATUS);
	Framework_StatusMsg				= RegisterWindowMessage(SYSMESSAGE_GT_STATUS);
	Framework_SMSReceivedMsg		= RegisterWindowMessage(SYSMESSAGE_SMS);

    return true;
}


//-------------------------------------------------------------------------------------------------------------------------------------
// Close down the application and destroy the window.

void Framework_Close()
{
	if (Framework_Initialised)
		DestroyWindow(Framework_hWndApp);

	Framework_hWndApp = NULL;
	Framework_Initialised = false;
}


//-------------------------------------------------------------------------------------------------------------------------------------
// Get the handle for the application's main window
//
// Returns:	Appication's window handle

HWND Framework_GethWnd(void)
{
	if (!Framework_Initialised)
		return NULL;

	return Framework_hWndApp;
}


//-------------------------------------------------------------------------------------------------------------------------------------
// Sends the window message to switch to the mail client

void Framework_SwitchToMail()
{
	PostMessage(HWND_BROADCAST, Framework_SwitchToShellMsg, 1, 0);
	Framework_ProcessMessages();
}


//-------------------------------------------------------------------------------------------------------------------------------------
// Sends the window message to switch to the power menu

void Framework_SwitchToPower()
{
	PostMessage(HWND_BROADCAST, Framework_SwitchToShellMsg, 0, 0);
	Framework_ProcessMessages();
}


//-------------------------------------------------------------------------------------------------------------------------------------
// Sends the window message to request status

void Framework_RequestStatus()
{
	SendMessage(HWND_BROADCAST, Framework_GetStatusMsg, 0, 0);					
}


//-------------------------------------------------------------------------------------------------------------------------------------
// Gets current system messages status
//
// Args:	status - pointer to structure for results to go.

void Framework_GetCurrentStatus(FRAMEWORK_STATUS *status)
{
	*status = Framework_Status;
}


//-------------------------------------------------------------------------------------------------------------------------------------
// Sends the window message to connect the GPRS

void Framework_GPRSConnect()
{
	SendMessage(HWND_BROADCAST, Framework_GPRSConnectMsg, 1, 0);
}


//-------------------------------------------------------------------------------------------------------------------------------------
// Sends the window message to disconnect the GPRS

void Framework_GPRSDisconnect()
{
	SendMessage(HWND_BROADCAST, Framework_GPRSConnectMsg, 0, 0);
}


//-------------------------------------------------------------------------------------------------------------------------------------
// Returns whether we are the current active appliaction. Used to
// determine when the user has come out of either the power or mail menus.
//
// Returns:	If application is the current active one.

bool Framework_IsAppActive()
{
	return Framework_AppActive;
}


//-------------------------------------------------------------------------------------------------------------------------------------
// Sets the display brightness from a value of 0 to 3
//
// Args:	value - brightness value from 0 to 3.
// Returns:	true if brightness set correctly, false otherwise.

bool Framework_SetDisplayBrightness(int value)
{
	HKEY hkey;
	LONG result;
	LONG setvalues[4] = {BACKLIGHT_MIN, BACKLIGHT_DIM_DEF, BACKLIGHT_DEF, BACKLIGHT_MAX};
	HANDLE eventbrightness;

	result = RegOpenKeyEx(HKEY_CURRENT_USER, REGKEY_BACKLIGHT, 0, 0, &hkey);

	if (result == ERROR_SUCCESS)
	{
		if (value < 0) value = 0;
		if (value > 3) value = 3;

		result = RegSetValueEx(hkey, REGVAL_ON_LEVEL, NULL, REG_DWORD, (const BYTE *) &setvalues[value], 4);

		RegCloseKey(hkey);

		if (result == ERROR_SUCCESS)
		{
			eventbrightness = OpenEvent(EVENT_ALL_ACCESS, false, EVENTNAME_BACKLIGHTCHANGEEVENT);		
			SetEvent(eventbrightness);
			CloseHandle(eventbrightness);

			return true;
		}
	}

	return false;
}


//-------------------------------------------------------------------------------------------------------------------------------------
// Gets the Gizmondo's registered name
//
// Args:	name - pointer to TCHAR array to store the name
//			size - size fo the array.
//
// Returns:	true if name retrieved correctly, false otherwise.

bool Framework_GetRegisteredName(TCHAR *name, DWORD size)
{
	HKEY hkey;
	LONG result;
	DWORD type;

	result = RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"\\Ident", 0, 0, &hkey);

	if (result == ERROR_SUCCESS)
	{
		size = 256;
		result = RegQueryValueEx(hkey, L"Name", NULL, &type, (BYTE *) name, &size);

		RegCloseKey(hkey);

		if (result == ERROR_SUCCESS)
			return true;
	}

	return false;
}
