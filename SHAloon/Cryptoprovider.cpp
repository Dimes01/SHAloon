#include "pch.h"
#include "Cryptoprovider.h"

Cryptoprovider::Cryptoprovider() {
	
}

bool Cryptoprovider::IsInitialized() {
	return mInitialized;
}

Certificate* Cryptoprovider::GetFirstCertificate() {
	refillCertificates();
	mCertificatesIterator = mCertificates.begin();
	if (mCertificatesIterator == mCertificates.end()) return nullptr;
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