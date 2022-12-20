#pragma once

#include <cstddef> // for ptrdiff_t
#include <vector>
#include <iterator>

// This file contains the base class for all iterators
namespace ft
{
    template <typename Category, typename T,
              typename Distance = std::ptrdiff_t,
              typename Pointer = T*, typename Reference = T&>
    struct iterator
    {
        typedef T			value_type;
        typedef Distance	difference_type;
        typedef Pointer		pointer;
        typedef Reference	reference;
        typedef Category	iterator_category;
    };
}