@echo off
if "%1" == "" goto done
if not exist %1.unsigned goto done
del %1
move %1.unsigned %1
echo %1
goto done
:done