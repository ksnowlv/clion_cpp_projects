//
//  SortTest.hpp
//  STLTest
//
//  Created by ksnowlv on 2022/3/11.
//

#ifndef SortTest_hpp
#define SortTest_hpp

#include <stdio.h>
#include <vector>
using namespace  std;
#include "BaseTest.hpp"

class SortTest: public BaseTest {
public:
    SortTest() = default;
    ~SortTest() = default;
    
public:
    
    void test() override;
    
private:
    void bubbleSort(vector<int> &v);
    void bubbleSort(int *p, const int len);
    void insertionSort(int *p, const int len);
    void selectionSort(int *p, const int len);
    void quickSort(int *p,const int start, const int end);
    
private:
    const void showArray(const int *p, const int len) const;

    
};

#endif /* SortTest_hpp */


