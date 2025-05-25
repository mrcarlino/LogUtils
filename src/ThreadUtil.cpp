#include "ThreadUtil.h"

#include <atomic>
#include <thread>

static std::atomic<int> globalThreadCounter{1}; // Shared across all threads
thread_local int threadId = 0; // Local to each thread

namespace ThreadUtil
{
    int getThreadId()
    {
        if (threadId == 0)
            threadId = globalThreadCounter++;
        
        return threadId;
    }
}
