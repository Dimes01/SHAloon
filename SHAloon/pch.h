// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here
#include "framework.h"
#include <algorithm>
#include <string>
#include <list>
#include <sstream>
#include <tchar.h>
#include <locale>
#include <wincrypt.h>
#include <chrono>
#include <format>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <system_error>
#include <cstdlib>
#include <strsafe.h>

#ifndef MY_TSTRING
#define MY_TSTRING

typedef std::basic_string<TCHAR> tstring;
typedef std::basic_stringstream<TCHAR> tstringstream;

#ifdef UNICODE
typedef std::wofstream tofstream;
typedef std::wifstream tifstream;
#else
typedef std::ofstream tofstream;
typedef std::ifstream tifstream;
#endif // UNICODE

#endif // MY_TSTRING

#endif //PCH_H
