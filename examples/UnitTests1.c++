// --------------
// UnitTests1.c++
// --------------

// https://github.com/google/googletest
// https://github.com/google/googletest/blob/master/googletest/docs/Primer.md
// https://github.com/google/googletest/blob/master/googletest/docs/AdvancedGuide.md

#include <cassert>  // assert
#include <iostream> // cout, endl

#include "gtest/gtest.h"

int cycle_length (int n) {
    assert(n > 0);
    int c = 0;
    while (n > 1) {
        if ((n % 2) == 0)
            n = (n / 2);
        else
            n = (3 * n) + 1;
        ++c;}
    assert(c > 0);
    return c;}

TEST(UnitTestsFixture, test_1) {
    ASSERT_EQ(cycle_length( 1), 1);}

TEST(UnitTestsFixture, test_2) {
    ASSERT_EQ(cycle_length( 5), 6);}

TEST(UnitTestsFixture, test_3) {
    ASSERT_EQ(cycle_length(10), 7);}

/*
% ls -al /usr/include/gtest/
...
gtest.h
...



% locate libgtest.a
/usr/lib/libgtest.a



% locate libpthread.a
...
/usr/lib32/libpthread.a
...



% locate libgtest_main.a
/usr/lib/libgtest_main.a



% g++ -pedantic -std=c++11 -Wall UnitTests1.c++ -o UnitTests1 -lgtest -lgtest_main -pthread



% UnitTests1
Running main() from gtest_main.cc
[==========] Running 3 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 3 tests from UnitTestsFixture
[ RUN      ] UnitTestsFixture.test_1
UnitTests1: Collatz1.h:19: int cycle_length(int): Assertion `c > 0' failed.
*/
