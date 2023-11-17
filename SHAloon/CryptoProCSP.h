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

    virtual ~CryptoProCSP();
};