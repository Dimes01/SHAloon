#include "pch.h"
#include "CryptoProCSP.h"

CryptoProCSP::CryptoProCSP() : Cryptoprovider() {
    // Пытаемся получить контекст КриптоПро CSP. Если удачно, значит, он есть в системе.
    auto result = CryptAcquireContext(&hCryptProv, NULL, CP_GR3410_2012_PROV, PROV_GOST_2012_256, CRYPT_VERIFYCONTEXT);
    if (result) {
        mInitialized = true;
    }
    if (hCryptProv) {
        CryptReleaseContext(hCryptProv, 0);
    }
}

void CryptoProCSP::SignDocument(Certificate* certificate,
                                const tstring& absoluteFilePath, 
                                const tstring& absoluteSignaturePath) {
    
}

CryptoProCSP::~CryptoProCSP() {

}
