#ifndef VECTORTEST_H
#define VECTORTEST_H

#pragma once

#include <vector>

using namespace std;

#include "BaseTest.hpp"

class VectorTest : public BaseTest {
public:
    VectorTest();

    ~VectorTest();

public:
    void test() override;

private:
    void showInfomation(const vector<int> &v);

    void findTest(vector<int> &v);
};

#endif