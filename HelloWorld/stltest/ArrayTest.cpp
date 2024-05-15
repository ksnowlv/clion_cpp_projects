//
//  ArrayTest.cpp
//  STLTest
//
//  Created by ksnowlv on 2022/3/1.
//

#include "ArrayTest.hpp"

#include <array>
#include <forward_list>
#include <unordered_map>
#include <map>
#include <iostream>
#include "ConstDefine.h"

using namespace std;

auto get_student(const int id) {
    switch (id) {
        case 0:
            return ::make_tuple(3.8, 'A', "张三");
            break;
        case 1:
            return ::make_tuple(4.8, 'C', "李四");
            break;
        case 2:
            return ::make_tuple(1.8, 'D', "王五");
        default:
            break;
    }

    return ::make_tuple(0.0, 'D', "null");
}


ArrayTest::~ArrayTest() {

}

void ArrayTest::test() {
    LOG_INFO

    std::array<int, 7> a = {1, 6, 11, 5, 3, 8, 13};

    ::cout << "befor sort " << endl;
    for (int i: a) {
        std::cout << i << ",";
    }

    ::cout << "after sort " << endl;
    std:
    sort(a.begin(), a.end());

    for (int i: a) {
        std::cout << i << ",";
    }

    std::cout << endl;


    std::forward_list<int> fl;

    for (int i = 0; i < 20; ++i) {
        fl.push_front(i);
    }

    fl.remove(11);

    std::cout << "forward_list " << endl;

    for (auto i: fl) {
        ::cout << i << ",";
    }

    std::cout << endl;

    fl.reverse();

    std::cout << "forward_list reverse" << endl;

    for (auto i: fl) {
        ::cout << i << ",";
    }

    std::cout << endl;

    std::unordered_map<int, std::string> u = {
            {1, "1"},
            {3, "3"},
            {2, "2"}
    };

    std::map<int, std::string> v = {
            {1, "1"},
            {3, "3"},
            {2, "2"}
    };

    std::cout << "unordered_map" << endl;
    for (const auto &n: u) {
        std::cout << "key = " << n.first << ",value = " << n.second << "";
    }
    ::cout << endl;

    std::cout << "std::map" << std::endl;

    for (const auto &n: v) {
        std::cout << "key = " << n.first << ",value = " << n.second << "";
    }

    ::cout << endl;

    //

    auto student = get_student(0);
    std::cout << "ID:0"
              << "GPA:" << std::get<0>(student) << ","
              << "成绩:" << std::get<1>(student) << ","
              << "姓名:" << std::get<2>(student) << "," << endl;

    double gpa;
    char grade;
    std::string name;

    std::tie(gpa, grade, name) = get_student(1);
    std::cout << "ID: 1, "
              << "GPA: " << gpa << ", "
              << "成绩: " << grade << ", "
              << "姓名: " << name << '\n';
}
