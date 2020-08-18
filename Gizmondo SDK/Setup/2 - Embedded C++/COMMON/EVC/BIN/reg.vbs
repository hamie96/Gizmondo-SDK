' this script creates the following "top-level" platman packages for eMbedded Visual C++ 4.0
'	WCE 400: Cemon.exe and Jitdebugger.exe

Dim platman
Dim package
Dim instDir
Dim nCPUs
Dim CPU(20)
Dim CPUDir(20)
Dim OS
Dim Version
Dim MsgError

' Configuration constants

'we're running from the command line
Set args = WScript.Arguments
if args.count < 1 then
	WScript.echo("Usage: runtime_register <install dir>")
	WScript.quit(1)
end if
instDir = args(0)



Set platman = CreateObject("PlatformManager.PlatformManager.1")

If instDir <> "" Then
	
	'If InstDir does not have a trailing backslash add one on.
	
	If InStr( Len(instDir), instDir, "\", vbTextCompare) = 0 Then
		instDir = instDir + "\"
	End if



	'********************** WCE400 ****************************	
	' Initialize the CPU list
	Set OS      = platman.GetOS("wce400")
	nCPUs       = 11
	
	Set CPU(0) = platman.GetCPU("armv4")
	CPUDir(0)  = instDir + "wce400\target\armv4\"
	Set CPU(1) = platman.GetCPU("armv4i")
	CPUDir(1)  = instDir + "wce400\target\armv4i\"
	Set CPU(2) = platman.GetCPU("armv4t")
	CPUDir(2)  = instDir + "wce400\target\armv4t\"
	Set CPU(3)  = platman.GetCPU("mipsII")
	CPUDir(3)   = instDir + "wce400\target\mipsII\"	
	Set CPU(4)  = platman.GetCPU("mipsII_fp")
	CPUDir(4)   = instDir + "wce400\target\mipsII_fp\"	
	Set CPU(5)  = platman.GetCPU("mipsIV")
	CPUDir(5)   = instDir + "wce400\target\mipsIV\"
	Set CPU(6)  = platman.GetCPU("mipsIV_FP")
	CPUDir(6)   = instDir + "wce400\target\mipsIV_FP\"
	Set CPU(7)  = platman.GetCPU("mips16")
	CPUDir(7)   = instDir + "wce400\target\mips16\"	
	Set CPU(8)  = platman.GetCPU("sh3")
	CPUDir(8)   = instDir + "wce400\target\sh3\"
	Set CPU(9)  = platman.GetCPU("sh4")
	CPUDir(9)   = instDir + "wce400\target\sh4\"
	Set CPU(10)  = platman.GetCPU("x86")
	CPUDir(10)   = instDir + "wce400\target\x86\"
	
	' Install packages - note: these are "top-level" packages, and not
	' installed under any given platform

	'***Package: cemon
	GetPackage "cemon.exe", "{70E03D11-82C3-41A5-A1FA-708927164234}"
	AddFiles package, "cemon.exe"

	'***Package: jitdebugger
	GetPackage "jitdebugger.exe", "{A0D95FCD-6DEE-4DFF-B213-04DEFBE70429}"
	AddFiles package, "jitdebugger.exe"

	
End If


Sub AddFiles (package, file)
    Dim ix
    For ix = 0 To nCPUs - 1
        'Wscript.Echo "Adding file " + CPUDir(ix) + file
        package.AddFile CPUDir(ix) + file, file, CPU(ix), OS, 0, 0
    Next
End Sub

Sub GetPackage (pkgName, pkgId)
On Error Resume Next
platman.DeletePackage (pkgId)
On Error GoTo 0
Set package = platman.AddPackage (pkgName, pkgId)
End Sub

