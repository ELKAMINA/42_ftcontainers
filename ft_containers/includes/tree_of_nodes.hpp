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
	template < class Key, class ValueOfKey, class Pair, class Compare, class Alloc = std::allocator<Pair> >

	class mytree
	{
		private: 
			/* Typedefs */
			typedef ft::Node< Pair >														node_type;
			typedef node_type*																NodePtr;
			typedef std::allocator<node_type> 									node_allocator_type;

		public:
			//key_type:			the type of the key in the key Pair pair.
			typedef Key																			key_type;
			//Pair_type:		the type of elements contained in the Node
			typedef	Pair																		value_type;
			//key_compare:		The third parameter, it allows us to copmare keys.
			typedef Compare																		key_compare;
			//allocator_type:	the allocator used to allocate memory.
			typedef Alloc																		allocator_type;
			//reference:		the type "reference to value_type"
			typedef typename allocator_type::reference											reference; 
			//const_reference:	the type "const reference to value_type"
			typedef typename allocator_type::const_reference									const_reference;
			//pointer:			the type "pointer to value_type"
			typedef typename allocator_type::pointer											pointer;
			//const_pointer:	the type "const pointer to value_type"
			typedef typename allocator_type::const_pointer										const_pointer;	
			// typedef typename allocator_type::template rebind< ft::Node<value_type> >::other 	node_allocation;


			/* Some structs */



			// //ITERATORS
			// typedef typename ft::rb_tree_iterator<value_type, NodePtr>iterator;
			// typedef typename ft::rb_tree_iterator<value_type const, NodePtconst_iterator;
			// typedef typename ft::reverse_iterator<iterator>		reverse_iterator;
			// typedef typename ft::reverse_iterator<const_iterator>const_reverse_iterator;

			//OTHER
			typedef std::ptrdiff_t 															difference_type;
			typedef typename node_allocator_type::size_type 								size_type;



/*************************************************************************/
/*                Constructors : 						                */
/* *********************************************************************/
	public: 
		explicit
		mytree(const Compare& compare = Compare(), const node_allocator_type& allocator = allocator_type())
		{
 			_allocation = allocator;
			_comp = compare;
			_current = 0;
			_TNULL = _allocation.allocate(1);
			_allocation.construct(_TNULL, ft::Node<value_type>());
			_TNULL->parent = 0;
			_TNULL->right = NULL;
			_TNULL->left = NULL;
			_ROOT = _TNULL
		}


	protected:
		NodePtr							_ROOT;
		NodePtr							_TNULL;
		size_type						_current;
		node_allocator_type 			_allocation;
		key_compare						_comp;

/*************************************************************************/
/*               Modifiers : 							                */
/* *********************************************************************/


	public: 
		void preOrderHelper(NodePtr node) {
		if (node != _TNULL) {
		std::cout << node->data << " ";
		preOrderHelper(node->left);
		preOrderHelper(node->right);
		}
	}

	// Inorder
		void inOrderHelper(NodePtr node) {
			if (node != _TNULL) {
				inOrderHelper(node->left);
				std::cout << node->data << " ";
				inOrderHelper(node->right);
			}
		}

	// Post order
		void postOrderHelper(NodePtr node) {
			if (node != _TNULL) {
			postOrderHelper(node->left);
			postOrderHelper(node->right);
			std::cout << node->data << " ";
			}
		}

		void preorder() {
			preOrderHelper(this->_ROOT);
		}

		void inorder() {
			inOrderHelper(this->_ROOT);
		}

		void postorder() {
			postOrderHelper(this->_ROOT);
		}

		void leftRotate(NodePtr x) {
			NodePtr y = x->right;
			x->right = y->left;
			if (y->left != _TNULL) {
			y->left->parent = x;
			}
			y->parent = x->parent;
			if (x->parent == NULL) {
			this->_ROOT = y;
			} else if (x == x->parent->left) {
			x->parent->left = y;
			} else {
			x->parent->right = y;
			}
			y->left = x;
			x->parent = y;
		}

		void rightRotate(NodePtr x) {
			NodePtr y = x->left;
			x->left = y->right;
			if (y->right != _TNULL) {
			y->right->parent = x;
			}
			y->parent = x->parent;
			if (x->parent == NULL) {
			this->_ROOT = y;
			} else if (x == x->parent->right) {
			x->parent->right = y;
			} else {
			x->parent->left = y;
			}
			y->right = x;
			x->parent = y;
		}


	// For balancing the tree after insertion
		void insertFix(NodePtr k) {
			NodePtr u;
			while (k->parent->color == 'b') {
			if (k->parent == k->parent->parent->right) {
				u = k->parent->parent->left;
				if (u->color == u->BLACK) {
				u->color = u.RED;
				k->parent->color = u.RED;
				k->parent->parent->color = k.BLACK;
				k = k->parent->parent;
				} else {
				if (k == k->parent->left) {
					k = k->parent;
					rightRotate(k);
				}
				k->parent->color = RED;
				k->parent->parent->color = k.BLACK;
				leftRotate(k->parent->parent);
				}
			} else {
				u = k->parent->parent->right;

				if (u->color == u.BLACK) {
				u->color = u.RED;
				k->parent->color = k.RED;
				k->parent->parent->color = k.BLACK;
				k = k->parent->parent;
				} else {
				if (k == k->parent->right) {
					k = k->parent;
					leftRotate(k);
				}
				k->parent->color = k.RED;
				k->parent->parent->color = k.BLACK;
				rightRotate(k->parent->parent);
				}
			}
			if (k == _ROOT) {
				break;
			}
			}
			_ROOT->color = _ROOT.RED;
		}

		void insert(const value_type& pair) {
			NodePtr node;
			node = _allocation.allocate(1);
			_allocation.construct(node, ft::Node<value_type>());
			node->parent = NULL;
			node->left = _TNULL;
			node->right = _TNULL;
			node->color = RED;

			NodePtr y = NULL;
			NodePtr x = this->_ROOT;

			while (x != _TNULL) {
				y = x;
				if (node->data < x->data) {
					x = x->left;
				} else {
					x = x->right;
				}
			}
			node->parent = y;
			if (y == NULL) {
				_ROOT = node;
			} else if (node->data < y->data) {
				y->left = node;
			} else {
				y->right = node;
			}

			if (node->parent == NULL) {
				node->color = BLACK;
				return;
			}
			if (node->parent->parent == NULL) {
				return;
			}
			insertFix(node);
		}


		void printHelper(NodePtr root, std::string indent, bool last) {
		if (root != _TNULL) {
		std::cout << indent;
		if (last) {
			std::cout << "R----";
			indent += "   ";
		} else {
			std::cout << "L----";
			indent += "|  ";
		}

		std::string sColor = root->color ? "RED" : "BLACK";
		std::cout << root->data << "(" << sColor << ")" << std::endl;
		printHelper(root->left, indent, false);
		printHelper(root->right, indent, true);
		}
	}

		void printTree() {
		if (_ROOT) {
			printHelper(this->_ROOT, "", true);
		}
	}


	};
}