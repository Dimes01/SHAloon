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

    virtual void EncryptDocument(Certificate* certificate, LPCTSTR absoluteSourcePath, LPCTSTR absoluteEncryptedPath) override;

    virtual Certificate* DecryptDocument(LPCTSTR absoluteEncryptedPath, LPCTSTR absoluteDecryptedPath) override;

    virtual ~ViPNetCSP();
};

