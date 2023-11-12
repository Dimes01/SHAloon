#include "pch.h"
#include "ShaloonLibrary.h"

void InitShaloon() {
    /*
    TODO:
        1. ����������, ����� ��������������� ������ ������������
        2. �� ��������� ���������� ���� 1 ���������������� ������ "cryptoprovider"
    */

    cryptoprovider = new CryptoProCSP(); // ��������
}

Certificate* GetFirstCertificate() {
    return cryptoprovider->GetFirstCertificate();
}

Certificate* GetNextCertificate() {
    return cryptoprovider->GetNextCertificate();
}

void SignDocument(Certificate* certificate, const char* absoluteFilePath) {
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