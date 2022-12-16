#include "./iterator_traits.hpp"

template <class Category,
    class T, class Distance = ptrdiff_t,
    class Pointer = T*, class Reference = T &>
struct vec_iterator
{
    typedef T         						value_type;
    typedef Distance  						difference_type;
    typedef Pointer   						pointer;
    typedef Reference 						reference;
    typedef bidirectional_iterator_tag 		iterator_category;
};
