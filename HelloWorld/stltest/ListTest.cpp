//
//  ListTest.cpp
//  STLTest
//
//  Created by ksnowlv on 2022/2/25.
//

#include "ListTest.hpp"
#include <iostream>
#include <list>
#include <algorithm>
#include "ConstDefine.h"

using namespace std;

void printList(const list<int> &l) {

    for (::list<int>::const_iterator it = l.begin(); it != l.end(); ++it) {
        cout << *it << ",";
    }
    cout << endl;
}

bool mycomp(int i, int j) {
    return (i < j);
}

ListTest::ListTest() {

}

ListTest::~ListTest() {

}

void ListTest::test() {
    LOG_INFO
    list<int> l;
    list<int> *pList = new list<int>();
    delete pList;

    //依次加入0到9
    for (int i = 0; i < 10; ++i) {
        l.push_back(i);
    }

    printList(l);

    //在列表头部依次加入0到9
    for (int i = 0; i < 10; ++i) {
        l.push_front(i);
    }

    printList(l);

    //在列表末尾加入100
    l.emplace_back(100);

    //在列表头部加入101
    l.emplace_back(101);


    //升序排列后
    cout << "升序排列后" << endl;
    //l.sort(mycomp);
    l.sort([](const int &a1, const int &a2) { return a1 > a2; });
    printList(l);

    cout << "反序后" << endl;
    l.reverse();
    printList(l);

    cout << "合并后" << endl;
    list<int> l2 = {1000, 1001, 10003};
    l.merge(l2);
    printList(l);

    cout << "排序后" << endl;
    l.sort([&](const int &a, const int &b) -> bool { return a < b; });
    printList(l);


    cout << "去重后" << endl;
    l.unique();
    printList(l);
}

