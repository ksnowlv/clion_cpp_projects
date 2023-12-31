#ifndef PROCESS_TEST_H
#define PROCESS_TEST_H


#include "BaseTest.h"


class ProcessTest: public BaseTest {

public:
    ProcessTest();
    ~ProcessTest();

public:
    void Test() override;

private:
    void ProcessCreate();
    void SignalTest();
    static void Ouch(const int sig);
    
    void AlarmTest();
    static void AlarmCallBack(const int sig);
    
    void SharedMemoryTest();

    void MessageQueueTest();

private:
    static int s_AlarmFired;

};

#endif /* PROCESS_TEST_H */
