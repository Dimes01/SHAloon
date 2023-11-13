#pragma once

#include "Cryptoprovider.h"

class ViPNetCSP : public Cryptoprovider {
protected:
    virtual void refillCertificates() override;

public:
    ViPNetCSP();

    virtual void SignDocument(Certificate* certificate, const std::string& absoluteFilePath) override;
};

