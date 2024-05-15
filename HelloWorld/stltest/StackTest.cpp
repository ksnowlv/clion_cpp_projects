//
//  StackTest.cpp
//  STLTest
//
//  Created by ksnowlv on 2022/2/26.
//

#include "StackTest.hpp"
#include <stack>
#include <iostream>
#include "ConstDefine.h"

using namespace std;

StackTest::StackTest() {

}

StackTest::~StackTest() {

}

void StackTest::test() {

    LOG_INFO

    stack<int> s;

    for (int i = 0; i < 20; ++i) {
        s.push(i);
    }

    s.pop();
    s.emplace(10);

    stack<int> p(s);
    while (!p.empty()) {
        int v = p.top();
        p.pop();
        cout << v << endl;
    }

    shared_ptr<StackTest> newHead(std::make_shared<StackTest>());
    shared_ptr<StackTest> n = newHead;
    unique_ptr<StackTest> stack(std::make_unique<StackTest>());

    unique_ptr<StackTest> s1(std::make_unique<StackTest>());
}
