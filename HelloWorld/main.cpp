
#include <iostream>
#include "TestCase.h"

using namespace std;

int main(int argc, char *argv[])
{
    std::string filePath = "/tmp/linux-sdk/counterlib/video/3/1.mp4";


    std::cout << "Hello world!" << std::endl;
    unique_ptr<TestCase> tc(make_unique<TestCase>());
    tc->TestMyCase();

    int * p = new int[100];

    p[100] = 3;
}
