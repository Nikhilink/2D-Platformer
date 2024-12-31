#include "log_utils.h"

Logger::Logger()
{
    m_ClientName = "System";
}

Logger::Logger(std::string clientName): m_ClientName(clientName)
{

}

void Logger::SetLogFilePath(const std::string& path)
{
    m_LogFilePath = path;
}

void Logger::EnableConsoleLogging(bool enable)
{
    m_ConsoleLoggingEnabled = enable;
}

void Logger::Log(LogLevel level, const char* format, ...)
{
    va_list args;
    va_start(args, format);

    std::string formatted_message = FormatMessageV(level, format, args);

    va_end(args);

    if(m_ConsoleLoggingEnabled)
    {
        switch (level)

        {
            case INFO: TraceLog(LOG_INFO, formatted_message.c_str()); break;
            case WARNING: TraceLog(LOG_WARNING, formatted_message.c_str()); break;
            case ERROR: TraceLog(LOG_ERROR, formatted_message.c_str()); break;
            case DEBUG: TraceLog(LOG_DEBUG, formatted_message.c_str()); break;
        }
    }

    if(!m_LogFilePath.empty())
    {
        std::ofstream logFile(m_LogFilePath, std::ios::app);

        if(logFile.is_open())
        {
            logFile << formatted_message << std::endl;
            logFile.close();
        }
        else
        {
            TraceLog(LOG_WARNING, "Could not open log file: %s", m_LogFilePath.c_str());
        }
    }
}

std::string Logger::FormatMessageV(LogLevel level, const char* format, va_list args)
{
    std::stringstream ss;

    ss << "[" + m_ClientName + "] ";

    char buffer[512];
    vsnprintf(buffer, sizeof(buffer), format, args);

    ss << buffer;

    return ss.str();
}

inline void Logger::RectangleInfoLog(Rectangle& rect)
{
    TraceLog(LOG_INFO, TextFormat("%f %f %f %f", rect.x, rect.y, rect.width, rect.height));
}

void Logger::InfoLog(const char* format, ...)
{
    va_list args;
    va_start(args, format);

    std::string formatted_message = FormatMessageV(INFO, format, args);

    va_end(args);

    if(m_ConsoleLoggingEnabled)
    {
        TraceLog(LOG_INFO, formatted_message.c_str());
    }

    if(!m_LogFilePath.empty())
    {
        std::ofstream logFile(m_LogFilePath, std::ios::app);

        if(logFile.is_open())
        {
            logFile << formatted_message << std::endl;
            logFile.close();
        }
        else
        {
            TraceLog(LOG_WARNING, "Could not open log file: %s", m_LogFilePath.c_str());
        }
    }
}
void Logger::WarningLog(const char* format, ...)
{
    va_list args;
    va_start(args, format);

    std::string formatted_message = FormatMessageV(WARNING, format, args);

    va_end(args);

    if(m_ConsoleLoggingEnabled)
    {
        TraceLog(LOG_WARNING, formatted_message.c_str());
    }

    if(!m_LogFilePath.empty())
    {
        std::ofstream logFile(m_LogFilePath, std::ios::app);

        if(logFile.is_open())
        {
            logFile << formatted_message << std::endl;
            logFile.close();
        }
        else
        {
            TraceLog(LOG_WARNING, "Could not open log file: %s", m_LogFilePath.c_str());
        }
    }
}
void Logger::ErrorLog(const char* format, ...)
{
    va_list args;
    va_start(args, format);

    std::string formatted_message = FormatMessageV(ERROR, format, args);

    va_end(args);

    if(m_ConsoleLoggingEnabled)
    {
        TraceLog(LOG_ERROR, formatted_message.c_str());
    }

    if(!m_LogFilePath.empty())
    {
        std::ofstream logFile(m_LogFilePath, std::ios::app);

        if(logFile.is_open())
        {
            logFile << formatted_message << std::endl;
            logFile.close();
        }
        else
        {
            TraceLog(LOG_WARNING, "Could not open log file: %s", m_LogFilePath.c_str());
        }
    }
}
void Logger::DebugLog(const char* format, ...)
{
    va_list args;
    va_start(args, format);

    std::string formatted_message = FormatMessageV(DEBUG, format, args);

    va_end(args);

    if(m_ConsoleLoggingEnabled)
    {
        TraceLog(LOG_DEBUG, formatted_message.c_str());
    }

    if(!m_LogFilePath.empty())
    {
        std::ofstream logFile(m_LogFilePath, std::ios::app);

        if(logFile.is_open())
        {
            logFile << formatted_message << std::endl;
            logFile.close();
        }
        else
        {
            TraceLog(LOG_WARNING, "Could not open log file: %s", m_LogFilePath.c_str());
        }
    }
}