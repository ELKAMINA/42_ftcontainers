#pragma once
#include <memory> // for allocator
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <iomanip>
//#include "./binary_function.hpp"
#include "./enable_if.hpp"
#include "./equal.hpp"
#include "./lexicographical_compare.hpp"
#include "./RandomAccessIterator.hpp"
#include "./ReverseIterator.hpp"
#include "struct_node.hpp"
#include "./tree_of_nodes.hpp"

/* Maps are associative containers that store elements formed by a combination of a key value and a mapped value, following a specific order.

value_type => pair type combining key and mapped value*/

class mytree;

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
			// typedef	typename	ft::reverse_iterator<iterator>										reverse_iterator;
			// typedef	typename	ft::reverse_iterator<const_iterator>								const_reverse_iterator;


			/* *** Nodes AND TREE ** */
			typedef typename ft::mytree::value_comp					value_compare; //a function object that allows to compare 2 value_type

			typedef ft::Node< ft::pair<const Key, T> >			node_type;
			typedef node_type*									node_pointer;
			typedef std::allocator<node_type> 					node_allocator_type;


			typedef typename ft::Node::KeyOfValue<value_type>()					KeyOfValue;
			typedef typename ft::mytree<key_type, value_type, KeyOfValue, key_compare, Allocator> rbt;

			/* ****************************************************************************** */



					/* Some structs */

			/* to give to the class tree_of_nodes a function object that
			** will extract the first_type parameter out of an std::pair<first_type,
			** second_type> */	
		struct KeyOfValue : public std::unary_function<value_type, typename value_type::first_type> {

			typename value_type::first_type &
			operator()(value_type & x)
			const
			{ return x.first; }

			const typename value_type::first_type &
			operator()(const value_type & x)
			const
			{ return x.first; }	

		};	/* Getting the key from the a pair*/
	


/*************************************************************************/
/*                Constructors : 						                */
/* *********************************************************************/

			explicit map (const key_compare& comp = key_compare(),             const allocator_type& alloc = allocator_type()) : _rbt(value_compare(comp), alloc)
			{

			};

			// template <class InputIterator> 
			// map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			// {

			// };

			// map (const map& x)
			// {

			// };


/*************************************************************************/
/*                Attributes : 						                	*/
/* *********************************************************************/
	// typedef struct_node<value_type>						RBT;
	// typedef RBT*										RBTPtr;
			
	// typename allocator_type::template rebind<RBT>::other node_allocation;

	// private:
	// 	allocator_type 		_allocation;
	// 	node*				_root;
	// 	node*				_leaf;
	// 	size_type			_current;
	// 	size_type			_capacity;
	// 	key_compare			_comp;
	rbt	_rbt;

/*************************************************************************/
/*                Capacity : 						                	*/
/* *********************************************************************/

		size_type	size() const {
			return (this->_current);
		}

		bool		empty() const {
			return ((this->_current == 0));
		}

		size_type max_size() const { 
			return _rbt.node_allocation.max_size(); 
		};

/* ************************************************************************** */
/*                             		Observers:                                */
/* ************************************************************************** */

		key_compare key_comp() const { 
			
			return (key_compare()); // on cree un object de la class Compare (par defaut est le rtat de less<T>)
		};

		value_compare value_comp() const {

			return (value_compare(key_compare()));// on cree un object de la class value_compare (avec en param l'objet Compare alias key_compare)
		};


	};
}
