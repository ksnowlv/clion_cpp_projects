#ifndef FUTURETEST_H
#define FUTURETEST_H

#pragma once

#include <string>

using namespace std;

#include "BaseTest.hpp"


class FutureTest : public BaseTest {
public:
    FutureTest();

    ~FutureTest();

public:
    void test() override;

private:
    static int processBigDataTest(const int number1, const int number2);

    void showMyInfomation(const string &s);

    void testAsync();

    void testPackagedTask();

    void testPromise();

};

#endif