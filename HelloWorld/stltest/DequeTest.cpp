//
//  DequeTest.cpp
//  STLTest
//
//  Created by ksnowlv on 2022/2/25.
//

#include "DequeTest.hpp"
#include <iostream>
#include <deque>
#include "ConstDefine.h"

using namespace std;

void printQueue(const deque<int> &que) {

    for (::deque<int>::const_iterator it = que.begin(); it != que.end(); ++it) {
        cout << *it << ",";
    }

    cout << endl;
}

DequeueTest::DequeueTest() {

}

DequeueTest::~DequeueTest() {

}

void DequeueTest::test() {
    LOG_INFO

    deque<int> que;


    //末尾添加10个元素
    for (int i = 0; i < 10; ++i) {
        que.emplace_back(i);
    }

    printQueue(que);

    //队头添加10个元素
    for (int i = 0; i < 10; ++i) {
        que.emplace_front(i + 10);
    }

    printQueue(que);

    int v = que.front();
    que.pop_front();
    cout << "删除队头元素" << v << "此时的队头元素为" << que.front() << endl;

    v = que.back();
    que.pop_back();

    cout << "删除队尾元素" << v << "此时的队尾元素为" << que.back() << endl;

    printQueue(que);

    std::deque<int>::const_iterator it = que.begin();
    que.emplace(it + 2, 88);
    cout << "第二个位置添加88后" << endl;
    printQueue(que);

    it = que.begin();
    que.insert(it + 2, 99);
    cout << "第二个位置添加99后" << endl;
    printQueue(que);

    it = que.begin();
    que.erase(it + 2, it + 10);
    printQueue(que);

    for (::deque<int>::reverse_iterator it = que.rbegin(); it != que.rend(); ++it) {
        cout << *it << ",";
    }
    cout << endl;

}
