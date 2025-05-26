#pragma once

#include <chrono>
#include <iomanip>
#include <mutex>
#include <sstream>
#include <thread>
#include <atomic>

namespace LogUtils
{
    inline std::atomic<int> globalThreadCounter{1}; // Shared across all threads
    inline std::mutex logMutex;
    
    inline std::string getTimestamp()
    {
        using namespace std::chrono;
        auto now = system_clock::now();
        auto time_t = system_clock::to_time_t(now);
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

    inline int getThreadId()
    {
        // Evaluated only once per thread
        thread_local int threadId = [] {
            return globalThreadCounter++;
        }();

        return threadId;
    }
}
