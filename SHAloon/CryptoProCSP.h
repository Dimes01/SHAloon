#pragma once

#include "Cryptoprovider.h"
#include <WinCryptEx.h>

class CryptoProCSP : public Cryptoprovider {
protected:
    virtual LPSTR getHashOidByKeyOid(LPSTR szKeyOid) override;

public:
    CryptoProCSP();

    virtual void SignDocument(Certificate* certificate,
        LPCTSTR absoluteFilePath, LPCTSTR absoluteSignaturePath) override;

    virtual Certificate* VerifySignature(LPCTSTR absoluteFilePath, LPCTSTR absoluteSignaturePath) override;

    virtual void EncryptDocument(Certificate* certificate, LPCTSTR absoluteSourcePath, LPCTSTR absoluteEncryptedPath) override;

    virtual Certificate* DecryptDocument(LPCTSTR absoluteEncryptedPath, LPCTSTR absoluteDecryptedPath) override;

    virtual ~CryptoProCSP();
};