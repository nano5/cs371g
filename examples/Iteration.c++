// -------------
// Iteration.c++
// -------------

// http://www.cplusplus.com/doc/tutorial/control/

#include <algorithm> // equal
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <list>      // list
#include <map>       // map
#include <set>       // set
#include <utility>   // pair

int main () {
    using namespace std;
    cout << "Iteration.c++" << endl;

    {
    int i = 0;
    int s = 0;
    while (i != 10) {
        s += i;
        ++i;}
    assert(i == 10);
    assert(s == 45);
    }

    {
    int i = 0;
    int s = 0;
    do {
        s += i;
        ++i;}
    while (i != 10);
    assert(i == 10);
    assert(s == 45);
    }

    {
    int s = 0;
    for (int i = 0; i != 10; ++i)
        s += i;
//  assert(i == 10);              // error: name lookup of 'i' changed for new ISO 'for' scoping
    assert(s == 45);
    }

    {
    const int a[] = {2, 3, 4};
    const int b[] = {5, 6, 7};
    int s = 0;
    for (int i = 0, j = 0; i != 3; ++i, ++j)
        s += a[i] + b[j];
    assert(s == 27);
    }

    {
    const int a[] = {2, 3, 4};
          int s   = 0;
    for (int v : a) {
        s += v;
        ++v;}                  // ?
    assert(s == 9);
    }

    {
    int a[] = {2, 3, 4};
    int s   = 0;
    for (int& r : a) {
        s += r;
        ++r;}
    assert(s == 9);
    assert(equal(a, a + 3, begin({3, 4, 5})));
    }

    {
    const list<int> x = {2, 3, 4};
          int       s = 0;
    for (int v : x)
        s += v;
    assert(s == 9);
    }

    {
    const list<int> x = {2, 3, 4};
          int       s = 0;
    for (list<int>::value_type v : x)
        s += v;
    assert(s == 9);
    }

    {
    const list<int> x = {2, 3, 4};
          int       s = 0;
    for (auto v : x)
        s += v;
    assert(s == 9);
    }

    {
    const list<int> x = {2, 3, 4};
          int       s = 0;
    list<int>::const_iterator b = begin(x); // x.begin()
    list<int>::const_iterator e = end(x);   // x.end()
    while (b != e) {
        list<int>::value_type v = *b;
        s += v;
        ++b;}
    assert(s == 9);
    }

    {
    const set<int> x = {2, 3, 4};
          int      s = 0;
    for (auto v : x)
        s += v;
    assert(s == 9);
    }

    {
    const set<int> x = {2, 3, 4};
          int      s = 0;
    for (set<int>::value_type v : x)
        s += v;
    assert(s == 9);
    }

    {
    const map<char, int> x = {{'a', 2}, {'b', 3}, {'c', 4}};
          int            s = 0;
    for (pair<const char, int> v : x)
        s += v.second;
    assert(s == 9);
    }

    {
    const map<char, int> x = {{'a', 2}, {'b', 3}, {'c', 4}};
          int      s = 0;
    for (auto v : x)
        s += v.second;
    assert(s == 9);
    }

    cout << "Done." << endl;
    return 0;}
