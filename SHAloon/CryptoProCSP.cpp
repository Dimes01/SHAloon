#include "pch.h"
#include "CryptoProCSP.h"

CryptoProCSP::CryptoProCSP() : Cryptoprovider() {
    // �������� �������� �������� ��������� CSP. ���� ������, ������, �� ���� � �������.
    auto result = CryptAcquireContext(&mHCryptProv, NULL, CP_GR3410_2012_PROV, PROV_GOST_2012_256, CRYPT_VERIFYCONTEXT);
    if (result) {
        mInitialized = true;
    }
    if (mHCryptProv) {
        CryptReleaseContext(mHCryptProv, 0);
    }
}

void CryptoProCSP::SignDocument(Certificate* certificate,
                                const std::string& absoluteFilePath, 
                                const std::string& absoluteSignaturePath) {
    
}
