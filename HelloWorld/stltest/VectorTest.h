#ifndef VECTORTEST_H
#define VECTORTEST_H

#pragma once
#include <vector>
using namespace std;

#include "BaseTest.h"

class VectorTest: public BaseTest
{
public:
    VectorTest();
    ~VectorTest();

public:
    void Test() override;

private:
    void ShowInfomation(const vector<int> &v);

};

#endif