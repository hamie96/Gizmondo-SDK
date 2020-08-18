//-------------------------------------------------------------------------------------------------

#include "Device.h"
#include "Draw.h"
#include "Util.h"
#include "Bluetooth.h"
#include "Gameloop.h"

//-------------------------------------------------------------------------------------------------

enum
{
	MODE_START,
	MODE_MAINMENU,
	MODE_WAITINGFORCLIENT,
	MODE_CONNECTED,
	MODE_QUERYDEVICES,
	MODE_SELECTDEVICE,
	MODE_ERROR,
};

static int s_iCursorPos = 0;
static int s_iMode = -1;
static char s_pReceiveBuffer[256];

static int s_iNumMenuItems = 3;
char pMenuItems[][16] =
{
	"Create game",
	"Join game",
	"Exit",
};

static int s_iBallXPos = 40;
static int s_iBallYPos = 80;
static int s_iBallXSpeed = 2;
static int s_iBallYSpeed = 1;

//-------------------------------------------------------------------------------------------------

void Gameloop_Init()
{
	Bluetooth_Init();

	s_iMode = MODE_MAINMENU;
}

//-------------------------------------------------------------------------------------------------

bool Gameloop_Update()
{
	bool bQuit = false;
	int iButtons = Device_GetKeyStatusDebounced();

	switch (s_iMode)
	{
		//-------------------------------------------
		// MODE_MAINMENU

		case MODE_MAINMENU:
		{
			if (iButtons & DEVICE_KEY_UP)
			{
				if (s_iCursorPos>0)
					s_iCursorPos--;
			}

			if (iButtons & DEVICE_KEY_DOWN)
			{
				if (s_iCursorPos<(s_iNumMenuItems-1))
					s_iCursorPos++;
			}

			if (iButtons & DEVICE_KEY_PLAY)
			{
				if (s_iCursorPos == 0)
				{
					bool bSuccess = Bluetooth_CreateServer();

					if (bSuccess)
					{
						Bluetooth_ReceiveDataNB(s_pReceiveBuffer, 256);
						s_iMode = MODE_WAITINGFORCLIENT;
					}
					else
					{
						s_iMode = MODE_ERROR;
					}
				}
				else if (s_iCursorPos == 1)
				{
					Bluetooth_QueryDevicesNB();
					s_iMode = MODE_QUERYDEVICES;
					s_iCursorPos = 0;
				}
				else if (s_iCursorPos == 2)
				{
					bQuit = true;
				}
			}
			break;
		}

		//-------------------------------------------
		// MODE_WAITINGFORCLIENT

		case MODE_WAITINGFORCLIENT:
		{
			if (iButtons & DEVICE_KEY_STOP)
			{
				Bluetooth_ReceiveDataCancel();
				Bluetooth_DestroyServer();
				s_iMode = MODE_MAINMENU;
			}

			int iBytesReceived;
			if (Bluetooth_ReceiveDataFinished(&iBytesReceived))
			{
				s_iMode = MODE_CONNECTED;
			}

			break;
		}

		//-------------------------------------------
		// MODE_CONNECTED

		case MODE_CONNECTED:
		{
			if (iButtons & DEVICE_KEY_STOP)
			{
				Bluetooth_DestroyServer();
				s_iMode = MODE_MAINMENU;
			}
			break;
		}

		//-------------------------------------------
		// MODE_QUERYDEVICES

		case MODE_QUERYDEVICES:
		{
			if (Bluetooth_QueryDevicesFinished())
			{
				s_iMode = MODE_SELECTDEVICE;
			}
			break;
		}

		//-------------------------------------------
		// MODE_SELECTDEVICE

		case MODE_SELECTDEVICE:
		{
			int iNumDevices = Bluetooth_GetNumDevices();

			if (iButtons & DEVICE_KEY_UP)
			{
				if (s_iCursorPos>0)
					s_iCursorPos--;
			}

			if (iButtons & DEVICE_KEY_DOWN)
			{
				if (s_iCursorPos<iNumDevices)
					s_iCursorPos++;
			}

			if (iButtons & DEVICE_KEY_PLAY)
			{
				if (s_iCursorPos == iNumDevices)	// rescan?
				{
					s_iCursorPos = 0;
					s_iMode = MODE_QUERYDEVICES;
					Bluetooth_QueryDevicesNB();
				}
				else
				{
					BLUETOOTH_DEVICE *pDevices = Bluetooth_GetDeviceList();
					Bluetooth_CreateClient(&pDevices[s_iCursorPos]);

					char pMessage[] = "Hello boys";
					Bluetooth_SendData(pMessage, strlen(pMessage));

					Bluetooth_DestroyClient();

					s_iCursorPos = 0;
					s_iMode = MODE_MAINMENU;
				}
			}

			if (iButtons & DEVICE_KEY_STOP)
			{
				s_iMode = MODE_MAINMENU;
				s_iCursorPos = 0;
			}
			break;
		}

		//-------------------------------------------
		// MODE_ERROR

		case MODE_ERROR:
		{
			if (iButtons & DEVICE_KEY_STOP)
			{
				s_iMode = MODE_MAINMENU;
			}
			break;
		}
	}

	//----------------------------------
	// move ball

	s_iBallXPos += s_iBallXSpeed;
	s_iBallYPos += s_iBallYSpeed;
	if (s_iBallXPos>(320-4))
	{
		s_iBallXPos = (320-4);
		s_iBallXSpeed = -s_iBallXSpeed;
	}
	if (s_iBallXPos<(4))
	{
		s_iBallXPos = 4;
		s_iBallXSpeed = -s_iBallXSpeed;
	}
	if (s_iBallYPos>(240-4))
	{
		s_iBallYPos = (240-4);
		s_iBallYSpeed = -s_iBallYSpeed;
	}
	if (s_iBallYPos<(4))
	{
		s_iBallYPos = 4;
		s_iBallYSpeed = -s_iBallYSpeed;
	}

	//----------------------------------

	return bQuit;
}

//-------------------------------------------------------------------------------------------------

void Gameloop_Render()
{
	unsigned short pString[128];

	Draw_Fill(0, SETRGB(10,10,10), 320*60);
	Draw_Fill(320*60, SETRGB(20,10,0), 320*60);
	Draw_Fill(320*120, SETRGB(0,20,0), 320*60);
	Draw_Fill(320*180, SETRGB(0,0,20), 320*60);

	Draw_Ball(s_iBallXPos, s_iBallYPos);

	//-------------------------------------------

	Util_CopyAsciiToUnicode(pString, Bluetooth_GetHostName());
	Draw_Text(pString, 100, 4);

	switch (s_iMode)
	{
		//-------------------------------------------
		// MODE_MAINMENU

		case MODE_MAINMENU:
		{
			for (int i=0; i<s_iNumMenuItems; i++)
			{
				Util_CopyAsciiToUnicode(pString, pMenuItems[i]);
				Draw_Text(pString, 20, 50+(i*14));

				if (i == s_iCursorPos)
				{
					Draw_Text(TEXT(">"), 10, 50+(i*14));
				}
			}
			break;
		}

		//-------------------------------------------
		// MODE_WAITINGFORCLIENT

		case MODE_WAITINGFORCLIENT:
		{
			static int iTwistNum = 0;
			unsigned short pTwist[] = {'|','/','-','\\'};
			swprintf(pString, TEXT("Waiting for player...%c"), pTwist[iTwistNum]);
			Draw_Text(pString, 10, 30);
			iTwistNum = (iTwistNum+1)&3;
			break;
		}

		//-------------------------------------------
		// MODE_CONNECTED

		case MODE_CONNECTED:
		{
			Draw_Text(TEXT("Connected"), 10, 30);
			unsigned short pMessage[128];
			Util_CopyAsciiToUnicode(pMessage, s_pReceiveBuffer);
			swprintf(pString, TEXT("Message received is : %s"), pMessage);
			Draw_Text(pString, 10, 50);
			break;
		}

		//-------------------------------------------
		// MODE_QUERYDEVICES

		case MODE_QUERYDEVICES:
		{
			static int iTwistNum = 0;
			unsigned short pTwist[] = {'|','/','-','\\'};
			swprintf(pString, TEXT("Looking for devices...%c"), pTwist[iTwistNum]);
			Draw_Text(pString, 10, 30);
			iTwistNum = (iTwistNum+1)&3;
			break;
		}

		//-------------------------------------------
		// MODE_SELECTDEVICE

		case MODE_SELECTDEVICE:
		{
			int iNumDevices = Bluetooth_GetNumDevices();
			Draw_Text(TEXT("Select a device (or rescan) :"), 10, 30);
			BLUETOOTH_DEVICE *pDevices = Bluetooth_GetDeviceList();

			for (int i=0; i<iNumDevices+1; i++)
			{
				Util_CopyAsciiToUnicode(pString, pDevices[i].pName);

				if (i<iNumDevices)
				{
					Draw_Text(pString, 20, 50 + (i*14));
				}
				else
				{
					Draw_Text(TEXT("[rescan]"), 20, 50+(i*14));
				}

				if (i == s_iCursorPos)
				{
					Draw_Text(TEXT(">"), 10, 50+(i*14));
				}
			}


			break;
		}

		//-------------------------------------------
		// MODE_ERROR

		case MODE_ERROR:
		{
			Draw_Text(TEXT("Device error!"), 10, 30);
			break;
		}

	}
}

//-------------------------------------------------------------------------------------------------

void Gameloop_Exit()
{
	Bluetooth_Exit();
}

//-------------------------------------------------------------------------------------------------
