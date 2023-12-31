#ifndef MUTEXTEST_H
#define MUTEXTEST_H

#pragma once

#include <mutex>
using namespace std;

#include "BaseTest.h"

/*
std::mutex，最基本的 Mutex 类。
std::recursive_mutex，递归 Mutex 类。
std::time_mutex，限时 Mutex 类。
std::recursive_timed_mutex，限时递归 Mutex 类。
当然C++14和C++17各增加了一个：
std::shared_timed_mutex，限时读写锁（C++14）
std::shared_mutex，读写锁（C++17）
*/

class MutexTest: public BaseTest
{
public:
    MutexTest();
    ~MutexTest();

public:
    void Test() override;

private:
    void TestMutex();
    static void CalCount(MutexTest& t, const int threadid);

    void TestRecursiveMutex();
    void TestTimeMutex();
    static void TimeMutextTask(MutexTest& t, const int threadid);

    void TestTwoLock();
    void TestLockGuard();

private:

    mutex m_Lock;
    int m_Count;

    recursive_mutex m_RecursiveMutex;
    string m_Text;

    timed_mutex m_TimeMutex;
};

#endif