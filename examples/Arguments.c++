// -------------
// Arguments.c++
// -------------

#include <algorithm> // equal
#include <cassert>   // assert
#include <iostream>  // cout, endl

void by_value (int v) {
    ++v;}

void by_address (int* p) {
    ++*p;}

void by_reference (int& r) {
    ++r;}

void f (int p[]) {
//  assert(sizeof(p) == 8); // warning: sizeof on array function parameter will return size of 'int *' instead of 'int []'
    ++p;
    ++p[0];
    ++*p;}

void g (int* p) {
    assert(sizeof(p) == 8);
    ++p;
    ++p[0];
    ++*p;}

int main () {
    using namespace std;
    cout << "Arguments.c++" << endl;

    {
    const int i = 2;
    by_value(i);
    assert(i == 2);
    }

    {
    int j = 3;
    by_address(&j);
    assert(j == 4);
    }

    {
    int k = 4;
    by_reference(k);
    assert(k == 5);
    }

    {
    int a[] = {2, 3, 4};
    int b[] = {2, 5, 4};
    f(a);
    assert(equal(a, a + 3, b));
    }

    {
    int a[] = {2, 3, 4};
    int b[] = {2, 5, 4};
    g(a);
    assert(equal(a, a + 3, b));
    }

    cout << "Done." << endl;
    return 0;}
