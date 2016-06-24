// ---------
// Range.c++
// ---------

#include <algorithm> // equal
#include <cassert>   // assert
#include <iostream>  // cout, endl

#include "gtest/gtest.h"

#include "Range.h"

/*
template <typename C>
auto begin (C& x) -> decltype (x.begin()) {
    return x.begin();}

template <typename C>
auto begin (const C& x) -> decltype (x.begin()) {
    return x.begin();}

template <typename C>
auto end (C& x) -> decltype (x.end()) {
    return x.end();}

template <typename C>
auto end (const C& x) -> decltype (x.end()) {
    return x.end();}
*/

using namespace std;

TEST(RangeFixture, test_1) {
    const Range<int> x = {2, 2};
    const Range<int>::iterator b = x.begin();
    const Range<int>::iterator e = x.end();
    ASSERT_EQ(b, e);}

TEST(RangeFixture, test_2) {
    Range<int> x = {2, 3};
    Range<int>::iterator b = x.begin();
    Range<int>::iterator e = x.end();
    ASSERT_NE(b, e);
    ASSERT_EQ(2, *b);
    Range<int>::iterator& y = ++b;
    ASSERT_EQ(&y, &b);
    ASSERT_EQ(b, e);}

TEST(RangeFixture, test_3) {
    Range<int> x = {2, 4};
    Range<int>::iterator b = x.begin();
    Range<int>::iterator e = x.end();
    ASSERT_NE(b, e);
    ASSERT_EQ(2, *b);
    ++b;
    ASSERT_NE(b, e);
    ASSERT_EQ(3, *b);
    b++;
    ASSERT_EQ(b, e);}

TEST(RangeFixture, test_4) {
    Range<int> x = {2, 5};
    ASSERT_TRUE(equal(begin(x), end(x), begin({2, 3, 4})));}

/*
% Range
Running main() from gtest_main.cc
[==========] Running 4 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 4 tests from RangeFixture
[ RUN      ] RangeFixture.test_1
[       OK ] RangeFixture.test_1 (0 ms)
[ RUN      ] RangeFixture.test_2
[       OK ] RangeFixture.test_2 (0 ms)
[ RUN      ] RangeFixture.test_3
[       OK ] RangeFixture.test_3 (0 ms)
[ RUN      ] RangeFixture.test_4
[       OK ] RangeFixture.test_4 (0 ms)
[----------] 4 tests from RangeFixture (0 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 4 tests.
*/
