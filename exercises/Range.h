// ---------
// Range.c++
// ---------

#ifndef Range_h
#define Range_h

#include <cstddef>  // ptrdiff_t
#include <iterator> // input_iterator_tag, iterator

/*
namespace std {

template <typename C, typename T, typename D = ptrdiff_t, typename P = T*, typename R = T&>
struct iterator {
    using iterator_category = C;
    using value_type        = T;
    using difference_type   = D;
    using pointer           = P;
    using reference         = R;};

} // std
*/

using namespace std;

template <typename T>
class Range {
    private:
        T _b;
        T _e;

    public:
        class iterator : public std::iterator<input_iterator_tag, T> {
/*
            public:
                using iterator_category = input_iterator_tag;
                using value_type        = T;
                using difference_type   = ptrdiff_t;
                using pointer           = T*;
                using reference         = T&;
*/
            private:
                T _v;

            public:
                iterator (const T& v) :
                        _v (v)
                    {}

                bool operator == (const iterator& rhs) const {
                    return (_v == rhs._v);}

                bool operator != (const iterator& rhs) const {
                    return !(*this == rhs);}

                const T& operator * () const {
                    return _v;}

                iterator& operator ++ () {
                    ++_v;
                    return *this;}

                iterator operator ++ (int) {
                    iterator x = *this;
                    ++*this;
                    return x;}};

        Range (const T& b, const T& e) :
                _b (b),
                _e (e)
            {}

        iterator begin () const {
            return iterator(_b);}

        iterator end () const {
            return iterator(_e);}};

#endif // Range_h
