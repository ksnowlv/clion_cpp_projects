
#include <iostream>
#include "TestCase.h"

using namespace std;

int main(int argc, char *argv[]) {
    std::cout << "Hello world!" << std::endl;
    unique_ptr<TestCase> tc(make_unique<TestCase>());
    tc->testMyCase();

    //test memory problem
    int *p = new int[100];
    p[100] = 3;
}
