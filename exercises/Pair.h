// ------
// Pair.h
// ------

#ifndef Pair_h
#define Pair_h

template <typename T1, typename T2>
struct my_pair {
    typedef T1 first_type;
    typedef T2 second_type;

    T1 first;
    T2 second;

    my_pair (const T1& first = T1(), const T2& second = T2()) :
            first  (first),
            second (second)
        {}

    template <typename U1, typename U2>
    my_pair (const my_pair<U1, U2>& that) :
            first  (that.first),
            second (that.second)
        {}};

template <typename T1, typename T2>
my_pair<T1, T2> my_make_pair (const T1& first, const T2& second) {
    return my_pair<T1, T2>(first, second);}

#endif // Pair_h
