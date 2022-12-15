#ifndef	VECTOR_CLASS_HPP
# define VECTOR_CLASS_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <iterator> //pour rajouter les categories
#include <cstddef> // pour ptrdiff_t

// Reference : https://cplusplus.com/reference/iterator/iterator/

namespace ft_vector
{
	template <class Category,
			class T, 
			class Distance = std::ptrdiff_t, 
			class Pointer = T*, 
			class Reference = T&>
	struct iterator
	{
		typedef T         value_type; // Type of elements pointed by the iterator.
		typedef Distance  difference_type; // ype to represent the difference between two iterators.
		typedef Pointer   pointer; // Type to represent a pointer to an element pointed by the iterator.
		typedef Reference reference; // Type to represent a reference to an element pointed by the iterator.
		typedef Category  iterator_category; // Category to which the iterator belongs to.
	};
	template <class Category,
			class T, 
			class Distance = std::ptrdiff_t, 
			class Pointer = const T*, 
			class Reference = const T&>
	struct const_iterator
	{
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};

	/*	. We need to define iterator traits 
		: which defines properties of iterators -
		
		. For every iterator type, a corresponding specialization of iterator_traits class template shall be defined -
	*/
}



#endif