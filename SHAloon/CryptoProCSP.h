#pragma once

#include "Cryptoprovider.h"

class CryptoProCSP : public Cryptoprovider {
protected:
    virtual void refillCertificates() override;

public:
    CryptoProCSP();

    virtual void SignDocument(Certificate* certificate, const std::string& absoluteFilePath) override;
};