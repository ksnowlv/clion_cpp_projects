#ifndef C71500F9_F5A5_4D88_A3B8_15D7F814724E
#define C71500F9_F5A5_4D88_A3B8_15D7F814724E

#include <string>

using namespace std;

#include "BaseTest.hpp"

class AtomicTest : public BaseTest {

public:
    AtomicTest() = default;

    ~AtomicTest();

public:
    void test() override;

private:
    void testAtomicInt64();

    void testAtomicIntFlag();

private:
    static void threadFunction(const string &name, const int num);

    static void setAtomicFlag();

    static void clearAtomicFlag();
};

#endif /* C71500F9_F5A5_4D88_A3B8_15D7F814724E */
