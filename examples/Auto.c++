// --------
// Auto.c++
// --------

// http://en.cppreference.com/w/cpp/language/auto

#include <cassert>    // assert
#include <functional> // function
#include <iostream>   // cout, endl
#include <map>        // map
#include <utility>    // make_pair, pair
#include <vector>     // vector

int main () {
    using namespace std;
    cout << "Auto.c++" << endl;

    {
    int i;            // uninitialized
    assert(&i == &i);
//  auto j;           // error: declaration of variable 'j' with type 'auto' requires an initializer
    }

    {
    int i = 2;
    assert(i == 2);
    auto j = 2;
    assert(j == 2);
    }

    {
    int i = (2);
    assert(i == 2);
    auto j = {2};
    assert(equal(begin(j), end(j), begin({2})));
    }

    cout << "Done." << endl;
    return 0;}
