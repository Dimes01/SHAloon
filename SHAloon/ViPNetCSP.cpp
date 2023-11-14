#include "pch.h"
#include "ViPNetCSP.h"

ViPNetCSP::ViPNetCSP() : Cryptoprovider() {
    // �������� �������� �������� ViPNet CSP. ���� ������, ������, �� ���� � �������.
    auto result = CryptAcquireContext(&hCryptProv, NULL, VPN_DEF_PROV, VPN_PROV_TYPE, CRYPT_VERIFYCONTEXT);
    if (result) {
        mInitialized = true;
    }
    if (hCryptProv) {
        CryptReleaseContext(hCryptProv, 0);
    }
}


void ViPNetCSP::SignDocument(Certificate* certificate,
                             const std::string& absoluteFilePath, 
                             const std::string& absoluteSignaturePath) {

}
