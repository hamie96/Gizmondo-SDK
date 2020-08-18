<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: SysMessages - Win32 (WCE ARMV4I) Release--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "rc.exe /l 0x409 /fo"ARMV4IRel/SysMessages.res" /d UNDER_CE=420 /d _WIN32_WCE=420 /d "UNICODE" /d "_UNICODE" /d "NDEBUG" /d "WCE_PLATFORM_GTERM" /d "THUMB" /d "_THUMB_" /d "ARM" /d "_ARM_" /d "ARMV4I" /r "C:\Working\GIZMONDO\DEVELOPER SAMPLES\SysMessages\SysMessages.rc"" 
Creating temporary file "C:\DOCUME~1\DeanW\LOCALS~1\Temp\RSP188.tmp" with contents
[
/nologo /W3 /D _WIN32_WCE=420 /D "ARM" /D "_ARM_" /D "WCE_PLATFORM_GTERM" /D "ARMV4I" /D UNDER_CE=420 /D "UNICODE" /D "_UNICODE" /D "NDEBUG" /Fp"ARMV4IRel/SysMessages.pch" /Yu"stdafx.h" /Fo"ARMV4IRel/" /QRarch4T /QRinterwork-return /O2 /MC /c 
"C:\Working\GIZMONDO\DEVELOPER SAMPLES\SysMessages\SysMessages.cpp"
]
Creating command line "clarm.exe @C:\DOCUME~1\DeanW\LOCALS~1\Temp\RSP188.tmp" 
Creating temporary file "C:\DOCUME~1\DeanW\LOCALS~1\Temp\RSP189.tmp" with contents
[
/nologo /W3 /D _WIN32_WCE=420 /D "ARM" /D "_ARM_" /D "WCE_PLATFORM_GTERM" /D "ARMV4I" /D UNDER_CE=420 /D "UNICODE" /D "_UNICODE" /D "NDEBUG" /Fp"ARMV4IRel/SysMessages.pch" /Yc"stdafx.h" /Fo"ARMV4IRel/" /QRarch4T /QRinterwork-return /O2 /MC /c 
"C:\Working\GIZMONDO\DEVELOPER SAMPLES\SysMessages\StdAfx.cpp"
]
Creating command line "clarm.exe @C:\DOCUME~1\DeanW\LOCALS~1\Temp\RSP189.tmp" 
Creating temporary file "C:\DOCUME~1\DeanW\LOCALS~1\Temp\RSP18A.tmp" with contents
[
commctrl.lib coredll.lib /nologo /base:"0x00010000" /stack:0x10000,0x1000 /entry:"WinMainCRTStartup" /incremental:no /pdb:"ARMV4IRel/SysMessages.pdb" /nodefaultlib:"libc.lib /nodefaultlib:libcd.lib /nodefaultlib:libcmt.lib /nodefaultlib:libcmtd.lib /nodefaultlib:msvcrt.lib /nodefaultlib:msvcrtd.lib" /out:"ARMV4IRel/SysMessages.exe" /subsystem:windowsce,4.20 /MACHINE:THUMB 
".\ARMV4IRel\StdAfx.obj"
".\ARMV4IRel\SysMessages.obj"
".\ARMV4IRel\SysMessages.res"
]
Creating command line "link.exe @C:\DOCUME~1\DeanW\LOCALS~1\Temp\RSP18A.tmp"
<h3>Output Window</h3>
Compiling resources...
Compiling...
StdAfx.cpp
Compiling...
SysMessages.cpp
Linking...




<h3>Results</h3>
SysMessages.exe - 0 error(s), 0 warning(s)
</pre>
</body>
</html>
