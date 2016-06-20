// -----------
// Lambdas.c++
// -----------

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

int main () {
    cout << "Lambdas.c++" << endl;

    {
    BF   f = my_function;
    auto g = my_function;

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

    assert([] (int i, int j) -> int {return i + j;}(2, 3) == 5);
    assert(                                       f(2, 3) == 5);
    assert(                                       g(2, 3) == 5);

    const initializer_list<int> x = {2, 3, 4};

    assert(accumulate(begin(x), end(x), 0, [] (int i, int j) -> int {return i + j;}) == 9);
    assert(accumulate(begin(x), end(x), 0, f)                                        == 9);
    assert(accumulate(begin(x), end(x), 0, g)                                        == 9);
    }



    {
    BF   f = my_lambda();
    auto g = my_lambda();

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

    UF   f = [i] (int j) -> int {return i + j;};
    auto g = [i] (int j) -> int {return i + j;};

    assert([i] (int j) -> int {return i + j;}(3) == 5);
    assert(                                 f(3) == 5);
    assert(                                 g(3) == 5);

    {
    initializer_list<int>   x = {2, 3, 4};
    vector<int> y(3);
    initializer_list<int>   z = {4, 5, 6};
    transform(begin(x), end(x), begin(y), [i] (int j) -> int {return i + j;});
    assert(equal(begin(y), end(y), begin(z)));
    }
    {
    initializer_list<int>   x = {2, 3, 4};
    vector<int> y(3);
    initializer_list<int>   z = {4, 5, 6};
    transform(begin(x), end(x), begin(y), f);
    assert(equal(begin(y), end(y), begin(z)));
    }
    {
    initializer_list<int>   x = {2, 3, 4};
    vector<int> y(3);
    initializer_list<int>   z = {4, 5, 6};
    transform(begin(x), end(x), begin(y), g);
    assert(equal(begin(y), end(y), begin(z)));
    }
    }



    {
    int i = 2;

    UF   f = my_closure_by_value(i);
    auto g = my_closure_by_value(i);

    assert(my_closure_by_value(i)(3) == 5);
    assert(                     f(3) == 5);
    assert(                     g(3) == 5);

    {
    initializer_list<int>   x = {2, 3, 4};
    vector<int> y(3);
    initializer_list<int>   z = {4, 5, 6};
    transform(begin(x), end(x), begin(y), my_closure_by_value(i));
    assert(equal(begin(y), end(y), begin(z)));
    }
    {
    initializer_list<int>   x = {2, 3, 4};
    vector<int> y(3);
    initializer_list<int>   z = {4, 5, 6};
    transform(begin(x), end(x), begin(y), f);
    assert(equal(begin(y), end(y), begin(z)));
    }
    {
    initializer_list<int>   x = {2, 3, 4};
    vector<int> y(3);
    initializer_list<int>   z = {4, 5, 6};
    transform(begin(x), end(x), begin(y), g);
    assert(equal(begin(y), end(y), begin(z)));
    }
    }



    {
    int i = 2;

    UF   f = [&i] (int j) -> int {return i++ + j;};
    auto g = [&i] (int j) -> int {return i++ + j;};

    assert([&i] (int j) -> int {return i++ + j;}(3) == 5);
    assert(                                    f(3) == 6);
    assert(                                    g(3) == 7);

    assert(i == 5);

    {
    initializer_list<int>   x = {2, 3, 4};
    vector<int> y(3);
    initializer_list<int>   z = {7, 9, 11};
    transform(begin(x), end(x), begin(y), [&i] (int j) -> int {return i++ + j;});
    assert(i == 8);
    assert(equal(begin(y), end(y), begin(z)));
    }
    {
    initializer_list<int>   x = {2, 3, 4};
    vector<int> y(3);
    initializer_list<int>   z = {10, 12, 14};
    transform(begin(x), end(x), begin(y), f);
    assert(i == 11);
    assert(equal(begin(y), end(y), begin(z)));
    }
    {
    initializer_list<int>   x = {2, 3, 4};
    vector<int> y(3);
    initializer_list<int>   z = {13, 15, 17};
    transform(begin(x), end(x), begin(y), g);
    assert(i == 14);
    assert(equal(begin(y), end(y), begin(z)));
    }
    }



    {
    int i = 2;

    UF   f = my_closure_by_reference(i);
    auto g = my_closure_by_reference(i);

    assert(my_closure_by_reference(i)(3) == 5);
    assert(                         f(3) == 6);
    assert(                         g(3) == 7);

    assert(i == 5);

    {
    initializer_list<int>   x = {2, 3, 4};
    vector<int> y(3);
    initializer_list<int>   z = {7, 9, 11};
    transform(begin(x), end(x), begin(y), my_closure_by_reference(i));
    assert(i == 8);
    assert(equal(begin(y), end(y), begin(z)));
    }
    {
    initializer_list<int>   x = {2, 3, 4};
    vector<int> y(3);
    initializer_list<int>   z = {10, 12, 14};
    transform(begin(x), end(x), begin(y), f);
    assert(i == 11);
    assert(equal(begin(y), end(y), begin(z)));
    }
    {
    initializer_list<int>   x = {2, 3, 4};
    vector<int> y(3);
    initializer_list<int>   z = {13, 15, 17};
    transform(begin(x), end(x), begin(y), g);
    assert(i == 14);
    assert(equal(begin(y), end(y), begin(z)));
    }
    }

    cout << "Done." << endl;
    return 0;}
