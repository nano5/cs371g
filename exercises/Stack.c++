// ---------
// Stack.c++
// ---------

// http://www.cplusplus.com/reference/stack/stack/

#include <cassert> // assert
#include <list>    // list
#include <stack>   // stack
#include <vector>  // vector

#include "gtest/gtest.h"

#include "Stack.h"

using namespace std;

using testing::Test;
using testing::Types;

template <typename T>
struct Stack_Fixture : Test {
    typedef T stack_type;};

typedef Types<
            stack<int>,
            stack<int, list<int>>,
            stack<int, vector<int>>,
            my_stack<int>,
            my_stack<int, list<int>>,
            my_stack<int, vector<int>>>
        stack_types;

TYPED_TEST_CASE(Stack_Fixture, stack_types);

TYPED_TEST(Stack_Fixture, test_1) {
    typedef typename TestFixture::stack_type stack_type;

    stack_type x;
    ASSERT_TRUE(x.empty());
    ASSERT_EQ(x.size(), 0);

    x.push(2);
    x.push(3);
    x.push(4);
    ASSERT_FALSE(x.empty());
    ASSERT_EQ(x.size(), 3);
    ASSERT_EQ(x.top(),  4);

    x.pop();
    ASSERT_EQ(x.size(), 2);
    ASSERT_EQ(x.top(),  3);

    x.top() = 4;
    ASSERT_EQ(x.top(),  4);}

TYPED_TEST(Stack_Fixture, test_2) {
    typedef typename TestFixture::stack_type stack_type;

    stack_type x;
    x.push(2);
    x.push(3);
    x.push(4);
    x.top() = 5;
    ASSERT_EQ(x.top(), 5);

    const stack_type& r = x;
//  r.top() = 6;             // error: member function 'push' not viable: 'this' argument has type 'const stack_type'
    ASSERT_EQ(r.top(), 5);}

TYPED_TEST(Stack_Fixture, test_3) {
    typedef typename TestFixture::stack_type stack_type;

    stack_type x;
    x.push(2);
    x.push(3);
    x.push(4);

    stack_type y = x;
    ASSERT_EQ(y, x);

    y.pop();
    ASSERT_EQ(x.size(), 3);
    ASSERT_EQ(x.top(),  4);
    ASSERT_EQ(y.size(), 2);
    ASSERT_EQ(y.top(),  3);}

TYPED_TEST(Stack_Fixture, test_4) {
    typedef typename TestFixture::stack_type stack_type;

    stack_type x;
    x.push(2);
    x.push(3);
    x.push(4);

    stack_type y;
    y.push(5);
    y.push(6);

    y = x;
    ASSERT_EQ(y, x);

    y.pop();
    ASSERT_EQ(x.size(), 3);
    ASSERT_EQ(x.top(),  4);
    ASSERT_EQ(y.size(), 2);
    ASSERT_EQ(y.top(),  3);}

TYPED_TEST(Stack_Fixture, test_5) {
    typedef typename TestFixture::stack_type stack_type;

    stack_type x;
    x.push(2);
    x.push(3);
    x.push(4);

    stack_type y;
    y.push(2);
    y.push(3);
    y.push(4);

    ASSERT_FALSE(x != y);
    ASSERT_FALSE(x <  y);
    ASSERT_FALSE(x >  y);
    ASSERT_TRUE (x <= y);
    ASSERT_TRUE (x >= y);}
