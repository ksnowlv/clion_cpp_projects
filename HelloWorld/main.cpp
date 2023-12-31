
#include <iostream>
#include "TestCase.h"

using namespace std;

int main(int argc, char *argv[])
{
    std::cout << "Hello world!" << std::endl;
    unique_ptr<TestCase> tc(make_unique<TestCase>());
    tc->TestMyCase();
}
