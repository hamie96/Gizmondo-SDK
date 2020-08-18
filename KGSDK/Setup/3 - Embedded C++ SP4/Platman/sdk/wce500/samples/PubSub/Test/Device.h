//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
//
// Use of this source code is subject to the terms of the Microsoft end-user
// license agreement (EULA) under which you licensed this SOFTWARE PRODUCT.
// If you did not accept the terms of the EULA, you are not authorized to use
// this source code. For a copy of the EULA, please see the LICENSE.RTF on your
// install media.
//
/***********************************************************************
 THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
 ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
 PARTICULAR PURPOSE.

 MODULE:  Device.h

 COMMENTS: N/A
***********************************************************************/

#ifndef _DEVICE_H
#define _DEVICE_H

#include "CePubSub.h"

interface IRDSDeviceManager;

class CDevice  
{
public:
	void SetDevice(GUID platform, GUID device);
	HRESULT Launch(WCHAR *path, WCHAR *cmdLine);
	HRESULT DownloadPackage(GUID package);
	HRESULT SelectDevice(GUID &platform, GUID &device);
	HRESULT ConfigureDevice(HWND hWndParent);
	HRESULT RegisterFile(WCHAR* wszRemoteFileName);

	CDevice();
	virtual ~CDevice();

private:
	GUID m_platform;
	GUID m_device;
    IRDSDeviceManager *m_pDevMgr;       // device manager
};

#endif 
