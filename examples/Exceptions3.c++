// ---------------
// Exceptions3.c++
// ---------------

// http://www.cplusplus.com/doc/tutorial/exceptions/

#include <cassert>   // assert
#include <cstring>   // strcmp
#include <exception> // exception
#include <iostream>  // cout, endl;

using namespace std;

struct My_Exception : exception {
    const char* what () const throw () {
        return "My_Exception";}};

int main () {
    cout << "Exceptions3.c++" << endl;

    My_Exception x;
    exception&   y = x;
    assert(strcmp(y.what(), "My_Exception") == 0);

    cout << "Done." << endl;
    return 0;}
