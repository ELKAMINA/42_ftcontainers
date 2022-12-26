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
#include "struct_node.hpp"
//#include "./binary_function.hpp"
#include "./map.hpp"
#include"pair_make_pair.hpp"


namespace ft
{
	template < class Key, class KeyOfValue, class Value, class Compare, class Alloc = std::allocator<Value> >

	class mytree
	{
		private: 
			/* Typedefs */
			typedef ft::Node< Value >							node_type;
			typedef node_type*									node_pointer;
			typedef std::allocator<node_type> 					node_allocator_type;

		public:
			//key_type:			the type of the key in the key value pair.
			typedef Key																		key_type;
			//value_type:		the type of elements contained in the Node
			typedef	Value																	value_type;
			//key_compare:		The third parameter, it allows us to copmare keys.
			typedef Compare																	key_compare;
			//allocator_type:	the allocator used to allocate memory.
			typedef Alloc																	allocator_type;
			//reference:		the type "reference to value_type"
			typedef typename allocator_type::reference										reference; 
			//const_reference:	the type "const reference to value_type"
			typedef typename allocator_type::const_reference								const_reference;
			//pointer:			the type "pointer to value_type"
			typedef typename allocator_type::pointer										pointer;
			//const_pointer:	the type "const pointer to value_type"
			typedef typename allocator_type::const_pointer									const_pointer;	
			typedef typename allocator_type::template rebind< ft::Node<value_type> >::other 	node_allocation;


			/* Some structs */

			class value_compare : public std::binary_function<value_type, value_type, bool>
			{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
				friend class  mytree;
				
				protected:
					key_compare comp; // the stored comparator
					value_compare(key_compare c) : comp(c) {}; //constructs a new value_compare object
				
				public:
					bool operator()(const value_type& x, const value_type& y) const
					{ return comp(x.first, y.first); }

					bool operator()(const key_type& x, const value_type& y) const
					{ return comp(x, y.first); }

					bool operator()(const value_type& x, const key_type& y ) const
					{ return comp(x.first, y); }
			
			};


			// //ITERATORS
			// typedef typename ft::rb_tree_iterator<value_type, node_pointer> \
			// 													iterator;
			// typedef typename ft::rb_tree_iterator<value_type const, node_pointer> \
			// 													const_iterator;
			// typedef typename ft::reverse_iterator<iterator>		reverse_iterator;
			// typedef typename ft::reverse_iterator<const_iterator> \
			// 													const_reverse_iterator;

			//OTHER
			typedef std::ptrdiff_t 															difference_type;
			typedef typename node_allocator_type::size_type 								size_type;



/*************************************************************************/
/*                Constructors : 						                */
/* *********************************************************************/
	public: 
		explicit
		mytree(const Compare& compare = Compare(), const node_allocation& allocator = allocator_type())
			: _allocation(allocator), _comp(compare)
		{
			// std::cout << "kikou " << std::endl;
			// _current = 0;
			// _head = NULL;
			// allocator.construct(_head, ft::Node<KeyOfValue>());
			// _head->bah = NULL;
			// _head->left = _head;
			// _head->right = _head;
		}




			protected:
				node_pointer					_head;
				size_type						_current;
				node_allocation 				_allocation;
				node_pointer					_root;
				node_pointer					_leaf;
				key_compare						_comp;

/*************************************************************************/
/*               Modifiers : 							                */
/* *********************************************************************/

	// void	create_ll()




	};
}