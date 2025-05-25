#pragma once

#include "LogStream.h"

#define LOGD LogStream(LogLevel::DEBUG)
#define LOGI LogStream(LogLevel::INFO)
#define LOGW LogStream(LogLevel::WARNING)
#define LOGE LogStream(LogLevel::ERROR)
#define LOGF LogStream(LogLevel::FATAL)