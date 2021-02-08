#!/usr/bin/bash
echo "starting msvc environment"
if [[ -z "${VCVARS64}" ]]; then
  export VCVARS64='"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"'
fi
# Set Visual Studio environment variables
cmd='WSLENV=VCVARS64/w cmd.exe /C %VCVARS64% \&\& wsl.exe'
if [[ -n $1 ]]; then
  cmd+=" < $1"
fi
echo "running command: $cmd"
eval $cmd
