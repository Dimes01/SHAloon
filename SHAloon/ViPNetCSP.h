#pragma once

#include "Cryptoprovider.h"
#include <cspsdk/importitccsp.h>

class ViPNetCSP : public Cryptoprovider {
protected:
    virtual LPSTR getHashOidByKeyOid(LPSTR szKeyOid) override;

public:
    ViPNetCSP();

    virtual void SignDocument(Certificate* certificate,
        LPCTSTR absoluteFilePath, LPCTSTR absoluteSignaturePath) override;

    virtual Certificate* VerifySignature(LPCTSTR absoluteFilePath, LPCTSTR absoluteSignaturePath) override;

    virtual ~ViPNetCSP();
};

