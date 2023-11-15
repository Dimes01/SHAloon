#pragma once

#include "ShaloonUtils.h"
#include "CryptoProCSP.h"
#include "ViPNetCSP.h"
#include "CertificateStorage.h"
#include "Logger.h"

#define SHALOONAPI __declspec(dllexport)

Cryptoprovider* cryptoprovider;
CertificateStorage* certStorage;
Logger* logger;

extern "C" {
    SHALOONAPI void InitShaloon();
    SHALOONAPI void FinishShaloon();
    SHALOONAPI Certificate* GetFirstCertificate();
    SHALOONAPI Certificate* GetNextCertificate();
    SHALOONAPI void SignDocument(Certificate* certificate, 
        const LPTSTR absoluteFilePath, const LPTSTR absoluteSignaturePath);

    SHALOONAPI LPCTSTR GetCertificateSubject(Certificate* certificate);
    SHALOONAPI LPCTSTR GetCertificateIssuer(Certificate* certificate);
    SHALOONAPI LPCTSTR GetCertificateSerialNumber(Certificate* certificate);
    SHALOONAPI LPCTSTR GetCertificateNotAfter(Certificate* certificate);

    SHALOONAPI LPCTSTR GetLogSource();
    SHALOONAPI LPCTSTR GetLogSummary();
    SHALOONAPI LPCTSTR GetLogMessage();
    SHALOONAPI LPCTSTR GetLogTime();
    SHALOONAPI LPCTSTR GetLogLevel();
    SHALOONAPI bool GetLogSuccess();
}