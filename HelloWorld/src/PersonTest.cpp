#include "PersonTest.h"
#include "Person.h"
#include <iostream>
#include <memory>
#include <tuple>
using namespace std;

PersonTest::PersonTest() {

}

PersonTest::~PersonTest() {

}

void PersonTest::Test() {
    cout<<"---"<<__func__<<endl;
    unique_ptr<Person> person(make_unique<Person>());
    person->SetAge(20);
    person->SetName("ksnowlv");
    person->ShowInfomation();

    const int PersonNumber = 10;
    unique_ptr<Person[]> persons(new Person[PersonNumber]());

    for (size_t i = 0; i < PersonNumber; i++) {
        persons[i].SetAge(i + 1);
        persons[i].SetName("ksnow:" + to_string(i));
        cout<<"unique_ptr age:"<<persons[i].GetAge()<<",name:"<<persons[i].GetName()<<endl;
    }

    shared_ptr<Person> sharedPersons(new Person[PersonNumber](), default_delete<Person[]>());


    for (size_t i = 0; i < PersonNumber; i++) {
        sharedPersons.get()[i].SetAge(i + 1);
        sharedPersons.get()[i].SetName("ksnow:" + to_string(i));
        cout<<"sharedPersons age:"<<sharedPersons.get()[i].GetAge()<<",name:"<<sharedPersons.get()[i].GetName()<<endl;
    }

    // std::shared_ptr<int> sp3(new int[10](), std::default_delete<int[]>());

    shared_ptr<Person> p1(make_shared<Person>(10));
    cout<<"1 p1 use_count:"<<p1.use_count()<<",age:"<<p1->GetAge()<<endl;
    shared_ptr<Person> p2 = p1;
    cout<<"2 p1 use_count:"<<p1.use_count()<<endl;
    shared_ptr<Person> p3 = p1;
    cout<<"3 p1 use_count:"<<p1.use_count()<<endl;
    p3.reset();
    cout<<"4 p1 use_count:"<<p1.use_count()<<endl;
}