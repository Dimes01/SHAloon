#pragma once

#include <string>
#include <chrono>
#include <format>

enum class LogLevel {
    LOG_FATAL,
    LOG_ERROR,
    LOG_WARN,
    LOG_INFO
};

// YYYY-MM-DD hh:mm:ss
constexpr auto LogTimeFormat = "{:%Y-%m-%d %X}";

class Logger {
private:
    std::string mSource;
    std::string mSummary;
    std::string mMessage;
    std::string mTime;
    std::string mLogLevel;
    bool mSuccess;

    std::string toString(const LogLevel& logLevel);

public:
    Logger(bool success, const std::string& source, const std::string& summary, const std::string& message, LogLevel logLevel);

    std::string GetLogSource();
    std::string GetLogSummary();
    std::string GetLogMessage();
    std::string GetLogTime();
    std::string GetLogLevel();
    bool GetLogSuccess();

    static void Log(Logger* logger, bool success, const std::string& source, const std::string& summary, 
        const std::string& message, LogLevel logLevel);
};

