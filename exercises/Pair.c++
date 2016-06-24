// --------
// Pair.c++
// --------

// http://www.cplusplus.com/reference/utility/pair/

#include <utility> // pair

#include "gtest/gtest.h"

#include "Pair.h"

using namespace std;

using testing::Test;
using testing::Types;

template <typename T>
struct Pair_Fixture : Test {
    using pair_type   = T;
    using first_type  = typename T::first_type;
    using second_type = typename T::second_type;};

typedef Types<
               pair<int, int>,
            my_pair<int, int>>
        pair_types;

TYPED_TEST_CASE(Pair_Fixture, pair_types);

TYPED_TEST(Pair_Fixture, test_1) {
    using pair_type   = typename TestFixture::pair_type;
    using first_type  = typename TestFixture::first_type;
    using second_type = typename TestFixture::second_type;

    pair_type   x;
    first_type  f = x.first;
    second_type s = x.second;
    ASSERT_EQ(f, 0);
    ASSERT_EQ(s, 0);}

TYPED_TEST(Pair_Fixture, test_2) {
    using pair_type   = typename TestFixture::pair_type;
    using first_type  = typename TestFixture::first_type;
    using second_type = typename TestFixture::second_type;

    pair_type   x = {2, 3};
    first_type  f = x.first;
    second_type s = x.second;
    ASSERT_EQ(f, 2);
    ASSERT_EQ(s, 3);}

TYPED_TEST(Pair_Fixture, test_3) {
    using pair_type = typename TestFixture::pair_type;

    pair_type x = {2, 3};
    pair_type y = x;
    ASSERT_EQ(y.first,  2);
    ASSERT_EQ(y.second, 3);
    ASSERT_NE(&x.first,  &y.first);
    ASSERT_NE(&x.second, &y.second);}

TYPED_TEST(Pair_Fixture, test_4) {
    using pair_type = typename TestFixture::pair_type;

    pair_type x = {2, 3};
    pair_type y = {4, 5};
    y = x;
    ASSERT_EQ(y.first,  2);
    ASSERT_EQ(y.second, 3);
    ASSERT_NE(&x.first,  &y.first);
    ASSERT_NE(&x.second, &y.second);}

/*
% Pair
Running main() from gtest_main.cc
[==========] Running 8 tests from 2 test cases.
[----------] Global test environment set-up.
[----------] 4 tests from Pair_Fixture/0, where TypeParam = std::__1::pair<int, int>
[ RUN      ] Pair_Fixture/0.test_1
[       OK ] Pair_Fixture/0.test_1 (0 ms)
[ RUN      ] Pair_Fixture/0.test_2
[       OK ] Pair_Fixture/0.test_2 (0 ms)
[ RUN      ] Pair_Fixture/0.test_3
[       OK ] Pair_Fixture/0.test_3 (0 ms)
[ RUN      ] Pair_Fixture/0.test_4
[       OK ] Pair_Fixture/0.test_4 (0 ms)
[----------] 4 tests from Pair_Fixture/0 (0 ms total)

[----------] 4 tests from Pair_Fixture/1, where TypeParam = my_pair<int, int>
[ RUN      ] Pair_Fixture/1.test_1
[       OK ] Pair_Fixture/1.test_1 (0 ms)
[ RUN      ] Pair_Fixture/1.test_2
[       OK ] Pair_Fixture/1.test_2 (0 ms)
[ RUN      ] Pair_Fixture/1.test_3
[       OK ] Pair_Fixture/1.test_3 (0 ms)
[ RUN      ] Pair_Fixture/1.test_4
[       OK ] Pair_Fixture/1.test_4 (0 ms)
[----------] 4 tests from Pair_Fixture/1 (0 ms total)

[----------] Global test environment tear-down
[==========] 8 tests from 2 test cases ran. (0 ms total)
[  PASSED  ] 8 tests.
*/
