' This script installs platman and the remote tools as "top level" platman
' packages. That means that these packages are available for all devices.

Dim platman
Dim package
Dim instDir
Dim nCPUs
Dim CPU(11)
Dim CPUDir(11)
Dim OS

' Configuration constants

Set args = WScript.Arguments
instDir = args(0)


' Initialize the CPU list

Set platman = CreateObject("PlatformManager.PlatformManager.1")
Set OS      = platman.GetOS("wce420")
nCPUs       = 11

Set CPU(0)  = platman.GetCPU("x86")
CPUDir(0)   = instDir + "\target\x86\"
Set CPU(1)  = platman.GetCPU("mipsII")
CPUDir(1)   = instDir + "\target\mipsII\"
Set CPU(2)  = platman.GetCPU("mips16")
CPUDir(2)   = instDir + "\target\mips16\"
Set CPU(3)  = platman.GetCPU("mipsII_fp")
CPUDir(3)   = instDir + "\target\mipsII_fp\"
Set CPU(4)  = platman.GetCPU("armV4")
CPUDir(4)   = instDir + "\target\armV4\"
Set CPU(5)  = platman.GetCPU("armV4t")
CPUDir(5)   = instDir + "\target\armV4t\"
Set CPU(6)  = platman.GetCPU("sh3")
CPUDir(6)   = instDir + "\target\sh3\"
Set CPU(7)  = platman.GetCPU("sh4")
CPUDir(7)   = instDir + "\target\sh4\"
Set CPU(8)  = platman.GetCPU("mipsIV")
CPUDir(8)   = instDir + "\target\mipsIV\"
Set CPU(9)  = platman.GetCPU("mipsIV_fp")
CPUDir(9)   = instDir + "\target\mipsIV_fp\"
Set CPU(10) = platman.GetCPU("armV4i")
CPUDir(10)  = instDir + "\target\armV4i\"

' Install packages - note: these are "top-level" packages, and not
' installed under any given platform

GetPackage "TickStats (CEPerfmon) Sample", "{F613CB32-F687-4120-A386-F0E92C9E82F9}"
AddFiles package, "TickStatsCE.exe"

GetPackage "TimeViewer Sample", "{5344F94F-E122-430c-A553-62EB86D7671C}"
AddFiles package, "TimeViewerCE.exe"

GetPackage "TimeViewer2 Sample", "{41467246-55B0-477f-9CC8-F4F248A6C74D}"
AddFiles package, "GenDataTime.dll"

GetPackage "TimeViewer3 Sample", "{61DBAE87-60A6-4dcf-9730-1CBF68AB9F48}"
AddFiles package, "SysTimeCE.dll"

GetPackage "SampleObject Sample", "{E9568310-57F8-421b-9083-8ABE9A043F65}"
AddFiles package, "SampleObject.dll"

Sub AddFiles (package, file)
    Dim ix
    For ix = 0 To nCPUs - 1
        'Wscript.Echo "Adding file " + CPUDir(ix) + file
        package.AddFile CPUDir(ix) + file, file, CPU(ix), OS, 0, 0
    Next
End Sub

Sub GetPackage (pkgName, pkgId)
package = null
On Error Resume Next
Set package = platman.GetPackage(pkgId)
if (IsObject(package) = false) then
	Set package = platman.AddPackage (pkgName, pkgId)
end if
End Sub

