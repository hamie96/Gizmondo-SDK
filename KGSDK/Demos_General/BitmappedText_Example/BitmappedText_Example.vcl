<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: BitmappedText_Example - Win32 (WCE ARMV4I) Debug--------------------
</h3>
<h3>Command Lines</h3>
Creating temporary file "C:\DOCUME~1\KING~1.KIN\LOCALS~1\Temp\RSP4D1.tmp" with contents
[
/nologo /W3 /Zi /Od /D "DEBUG" /D "ARM" /D "_ARM_" /D "ARMV4I" /D UNDER_CE=420 /D _WIN32_WCE=420 /D "WCE_PLATFORM_GIZMONDO" /D "UNICODE" /D "_UNICODE" /Fp"ARMV4IDbg/BitmappedText_Example.pch" /YX /Fo"ARMV4IDbg/" /Fd"ARMV4IDbg/" /QRarch4T /QRinterwork-return /MC /c 
"D:\My Documents\Gizmondo\Dev\SDK\Tutorials\KGSDK\Demos_General\BitmappedText_Example\main.cpp"
]
Creating command line "clarm.exe @C:\DOCUME~1\KING~1.KIN\LOCALS~1\Temp\RSP4D1.tmp" 
Creating temporary file "C:\DOCUME~1\KING~1.KIN\LOCALS~1\Temp\RSP4D2.tmp" with contents
[
commctrl.lib coredll.lib /nologo /base:"0x00010000" /stack:0x10000,0x1000 /entry:"WinMainCRTStartup" /incremental:yes /pdb:"ARMV4IDbg/BitmappedText_Example.pdb" /debug /nodefaultlib:"libc.lib /nodefaultlib:libcd.lib /nodefaultlib:libcmt.lib /nodefaultlib:libcmtd.lib /nodefaultlib:msvcrt.lib /nodefaultlib:msvcrtd.lib" /out:"ARMV4IDbg/BitmappedText_Example.exe" /subsystem:windowsce,4.20 /MACHINE:THUMB 
".\ARMV4IDbg\main.obj"
]
Creating command line "link.exe @C:\DOCUME~1\KING~1.KIN\LOCALS~1\Temp\RSP4D2.tmp"
<h3>Output Window</h3>
Compiling...
main.cpp
e:\program files\windows ce tools\wce420\gizmondo\include\armv4i\kgsdk\frameworkking_bitmappedtext.h(870) : warning C4244: 'initializing' : conversion from 'double' to 'float', possible loss of data
e:\program files\windows ce tools\wce420\gizmondo\include\armv4i\kgsdk\frameworkking_bitmappedtext.h(871) : warning C4244: 'initializing' : conversion from 'double' to 'float', possible loss of data
e:\program files\windows ce tools\wce420\gizmondo\include\armv4i\kgsdk\frameworkking_bitmappedtext.h(872) : warning C4244: 'initializing' : conversion from 'double' to 'float', possible loss of data
e:\program files\windows ce tools\wce420\gizmondo\include\armv4i\kgsdk\frameworkking_bitmappedtext.h(873) : warning C4244: 'initializing' : conversion from 'double' to 'float', possible loss of data
e:\program files\windows ce tools\wce420\gizmondo\include\armv4i\kgsdk\frameworkking_bitmappedtext.h(885) : warning C4244: 'argument' : conversion from 'int' to 'float', possible loss of data
e:\program files\windows ce tools\wce420\gizmondo\include\armv4i\kgsdk\frameworkking_bitmappedtext.h(887) : warning C4244: 'argument' : conversion from 'int' to 'float', possible loss of data
Linking...




<h3>Results</h3>
BitmappedText_Example.exe - 0 error(s), 6 warning(s)
</pre>
</body>
</html>
