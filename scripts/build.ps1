param(
    [Parameter(Mandatory = $true)]
    [string]$Source,
    [switch]$StageForDebug
)

$ErrorActionPreference = 'Stop'
$sourceFile = Get-Item -LiteralPath $Source
if ($sourceFile.Extension -ne '.c') {
    throw 'Open a C source file before building.'
}

$sourceDirectory = $sourceFile.Directory.FullName
$sourceNames = @($sourceFile.Name)
$outputName = $sourceFile.BaseName + '.exe'

if ($sourceFile.Directory.Name -eq 'test06-1') {
    $sourceNames = @('main.c', 'sub.c')
    $outputName = 'main.exe'
}
elseif ($sourceFile.Directory.Name -eq 'test06-2') {
    $sourceNames = @('main.c', 'sum.c')
    $outputName = 'main.exe'
    Write-Host 'Exercise 6-2: a linker error for all_files is the expected result.'
}

$compiler = 'C:\msys64\ucrt64\bin\gcc.exe'
$compilerArguments = @('-std=c17', '-g', '-Wall', '-Wextra', '-fno-common')
$compilerArguments += "-fdebug-prefix-map=$sourceDirectory=C:/codex-source"
$compilerArguments += $sourceNames
$compilerArguments += @('-o', $outputName)

Push-Location -LiteralPath $sourceDirectory
try {
    & $compiler @compilerArguments
    $compilerExitCode = $LASTEXITCODE
}
finally {
    Pop-Location
}

if ($compilerExitCode -ne 0) {
    exit $compilerExitCode
}

if ($StageForDebug) {
    Copy-Item -LiteralPath (Join-Path $sourceDirectory $outputName) `
        -Destination (Join-Path $env:TEMP '07-debug.exe') -Force
}

exit 0
