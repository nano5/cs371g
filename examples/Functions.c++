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
// using UF = int (*) (int);
// typedef function<int (int)> UF;
using UF = function<int (int)>;

// typedef int (*BF) (int, int);
// using BF = int (*) (int, int);
// typedef function<int (int, int)> BF;
using BF = function<int (int, int)>;

int my_function (int i, int j) {
    return i + j;}

BF my_lambda () {
    return [] (int i, int j) -> int {return i + j;};}

UF my_closure_by_value (int& i) {
    return [i] (int j) -> int {return i + j;};}

UF my_closure_by_reference (int& i) {
    return [&i] (int j) -> int {return i++ + j;};}

struct my_struct {
    int operator () (int i, int j) {
        return i + j;}};

int main () {
    cout << "Functions.c++" << endl;

    {
    BF   f = my_function;
    auto g = my_function;

    assert(sizeof(f) == 48);
    assert(sizeof(g) ==  8);

    assert(my_function(2, 3) == 5);
    assert(          f(2, 3) == 5);
    assert(          g(2, 3) == 5);

    const initializer_list<int> x = {2, 3, 4};

    assert(accumulate(begin(x), end(x), 0, my_function) == 9);
    assert(accumulate(begin(x), end(x), 0, f)           == 9);
    assert(accumulate(begin(x), end(x), 0, g)           == 9);
    }



    {
    BF   f = [] (int i, int j) -> int {return i + j;};
    auto g = [] (int i, int j) -> int {return i + j;};

    assert(sizeof(f) == 48);
    assert(sizeof(g) ==  1);

    assert([] (int i, int j) -> int {return i + j;}(2, 3) == 5);
    assert(                                       f(2, 3) == 5);
    assert(                                       g(2, 3) == 5);

    const initializer_list<int> x = {2, 3, 4};

    assert(accumulate(begin(x), end(x), 0, [] (int i, int j) -> int {return i + j;}) == 9);
    assert(accumulate(begin(x), end(x), 0, f)                                        == 9);
    assert(accumulate(begin(x), end(x), 0, g)                                        == 9);
    }



    {
    BF   f = my_struct();
    auto g = my_struct();

    assert(sizeof(f) == 48);
    assert(sizeof(g) ==  1);

    assert(my_struct()(2, 3) == 5);
    assert(          f(2, 3) == 5);
    assert(          g(2, 3) == 5);

    const initializer_list<int> x = {2, 3, 4};

    assert(accumulate(begin(x), end(x), 0, [] (int i, int j) -> int {return i + j;}) == 9);
    assert(accumulate(begin(x), end(x), 0, f)                                        == 9);
    assert(accumulate(begin(x), end(x), 0, g)                                        == 9);
    }



    {
    int i = 2;

    UF   f = [i] (int j) -> int {return i + j;};
    auto g = [i] (int j) -> int {return i + j;};

    assert(sizeof(f) == 48);
    assert(sizeof(g) ==  4);

    assert([i] (int j) -> int {return i + j;}(3) == 5);
    assert(                                 f(3) == 5);
    assert(                                 g(3) == 5);

    {
    initializer_list<int> x = {2, 3, 4};
    vector<int> y(3);
    transform(begin(x), end(x), begin(y), [i] (int j) -> int {return i + j;});
    assert(equal(begin(y), end(y), begin({4, 5, 6})));
    }
    {
    initializer_list<int> x = {2, 3, 4};
    vector<int> y(3);
    transform(begin(x), end(x), begin(y), f);
    assert(equal(begin(y), end(y), begin({4, 5, 6})));
    }
    {
    initializer_list<int> x = {2, 3, 4};
    vector<int> y(3);
    transform(begin(x), end(x), begin(y), g);
    assert(equal(begin(y), end(y), begin({4, 5, 6})));
    }
    }



    {
    int i = 2;

    UF   f = [&i] (int j) -> int {return i++ + j;};
    auto g = [&i] (int j) -> int {return i++ + j;};

    assert(sizeof(f) == 48);
    assert(sizeof(g) ==  8);

    assert([&i] (int j) -> int {return i++ + j;}(3) == 5);
    assert(                                    f(3) == 6);
    assert(                                    g(3) == 7);

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
    transform(begin(x), end(x), begin(y), f);
    assert(i == 11);
    assert(equal(begin(y), end(y), begin({10, 12, 14})));
    }
    {
    initializer_list<int> x = {2, 3, 4};
    vector<int> y(3);
    transform(begin(x), end(x), begin(y), g);
    assert(i == 14);
    assert(equal(begin(y), end(y), begin({13, 15, 17})));
    }
    }



    {
    BF   f = my_lambda();
    auto g = my_lambda();

    assert(sizeof(f) == 48);
    assert(sizeof(g) == 48);

    assert(my_lambda()(2, 3) == 5);
    assert(          f(2, 3) == 5);
    assert(          g(2, 3) == 5);

    const initializer_list<int> x = {2, 3, 4};

    assert(accumulate(begin(x), end(x), 0, my_lambda()) == 9);
    assert(accumulate(begin(x), end(x), 0, f)           == 9);
    assert(accumulate(begin(x), end(x), 0, g)           == 9);
    }



    {
    int i = 2;

    UF   f = my_closure_by_value(i);
    auto g = my_closure_by_value(i);

    assert(sizeof(f) == 48);
    assert(sizeof(g) == 48);

    assert(my_closure_by_value(i)(3) == 5);
    assert(                     f(3) == 5);
    assert(                     g(3) == 5);

    {
    initializer_list<int> x = {2, 3, 4};
    vector<int> y(3);
    transform(begin(x), end(x), begin(y), my_closure_by_value(i));
    assert(equal(begin(y), end(y), begin({4, 5, 6})));
    }
    {
    initializer_list<int> x = {2, 3, 4};
    vector<int> y(3);
    transform(begin(x), end(x), begin(y), f);
    assert(equal(begin(y), end(y), begin({4, 5, 6})));
    }
    {
    initializer_list<int> x = {2, 3, 4};
    vector<int> y(3);
    transform(begin(x), end(x), begin(y), g);
    assert(equal(begin(y), end(y), begin({4, 5, 6})));
    }
    }



    {
    int i = 2;

    UF   f = my_closure_by_reference(i);
    auto g = my_closure_by_reference(i);

    assert(sizeof(f) == 48);
    assert(sizeof(g) == 48);

    assert(my_closure_by_reference(i)(3) == 5);
    assert(                         f(3) == 6);
    assert(                         g(3) == 7);

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
    transform(begin(x), end(x), begin(y), f);
    assert(i == 11);
    assert(equal(begin(y), end(y), begin({10, 12, 14})));
    }
    {
    initializer_list<int> x = {2, 3, 4};
    vector<int> y(3);
    transform(begin(x), end(x), begin(y), g);
    assert(i == 14);
    assert(equal(begin(y), end(y), begin({13, 15, 17})));
    }
    }

    cout << "Done." << endl;
    return 0;}
