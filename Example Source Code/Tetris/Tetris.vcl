<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: Tetris - Win32 (WCE ARM) Release--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "rc.exe /l 0x409 /fo".\_Intermediate\ARM\Release/Tetris.res" /d UNDER_CE=300 /d _WIN32_WCE=300 /d "UNICODE" /d "_UNICODE" /d "NDEBUG" /d "WIN32_PLATFORM_PSPC=310" /d "ARM" /d "_ARM_" /r "C:\Temp\Tetris.rc"" 
Creating temporary file "C:\DOCUME~1\Rob\LOCALS~1\Temp\RSP1D0.tmp" with contents
[
/nologo /W3 /Zi /D _WIN32_WCE=300 /D "WIN32_PLATFORM_PSPC=310" /D "ARM" /D "_ARM_" /D UNDER_CE=300 /D "UNICODE" /D "_UNICODE" /D "NDEBUG" /Fp".\_Intermediate\ARM\Release/Tetris.pch" /Yu"stdafx.h" /Fo".\_Intermediate\ARM\Release/" /Fd".\_Intermediate\ARM\Release/" /Oxs /MC /c 
"C:\Temp\TetrisMatrix.cpp"
"C:\Temp\TetrisOptions.cpp"
"C:\Temp\TetrisScore.cpp"
"C:\Temp\Tetris.cpp"
"C:\Temp\IrDASocket.cpp"
"C:\Temp\KeyControl.cpp"
]
Creating command line "clarm.exe @C:\DOCUME~1\Rob\LOCALS~1\Temp\RSP1D0.tmp" 
Creating temporary file "C:\DOCUME~1\Rob\LOCALS~1\Temp\RSP1D1.tmp" with contents
[
/nologo /W3 /Zi /D _WIN32_WCE=300 /D "WIN32_PLATFORM_PSPC=310" /D "ARM" /D "_ARM_" /D UNDER_CE=300 /D "UNICODE" /D "_UNICODE" /D "NDEBUG" /Fp".\_Intermediate\ARM\Release/Tetris.pch" /Yc"stdafx.h" /Fo".\_Intermediate\ARM\Release/" /Fd".\_Intermediate\ARM\Release/" /Oxs /MC /c 
"C:\Temp\StdAfx.cpp"
]
Creating command line "clarm.exe @C:\DOCUME~1\Rob\LOCALS~1\Temp\RSP1D1.tmp" 
Creating temporary file "C:\DOCUME~1\Rob\LOCALS~1\Temp\RSP1D2.tmp" with contents
[
commctrl.lib coredll.lib aygshell.lib /nologo /base:"0x00010000" /stack:0x10000,0x1000 /entry:"WinMainCRTStartup" /incremental:no /pdb:".\_Output\ARM\Release/Tetris.pdb" /map:".\_Intermediate\ARM\Release/Tetris.map" /debug /nodefaultlib:"libc.lib /nodefaultlib:libcd.lib /nodefaultlib:libcmt.lib /nodefaultlib:libcmtd.lib /nodefaultlib:msvcrt.lib /nodefaultlib:msvcrtd.lib /nodefaultlib:oldnames.lib" /out:".\_Output\ARM\Release/Tetris.exe" /subsystem:windowsce,3.00 /align:"4096" /MACHINE:ARM 
.\_Intermediate\ARM\Release\TetrisMatrix.obj
.\_Intermediate\ARM\Release\TetrisOptions.obj
.\_Intermediate\ARM\Release\TetrisScore.obj
.\_Intermediate\ARM\Release\StdAfx.obj
.\_Intermediate\ARM\Release\Tetris.obj
.\_Intermediate\ARM\Release\IrDASocket.obj
.\_Intermediate\ARM\Release\KeyControl.obj
.\_Intermediate\ARM\Release\Tetris.res
]
Creating command line "link.exe @C:\DOCUME~1\Rob\LOCALS~1\Temp\RSP1D2.tmp"
<h3>Output Window</h3>
Compiling resources...
Compiling...
StdAfx.cpp
Compiling...
TetrisMatrix.cpp
TetrisOptions.cpp
TetrisScore.cpp
Tetris.cpp
IrDASocket.cpp
KeyControl.cpp
Generating Code...
Linking...




<h3>Results</h3>
Tetris.exe - 0 error(s), 0 warning(s)
</pre>
</body>
</html>
