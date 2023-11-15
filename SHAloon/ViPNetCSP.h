#pragma once

#include "Cryptoprovider.h"
#include <cspsdk/importitccsp.h>

class ViPNetCSP : public Cryptoprovider {
protected:

public:
    ViPNetCSP();

    virtual void SignDocument(Certificate* certificate,
        const tstring& absoluteFilePath, const tstring& absoluteSignaturePath) override;

    virtual ~ViPNetCSP();
};

