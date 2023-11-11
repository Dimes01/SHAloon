#include "pch.h"
#include "Cryptoprovider.h"

Cryptoprovider::Cryptoprovider() {

}

// Вызов этого метода подразумевает пересканирование сертификатов
// поскольку за ним обязательно последует ряд вызовов GetNextCertificate
// для получения всех остальных сертификатов
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