//
//  ArrayTest.hpp
//  STLTest
//
//  Created by ksnowlv on 2022/3/1.
//

#ifndef ArrayTest_hpp
#define ArrayTest_hpp

#include <stdio.h>
#include "BaseTest.hpp"

class ArrayTest : public BaseTest {

public:
    ArrayTest() = default;

    ArrayTest &operator=(const ArrayTest &test) = delete;

    ~ArrayTest();

public:
    void test() override;

};

#endif /* ArrayTest_hpp */
