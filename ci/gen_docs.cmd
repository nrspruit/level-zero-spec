@echo off
setlocal enabledelayedexpansion

:: setup environment
call %~dp0setenv.cmd

:: set working dir
cd %SCRIPTS_DIR%

:: run cmd
echo %RUN_PY% run.py --!core --!extended --!tools --!md
%RUN_PY% run.py --!core --!extended --!tools --!md
