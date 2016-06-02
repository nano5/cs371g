// ----------
// IsPrime1.h
// ----------

#ifndef IsPrime1_h
#define IsPrime1_h

#include <cassert>  // assert
#include <cmath>    // sqrt

bool is_prime (int n) {
    assert(n > 0);
    if ((n == 1) || ((n % 2) == 0))
        return false;
    for (int i = 3; i < std::sqrt(n); ++i)
        if ((n % i) == 0)
            return false;
    return true;}

#endif // IsPrime1_h
