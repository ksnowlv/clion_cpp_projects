#include "TestCase.h"
#include "PersonTest.h"
#include "AtomicTest.h"
#include "ProcessTest.h"
#include "VectorTest.h"
#include <algorithm>
#include <memory>
#include <utility>
#include "FutureTest.h"
#include "MutexTest.h"
#include "MunmapTest.h"


TestCase::TestCase() {
    Init();
}

TestCase::~TestCase() {

}

void TestCase::TestMyCase() {

    for (const auto &item : m_vector) {
        item->Test();
    }
}

void TestCase::Init() {

    unique_ptr<BaseTest> personTest(make_unique<PersonTest>());
    m_vector.emplace_back(std::move(personTest));

    unique_ptr<AtomicTest> atomicTest(make_unique<AtomicTest>());
    m_vector.emplace_back(std::move(atomicTest));

    unique_ptr<ProcessTest> processTest(make_unique<ProcessTest>());
    m_vector.emplace_back(std::move(processTest));

    unique_ptr<VectorTest> vectorTest(make_unique<VectorTest>());
    m_vector.emplace_back(std::move(vectorTest));

    unique_ptr<FutureTest> futureTest(make_unique<FutureTest>());
    m_vector.emplace_back(std::move(futureTest));

    unique_ptr<MutexTest> mutexTest(make_unique<MutexTest>());
    m_vector.emplace_back(std::move(mutexTest));

    unique_ptr<MunmapTest>  munmapTest(make_unique<MunmapTest>());
    m_vector.emplace_back(std::move(munmapTest));
}
