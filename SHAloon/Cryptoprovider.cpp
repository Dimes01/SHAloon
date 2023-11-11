#include "pch.h"
#include "Cryptoprovider.h"

Cryptoprovider::Cryptoprovider() {

}

Certificate* Cryptoprovider::GetFirstCertificate() {
    refillCertificates();
    mCertificatesIterator = mCertificates.begin();
    return *mCertificatesIterator;
}

Certificate* Cryptoprovider::GetNextCertificate() {
    ++mCertificatesIterator;
    if (mCertificatesIterator == mCertificates.end()) return nullptr;
    return *mCertificatesIterator;
}

Cryptoprovider::~Cryptoprovider() {
    for (auto& certificate : mCertificates) {
        if (certificate != nullptr) delete certificate;
    }
}