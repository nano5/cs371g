// ---------
// Equal.c++
// ---------

// http://www.cplusplus.com/reference/algorithm/equal/

#include <algorithm>  // equal
#include <functional> // function
#include <list>       // list
#include <vector>     // vector

#include "gtest/gtest.h"

#include "Equal.h"

using namespace std;
using namespace testing;

using EqualListSignature = function<bool (list<int>::const_iterator, list<int>::const_iterator, vector<int>::const_iterator)>;

struct EqualListFixture : TestWithParam<EqualListSignature>
    {};

INSTANTIATE_TEST_CASE_P(
    EqualListInstantiation,
    EqualListFixture,
    Values(
           equal<list<int>::const_iterator, vector<int>::const_iterator>,
        my_equal<list<int>::const_iterator, vector<int>::const_iterator>));

TEST_P(EqualListFixture, test_1) {
    const list<int>   x = {2, 3, 4};
    const vector<int> y = {0, 2, 3, 4, 0};
	ASSERT_FALSE(GetParam()(x.begin(), x.end(), y.begin()));}

TEST_P(EqualListFixture, test_2) {
    const list<int>   x = {2, 3, 4};
    const vector<int> y = {0, 2, 3, 4, 0};
	ASSERT_TRUE(GetParam()(x.begin(), x.end(), y.begin() + 1));}

/*
% g++ -pedantic -std=c++11 -Wall Equal.c++ -o Equal -lgtest -lgtest_main -pthread



% Equal
Running main() from gtest_main.cc
[==========] Running 4 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 4 tests from EqualListInstantiation/EqualListFixture
[ RUN      ] EqualListInstantiation/EqualListFixture.test_1/0
[       OK ] EqualListInstantiation/EqualListFixture.test_1/0 (0 ms)
[ RUN      ] EqualListInstantiation/EqualListFixture.test_1/1
[       OK ] EqualListInstantiation/EqualListFixture.test_1/1 (0 ms)
[ RUN      ] EqualListInstantiation/EqualListFixture.test_2/0
[       OK ] EqualListInstantiation/EqualListFixture.test_2/0 (0 ms)
[ RUN      ] EqualListInstantiation/EqualListFixture.test_2/1
[       OK ] EqualListInstantiation/EqualListFixture.test_2/1 (0 ms)
[----------] 4 tests from EqualListInstantiation/EqualListFixture (0 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 4 tests.
*/
