#pragma once

#include "ColorCodes.h"

namespace LogUtils
{
    enum class LogLevel
    {
        DEBUG = 0,
        INFO,
        WARNING,
        ERROR,
        FATAL
    };

    inline LogLevel severityLevel = LogLevel::DEBUG;

    inline void setSeverityLevel(LogLevel level)
    {
        severityLevel = level;
    }

    inline LogLevel& getSeverityLevel()
    {
        return severityLevel;
    }

    inline const char* getLabel(LogLevel level)
    {
        switch(level)
        {
            case LogLevel::DEBUG:    return "DEBUG";
            case LogLevel::INFO:     return "INFO";
            case LogLevel::WARNING:  return "WARNING";
            case LogLevel::ERROR:    return "ERROR";
            case LogLevel::FATAL:    return "FATAL";
            default:                 return "UNKNOWN";
        }
    }

    inline const char* getColor(LogLevel level)
    {
        switch (level)
        {
            case LogLevel::DEBUG:    return LogUtils::COLOR_DEBUG; // DARK_GRAY
            case LogLevel::INFO:     return LogUtils::COLOR_INFO;  // GREEN
            case LogLevel::WARNING:  return LogUtils::COLOR_WARN;  // YELLOW or ORANGE
            case LogLevel::ERROR:    return LogUtils::COLOR_ERROR; // RED
            case LogLevel::FATAL:    return LogUtils::COLOR_FATAL; // BACKGROUND RED
            default:                 return LogUtils::COLOR_RESET;
        }
    }
}
