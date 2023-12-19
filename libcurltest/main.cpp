
#include "CurlTest.h"

using namespace std;

int main() {
    std::unique_ptr<CurlTest> curlTest(std::make_unique<CurlTest>());
    curlTest->testCurlhttpGet();
    curlTest->testCurlHttpPost();

    return 0;
}
