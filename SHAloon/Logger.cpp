#include "pch.h"
#include "Logger.h"

Logger::Logger(bool success, const tstring& source, const tstring& summary,
               const tstring& message, LogLevel logLevel)
    : mSuccess(success), mSource(source), mSummary(summary), mMessage(message) {
    setLogTime();
    setLogLevel(logLevel);
    setLogsFilePath();
}

Logger::~Logger() {
    if (anyLogWritten) {
        tofstream output(logsFilePath, std::ios::app);
        output << _T("}");
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

void Logger::Init() {
    namespace fs = std::filesystem;

    readFromSettings();

    if (fs::exists(logsFolderPath) == false) {
        fs::create_directory(logsFolderPath);
    }

    auto settingsParent = settingsPath.parent_path();
    if (fs::exists(settingsParent) == false) {
        fs::create_directory(settingsParent);
    }
}

void Logger::Dispose() {
    if (Instance != nullptr) delete Instance;
}

void Logger::setLogTime() {
    auto const currentLocalTime = std::chrono::current_zone()->to_local(std::chrono::system_clock::now());
    mTime = std::format(LogTimeFormat, currentLocalTime);
}

void Logger::setLogLevel(LogLevel logLevel) {
    mLogLevel = fromLogLevel(logLevel);
}

void Logger::setLogsFilePath() {
    tstring time{ mTime };
    std::replace(time.begin(), time.end(), _T(':'), _T('-'));
    tstring name = _T("ShaloonLogs-") + time + _T(".json");
    logsFilePath = logsFolderPath / name;
}

void Logger::readFromSettings() {
    tifstream input(settingsPath);
    if (input.is_open() == false) return;

    tstring data;
    while (input >> data) {
        if (data == _T("LogLevel")) {
            input >> data >> data;
            minimalLogLevel = fromString(data);
        }
    }
}

void Logger::writeToSettings() {
    tofstream output(settingsPath);
    output << _T("LogLevel : ") << fromLogLevel(minimalLogLevel);
}

void Logger::writeToJson() {
    namespace fs = std::filesystem;

    auto json_key_value = [](const tstring& key, const tstring& value) {
        tstring quotes = _T("\"");
        return quotes + key + quotes + _T(":") + quotes + value + quotes + _T(",");
    };

    tstring success = json_key_value(_T("Success"), mSuccess ? _T("True") : _T("False"));
    tstring logLevel = json_key_value(_T("Log Level"), mLogLevel);
    tstring source = json_key_value(_T("Source"), mSource);
    tstring summary = json_key_value(_T("Summary"), mSummary);
    tstring message = json_key_value(_T("Message"), mMessage);
    tstring time = json_key_value(_T("Time"), mTime);
    time.pop_back();

    tofstream output(logsFilePath, std::ios::app);

#ifdef UNICODE
    output.imbue(std::locale(".UTF-8"));
#endif // UNICODE

    if (anyLogWritten == false) {
        output << _T("{");
    } else {
        output << _T(",");
    }

    output << _T("\"Log\":{") << success << logLevel << source << summary << message << time << _T("}");
    anyLogWritten = true;
}

LogLevel Logger::fromString(const tstring& logLevel) {
    if (logLevel == _T("FATAL")) return LogLevel::LOG_FATAL;
    else if (logLevel == _T("ERROR")) return LogLevel::LOG_ERROR;
    else if (logLevel == _T("WARN")) return LogLevel::LOG_WARN;
    else if (logLevel == _T("INFO")) return LogLevel::LOG_INFO;
    return LogLevel::LOG_INFO;
}

tstring Logger::fromLogLevel(LogLevel logLevel) {
    if (logLevel == LogLevel::LOG_FATAL) return _T("FATAL");
    else if (logLevel == LogLevel::LOG_ERROR) return _T("ERROR");
    else if (logLevel == LogLevel::LOG_WARN) return _T("WARN");
    else if (logLevel == LogLevel::LOG_INFO) return _T("INFO");
    return _T("INFO");
}

void Logger::Log(bool success, const tstring& source, const tstring& summary,
                 const tstring& message, LogLevel logLevel) {
    if (Instance == nullptr) {
        Instance = new Logger(success, source, summary, message, logLevel);
    } else {
        Instance->mSuccess = success;
        Instance->mSource = source;
        Instance->mSummary = summary;
        Instance->mMessage = message;
        Instance->setLogLevel(logLevel);
        Instance->setLogTime();
    }
    if (logLevel <= minimalLogLevel) {
        Instance->writeToJson();
    }
}

void Logger::WinApiLog(bool success, const tstring& source, const tstring& summary, LogLevel logLevel) {
    tstring errorMessage = std::format(_T("WINAPI error code: 0x{:x}"), GetLastError());
    Log(success, source, summary, errorMessage, logLevel);
}

void Logger::SetMinimalLogLevel(const tstring& logLevel) {
    minimalLogLevel = fromString(logLevel);
    writeToSettings();
}
