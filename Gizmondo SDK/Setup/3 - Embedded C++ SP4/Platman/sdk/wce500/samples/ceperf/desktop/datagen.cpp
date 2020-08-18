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
//
// Module: datagen.c
//
// COMMENTS:  a file containing the constant data structures used by the Performance
//  Monitor data for the Tick Count Sample DLL This file contains a set of constant 
//  data structures which are currently defined for the Tick Count Sample DLL.
//
//**********************************************************************

/*++



--*/
//
//  Include Files
//

#include <windows.h>
#include <winperf.h>
#include "genctrnm.h"
#include "datagen.h"

//----------------------------------------------------------------------
// TODO: Create a static variable for field sizing
//----------------------------------------------------------------------
// dummy variable for field sizing.
static CE_TICK_COUNTER   tickcounter;

//
//  Constant structure initializations
//      defined in datagen.h
//

//----------------------------------------------------------------------
// TODO: Initialize the data definition and counter data structures
//----------------------------------------------------------------------
CE_TICKSTATS_DATA_DEFINITION CE_TickStats_DataDefinition = {

    {sizeof(CE_TICKSTATS_DATA_DEFINITION) + sizeof(CE_TICK_COUNTER),
    sizeof(CE_TICKSTATS_DATA_DEFINITION),
    sizeof(PERF_OBJECT_TYPE),
    CE_TICKSTATS_OBJ,
    0,
    CE_TICKSTATS_OBJ,
    0,
    PERF_DETAIL_ADVANCED,
    (sizeof(CE_TICKSTATS_DATA_DEFINITION)-sizeof(PERF_OBJECT_TYPE))/
        sizeof(PERF_COUNTER_DEFINITION),
    0   // assigned in Open Procedure
    PERF_NO_INSTANCES,
    0
    },

    {   sizeof(PERF_COUNTER_DEFINITION),
    TICK_COUNT,
    0,
    TICK_COUNT,
    0,
    0,
    PERF_DETAIL_ADVANCED,
    PERF_COUNTER_RAWCOUNT,
    sizeof(tickcounter.dwTickCount),
    (DWORD)&(((PCE_TICK_COUNTER)0)->dwTickCount)
    },

};

