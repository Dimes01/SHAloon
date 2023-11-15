#include "pch.h"
#include "Certificate.h"

Certificate::Certificate() {}

void Certificate::SetSubject(const tstring& subject) {
    mSubject = subject;
}

tstring Certificate::GetSubject() {
    return mSubject;
}

void Certificate::SetIssuer(const tstring& issuer) {
    mIssuer = issuer;
}

tstring Certificate::GetIssuer() {
    return mIssuer;
}

void Certificate::SetSerialNumber(const BYTE* serialNumber, const DWORD serialNumberSize) {
    mSerialNumberBinary = new BYTE[serialNumberSize];
    CopyMemory(mSerialNumberBinary, serialNumber, serialNumberSize);

    tstringstream ss;

    for (long long i = static_cast<long long>(serialNumberSize) - 1; i >= 0; --i) {
        ss << std::setw(2) << std::setfill(TEXT('0')) << std::hex << (int)(mSerialNumberBinary[i]);
    }

    mSerialNumberString = ss.str();
}

tstring Certificate::GetSerialNumber() {
    return mSerialNumberString;
}

void Certificate::SetNotAfter(const tstring& notAfter) {
    mNotAfter = notAfter;
}

tstring Certificate::GetNotAfter() {
    return mNotAfter;
}

Certificate::~Certificate() {
    if (mSerialNumberBinary) delete[] mSerialNumberBinary;
}