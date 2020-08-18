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


//****************************************************************************
//  TODO:  Create a data structure that will be sent from the device to the
//         desktop.
//
//  The TICK_STATS structure stores the value returned from a call to
//  to GetTickCount()
//
//  TICK_STATS members
//  dwSize          Specifies the version of the structure. Set this
//                  member to sizeof(TICK_STATS) before using the structure
//                  in a function call.
//  dwTickCount     The current value returned by GetTickCount on the device.
//****************************************************************************

#ifndef _CE_TICK_STRUCTS_H_
#define _CE_TICK_STRUCTS_H_


typedef struct _TICK_STATS
{
    DWORD dwSize;                       // sizeof(TICK_STATS)
    DWORD dwTickCount;                  // Current tick count
} TICK_STATS, *PTICK_STATS;

#endif  // _CE_TICK_STRUCTS_H_
