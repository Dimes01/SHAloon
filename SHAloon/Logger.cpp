#include "pch.h"
#include "Logger.h"

Logger::Logger(bool success, const std::string& summary, const std::string& message, LogLevel logLevel) 
    : mSummary(summary), mMessage(message), mSuccess(success) {
    auto const currentLocalTime = std::chrono::current_zone()->to_local(std::chrono::system_clock::now());
    mTime = std::format(LogTimeFormat, currentLocalTime);
    mLogLevel = toString(logLevel);
}

std::string Logger::toString(const LogLevel& logLevel) {
    switch (logLevel) {
        case LogLevel::LOG_FATAL: return "FATAL";
        case LogLevel::LOG_ERROR: return "ERROR";
        case LogLevel::LOG_WARN:  return "WARN";
        case LogLevel::LOG_INFO:  return "INFO";
        default: return "INFO";
    }
}

std::string Logger::GetLogSummary() {
    return mSummary;
}

std::string Logger::GetLogMessage() {
    return mMessage;
}

std::string Logger::GetLogTime() {
    return mTime;
}

std::string Logger::GetLogLevel() {
    return mLogLevel;
}

bool Logger::GetLogSuccess() {
    return mSuccess;
}

void Logger::Log(Logger* logger, bool success, const std::string& summary, const std::string& message, LogLevel logLevel) {
    if (logger != nullptr) delete logger;
    logger = new Logger(success, summary, message, logLevel);
}
