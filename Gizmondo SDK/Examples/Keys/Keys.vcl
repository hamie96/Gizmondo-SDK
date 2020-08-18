<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: Keys - Win32 (WCE ARMV4I) Release--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "rc.exe /l 0x409 /fo"ARMV4IRel/Keys.res" /d UNDER_CE=420 /d _WIN32_WCE=420 /d "UNICODE" /d "_UNICODE" /d "NDEBUG" /d "WCE_PLATFORM_GTERM" /d "THUMB" /d "_THUMB_" /d "ARM" /d "_ARM_" /d "ARMV4I" /r "C:\Working\GIZMONDO\DEVELOPER SAMPLES\Keys\Keys.rc"" 
Creating temporary file "C:\DOCUME~1\DeanW\LOCALS~1\Temp\RSP16C.tmp" with contents
[
/nologo /W3 /D _WIN32_WCE=420 /D "ARM" /D "_ARM_" /D "WCE_PLATFORM_GTERM" /D "ARMV4I" /D UNDER_CE=420 /D "UNICODE" /D "_UNICODE" /D "NDEBUG" /Fp"ARMV4IRel/Keys.pch" /Yu"stdafx.h" /Fo"ARMV4IRel/" /QRarch4T /QRinterwork-return /O2 /MC /c 
"C:\Working\GIZMONDO\DEVELOPER SAMPLES\Keys\Keys.cpp"
]
Creating command line "clarm.exe @C:\DOCUME~1\DeanW\LOCALS~1\Temp\RSP16C.tmp" 
Creating temporary file "C:\DOCUME~1\DeanW\LOCALS~1\Temp\RSP16D.tmp" with contents
[
/nologo /W3 /D _WIN32_WCE=420 /D "ARM" /D "_ARM_" /D "WCE_PLATFORM_GTERM" /D "ARMV4I" /D UNDER_CE=420 /D "UNICODE" /D "_UNICODE" /D "NDEBUG" /Fp"ARMV4IRel/Keys.pch" /Yc"stdafx.h" /Fo"ARMV4IRel/" /QRarch4T /QRinterwork-return /O2 /MC /c 
"C:\Working\GIZMONDO\DEVELOPER SAMPLES\Keys\StdAfx.cpp"
]
Creating command line "clarm.exe @C:\DOCUME~1\DeanW\LOCALS~1\Temp\RSP16D.tmp" 
Creating temporary file "C:\DOCUME~1\DeanW\LOCALS~1\Temp\RSP16E.tmp" with contents
[
commctrl.lib coredll.lib /nologo /base:"0x00010000" /stack:0x10000,0x1000 /entry:"WinMainCRTStartup" /incremental:no /pdb:"ARMV4IRel/Keys.pdb" /nodefaultlib:"libc.lib /nodefaultlib:libcd.lib /nodefaultlib:libcmt.lib /nodefaultlib:libcmtd.lib /nodefaultlib:msvcrt.lib /nodefaultlib:msvcrtd.lib" /out:"ARMV4IRel/Keys.exe" /subsystem:windowsce,4.20 /MACHINE:THUMB 
".\ARMV4IRel\Keys.obj"
".\ARMV4IRel\StdAfx.obj"
".\ARMV4IRel\Keys.res"
]
Creating command line "link.exe @C:\DOCUME~1\DeanW\LOCALS~1\Temp\RSP16E.tmp"
<h3>Output Window</h3>
Compiling resources...
Compiling...
StdAfx.cpp
Compiling...
Keys.cpp
Linking...




<h3>Results</h3>
Keys.exe - 0 error(s), 0 warning(s)
</pre>
</body>
</html>
