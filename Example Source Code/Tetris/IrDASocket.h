//	IrDASocket.h - Bubbles for Pocket PC (IrDA socket support)
//
//	Copyright (C) 2000-2004 Ramon de Klein (Ramon.de.Klein@ict.nl)
//
//	This program is free software; you can redistribute it and/or modify
//	it under the terms of the GNU General Public License as published by
//	the Free Software Foundation; either version 2 of the License, or
//	(at your option) any later version.
//
//	This program is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//	GNU General Public License for more details.
//
//	You should have received a copy of the GNU General Public License
//	along with this program; if not, write to the Free Software
//	Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

#ifndef __IRDASOCKET_H
#define __IRDASOCKET_H


class CWinSock
{
private:
	static int		mg_iInstance;
	static WSADATA	mg_wsaData;

public:
	CWinSock()
	{
		// Only initialize WinSock the first time
		if (++mg_iInstance == 1)
		{
			WSAStartup(MAKEWORD(1,1), &mg_wsaData);
		}
	}

	~CWinSock()
	{
		// Cleanup WinSock when the last instance is gone
		if (--mg_iInstance == 0)
		{
			WSACleanup();
		}
	}
};

class CIrDASocket
{
private:
	SOCKET m_sd;

public:
	CIrDASocket()
		: m_sd(INVALID_SOCKET) 
	{
	}

	~CIrDASocket()
	{
		// Close socket if left open
		if (m_sd != INVALID_SOCKET)
			closesocket(m_sd);
	}

	bool WaitForOperation (const bool fRead, const bool fWrite, const DWORD dwTimeout)
	{
		// Check if the call would block
		const int iError = WSAGetLastError();
		if (iError != WSAEWOULDBLOCK)
		{
			ATLTRACE(_T("WaitForOperation called unexpectedly (error=%08Xh).\n"),iError);
			return false;
		}

		// Setup the socket descriptors
		fd_set fdsRead  = {0};
		fdsRead.fd_count    = 1;
		fdsRead.fd_array[0] = m_sd;

		fd_set fdsWrite = {0};
		fdsWrite.fd_count    = 1;
		fdsWrite.fd_array[0] = m_sd;

		// Setup the timeout structure
		struct timeval tv = {0};
		if (dwTimeout != INFINITE)
		{
			// Convert to correct values
			tv.tv_sec  = dwTimeout/1000;
			tv.tv_usec = dwTimeout%1000;
		}

		// Wait for the socket to accept
		if (select(0,fRead?&fdsRead:0,fWrite?&fdsWrite:0,0,(dwTimeout!=INFINITE)?&tv:0) == 0)
		{
			ATLTRACE(_T("WaitForOperation select failed (error=%08Xh).\n"),WSAGetLastError());
			return false;
		}

		// Return successful
		ATLTRACE(_T("WaitForOperation succeeded.\n"));
		return true;
	}

	bool EnumDevices (DEVICELIST* pDevList, int cbDevices)
	{
		// Check pre-conditions
		ATLASSERT(m_sd != INVALID_SOCKET);
		ATLASSERT(pDevList != 0);

		// Obtain the available devices
		pDevList->numDevice = 0;
		if (getsockopt(m_sd,SOL_IRLMP,IRLMP_ENUMDEVICES,reinterpret_cast<char*>(pDevList),&cbDevices) == SOCKET_ERROR)
			return false;

		// Return successful
		return true;
	}

	bool Open()
	{
		// Check pre-conditions
		ATLASSERT(m_sd == INVALID_SOCKET);

		// Open socket
		m_sd = socket(AF_IRDA,SOCK_STREAM,0);
		if (m_sd == INVALID_SOCKET)
			return false;

		// Set socket as non-blocking socket
		u_long ulArg = 1;
		if (ioctlsocket(m_sd,FIONBIO,&ulArg) == SOCKET_ERROR)
			return false;

		// Return succcesful
		return true;
	}

	bool Close()
	{
		// Only open sockets can be closed
		if (m_sd == INVALID_SOCKET)
			return false;

		// Close socket
		closesocket(m_sd);
		m_sd = INVALID_SOCKET;

		// Return succcesful
		return true;
	}

	bool Bind (LPCSTR lpszServiceName)
	{
		SOCKADDR_IRDA sa = {0};

		// Check pre-conditions
		ATLASSERT(m_sd != INVALID_SOCKET);
		ATLASSERT(lpszServiceName != 0);
		ATLASSERT(strlen(lpszServiceName) < sizeof(sa.irdaServiceName));

		// Set the socket address
		sa.irdaAddressFamily = AF_IRDA;
		strcpy(sa.irdaServiceName,lpszServiceName);
		
		// Associate the server socket address with the server socket
		if (bind(m_sd,reinterpret_cast<SOCKADDR*>(&sa),sizeof(sa)) == SOCKET_ERROR)
			return false;

		// Return succcesful
		return true;
	}

	bool Listen (const int iBackLog=1)
	{
		// Check pre-conditions
		ATLASSERT(m_sd != INVALID_SOCKET);

		// Establish a socket to listen for incoming connections
		if (listen(m_sd,iBackLog) == SOCKET_ERROR) 
			return false;

		// Return succcesful
		return true;
	}

	bool Accept (SOCKET* psd, const DWORD dwTimeout)
	{
		// Check pre-conditions
		ATLASSERT(m_sd != INVALID_SOCKET);
		ATLASSERT(psd != 0);

		// Accept a connection
		SOCKET sd = accept(m_sd,0,0);
		if (sd == INVALID_SOCKET)
		{
			// Wait for operation to complete
			if (!WaitForOperation(true,false,dwTimeout))
				return false;

			// Accept a connection
			sd = accept(m_sd,0,0);
			if (sd == INVALID_SOCKET)
				return false;
		}

		// Set socket as non-blocking socket
		u_long ulArg = 1;
		if (ioctlsocket(sd,FIONBIO,&ulArg) == SOCKET_ERROR)
			return false;

		// Set socket descriptor and return
		*psd = sd;
		return true;
	}

	bool Connect (LPCSTR lpszServiceName, const LPBYTE pDeviceId, const DWORD dwTimeout)
	{
		SOCKADDR_IRDA sa = {0};

		// Check pre-conditions
		ATLASSERT(m_sd != INVALID_SOCKET);
		ATLASSERT(lpszServiceName != 0);
		ATLASSERT(strlen(lpszServiceName) < sizeof(sa.irdaServiceName));

		// Setup the IrDA address
		sa.irdaAddressFamily = AF_IRDA;
		strcpy(sa.irdaServiceName,lpszServiceName);
		memcpy(sa.irdaDeviceID,pDeviceId,sizeof(sa.irdaDeviceID));

		// Try to connect
		if (connect(m_sd,reinterpret_cast<SOCKADDR*>(&sa),sizeof(sa)) == SOCKET_ERROR)
		{
			// Wait for operation to complete
			if (!WaitForOperation(false,true,dwTimeout))
				return false;
		}

		// Return succesful
		return true;
	}

	bool Send (LPCVOID lpData, DWORD cbBytes, const DWORD dwTimeout)
	{
		ATLASSERT(m_sd != INVALID_SOCKET);

		ATLTRACE(_T("Send(%d) operation started.\n"),cbBytes);

		// Try to send the data
		DWORD dwBytes = send(m_sd,reinterpret_cast<const char*>(lpData),cbBytes,0);
		if (dwBytes != cbBytes)
		{
			ATLTRACE(_T("Send(%d) operation cannot complete synchronous.\n"),cbBytes);

			// Wait for operation to complete
			if (!WaitForOperation(false,true,dwTimeout))
			{
				ATLTRACE(_T("Send(%d) operation failed.\n"),cbBytes);
				return false;
			}

			// Retry the send operation
			dwBytes = send(m_sd,reinterpret_cast<const char*>(lpData),cbBytes,0);
			if (dwBytes != cbBytes)
				return false;
		}

		// Return succesful
		ATLTRACE(_T("Send(%d) operation succeeded.\n"),cbBytes);
		return true;
	}

	template <class T> bool Send (const T& data, const DWORD dwTimeout)
	{
		return Send(&data,sizeof(T),dwTimeout);
	}


	bool Receive (LPVOID lpData, DWORD cbBytes, const DWORD dwTimeout)
	{
		ATLASSERT(m_sd != INVALID_SOCKET);

		// Try to Receive the data
		DWORD dwBytes = recv(m_sd,reinterpret_cast<char*>(lpData),cbBytes,0);
		if (dwBytes != cbBytes)
		{
			ATLTRACE(_T("Receive(%d) operation cannot complete synchronous.\n"),cbBytes);

			// Wait for operation to complete
			if (!WaitForOperation(true,false,dwTimeout))
			{
				ATLTRACE(_T("Receive(%d) operation failed.\n"),cbBytes);
				return false;
			}

			// Retry the read operation
			dwBytes = recv(m_sd,reinterpret_cast<char*>(lpData),cbBytes,0);
			if (dwBytes != cbBytes)
				return false;
		}

		// Return succesful
		ATLTRACE(_T("Receive(%d) operation succeeded.\n"),cbBytes);
		return true;
	}

	template <class T> bool Receive (T& data, const DWORD dwTimeout)
	{
		return Receive(&data,sizeof(T),dwTimeout);
	}

	operator SOCKET()
	{
		return m_sd;
	}

	SOCKET* operator& ()
	{
		ATLASSERT(m_sd == INVALID_SOCKET);
		return &m_sd;
	}
};


#endif	// __IRDASOCKET_H