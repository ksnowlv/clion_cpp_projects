#include "Person.h"
#include <iostream>

Person::Person() {
    m_age = 0;
}

Person::Person(const int age) {
    m_age = age;
}

Person::~Person() {

}

void Person::ShowInfomation() const {
    std::cout<<"name:"<<m_name<<",age:"<<m_age<<std::endl;
}