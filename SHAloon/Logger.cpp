#include "pch.h"
#include "Logger.h"

Logger::Logger(bool success, const tstring& source, const tstring& summary,
               const tstring& message, LogLevel logLevel)
               : mSuccess(success), mSource(source), mSummary(summary), mMessage(message) {
    setLogTime();
    setLogLevel(logLevel);
}

tstring Logger::GetLogSource() {
    return mSource;
}

tstring Logger::GetLogSummary() {
    return mSummary;
}

tstring Logger::GetLogMessage() {
    return mMessage;
}

tstring Logger::GetLogTime() {
    return mTime;
}

tstring Logger::GetLogLevel() {
    return mLogLevel;
}

bool Logger::GetLogSuccess() {
    return mSuccess;
}

void Logger::setLogTime() {
    auto const currentLocalTime = std::chrono::current_zone()->to_local(std::chrono::system_clock::now());
    mTime = std::format(LogTimeFormat, currentLocalTime);
}

void Logger::setLogLevel(LogLevel logLevel) {
    if (logLevel == LogLevel::LOG_FATAL) mLogLevel = _T("FATAL");
    else if (logLevel == LogLevel::LOG_ERROR) mLogLevel = _T("ERROR");
    else if (logLevel == LogLevel::LOG_WARN) mLogLevel = _T("WARN");
    else if (logLevel == LogLevel::LOG_INFO) mLogLevel = _T("INFO");
    else mLogLevel = _T("INFO");
}

void Logger::Log(bool success, const tstring& source, const tstring& summary,
                 const tstring& message, LogLevel logLevel) {
    if (Instance == nullptr) {
        Instance = new Logger(success, source, summary, message, logLevel);
    }
}

void Logger::WinApiLog(bool success, const tstring& source, const tstring& summary, LogLevel logLevel) {
    tstring errorCode = std::format(_T("WINAPI error code: 0x{:x}"), GetLastError());
    Log(success, source, summary, errorCode, logLevel);
}
