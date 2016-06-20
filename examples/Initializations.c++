// -------------------
// Initializations.c++
// -------------------

// http://en.cppreference.com/w/cpp/language/value_initialization
// http://en.cppreference.com/w/cpp/language/initializer_list
// http://en.cppreference.com/w/cpp/utility/initializer_list

#include <cassert>          // assert
#include <initializer_list> // initializer_list
#include <iostream>         // cout, endl
#include <vector>           // vector

using namespace std;

struct A {
    A (int)
        {}};

struct B {
    explicit B (int)
        {}};

struct C {
    C (initializer_list<int> l)
        {}};

struct D {
    D (int)
        {}

    D (initializer_list<int> l)
        {}};

int main () {
    cout << "Initializations.c++" << endl;

    {
    int i = 2.0;
    assert(i == 2);
    int j(3.0);
    assert(j == 3);
//  int k{4.0};     // error: type 'double' cannot be narrowed to 'int' in initializer list [-Wc++11-narrowing]
//  int m = {5.0};  // error: type 'double' cannot be narrowed to 'int' in initializer list [-Wc++11-narrowing]
    }

    {
    A x(2);
    assert(&x == &x);
    A y = 2;
    assert(&y == &y);
    A z{2};
    assert(&z == &z);
    A t = {2};
    assert(&t == &t);
    }

    {
    B x(2);
    assert(&x == &x);
//  B y = 2;          // error: no viable conversion from 'int' to 'B'
    B z{2};
    assert(&z == &z);
//  B t = {2};        // error: chosen constructor is explicit in copy-initialization
    }

    {
//  C x(2);           // error: no matching constructor for initialization of 'C'
//  C y = 2;          // error: no viable conversion from 'int' to 'C'
    C z{2};
    assert(&z == &z);
    C t = {2};
    assert(&t == &t);
    }

    {
    D x(2);
    assert(&x == &x);
    D y = 2;
    assert(&y == &y);
    D z{2};
    assert(&z == &z);
    D t = {2};
    assert(&t == &t);
    }

    {
    vector<int> x(2);
    assert(x.size() == 2);
    assert(x[0]     == 0);
    assert(x[1]     == 0);
//  vector<int> y = 2;     // error: no viable conversion from 'int' to 'vector<int>'
    vector<int> z{2};
    assert(z.size() == 1);
    assert(z[0]     == 2);
    vector<int> t = {2};
    assert(t.size() == 1);
    assert(t[0]     == 2);
    vector<int> u{2, 3, 4};
    assert(u.size() == 3);
    assert(u[0]     == 2);
    assert(u[1]     == 3);
    assert(u[2]     == 4);
    }

    cout << "Done." << endl;
    return 0;}
