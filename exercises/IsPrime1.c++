// ------------
// IsPrime1.c++
// ------------

// https://en.wikipedia.org/wiki/Primality_test

#include "gtest/gtest.h"

#include "IsPrime1.h"

TEST(IsPrimeFixture, test_1) {
    ASSERT_FALSE(is_prime( 1));}

TEST(IsPrimeFixture, test_2) {
    ASSERT_FALSE(is_prime( 2));}

TEST(IsPrimeFixture, test_3) {
    ASSERT_TRUE(is_prime( 3));}

TEST(IsPrimeFixture, test_4) {
    ASSERT_FALSE(is_prime( 4));}

TEST(IsPrimeFixture, test_5) {
    ASSERT_TRUE(is_prime( 5));}

TEST(IsPrimeFixture, test_7) {
    ASSERT_TRUE(is_prime( 7));}

TEST(IsPrimeFixture, test_9) {
    ASSERT_TRUE(is_prime( 9));}

TEST(IsPrimeFixture, test_27) {
    ASSERT_FALSE(is_prime(27));}

TEST(IsPrimeFixture, test_29) {
    ASSERT_TRUE(is_prime(29));}

/*
% IsPrime1
Running main() from gtest_main.cc
[==========] Running 9 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 9 tests from IsPrimeFixture
[ RUN      ] IsPrimeFixture.test_1
[       OK ] IsPrimeFixture.test_1 (0 ms)
[ RUN      ] IsPrimeFixture.test_2
[       OK ] IsPrimeFixture.test_2 (0 ms)
[ RUN      ] IsPrimeFixture.test_3
[       OK ] IsPrimeFixture.test_3 (0 ms)
[ RUN      ] IsPrimeFixture.test_4
[       OK ] IsPrimeFixture.test_4 (0 ms)
[ RUN      ] IsPrimeFixture.test_5
[       OK ] IsPrimeFixture.test_5 (0 ms)
[ RUN      ] IsPrimeFixture.test_7
[       OK ] IsPrimeFixture.test_7 (0 ms)
[ RUN      ] IsPrimeFixture.test_9
[       OK ] IsPrimeFixture.test_9 (0 ms)
[ RUN      ] IsPrimeFixture.test_27
[       OK ] IsPrimeFixture.test_27 (0 ms)
[ RUN      ] IsPrimeFixture.test_29
[       OK ] IsPrimeFixture.test_29 (0 ms)
[----------] 9 tests from IsPrimeFixture (0 ms total)

[----------] Global test environment tear-down
[==========] 9 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 9 tests.
*/
