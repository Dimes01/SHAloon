#pragma once

#include "Cryptoprovider.h"

class CryptoProCSP : public Cryptoprovider {
protected:
    virtual void refillCertificates();

public:
    CryptoProCSP();
};