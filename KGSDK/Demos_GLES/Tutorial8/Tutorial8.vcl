<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: Tutorial8 - Win32 (WCE ARMV4I) Debug--------------------
</h3>
<h3>Command Lines</h3>
Creating temporary file "C:\DOCUME~1\KING~1.KIN\LOCALS~1\Temp\RSP777.tmp" with contents
[
/nologo /W3 /Zi /Od /D "DEBUG" /D "ARM" /D "_ARM_" /D "ARMV4I" /D UNDER_CE=420 /D _WIN32_WCE=420 /D "WCE_PLATFORM_GIZMONDO" /D "UNICODE" /D "_UNICODE" /Fp"ARMV4IDbg/Tutorial8.pch" /YX /Fo"ARMV4IDbg/" /Fd"ARMV4IDbg/" /QRarch4T /QRinterwork-return /MC /c 
"D:\My Documents\Gizmondo\Dev\SDK\Tutorials\KGSDK\Tutorial8\main.cpp"
]
Creating command line "clarm.exe @C:\DOCUME~1\KING~1.KIN\LOCALS~1\Temp\RSP777.tmp" 
Creating temporary file "C:\DOCUME~1\KING~1.KIN\LOCALS~1\Temp\RSP778.tmp" with contents
[
commctrl.lib coredll.lib /nologo /base:"0x00010000" /stack:0x10000,0x1000 /entry:"WinMainCRTStartup" /incremental:yes /pdb:"ARMV4IDbg/Tutorial8.pdb" /debug /nodefaultlib:"libc.lib /nodefaultlib:libcd.lib /nodefaultlib:libcmt.lib /nodefaultlib:libcmtd.lib /nodefaultlib:msvcrt.lib /nodefaultlib:msvcrtd.lib" /out:"ARMV4IDbg/Tutorial8.exe" /subsystem:windowsce,4.20 /MACHINE:THUMB 
".\ARMV4IDbg\main.obj"
]
Creating command line "link.exe @C:\DOCUME~1\KING~1.KIN\LOCALS~1\Temp\RSP778.tmp"
<h3>Output Window</h3>
Compiling...
main.cpp
d:\my documents\gizmondo\dev\sdk\tutorials\kgsdk\tutorial8\functions.h(2) : fatal error C1083: Cannot open include file: 'GLES\gl.h': No such file or directory
Error executing clarm.exe.



<h3>Results</h3>
Tutorial8.exe - 1 error(s), 0 warning(s)
</pre>
</body>
</html>