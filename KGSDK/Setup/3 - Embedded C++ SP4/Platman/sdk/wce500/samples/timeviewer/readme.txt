TimeViewer Sample ReadMe.txt

------------
Introduction
------------
The TimeViewer sample application demonstrates the basic requirements
needed to develop a remote Windows CE tool using the Platform Manager
APIs.  TimeViewer is a very simple application that displays the
Windows CE device's system time.

TimeViewer consists of 2 executables.  TimeViewer.exe is the desktop
component that intiates the communication to the device component and
presents the user interface.  TimeViewerCE.exe is the device component
that responds to commands sent by TimeViewer.exe.


----------------------------
Build the desktop executable
----------------------------
The Visual Studio 6.0 project file for the desktop component is
called Samples\TimeViewer\desktop\TimeViewer.dsp

Perform Rebuild All to create the exe: Samples\bin\TimeViewer.exe


--------------------------
Build the device component
--------------------------
The eMbedded Visual C++ 3.0 project file for device component
is called Samples\TimeViewer\Device\TimeViewerCE.vcp

Select the appropriate platform: Build | Select Active Platform.
Select the appropriate processor type: Build | Set Active Configuration.

Perform Rebuild All to create the executable.

Repeat these steps for each platform & processor.

NOTE: The .vcp file supports ARM, Mips, SH3, SH4, and x86 processors.
If you add other configurations, update the Additional include
directories setting.

    From the eVC++ menu: Project | Settings
    In the Settings For: edit box, select "All configurations".
    Click on the C/C++ tab.
    In the Category edit box, select Preprocessor.
    In the Additional include directories edit box, type
    "..\include,..\..\..\Platman\include". Click on OK.

------------------
Running TimeViewer
------------------

1.  Register the package.

    If you have already executed the SamplesReg.vbs script, it is not
    necessary to run it again.  This script registers the
    packages for these samples: CEPerf, TimeViewer

    This needs to be performed once to register the device component of
    the application.  This registration allows the desktop component to
    identify where TimeViewerCE.exe is located.  Package registration
    also allows for CPU specific versions to be installed.
    For this sample, TimeViewer is registered only as a top level
    package so that it may be run on all platforms.

    a. Open a command window and change to the Samples\bin directory.
    b. Execute the registration script

            SamplesReg.vbs <fullpath>

       Replace <fullpath> with the fully-qualified pathname to the
       Samples\bin directory.  For example,

       SamplesReg.vbs "C:\Program Files\Windows CE Platform Builder\4.00\Samples\Bin"

2.  Use Platform Builder to build and download a platform to your
    development device.

3.  Run TimeViewer.exe

    a. Launch it from the command line.
    b. Configure and test the connection as you would with any remote tool.

-------------------------
Desktop Component Details
-------------------------

Establishing the connection
---------------------------
This functionality can be found in the ConnectToDevice function in
TimeViewer.cpp.

The steps required to establish a connection between the desktop and
device components are:

    1.  Instantiate IPlatformManager and IPlatformManagerUI COM objects.
    2.  Call the IPlatformManagerUI::GetDevice.
        This method presents the dialog that allows the user to
        select the Windows CE device.

    3.  Call IPlatformManagerUI Connect method.
        This method establishes the connection between the desktop and
        the device.

    4.  Call IConnection::QueuePackage and IConnection::CopyQueuedFiles.
        These methods use the package registered in SamplesReg.vbs.
        The net effect is that the device
        component of the application (TimeViewerCE.exe) is copied down
        to the Windows CE device.

    5.  Call IConnection::Launch to start TimeViewerCE.exe.

    6.  Call IConnection::CreateStream.
        This establishes a communication stream between TimeViewer.exe
        and TimeViewerCE.exe.  This returns an interface pointer to an
        IConnectionStream object.

    7.  Release the interface pointers.


Obtain the data to be displayed.
--------------------------------
This functionality can be found in the Refresh function in
TimeViewer.cpp.

    1.  Call IConnectionStream::Send to send a command that will cause
        TimeViewerCE.exe to obtain the current system time.

    2.  Call IConnectionStream::ReadBytes to get a SYSTEMTIME structure
        from TimeViewerCE.exe.

    3.  Format and display the current system time.


Disconnect from the device.
---------------------------
This functionality can be found in the DisconnectFromDevice function in
TimeViewer.cpp.

    1.  Call IConnectionStream::Send to send a command that will cause
        TimeViewerCE.exe to exit.

    2.  Call IConnectionStream::Close to close the stream and then
        IConnectionStream::Release to release the interface pointer.




------------------------
Device Component Details
------------------------
The device component, TimeViewerCE.cpp is very simple and is composed of
3 parts.

    1.  Load the Platform Manager DLL and create a stream
        (InitializeITL).

    2.  A loop that reads bytes from the desktop and either sends back
        the system time or causes itself to exit.

    3.  A function that closes the connection stream (Cleanup).
