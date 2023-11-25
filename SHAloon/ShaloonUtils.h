#pragma once

class ShaloonUtils {
public:
    static LPCTSTR ToLPCTSTR(const tstring& str);
    static LPCWSTR ToLPCWSTR(const std::basic_string<WCHAR>& str);
};

