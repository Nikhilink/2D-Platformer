#pragma once

#include "pch.h"

class Logger
{
    public:
        Logger();
        Logger(std::string clientName);

        enum LogLevel
        {
            INFO,
            WARNING,
            ERROR,
            DEBUG
        };

        void SetLogFilePath(const std::string& path);
        void EnableConsoleLogging(bool enable);

        void Log(LogLevel level, const char* format, ...);

        void InfoLog(const char* format, ...);
        void WarningLog(const char* format, ...);
        void ErrorLog(const char* format, ...);
        void DebugLog(const char* format, ...);

        inline void RectangleInfoLog(Rectangle& rect);

        private:
            std::string m_ClientName;
            std::string m_LogFilePath;
            bool m_ConsoleLoggingEnabled = true;

            std::string FormatMessageV(LogLevel level, const char* format, va_list args);
};
