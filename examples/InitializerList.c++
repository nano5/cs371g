// -------------------
// InitializerList.c++
// -------------------

// http://en.cppreference.com/w/cpp/utility/initializer_list

#include <algorithm>        // equal
#include <cassert>          // assert
#include <initializer_list> // initializer_list
#include <iostream>         // cout, endl

int main () {
    using namespace std;
    cout << "InitializerList.c++" << endl;

    {
    initializer_list<int> x;
    assert(x.size() == 0);
    }

    {
    initializer_list<int> x = {};
    assert(x.size() == 0);
    }

    {
    initializer_list<int> x = {2};
    assert(x.size() == 1);
    }

    {
    initializer_list<int> x = {2, 3};
    assert(x.size() == 2);
    }

    {
    initializer_list<int> x = {2, 3, 4};
    assert(x.size() == 3);
    }

    {
    initializer_list<int> x;
    x = {2, 3, 4};
    assert(x.size() == 3);
    }

    {
    initializer_list<int> x = {2, 3, 4};
    assert(x.size() == 3);
    initializer_list<int> y = x;
    assert(y.size() == 3);
    assert(equal(begin(x), end(x), begin(y)));
    }

    {
    initializer_list<int> x = {2, 3, 4};
    assert(x.size() == 3);
    initializer_list<int> y = {5, 6};
    assert(y.size() == 2);
    x = y;
    assert(x.size() == 2);
    assert(equal(begin(x), end(x), begin(y)));
    }

    cout << "Done." << endl;
    return 0;}
