#include "AtomicTest.h"

#include <atomic>
#include <thread>
#include <iostream>
#include <unistd.h>

//原子操作，可保证多线程下数据完全同步。
atomic_int64_t g_total(0);
//非原子操作，多线程下数据会出现不一致的情况
// int64_t g_total = 0;

atomic_flag g_flag_lock = ATOMIC_FLAG_INIT;

void AtomicTest::ThreadFunction(const string &name, const int num) {

    for (int i = 1; i <=num; ++i) {
        g_total += i;
    }
    cout<<"thread name:"<<name<<",g_total="<<g_total<<endl;
}

AtomicTest::~AtomicTest() {
    std::cout << "~AtomicTest" << std::endl;
}

void AtomicTest::TestAtomicInt64() {

    const int64_t num = 10000;  
    //atomic_int64_t g_total=150015000  
    thread t1(AtomicTest::ThreadFunction, "t1",num);
    thread t2(AtomicTest::ThreadFunction, "t2",num);
    thread t3(AtomicTest::ThreadFunction, "t3",num);

    t1.join();
    t2.join();
    t3.join();

    cout<<"g_total="<<g_total<<endl;
}

void AtomicTest::Test() {
    TestAtomicInt64();
    TestAtomicIntFlag();
}

void AtomicTest::SetAtomicFlag() {

    while (g_flag_lock.test_and_set(memory_order_acquire)) {
        cout<<"SetAtomicFlag"<<endl;
    }
    cout<<"func1 do somethings!"<<endl;
}

void AtomicTest::ClearAtomicFlag() {

    g_flag_lock.clear();
    cout<<"clearAtomicFlag "<<endl;
}
/*
有一个比较特殊的原子类型是 atomic_flag，因为 atomic_flag 与其他原子类型不同，
它是无锁（lock_free）的，即线程对其访问不需要加锁，而其他的原子类型不一定是无锁的。
因为atomic并不能保证类型T是无锁的，另外不同平台的处理器处理方式不同，
也不能保证必定无锁，所以其他的类型都会有 is_lock_free() 成员函数来判断是否是无锁的。
atomic_flag 只支持 test_and_set() 以及 clear() 两个成员函数，test_and_set()函数检查 std::atomic_flag 标志，
如果 std::atomic_flag 之前没有被设置过，则设置 std::atomic_flag 的标志；
如果之前 std::atomic_flag 已被设置，则返回 true，否则返回 false。
clear()函数清除 std::atomic_flag 标志使得下一次调用 std::atomic_flag::test_and_set()返回 false。
可以用 atomic_flag 的成员函数test_and_set() 和 clear() 来实现一个自旋锁（spin lock）：
*/
void AtomicTest::TestAtomicIntFlag() {

    g_flag_lock.test_and_set();
    thread t1(AtomicTest::SetAtomicFlag);
    usleep(2);
    thread t2(AtomicTest::ClearAtomicFlag);
    
    t1.join();
    t2.join();
}