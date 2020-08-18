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

 MODULE:   TvCommon.h

 PURPOSE: Header file used by both desktop and Windows CE components of
          the TimeViewer sample application using ITL.

 COMMENTS: N/A
***********************************************************************/
#ifndef _TVCOMMON_H_
#define _TVCOMMON_H_


// TimeViewerID - {5344F94F-E122-430c-A553-62EB86D7671C}
DEFINE_GUID(
    TimeViewerID,
    0x5344f94f, 0xe122, 0x430c, 0xa5, 0x53, 0x62, 0xeb, 0x86, 0xd7, 0x67, 0x1c
    );

typedef enum _CMD_VALUES
{
    CMD_NONE,
    CMD_GET_DATA,
    CMD_FINISHED
} CMD_VALUES;


#endif // _TVCOMMON_H_
