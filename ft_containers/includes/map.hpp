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
#include "./struct_node.hpp"
#include "./pair_make_pair.hpp"
// #include "./tree_of_nodes.hpp"

/* Maps are associative containers that store elements formed by a combination of a key value and a mapped value, following a specific order.

value_type => pair type combining key and mapped value*/

// class mytree;

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
			typedef 			Key 																			key_type; // ok
			typedef 			T 																				mapped_type;
			typedef				ft::pair<const key_type, mapped_type> 											value_type;
			typedef				Compare																			key_compare;
			typedef				std::size_t																		size_type; // ok
			typedef				std::ptrdiff_t																	difference_type;
			typedef				Allocator																		allocator_type;
			typedef				value_type&																		reference;
			typedef				const value_type&																const_reference;
			typedef	typename	Allocator::pointer																pointer;
			typedef	typename	Allocator::const_pointer														const_pointer;
			typedef				ft::Node<value_type>															node;
			typedef				ft::Node<value_type>*															ptr_n;
			// typedef				binary_tree_iterator<value_type, Compare, node*>					iterator;
			// typedef				binary_tree_iterator<const value_type, Compare, node*>				const_iterator;
			// typedef	typename	ft::reverse_iterator<iterator>										reverse_iterator;
			// typedef	typename	ft::reverse_iterator<const_iterator>								const_reverse_iterator;

			class value_compare : public std::binary_function<value_type, value_type, bool>
			{   
				friend class map<key_type, mapped_type, key_compare, allocator_type>;
				
				protected:
					key_compare comp; // the stored comparator
					value_compare(key_compare c) : comp(c) {}; //constructs a new value_compare object
				
				public:
				/* Surcharge dans la surcharge d'operateurs */
					bool operator()(const value_type& x, const value_type& y) const
					{ return comp(x.first, y.first); }

					bool operator()(const key_type& x, const value_type& y) const
					{ return comp(x, y.first); }

					bool operator()(const value_type& x, const key_type& y ) const
					{ return comp(x.first, y); }
			
			};

	/*************************************************************************/
	/*                Attributes : 						                	*/
	/* *********************************************************************/
	/* We need to define a new type of allocator to adapt it to a new type of variable : Node*/
		private:

			typedef typename allocator_type::template rebind<node>::other	allocation_for_Node;
			allocation_for_Node										_node_allocation;
			ptr_n													_base;
			ptr_n													_sentinel; // our '\0'
			allocator_type											_allocation;
			size_type												_size_tree;
			key_compare												_comp;




/*************************************************************************/
/*                Constructors : 						                */
/* *********************************************************************/
				public:

					explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
					{
						_allocation = alloc;
						_comp = comp;
						_size_tree = 0;

						/* Initializing an empty tree with its empty nodes */
						_sentinel = _node_allocation.allocate(1); // allocating memory for our sentinel
						_sentinel->color = RED;
						_sentinel->left = NULL;
						_sentinel->right = NULL;
						_sentinel->parent = _sentinel;
						_sentinel->node_sent = &_sentinel;
						_sentinel->node_base = &_base;

						/* Root node */
						_base = _sentinel;

						_allocation.construct(&_sentinel->pair_node, _sentinel->pair_node); // pourquoi on envoie le ptr de pair_node?
						std::cout << "Kikou " << std::endl;
					};

			// template <class InputIterator> 
			// map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			// {

			// };

			// map (const map& x)
			// {

			// };



/*************************************************************************/
/*                Capacity : 						                	*/
/* *********************************************************************/

		size_type	size() const {
			return (this->_size_tree);
		};

		bool		empty() const {
			return ((this->_size_tree == 0));
		};

		size_type max_size() const { 
			return _allocation.max_size(); 
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

/* ************************************************************************** */
/*                             		Modifiers : 		                      */
/* ************************************************************************** */

	public:

		void preOrderHelper(ptr_n node) {
			if (node != _sentinel) {
			std::cout << node->data << " ";
			preOrderHelper(node->left);
			preOrderHelper(node->right);
		}
	}

	// Inorder
		void inOrderHelper(ptr_n node) {
			if (node != _sentinel) {
				inOrderHelper(node->left);
				std::cout << node->data << " ";
				inOrderHelper(node->right);
			}
		}

		void postOrderHelper(ptr_n node) {
			if (node != _sentinel) {
			postOrderHelper(node->left);
			postOrderHelper(node->right);
			std::cout << node->data << " ";
			}
		}

		void preorder() {
			preOrderHelper(_base);
		}

		void inorder() {
			inOrderHelper(_base);
		}

		void postorder() {
			postOrderHelper(_base);
		}

		void leftRotate(ptr_n x) {
			ptr_n y = x->right;
			x->right = y->left;
			if (y->left !=_sentinel) {
				y->left->parent = x;
			}
			y->parent = x->parent;
			if (x->parent == NULL) {
				this->_base = y;
			} else if (x == x->parent->left) {
				x->parent->left = y;
			} else {
				x->parent->right = y;
			}
			y->left = x;
			x->parent = y;
		}

		void rightRotate(ptr_n x) 
		{
			ptr_n y = x->left;
			x->left = y->right;
			if (y->right !=_sentinel) {
				y->right->parent = x;
			}
			y->parent = x->parent;
			if (x->parent == NULL) {
				this->_base = y;
			} 
			else if (x == x->parent->right) {
				x->parent->right = y;
			} else {
				x->parent->left = y;
			}
			y->right = x;
			x->parent = y;
		}

		void insertFix(ptr_n k) {
			ptr_n u;
			while (k->parent->color == BLACK) {
				if (k->parent == k->parent->parent->right) {
						u = k->parent->parent->left;
					if (u->color == BLACK)
					{
						u->color = RED;
						k->parent->color = RED;
						k->parent->parent->color = BLACK;
						k = k->parent->parent;
					} 
					else {
						if (k == k->parent->left)
						{
							k = k->parent;
							rightRotate(k);
						}
						k->parent->color = RED;
						k->parent->parent->color = BLACK;
						leftRotate(k->parent->parent);
					}
				} 
				else {
					u = k->parent->parent->right;

					if (u->color == BLACK)
					{
						u->color = RED;
						k->parent->color = RED;
						k->parent->parent->color = BLACK;
						k = k->parent->parent;
					}
					else 
					{
						if (k == k->parent->right) {
							k = k->parent;
							leftRotate(k);
					}
						k->parent->color = RED;
						k->parent->parent->color = BLACK;
						rightRotate(k->parent->parent);
					}
				}
				if (k == _base) {
					break;
				}
			}
			_base->color = RED;
		}

		void insert(const value_type& pair) {
			/* Création de node et allocation/construction en mémoire */
			ptr_n node;
			node = _node_allocation.allocate(1);
			node->parent = NULL;
			node->left = _sentinel;
			node->right = _sentinel;
			node->color = BLACK;
			node->node_sent = &_sentinel;
			_allocation.construct(&node->pair_node, pair);
			_size_tree++;


			ptr_n y = NULL;
			ptr_n x = this->_base;

			while (x != _sentinel) {
				y = x;
				if (_comp(node->pair_node.first, x->pair_node.first)) {
					x = x->left;
				} else {
					x = x->right;
				}
			}
			node->parent = y;
			if (y == NULL) {
				_base = node;
			} else if (_comp(node->pair_node.first, y->pair_node.first)) {
				y->left = node;
			} else {
				y->right = node;
			}

			if (node->parent == NULL) {
				node->color = RED;
				return;
			}
			if (node->parent->parent == NULL) {
				return;
			}
			insertFix(node);
		}

/* ************************************************************************** */
/*                             		Tree Visualisation :  	                  */
/* ************************************************************************** */

	void printHelper(ptr_n root, std::string indent, bool last) {
		if (root != _sentinel) {
			std::cout << indent;
		if (last) {
			std::cout << "R----";
			indent += "   ";
		} else {
			std::cout << "L----";
			indent += "|  ";
		}

		std::string sColor = root->color ? "RED" : "BLACK";
		std::cout << root->pair_node.first << "(" << sColor << ")" << std::endl;
		printHelper(root->left, indent, false);
		printHelper(root->right, indent, true);
		}
	};

	void printTree() {
		if (_base) {
			printHelper(_base, "", true);
		}
	
    };
	};
}
