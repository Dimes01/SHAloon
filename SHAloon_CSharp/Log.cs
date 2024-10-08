﻿namespace SHAloon_CSharp;

public class Log {
    public bool Success { get; set; }
    public string Source { get; set; } = string.Empty;
    public string Summary { get; set; } = string.Empty;
    public string Message { get; set; } = string.Empty;
    public string Time { get; set; } = string.Empty;
    public string LogLevel { get; set; } = string.Empty;

    public static Log GetLastLog() {
        return new Log() {
            Success = ImportsDLL.GetLogSuccess(),
            Source = ImportsDLL.GetLogSource(),
            Summary = ImportsDLL.GetLogSummary(),
            Message = ImportsDLL.GetLogMessage(),
            Time = ImportsDLL.GetLogTime(),
            LogLevel = ImportsDLL.GetLogLevel()
        };
    }

    public static void SetMinimalLogLevel(string logLevel) {
        ImportsDLL.SetMinimalLogLevel(logLevel);
    }

    public static void DeleteAllLogs() {
        ImportsDLL.DeleteAllLogs();
    }
}

