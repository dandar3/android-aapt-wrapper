Wrapper for `Android Asset Packaging Tool` (AAPT) to pass `--no-version-vectors` when packaging.

This is useful for non-Gradle builds that cannot pass this parameter (e.g. Android ADT not maintained anymore), to avoid apps using AppCompat to crash with:

```
Caused by: android.content.res.Resources$NotFoundException: File res/drawable/abc_vector_test.xml from drawable resource ID #0x7f020052
```

[Android Developers - Vector Drawables Backward Compatibility Solution](https://developer.android.com/guide/topics/graphics/vector-drawable-resources.html#vector-drawables-backward-solution)

## Installation

Download already compiled binaries from [Releases](https://github.com/dandar3/android-aapt-wrapper/releases) tab (top)

#### Windows
* Navigate to `android-sdk\build-tools\xx.y.z\`
* Rename `aapt.exe` to `aapt-original.exe`
* Save `aapt-wrapper.exe` as `aapt.exe`

#### Unix
* Navigate to `android-sdk/build-tools/xx.y.z/`
* Rename `aapt` to `aapt-original`
* Save `aapt-wrapper` as `aapt`

Verify installation by calling `aapt`. You should see the wrapper info followed by the real `aapt` info.

```
> aapt
Android Asset Packaging Tool - Wrapper
Version 1.0 (31 Dec 2017)
https://github.com/dandar3/android-aapt-wrapper
 
Command:
  aapt-original
 
Android Asset Packaging Tool
 
Usage:
 aapt l[ist] [-v] [-a] file.{zip,jar,apk}
   List contents of Zip-compatible archive.
 
 aapt d[ump] [--values] [--include-meta-data] WHAT file.{apk} [asset [asset ...]]
   strings          Print the contents of the resource table string pool in the APK.
...
```

## How to compile

Optional step if you need to compile it yourself with [MingW](http://www.mingw.org/wiki/howto_install_the_mingw_gcc_compiler_suite) for Windows / g++ for Linux.

```
g++ aapt-wrapper.cpp -o aapt-wrapper
```
