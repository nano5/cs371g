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

    initializer_list<int> x = {2, 3, 4};
    assert(x.size() == 3);

    initializer_list<int> y;
    y = {2, 3, 4, 5};
    assert(y.size() == 4);

    assert(equal(begin(x), end(x), begin(y)));

    initializer_list<int> z = x;
    assert(z.size() == 3);

    z = y;
    assert(z.size() == 4);

    cout << "Done." << endl;
    return 0;}
