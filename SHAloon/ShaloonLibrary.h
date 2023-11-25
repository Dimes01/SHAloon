#pragma once

#include "ShaloonUtils.h"
#include "CryptoProCSP.h"
#include "ViPNetCSP.h"
#include "CertificateStorage.h"
#include "Logger.h"

#define SHALOONAPI __declspec(dllexport)

Cryptoprovider* cryptoprovider;

extern "C" {
    SHALOONAPI void InitShaloon();
    SHALOONAPI void FinishShaloon();

    SHALOONAPI Certificate* GetFirstCertificate();
    SHALOONAPI Certificate* GetNextCertificate();

    SHALOONAPI void SignDocument(Certificate* certificate, LPCTSTR absoluteFilePath, LPCTSTR absoluteSignaturePath);
    SHALOONAPI Certificate* VerifySignature(LPCTSTR absoluteFilePath, LPCTSTR absoluteSignaturePath);

    SHALOONAPI void EncryptDocument(Certificate* certificate, LPCTSTR absoluteSourcePath, LPCTSTR absoluteEncryptedPath);
    SHALOONAPI Certificate* DecryptDocument(LPCTSTR absoluteEncryptedPath, LPCTSTR absoluteDecryptedPath);

    SHALOONAPI LPCTSTR GetCertificateSubject(Certificate* certificate);
    SHALOONAPI LPCTSTR GetCertificateIssuer(Certificate* certificate);
    SHALOONAPI LPCTSTR GetCertificateSerialNumber(Certificate* certificate);
    SHALOONAPI LPCTSTR GetCertificateNotAfter(Certificate* certificate);

    SHALOONAPI LPCTSTR GetCertificateNotBefore(Certificate* certificate);
    SHALOONAPI LPCTSTR GetCertificateSha1Hash(Certificate* certificate);
    SHALOONAPI LPCTSTR GetCertificatePublicKeyBytes(Certificate* certificate);
    SHALOONAPI LPCWSTR GetCertificatePublicKeyAlgorithm(Certificate* certificate);
    SHALOONAPI LPCWSTR GetCertificateSignatureAlgorithm(Certificate* certificate);
    SHALOONAPI LPCWSTR GetCertificateFullSubject(Certificate* certificate);
    SHALOONAPI LPCWSTR GetCertificateFullIssuer(Certificate* certificate);

    SHALOONAPI LPCTSTR GetLogSource();
    SHALOONAPI LPCTSTR GetLogSummary();
    SHALOONAPI LPCTSTR GetLogMessage();
    SHALOONAPI LPCTSTR GetLogTime();
    SHALOONAPI LPCTSTR GetLogLevel();
    SHALOONAPI bool GetLogSuccess();

    SHALOONAPI void SetMinimalLogLevel(LPCTSTR logLevel);
}