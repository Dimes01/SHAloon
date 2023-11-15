#include "pch.h"
#include "ShaloonUtils.h"

LPCTSTR ShaloonUtils::ToLPCTSTR(const tstring& str) {
    size_t size = str.size() + 1;
    LPTSTR result = new TCHAR[size];
    StringCchCopy(result, size, str.c_str());
    return result;
}
