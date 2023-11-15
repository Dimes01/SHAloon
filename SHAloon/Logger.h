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

public:
    static Logger* Instance;
    
    Logger();

    tstring GetLogSource();
    void SetLogSource(const tstring& source);

    tstring GetLogSummary();
    void SetLogSummary(const tstring& summary);

    tstring GetLogMessage();
    void SetLogMessage(const tstring& message);

    tstring GetLogTime();
    void SetLogTime();

    tstring GetLogLevel();
    void SetLogLevel(LogLevel logLevel);

    bool GetLogSuccess();
    void SetLogSuccess(bool success);

    static void Log(bool success, const tstring& source, const tstring& summary, 
        const tstring& message, LogLevel logLevel);
};
