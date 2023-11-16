#include "pch.h"
#include "ShaloonLibrary.h"

void InitShaloon() {
    CertificateStorage::Instance = new CertificateStorage();

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
    Logger::Log(false, TEXT("��������� CSP"), TEXT("������ ��� �������� �������"),
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