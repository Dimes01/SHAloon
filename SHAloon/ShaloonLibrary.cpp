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
    Logger::Log(logger, true, "", "", LogLevel::LOG_INFO);
}


const char* GetLogSummary() {
    std::string summary = logger->GetLogSummary();
    size_t size = summary.size() + 1;
    char* result = new char[size];
    strcpy_s(result, size, summary.c_str());
    return result;
}

const char* GetLogMessage() {
    std::string message = logger->GetLogMessage();
    size_t size = message.size() + 1;
    char* result = new char[size];
    strcpy_s(result, size, message.c_str());
    return result;
}

const char* GetLogTime() {
    std::string time = logger->GetLogTime();
    size_t size = time.size() + 1;
    char* result = new char[size];
    strcpy_s(result, size, time.c_str());
    return result;
}

const char* GetLogLevel() {
    std::string logLevel = logger->GetLogLevel();
    size_t size = logLevel.size() + 1;
    char* result = new char[size];
    strcpy_s(result, size, logLevel.c_str());
    return result;
}

bool GetLogSuccess() {
    return logger->GetLogSuccess();
}