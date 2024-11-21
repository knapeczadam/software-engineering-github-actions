@echo off
:: Enable error handling to stop the script if a command fails
setlocal enabledelayedexpansion
set "BUILD_DIR=build"

echo Generating build system...
cmake -S . -B %BUILD_DIR% -DBUILD_TESTS=ON
if errorlevel 1 goto error

echo Building the project...
cmake --build %BUILD_DIR%
if errorlevel 1 goto error

echo Running tests...
ctest --test-dir %BUILD_DIR%
if errorlevel 1 goto error

echo Script completed successfully.
exit /b 0

:error
echo An error occurred. Exiting...
exit /b 1