#include <iostream>

#include "LogUtils.h"

#include <thread>

using std::string;
using namespace LogUtils;

void testThread(const string& msg)
{
    LOGI << msg;
}

int main()
{
    LogUtils::setSeverityLevel(LogLevel::DEBUG);

    // Integer
    int x = 11;
    LOGD << "int: " << x;
    LOGI << "int: " << x;
    LOGW << "int: " << x;
    LOGE << "int: " << x;
    LOGF << "int: " << x;

    // Float
    float f = 22.2;
    LOGD << "float: " << f;
    LOGI << "float: " << f;
    LOGW << "float: " << f;
    LOGE << "float: " << f;
    LOGF << "float: " << f;

    // Double
    double d = 33.3;
    LOGD << "double: " << d;
    LOGI << "double: " << d;
    LOGW << "double: " << d;
    LOGE << "double: " << d;
    LOGF << "double: " << d;

    // Bool
    bool b = true;
    LOGD << "bool: " << b;
    LOGI << "bool: " << b;
    LOGW << "bool: " << b;
    LOGE << "bool: " << b;
    LOGF << "bool: " << b;

    // String
    string str = "Test string";
    LOGD << "string: " << str;
    LOGI << "string: " << str;
    LOGW << "string: " << str;
    LOGE << "string: " << str;
    LOGF << "string: " << str;

    // Thread
    std::thread t1(testThread, "Test thread");
    std::thread t2(testThread, "Test thread");
    testThread("Thread: Main");
    t1.join();
    t2.join();

    return 0;
}
