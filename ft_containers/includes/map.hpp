#pragma once
#include <memory> // for allocator
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "./enable_if.hpp"
#include "./equal.hpp"
#include "./lexicographical_compare.hpp"
#include "./RandomAccessIterator.hpp"
#include "./ReverseIterator.hpp"

/* Maps are associative containers that store elements formed by a combination of a key value and a mapped value, following a specific order.

value_type => pair type combining key and mapped value*/

namespace ft {

	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >

	/* Parameters : 
		1. Key : Type of the keys. Each element in a map is uniquely identified by its key value.
		2. T
		3 . Compare = The comparison object of a map object is set on construction. Its type (member key_compare) is the third template parameter of the map template. By default, this is a less object, which returns the same as operator<.
		This object determines the order of the elements in the container: it is a function pointer or a function object that takes two arguments of the same type as the element keys, and returns true if the first argument is considered to go before the second in the strict weak ordering it defines, and false otherwise.*/
	class map
	{

		public: 
/*************************************************************************/
/*                Member types and their definition :                   */
/* *********************************************************************/
		typedef Key 																			key_type; // ok
		typedef T 																				mapped_type; // ok
		typedef pair<const Key, T> 																value_type; // ok
		typedef Compare																			key_compare; // ok
		typedef				std::size_t															size_type; // ok
		typedef				std::ptrdiff_t														difference_type;// ok
		typedef				Allocator															allocator_type;// ok
		// typedef	typename	Allocator::template rebind<node>::other								rebind_type;
		typedef				value_type&															reference;
		typedef				const value_type&													const_reference;
		typedef	typename	Allocator::pointer													pointer;
		typedef	typename	Allocator::const_pointer											const_pointer;
		// typedef				binary_tree_iterator<value_type, Compare, node*>					iterator;
		// typedef				binary_tree_iterator<const value_type, Compare, node*>				const_iterator;
		typedef	typename	ft::reverse_iterator<iterator>										reverse_iterator;
		typedef	typename	ft::reverse_iterator<const_iterator>								const_reverse_iterator;


/*************************************************************************/
/*                Constructors : 						                */
/* *********************************************************************/

		// explicit map (const key_compare& comp = key_compare(),             const allocator_type& alloc = allocator_type())
		// {

		// };

		// template <class InputIterator> 
		// map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		// {

		// };

		// map (const map& x)
		// {

		// };

		typedef struct Node 
		{
			key_type 		key;
			mapped_type 	value;
			char 			color;  // b = black, r = red
			Node* 			left;
			Node* 			right;
			int	  			nb_nodes;
			int	 			level;
			char			heaviness;
		} node;

/*************************************************************************/
/*                Attributes : 						                */
/* *********************************************************************/

		private:
			allocator_type 		allocation;
			node*				root;
			node*				leaf;
			size_type			_current;
			size_type			_capacity;

	}

}