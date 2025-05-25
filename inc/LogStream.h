#pragma once

#include "LogUtils.h"
#include <sstream>

class LogStream
{
public:
    explicit LogStream(LogLevel level);
    ~LogStream();

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