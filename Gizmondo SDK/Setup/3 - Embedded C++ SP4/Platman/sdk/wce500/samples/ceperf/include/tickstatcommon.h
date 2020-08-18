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

 MODULE:   TickStatCommon.h

 PURPOSE: Header file used by both desktop and Windows CE components of
          the CEPerfmon sample using ITL.

 COMMENTS: N/A
***********************************************************************/
#ifndef _TICKSTATCOMMON_H_
#define _TICKSTATCOMMON_H_

// TickViewerPkgID - {F613CB32-F687-4120-A386-F0E92C9E82F9}
DEFINE_GUID(
    TickViewerPkgID,
    0xF613CB32, 0xF687, 0x4120, 0xA3, 0x86, 0xF0, 0xE9, 0x2C, 0x9E, 0x82, 0xF9
    );

// TickViewerID - {C21B0E51-A06A-4d42-8831-CC974D31FD94}
DEFINE_GUID(
    TickViewerID,
    0xc21b0e51, 0xa06a, 0x4d42, 0x88, 0x31, 0xcc, 0x97, 0x4d, 0x31, 0xfd, 0x94
    );

typedef enum _CMD_VALUES
{
    CMD_NONE,
    CMD_GET_DATA,
    CMD_FINISHED
} CMD_VALUES;


#endif // _TICKSTATCOMMON_H_
