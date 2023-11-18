#include "pch.h"
#include "Logger.h"

Logger* Logger::Instance = nullptr;

Logger::Logger() {}

tstring Logger::GetLogSource() {
    return mSource;
}

void Logger::SetLogSource(const tstring& source) {
    mSource = source;
}

tstring Logger::GetLogSummary() {
    return mSummary;
}

void Logger::SetLogSummary(const tstring& summary) {
    mSummary = summary;
}

tstring Logger::GetLogMessage() {
    return mMessage;
}

void Logger::SetLogMessage(const tstring& message){
    mMessage = message;
}

tstring Logger::GetLogTime() {
    return mTime;
}

void Logger::SetLogTime() {
    auto const currentLocalTime = std::chrono::current_zone()->to_local(std::chrono::system_clock::now());
    mTime = std::format(LogTimeFormat, currentLocalTime);
}

tstring Logger::GetLogLevel() {
    return mLogLevel;
}

void Logger::SetLogLevel(LogLevel logLevel) {
    if (logLevel == LogLevel::LOG_FATAL) mLogLevel = _T("FATAL");
    else if (logLevel == LogLevel::LOG_ERROR) mLogLevel = _T("ERROR");
    else if (logLevel == LogLevel::LOG_WARN) mLogLevel = _T("WARN");
    else if (logLevel == LogLevel::LOG_INFO) mLogLevel = _T("INFO");
    else mLogLevel = _T("INFO");
}

bool Logger::GetLogSuccess() {
    return mSuccess;
}

void Logger::SetLogSuccess(bool success) {
    mSuccess = success;
}

void Logger::Log(bool success, const tstring& source, const tstring& summary,
        const tstring& message, LogLevel logLevel) {
    if (Instance == nullptr) Instance = new Logger();
    Instance->SetLogSuccess(success);
    Instance->SetLogSource(source);
    Instance->SetLogSummary(summary);
    Instance->SetLogMessage(message);
    Instance->SetLogLevel(logLevel);
}

void Logger::WinApiLog(bool success, const tstring& source, const tstring& summary, LogLevel logLevel) {
    tstring errorCode = std::format(_T("WINAPI error code: 0x{:x}"), GetLastError());
    Log(success, source, summary, errorCode, logLevel);
}
