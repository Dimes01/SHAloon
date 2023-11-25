#include "pch.h"
#include "ShaloonUtils.h"

LPCTSTR ShaloonUtils::ToLPCTSTR(const tstring& str) {
    LPTSTR result = _tcsdup(str.c_str());
    return result;
}

LPCWSTR ShaloonUtils::ToLPCWSTR(const std::basic_string<WCHAR>& str) {
    LPWSTR result = _wcsdup(str.c_str());
    return result;
}
