// --------
// Incr.c++
// --------

#ifndef Incr_h
#define Incr_h

int& pre_incr (int& r) {
    return r += 1;}

int post_incr (int& r) {
    int v = r;
    r += 1;
    return v;}

#endif // Incr_h
