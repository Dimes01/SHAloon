#pragma once

#include "Cryptoprovider.h"
#include "CryptoProCSP.h"
#include "ViPNetCSP.h"

#define SHALOONAPI __declspec(dllexport)

Cryptoprovider* cryptoprovider;

extern "C" {
    SHALOONAPI void InitShaloon();
    SHALOONAPI Certificate* GetFirstCertificate();
    SHALOONAPI Certificate* GetNextCertificate();
    SHALOONAPI void SignDocument(Certificate* certificate, const char* absoluteFilePath);
}