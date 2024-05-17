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
#include "ArrayTest.hpp"
#include "DequeTest.hpp"
#include "ListTest.hpp"
#include "QueueTest.hpp"
#include "StackTest.hpp"
#include "SortTest.hpp"


TestCase::TestCase() {
    init();
}

TestCase::~TestCase() {

}

void TestCase::testMyCase() {
    for (const auto &item: m_vector) {
        item->test();
    }
}

void TestCase::init() {

    unique_ptr<BaseTest> personTest(make_unique<PersonTest>());
    m_vector.emplace_back(std::move(personTest));

    initSTL();
    initSort();
    initMultiThread();
}

void TestCase::initSTL() {
    unique_ptr<VectorTest> vectorTest(make_unique<VectorTest>());
    m_vector.emplace_back(std::move(vectorTest));

    unique_ptr<ArrayTest> arrayTest(make_unique<ArrayTest>());
    m_vector.emplace_back(std::move(arrayTest));

    unique_ptr<DequeueTest> dequeueTest(make_unique<DequeueTest>());
    m_vector.emplace_back(std::move(dequeueTest));

    unique_ptr<ListTest> listTest(make_unique<ListTest>());
    m_vector.emplace_back(std::move(listTest));

    unique_ptr<QueueTest> queueTest(make_unique<QueueTest>());
    m_vector.emplace_back(std::move(queueTest));

    unique_ptr<StackTest> stackTest(make_unique<StackTest>());
    m_vector.emplace_back(std::move(stackTest));

}

void TestCase::initMultiThread() {
    unique_ptr<AtomicTest> atomicTest(make_unique<AtomicTest>());
    m_vector.emplace_back(std::move(atomicTest));

    unique_ptr<ProcessTest> processTest(make_unique<ProcessTest>());
    m_vector.emplace_back(std::move(processTest));

    unique_ptr<FutureTest> futureTest(make_unique<FutureTest>());
    m_vector.emplace_back(std::move(futureTest));

    unique_ptr<MutexTest> mutexTest(make_unique<MutexTest>());
    m_vector.emplace_back(std::move(mutexTest));

    unique_ptr<MunmapTest> munmapTest(make_unique<MunmapTest>());
    m_vector.emplace_back(std::move(munmapTest));

}

void TestCase::initSort() {
    unique_ptr<SortTest> sortTest(make_unique<SortTest>());
    m_vector.emplace_back(std::move(sortTest));
}
