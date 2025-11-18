@echo off
setlocal enabledelayedexpansion

:: Folder to store firmware
set BIN_DIR=bin

:: Create bin folder if it doesn't exist
if not exist "%BIN_DIR%" mkdir "%BIN_DIR%"

echo ====================================================
echo  Compiling all envsensor YAML files to BIN ...
echo ====================================================

:: Loop over all envsensor*.yaml files
for %%F in (envsensor*.yaml) do (
    set "YAML_FILE=%%F"
    set "NAME=%%~nF"  :: filename without extension

    echo.
    echo 🛠️  Compiling !YAML_FILE! ...

    :: Compile using ESPHome CLI
    esphome compile "!YAML_FILE!"
    if errorlevel 1 (
        echo  Build failed for !YAML_FILE!
        pause
        exit /b
    )

    :: Move the firmware.bin to bin folder
    set "SRC_BIN=.!NAME!\.pioenvs\!NAME!\firmware.bin"
    set "DST_BIN=%BIN_DIR%\!NAME!.bin"

    if exist "!SRC_BIN!" (
        move /Y "!SRC_BIN!" "!DST_BIN!" >nul
        echo  !NAME!.bin saved to %BIN_DIR%\
    ) else (
        echo  Firmware not found for !NAME!
    )
)

echo.
echo  All builds completed! Check the "%BIN_DIR%" folder.
pause
