#pragma once

#include <ostream>
#include <mutex>
#include "LogLevel.h"
#include "LogInternals.h"

namespace LogUtils
{
    class LogStream
    {
    public:
        explicit LogStream(LogLevel level) :
            mLevel(level) {}

        ~LogStream()
        {
            if (mLevel < getSeverityLevel())
                return;

            static std::mutex logMutex;
            std::lock_guard<std::mutex> lock(logMutex);
            std::cout << getColor(mLevel)
                    << getTimestamp() << " "
                    << "[TID " << getThreadId() << "] "
                    << "[" << getLabel(mLevel) << "] "
                    << mBuffer.str()
                    << "\033[0m" << std::endl; // RESET
        }

        template <typename T>
        LogStream& operator<<(const T& value)
        {
            mBuffer << value;
            return *this;
        }

    private:
        LogLevel mLevel;
        std::ostringstream mBuffer;
    };
}
