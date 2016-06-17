// ------
// Fill.h
// ------

#ifndef Fill_h
#define Fill_h

template <typename FI, typename T>
void my_fill (FI b, FI e, const T& v) {
    while (b != e) {
        *b = v;
        ++b;}}

#endif // Fill_h
