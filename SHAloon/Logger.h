#pragma once

enum class LogLevel {
    LOG_FATAL,
    LOG_ERROR,
    LOG_WARN,
    LOG_INFO
};

// YYYY-MM-DD hh:mm:ss
constexpr auto LogTimeFormat = TEXT("{:%Y-%m-%d %X}");

class Logger {
private:
    tstring mSource;
    tstring mSummary;
    tstring mMessage;
    tstring mTime;
    tstring mLogLevel;
    bool mSuccess;

    tstring toString(const LogLevel& logLevel);

public:
    Logger(bool success, const tstring& source, const tstring& summary, const tstring& message, LogLevel logLevel);

    tstring GetLogSource();
    tstring GetLogSummary();
    tstring GetLogMessage();
    tstring GetLogTime();
    tstring GetLogLevel();
    bool GetLogSuccess();

    static void Log(Logger* logger, bool success, const tstring& source, const tstring& summary, 
        const tstring& message, LogLevel logLevel);
};

