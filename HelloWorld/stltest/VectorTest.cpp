#include "VectorTest.h"
#include <iostream>

VectorTest::VectorTest() {

}

VectorTest::~VectorTest() {

}

void VectorTest::Test() {
    cout<<"------"<<__func__<<"------"<<endl;
    constexpr int VectorSize = 20;
    vector<int> v;

    for (int i = 0; i < VectorSize; ++i) {
        v.emplace_back(i);
    }
    cout<<"顺序遍历"<<endl;
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout<<*it<<",";
    }
    cout<<endl;

    cout<<"反序遍历"<<endl;
    for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it) {
        cout<<*it<<",";
    }
    cout<<endl;

    cout<<"删除3 或 5之间"<<endl;

    for (auto it = v.begin(); it != v.end();) {
        if (*it == 3 || *it == 5) {
            v.erase(it);
        } else
        {
            ++it;
        }
    }

    ShowInfomation(v);
    cout<<"删除5或 11位置之间"<<endl;
    vector<int>::iterator it = v.begin();
    v.erase(it + 5, it + 11);
    ShowInfomation(v);
}

void VectorTest::ShowInfomation(const vector<int> &v) {

    for (auto item : v) {
        cout<<item<<","<<endl;
    }
    cout<<endl;
}