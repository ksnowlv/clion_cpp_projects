#ifndef PROCESS_TEST_H
#define PROCESS_TEST_H


#include "BaseTest.hpp"


class ProcessTest : public BaseTest {

public:
    ProcessTest();

    ~ProcessTest();

public:
    void test() override;

private:
    void processCreate();

    void signalTest();

    static void ouch(const int sig);

    void alarmTest();

    static void alarmCallBack(const int sig);

    void sharedMemoryTest();

    void messageQueueTest();

private:
    static int s_AlarmFired;

};

#endif /* PROCESS_TEST_H */
