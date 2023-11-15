#include "pch.h"
#include "Logger.h"

Logger::Logger(bool success, const tstring& source, const tstring& summary, const tstring& message, LogLevel logLevel)
        : mSource(source), mSummary(summary), mMessage(message), mSuccess(success) {
    auto const currentLocalTime = std::chrono::current_zone()->to_local(std::chrono::system_clock::now());
    mTime = std::format(LogTimeFormat, currentLocalTime);
    
    mLogLevel = toString(logLevel);
}

tstring Logger::toString(const LogLevel& logLevel) {
    switch (logLevel) {
        case LogLevel::LOG_FATAL: return TEXT("FATAL");
        case LogLevel::LOG_ERROR: return TEXT("ERROR");
        case LogLevel::LOG_WARN:  return TEXT("WARN");
        case LogLevel::LOG_INFO:  return TEXT("INFO");
        default: return TEXT("INFO");
    }
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

void Logger::Log(Logger* logger, bool success, const tstring& source, const tstring& summary,
        const tstring& message, LogLevel logLevel) {
    if (logger != nullptr) delete logger;
    logger = new Logger(success, source, summary, message, logLevel);
}
