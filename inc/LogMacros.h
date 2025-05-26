#pragma once

#include "LogStream.h"

#define LOGD LogUtils::LogStream(LogLevel::DEBUG)
#define LOGI LogUtils::LogStream(LogLevel::INFO)
#define LOGW LogUtils::LogStream(LogLevel::WARNING)
#define LOGE LogUtils::LogStream(LogLevel::ERROR)
#define LOGF LogUtils::LogStream(LogLevel::FATAL)
