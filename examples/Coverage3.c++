// -------------
// Coverage3.c++
// -------------

// http://gcc.gnu.org/onlinedocs/gcc/Gcov.html

#include <cassert>  // assert
#include <iostream> // cout, endl

#include "gtest/gtest.h"

int cycle_length (int n) {
    assert(n > 0);
    int c = 1;
    while (n > 1) {
        if ((n % 2) == 0)
            n = (n / 2);
        else
            n = (3 * n) + 1;
        ++c;}
    assert(c > 0);
    return c;}

TEST(CoverageFixture, test) {
    ASSERT_EQ(cycle_length(3), 8);}

/*
% g++ -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall Coverage3.c++ -o Coverage3 -lgtest -lgtest_main -pthread



% Coverage3
Running main() from gtest_main.cc
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from CoverageFixture
[ RUN      ] CoverageFixture.test
[       OK ] CoverageFixture.test (0 ms)
[----------] 1 test from CoverageFixture (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (0 ms total)
[  PASSED  ] 1 test.



% gcov -b Coverage3.c++ | grep -A 5 "File 'Coverage3.c++'"
File 'Coverage3.c++'
Lines executed:100.00% of 12
Branches executed:71.43% of 28
Taken at least once:42.86% of 28
Calls executed:52.00% of 25
Creating 'Coverage3.c++.gcov'


% g++ -pg -pedantic -std=c++11 -Wall Coverage3.c++ -o Coverage3 -lgtest -lgtest_main -pthread



% Coverage3
Running main() from gtest_main.cc
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from CoverageFixture
[ RUN      ] CoverageFixture.test
[       OK ] CoverageFixture.test (0 ms)
[----------] 1 test from CoverageFixture (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (0 ms total)
[  PASSED  ] 1 test.



% gprof Coverage3
Flat profile:

Each sample counts as 0.01 seconds.
 no time accumulated

  %   cumulative   self              self     total
 time   seconds   seconds    calls  Ts/call  Ts/call  name
  0.00      0.00     0.00        1     0.00     0.00  _GLOBAL__sub_I__Z12cycle_lengthi
  0.00      0.00     0.00        1     0.00     0.00  cycle_length(int)
  0.00      0.00     0.00        1     0.00     0.00  __static_initialization_and_destruction_0(int, int)
  0.00      0.00     0.00        1     0.00     0.00  CoverageFixture_test_Test::TestBody()
  0.00      0.00     0.00        1     0.00     0.00  CoverageFixture_test_Test::CoverageFixture_test_Test()
  0.00      0.00     0.00        1     0.00     0.00  CoverageFixture_test_Test::~CoverageFixture_test_Test()
  0.00      0.00     0.00        1     0.00     0.00  CoverageFixture_test_Test::~CoverageFixture_test_Test()
  0.00      0.00     0.00        1     0.00     0.00  testing::AssertionResult::~AssertionResult()
  0.00      0.00     0.00        1     0.00     0.00  testing::Test::SetUpTestCase()
  0.00      0.00     0.00        1     0.00     0.00  testing::Test::TearDownTestCase()
  0.00      0.00     0.00        1     0.00     0.00  testing::internal::scoped_ptr<std::string>::reset(std::string*)
  0.00      0.00     0.00        1     0.00     0.00  testing::internal::scoped_ptr<std::string>::~scoped_ptr()
  0.00      0.00     0.00        1     0.00     0.00  testing::AssertionResult testing::internal::CmpHelperEQ<int, int>(char const*, char const*, int const&, int const&)
  0.00      0.00     0.00        1     0.00     0.00  testing::internal::TestFactoryBase::TestFactoryBase()
  0.00      0.00     0.00        1     0.00     0.00  testing::internal::TestFactoryBase::~TestFactoryBase()
  0.00      0.00     0.00        1     0.00     0.00  testing::internal::TestFactoryImpl<CoverageFixture_test_Test>::CreateTest()
  0.00      0.00     0.00        1     0.00     0.00  testing::internal::TestFactoryImpl<CoverageFixture_test_Test>::TestFactoryImpl()
  0.00      0.00     0.00        1     0.00     0.00  testing::internal::TestFactoryImpl<CoverageFixture_test_Test>::~TestFactoryImpl()
  0.00      0.00     0.00        1     0.00     0.00  testing::internal::TestFactoryImpl<CoverageFixture_test_Test>::~TestFactoryImpl()
  0.00      0.00     0.00        1     0.00     0.00  testing::AssertionResult testing::internal::EqHelper<false>::Compare<int, int>(char const*, char const*, int const&, int const&)
  0.00      0.00     0.00        1     0.00     0.00  testing::AssertionResult::operator bool() const

 %         the percentage of the total running time of the
time       program used by this function.

cumulative a running sum of the number of seconds accounted
 seconds   for by this function and those listed above it.

 self      the number of seconds accounted for by this
seconds    function alone.  This is the major sort for this
           listing.

calls      the number of times this function was invoked, if
           this function is profiled, else blank.

 self      the average number of milliseconds spent in this
ms/call    function per call, if this function is profiled,
	   else blank.

 total     the average number of milliseconds spent in this
ms/call    function and its descendents per call, if this
	   function is profiled, else blank.

name       the name of the function.  This is the minor sort
           for this listing. The index shows the location of
	   the function in the gprof listing. If the index is
	   in parenthesis it shows where it would appear in
	   the gprof listing if it were to be printed.


Copyright (C) 2012 Free Software Foundation, Inc.

Copying and distribution of this file, with or without modification,
are permitted in any medium without royalty provided the copyright
notice and this notice are preserved.


		     Call graph (explanation follows)


granularity: each sample hit covers 2 byte(s) no time propagated

index % time    self  children    called     name
                0.00    0.00       1/1           __libc_csu_init [583]
[9]      0.0    0.00    0.00       1         _GLOBAL__sub_I__Z12cycle_lengthi [9]
                0.00    0.00       1/1           __static_initialization_and_destruction_0(int, int) [11]
-----------------------------------------------
                0.00    0.00       1/1           CoverageFixture_test_Test::TestBody() [12]
[10]     0.0    0.00    0.00       1         cycle_length(int) [10]
-----------------------------------------------
                0.00    0.00       1/1           _GLOBAL__sub_I__Z12cycle_lengthi [9]
[11]     0.0    0.00    0.00       1         __static_initialization_and_destruction_0(int, int) [11]
                0.00    0.00       1/1           testing::internal::TestFactoryImpl<CoverageFixture_test_Test>::TestFactoryImpl() [25]
-----------------------------------------------
                0.00    0.00       1/1           void testing::internal::HandleExceptionsInMethodIfSupported<testing::Test, void>(testing::Test*, void (testing::Test::*)(), char const*) [416]
[12]     0.0    0.00    0.00       1         CoverageFixture_test_Test::TestBody() [12]
                0.00    0.00       1/1           cycle_length(int) [10]
                0.00    0.00       1/1           testing::AssertionResult testing::internal::EqHelper<false>::Compare<int, int>(char const*, char const*, int const&, int const&) [28]
                0.00    0.00       1/1           testing::AssertionResult::operator bool() const [29]
                0.00    0.00       1/1           testing::AssertionResult::~AssertionResult() [16]
-----------------------------------------------
                0.00    0.00       1/1           testing::internal::TestFactoryImpl<CoverageFixture_test_Test>::CreateTest() [24]
[13]     0.0    0.00    0.00       1         CoverageFixture_test_Test::CoverageFixture_test_Test() [13]
-----------------------------------------------
                0.00    0.00       1/1           void testing::internal::HandleExceptionsInMethodIfSupported<testing::Test, void>(testing::Test*, void (testing::Test::*)(), char const*) [416]
[14]     0.0    0.00    0.00       1         CoverageFixture_test_Test::~CoverageFixture_test_Test() [14]
                0.00    0.00       1/1           CoverageFixture_test_Test::~CoverageFixture_test_Test() [15]
-----------------------------------------------
                0.00    0.00       1/1           CoverageFixture_test_Test::~CoverageFixture_test_Test() [14]
[15]     0.0    0.00    0.00       1         CoverageFixture_test_Test::~CoverageFixture_test_Test() [15]
-----------------------------------------------
                0.00    0.00       1/1           CoverageFixture_test_Test::TestBody() [12]
[16]     0.0    0.00    0.00       1         testing::AssertionResult::~AssertionResult() [16]
                0.00    0.00       1/1           testing::internal::scoped_ptr<std::string>::~scoped_ptr() [20]
-----------------------------------------------
                0.00    0.00       1/1           void testing::internal::HandleExceptionsInMethodIfSupported<testing::TestCase, void>(testing::TestCase*, void (testing::TestCase::*)(), char const*) [417]
[17]     0.0    0.00    0.00       1         testing::Test::SetUpTestCase() [17]
-----------------------------------------------
                0.00    0.00       1/1           void testing::internal::HandleExceptionsInMethodIfSupported<testing::TestCase, void>(testing::TestCase*, void (testing::TestCase::*)(), char const*) [417]
[18]     0.0    0.00    0.00       1         testing::Test::TearDownTestCase() [18]
-----------------------------------------------
                0.00    0.00       1/1           testing::internal::scoped_ptr<std::string>::~scoped_ptr() [20]
[19]     0.0    0.00    0.00       1         testing::internal::scoped_ptr<std::string>::reset(std::string*) [19]
-----------------------------------------------
                0.00    0.00       1/1           testing::AssertionResult::~AssertionResult() [16]
[20]     0.0    0.00    0.00       1         testing::internal::scoped_ptr<std::string>::~scoped_ptr() [20]
                0.00    0.00       1/1           testing::internal::scoped_ptr<std::string>::reset(std::string*) [19]
-----------------------------------------------
                0.00    0.00       1/1           testing::AssertionResult testing::internal::EqHelper<false>::Compare<int, int>(char const*, char const*, int const&, int const&) [28]
[21]     0.0    0.00    0.00       1         testing::AssertionResult testing::internal::CmpHelperEQ<int, int>(char const*, char const*, int const&, int const&) [21]
-----------------------------------------------
                0.00    0.00       1/1           testing::internal::TestFactoryImpl<CoverageFixture_test_Test>::TestFactoryImpl() [25]
[22]     0.0    0.00    0.00       1         testing::internal::TestFactoryBase::TestFactoryBase() [22]
-----------------------------------------------
                0.00    0.00       1/1           testing::internal::TestFactoryImpl<CoverageFixture_test_Test>::~TestFactoryImpl() [27]
[23]     0.0    0.00    0.00       1         testing::internal::TestFactoryBase::~TestFactoryBase() [23]
-----------------------------------------------
                0.00    0.00       1/1           testing::Test* testing::internal::HandleExceptionsInMethodIfSupported<testing::internal::TestFactoryBase, testing::Test*>(testing::internal::TestFactoryBase*, testing::Test* (testing::internal::TestFactoryBase::*)(), char const*) [415]
[24]     0.0    0.00    0.00       1         testing::internal::TestFactoryImpl<CoverageFixture_test_Test>::CreateTest() [24]
                0.00    0.00       1/1           CoverageFixture_test_Test::CoverageFixture_test_Test() [13]
-----------------------------------------------
                0.00    0.00       1/1           __static_initialization_and_destruction_0(int, int) [11]
[25]     0.0    0.00    0.00       1         testing::internal::TestFactoryImpl<CoverageFixture_test_Test>::TestFactoryImpl() [25]
                0.00    0.00       1/1           testing::internal::TestFactoryBase::TestFactoryBase() [22]
-----------------------------------------------
                0.00    0.00       1/1           testing::TestInfo::~TestInfo() [151]
[26]     0.0    0.00    0.00       1         testing::internal::TestFactoryImpl<CoverageFixture_test_Test>::~TestFactoryImpl() [26]
                0.00    0.00       1/1           testing::internal::TestFactoryImpl<CoverageFixture_test_Test>::~TestFactoryImpl() [27]
-----------------------------------------------
                0.00    0.00       1/1           testing::internal::TestFactoryImpl<CoverageFixture_test_Test>::~TestFactoryImpl() [26]
[27]     0.0    0.00    0.00       1         testing::internal::TestFactoryImpl<CoverageFixture_test_Test>::~TestFactoryImpl() [27]
                0.00    0.00       1/1           testing::internal::TestFactoryBase::~TestFactoryBase() [23]
-----------------------------------------------
                0.00    0.00       1/1           CoverageFixture_test_Test::TestBody() [12]
[28]     0.0    0.00    0.00       1         testing::AssertionResult testing::internal::EqHelper<false>::Compare<int, int>(char const*, char const*, int const&, int const&) [28]
                0.00    0.00       1/1           testing::AssertionResult testing::internal::CmpHelperEQ<int, int>(char const*, char const*, int const&, int const&) [21]
-----------------------------------------------
                0.00    0.00       1/1           CoverageFixture_test_Test::TestBody() [12]
[29]     0.0    0.00    0.00       1         testing::AssertionResult::operator bool() const [29]
-----------------------------------------------

 This table describes the call tree of the program, and was sorted by
 the total amount of time spent in each function and its children.

 Each entry in this table consists of several lines.  The line with the
 index number at the left hand margin lists the current function.
 The lines above it list the functions that called this function,
 and the lines below it list the functions this one called.
 This line lists:
     index	A unique number given to each element of the table.
		Index numbers are sorted numerically.
		The index number is printed next to every function name so
		it is easier to look up where the function is in the table.

     % time	This is the percentage of the `total' time that was spent
		in this function and its children.  Note that due to
		different viewpoints, functions excluded by options, etc,
		these numbers will NOT add up to 100%.

     self	This is the total amount of time spent in this function.

     children	This is the total amount of time propagated into this
		function by its children.

     called	This is the number of times the function was called.
		If the function called itself recursively, the number
		only includes non-recursive calls, and is followed by
		a `+' and the number of recursive calls.

     name	The name of the current function.  The index number is
		printed after it.  If the function is a member of a
		cycle, the cycle number is printed between the
		function's name and the index number.


 For the function's parents, the fields have the following meanings:

     self	This is the amount of time that was propagated directly
		from the function into this parent.

     children	This is the amount of time that was propagated from
		the function's children into this parent.

     called	This is the number of times this parent called the
		function `/' the total number of times the function
		was called.  Recursive calls to the function are not
		included in the number after the `/'.

     name	This is the name of the parent.  The parent's index
		number is printed after it.  If the parent is a
		member of a cycle, the cycle number is printed between
		the name and the index number.

 If the parents of the function cannot be determined, the word
 `<spontaneous>' is printed in the `name' field, and all the other
 fields are blank.

 For the function's children, the fields have the following meanings:

     self	This is the amount of time that was propagated directly
		from the child into the function.

     children	This is the amount of time that was propagated from the
		child's children to the function.

     called	This is the number of times the function called
		this child `/' the total number of times the child
		was called.  Recursive calls by the child are not
		listed in the number after the `/'.

     name	This is the name of the child.  The child's index
		number is printed after it.  If the child is a
		member of a cycle, the cycle number is printed
		between the name and the index number.

 If there are any cycles (circles) in the call graph, there is an
 entry for the cycle-as-a-whole.  This entry shows who called the
 cycle (as parents) and the members of the cycle (as children.)
 The `+' recursive calls entry shows the number of function calls that
 were internal to the cycle, and the calls entry for each member shows,
 for that member, how many times it was called from other members of
 the cycle.


Copyright (C) 2012 Free Software Foundation, Inc.

Copying and distribution of this file, with or without modification,
are permitted in any medium without royalty provided the copyright
notice and this notice are preserved.


Index by function name

   [9] _GLOBAL__sub_I__Z12cycle_lengthi [16] testing::AssertionResult::~AssertionResult() [23] testing::internal::TestFactoryBase::~TestFactoryBase()
  [10] cycle_length(int)      [17] testing::Test::SetUpTestCase() [24] testing::internal::TestFactoryImpl<CoverageFixture_test_Test>::CreateTest()
  [11] __static_initialization_and_destruction_0(int, int) [18] testing::Test::TearDownTestCase() [25] testing::internal::TestFactoryImpl<CoverageFixture_test_Test>::TestFactoryImpl()
  [12] CoverageFixture_test_Test::TestBody() [19] testing::internal::scoped_ptr<std::string>::reset(std::string*) [26] testing::internal::TestFactoryImpl<CoverageFixture_test_Test>::~TestFactoryImpl()
  [13] CoverageFixture_test_Test::CoverageFixture_test_Test() [20] testing::internal::scoped_ptr<std::string>::~scoped_ptr() [27] testing::internal::TestFactoryImpl<CoverageFixture_test_Test>::~TestFactoryImpl()
  [14] CoverageFixture_test_Test::~CoverageFixture_test_Test() [21] testing::AssertionResult testing::internal::CmpHelperEQ<int, int>(char const*, char const*, int const&, int const&) [28] testing::AssertionResult testing::internal::EqHelper<false>::Compare<int, int>(char const*, char const*, int const&, int const&)
  [15] CoverageFixture_test_Test::~CoverageFixture_test_Test() [22] testing::internal::TestFactoryBase::TestFactoryBase() [29] testing::AssertionResult::operator bool() const
*/
