#include "pch.h"
#include "ShaloonUtils.h"

const char* ShaloonUtils::ToConstCharArray(const std::string& str) {
    size_t size = str.size() + 1;
    char* result = new char[size];
    strcpy_s(result, size, str.c_str());
    return result;
}
