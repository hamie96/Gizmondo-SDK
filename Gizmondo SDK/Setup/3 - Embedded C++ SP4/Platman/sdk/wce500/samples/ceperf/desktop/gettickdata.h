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
#ifndef _GETTICKDATA_H_
#define _GETTICKDATA_H_

#define IConnection IConnectionCE
#define IConnectionStream IConnectionStreamCE

HRESULT InitializeRemoteData();
HRESULT AddConnection(HWND hWnd);
void UninitializeRemoteData();

//----------------------------------------------------------------------
// TODO: Prototype for the function that gets the data from the device
//----------------------------------------------------------------------
HRESULT GetTickPerf(TICK_STATS *pTickStats);

#endif // _GETTICKDATA_H_
