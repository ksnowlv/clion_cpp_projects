//
//  SortTest.cpp
//  STLTest
//
//  Created by ksnowlv on 2022/3/11.
//

#include "SortTest.hpp"
#include <string.h>
#include <iostream>
using namespace std;


void SortTest::test() {
    const int KLenOfArray = 11;
    int p[KLenOfArray] = {10,6,12,5,1,8,11,32,1,21, 3};
    int q[KLenOfArray];
    memset(q, 0, sizeof(int) * KLenOfArray);
    memcpy(q, p, sizeof(int) * KLenOfArray);
    
    std::cout<<"初始数组顺序如下"<<endl;
    showArray(q, KLenOfArray);
    
    memset(q, 0, sizeof(int) * KLenOfArray);
    memcpy(q, p, sizeof(int) * KLenOfArray);
    std::cout<<"冒泡排序后为"<<endl;
    bubbleSort(q, KLenOfArray);
    showArray(q, KLenOfArray);


    memset(q, 0, sizeof(int) * KLenOfArray);
    memcpy(q, p, sizeof(int) * KLenOfArray);
    std::cout<<"插入排序后为"<<endl;
    insertionSort(q, KLenOfArray);
    showArray(q, KLenOfArray);
    
    memset(q, 0, sizeof(int) * KLenOfArray);
    memcpy(q, p, sizeof(int) * KLenOfArray);
    std::cout<<"选择排序后为"<<endl;
    selectionSort(q, KLenOfArray);
    showArray(q, KLenOfArray);
    
    memset(q, 0, sizeof(int) * KLenOfArray);
    memcpy(q, p, sizeof(int) * KLenOfArray);
    std::cout<<"quickSort快速排序后为"<<endl;
    quickSort(q, 0, KLenOfArray - 1);
    showArray(q, KLenOfArray);

}

void SortTest::bubbleSort(int *p, const int len) {
    
    bool exchangeFlag = false;
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - 1 - i; ++j) {
            if (p[j] > p[j + 1]) {
                swap(p[j], p[j + 1]);
                exchangeFlag = true;
            }
        }
        
        if (!exchangeFlag) {
            break;
        }
    }
}

void SortTest::bubbleSort(vector<int> &v) {
    
    bool exchangeFlag = false;
    const unsigned long len  = v.size();
    
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - 1 - i; ++j) {
            if (v[j] > v[j + 1]) {
                std::swap(v[j], v[j + 1]);
                exchangeFlag = true;
            }
        }
        
        if (!exchangeFlag) {
            break;
        }
    }
}

void SortTest::insertionSort(int *p, const int len) {
    
    int key = 0;
    
    for (int i = 1; i < len; ++i) {
        key = p[i];
        int j = i - 1;
        
        while (j >= 0 && p[j] > key) {
            p[j + 1] = p[j];
            --j;
        }
        
        p[j + 1] = key;
    }
}

void SortTest::selectionSort(int *p, const int len) {
    
    for (int i = 0; i < len; ++i) {
        int smallIdx = i;
        for (int j = i + 1; j < len; ++j) {
            if (p[j] < p[smallIdx]) {
                smallIdx = j;
            }
        }
        
        if (smallIdx != i) {
            swap(p[i], p[smallIdx]);
        }
    }
}


void SortTest::quickSort(int *p,const int start, const int end) {

    if (start < end) {
        int pivot = p[end];
        int i = start - 1;

        for (int j = start; j < end  ; ++j) {

            if (p[j] <= pivot) {
                ++i;
                std::swap(p[i], p[j]);
            }
        }
        std::swap(p[i + 1], p[end]);
        int pivotIndex = i + 1;//分区并获取枢纽索引

        quickSort(p, 0, pivotIndex - 1);//对枢纽左侧的子数组进行快速排序
        quickSort(p, pivotIndex + 1, end);//对枢纽右侧的子数组进行快速排序

    }
}

const void SortTest::showArray(const int *p, const int len) const {
    if (nullptr == p || len == 0) {
        return;
    }
    
    std::cout<<"arraylist infommation:";
    for (int i = 0; i < len; ++i) {
        std::cout<<p[i]<<",";
    }
    std::cout<<endl;
}



