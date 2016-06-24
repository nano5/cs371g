// -----------------
// RangeIterator.c++
// -----------------

#include <algorithm> // equal

#include "gtest/gtest.h"

#include "RangeIterator.h"

using namespace std;

TEST(RangeIteratorFixture, test_1) {
    const Range_Iterator<int> b = 2;
    const Range_Iterator<int> e = 2;
    ASSERT_EQ(b, e);}

TEST(RangeIteratorFixture, test_2) {
    Range_Iterator<int> b = 2;
    Range_Iterator<int> e = 3;
    ASSERT_NE(b, e);
    ASSERT_EQ(2, *b);
    Range_Iterator<int>& x = ++b;
    ASSERT_EQ(&x, &b);
    ASSERT_EQ(b, e);}

TEST(RangeIteratorFixture, test_3) {
    Range_Iterator<int> b = 2;
    Range_Iterator<int> e = 4;
    ASSERT_NE(b, e);
    ASSERT_EQ(2, *b);
    ++b;
    ASSERT_NE(b, e);
    ASSERT_EQ(3, *b);
    Range_Iterator<int> x = b++;
    ASSERT_NE(&x, &b);
    ASSERT_EQ(b, e);}

TEST(RangeIteratorFixture, test_4) {
    ASSERT_TRUE(equal(Range_Iterator<int>(2), Range_Iterator<int>(5), begin({2, 3, 4})));}

/*
% RangeIterator
Running main() from gtest_main.cc
[==========] Running 4 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 4 tests from RangeIteratorFixture
[ RUN      ] RangeIteratorFixture.test_1
[       OK ] RangeIteratorFixture.test_1 (0 ms)
[ RUN      ] RangeIteratorFixture.test_2
[       OK ] RangeIteratorFixture.test_2 (0 ms)
[ RUN      ] RangeIteratorFixture.test_3
[       OK ] RangeIteratorFixture.test_3 (0 ms)
[ RUN      ] RangeIteratorFixture.test_4
[       OK ] RangeIteratorFixture.test_4 (0 ms)
[----------] 4 tests from RangeIteratorFixture (0 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 4 tests.
*/
