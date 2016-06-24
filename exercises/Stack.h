// -------
// Stack.h
// -------

// http://www.cplusplus.com/reference/stack/stack/

#ifndef Stack_h
#define Stack_h

#include <cassert> // assert
#include <utility> // !=, <=, >, >=

/*
namespace std     {
namespace rel_ops {

template <typename T>
inline bool operator != (const T& lhs, const T& rhs) {
    return !(lhs == rhs);}

template <typename T>
inline bool operator <= (const T& lhs, const T& rhs) {
    return !(rhs < lhs);}

template <typename T>
inline bool operator > (const T& lhs, const T& rhs) {
    return (rhs < lhs);}

template <typename T>
inline bool operator >= (const T& lhs, const T& rhs) {
    return !(lhs < rhs);}

} // rel_ops
} // std;
*/

using namespace std::rel_ops;

template <typename T, typename C = std::deque<T>>
class my_stack {
    public:
        using container_type  = C;

        using value_type      = typename container_type::value_type;
        using size_type       = typename container_type::size_type;

        using reference       = typename container_type::reference;
        using const_reference = typename container_type::const_reference;

    public:
        friend bool operator == (const my_stack& lhs, const my_stack& rhs) {
            return lhs._c == rhs._c;}

        friend bool operator < (const my_stack& lhs, const my_stack& rhs) {
            return lhs._c < rhs._c;}

    private:
        container_type _c;

    public:
        explicit my_stack (const container_type& c = container_type()) :
                _c (c)
            {}

        // Default copy, destructor, copy assignment.
                  my_stack   (const my_stack&)  = default;
                  ~my_stack  ()                 = default;
        my_stack& operator = (const my_stack&)  = default;

        bool empty () const {
            return _c.empty();}

        void pop () {
            _c.pop_back();}

        void push (const_reference v) {
            _c.push_back(v);}

        size_type size () const {
            return _c.size();}

        reference top () {
            return _c.back();}

        const_reference top () const {
            return _c.back();}};

#endif // Stack_h
