#ifndef E5B39878_7C3A_441F_B204_66722AD76B36
#define E5B39878_7C3A_441F_B204_66722AD76B36

#include <memory>
#include <vector>
using namespace std;

#include "BaseTest.h"

class TestCase {
public:
    TestCase();
    ~TestCase();

public:
    void TestMyCase();

private:
    void Init();
private:
    vector<unique_ptr<BaseTest>> m_vector;
};

#endif /* E5B39878_7C3A_441F_B204_66722AD76B36 */
