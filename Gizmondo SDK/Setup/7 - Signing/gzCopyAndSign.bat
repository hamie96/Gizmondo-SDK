@echo off
if "%1" == "" goto done
if exist %1.unsigned goto done
attrib %1 -r
copy %1 %1.unsigned
call gzSign %1
:done