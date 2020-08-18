///////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2004 Gizmondo Ltd and
// Copyright (C) 2004 Intrinsyc Europe Ltd.
// All rights reserved.
// No use or disclosure of this information in any form without the
// written permission of the author Intrinsyc Europe Ltd.
// http://www.intrinsyc.com
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
// FILE INFORMATION
//
//   Project: Gizmondo Terminal WinCE Port
//      Unit: Vibrator Driver
// $Workfile: VIBRATOR.cpp $
// $Revision: 1 $
//     $Date: 21/10/04 12:11 $
//
// DESCRIPTION : Developer Sample :Demonstration program for the vibrator
//
///////////////////////////////////////////////////////////////////////////////
//
// MODIFICATION HISTORY
//
// $Log: /Gizmondo/Apps/Developer Samples/Vibrator/VIBRATOR.cpp $
// 
// 1     21/10/04 12:11 Deanw
// Created
// 
// 
// $NoKeywords: $
//
///////////////////////////////////////////////////////////////////////////////

// VIBRATOR.cpp : Defines the entry point for the application.
//
#include "stdafx.h"
#include "nled.h"

int WINAPI WinMain(	HINSTANCE hInstance,
					HINSTANCE hPrevInstance,
					LPTSTR    lpCmdLine,
					int       nCmdShow)
{
	HANDLE hLed;
	DWORD dwDelay;
	UINT i;
    struct NLED_COUNT_INFO ledCountInfo;
    struct NLED_SETTINGS_INFO ledSettingInfo;

	hLed = CreateFile (L"VIB1:", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
	if(hLed!=(HANDLE)-1)
    {
    	// Get the number of vibrators
	    DeviceIoControl( hLed, NLED_COUNT_INFO_ID,NULL, 0, (void*) &ledCountInfo, sizeof(ledCountInfo), NULL, NULL );
    	RETAILMSG(1, (TEXT("<Vibrator> Number of vibrators on platform = %x \r\n"), ledCountInfo.cLeds));

	    // Set first vibrator to pulse every 4 seconds  
	    dwDelay = 2000000;
        
        // Start each vibrator flashing, halving the frequency for each
	    RETAILMSG(1, (TEXT("<Vibrator> Pulsing vibrators...\r\n")));
	    for (i = 0; i < ledCountInfo.cLeds; i++, dwDelay <<= 1) 
        {   
		    ledSettingInfo.LedNum = i;
    		ledSettingInfo.OffOnBlink = 2;		// 0 = off, 1 = on, 2 = blink
	    	ledSettingInfo.OnTime = dwDelay;
		    ledSettingInfo.OffTime = dwDelay;
    		ledSettingInfo.TotalCycleTime = ledSettingInfo.OffTime + ledSettingInfo.OnTime;
	    	ledSettingInfo.MetaCycleOn = 0;
		    ledSettingInfo.MetaCycleOff = 0;

		    DeviceIoControl( hLed, NLED_SETTINGS_INFO_ID,&ledSettingInfo, sizeof(ledSettingInfo),NULL,0, NULL, NULL );
    	}

	    // Wait for 30s
	    RETAILMSG(1, (TEXT("<Vibrator> ... wait 30s...\r\n")));
	    Sleep (30000);

	    // Turn all vibrators off
	    RETAILMSG(1, (TEXT("<Vibrator> ... turning vibrators off\r\n")));
	    for (i = 0; i < ledCountInfo.cLeds; i++) 
        {
		    ledSettingInfo.LedNum = i;
    		ledSettingInfo.OffOnBlink = 0;		// 0 = off, 1 = on, 2 = blink
	    	DeviceIoControl( hLed, NLED_SETTINGS_INFO_ID,&ledSettingInfo, sizeof(ledSettingInfo),NULL,0, NULL, NULL );
    	}
				
	    CloseHandle(hLed);
    }
    else
    {
		RETAILMSG (1, (TEXT("<Vibrator> Open device failed\r\n")));
		return(1);
	}

	return 0;
}

