#include "pch.h"
#include "ShaloonLibrary.h"

void InitShaloon() {
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

Certificate* GetFirstCertificate() {
    return certStorage->CertGetFirst();
}

Certificate* GetNextCertificate() {
    return certStorage->GetNextCertificate();
}

void SignDocument(Certificate* certificate, 
                  const char* absoluteFilePath,
                  const char* absoluteSignaturePath) {
    /*
    TODO:
        1. ��������� �������� �� �������������
        2. ���� �������� �� ����������, �������� ��� � ��� ��������� ����������� ��������: �������
        3. ���������� � ���������������� �� ������� ���������, ���� �������� ����������
        4. �������� ��������� ���������� � ��� ��������� ����������� ��������: �����
    */

    // ��������� ������ ������������� �������
    Logger::Log(logger, false, "��������� CSP", "������ ��� �������� �������", "������ #519: ����-����", LogLevel::LOG_ERROR);
}


const char* GetLogSource() {
    std::string source = logger->GetLogSource();
    return ShaloonUtils::ToConstCharArray(source);
}

const char* GetLogSummary() {
    std::string summary = logger->GetLogSummary();
    return ShaloonUtils::ToConstCharArray(summary);
}

const char* GetLogMessage() {
    std::string message = logger->GetLogMessage();
    return ShaloonUtils::ToConstCharArray(message);
}

const char* GetLogTime() {
    std::string time = logger->GetLogTime();
    return ShaloonUtils::ToConstCharArray(time);
}

const char* GetLogLevel() {
    std::string logLevel = logger->GetLogLevel();
    return ShaloonUtils::ToConstCharArray(logLevel);
}

bool GetLogSuccess() {
    return logger->GetLogSuccess();
}