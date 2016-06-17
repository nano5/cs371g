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
    typedef          T              pair_type;
    typedef typename T::first_type  first_type;
    typedef typename T::second_type second_type;};

typedef Types<
               pair<int, int>,
            my_pair<int, int>>
        pair_types;

TYPED_TEST_CASE(Pair_Fixture, pair_types);

TYPED_TEST(Pair_Fixture, test_1) {
    typedef typename TestFixture::pair_type   pair_type;
    typedef typename TestFixture::first_type  first_type;
    typedef typename TestFixture::second_type second_type;

    pair_type   x;
    first_type  f = x.first;
    second_type s = x.second;
    ASSERT_EQ(f, 0);
    ASSERT_EQ(s, 0);}

TYPED_TEST(Pair_Fixture, test_2) {
    typedef typename TestFixture::pair_type   pair_type;
    typedef typename TestFixture::first_type  first_type;
    typedef typename TestFixture::second_type second_type;

    pair_type   x(2, 3);
    first_type  f = x.first;
    second_type s = x.second;
    ASSERT_EQ(f, 2);
    ASSERT_EQ(s, 3);}

TYPED_TEST(Pair_Fixture, test_3) {
    typedef typename TestFixture::pair_type pair_type;

    pair_type x(2, 3);
    pair_type y = x;
    ASSERT_EQ(y.first,  2);
    ASSERT_EQ(y.second, 3);
    ASSERT_NE(&x.first,  &y.first);
    ASSERT_NE(&x.second, &y.second);}

TYPED_TEST(Pair_Fixture, test_4) {
    typedef typename TestFixture::pair_type pair_type;

    pair_type x(2, 3);
    pair_type y(4, 5);
    y = x;
    ASSERT_EQ(y.first,  2);
    ASSERT_EQ(y.second, 3);
    ASSERT_NE(&x.first,  &y.first);
    ASSERT_NE(&x.second, &y.second);}
