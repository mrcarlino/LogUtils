#pragma once

namespace LogUtils
{
    inline constexpr const char* COLOR_RESET = "\033[0m";   // RESET
    inline constexpr const char* COLOR_DEBUG = "\033[90m";  // DARK_GRAY
    inline constexpr const char* COLOR_INFO  = "\033[32m";  // GREEN
    inline constexpr const char* COLOR_WARN  = "\033[33m";  // YELLOW or ORANGE
    inline constexpr const char* COLOR_ERROR = "\033[31m";  // RED
    inline constexpr const char* COLOR_FATAL = "\033[101m"; // BACKGROUND RED
}
