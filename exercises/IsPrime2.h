// ----------
// IsPrime2.h
// ----------

#ifndef IsPrime2_h
#define IsPrime2_h

#include <cassert>  // assert
#include <cmath>    // sqrt

bool is_prime (int n) {
    assert(n > 0);
    if (n == 2)
        return true;
    if ((n == 1) || ((n % 2) == 0))
        return false;
    for (int i = 3; i <= std::sqrt(n); i += 2)
        if ((n % i) == 0)
            return false;
    return true;}

#endif // IsPrime2_h
