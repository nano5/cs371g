// -------
// AllOf.h
// -------

#ifndef AllOf_h
#define AllOf_h

template <typename II, typename UP>
bool my_all_of (II b, II e, UP f) {
    while (b != e) {
        if (!f(*b))
            return false;
        ++b;}
    return true;}

#endif // AllOf_h
