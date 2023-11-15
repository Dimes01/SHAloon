#pragma once

#include "Cryptoprovider.h"
#include <WinCryptEx.h>

class CryptoProCSP : public Cryptoprovider {
protected:

public:
    CryptoProCSP();

    virtual void SignDocument(Certificate* certificate,
        const tstring& absoluteFilePath, const tstring& absoluteSignaturePath) override;

    virtual ~CryptoProCSP();
};