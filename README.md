Replacement wrapper for Android AAPT tool to use '--no-version-vectors' when packaging

## Description

WORK IN PROGRESS

## Installation

#### Windows
* Navigate to `android-sdk\build-tools\xx.y.z\`
* Rename `aapt.exe` to `aapt-original.exe`
* Save `aapt-wrapper.exe` as `aapt.exe`

#### Unix
* Navigate to `android-sdk/build-tools/xx.y.z/`
* Rename `aapt` to `aapt-original`
* Save `aapt-wrapper` as `aapt`


## Compilation

Optional step if you want to compile it yourself.

#### [MingW](http://www.mingw.org/wiki/howto_install_the_mingw_gcc_compiler_suite) for Windows, G++ for Linux

`g++ aapt-wrapper.cpp -o aapt-wrapper`
