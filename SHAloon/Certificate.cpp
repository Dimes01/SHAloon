#include "pch.h"
#include "Certificate.h"

Certificate::Certificate(const std::string& subject, const std::string& publicKey)
    : mSubject(subject), mPublicKey(publicKey) {}

void Certificate::SetSubject(const std::string& subject) {
    mSubject = subject;
}

std::string Certificate::GetSubject() {
    return mSubject;
}

// что-то