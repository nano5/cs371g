// ---------
// AllOf.c++
// ---------

// http://www.cplusplus.com/reference/algorithm/all_of/

#include <algorithm>  // all_of
#include <cassert>    // assert
#include <functional> // function
#include <iostream>   // cout, endl
#include <list>       // list

#include "gtest/gtest.h"

#include "AllOf.h"

using namespace std;
using namespace testing;

using AllOfListSignature = function<bool (list<int>::const_iterator, list<int>::const_iterator, function<bool (int)>)>;

struct AllOfListFixture : TestWithParam<AllOfListSignature>
    {};

INSTANTIATE_TEST_CASE_P(
    AllOfListInstantiation,
    AllOfListFixture,
    Values(
           all_of<list<int>::const_iterator, function<bool (int)>>,
        my_all_of<list<int>::const_iterator, function<bool (int)>>));

TEST_P(AllOfListFixture, test_1) {
    const list<int> x = {3, 5, 7};
    ASSERT_TRUE(GetParam()(begin(x), end(x), [] (int v) -> bool {return (v % 2);}));}

TEST_P(AllOfListFixture, test_2) {
    const int       n = 2;
    const list<int> x = {3, 5, 7};
    ASSERT_TRUE(GetParam()(begin(x), end(x), [n] (int v) -> bool {return (v % n);}));}

/*
% AllOf
Running main() from gtest_main.cc
[==========] Running 4 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 4 tests from AllOfListInstantiation/AllOfListFixture
[ RUN      ] AllOfListInstantiation/AllOfListFixture.test_1/0
[       OK ] AllOfListInstantiation/AllOfListFixture.test_1/0 (0 ms)
[ RUN      ] AllOfListInstantiation/AllOfListFixture.test_1/1
[       OK ] AllOfListInstantiation/AllOfListFixture.test_1/1 (0 ms)
[ RUN      ] AllOfListInstantiation/AllOfListFixture.test_2/0
[       OK ] AllOfListInstantiation/AllOfListFixture.test_2/0 (0 ms)
[ RUN      ] AllOfListInstantiation/AllOfListFixture.test_2/1
[       OK ] AllOfListInstantiation/AllOfListFixture.test_2/1 (0 ms)
[----------] 4 tests from AllOfListInstantiation/AllOfListFixture (0 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 4 tests.
*/
