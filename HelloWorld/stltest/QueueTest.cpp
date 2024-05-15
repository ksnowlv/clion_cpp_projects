//
//  QueueTest.cpp
//  STLTest
//
//  Created by ksnowlv on 2022/2/25.
//

#include "QueueTest.hpp"
#include <iostream>
#include <queue>
#include "ConstDefine.h"

using namespace std;


QueueTest::QueueTest() {

}

QueueTest::~QueueTest() {

}

void QueueTest::test() {
    LOG_INFO

    queue<int> q;

    for (int i = 0; i < 20; ++i) {
        q.push(i);
    }

    //在末尾添加新元素
    q.emplace(33);

    int v = q.back();
    q.pop();
    q.back();

    cout << "在末尾添加新元素" << v << endl;
}
