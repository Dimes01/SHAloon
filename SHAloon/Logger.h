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

    bool anyLogWritten = false;
    std::filesystem::path logsFilePath;

    static inline std::filesystem::path settingsPath{ "settings/ShaloonSettings.conf" };
    static inline std::filesystem::path logsFolderPath{ _T("logs/") };
    static inline LogLevel minimalLogLevel = LogLevel::LOG_INFO;

    void setLogTime();
    void setLogLevel(LogLevel logLevel);
    void setLogsFilePath();

    static void readFromSettings();
    static void writeToSettings();
    void writeToJson();

    static LogLevel fromString(const tstring& logLevel);
    static tstring fromLogLevel(LogLevel logLevel);

public:
    static inline Logger* Instance = nullptr;

    Logger(bool success, const tstring& source, const tstring& summary,
        const tstring& message, LogLevel logLevel);
    ~Logger();

    tstring GetLogSource();
    tstring GetLogSummary();
    tstring GetLogMessage();
    tstring GetLogTime();
    tstring GetLogLevel();
    bool GetLogSuccess();

    static void Init();
    static void Dispose();

    static void Log(bool success, const tstring& source, const tstring& summary,
        const tstring& message, LogLevel logLevel);

    // message �������� �� GetLastError()
    static void WinApiLog(bool success, const tstring& source, const tstring& summary, LogLevel logLevel);

    static void SetMinimalLogLevel(const tstring& logLevel);
};
