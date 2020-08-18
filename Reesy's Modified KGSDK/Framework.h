/*
vim:ts=4

File:			Framework.h
Description:	Framework header file.

Copyright (c) Gizmondo Europe Ltd. All rights reserved.

*/

#ifndef _FRAMEWORK_H
#define _FRAMEWORK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "KGSDK.h"

//-------------------------------------------------------------------------------------------------------------------------------------

enum FRAMEWORK_BUTTONTYPES
{
	FRAMEWORK_BUTTON_DPAD_LEFT = 0,
	FRAMEWORK_BUTTON_DPAD_RIGHT,
	FRAMEWORK_BUTTON_DPAD_UP,
	FRAMEWORK_BUTTON_DPAD_DOWN,
	FRAMEWORK_BUTTON_STOP,
	FRAMEWORK_BUTTON_PLAY,
	FRAMEWORK_BUTTON_FORWARD,
	FRAMEWORK_BUTTON_REWIND,
	FRAMEWORK_BUTTON_LEFT_SHOULDER,
	FRAMEWORK_BUTTON_RIGHT_SHOULDER,
	FRAMEWORK_BUTTON_HOME,
	FRAMEWORK_BUTTON_VOLUME,
	FRAMEWORK_BUTTON_BRIGHTNESS,
	FRAMEWORK_BUTTON_ALARM,
	FRAMEWORK_BUTTON_POWER,

	FRAMEWORK_BUTTON_COUNT

};


struct FRAMEWORK_STATUS
{
	int		FlightMode;
	int		GPSState;
	int		GSMState;
	int		BTState;
	int		InternetMMSConnected;
	int		ActiveSyncConnected;
	int		GPRSConnected;
	int		AlreadyInternetMMS;
	int		AlreadyActiveSync;
	int		SMS;
	int		LowBatt;
	int		CritBatt;
};


//-------------------------------------------------------------------------------------------------------------------------------------


DECLSPEC	int			Framework_Init					(HINSTANCE hInstance, HINSTANCE hPrevInstance);
DECLSPEC	void		Framework_Close					();
DECLSPEC	HWND		Framework_GethWnd				();
DECLSPEC	int			Framework_IsButtonPressed		(enum FRAMEWORK_BUTTONTYPES button);
DECLSPEC	void		Framework_ClearButtonPressed	(enum FRAMEWORK_BUTTONTYPES button);
DECLSPEC	void		Framework_ClearButtons			();
DECLSPEC	int			Framework_PollGetButtons		();
DECLSPEC	int			Framework_ProcessMessages		();
DECLSPEC	void		Framework_SwitchToPower			();
DECLSPEC	void		Framework_SwitchToMail			();
DECLSPEC	void		Framework_RequestStatus			();
DECLSPEC	void		Framework_GetCurrentStatus		(struct FRAMEWORK_STATUS *status);
DECLSPEC	void		Framework_GPRSConnect			();
DECLSPEC	void		Framework_GPRSDisconnect		();
DECLSPEC	int			Framework_IsAppActive			();
DECLSPEC	void		Framework_SetFocus				();
DECLSPEC	int			Framework_SetDisplayBrightness	(int value);
DECLSPEC	int			Framework_GetRegisteredName		(TCHAR *name, DWORD size);
DECLSPEC	int			Framework_GetTicks();
//-------------------------------------------------------------------------------------------------------------------------------------

/* Ends C function definitions when using C++ */
#ifdef __cplusplus
}
#endif


#endif // _FRAMEWORK_H





