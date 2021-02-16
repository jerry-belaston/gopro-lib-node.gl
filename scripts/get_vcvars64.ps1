# Download latest vswhere.exe from microsoft server into windows temp directory
$vswhereLatest = "https://github.com/Microsoft/vswhere/releases/latest/download/vswhere.exe"
$vswhere = "$env:temp\vswhere.exe"
if ([System.IO.File]::Exists($vswhere)) {
    remove-item $vswhere
}
invoke-webrequest $vswhereLatest -OutFile $vswhere

# Retrieve vcvars64, using vswhere
$vsInstallationPath = &$vswhere -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath
$vcvars64 = "$vsInstallationPath\VC\Auxiliary\Build\vcvars64.bat"

Write-Output $vcvars64