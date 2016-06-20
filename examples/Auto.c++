// --------
// Auto.c++
// --------

//  http://en.cppreference.com/w/cpp/language/auto

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
    }

    {
//  auto i;           // error: declaration of variable 'i' with type 'auto' requires an initializer
    auto i = 2;
    assert(i == 2);
    }



    {
    vector<int> x;
    unsigned    s = x.size();
    assert(sizeof(s) == 4);
    }

    {
    vector<int>            x;
    vector<int>::size_type s = x.size();
    assert(sizeof(s) == 8);
    }

    {
    vector<int> x;
    auto        s = x.size();
    assert(sizeof(s) == 8);
    }



    {
    map<char, int> m;
    m.insert(make_pair('a', 2));
//  for (      pair<char, int>& p : m)                                                           // error: non-const lvalue reference to type 'pair<char, [...]>' cannot bind to a value of unrelated type 'pair<__key_type, [...]>'
    for (const pair<char, int>& p : m)
//      assert(&p == &*m.begin());                                                               // error: comparison of distinct pointer types ('const pair<char, int> *' and 'value_type *' (aka 'pair<const char, int> *'))
        assert(reinterpret_cast<const void*>(&p) != reinterpret_cast<const void*>(&*m.begin()));
    }

    {
    map<char, int> m;
    m.insert(make_pair('a', 2));
    for (pair<const char, int>& p : m)
        assert(&p == &*m.begin());
    }

    {
    map<char, int> m;
    m.insert(make_pair('a', 2));
    for (map<char, int>::reference p : m)
        assert(&p == &*m.begin());
    }

    {
    map<char, int> m;
    m.insert(make_pair('a', 2));
    for (auto& p : m)
        assert(&p == &*m.begin());
    }



    {
    function<int (int)> f = [] (int i) -> int {return i + 1;};
    #ifdef __APPLE__
    assert(sizeof(f) == 48);
    #else
    assert(sizeof(f) == 32);
    #endif
    }

    {
    auto f = [] (int i) -> int {return i + 1;};
    assert(sizeof(f) == 1);
    }



    {
    vector<bool> x;
    x.push_back(true);
//  bool& b = x.back(); // error: non-const lvalue reference to type 'bool' cannot bind to a temporary of type 'reference' (aka '__bit_reference<std::__1::vector<bool, std::__1::allocator<bool> > >')
//  b = false;
//  assert(!x.back());
    }

    {
    vector<bool> x;
    x.push_back(true);
    vector<bool>::reference b = x.back();
    b = false;
    assert(!x.back());
    }

    {
    vector<bool> x;
    x.push_back(true);
    auto b = x.back();
    b = false;
    assert(!x.back());
    }

    cout << "Done." << endl;
    return 0;}
