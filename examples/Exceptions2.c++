// ---------------
// Exceptions2.c++
// ---------------

// http://www.cplusplus.com/doc/tutorial/exceptions/
// http://www.cplusplus.com/reference/memory/shared_ptr/

#include <cassert>   // assert
#include <cstring>   // strcmp
#include <iostream>  // cout, endl
#include <memory>    // shared_ptr
#include <stdexcept> // domain_error

using namespace std;

int f (bool b) {
    if (b)
        throw domain_error("abc");
    return 0;}

int main () {
    cout << "Exceptions2.c++" << endl;

    try {
        int* const a = new int[10];
        assert(a);
        assert(f(false) == 0);
        delete [] a;
        }
    catch (domain_error& e) {
        assert(false);}

    try {
        int* const a = new int[10];
        assert(a);
        f(true);
        assert(false);
        delete [] a;                           // memory leak
        }
    catch (domain_error& e) {
        assert(strcmp(e.what(), "abc") == 0);}

    try {
        const shared_ptr<int> p(new int[10]);
        f(true);
        assert(false);
        }
    catch (domain_error& e) {
        assert(strcmp(e.what(), "abc") == 0);}

    cout << "Done." << endl;
    return 0;}
