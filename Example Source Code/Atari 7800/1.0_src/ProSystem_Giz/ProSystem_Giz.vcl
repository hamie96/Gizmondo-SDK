<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: ProSystem_Giz - Win32 (WCE ARMV4I) Release--------------------
</h3>
<h3>Command Lines</h3>
Creating temporary file "C:\DOCUME~1\Mark\LOCALS~1\Temp\RSP46.tmp" with contents
[
/nologo /W3 /I "C:\Docume~1\Mark\Desktop\gizmondo\ProSystem_Giz\trunk\sdlport\include" /I "C:\Docume~1\Mark\Desktop\gizmondo\ProSystem_Giz\trunk\STLPort\stlport" /I "C:\Docume~1\Mark\Desktop\gizmondo\ProSystem_Giz\\" /I "C:\Docume~1\Mark\Desktop\gizmondo\ProSystem_Giz\zlib" /I "C:\Docume~1\Mark\Desktop\gizmondo\7800-v1.0.2\src" /I "C:\Docume~1\Mark\Desktop\gizmondo\7800-v1.0.2\src\libzip" /D _WIN32_WCE=420 /D "ARM" /D "_ARM_" /D "WCE_PLATFORM_GTERM" /D "ARMV4I" /D UNDER_CE=420 /D "UNICODE" /D "_UNICODE" /D "NDEBUG" /Fo"ARMV4IRel/" /QRarch4T /QRinterwork-return /O2 /MC /c 
"C:\DOCUMENTS AND SETTINGS\MARK\DESKTOP\GIZMONDO\7800-v1.0.2\src\psp_menu_kbd.c"
]
Creating command line "clarm.exe @C:\DOCUME~1\Mark\LOCALS~1\Temp\RSP46.tmp" 
Creating temporary file "C:\DOCUME~1\Mark\LOCALS~1\Temp\RSP47.tmp" with contents
[
commctrl.lib coredll.lib libPNG.lib libJPEG.lib zlib.lib gx.lib /nologo /base:"0x00010000" /stack:0x10000,0x1000 /entry:"WinMainCRTStartup" /incremental:no /pdb:"ARMV4IRel/ProSystem_Giz.pdb" /nodefaultlib:"libc.lib /nodefaultlib:libcd.lib /nodefaultlib:libcmt.lib /nodefaultlib:libcmtd.lib /nodefaultlib:msvcrt.lib /nodefaultlib:msvcrtd.lib" /out:"ARMV4IRel/ProSystem_Giz.exe" /libpath:"C:\Docume~1\Mark\Desktop\gizmondo\ProSystem_Giz\trunk\stlport\lib\evc4-arm" /libpath:"C:\Docume~1\Mark\Desktop\gizmondo\ProSystem_Giz\trunk\sdlport\lib" /subsystem:windowsce,4.20 /MACHINE:THUMB 
".\ARMV4IRel\backgroundjpg.obj"
".\ARMV4IRel\gxwrapper.obj"
".\ARMV4IRel\jpegbuffersrc.obj"
".\ARMV4IRel\loadbackground.obj"
".\ARMV4IRel\missing.obj"
".\ARMV4IRel\ProSystem_Giz.obj"
".\ARMV4IRel\StdAfx.obj"
".\ARMV4IRel\util.obj"
".\ARMV4IRel\ioapi.obj"
".\ARMV4IRel\iowin32.obj"
".\ARMV4IRel\mztools.obj"
".\ARMV4IRel\unzip.obj"
".\ARMV4IRel\zip.obj"
".\ARMV4IRel\Archive.obj"
".\ARMV4IRel\Bios.obj"
".\ARMV4IRel\Cartridge.obj"
".\ARMV4IRel\Common.obj"
".\ARMV4IRel\Database.obj"
".\ARMV4IRel\FrameworkAudio.obj"
".\ARMV4IRel\global.obj"
".\ARMV4IRel\gp2x_psp.obj"
".\ARMV4IRel\Hash.obj"
".\ARMV4IRel\Logger.obj"
".\ARMV4IRel\Maria.obj"
".\ARMV4IRel\Memory.obj"
".\ARMV4IRel\Palette.obj"
".\ARMV4IRel\Pokey.obj"
".\ARMV4IRel\ProSystem.obj"
".\ARMV4IRel\psp_atari.obj"
".\ARMV4IRel\psp_fmgr.obj"
".\ARMV4IRel\psp_font.obj"
".\ARMV4IRel\psp_kbd.obj"
".\ARMV4IRel\psp_main.obj"
".\ARMV4IRel\psp_menu.obj"
".\ARMV4IRel\psp_menu_help.obj"
".\ARMV4IRel\psp_menu_kbd.obj"
".\ARMV4IRel\psp_menu_set.obj"
".\ARMV4IRel\psp_sdl.obj"
".\ARMV4IRel\psp_sound.obj"
".\ARMV4IRel\Region.obj"
".\ARMV4IRel\Riot.obj"
".\ARMV4IRel\Sally.obj"
".\ARMV4IRel\Sound.obj"
".\ARMV4IRel\soundce.obj"
".\ARMV4IRel\Tia.obj"
".\ARMV4IRel\ProSystem_Giz.res"
]
Creating command line "link.exe @C:\DOCUME~1\Mark\LOCALS~1\Temp\RSP47.tmp"
<h3>Output Window</h3>
Compiling...
psp_menu_kbd.c
c:\documents and settings\mark\desktop\gizmondo\7800-v1.0.2\src\psp_menu_kbd.c(144) : warning C4013: 'psp_sdl_back2_print' undefined; assuming extern returning int
c:\documents and settings\mark\desktop\gizmondo\7800-v1.0.2\src\psp_menu_kbd.c(162) : warning C4013: 'string_fill_with_space' undefined; assuming extern returning int
c:\documents and settings\mark\desktop\gizmondo\7800-v1.0.2\src\psp_menu_kbd.c(172) : warning C4013: 'psp_menu_display_save_name' undefined; assuming extern returning int
c:\documents and settings\mark\desktop\gizmondo\7800-v1.0.2\src\psp_menu_kbd.c(119) : warning C4101: 'scan' : unreferenced local variable
c:\documents and settings\mark\desktop\gizmondo\7800-v1.0.2\src\psp_menu_kbd.c(183) : warning C4013: 'psp_kbd_reset_mapping' undefined; assuming extern returning int
c:\documents and settings\mark\desktop\gizmondo\7800-v1.0.2\src\psp_menu_kbd.c(184) : warning C4013: 'sleep' undefined; assuming extern returning int
c:\documents and settings\mark\desktop\gizmondo\7800-v1.0.2\src\psp_menu_kbd.c(271) : warning C4101: 'atari_key' : unreferenced local variable
Linking...
LINK : warning LNK4089: all references to 'commctrl.dll' discarded by /OPT:REF




<h3>Results</h3>
ProSystem_Giz.exe - 0 error(s), 8 warning(s)
</pre>
</body>
</html>
