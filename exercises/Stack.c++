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
    using stack_type = T;};

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
    using stack_type = typename TestFixture::stack_type;

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
    using stack_type = typename TestFixture::stack_type;

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
    using stack_type = typename TestFixture::stack_type;

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
    using stack_type = typename TestFixture::stack_type;

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
    using stack_type = typename TestFixture::stack_type;

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

/*
% Stack
Running main() from gtest_main.cc
[==========] Running 30 tests from 6 test cases.
[----------] Global test environment set-up.
[----------] 5 tests from Stack_Fixture/0, where TypeParam = std::__1::stack<int, std::__1::deque<int, std::__1::allocator<int> > >
[ RUN      ] Stack_Fixture/0.test_1
[       OK ] Stack_Fixture/0.test_1 (0 ms)
[ RUN      ] Stack_Fixture/0.test_2
[       OK ] Stack_Fixture/0.test_2 (0 ms)
[ RUN      ] Stack_Fixture/0.test_3
[       OK ] Stack_Fixture/0.test_3 (0 ms)
[ RUN      ] Stack_Fixture/0.test_4
[       OK ] Stack_Fixture/0.test_4 (0 ms)
[ RUN      ] Stack_Fixture/0.test_5
[       OK ] Stack_Fixture/0.test_5 (0 ms)
[----------] 5 tests from Stack_Fixture/0 (0 ms total)

[----------] 5 tests from Stack_Fixture/1, where TypeParam = std::__1::stack<int, std::__1::list<int, std::__1::allocator<int> > >
[ RUN      ] Stack_Fixture/1.test_1
[       OK ] Stack_Fixture/1.test_1 (0 ms)
[ RUN      ] Stack_Fixture/1.test_2
[       OK ] Stack_Fixture/1.test_2 (0 ms)
[ RUN      ] Stack_Fixture/1.test_3
[       OK ] Stack_Fixture/1.test_3 (0 ms)
[ RUN      ] Stack_Fixture/1.test_4
[       OK ] Stack_Fixture/1.test_4 (0 ms)
[ RUN      ] Stack_Fixture/1.test_5
[       OK ] Stack_Fixture/1.test_5 (0 ms)
[----------] 5 tests from Stack_Fixture/1 (0 ms total)

[----------] 5 tests from Stack_Fixture/2, where TypeParam = std::__1::stack<int, std::__1::vector<int, std::__1::allocator<int> > >
[ RUN      ] Stack_Fixture/2.test_1
[       OK ] Stack_Fixture/2.test_1 (0 ms)
[ RUN      ] Stack_Fixture/2.test_2
[       OK ] Stack_Fixture/2.test_2 (0 ms)
[ RUN      ] Stack_Fixture/2.test_3
[       OK ] Stack_Fixture/2.test_3 (0 ms)
[ RUN      ] Stack_Fixture/2.test_4
[       OK ] Stack_Fixture/2.test_4 (0 ms)
[ RUN      ] Stack_Fixture/2.test_5
[       OK ] Stack_Fixture/2.test_5 (0 ms)
[----------] 5 tests from Stack_Fixture/2 (0 ms total)

[----------] 5 tests from Stack_Fixture/3, where TypeParam = my_stack<int, std::__1::deque<int, std::__1::allocator<int> > >
[ RUN      ] Stack_Fixture/3.test_1
[       OK ] Stack_Fixture/3.test_1 (0 ms)
[ RUN      ] Stack_Fixture/3.test_2
[       OK ] Stack_Fixture/3.test_2 (0 ms)
[ RUN      ] Stack_Fixture/3.test_3
[       OK ] Stack_Fixture/3.test_3 (0 ms)
[ RUN      ] Stack_Fixture/3.test_4
[       OK ] Stack_Fixture/3.test_4 (0 ms)
[ RUN      ] Stack_Fixture/3.test_5
[       OK ] Stack_Fixture/3.test_5 (0 ms)
[----------] 5 tests from Stack_Fixture/3 (0 ms total)

[----------] 5 tests from Stack_Fixture/4, where TypeParam = my_stack<int, std::__1::list<int, std::__1::allocator<int> > >
[ RUN      ] Stack_Fixture/4.test_1
[       OK ] Stack_Fixture/4.test_1 (0 ms)
[ RUN      ] Stack_Fixture/4.test_2
[       OK ] Stack_Fixture/4.test_2 (0 ms)
[ RUN      ] Stack_Fixture/4.test_3
[       OK ] Stack_Fixture/4.test_3 (0 ms)
[ RUN      ] Stack_Fixture/4.test_4
[       OK ] Stack_Fixture/4.test_4 (0 ms)
[ RUN      ] Stack_Fixture/4.test_5
[       OK ] Stack_Fixture/4.test_5 (0 ms)
[----------] 5 tests from Stack_Fixture/4 (0 ms total)

[----------] 5 tests from Stack_Fixture/5, where TypeParam = my_stack<int, std::__1::vector<int, std::__1::allocator<int> > >
[ RUN      ] Stack_Fixture/5.test_1
[       OK ] Stack_Fixture/5.test_1 (0 ms)
[ RUN      ] Stack_Fixture/5.test_2
[       OK ] Stack_Fixture/5.test_2 (0 ms)
[ RUN      ] Stack_Fixture/5.test_3
[       OK ] Stack_Fixture/5.test_3 (0 ms)
[ RUN      ] Stack_Fixture/5.test_4
[       OK ] Stack_Fixture/5.test_4 (0 ms)
[ RUN      ] Stack_Fixture/5.test_5
[       OK ] Stack_Fixture/5.test_5 (0 ms)
[----------] 5 tests from Stack_Fixture/5 (0 ms total)

[----------] Global test environment tear-down
[==========] 30 tests from 6 test cases ran. (0 ms total)
[  PASSED  ] 30 tests.
*/
