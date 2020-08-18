//-------------------------------------------------------------------------------------------------

#include <assert.h>
#include <winsock2.h>
#include <bt_api.h>
#include <bt_sdp.h>

#include "Bluetooth.h"

//-------------------------------------------------------------------------------------------------

#define BLUETOOTH_MAXDEVICES 8

static bool				s_bInitialised = false;
static int				s_iLastError;
static HANDLE			s_hCommPort;
static volatile bool	s_bQueryFinished;
static volatile bool	s_bReceiveFinished;
static int				s_iNumDevices = 0;
static BLUETOOTH_DEVICE	s_pDeviceList[BLUETOOTH_MAXDEVICES];
static UINT				s_iBTMessage;
static char *			s_pReceiveBuffer;
static int				s_iReceiveBufferSize;
static int				s_iBytesReceived;
static bool				s_bReceiveCancel;
static char				s_pHostName[64];
static HANDLE			s_hDeviceHandle;

//-------------------------------------------------------------------------------------------------
//
// Initialise bluetooth support system. Returns true if operation was successful.
//

bool Bluetooth_Init()
{
	assert(!s_bInitialised);

	// send message to shell to turn on bluetooth
	s_iBTMessage = RegisterWindowMessage(TEXT("BT_MSG"));
	SendMessage(HWND_BROADCAST, s_iBTMessage, 1, 0);

	// wait for message to be processed
	Sleep(1000);

	// initialse ws2.dll which is used to query bluetooth devices
	WSAData wsaData;
	int iRet = WSAStartup(MAKEWORD(2, 2), &wsaData);

	if (iRet == SOCKET_ERROR)
	{
		s_iLastError = WSAGetLastError();
		return false;
	}

	iRet = gethostname(s_pHostName, 64);

	s_bReceiveCancel = false;
	s_bQueryFinished = true;
	s_bReceiveFinished = true;
	s_hDeviceHandle = 0;

	s_bInitialised = true;

	return true;
}

//-------------------------------------------------------------------------------------------------

void Bluetooth_Exit()
{
	assert(s_bInitialised);
	s_bInitialised = false;

	if (s_hDeviceHandle != 0)
	{
		DeregisterDevice(s_hDeviceHandle);
	}

	WSACleanup();
}

//-------------------------------------------------------------------------------------------------
//
// If a function was unsuccessful, this function returns the error number
//

int Bluetooth_GetLastError()
{
	return s_iLastError;
}

//-------------------------------------------------------------------------------------------------

char *Bluetooth_GetHostName()
{
	return s_pHostName;
}

//-------------------------------------------------------------------------------------------------
//
// Fills in s_pDeviceList with a list of available devices. This function is blocking and may take
// some time so running it in a separate thread is advisable.
// Functions returns the number of devices found or -1 if there was an error.
//
// Need some simple locking in here
//

int Bluetooth_QueryDevices()
{
	WSAQUERYSET querySet;
	memset(&querySet, 0, sizeof(querySet));
	querySet.dwSize = sizeof(querySet);
	querySet.dwNameSpace = NS_BTH;

	// make sure bluetooth is turned on
	SendMessage(HWND_BROADCAST, s_iBTMessage, 1, 0);

	HANDLE hLookup;
	int iRet = WSALookupServiceBegin(&querySet, LUP_CONTAINERS , &hLookup);

	if (iRet == SOCKET_ERROR)
	{
		s_iLastError = WSAGetLastError();
		return -1;
	}

	s_iNumDevices = 0;

	while (iRet == 0)
	{
		char pBuffer[1000];
		DWORD dwBuffLen = sizeof(pBuffer);
		WSAQUERYSET *pResults = (WSAQUERYSET*)&pBuffer;
		iRet = WSALookupServiceNext(hLookup, LUP_RETURN_NAME|LUP_RETURN_ADDR, &dwBuffLen, pResults);

		if (iRet == 0)
		{
			s_pDeviceList[s_iNumDevices].iDeviceAddr = reinterpret_cast<_SOCKADDR_BTH*>(pResults->lpcsaBuffer->RemoteAddr.lpSockaddr)->btAddr;

			if (pResults->lpszServiceInstanceName != NULL)
			{
				// convert wide string to ascii
				WCHAR *pWName = pResults->lpszServiceInstanceName;
				char *pName = s_pDeviceList[s_iNumDevices].pName;
				do
				{
					*pName = (char)(*pWName++);
				}
				while (*pName++ != 0);
			}
			else
			{
				strcpy(s_pDeviceList[s_iNumDevices].pName, "<unnamed>");
			}

			s_iNumDevices++;
		}
	}

	WSALookupServiceEnd(hLookup);

	return s_iNumDevices;
}

//-------------------------------------------------------------------------------------------------
//
// non blocking version
//

DWORD WINAPI Bluetooth_QueryDevicesThread(LPVOID lpParameter)
{
	Bluetooth_QueryDevices();
	s_bQueryFinished = true;

	ExitThread(0);
	return 0;
}

void Bluetooth_QueryDevicesNB()
{
	if (s_bQueryFinished)
	{
		s_bQueryFinished = false;
		HANDLE hResult = CreateThread( NULL, 0, Bluetooth_QueryDevicesThread, NULL, 0, NULL);
	}
}

//-------------------------------------------------------------------------------------------------
//
// Returns true if Bluetooth_QueryDevicesNB has completed
//

bool Bluetooth_QueryDevicesFinished()
{
	return s_bQueryFinished;
}

//-------------------------------------------------------------------------------------------------

BLUETOOTH_DEVICE *Bluetooth_GetDeviceList()
{
	return s_pDeviceList;
}

//-------------------------------------------------------------------------------------------------

int Bluetooth_GetNumDevices()
{
	return s_iNumDevices;
}

//-------------------------------------------------------------------------------------------------
//
//
//

bool Bluetooth_CreateServer()
{
	assert(s_hDeviceHandle == 0);

	PORTEMUPortParams pp;
	memset (&pp, 0, sizeof(pp));
	pp.flocal = true;
	pp.channel = 2;
	int iPort = 4;
	s_hDeviceHandle = RegisterDevice(L"COM", iPort, L"btd.dll", (DWORD)&pp);

	if (s_hDeviceHandle == 0)
	{
		s_iLastError = GetLastError();
		return false;
	}

	WCHAR szComPort[30];
	wsprintf (szComPort, L"COM%d:", iPort);

	s_hCommPort = CreateFile(szComPort, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);

	return true;
}

//-------------------------------------------------------------------------------------------------

void Bluetooth_DestroyServer()
{
	assert(s_hDeviceHandle != 0);
	DeregisterDevice(s_hDeviceHandle);
	s_hDeviceHandle = 0;
}

//-------------------------------------------------------------------------------------------------

bool Bluetooth_CreateClient(BLUETOOTH_DEVICE *pDevice)
{
	assert(s_hDeviceHandle == 0);

	PORTEMUPortParams pp;
	memset (&pp, 0, sizeof(pp));
	pp.uiportflags = RFCOMM_PORT_FLAGS_REMOTE_DCB;
	pp.device = pDevice->iDeviceAddr;
	pp.channel = 2;
	int iPort = 4;
	s_hDeviceHandle = RegisterDevice(L"COM", iPort, L"btd.dll", (DWORD)&pp);

	if (s_hDeviceHandle == 0)
	{
		s_iLastError = GetLastError();
		return false;
	}

	WCHAR szComPort[30];
	wsprintf (szComPort, L"COM%d:", iPort);

	s_hCommPort = CreateFile (szComPort, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);

	return true;
}

//-------------------------------------------------------------------------------------------------

void Bluetooth_DestroyClient()
{
	assert(s_hDeviceHandle != 0);
	DeregisterDevice(s_hDeviceHandle);
	s_hDeviceHandle = 0;
}

//-------------------------------------------------------------------------------------------------

int Bluetooth_SendData(char *pBuffer, int iBufferSize)
{
	DWORD iBytesWritten;
	WriteFile( s_hCommPort, pBuffer, iBufferSize, &iBytesWritten, NULL);

	return iBytesWritten;
}

//-------------------------------------------------------------------------------------------------
//
// Returns bytes received or -1 if there was an error
//

int Bluetooth_ReceiveData(char *pBuffer, int iBufferSize)
{
	DWORD iBytesRead;

	SetCommMask(s_hCommPort, EV_RXCHAR);

	bool bReceived = false;

	while (!bReceived && !s_bReceiveCancel)
	{
		DWORD iEventMask;
		WaitCommEvent( s_hCommPort, &iEventMask, NULL);

		if (iEventMask &= EV_RXCHAR)
		{
			ReadFile( s_hCommPort, pBuffer, iBufferSize, &iBytesRead, NULL);
			bReceived = true;
		}
	}

	return iBytesRead;
}

//-------------------------------------------------------------------------------------------------
//
// non blocking version
//

DWORD WINAPI Bluetooth_ReceiveDataThread(LPVOID lpParameter)
{
	s_iBytesReceived = Bluetooth_ReceiveData(s_pReceiveBuffer, s_iReceiveBufferSize);
	s_bReceiveFinished = true;

	ExitThread(0);
	return 0;
}

void Bluetooth_ReceiveDataNB(char *pBuffer, int iBufferSize)
{
	if (s_bReceiveFinished)
	{
		s_pReceiveBuffer = pBuffer;
		s_iReceiveBufferSize = iBufferSize;
		s_bReceiveFinished = false;
		s_bReceiveCancel = false;

		HANDLE hResult = CreateThread( NULL, 0, Bluetooth_ReceiveDataThread, NULL, 0, NULL);
	}
}

//-------------------------------------------------------------------------------------------------

void Bluetooth_ReceiveDataCancel()
{
	s_bReceiveCancel = true;
}

//-------------------------------------------------------------------------------------------------
//
// Returns true if Bluetooth_ReceiveDataNB has completed
//

bool Bluetooth_ReceiveDataFinished(int *pBytesReceived)
{
	if (s_bReceiveFinished)
	{
		*pBytesReceived = s_iBytesReceived;
	}
	else
	{
		*pBytesReceived = 0;
	}

	return s_bReceiveFinished;
}

//-------------------------------------------------------------------------------------------------
