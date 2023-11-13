#pragma once

#include "ShaloonUtils.h"
#include "Cryptoprovider.h"
#include "CryptoProCSP.h"
#include "ViPNetCSP.h"
#include "Logger.h"

#define SHALOONAPI __declspec(dllexport)

Cryptoprovider* cryptoprovider;
Logger* logger;

extern "C" {
    SHALOONAPI void InitShaloon();
    SHALOONAPI Certificate* GetFirstCertificate();
    SHALOONAPI Certificate* GetNextCertificate();
    SHALOONAPI void SignDocument(Certificate* certificate, 
        const char* absoluteFilePath, const char* absoluteSignaturePath);

    SHALOONAPI const char* GetLogSource();
    SHALOONAPI const char* GetLogSummary();
    SHALOONAPI const char* GetLogMessage();
    SHALOONAPI const char* GetLogTime();
    SHALOONAPI const char* GetLogLevel();
    SHALOONAPI bool GetLogSuccess();
}