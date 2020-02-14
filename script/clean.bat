SET CURDIR=%~dp0

cd ..\
rmdir build_win /s /q
rmdir build_linux /s /q
rmdir build_vs /s /q

cd code

rmdir .vs /s /q

cd %CURDIR%