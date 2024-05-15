#include "VectorTest.h"
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>

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

    findTest(v);

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

    vector<char*> stringList;

    for (int i = 0; i < 10; ++i) {
        char *pName = new char [100];
        memset(pName, 0, 100 * sizeof (char));
        strcpy(pName, "hello");
    }

    while (!stringList.empty()) {
        char* p = stringList.back();
        stringList.pop_back();
        delete[] p;
    }
}

void VectorTest::findTest(vector<int> &v) {

//    find
    auto it = std::find(v.begin(), v.end(), 3);

    if (it != v.end()) {
        std::cout<<"find "<<*it<< " at " <<std::distance(v.begin(), it)<<std::endl;
    } else {
        std::cout<<"not find"<<std::endl;
    }

    it = std::find_if(v.begin(), v.end(), [](int x) {
        return x > 10;
    });

    if (it != v.end()) {
        std::cout<<"找到了第一个大于10的元素"<<*it<< " at " <<std::distance(v.begin(), it)<<std::endl;
    } else {
        std::cout<<"没有找到大于10的元素"<<endl;
    }

    //确保向量是有序的
    std::sort(v.begin(), v.end());
    int value = 6;
    bool foundFlag = std::binary_search(v.begin(), v.end(), value);
    if(foundFlag) {
        std::cout<<value<<"已经找到"<<std::endl;
    } else {
        std::cout<<value<<"未找到"<<std::endl;
    }

    auto lower= std::lower_bound(v.begin(), v.end(), value);
    auto upper = std::upper_bound(v.begin(), v.end(), value);
    std::cout << "第一个不小于 " << value << " 的元素在位置 " << std::distance(v.begin(), lower) << std::endl;
    std::cout << "第一个大于 " << value << " 的元素在位置 " << std::distance(v.begin(), upper) << std::endl;

    std::vector<int> vec = {1,2,2,4,5};

    // 使用 std::lower_bound 查找第一个不小于给定值的元素位置
    it = std::lower_bound(vec.begin(),vec.end(),3);
    std::cout << "Lower bound at position:" << it - vec.begin() << std::endl;

    // 使用 std::upper_bound 查找第一个大于给定值的元素位置
    it = std::upper_bound(vec.begin(),vec.end(),2);

    std::cout << "Upper bound at position:" << it - vec.begin() << std::endl;
}

void VectorTest::ShowInfomation(const vector<int> &v) {

    for (auto item : v) {
        cout<<item<<","<<endl;
    }
    cout<<endl;
}
