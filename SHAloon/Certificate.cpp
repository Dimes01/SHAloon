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
    tstringstream ss;

    for (long long i = static_cast<long long>(serialNumberSize) - 1; i >= 0; --i) {
        ss << std::setw(2) << std::setfill(TEXT('0')) << std::hex << (int)(serialNumber[i]);
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

void Certificate::SetCertContext(PCCERT_CONTEXT certContext) {
    mCertContext = certContext;
}

PCCERT_CONTEXT Certificate::GetCertContext() {
    return mCertContext;
}

Certificate::~Certificate() {
    if (mCertContext) CertFreeCertificateContext(mCertContext);
}