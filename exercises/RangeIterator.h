// ---------------
// RangeIterator.h
// ---------------

#ifndef RangeIterator_h
#define RangeIterator_h

#include <cstddef>  // ptrdiff_t
#include <iterator> // input_iterator_tag, iterator
#include <utility>  // !=

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

/*
namespace std     {
namespace rel_ops {

template <typename T>
inline bool operator != (const T& lhs, const T& rhs) {
    return !(lhs == rhs);}

} // rel_ops
} // std;
*/

using std::rel_ops::operator!=;

template <typename T>
class Range_Iterator : public std::iterator<std::input_iterator_tag, T> {
/*
    public:
        using iterator_category = input_iterator_tag;
        using value_type        = T;
        using difference_type   = ptrdiff_t;
        using pointer           = T*;
        using reference         = T&;
*/
    friend bool operator == (const Range_Iterator& lhs, const Range_Iterator& rhs) {
            return (lhs._v == rhs._v);}

    private:
        T _v;

    public:
        Range_Iterator(const T& v) :
                _v (v)
            {}

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
