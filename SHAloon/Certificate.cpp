#include "pch.h"
#include "Certificate.h"

Certificate::Certificate() {}

void Certificate::SetSubject(const std::string& subject) {
    mSubject = subject;
}

std::string Certificate::GetSubject() {
    return mSubject;
}

void Certificate::SetIssuer(const std::string& issuer) {
    mIssuer = issuer;
}

std::string Certificate::GetIssuer() {
    return mIssuer;
}

void Certificate::SetSerialNumber(const std::string& serialNumber) {
    mSerialNumber = serialNumber;
}

std::string Certificate::GetSerialNumber() {
    return mSerialNumber;
}

void Certificate::SetNotAfter(const std::string& notAfter) {
    mNotAfter = notAfter;
}

std::string Certificate::GetNotAfter() {
    return mNotAfter;
}
