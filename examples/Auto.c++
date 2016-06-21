// --------
// Auto.c++
// --------

// http://en.cppreference.com/w/cpp/language/auto

#include <cassert>  // assert
#include <iostream> // cout, endl

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
    int i = 2.0;
    assert(i == 2);
    assert(sizeof(i) == 4); // i is an int

    auto j = 2.0;
    assert(j == 2);
    assert(sizeof(j) == 8); // j is a double
    }

    {
    int i = {2};
    assert(i == 2);
    assert(sizeof(i) == 4);                      // i is an int

    auto j = {2};
    assert(equal(begin(j), end(j), begin({2})));
    assert(sizeof(j) == 16);                     // j is a std::initializer_list<int>
    }

    cout << "Done." << endl;
    return 0;}
