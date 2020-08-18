<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: Tutorial9 - Win32 (WCE ARMV4I) Debug--------------------
</h3>
<h3>Command Lines</h3>
Creating temporary file "C:\DOCUME~1\KING~1.KIN\LOCALS~1\Temp\RSP873.tmp" with contents
[
/nologo /W3 /Zi /Od /D "DEBUG" /D "ARM" /D "_ARM_" /D "ARMV4I" /D UNDER_CE=420 /D _WIN32_WCE=420 /D "WCE_PLATFORM_GIZMONDO" /D "UNICODE" /D "_UNICODE" /Fp"ARMV4IDbg/Tutorial9.pch" /YX /Fo"ARMV4IDbg/" /Fd"ARMV4IDbg/" /QRarch4T /QRinterwork-return /MC /c 
"D:\My Documents\Gizmondo\Dev\SDK\Tutorials\KGSDK\Demos_GLES\Tutorial9\main.cpp"
]
Creating command line "clarm.exe @C:\DOCUME~1\KING~1.KIN\LOCALS~1\Temp\RSP873.tmp" 
Creating temporary file "C:\DOCUME~1\KING~1.KIN\LOCALS~1\Temp\RSP874.tmp" with contents
[
commctrl.lib coredll.lib /nologo /base:"0x00010000" /stack:0x10000,0x1000 /entry:"WinMainCRTStartup" /incremental:yes /pdb:"ARMV4IDbg/Tutorial9.pdb" /debug /nodefaultlib:"libc.lib /nodefaultlib:libcd.lib /nodefaultlib:libcmt.lib /nodefaultlib:libcmtd.lib /nodefaultlib:msvcrt.lib /nodefaultlib:msvcrtd.lib" /out:"ARMV4IDbg/Tutorial9.exe" /subsystem:windowsce,4.20 /MACHINE:THUMB 
".\ARMV4IDbg\main.obj"
]
Creating command line "link.exe @C:\DOCUME~1\KING~1.KIN\LOCALS~1\Temp\RSP874.tmp"
<h3>Output Window</h3>
Compiling...
main.cpp
Linking...
Framework.lib(Framework2D.obj) : warning LNK4204: 'D:\My Documents\Gizmondo\Dev\SDK\Tutorials\KGSDK\Demos_GLES\Tutorial9\ARMV4IDbg\vc60.pdb' is missing debugging information for referencing module; linking object as if no debug info
Framework.lib(Framework.obj) : warning LNK4204: 'D:\My Documents\Gizmondo\Dev\SDK\Tutorials\KGSDK\Demos_GLES\Tutorial9\ARMV4IDbg\vc60.pdb' is missing debugging information for referencing module; linking object as if no debug info
Framework.lib(FrameworkGL.obj) : warning LNK4204: 'D:\My Documents\Gizmondo\Dev\SDK\Tutorials\KGSDK\Demos_GLES\Tutorial9\ARMV4IDbg\vc60.pdb' is missing debugging information for referencing module; linking object as if no debug info




<h3>Results</h3>
Tutorial9.exe - 0 error(s), 3 warning(s)
</pre>
</body>
</html>
