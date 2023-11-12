#include "pch.h"
#include "ShaloonLibrary.h"

void InitShaloon() {
    /*
    TODO:
        1. Определить, какой криптопровайдер сейчас используется
        2. На основании результата шага 1 инициализировать объект "cryptoprovider"
    */

    cryptoprovider = new CryptoProCSP(); // Заглушка
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
        1. Проверить документ на существование
        2. Если документ не существует, записать это в лог последней совершённой операции: неудача
        3. Обратиться к криптопровайдеру на подпись документа, если документ существует
        4. Записать результат подписания в лог последней совершённой операции: успех
    */

    // Временный пример использования логгера
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