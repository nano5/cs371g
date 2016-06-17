// ------
// Copy.h
// ------

#ifndef Copy_h
#define Copy_h

template <typename II, typename OI>
OI my_copy (II b, II e, OI x) {
    while (b != e) {
        *x = *b;
        ++b;
        ++x;}
    return x;}

#endif // Copy_h
