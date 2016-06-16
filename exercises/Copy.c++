// --------
// Copy.c++
// --------

// http://www.cplusplus.com/reference/algorithm/copy/

#include <algorithm>  // copy, equal
#include <cassert>    // assert
#include <functional> // function
#include <iostream>   // cout, endl
#include <list>       // list
#include <vector>     // vector

#include "gtest/gtest.h"

#include "Copy.h"

using namespace std;
using namespace testing;

using CopyListSignature = function<vector<int>::iterator (list<int>::const_iterator, list<int>::const_iterator, vector<int>::iterator)>;

struct CopyListFixture : TestWithParam<CopyListSignature>
    {};

INSTANTIATE_TEST_CASE_P(
    CopyListInstantiation,
    CopyListFixture,
    Values(
           copy<list<int>::const_iterator, vector<int>::iterator>,
        my_copy<list<int>::const_iterator, vector<int>::iterator>));

TEST_P(CopyListFixture, test_1) {
    const list<int>       x = {2, 3, 4};
          vector<int>     y(5);
    const vector<int>     z = {0, 2, 3, 4, 0};
    vector<int>::iterator p = GetParam()(begin(x), end(x), begin(y) + 1);
    ASSERT_EQ(p, begin(y) + 4);
    ASSERT_TRUE(equal(begin(y), y.end(), z.begin()));}

TEST_P(CopyListFixture, test_2) {
    const list<int>       x = {2, 3, 4, 5};
          vector<int>     y(6);
    const vector<int>     z = {0, 2, 3, 4, 5, 0};
    vector<int>::iterator p = GetParam()(begin(x), end(x), begin(y) + 1);
    ASSERT_EQ(p, begin(y) + 5);
    ASSERT_TRUE(equal(begin(y), y.end(), z.begin()));}

/*
% g++ -pedantic -std=c++11 -Wall Copy.c++ -o Copy -lgtest -lgtest_main -pthread



% Copy
Running main() from gtest_main.cc
[==========] Running 4 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 4 tests from CopyListInstantiation/CopyListFixture
[ RUN      ] CopyListInstantiation/CopyListFixture.test_1/0
[       OK ] CopyListInstantiation/CopyListFixture.test_1/0 (0 ms)
[ RUN      ] CopyListInstantiation/CopyListFixture.test_1/1
[       OK ] CopyListInstantiation/CopyListFixture.test_1/1 (0 ms)
[ RUN      ] CopyListInstantiation/CopyListFixture.test_2/0
[       OK ] CopyListInstantiation/CopyListFixture.test_2/0 (0 ms)
[ RUN      ] CopyListInstantiation/CopyListFixture.test_2/1
[       OK ] CopyListInstantiation/CopyListFixture.test_2/1 (0 ms)
[----------] 4 tests from CopyListInstantiation/CopyListFixture (0 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 4 tests.
*/
