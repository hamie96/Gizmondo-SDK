<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: Tutorial2 - Win32 (WCE ARMV4I) Debug--------------------
</h3>
<h3>Command Lines</h3>
Creating temporary file "E:\DOCUME~1\king\LOCALS~1\Temp\RSP4AC.tmp" with contents
[
/nologo /W3 /Zi /Od /D "DEBUG" /D "ARM" /D "_ARM_" /D "ARMV4I" /D UNDER_CE=420 /D _WIN32_WCE=420 /D "WCE_PLATFORM_GTERM" /D "UNICODE" /D "_UNICODE" /Fp"ARMV4IDbg/Tutorial2.pch" /YX /Fo"ARMV4IDbg/" /Fd"ARMV4IDbg/" /QRarch4T /QRinterwork-return /MC /c 
"C:\My Documents\Gizmondo\Dev\SDK\Tutorials\KGSDK\Tutorial2\main.cpp"
]
Creating command line "clarm.exe @E:\DOCUME~1\king\LOCALS~1\Temp\RSP4AC.tmp" 
Creating temporary file "E:\DOCUME~1\king\LOCALS~1\Temp\RSP4AD.tmp" with contents
[
commctrl.lib coredll.lib  /nologo /base:"0x00010000" /stack:0x10000,0x1000 /entry:"WinMainCRTStartup" /incremental:yes /pdb:"ARMV4IDbg/Tutorial2.pdb" /debug /nodefaultlib:"libc.lib /nodefaultlib:libcd.lib /nodefaultlib:libcmt.lib /nodefaultlib:libcmtd.lib /nodefaultlib:msvcrt.lib /nodefaultlib:msvcrtd.lib" /out:"ARMV4IDbg/Tutorial2.exe" /subsystem:windowsce,4.20 /MACHINE:THUMB  
".\ARMV4IDbg\main.obj"
]
Creating command line "link.exe @E:\DOCUME~1\king\LOCALS~1\Temp\RSP4AD.tmp"
<h3>Output Window</h3>
Compiling...
main.cpp
Linking...




<h3>Results</h3>
Tutorial2.exe - 0 error(s), 0 warning(s)
</pre>
</body>
</html>