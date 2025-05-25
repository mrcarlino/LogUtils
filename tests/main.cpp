#include <iostream>

#include "LogUtils.h"
#include "LogMacros.h"

#include <thread>

using std::string;

void testThread(const string& msg)
{
    LOGI << msg;
}

int main()
{
    LogUtils::setLogLevel(LogLevel::DEBUG);

    // Integer
    int x = 11;
    LOGD << "Debug value: " << x;
    LOGI << "Info value: " << x;
    LOGW << "Warning value: " << x;
    LOGE << "Error value: " << x;
    LOGF << "Fatal value: " << x;

    // Float
    float f = 22.2;
    LOGD << "Debug value: " << f;
    LOGI << "Info value: " << f;
    LOGW << "Warning value: " << f;
    LOGE << "Error value: " << f;
    LOGF << "Fatal value: " << f;

    // Double
    double d = 33.3;
    LOGD << "Debug value: " << d;
    LOGI << "Info value: " << d;
    LOGW << "Warning value: " << d;
    LOGE << "Error value: " << d;
    LOGF << "Fatal value: " << d;

    // Bool
    bool b = true;
    LOGD << "Debug value: " << b;
    LOGI << "Info value: " << b;
    LOGW << "Warning value: " << b;
    LOGE << "Error value: " << b;
    LOGF << "Fatal value: " << b;

    // String
    string str = "Test string";
    LOGD << "Debug value: " << str;
    LOGI << "Info value: " << str;
    LOGW << "Warning value: " << str;
    LOGE << "Error value: " << str;
    LOGF << "Fatal value: " << str;

    // Thread
    std::thread t1(testThread, "Test thread");
    std::thread t2(testThread, "Test thread");
    testThread("Thread: Main");
    t1.join();
    t2.join();

    return 0;
}
