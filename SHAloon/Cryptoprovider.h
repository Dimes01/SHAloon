#pragma once

#include "Certificate.h"

class Cryptoprovider {
protected:
    bool mInitialized = false;

    HCRYPTPROV hCryptProv = 0;

public:
    Cryptoprovider();

    bool IsInitialized();

    virtual void SignDocument(Certificate* certificate, 
        const tstring& absoluteFilePath, const tstring& absoluteSignaturePath) = 0;

    virtual ~Cryptoprovider();
};

