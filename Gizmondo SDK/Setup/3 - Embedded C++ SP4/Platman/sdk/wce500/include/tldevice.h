#ifndef _TLDEVICE_H_
#define _TLDEVICE_H_

#include <windows.h>

class CConnectionStream
{
public:
	CConnectionStream();
	virtual ~CConnectionStream();
	virtual BOOL Close();
	virtual LRESULT WriteBytes( LPVOID pData, DWORD  dwSize);
	virtual LRESULT ReadBytes(LPVOID pData, DWORD dwSize, DWORD *pdwSizeRet);
};

extern "C" CConnectionStream *CreateStream(GUID HostId, DWORD dwPort); 

typedef CConnectionStream *(*CREATESTREAMFUNC)(GUID HostId, DWORD dwPort);

#endif // _TLDEVICE_H_
