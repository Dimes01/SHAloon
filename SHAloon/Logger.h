#pragma once

enum class LogLevel {
    LOG_FATAL,
    LOG_ERROR,
    LOG_WARN,
    LOG_INFO
};

class Logger {
private:

    // YYYY-MM-DD hh:mm:ss
    constexpr static auto LogTimeFormat = _T("{:%Y-%m-%d %X}");

    tstring mSource;
    tstring mSummary;
    tstring mMessage;
    tstring mTime;
    tstring mLogLevel;
    bool mSuccess;

    void setLogTime();
    void setLogLevel(LogLevel logLevel);

public:
    static inline Logger* Instance = nullptr;

    Logger(bool success, const tstring& source, const tstring& summary,
        const tstring& message, LogLevel logLevel);

    tstring GetLogSource();
    tstring GetLogSummary();
    tstring GetLogMessage();
    tstring GetLogTime();
    tstring GetLogLevel();
    bool GetLogSuccess();

    static void Log(bool success, const tstring& source, const tstring& summary, 
        const tstring& message, LogLevel logLevel);

    // message достаётся из GetLastError()
    static void WinApiLog(bool success, const tstring& source, const tstring& summary, LogLevel logLevel);
};
