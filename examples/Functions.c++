// -------------
// Functions.c++
// -------------

// http://en.cppreference.com/w/cpp/language/lambda
// http://en.cppreference.com/w/cpp/utility/functional/function
// http://www.cplusplus.com/reference/algorithm/transform/
// http://www.cplusplus.com/reference/numeric/accumulate/

#include <algorithm>        // equal, transform
#include <cassert>          // assert
#include <functional>       // function
#include <initializer_list> // initializer_list
#include <iostream>         // cout, endl
#include <numeric>          // accumulate
#include <vector>           // vector

using namespace std;

// typedef int (*UF) (int);
using UF1 = int (*) (int);
// typedef function<int (int)> UF;
using UF2 = function<int (int)>;

// typedef int (*BF) (int, int);
using BF1 = int (*) (int, int);
// typedef function<int (int, int)> BF;
using BF2 = function<int (int, int)>;

struct A {
    int i;

    A (int i) :
            i (i)
        {}

    int my_method (int j) {
        return i + j;}};

struct B {
    int i;

    B (int i) :
            i (i)
        {}

    int operator () (int j) {
        return i + j;}};

// typedef int (A::*BF3) (int);
using BF3 = int (A::*) (int);

int my_function (int i, int j) {
    return i + j;}

BF1 my_lambda () {
    return [] (int i, int j) -> int {return i + j;};}

UF2 my_closure_by_value (int i) {
    return [i] (int j) -> int {return i + j;};}

UF2 my_closure_by_reference (int& i) {
    return [&i] (int j) -> int {return i++ + j;};}

int main () {
    cout << "Functions.c++" << endl;

    {
    BF1  f = my_function;
    BF2  g = my_function;
    auto h = my_function;

    assert(sizeof(f) ==  8);
    assert(sizeof(g) == 48);
    assert(sizeof(h) ==  8);

    assert(my_function(2, 3) == 5);
    assert(          f(2, 3) == 5);
    assert(          g(2, 3) == 5);
    assert(          h(2, 3) == 5);

    const initializer_list<int> x = {2, 3, 4};

    assert(accumulate(begin(x), end(x), 0, my_function) == 9);
    assert(accumulate(begin(x), end(x), 0, f)           == 9);
    assert(accumulate(begin(x), end(x), 0, g)           == 9);
    assert(accumulate(begin(x), end(x), 0, h)           == 9);
    }



    {
    BF1  f = [] (int i, int j) -> int {return i + j;};
    BF2  g = [] (int i, int j) -> int {return i + j;};
    auto h = [] (int i, int j) -> int {return i + j;};

    assert(sizeof(f) ==  8);
    assert(sizeof(g) == 48);
    assert(sizeof(h) ==  1);

    assert([] (int i, int j) -> int {return i + j;}(2, 3) == 5);
    assert(                                       f(2, 3) == 5);
    assert(                                       g(2, 3) == 5);
    assert(                                       h(2, 3) == 5);

    const initializer_list<int> x = {2, 3, 4};

    assert(accumulate(begin(x), end(x), 0, [] (int i, int j) -> int {return i + j;}) == 9);
    assert(accumulate(begin(x), end(x), 0, f)                                        == 9);
    assert(accumulate(begin(x), end(x), 0, g)                                        == 9);
    assert(accumulate(begin(x), end(x), 0, h)                                        == 9);
    }



    {
    BF1  f = my_lambda();
    BF2  g = my_lambda();
    auto h = my_lambda();

    assert(sizeof(f) ==  8);
    assert(sizeof(g) == 48);
    assert(sizeof(h) ==  8);

    assert(my_lambda()(2, 3) == 5);
    assert(          f(2, 3) == 5);
    assert(          g(2, 3) == 5);
    assert(          h(2, 3) == 5);

    const initializer_list<int> x = {2, 3, 4};

    assert(accumulate(begin(x), end(x), 0, my_lambda()) == 9);
    assert(accumulate(begin(x), end(x), 0, f)           == 9);
    assert(accumulate(begin(x), end(x), 0, g)           == 9);
    assert(accumulate(begin(x), end(x), 0, h)           == 9);
    }



    {
    const int i = 2;

//  UF1  f = [i] (int j) -> int {return i + j;}; // error: no viable conversion from '(lambda at Functions.c++:124:14)' to 'UF1' (aka 'int (*)(int)')
    UF2  g = [i] (int j) -> int {return i + j;};
    auto h = [i] (int j) -> int {return i + j;};

    assert(sizeof(g) == 48);
    assert(sizeof(h) ==  4);

    assert([i] (int j) -> int {return i + j;}(3) == 5);
    assert(                                 g(3) == 5);
    assert(                                 h(3) == 5);

    {
    initializer_list<int> x = {2, 3, 4};
    vector<int> y(3);
    transform(begin(x), end(x), begin(y), [i] (int j) -> int {return i + j;});
    assert(equal(begin(y), end(y), begin({4, 5, 6})));
    }
    {
    initializer_list<int> x = {2, 3, 4};
    vector<int> y(3);
    transform(begin(x), end(x), begin(y), g);
    assert(equal(begin(y), end(y), begin({4, 5, 6})));
    }
    {
    initializer_list<int> x = {2, 3, 4};
    vector<int> y(3);
    transform(begin(x), end(x), begin(y), h);
    assert(equal(begin(y), end(y), begin({4, 5, 6})));
    }
    }



    {
//  UF1  f = my_closure_by_value(2); // error: no viable conversion from 'UF2' (aka 'function<int (int)>') to 'UF1' (aka 'int (*)(int)')
    UF2  g = my_closure_by_value(2);
    auto h = my_closure_by_value(2);

    assert(sizeof(g) == 48);
    assert(sizeof(h) == 48);

    assert(my_closure_by_value(2)(3) == 5);
    assert(                     g(3) == 5);
    assert(                     h(3) == 5);

    {
    initializer_list<int> x = {2, 3, 4};
    vector<int> y(3);
    transform(begin(x), end(x), begin(y), my_closure_by_value(2));
    assert(equal(begin(y), end(y), begin({4, 5, 6})));
    }
    {
    initializer_list<int> x = {2, 3, 4};
    vector<int> y(3);
    transform(begin(x), end(x), begin(y), g);
    assert(equal(begin(y), end(y), begin({4, 5, 6})));
    }
    {
    initializer_list<int> x = {2, 3, 4};
    vector<int> y(3);
    transform(begin(x), end(x), begin(y), h);
    assert(equal(begin(y), end(y), begin({4, 5, 6})));
    }
    }



    {
    int i = 2;

//  UF1  f = [&i] (int j) -> int {return i++ + j;}; // error: no viable conversion from '(lambda at Functions.c++:196:14)' to 'UF1' (aka 'int (*)(int)')
    UF2  g = [&i] (int j) -> int {return i++ + j;};
    auto h = [&i] (int j) -> int {return i++ + j;};

    assert(sizeof(g) == 48);
    assert(sizeof(h) ==  8);

    assert([&i] (int j) -> int {return i++ + j;}(3) == 5);
    assert(                                    g(3) == 6);
    assert(                                    h(3) == 7);

    assert(i == 5);

    {
    initializer_list<int> x = {2, 3, 4};
    vector<int> y(3);
    transform(begin(x), end(x), begin(y), [&i] (int j) -> int {return i++ + j;});
    assert(i == 8);
    assert(equal(begin(y), end(y), begin({7, 9, 11})));
    }
    {
    initializer_list<int> x = {2, 3, 4};
    vector<int> y(3);
    transform(begin(x), end(x), begin(y), g);
    assert(i == 11);
    assert(equal(begin(y), end(y), begin({10, 12, 14})));
    }
    {
    initializer_list<int> x = {2, 3, 4};
    vector<int> y(3);
    transform(begin(x), end(x), begin(y), h);
    assert(i == 14);
    assert(equal(begin(y), end(y), begin({13, 15, 17})));
    }
    }



    {
    int i = 2;

//  UF1  f = my_closure_by_reference(i); // error: no viable conversion from 'UF2' (aka 'function<int (int)>') to 'UF1' (aka 'int (*)(int)')
    UF2  g = my_closure_by_reference(i);
    auto h = my_closure_by_reference(i);

    assert(sizeof(g) == 48);
    assert(sizeof(h) == 48);

    assert(my_closure_by_reference(i)(3) == 5);
    assert(                         g(3) == 6);
    assert(                         h(3) == 7);

    assert(i == 5);

    {
    initializer_list<int> x = {2, 3, 4};
    vector<int> y(3);
    transform(begin(x), end(x), begin(y), my_closure_by_reference(i));
    assert(i == 8);
    assert(equal(begin(y), end(y), begin({7, 9, 11})));
    }
    {
    initializer_list<int> x = {2, 3, 4};
    vector<int> y(3);
    transform(begin(x), end(x), begin(y), g);
    assert(i == 11);
    assert(equal(begin(y), end(y), begin({10, 12, 14})));
    }
    {
    initializer_list<int> x = {2, 3, 4};
    vector<int> y(3);
    transform(begin(x), end(x), begin(y), h);
    assert(i == 14);
    assert(equal(begin(y), end(y), begin({13, 15, 17})));
    }
    }



    {
    BF3  f = &A::my_method;
    auto g = &A::my_method;

    assert(sizeof(f) == 16);
    assert(sizeof(g) == 16);

    A x = 2;
    assert(sizeof(x) == 4);

    assert(x.my_method(3) == 5);
    assert(     (x.*f)(3) == 5);
    }



    {
    B    f = 2;
    auto g = B(2);

    assert(sizeof(f) == 4);
    assert(sizeof(g) == 4);

    assert(B(2)(3) == 5);
    assert(   f(3) == 5);
    assert(   g(3) == 5);
    }

    cout << "Done." << endl;
    return 0;}
