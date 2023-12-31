#ifndef FUTURETEST_H
#define FUTURETEST_H

#pragma once

#include <string>
using namespace std;

#include "BaseTest.h"


class FutureTest: public BaseTest
{
public:
    FutureTest();
    ~FutureTest();

public:
    void Test() override;

private:
    static int ProcessBigDataTest(const int number1, const int number2);
    void ShowMyInfomation(const string& s);
    void TestAsync();
    void TestPackagedTask();
    void TestPromise();

};

#endif