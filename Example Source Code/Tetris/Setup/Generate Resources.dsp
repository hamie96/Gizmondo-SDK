# Microsoft Developer Studio Project File - Name="Generate Resources" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Generic Project" 0x010a

CFG=Generate Resources - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Generate Resources.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Generate Resources.mak" CFG="Generate Resources - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Generate Resources - Win32 Release" (based on "Win32 (x86) Generic Project")
!MESSAGE "Generate Resources - Win32 Debug" (based on "Win32 (x86) Generic Project")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
MTL=midl.exe

!IF  "$(CFG)" == "Generate Resources - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Intermediate"
# PROP Intermediate_Dir "Intermediate"
# PROP Target_Dir ""

!ELSEIF  "$(CFG)" == "Generate Resources - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Intermediate"
# PROP Intermediate_Dir "Intermediate"
# PROP Target_Dir ""

!ENDIF 

# Begin Target

# Name "Generate Resources - Win32 Release"
# Name "Generate Resources - Win32 Debug"
# Begin Source File

SOURCE=.\Config\Tetris.inf

!IF  "$(CFG)" == "Generate Resources - Win32 Release"

# Begin Custom Build - Creating cabinet file
IntDir=.\Intermediate
ProjDir=.
InputPath=.\Config\Tetris.inf

"$(IntDir)\Tetris.PPC30_ARM.cab" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) $(IntDir) 
	cd $(IntDir) 
	"C:\Program files\Windows CE tools\WCE300\Pocket PC 2002\Support\ActiveSync\Windows CE application installation\CabWiz\CabWiz.exe" Tetris.inf /cpu PPC30_ARM 
	del Tetris.inf 
	cd $(ProjDir) 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "Generate Resources - Win32 Debug"

# Begin Custom Build - Creating cabinet file
IntDir=.\Intermediate
ProjDir=.
InputPath=.\Config\Tetris.inf

"$(IntDir)\Tetris.PPC30_ARM.cab" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy $(InputPath) $(IntDir) 
	cd $(IntDir) 
	"C:\Program files\Windows CE tools\WCE300\Pocket PC 2002\Support\ActiveSync\Windows CE application installation\CabWiz\CabWiz.exe" Tetris.inf /cpu PPC30_ARM 
	del Tetris.inf 
	cd $(ProjDir) 
	
# End Custom Build

!ENDIF 

# End Source File
# End Target
# End Project
