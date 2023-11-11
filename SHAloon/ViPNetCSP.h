#pragma once

#include "Cryptoprovider.h"

class ViPNetCSP : public Cryptoprovider {
protected:
    virtual void refillCertificates();

public:
    ViPNetCSP();
};

