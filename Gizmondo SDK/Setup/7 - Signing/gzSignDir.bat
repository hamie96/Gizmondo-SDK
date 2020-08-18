@echo off
dir *.exe *.dll /b >temp.txt
for /F %%f in (temp.txt) do call gzCopyAndSign %%f
del temp.txt
:done