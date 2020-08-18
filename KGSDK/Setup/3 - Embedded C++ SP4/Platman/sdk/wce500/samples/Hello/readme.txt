THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

  Copyright (C) 2002  Microsoft Corporation.  All Rights Reserved.


		Sample Application for Remote Call Profiler


This sample consists of two eVC projects (fastcap and callcap).
They are essentially the same projects, except that they have 
different compiler settings.

Callcap has the flag /callcap for all CPUs other than x86 (for x86
we have /Gh).

Fastcap has the flag /fastcap for all CPUS other than x86.  We 
currently dont support this flag for x86.  If you want to insert 
probes on x86 platforms, you can manually make the calls.  Please
refer to the DoHand() function in the source to see how you can
do this.

Please refer to the comments in the source code, or the Windows CE
documentation for more information about Remote Call Profiled, 
the compiler flags that we are using, and these samples.

Instructions:

- Launch eVC and open Hello.vcw
- Select a project as the active project
- Select the platform you want, and build
- Download to device (For more information on how to download and 
  launch Call Profiler, please refer to the documentation)

Overview of sample:

The sample is a simple hello world application built using eVC.  We have
changed the compiler and linker settings (under Project | Settings)  to
enable profiling (For more information on the changes you need to make,
refer to the documentation).

The application demonstrates:
- Single Threaded Work: We do some simple computations to generate some 
  data.
- Multi Threaded Work: We create several threads, and each thread 
  generates data.
- Labels: Demonstrates the use of labels (More information in source code)
- Hand Annotation: We also demonstrate how to make calls to insert probes 
  in your code.  This code has been commented out since it doesn't run on
  all platforms.  Please refer to the comments in the source code for 
  details.

This project has been created using Microsoft eVC 4.0.

