//
//  QueueTest.hpp
//  STLTest
//
//  Created by ksnowlv on 2022/2/25.
//

#ifndef QueueTest_hpp
#define QueueTest_hpp

#include <stdio.h>
#include "BaseTest.hpp"

class QueueTest : public BaseTest {
public:
    QueueTest();

    ~QueueTest();

public:
    void test() override;
};

#endif /* QueueTest_hpp */
