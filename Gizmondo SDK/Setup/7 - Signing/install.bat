GizDevRun.pfx
certutil.exe
call getdevrunkey.bat
gzCreateBats.exe

rem pushd .
rem call gzSignCE.bat
rem popd

pushd .
call gzCopyFiles.bat
popd
