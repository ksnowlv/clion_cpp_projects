#ifndef C71500F9_F5A5_4D88_A3B8_15D7F814724E
#define C71500F9_F5A5_4D88_A3B8_15D7F814724E

#include <string>
using namespace std;

#include "BaseTest.h"

class AtomicTest: public BaseTest  {

public:
    AtomicTest() = default;
    ~AtomicTest();

public:
    void Test() override;

private:
    void TestAtomicInt64();
    void TestAtomicIntFlag();

private:
    static void ThreadFunction(const string &name, const int num);
    static void SetAtomicFlag();
    static void ClearAtomicFlag();
};

#endif /* C71500F9_F5A5_4D88_A3B8_15D7F814724E */
