@set CURRENT_PATH=%~dp0%
cd ..\..\

REM set PATH=%cd%\deps\cmake-3.16.2-win64-x64\bin;%PATH%

rmdir build_win /s /q
mkdir build_win

cd build_win
cmake ..\code\ -G "Visual Studio 17 2022" -A x64 -DSATES_WIN:STRING=yes

cd %CURRENT_PATH%