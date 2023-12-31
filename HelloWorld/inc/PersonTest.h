#ifndef PERSONTEST_H
#define PERSONTEST_H

#include "Person.h"
#pragma once

#include "BaseTest.h"

class PersonTest: public BaseTest
{
public:
    PersonTest();
    ~PersonTest();

public:
    void Test() override;
private:

};

#endif