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

 MODULE:  Device.cpp

 COMMENTS: N/A
***********************************************************************/



// Device.cpp: implementation of the CDevice class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "rds.h"
#include "cemgr.h"
#include "cemgr_i.c"
#include "cemgrui.h"
#include "cemgrui_i.c"
#include "Device.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDevice::CDevice() :
m_pDevMgr(NULL),
m_platform(GUID_NULL),
m_device(GUID_NULL)
{

}

CDevice::~CDevice()
{
}

HRESULT CDevice::SelectDevice(GUID &platform, GUID &device)
{
	HRESULT hr;
	platform = GUID_NULL;
	device = GUID_NULL;

	static IPlatformManager *g_piPlatMgr = NULL;

    //----------------------------------------------------------------
    // Establish the Platform Manager object
    //----------------------------------------------------------------
    hr = CoCreateInstance(
            CLSID_PlatformManager,
            NULL,
            CLSCTX_LOCAL_SERVER,
            IID_IPlatformManager,
            (void **) &g_piPlatMgr
            );

    IPlatformManagerUI *piMgrUI = NULL;

    //------------------------------------------------------------------
    // Instantiate the IPlatformManagerUI COM object
    //------------------------------------------------------------------
    hr = CoCreateInstance(
            CLSID_PlatformManagerUI,
            NULL,
            CLSCTX_INPROC_SERVER,
            IID_IPlatformManagerUI,
            (void**) &piMgrUI
            );

    IPlatformCE *piPlatform = NULL;
    IRemoteDevice *piDevice = NULL;

    if (SUCCEEDED(hr))
    {
        //------------------------------------------------------------------
        // Popup a dialog to allow the user to select the device
        //------------------------------------------------------------------
        hr = piMgrUI->GetDevice(NULL, g_piPlatMgr, &piPlatform, &piDevice);

        piMgrUI->Release();
    }

    if (SUCCEEDED(hr))
    {
        hr = piPlatform->GetPlatformId(&platform);
    }

    if (SUCCEEDED(hr))
    {
		hr = piDevice->GetDeviceId(&device);
    }

    if (piPlatform)
    {
        piPlatform->Release();
        piPlatform = NULL;
    }

    if (piDevice)
    {
        piDevice->Release();
        piDevice = NULL;
    }

    if (g_piPlatMgr)
    {
        g_piPlatMgr->Release();
        g_piPlatMgr = NULL;
    }

    if (SUCCEEDED(hr))
    {
		m_platform = platform;
		m_device = device;
	}

	return hr;
}

HRESULT CDevice::ConfigureDevice(HWND hWndParent)
{
	HRESULT hr;

    IPlatformManagerUI *piMgrUI = NULL;
    //------------------------------------------------------------------
    // Instantiate the IPlatformManagerUI COM object
    //------------------------------------------------------------------
    hr = CoCreateInstance(
            CLSID_PlatformManagerUI,
            NULL,
            CLSCTX_INPROC_SERVER,
            IID_IPlatformManagerUI,
            (void**) &piMgrUI
            );

    if (SUCCEEDED(hr))
    {
        //------------------------------------------------------------------
        // Popup a dialog to allow the user to configure the device
        //------------------------------------------------------------------
        hr = piMgrUI->Configure(hWndParent);
        piMgrUI->Release();
    }

	return hr;
}

HRESULT CDevice::DownloadPackage(GUID package)
{
	HRESULT hr = S_OK;

    if (m_pDevMgr == NULL)              // no infrastructure
    {
        hr = CreateDeviceManager(NULL,&m_platform,&m_device,&m_pDevMgr);  // start it up
    }

    if (SUCCEEDED(hr))
    {
		hr = m_pDevMgr->DownloadPackage(package);
	}

	return hr;
}

HRESULT CDevice::RegisterFile(WCHAR* wszRemoteFileName)
{
	HRESULT hr = S_OK;
	if (!wszRemoteFileName)
		return E_FAIL;

    if (m_pDevMgr == NULL)              // no infrastructure
    {
        hr = CreateDeviceManager(NULL,&m_platform,&m_device,&m_pDevMgr);  // start it up
    }

    if (SUCCEEDED(hr))
    {
		hr = m_pDevMgr->RegisterFile(wszRemoteFileName);
	}

	return hr;
}

HRESULT CDevice::Launch(WCHAR *path, WCHAR *cmdLine)
{
	if(m_pDevMgr)
		return m_pDevMgr->Launch(path, cmdLine);
	else
		return E_FAIL;
}

void CDevice::SetDevice(GUID platform, GUID device)
{
	m_platform = platform;
	m_device = device;
}
