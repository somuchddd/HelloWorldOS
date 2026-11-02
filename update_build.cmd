
@echo off
setlocal

cd /d "%~dp0"

echo Updating source code from Git

git pull --rebase
if errorlevel 1 (
    echo Git update failed!
    exit /b 1
)

echo Configuring CMake

cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=g++
if errorlevel 1 exit /b 1


echo Building project

cmake --build build
if errorlevel 1 exit /b 1

echo Running program

.\build\hello.exe
if errorlevel 1 exit /b 1

echo Finished successfully!

endlocal
