// ---------------
// RangeIterator.h
// ---------------

#ifndef RangeIterator_h
#define RangeIterator_h

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
class Range_Iterator : public iterator<input_iterator_tag, T> {
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
        Range_Iterator(const T& v) :
                _v (v)
            {}

        bool operator == (const Range_Iterator& rhs) const {
            return (_v == rhs._v);}

        bool operator != (const Range_Iterator& rhs) const {
            return !(*this == rhs);}

        const T& operator * () const {
            return _v;}

        Range_Iterator& operator ++ () {
            ++_v;
            return *this;}

        Range_Iterator operator ++ (int) {
            Range_Iterator x = *this;
            ++*this;
            return x;}};

#endif // RangeIterator_h
