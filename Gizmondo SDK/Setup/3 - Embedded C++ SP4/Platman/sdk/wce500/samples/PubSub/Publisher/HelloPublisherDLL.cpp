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

 MODULE:    HelloPublisherDLL.cpp

 COMMENTS: N/A
***********************************************************************/


#define INITGUID
#include <windows.h>
#include <objbase.h>
#include <ocidl.h>
#include "majfactory.h"

extern HINSTANCE g_hInstance = NULL;

// TestPub headers
#ifdef UNDER_CE
#include "CePubSubPS.h"
#else
#include "CePubSub.h"
#endif

#include "CePubSub_i.c"

#include "HelloPublisher.h"

#include "HelloPublisherDll.h"



TCHAR g_szDllName[MAX_PATH];
BOOL g_fDllCanUnload;

typedef HRESULT (*PFNREGISTER)(LPCTSTR);
typedef HRESULT (*PFNUNREGISTER)(void);
typedef HRESULT (*PFNCREATE)(IUnknown *pUnkOuter, REFIID riid, LPVOID *ppv);
typedef HRESULT (*PFNDLLREGISTER)(LPCTSTR);
typedef HRESULT (*PFNUNDLLREGISTER)(void);


//**********************************************************************
OBJCREATETABLE g_ObjCreateTable[] =
//----------------------------------------------------------------------
//----------------------------------------------------------------------
{
#ifdef UNDER_CE // If the object is on the device
    { &CLSID_HelloPublisher,  CHelloPublisher::CreateInstance },
#endif
};

#define COBJTABLEENTRIES  ( sizeof(g_ObjCreateTable) / sizeof(g_ObjCreateTable[0]) )

//****************************************************************************
PFNDLLREGISTER g_pfnRegisterServer[] =
//----------------------------------------------------------------------
//----------------------------------------------------------------------
{
#ifdef UNDER_CE // If the object is on the device
	CHelloPublisher::RegisterServer,
#endif
};
#define NFNDLLREGISTERCTL  (sizeof(g_pfnRegisterServer)/sizeof(PFNDLLREGISTER))

//****************************************************************************
PFNUNREGISTER g_pfnUnregisterServer[] =
//----------------------------------------------------------------------
//----------------------------------------------------------------------
{
#ifdef UNDER_CE // If the object is on the device
	CHelloPublisher::UnregisterServer,
#endif
};


//**********************************************************************
BOOL WINAPI DllMain(
    HANDLE hModule,
    DWORD dwReason,
    LPVOID lpvReserved
    )
//----------------------------------------------------------------------
//----------------------------------------------------------------------
{
    switch (dwReason)
    {
        case DLL_PROCESS_ATTACH:
			OutputDebugString(L"HelloPublisher, DllMain called, DLL_PROCESS_ATTACH\n");

            g_hInstance = (HINSTANCE) hModule;

			// Set the Dll Name
			GetModuleFileName ((HINSTANCE)hModule,
				               g_szDllName,
							   sizeof(g_szDllName)/sizeof(TCHAR));
			g_fDllCanUnload = FALSE;

			break;

        case DLL_THREAD_ATTACH:
			OutputDebugString(L"HelloPublisher, DllMain called, DLL_THREAD_ATTACH\n");
            break;

        case DLL_THREAD_DETACH:
			OutputDebugString(L"HelloPublisher, DllMain called, DLL_THREAD_DETACH\n");
            break;

        case DLL_PROCESS_DETACH:

			OutputDebugString(L"HelloPublisher, DllMain called, DLL_PROCESS_DETACH\n");
            break;
    }

    return TRUE;
}

//**********************************************************************
STDAPI DllCanUnloadNow(void)
//----------------------------------------------------------------------
//----------------------------------------------------------------------
{
	OutputDebugString(L"****HelloPublisher, DllCanUnloadNow called\n");
    return S_FALSE;
}

//**********************************************************************
STDAPI DllGetClassObject(
    REFCLSID rclsid,
    REFIID riid,
    LPVOID *ppv
    )
//----------------------------------------------------------------------
//----------------------------------------------------------------------
{
    HRESULT hr = S_OK;

    if (riid != IID_IClassFactory)
    {
        hr = E_NOINTERFACE;
    }
    else
    {
        hr = CLASS_E_CLASSNOTAVAILABLE;

        for (int i=0; i<COBJTABLEENTRIES; i++)
        {
            if (rclsid == *g_ObjCreateTable[i].pClsID)
            {
                hr = E_OUTOFMEMORY;

                *ppv = new CClassFactory(g_ObjCreateTable[i].pfnCreate);

                if (ppv != NULL)
                {
                    hr = S_OK;
                }

                break;
            }
        }
    }

    return hr;
}


//****************************************************************************
STDAPI DllRegisterServer(void)
//---------------------------------------------------------------------------
//  Register all component controls in the CE Designers Registry key.
//---------------------------------------------------------------------------
//----------------------------------------------------------------------
//----------------------------------------------------------------------
{
    HRESULT hr = S_OK;                      // function return value

    for (int i=0; i<NFNDLLREGISTERCTL; i++) // iterate defined controls
    {
        if (S_OK != (hr = (*g_pfnRegisterServer[i])(g_szDllName)))
        {                                   // registering control failed
            break;                          // abort
        }
    }
    return hr;                              // result of COM operation
}

//****************************************************************************
STDAPI DllUnregisterServer(void)
//---------------------------------------------------------------------------
//  "Unregister" (expunge) all component controls from the CE Designers
//  Registry key.
//---------------------------------------------------------------------------
{
    HRESULT hr = S_OK;                  // assume success
    HRESULT hrCtl;                      // intermediate return value

    for (int i=0; i<NFNDLLREGISTERCTL; i++) // iterate defined controls
    {
        if (S_OK != (hrCtl = (*g_pfnUnregisterServer[i])()))
        {
            hr = hrCtl;                 // control not unregistered properly
        }
    }
    return hr;                          // result of COM operation
}
