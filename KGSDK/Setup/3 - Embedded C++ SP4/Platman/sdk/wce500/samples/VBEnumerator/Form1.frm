VERSION 5.00
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "MSCOMCTL.OCX"
Begin VB.Form Form1 
   Caption         =   "PLATMAN VIEWER"
   ClientHeight    =   9030
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   13365
   LinkTopic       =   "Form1"
   ScaleHeight     =   9030
   ScaleWidth      =   13365
   StartUpPosition =   2  'CenterScreen
   Begin MSComctlLib.TreeView tvwItems 
      Height          =   8535
      Left            =   240
      TabIndex        =   0
      Top             =   240
      Width           =   12975
      _ExtentX        =   22886
      _ExtentY        =   15055
      _Version        =   393217
      LabelEdit       =   1
      LineStyle       =   1
      Sorted          =   -1  'True
      Style           =   7
      Appearance      =   1
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
 '
 ' Copyright (c) Microsoft Corporation.	All rights reserved.
 '
 '
 ' Use of this source code is subject to the terms of the Microsoft end-user
 ' license agreement (EULA) under which you licensed this SOFTWARE PRODUCT.
 ' If you did not accept the terms of the EULA, you are not authorized to use 
 ' this source code. For a copy of the EULA, please see the LICENSE.RTF on your
 ' install media.
 '
 '/***********************************************************************
 'THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
 'ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 'THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
 'PARTICULAR PURPOSE.

 'MODULE:   VBEnumerator

 'COMMENTS: N/A
 '***********************************************************************/


Option Explicit
Const FORMAT_MESSAGE_FROM_SYSTEM = &H1000

Private Declare Function FormatMessage Lib "kernel32" Alias _
      "FormatMessageA" (ByVal dwFlags As Long, lpSource As Long, _
      ByVal dwMessageId As Long, ByVal dwLanguageId As Long, _
      ByVal lpBuffer As String, ByVal nSize As Long, Arguments As Any) _
      As Long

Function DisplayProperties(tEnumObjects As Object, tRootNode As Node, nKey As Integer)
    
    ' this special check as this method is called recursively
    If (tEnumObjects.Count > 0) Then
        DisplayProperties = True
    Else
        DisplayProperties = False
        Exit Function
    End If

    Dim propertyNode As Node, propertiesNode As Node
    Dim tPropObject As Object

    On Error GoTo DisplayError

    ' create the root properties node
    Set propertiesNode = tvwItems.Nodes.Add(tRootNode.Key, tvwChild, "DP" & CStr(nKey), "Properties")
    nKey = nKey + 1

    ' display the enumeration of properties
    For Each tPropObject In tEnumObjects
            
        ' get the next element and add it to the tree
        Set propertyNode = tvwItems.Nodes.Add(propertiesNode.Key, tvwChild, "DP" & CStr(nKey), tPropObject.Id)
        nKey = nKey + 1
                
        Dim tPropInfoObject As Object, propInfoNode As Node, ttype As Integer
        For Each tPropInfoObject In tPropObject.EnumPropInfos
            Set propInfoNode = tvwItems.Nodes.Add(propertyNode.Key, tvwChild, "DP" & CStr(nKey), tPropInfoObject.Name & ": " & CStr(tPropInfoObject.Value))
            nKey = nKey + 1
        Next tPropInfoObject
        
        ' display any other properties within this object
        ' properties can have properties!
        DisplayProperties tPropObject.EnumProperties, propertyNode, nKey
        
    Next tPropObject
    Exit Function
    
DisplayError:
    Debug.Assert False
    If (Err.Number <> 0) Then
        ShowError "DisplayProperties"
    End If
    
End Function

Sub DisplayDevices(tPlatform As Object, tEnumObjects As Object, tRootNode As Node, nKey As Integer)
    
    If tEnumObjects.Count = 0 Then
        Exit Sub
    End If
    
    Dim deviceNode As Node, devicesNode As Node, startupServerNode As Node, transportNode As Node
    Dim tDevice As Object
    
    On Error GoTo DisplayError
    
    ' create the root remote devices node
    Set devicesNode = tvwItems.Nodes.Add(tRootNode.Key, tvwChild, "DD" & CStr(nKey), "Devices")
    nKey = nKey + 1

    ' display the enumeration of devices
    For Each tDevice In tEnumObjects
    
        ' get the next element and add it to the tree
        Set deviceNode = tvwItems.Nodes.Add(devicesNode.Key, tvwChild, "DD" & CStr(nKey), tDevice.Name)
        nKey = nKey + 1
        
        ' display the startup server and transport within this device
        Dim tobject As Object
        Set tobject = tPlatform.GetStartupServer(tDevice.StartupServer)
        Set startupServerNode = tvwItems.Nodes.Add(deviceNode.Key, tvwChild, "DD" & CStr(nKey), "StartupServer: " & tobject.Name)
        nKey = nKey + 1
        Set tobject = Nothing
        
        Set tobject = tPlatform.GetTransport(tDevice.Transport)
        Set transportNode = tvwItems.Nodes.Add(deviceNode.Key, tvwChild, "DD" & CStr(nKey), "Transport: " & tobject.Name)
        nKey = nKey + 1
        Set tobject = Nothing

        ' get the enumeration of properties
        DisplayProperties tDevice.EnumProperties, deviceNode, nKey
        
    Next tDevice
    Exit Sub
    
DisplayError:
    Debug.Assert False
    If (Err.Number <> 0) Then
        ShowError "DisplayDevices"
    End If
    
End Sub

Sub DisplayBootableDevices(tEnumObjects As Object, tRootNode As Node, nKey As Integer)
    
    If tEnumObjects.Count = 0 Then
        Exit Sub
    End If

    Dim bootableDeviceNode As Node, bootableDevicesNode As Node
    Dim tBootDevice As Object
    
    On Error GoTo DisplayError
    
    ' create the root bootable devices node
    Set bootableDevicesNode = tvwItems.Nodes.Add(tRootNode.Key, tvwChild, "DB" & CStr(nKey), "BootableDevices")
    nKey = nKey + 1

    ' display the enumeration of bootable devices
    For Each tBootDevice In tEnumObjects
    
        ' get the next element and add it to the tree
        Set bootableDeviceNode = tvwItems.Nodes.Add(bootableDevicesNode.Key, tvwChild, "DB" & CStr(nKey), tBootDevice.Name)
        nKey = nKey + 1
        
        ' get the enumeration of properties
        DisplayProperties tBootDevice.EnumProperties, bootableDeviceNode, nKey
        
    Next tBootDevice
    Exit Sub
    
DisplayError:
    Debug.Assert False
    If (Err.Number <> 0) Then
        ShowError "DisplayBootableDevices"
    End If
    
End Sub
Sub DisplayCPUs(tEnumObjects As Object, tRootNode As Node, nKey As Integer)
    
    If tEnumObjects.Count = 0 Then
        Exit Sub
    End If

    Dim cpuNode As Node, cpusNode As Node, cpuPropNode As Node
    Dim tCPU As Object
    
    On Error GoTo DisplayError
    
    ' create the root cpu node
    Set cpusNode = tvwItems.Nodes.Add(tRootNode.Key, tvwChild, "DCPU" & CStr(nKey), "CPUs")
    nKey = nKey + 1

    ' display the enumeration of cpus
    For Each tCPU In tEnumObjects
    
        ' get the next element and add it to the tree
        Set cpuNode = tvwItems.Nodes.Add(cpusNode.Key, tvwChild, "DCPU" & CStr(nKey), tCPU.Name)
        nKey = nKey + 1
        
        ' display the property of a cpu object
        Set cpuPropNode = tvwItems.Nodes.Add(cpuNode.Key, tvwChild, "DCPU" & CStr(nKey), "Default: " & tCPU.DefaultValue)
        nKey = nKey + 1
        Set cpuPropNode = tvwItems.Nodes.Add(cpuNode.Key, tvwChild, "DCPU" & CStr(nKey), "Id: " & tCPU.Id)
        nKey = nKey + 1
        Set cpuPropNode = tvwItems.Nodes.Add(cpuNode.Key, tvwChild, "DCPU" & CStr(nKey), "Architecture: " & tCPU.Architecture)
        nKey = nKey + 1
        Set cpuPropNode = tvwItems.Nodes.Add(cpuNode.Key, tvwChild, "DCPU" & CStr(nKey), "Type: " & tCPU.Type)
        nKey = nKey + 1
        Set cpuPropNode = tvwItems.Nodes.Add(cpuNode.Key, tvwChild, "DCPU" & CStr(nKey), "Level: " & tCPU.Level)
        nKey = nKey + 1
        Set cpuPropNode = tvwItems.Nodes.Add(cpuNode.Key, tvwChild, "DCPU" & CStr(nKey), "PageSize: " & tCPU.PageSize)
        nKey = nKey + 1
                
    Next tCPU
    Exit Sub
    
DisplayError:
    Debug.Assert False
    If (Err.Number <> 0) Then
        ShowError "DisplayCPUs"
    End If
    
End Sub

Sub DisplayStartupServers(tEnumObjects As Object, tRootNode As Node, nKey As Integer)
    
    If tEnumObjects.Count = 0 Then
        Exit Sub
    End If

    Dim startupServerNode As Node, startupServersNode As Node, startupServerPropNode As Node
    Dim tStartupServer As Object
    
    On Error GoTo DisplayError
    
    ' create the root startup server node
    Set startupServersNode = tvwItems.Nodes.Add(tRootNode.Key, tvwChild, "DS" & CStr(nKey), "StartupServers")
    nKey = nKey + 1

    ' display the enumeration of startup servers
    For Each tStartupServer In tEnumObjects
    
        ' get the next element and add it to the tree
        Set startupServerNode = tvwItems.Nodes.Add(startupServersNode.Key, tvwChild, "DS" & CStr(nKey), tStartupServer.Name)
        nKey = nKey + 1
                        
        ' display the properties of the startup server; right now just the name
        Set startupServerPropNode = tvwItems.Nodes.Add(startupServerNode.Key, tvwChild, "DS" & CStr(nKey), "Id: " & tStartupServer.Id)
        nKey = nKey + 1

    Next tStartupServer
    Exit Sub
    
DisplayError:
    Debug.Assert False
    If (Err.Number <> 0) Then
        ShowError "DisplayStartupServers"
    End If
    
End Sub

Sub DisplayTransports(tEnumObjects As Object, tRootNode As Node, nKey As Integer)
    
    If tEnumObjects.Count = 0 Then
        Exit Sub
    End If

    Dim transportNode As Node, transportsNode As Node, transportPropNode As Node
    Dim tTransport As Object
    
    On Error GoTo DisplayError
    
    ' create the root transports node
    Set transportsNode = tvwItems.Nodes.Add(tRootNode.Key, tvwChild, "DTP" & CStr(nKey), "Transports")
    nKey = nKey + 1

    ' display the enumeration of transports
    For Each tTransport In tEnumObjects
    
        ' get the next element and add it to the tree
        Set transportNode = tvwItems.Nodes.Add(transportsNode.Key, tvwChild, "DTP" & CStr(nKey), tTransport.Name)
        nKey = nKey + 1
                        
        ' display the properties of the transport; right now just the name
        Set transportPropNode = tvwItems.Nodes.Add(transportNode.Key, tvwChild, "DTP" & CStr(nKey), "Id: " & tTransport.Id)
        nKey = nKey + 1

    Next tTransport
    Exit Sub
    
DisplayError:
    Debug.Assert False
    If (Err.Number <> 0) Then
        ShowError "DisplayTransports"
    End If
   
End Sub

Sub DisplayPackages(tEnumObjects As Object, tRootNode As Node, nKey As Integer)
    
    If tEnumObjects.Count = 0 Then
        Exit Sub
    End If

    Dim pkgNode As Node, pkgCatNode As Node, pkgsNode As Node, pkgFileNode As Node, pkgFilePropNode As Node
    Dim tPackage As Object, tPackageFile As Object
    
    On Error GoTo DisplayError
    
    ' create the root packages node
    Set pkgsNode = tvwItems.Nodes.Add(CStr(tRootNode.Key), tvwChild, "DPG" & CStr(nKey), "Packages")
    nKey = nKey + 1

    ' display the enumeration of packages
    For Each tPackage In tEnumObjects
    
        ' get the next element and add it to the tree
        Set pkgNode = tvwItems.Nodes.Add(pkgsNode.Key, tvwChild, "DPG" & CStr(nKey), tPackage.Name)
        nKey = nKey + 1
        
        ' get the enumeration of all the files within this package
        For Each tPackageFile In tPackage.EnumFiles
            
            'find out if we have this file grouping already
            Set pkgCatNode = pkgNode.Child
            Do
                If pkgCatNode Is Nothing Then
                    Exit Do
                End If
                If (StrComp(pkgCatNode.Text, tPackageFile.KeyName) = 0) Then
                    Exit Do
                End If
                Set pkgCatNode = pkgCatNode.Next
            Loop
            If (pkgCatNode Is Nothing) Then
                'we did not find a match; so create a file grouping with the key name
                Set pkgCatNode = tvwItems.Nodes.Add(pkgNode.Key, tvwChild, "DPG" & CStr(nKey), tPackageFile.KeyName)
                nKey = nKey + 1
            End If
            
            ' get the next element and add it to the tree
            Set pkgFileNode = tvwItems.Nodes.Add(pkgCatNode.Key, tvwChild, "DPG" & CStr(nKey), tPackageFile.Name)
            nKey = nKey + 1
                        
            ' set the file properties
            Set pkgFilePropNode = tvwItems.Nodes.Add(pkgFileNode.Key, tvwChild, "DPG" & CStr(nKey), "OS: " & tPackageFile.MajorVersion & "." & tPackageFile.MinorVersion)
            nKey = nKey + 1
            Set pkgFilePropNode = tvwItems.Nodes.Add(pkgFileNode.Key, tvwChild, "DPG" & CStr(nKey), "File Info: Locale(" & tPackageFile.Locale & "), Flags(" & tPackageFile.Flags & ")")
            nKey = nKey + 1
            Set pkgFilePropNode = tvwItems.Nodes.Add(pkgFileNode.Key, tvwChild, "DPG" & CStr(nKey), "CPU: Type(" & tPackageFile.Type & "), PageSize(" & tPackageFile.PageSize & "), Level(" & tPackageFile.Level & "), Architecture(" & tPackageFile.Architecture & ")")
            nKey = nKey + 1

        Next tPackageFile
                        
    Next tPackage
    Exit Sub
    
DisplayError:
    Debug.Assert False
    If (Err.Number <> 0) Then
        ShowError "DisplayPackages"
    End If
    
End Sub

Sub DisplayOSs(tEnumObjects As Object, tRootNode As Node, nKey As Integer)
    
    If tEnumObjects.Count = 0 Then
        Exit Sub
    End If

    Dim osNode As Node, ossNode As Node, osPropNode As Node
    Dim tOS As Object
    
    On Error GoTo DisplayError
    
    ' create the root OSs node
    Set ossNode = tvwItems.Nodes.Add(tRootNode.Key, tvwChild, "DOSS" & CStr(nKey), "OSs")
    nKey = nKey + 1

    ' display the enumeration of OS
    For Each tOS In tEnumObjects
    
        ' add the os node
        Set osNode = tvwItems.Nodes.Add(ossNode.Key, tvwChild, "DOSS" & CStr(nKey), tOS.Name)
        nKey = nKey + 1
        
        ' add the properties of this os node
        Set osPropNode = tvwItems.Nodes.Add(osNode.Key, tvwChild, "DOSS" & CStr(nKey), "Id: " & tOS.Id)
        nKey = nKey + 1
        Set osPropNode = tvwItems.Nodes.Add(osNode.Key, tvwChild, "DOSS" & CStr(nKey), "TypeId: " & tOS.TypeId)
        nKey = nKey + 1
        Set osPropNode = tvwItems.Nodes.Add(osNode.Key, tvwChild, "DOSS" & CStr(nKey), "Major: " & tOS.MajorVersion)
        nKey = nKey + 1
        Set osPropNode = tvwItems.Nodes.Add(osNode.Key, tvwChild, "DOSS" & CStr(nKey), "Minor: " & tOS.MinorVersion)
        nKey = nKey + 1
    
    Next tOS
    Exit Sub
    
DisplayError:
    Debug.Assert False
    If (Err.Number <> 0) Then
        ShowError "DisplayOSs"
    End If
    
End Sub

Sub DisplayOS(tOS As Object, tRootNode As Node, nKey As Integer)
    
    Dim osNode As Node, ossNode As Node, osPropNode As Node
    
    On Error GoTo DisplayError
    
    ' create the root OS node
    Set ossNode = tvwItems.Nodes.Add(tRootNode.Key, tvwChild, "DOS" & CStr(nKey), "OS")
    nKey = nKey + 1
    
    ' add the os node
    Set osNode = tvwItems.Nodes.Add(ossNode.Key, tvwChild, "DOS" & CStr(nKey), tOS.Name)
    nKey = nKey + 1
    
    ' add the properties of this os node
    Set osPropNode = tvwItems.Nodes.Add(osNode.Key, tvwChild, "DOS" & CStr(nKey), "Id: " & tOS.Id)
    nKey = nKey + 1
    Set osPropNode = tvwItems.Nodes.Add(osNode.Key, tvwChild, "DOS" & CStr(nKey), "TypeId: " & tOS.TypeId)
    nKey = nKey + 1
    Set osPropNode = tvwItems.Nodes.Add(osNode.Key, tvwChild, "DOS" & CStr(nKey), "Major: " & tOS.MajorVersion)
    nKey = nKey + 1
    Set osPropNode = tvwItems.Nodes.Add(osNode.Key, tvwChild, "DOS" & CStr(nKey), "Minor: " & tOS.MinorVersion)
    nKey = nKey + 1
    Exit Sub
    
DisplayError:
    Debug.Assert False
    If (Err.Number <> 0) Then
        ShowError "DisplayOS"
    End If
    
End Sub

Sub DisplayPlatforms(tEnumObjects As Object, tRootNode As Node, nKey As Integer)
    
    If tEnumObjects.Count = 0 Then
        Exit Sub
    End If

    Dim platformNode As Node, platformsNode As Node
    Dim tPlatform As Object
    
    On Error GoTo DisplayError
    
    ' create the root platforms node
    Set platformsNode = tvwItems.Nodes.Add(tRootNode.Key, tvwChild, "DPL" & CStr(nKey), "Platforms")
    nKey = nKey + 1

    ' display the platforms
    For Each tPlatform In tEnumObjects
    
        ' get the next element and add it to the tree
        Set platformNode = tvwItems.Nodes.Add(platformsNode.Key, tvwChild, "DPL" & CStr(nKey), tPlatform.Name)
        nKey = nKey + 1
                
        ' display the packages
        DisplayPackages tPlatform.EnumPackages, platformNode, nKey
        
        ' display the os
        DisplayOS tPlatform.GetOS, platformNode, nKey

        ' display the enumeration of transports
        DisplayTransports tPlatform.EnumTransports, platformNode, nKey

        ' display the enumeration of cpus
        DisplayCPUs tPlatform.EnumCPUs, platformNode, nKey

        ' display the enumeration of startup servers
        DisplayStartupServers tPlatform.EnumStartupServers, platformNode, nKey

        ' display the enumeration of devices
        DisplayDevices tPlatform, tPlatform.EnumDevices, platformNode, nKey
                        
        ' display the properties of platform
        DisplayProperties tPlatform.EnumProperties, platformNode, nKey
        
    Next tPlatform
    Exit Sub
    
DisplayError:
    Debug.Assert False
    If (Err.Number <> 0) Then
        ShowError "DisplayPlatforms"
    End If
    
End Sub

Sub DisplayServiceCategories(tEnumObjects As Object, tRootNode As Node, nKey As Integer)
    
    If tEnumObjects.Count = 0 Then
        Exit Sub
    End If

    Dim serviceCategoryNode As Node, serviceCategoriesNode As Node, serviceCategoryPropNode As Node
    Dim tServiceCategory As Object
    
    On Error GoTo DisplayError
    
    ' create the root platforms node
    Set serviceCategoriesNode = tvwItems.Nodes.Add(tRootNode.Key, tvwChild, "DSC" & CStr(nKey), "ServiceCategories")
    nKey = nKey + 1

    ' display the service categories
    For Each tServiceCategory In tEnumObjects
    
        ' get the next element and add it to the tree
        Set serviceCategoryNode = tvwItems.Nodes.Add(serviceCategoriesNode.Key, tvwChild, "DPL" & CStr(nKey), tServiceCategory.Name)
        nKey = nKey + 1
                
        Set serviceCategoryPropNode = tvwItems.Nodes.Add(serviceCategoryNode.Key, tvwChild, "DPL" & CStr(nKey), tServiceCategory.Id)
        nKey = nKey + 1
       
        ' display the enumeration of service infos
        DisplayServiceInfos tServiceCategory.EnumServiceInfos, serviceCategoryNode, nKey
                        
        ' display the properties of service category
        DisplayProperties tServiceCategory.EnumProperties, serviceCategoryNode, nKey
        
    Next tServiceCategory
    Exit Sub
    
DisplayError:
    Debug.Assert False
    If (Err.Number <> 0) Then
        ShowError "DisplayServiceCategories"
    End If
    
End Sub

Sub DisplayServiceInfos(tEnumObjects As Object, tRootNode As Node, nKey As Integer)
    
    If tEnumObjects.Count = 0 Then
        Exit Sub
    End If

    Dim serviceInfoNode As Node, serviceInfosNode As Node, serviceInfoPropNode As Node
    Dim tServiceInfo As Object
    
    On Error GoTo DisplayError
    
    ' create the root platforms node
    Set serviceInfosNode = tvwItems.Nodes.Add(tRootNode.Key, tvwChild, "DSI" & CStr(nKey), "ServiceInfos")
    nKey = nKey + 1

    ' display the service categories
    For Each tServiceInfo In tEnumObjects
    
        ' get the next element and add it to the tree
        Set serviceInfoNode = tvwItems.Nodes.Add(serviceInfosNode.Key, tvwChild, "DPL" & CStr(nKey), tServiceInfo.Name)
        nKey = nKey + 1
                                        
        Set serviceInfoPropNode = tvwItems.Nodes.Add(serviceInfoNode.Key, tvwChild, "DPL" & CStr(nKey), tServiceInfo.Id)
        nKey = nKey + 1
                                
        ' display the properties of service info
        DisplayProperties tServiceInfo.EnumProperties, serviceInfoNode, nKey
        
    Next tServiceInfo
    Exit Sub
    
DisplayError:
    Debug.Assert False
    If (Err.Number <> 0) Then
        ShowError "DisplayServiceInfos"
    End If
    
End Sub

Private Sub Form_Load()
            
    ' unique key for each tree node
    Dim nKey As Integer
    
    On Error GoTo DisplayError
    
    ' add the platform manager node
    Dim rootNode As Node
    Set rootNode = tvwItems.Nodes.Add(, , "Root Node", "Platform Manager")
    nKey = 1

    ' create the platman
    Dim tPlatman As Object
    Set tPlatman = CreateObject("PlatformManager.PlatformManager.1")

    ' display enumeration of Packages
    DisplayPackages tPlatman.EnumPackages, rootNode, nKey

    ' display enumeration of OSs
    DisplayOSs tPlatman.EnumOSs, rootNode, nKey
    
    ' display enumeration of bootable devices
    DisplayBootableDevices tPlatman.EnumBootableDevices, rootNode, nKey
    
    ' display enumeration of service categories
    DisplayServiceCategories tPlatman.EnumServiceCategories, rootNode, nKey

    ' display enumeration of cpus
    DisplayCPUs tPlatman.EnumCPUs, rootNode, nKey

    ' display enumeration of platforms
    DisplayPlatforms tPlatman.EnumPlatforms, rootNode, nKey
    
    ' display enumeration of properties of platman
    DisplayProperties tPlatman.EnumProperties, rootNode, nKey
      
    ' release the reference to platman object
    Set tPlatman = Nothing
    
    'if there is atleast one item, expand the root node
    If tvwItems.Nodes.Count > 0 Then
        If tvwItems.Nodes(1).Children > 0 Then
            tvwItems.Nodes(1).Child.EnsureVisible
        End If
    End If
    Exit Sub
    
DisplayError:
    Debug.Assert False
    Set tPlatman = Nothing
    If (Err.Number <> 0) Then
        ShowError "Form_Load"
    End If

End Sub

Private Sub Form_Resize()
    
    If WindowState <> vbMinimized Then
        If Me.Height > (2 * tvwItems.Top + 420) Then
            tvwItems.Height = Me.Height - (2 * tvwItems.Top + 400 + 40)
        End If
        If Me.Width > (2 * tvwItems.Left + 160) Then
            tvwItems.Width = Me.Width - (2 * tvwItems.Left + 160)
        End If
    End If
    
End Sub

Sub ShowError(ByVal sMsg$)

    ' display the error
    Dim sRtrnCode As String
    Dim lRet As Long
    Dim MessageText As String
    
    sRtrnCode = Space$(256)
    lRet = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, 0&, Err.Number, 0&, _
              sRtrnCode, 256&, 0&)
    If lRet > 0 Then
       MessageText = MessageText & Chr(10) & "Error in: " & sMsg$ & " ; Code: " & Hex(Err.Number) & " Message: " & Left(sRtrnCode, lRet)
    Else
        MessageText = Err.Description
    End If
    MsgBox MessageText
    Screen.MousePointer = vbDefault
    
    Err.Clear
    
End Sub

