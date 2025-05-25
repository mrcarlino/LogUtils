#include "LogUtils.h"

#include "ThreadUtil.h"

#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <mutex>

using std::string;
using namespace ThreadUtil;

namespace
{
    LogLevel currentLevel = LogLevel::DEBUG;
    std::mutex logMutex;

    string getTimestamp()
    {
        auto now = std::chrono::system_clock::now();
        auto time_t = std::chrono::system_clock::to_time_t(now);
        std::tm tm;

        #ifdef _WIN32
            localtime_s(&tm, &time_t);
        #else
            localtime_r(&time_t, &tm);
        #endif
            std::ostringstream oss;
            oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
            return oss.str();
    }

    const char* getColor(LogLevel level)
    {
        switch (level)
        {
            case LogLevel::DEBUG:    return "\033[90m"; // DARK_GRAY
            case LogLevel::INFO:     return "\033[32m"; // GREEN
            case LogLevel::WARNING:  return "\033[33m"; // YELLOW or ORANGE
            case LogLevel::ERROR:    return "\033[31m"; // RED
            case LogLevel::FATAL:    return "\033[101m"; // WHITE, BACKGROUND RED
            default:                 return "";
        }
    }

    const char* getLabel(LogLevel level)
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
}

namespace LogUtils
{
    void setLogLevel(LogLevel level)
    {
        currentLevel = level;
    }

    void log(LogLevel level, const string& msg)
    {
        if (level < currentLevel)
            return;

        std::lock_guard<std::mutex> lock(logMutex);
        std::cout << getColor(level)
                  << getTimestamp() << " "
                  << "[" << getThreadId() << "] "
                  << "[" << getLabel(level) << "] "
                  << msg
                  << "\033[0m" << std::endl; // RESET
    }
}
