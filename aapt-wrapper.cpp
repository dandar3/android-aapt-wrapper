/*
 * Program  : aapt-wrapper.cpp
 * Purpose  : Replacement wrapper for 'Android Asset Packaging Tool' (aapt.exe) to
 *            pass "--no-version-vectors" option to the real AAPT tool when packaging.
 * Author   : Dan Dar3 <dan.dar33@gmail.com>
 * Created  : 31 Dec 2017
 * Project  : https://github.com/dandar3/android-aapt-wrapper
 *
 * Install : Windows                                       Linux
 *           o Go to android-sdk\build-tools\xx.y.z\       o Go to android-sdk/build-tools/xx.y.z/
 *           o Rename "aapt.exe" to "aapt-original.exe"    o Rename "aapt" to "aapt-original"
 *           o Save "aapt-wrapper.exe" as "aapt.exe"       o Save "aapt-wrapper" as "aapt"
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;

static const string VERSION = "1.0";
static const string DATE    = "31 Dec 2017";
static const string PROJECT = "https://github.com/dandar3/android-aapt-wrapper";

#if defined(WIN32)
static const char   PATH_SEPARATOR = '\\';
static const string AAPT_ORIGINAL  = "aapt-original.exe";
#else 
static const char   PATH_SEPARATOR = '/';
static const string AAPT_ORIGINAL  = "aapt-original";
#endif

int main(int argc, char *argv[]) {
  // Prepare new command...
  string cmdline;
  cmdline.reserve(4096);
  
  // Use calling location for current program to call the real "aapt"...
  string progpath = string(argv[0]);
  size_t lastpos  = progpath.rfind(PATH_SEPARATOR);
  if (lastpos != string::npos) {
     cmdline.append(progpath, 0, lastpos + 1);
  }
  cmdline.append(AAPT_ORIGINAL);
  
  // Copy arguments over...
  for (int i = 1; i < argc; i++) {
    // Quote argument if contains spaces...
    bool quote = (strchr(argv[i], ' ') != NULL);
    if (quote) {
      cmdline.append(" \"");
      cmdline.append(argv[i]);
      cmdline.append("\"");
    }
    // No need to quote...
    else {
      cmdline.append(" ");
      cmdline.append(argv[i]);    
    }
  }
  
  // 'package' action...
  if (argc > 1 && strcmp(argv[1], "package") == 0) {
    cmdline.append(" --no-version-vectors");
  }
  
  // Print new command line...
  cout << "Android Asset Packaging Tool - Wrapper" << endl;
  cout << "Version "   << VERSION << " (" << DATE << ")" << endl;
  cout << PROJECT      << endl    << endl;
  cout << "Command: "  << endl;
  cout << "  "         << cmdline << endl << endl;

  // Execute...
  return system(cmdline.c_str());
}