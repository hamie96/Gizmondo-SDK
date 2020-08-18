/*

File:			Framework.h
Description:	Framework header file.

Copyright (c) Gizmondo Europe Ltd. All rights reserved.

*/

#ifndef _FRAMEWORK_H
#define _FRAMEWORK_H


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
	bool	 FlightMode;
	bool	 GPSState;
	bool	 GSMState;
	bool	 BTState;
	int		 InternetMMSConnected;
	int		 ActiveSyncConnected;
	bool	 GPRSConnected;
	bool	 AlreadyInternetMMS;
	bool	 AlreadyActiveSync;
	int		 SMS;
	int		 LowBatt;
	int		 CritBatt;
};


//-------------------------------------------------------------------------------------------------------------------------------------


bool		Framework_Init					(HINSTANCE hInstance, HINSTANCE hPrevInstance);
void		Framework_Close					();
HWND		Framework_GethWnd				();
bool		Framework_IsButtonPressed		(FRAMEWORK_BUTTONTYPES button);
void		Framework_ClearButtonPressed	(FRAMEWORK_BUTTONTYPES button);
bool		Framework_ProcessMessages		();
void		Framework_SwitchToPower			();
void		Framework_SwitchToMail			();
void		Framework_RequestStatus			();
void		Framework_GetCurrentStatus		(FRAMEWORK_STATUS *status);
void		Framework_GPRSConnect			();
void		Framework_GPRSDisconnect		();
bool		Framework_IsAppActive			();
bool		Framework_SetDisplayBrightness	(int value);
bool		Framework_GetRegisteredName		(TCHAR *name, DWORD size);

//-------------------------------------------------------------------------------------------------------------------------------------

#endif // _FRAMEWORK_H
