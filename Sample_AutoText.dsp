# Microsoft Developer Studio Project File - Name="Sample_AutoText" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=Sample_AutoText - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Sample_AutoText.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Sample_AutoText.mak" CFG="Sample_AutoText - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Sample_AutoText - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Sample_AutoText - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Sample_AutoText - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /G3 /Zp2 /MT /W3 /O2 /I "..\..\Include" /I "..\..\Include\Internal" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 ..\..\Lib\OsEntry.obj ..\..\Lib\RimOs.lib ..\..\Lib\AutoText.lib ..\..\Lib\ribbon.lib ..\..\Lib\Database.lib ..\..\Lib\UI32.lib libc.lib /nologo /subsystem:windows /dll /machine:I386 /nodefaultlib

!ELSEIF  "$(CFG)" == "Sample_AutoText - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /G3 /Zp2 /MTd /W3 /Gm /ZI /Od /I "..\..\Include" /I "..\..\Include\Internal" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 ..\..\Lib\OsEntry.obj ..\..\Lib\RimOs.lib ..\..\Lib\AutoText.lib ..\..\Lib\ribbon.lib ..\..\Lib\Database.lib ..\..\Lib\UI32.lib libc.lib /nologo /subsystem:windows /dll /debug /machine:I386 /nodefaultlib /out:"..\..\Sample_AutoText.dll" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Sample_AutoText - Win32 Release"
# Name "Sample_AutoText - Win32 Debug"
# Begin Source File

SOURCE=.\DopeBitmap.h
# End Source File
# Begin Source File

SOURCE=.\DopeMenu.h
# End Source File
# Begin Source File

SOURCE=.\DopeTable.cpp
# End Source File
# Begin Source File

SOURCE=.\DopeTable.h
# End Source File
# Begin Source File

SOURCE=.\DopeWars.h
# End Source File
# Begin Source File

SOURCE=.\Main.cpp
# End Source File
# Begin Source File

SOURCE=.\MenuMgr.cpp
# End Source File
# Begin Source File

SOURCE=.\MenuMgr.h
# End Source File
# Begin Source File

SOURCE=.\Player.cpp
# End Source File
# Begin Source File

SOURCE=.\Player.h
# End Source File
# Begin Source File

SOURCE=.\SavingsAndLoans.cpp
# End Source File
# Begin Source File

SOURCE=.\SavingsAndLoans.h
# End Source File
# Begin Source File

SOURCE=.\TransactionDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\TransactionDialog.h
# End Source File
# End Target
# End Project
