@echo off
setlocal
set "SOURCE=%~dp0"
set "OUT=bin"
set "RelBuild=Release"
rem assume the 18362 EWDK is mounted at H:
call "H:\BuildEnv\SetupBuildEnv.cmd" x86_arm64
@echo off
if errorlevel 1 exit /b 1

cd /d "%SOURCE%"
if errorlevel 1 exit /b 1

if not exist "%OUT%\package" mkdir "%OUT%\package"
if errorlevel 1 exit /b 1
if not exist "%OUT%\package\PDB" mkdir "%OUT%\package\PDB"
if errorlevel 1 exit /b 1

msbuild.exe ES8316\ES8316.vcxproj /t:Rebuild /m /nologo /v:minimal ^
 /p:Configuration=%RelBuild% /p:Platform=ARM64 ^
 /p:WindowsTargetPlatformVersion=10.0.18362.0 ^
 /p:SignMode=Off /p:EnableInf2cat=false /p:SupportsPackaging=false
if errorlevel 1 exit /b 1

for %%F in (
    ES8316\ARM64\%RelBuild%\ES8316.sys
    ES8316\ARM64\%RelBuild%\ES8316.inf
) do (
    if exist "%SOURCE%%%F" (
        copy /y "%SOURCE%%%F" "%OUT%\package\" >nul
        if errorlevel 1 exit /b 1
    ) else (
        echo !!! MISSING: %SOURCE%%%F
        exit /b 1
    )
)

for %%F in (
    ES8316\ARM64\%RelBuild%\ES8316.pdb
) do (
    if exist "%SOURCE%%%F" (
        copy /y "%SOURCE%%%F" "%OUT%\package\PDB\" >nul
        if errorlevel 1 exit /b 1
    ) else (
        echo !!! MISSING: %SOURCE%%%F
        exit /b 1
    )
)

echo Built package: "%OUT%\package"
exit /b 0
