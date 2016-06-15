// -------
// Equal.h
// -------

#ifndef Equal_h
#define Equal_h

template <typename II1, typename II2>
bool my_equal (II1 b, II1 e, II2 c) {
    while (b != e) {
        if (*b != *c)
            return false;
        ++b;
        ++c;}
    return true;}

#endif // Equal_h
