
#ifndef _BLUETOOTH_H
#define _BLUETOOTH_H

//-------------------------------------------------------------------------------------------------

struct BLUETOOTH_DEVICE
{
	char		pName[32];
	__int64		iDeviceAddr;
};

//-------------------------------------------------------------------------------------------------

bool Bluetooth_Init();
void Bluetooth_Exit();
int Bluetooth_GetLastError();
char *Bluetooth_GetHostName();

bool Bluetooth_CreateServer();
bool Bluetooth_CreateClient(BLUETOOTH_DEVICE *pDevice);

void Bluetooth_DestroyServer();
void Bluetooth_DestroyClient();

int Bluetooth_QueryDevices();
void Bluetooth_QueryDevicesNB();
bool Bluetooth_QueryDevicesFinished();
int Bluetooth_GetNumDevices();
BLUETOOTH_DEVICE *Bluetooth_GetDeviceList();

int Bluetooth_SendData(char *pBuffer, int iBufferSize);
int Bluetooth_ReceiveData(char *pBuffer, int iBufferSize);
void Bluetooth_ReceiveDataNB(char *pBuffer, int iBufferSize);
void Bluetooth_ReceiveDataCancel();
bool Bluetooth_ReceiveDataFinished(int *pBytesReceived);

//-------------------------------------------------------------------------------------------------

#endif

