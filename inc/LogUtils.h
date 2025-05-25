#pragma once

// STL includes
#include <string>
#include <sstream>

enum class LogLevel
{
    DEBUG = 0,
    INFO,
    WARNING,
    ERROR,
    FATAL
};

namespace LogUtils
{
    void setLogLevel(LogLevel level);
    void log(LogLevel level, const std::string& msg);
}