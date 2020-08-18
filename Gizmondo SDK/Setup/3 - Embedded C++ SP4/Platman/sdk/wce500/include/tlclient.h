#ifndef _TLCLIENT_H_
#define _TLCLIENT_H_

#include <windows.h>


class CConnection
{
public:
	CConnection() {};
	virtual ~CConnection() {};
	virtual BOOL Close() = 0;
	virtual LRESULT WriteBytes( LPBYTE pData, DWORD  dwSize) = 0;
	virtual LRESULT ReadBytes(LPBYTE pData, DWORD dwSize, DWORD *pdwSizeRet) = 0;
};

class CTransport
{
public:
	CTransport() {}
	virtual ~CTransport() {};
	virtual BOOL Init(BYTE *pBuffer, DWORD dwSize)=0;
	virtual CConnection *NewConnection() = 0;
	virtual BOOL Uninit()=0;
};

extern "C" CTransport *CreateTransport(); 

typedef CTransport *(*TRANSPORTFUNC)();

#endif // _TLCLIENT_H_