@echo off
for %%f in (*.exe) do call gzUnsign.bat %%f
for %%f in (*.dll) do call gzUnsign.bat %%f
:done