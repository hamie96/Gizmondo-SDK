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
//**********************************************************************
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//**********************************************************************

/*++
Module Name:

    perfgen.c

Abstract:

    This file implements an Extensible Performance Object that displays
    the Tick Count from the Windows CE device

--*/

//
//  Include Files
//

#include <windows.h>
#include <string.h>
#include <winperf.h>
#include <math.h>
#include <tchar.h>
#include <stdio.h>
#include "genctrs.h" // error message definition
#include "perfmsg.h"
#include "perfutil.h"
#include "datagen.h"

//----------------------------------------------------------------------
// TODO: Include the header that defines the data structure that contains
//       the information retrieved by the device.
//----------------------------------------------------------------------
#include "CETickStructs.h"
#include "GetTickData.h"

#include "cemgr.h"

#include "cemgrui.h"
#include "cemgrui_i.c"

#include <initguid.h>
#include "rds.h"

IConnection *g_piConnection = NULL;
IConnectionStream *g_piStream = NULL;

HRESULT
Initialize();

//  define constant value counter's value here, any number will do.

#define CONSTANT_VALUE_VALUE    49

//----------------------------------------------------------------------
// TODO:  Declare extern data definition
//----------------------------------------------------------------------
//  References to constants which initialize the Object type definitions
//
extern CE_TICKSTATS_DATA_DEFINITION CE_TickStats_DataDefinition;

DWORD   dwOpenCount = 0;        // count of "Open" threads
BOOL    bInitOK = FALSE;        // true = DLL initialized OK

//
//  Function Prototypes
//
//      these are used to insure that the data collection functions
//      accessed by Perflib will have the correct calling format.
//
interface IUnknown;
typedef HRESULT (APIENTRY PM_SET_CONN)(IUnknown*);

//----------------------------------------------------------------------
// TODO:  Declare the aliases for the standard function names.  These
//        are the functions listed in CETickStats.cpp
//----------------------------------------------------------------------
PM_SET_CONN     SetITLConnectionCETickStats;
PM_OPEN_PROC    OpenCETickStats;
PM_COLLECT_PROC CollectCETickStats;
PM_CLOSE_PROC   CloseCETickStats;

static
DWORD
GetTimeInMilliSeconds ()
{
    SYSTEMTIME  st;
    DWORD       dwReturn;

    GetSystemTime (&st);
    dwReturn = (DWORD)st.wMilliseconds;
    dwReturn += (DWORD)st.wSecond * 1000L;
    dwReturn += (DWORD)st.wMinute * 60000L;
    dwReturn += (DWORD)st.wHour * 3600000L;
    dwReturn += (DWORD)st.wDay * 86500000L;

    // that's good enough for what it's for

    return dwReturn;
}

//----------------------------------------------------------------------
// TODO:  This is the real function that implements the SetITLConnection
//        function.  In general, this function can remain as is.
//----------------------------------------------------------------------
HRESULT APIENTRY
SetITLConnectionCETickStats(
    IUnknown *pUnk
    )

/*++

Routine Description:

    This routine will retrieve the IConnection interface pointer needed
    by the Platform Manager APIs.

Arguments:

    The IUnknown interface pointer to the IConnection object

Return Value:

    S_OK : if successful.

--*/

{
    HRESULT hr = E_NOINTERFACE;
    g_piStream = NULL;
    g_piConnection = NULL;

	// get the device manager interface
	IRDSDeviceManager* piDeviceManager = NULL;
    if (pUnk)
    {
        hr = pUnk->QueryInterface(IID_IRDSDeviceManager, (void **)&piDeviceManager);
    }

	// get the remote device and platform guid we are connected to
	GUID gdPlatform={0}, gdDevice={0};
	if (SUCCEEDED(hr) && piDeviceManager)
	{
		hr = piDeviceManager->GetConnectionIDs(&gdPlatform, &gdDevice);
	}

	// get the IRemoteDevice* interface based on the device guid we got above
	IRemoteDevice* piDevice = NULL;
	if (SUCCEEDED(hr))
	{
		IPlatformManager* piPlatman = NULL;
		hr = ::CoCreateInstance(CLSID_PlatformManager,
						NULL,
						CLSCTX_ALL,
						IID_IPlatformManager,
						(void **)&piPlatman);
		if (SUCCEEDED(hr) && piPlatman)
		{
			IPlatformCE* piPlatform = NULL;
			hr = piPlatman->GetPlatform(gdPlatform, &piPlatform);
			if (SUCCEEDED(hr) && piPlatform)
			{
				hr = piPlatform->GetDevice(gdDevice, &piDevice);
			}
			if (piPlatform)
			{
				piPlatform->Release();
				piPlatform = NULL;
			}
		}
		if (piPlatman)
		{
			piPlatman->Release();
			piPlatman = NULL;
		}
	}

	IPlatformManagerUI *piPlatManUI = NULL;
	if (SUCCEEDED(hr) && piDevice)
	{
		// get the IConnection interface
		hr = ::CoCreateInstance(CLSID_PlatformManagerUI,
								NULL,
								CLSCTX_INPROC_SERVER,
								IID_IPlatformManagerUI,
								(void **)&piPlatManUI);
	}
	if (SUCCEEDED(hr) && piPlatManUI)
	{
		hr = piPlatManUI->Connect(NULL,
								piDevice,
								&g_piConnection);
	}

	if (piPlatManUI)
	{
		piPlatManUI->Release();
		piPlatManUI = NULL;
	}
	if (piDeviceManager)
	{
		piDeviceManager->Release();
		piDeviceManager = NULL;
	}

    return hr;
}


//----------------------------------------------------------------------
// TODO: This is the Open function.
//----------------------------------------------------------------------
DWORD APIENTRY
OpenCETickStats(
    LPWSTR lpDeviceNames
    )

/*++

Routine Description:

    This routine will initialize the data structures used to pass
    data back to the registry

Arguments:

    Pointer to object ID of each device to be opened (PerfGen)

Return Value:

    None.

--*/

{
    LONG status;
    HKEY hKeyDriverPerf;
    DWORD size;
    DWORD type;
    DWORD dwFirstCounter;
    DWORD dwFirstHelp;

    //
    //  Since WINLOGON is multi-threaded and will call this routine in
    //  order to service remote performance queries, this library
    //  must keep track of how many times it has been opened (i.e.
    //  how many threads have accessed it). the registry routines will
    //  limit access to the initialization routine to only one thread
    //  at a time so synchronization (i.e. reentrancy) should not be
    //  a problem
    //


    if (!dwOpenCount) {
        // open Eventlog interface

        hEventLog = MonOpenEventLog();

        // get counter and help index base values from registry
        //      Open key to registry entry
        //      read First Counter and First Help values
        //      update static data strucutures by adding base to
        //          offset value in structure.

        //--------------------------------------------------------------
        // TODO: Replace parameter 2 with the appropriate subkey name
        //--------------------------------------------------------------
        status = RegOpenKeyEx (
            HKEY_LOCAL_MACHINE,
            "SYSTEM\\CurrentControlSet\\Services\\CETickStats_420\\Performance",
            0L,
            KEY_READ,
            &hKeyDriverPerf);

        if (status != ERROR_SUCCESS) {
            REPORT_ERROR_DATA (GENPERF_UNABLE_OPEN_DRIVER_KEY, LOG_USER,
                &status, sizeof(status));
            // this is fatal, if we can't get the base values of the
            // counter or help names, then the names won't be available
            // to the requesting application  so there's not much
            // point in continuing.
            goto OpenExitPoint;
        }

        size = sizeof (DWORD);
        status = RegQueryValueEx(
                    hKeyDriverPerf,
                    "First Counter",
                    0L,
                    &type,
                    (LPBYTE)&dwFirstCounter,
                    &size);

        if (status != ERROR_SUCCESS) {
            REPORT_ERROR_DATA (GENPERF_UNABLE_READ_FIRST_COUNTER, LOG_USER,
                &status, sizeof(status));
            // this is fatal, if we can't get the base values of the
            // counter or help names, then the names won't be available
            // to the requesting application  so there's not much
            // point in continuing.
            goto OpenExitPoint;
        }

        size = sizeof (DWORD);
        status = RegQueryValueEx(
                    hKeyDriverPerf,
                    "First Help",
                    0L,
                    &type,
                    (LPBYTE)&dwFirstHelp,
            &size);

        if (status != ERROR_SUCCESS) {
            REPORT_ERROR_DATA (GENPERF_UNABLE_READ_FIRST_HELP, LOG_USER,
                &status, sizeof(status));
            // this is fatal, if we can't get the base values of the
            // counter or help names, then the names won't be available
            // to the requesting application  so there's not much
            // point in continuing.
            goto OpenExitPoint;
        }

        //
        //  NOTE: the initialization program could also retrieve
        //      LastCounter and LastHelp if they wanted to do
        //      bounds checking on the new number. e.g.
        //
        //      counter->CounterNameTitleIndex += dwFirstCounter;
        //      if (counter->CounterNameTitleIndex > dwLastCounter) {
        //          LogErrorToEventLog (INDEX_OUT_OF_BOUNDS);
        //      }

        //--------------------------------------------------------------
        // TODO:  Set the data definition values
        //--------------------------------------------------------------
        CE_TickStats_DataDefinition.CETickStatsObjectType.ObjectNameTitleIndex += dwFirstCounter;
        CE_TickStats_DataDefinition.CETickStatsObjectType.ObjectHelpTitleIndex += dwFirstHelp;

        // assign index of default counter (Sine Wave)
        CE_TickStats_DataDefinition.CETickStatsObjectType.DefaultCounter = 0;

        //--------------------------------------------------------------
        // TODO: Add one pair of definitions for each *def variable in
        // Data Definition (datagen.h)
        //--------------------------------------------------------------
        CE_TickStats_DataDefinition.TickCountDef.CounterNameTitleIndex += dwFirstCounter;
        CE_TickStats_DataDefinition.TickCountDef.CounterHelpTitleIndex += dwFirstHelp;

        RegCloseKey (hKeyDriverPerf); // close key to registry

        bInitOK = TRUE; // ok to use this function
    }

    InitializeRemoteData();

    dwOpenCount++;  // increment OPEN counter

    status = ERROR_SUCCESS; // for successful exit

OpenExitPoint:

    return status;
}

//----------------------------------------------------------------------
// TODO: This is the Collect function.
//----------------------------------------------------------------------
DWORD APIENTRY
CollectCETickStats(
    IN      LPWSTR  lpValueName,
    IN OUT  LPVOID  *lppData,
    IN OUT  LPDWORD lpcbTotalBytes,
    IN OUT  LPDWORD lpNumObjectTypes
)
/*++

Routine Description:

    This routine will return the data for the Signal Generator counters.

Arguments:

   IN       LPWSTR   lpValueName
         pointer to a wide character string passed by registry.

   IN OUT   LPVOID   *lppData
         IN: pointer to the address of the buffer to receive the completed
            PerfDataBlock and subordinate structures. This routine will
            append its data to the buffer starting at the point referenced
            by *lppData.
         OUT: points to the first byte after the data structure added by this
            routine. This routine updated the value at lppdata after appending
            its data.

   IN OUT   LPDWORD  lpcbTotalBytes
         IN: the address of the DWORD that tells the size in bytes of the
            buffer referenced by the lppData argument
         OUT: the number of bytes added by this routine is writted to the
            DWORD pointed to by this argument

   IN OUT   LPDWORD  NumObjectTypes
         IN: the address of the DWORD to receive the number of objects added
            by this routine
         OUT: the number of objects added by this routine is writted to the
            DWORD pointed to by this argument

Return Value:

      ERROR_MORE_DATA if buffer passed is too small to hold data
         any error conditions encountered are reported to the event log if
         event logging is enabled.

      ERROR_SUCCESS  if success or any other error. Errors, however are
         also reported to the event log.

--*/
{
    //  Variables for reformating the data

    ULONG SpaceNeeded;
    DWORD   dwQueryType;
    //------------------------------------------------------------------
    // TODO: Create a pointer to a data definition structure and counter
    //------------------------------------------------------------------
    CE_TICKSTATS_DATA_DEFINITION *pCE_TickStats_DataDefinition;
    CE_TICK_COUNTER *   pTickCounter;
    static TICK_STATS TickStats = {0};

    //
    // before doing anything else, see if Open went OK
    //
    if (!bInitOK ) {
        // unable to continue because open failed.
        *lpcbTotalBytes = (DWORD) 0;
        *lpNumObjectTypes = (DWORD) 0;
        return ERROR_SUCCESS; // yes, this is a successful exit
    }


    // see if this is a foreign (i.e. non-NT) computer data request
    //
    dwQueryType = GetQueryType (lpValueName);

    if (dwQueryType == QUERY_FOREIGN) {
        // this routine does not service requests for data from
        // Non-NT computers
        *lpcbTotalBytes = (DWORD) 0;
        *lpNumObjectTypes = (DWORD) 0;
        return ERROR_SUCCESS;
    }

    if (dwQueryType == QUERY_ITEMS){
    //------------------------------------------------------------------
    // TODO: Replace this with reference to the data definition structure
    //------------------------------------------------------------------
    if ( !(IsNumberInUnicodeList (CE_TickStats_DataDefinition.CETickStatsObjectType.ObjectNameTitleIndex, lpValueName))) {
            // request received for data object not provided by this routine
            *lpcbTotalBytes = (DWORD) 0;
            *lpNumObjectTypes = (DWORD) 0;
            return ERROR_SUCCESS;
        }
    }


    //------------------------------------------------------------------
    // TODO: Replace these with reference to the data definition structure
    //------------------------------------------------------------------
    pCE_TickStats_DataDefinition = (CE_TICKSTATS_DATA_DEFINITION *) *lppData;

    SpaceNeeded = sizeof(CE_TICKSTATS_DATA_DEFINITION) + sizeof(CE_TICK_COUNTER);
    /* ~gs          (NUM_INSTANCES * (sizeof(PERF_INSTANCE_DEFINITION) +
          (24) +    // size of instance names
          sizeof (CE_TICK_COUNTER)));
          */

    if ( *lpcbTotalBytes < SpaceNeeded ) {
        *lpcbTotalBytes = (DWORD) 0;
        *lpNumObjectTypes = (DWORD) 0;
        return ERROR_MORE_DATA;
    }

    //
    // Copy the (constant, initialized) Object Type and counter definitions
    //  to the caller's data buffer
    //
    //------------------------------------------------------------------
    // TODO: Replace these with reference to the data definition structure
    //------------------------------------------------------------------
    memmove(pCE_TickStats_DataDefinition,
       &CE_TickStats_DataDefinition,
       sizeof(CE_TICKSTATS_DATA_DEFINITION));

    //------------------------------------------------------------------
    // TODO: Replace these with reference to the data definition structure
    //------------------------------------------------------------------
    pTickCounter = (CE_TICK_COUNTER *)((LPBYTE)(*lppData) + sizeof(CE_TICKSTATS_DATA_DEFINITION));


    //------------------------------------------------------------------
    // TODO: CAll the function that gets the data from the device
    //------------------------------------------------------------------
    // Get the data
    HRESULT hr = GetTickPerf(&TickStats);

    if(FAILED(hr))
    {
        return hr;
    }

    //------------------------------------------------------------------
    // TODO: Replace these with reference to the counter structure
    //------------------------------------------------------------------
    pTickCounter->CounterBlock.ByteLength = sizeof(CE_TICK_COUNTER);
    pTickCounter->dwTickCount = TickStats.dwTickCount;


    // update arguments for return

    //------------------------------------------------------------------
    // TODO: Replace this with reference to the counter structure
    //------------------------------------------------------------------
    *((LPBYTE*)lppData) += sizeof(CE_TICKSTATS_DATA_DEFINITION) + sizeof(CE_TICK_COUNTER);

    *lpNumObjectTypes = 1;

    //------------------------------------------------------------------
    // TODO: Replace this with reference to the counter structure
    //------------------------------------------------------------------
    *lpcbTotalBytes = sizeof(CE_TICKSTATS_DATA_DEFINITION) + sizeof(CE_TICK_COUNTER);

    //------------------------------------------------------------------
    // TODO: Replace this with reference to the data definition structure
    //------------------------------------------------------------------
    pCE_TickStats_DataDefinition->CETickStatsObjectType.TotalByteLength =  *lpcbTotalBytes ;

    //------------------------------------------------------------------
    // TODO: Replace this with reference to the data definition structure
    //------------------------------------------------------------------
    // update instance count
    pCE_TickStats_DataDefinition->CETickStatsObjectType.NumInstances = PERF_NO_INSTANCES;

    return ERROR_SUCCESS;
}

//----------------------------------------------------------------------
// TODO: This is the Close function
//----------------------------------------------------------------------
DWORD APIENTRY
CloseCETickStats(
)

/*++

Routine Description:

    This routine closes the open handles to the Signal Gen counters.

Arguments:

    None.


Return Value:

    ERROR_SUCCESS

--*/

{
    if (!(--dwOpenCount)) { // when this is the last thread...

        MonCloseEventLog();
    }

    UninitializeRemoteData();
    return ERROR_SUCCESS;

}


