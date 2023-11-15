#include "pch.h"
#include "ShaloonLibrary.h"

void InitShaloon() {
    certStorage = new CertificateStorage();

    cryptoprovider = new CryptoProCSP();
    if (cryptoprovider->IsInitialized()) {
        std::cout << "CryptoPro is working here!\n";
        return;
    } 
    
    delete cryptoprovider;
    cryptoprovider = new ViPNetCSP();
    if (cryptoprovider->IsInitialized()) {
        std::cout << "ViPNet is working here!\n";
        return;
    }
}

void FinishShaloon() {
    if (cryptoprovider) delete cryptoprovider;
    if (certStorage) delete certStorage;
    if (logger) delete logger;
}

Certificate* GetFirstCertificate() {
    return certStorage->GetFirstCertificate();
}

Certificate* GetNextCertificate() {
    return certStorage->GetNextCertificate();
}

void SignDocument(Certificate* certificate, 
                  const LPTSTR absoluteFilePath,
                  const LPTSTR absoluteSignaturePath) {
    /*
    TODO:
        1. ��������� �������� �� �������������
        2. ���� �������� �� ����������, �������� ��� � ��� ��������� ����������� ��������: �������
        3. ���������� � ���������������� �� ������� ���������, ���� �������� ����������
        4. �������� ��������� ���������� � ��� ��������� ����������� ��������: �����
    */

    // ��������� ������ ������������� �������
    Logger::Log(logger, false, TEXT("��������� CSP"), TEXT("������ ��� �������� �������"),
        TEXT("������ #519: ����-����"), LogLevel::LOG_ERROR);
}


LPCTSTR GetCertificateSubject(Certificate* certificate) {
    auto subject = certificate->GetSubject();
    return ShaloonUtils::ToLPCTSTR(subject);
}

LPCTSTR GetCertificateIssuer(Certificate* certificate) {
    auto subject = certificate->GetIssuer();
    return ShaloonUtils::ToLPCTSTR(subject);
}

LPCTSTR GetCertificateSerialNumber(Certificate* certificate) {
    auto subject = certificate->GetSerialNumber();
    return ShaloonUtils::ToLPCTSTR(subject);
}

LPCTSTR GetCertificateNotAfter(Certificate* certificate) {
    auto subject = certificate->GetNotAfter();
    return ShaloonUtils::ToLPCTSTR(subject);
}


LPCTSTR GetLogSource() {
    tstring source = logger->GetLogSource();
    return ShaloonUtils::ToLPCTSTR(source);
}

LPCTSTR GetLogSummary() {
    tstring summary = logger->GetLogSummary();
    return ShaloonUtils::ToLPCTSTR(summary);
}

LPCTSTR GetLogMessage() {
    tstring message = logger->GetLogMessage();
    return ShaloonUtils::ToLPCTSTR(message);
}

LPCTSTR GetLogTime() {
    tstring time = logger->GetLogTime();
    return ShaloonUtils::ToLPCTSTR(time);
}

LPCTSTR GetLogLevel() {
    tstring logLevel = logger->GetLogLevel();
    return ShaloonUtils::ToLPCTSTR(logLevel);
}

bool GetLogSuccess() {
    return logger->GetLogSuccess();
}