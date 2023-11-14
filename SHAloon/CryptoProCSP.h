#pragma once

#include "Cryptoprovider.h"
#include <WinCryptEx.h>

class CryptoProCSP : public Cryptoprovider {
protected:

public:
    CryptoProCSP();

    virtual void SignDocument(Certificate* certificate,
        const std::string& absoluteFilePath, const std::string& absoluteSignaturePath) override;
};