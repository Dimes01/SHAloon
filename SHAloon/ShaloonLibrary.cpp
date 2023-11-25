#include "pch.h"
#include "ShaloonLibrary.h"

void InitShaloon() {
    CertificateStorage::Instance = new CertificateStorage();

    cryptoprovider = new CryptoProCSP();
    if (cryptoprovider->IsInitialized()) {
        return;
    } 
    
    delete cryptoprovider;
    cryptoprovider = new ViPNetCSP();
    if (cryptoprovider->IsInitialized()) {
        return;
    }

    delete cryptoprovider;
    cryptoprovider = nullptr;

    Logger::Log(false, _T("ShaloonLibrary::InitShaloon()"), _T("No cryptoprovider found"), tstring(), LogLevel::LOG_FATAL);
}

void FinishShaloon() {
    Logger::Log(true, _T("ShaloonLibrary::FinishShaloon()"), _T("Freeing all resources..."), tstring(), LogLevel::LOG_INFO);
    if (cryptoprovider) delete cryptoprovider;
    if (CertificateStorage::Instance) delete CertificateStorage::Instance;
    if (Logger::Instance) delete Logger::Instance;
}

Certificate* GetFirstCertificate() {
    return CertificateStorage::Instance->GetFirstCertificate();
}

Certificate* GetNextCertificate() {
    return CertificateStorage::Instance->GetNextCertificate();
}

void SignDocument(Certificate* certificate, 
                  LPCTSTR absoluteFilePath,
                  LPCTSTR absoluteSignaturePath) {
    if (cryptoprovider == nullptr) {
        Logger::Log(false, _T("ShaloonLibrary::SignDocument()"), _T("Cryptoprovider doesn't exist"), tstring(), LogLevel::LOG_FATAL);
        return;
    }
    cryptoprovider->SignDocument(certificate, absoluteFilePath, absoluteSignaturePath);
}

Certificate* VerifySignature(LPCTSTR absoluteFilePath, LPCTSTR absoluteSignaturePath) {
    if (cryptoprovider == nullptr) {
        Logger::Log(false, _T("ShaloonLibrary::VerifySignature()"), _T("Cryptoprovider doesn't exist"), tstring(), LogLevel::LOG_FATAL);
        return nullptr;
    }
    return cryptoprovider->VerifySignature(absoluteFilePath, absoluteSignaturePath);
}


void EncryptDocument(Certificate* certificate, LPCTSTR absoluteSourcePath, LPCTSTR absoluteEncryptedPath) {
    if (cryptoprovider == nullptr) {
        Logger::Log(false, _T("ShaloonLibrary::EncryptDocument()"), _T("Cryptoprovider doesn't exist"), tstring(), LogLevel::LOG_FATAL);
        return;
    }
    cryptoprovider->EncryptDocument(certificate, absoluteSourcePath, absoluteEncryptedPath);
}

Certificate* DecryptDocument(LPCTSTR absoluteEncryptedPath, LPCTSTR absoluteDecryptedPath) {
    if (cryptoprovider == nullptr) {
        Logger::Log(false, _T("ShaloonLibrary::DecryptDocument()"), _T("Cryptoprovider doesn't exist"), tstring(), LogLevel::LOG_FATAL);
        return nullptr;
    }
    return cryptoprovider->DecryptDocument(absoluteEncryptedPath, absoluteDecryptedPath);
}


LPCTSTR GetCertificateSubject(Certificate* certificate) {
    auto subject = certificate->GetSubject();
    return ShaloonUtils::ToLPCTSTR(subject);
}

LPCTSTR GetCertificateIssuer(Certificate* certificate) {
    auto issuer = certificate->GetIssuer();
    return ShaloonUtils::ToLPCTSTR(issuer);
}

LPCTSTR GetCertificateSerialNumber(Certificate* certificate) {
    auto serialNumber = certificate->GetSerialNumber();
    return ShaloonUtils::ToLPCTSTR(serialNumber);
}

LPCTSTR GetCertificateNotAfter(Certificate* certificate) {
    auto notAfter = certificate->GetNotAfter();
    return ShaloonUtils::ToLPCTSTR(notAfter);
}

LPCTSTR GetCertificateNotBefore(Certificate* certificate) {
    auto notBefore = certificate->GetNotBefore();
    return ShaloonUtils::ToLPCTSTR(notBefore);
}

LPCTSTR GetCertificateSha1Hash(Certificate* certificate) {
    auto notBefore = certificate->GetSha1Hash();
    return ShaloonUtils::ToLPCTSTR(notBefore);
}

LPCTSTR GetCertificatePublicKeyBytes(Certificate* certificate) {
    auto notBefore = certificate->GetPublicKeyBytes();
    return ShaloonUtils::ToLPCTSTR(notBefore);
}

LPCWSTR GetCertificatePublicKeyAlgorithm(Certificate* certificate) {
    auto pkAlgorithm = certificate->GetPublicKeyAlgorithm();
    return ShaloonUtils::ToLPCWSTR(pkAlgorithm);
}

LPCWSTR GetCertificateSignatureAlgorithm(Certificate* certificate) {
    auto signatureAlgorithm = certificate->GetSignatureAlgorithm();
    return ShaloonUtils::ToLPCWSTR(signatureAlgorithm);
}

LPCWSTR GetCertificateFullSubject(Certificate* certificate) {
    auto fullSubject = certificate->GetFullSubject();
    return ShaloonUtils::ToLPCWSTR(fullSubject);
}

LPCWSTR GetCertificateFullIssuer(Certificate* certificate) {
    auto fullIssuer = certificate->GetFullIssuer();
    return ShaloonUtils::ToLPCWSTR(fullIssuer);
}


LPCTSTR GetLogSource() {
    tstring source = Logger::Instance->GetLogSource();
    return ShaloonUtils::ToLPCTSTR(source);
}

LPCTSTR GetLogSummary() {
    tstring summary = Logger::Instance->GetLogSummary();
    return ShaloonUtils::ToLPCTSTR(summary);
}

LPCTSTR GetLogMessage() {
    tstring message = Logger::Instance->GetLogMessage();
    return ShaloonUtils::ToLPCTSTR(message);
}

LPCTSTR GetLogTime() {
    tstring time = Logger::Instance->GetLogTime();
    return ShaloonUtils::ToLPCTSTR(time);
}

LPCTSTR GetLogLevel() {
    tstring logLevel = Logger::Instance->GetLogLevel();
    return ShaloonUtils::ToLPCTSTR(logLevel);
}

bool GetLogSuccess() {
    return Logger::Instance->GetLogSuccess();
}

void SetMinimalLogLevel(LPCTSTR logLevel) {
    Logger::SetMinimalLogLevel(logLevel);
}
