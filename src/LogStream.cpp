#include "LogStream.h"

LogStream::LogStream(LogLevel level) :
    mLevel(level) {}

LogStream::~LogStream()
{
    LogUtils::log(mLevel, mBuffer.str()); // Log on destruction
}
