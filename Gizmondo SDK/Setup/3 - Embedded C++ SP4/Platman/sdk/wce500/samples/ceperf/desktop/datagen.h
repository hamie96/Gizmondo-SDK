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

      DATAGEN.h

Abstract:

    Header file for the tick count performance counter.

    This file contains definitions to construct the dynamic data
    which is returned by the Configuration Registry.  Data from
    various system API calls is placed into the structures shown
    here.

--*/

#ifndef _DATAGEN_H_
#define _DATAGEN_H_

//
//  insure packing is done to the 8 byte align longlong data values. This
//  will eliminate alignment faults on RISC platforms. The fields can be
//  manually arranged to minimize or eliminate wasted space if necessary.
//
#pragma pack (8)

//
//  Extensible Object definitions
//

//----------------------------------------------------------------------
//  TODO: Update the following sort of define when adding an object type.
//----------------------------------------------------------------------
#define CE_TICKPERF_NUM_PERF_OBJECT_TYPES 1

//----------------------------------------------------------------------
//  TODO: Create a data definition structure
//----------------------------------------------------------------------
//  Perf Gen Resource object type counter definitions.
//
//  This is the counter structure presently returned by the generator
//
typedef struct _CE_TICKPERF_DATA_DEFINITION {
    PERF_OBJECT_TYPE        CETickStatsObjectType;
    PERF_COUNTER_DEFINITION TickCountDef;
} CE_TICKSTATS_DATA_DEFINITION;

//----------------------------------------------------------------------
// TODO: Create a counter data structure
//----------------------------------------------------------------------
// This is the block of data that corresponds to each instance of the
// object. This structure will immediately follow the instance definition
// data structure
//
typedef struct _CE_TICK_COUNTER {
    PERF_COUNTER_BLOCK      CounterBlock;
    DWORD   dwTickCount;
} CE_TICK_COUNTER, *PCE_TICK_COUNTER;

#pragma pack ()

#endif //_DATAGEN_H_
