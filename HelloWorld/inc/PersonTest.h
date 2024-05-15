#ifndef PERSONTEST_H
#define PERSONTEST_H

#include "Person.h"
#pragma once

#include "BaseTest.hpp"

class PersonTest: public BaseTest
{
public:
    PersonTest();
    ~PersonTest();

public:
    void test() override;
private:

};

#endif