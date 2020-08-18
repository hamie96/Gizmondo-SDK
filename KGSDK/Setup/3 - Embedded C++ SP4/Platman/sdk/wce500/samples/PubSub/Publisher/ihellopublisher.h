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

 MODULE:    IHelloPublisher.h

 PURPOSE:   Device object for sample application (SampleObject)

 COMMENTS: N/A
***********************************************************************/


// IHelloPublisher.h: interface for the IHelloPublisher class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _IHelloPublisher_H
#define _IHelloPublisher_H

// {5E595178-5C48-47d1-A1F7-7EB909897C4A}
DEFINE_GUID(IID_IHelloPublisher, 
0x5e595178, 0x5c48, 0x47d1, 0xa1, 0xf7, 0x7e, 0xb9, 0x9, 0x89, 0x7c, 0x4a);

interface IHelloPublisher : public IPublisher, public IPublisherManagement
{

};

#endif 
