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
#include "./BidirectionnalAccessIterator.hpp"
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
			typedef				ft::mapIterator<key_type, mapped_type>											iterator;
			typedef				ft::mapIterator<key_type, mapped_type>											const_iterator;
			typedef	typename	ft::reverse_iterator<iterator>													reverse_iterator;
			typedef	typename	ft::reverse_iterator<const_iterator>										 		const_reverse_iterator;

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
			ptr_n													_base; // the root of my tree
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
						_sentinel->color = BLACK;
						// _sentinel->pair_node = NULL;
						_sentinel->left = NULL;
						_sentinel->right = NULL;
						_sentinel->parent = _sentinel;
						_sentinel->node_sent = &_sentinel;
						_sentinel->node_base = &_base;

						/* Root node */
						_base = _sentinel;

						_allocation.construct(&_base->pair_node, value_type()); // pourquoi on envoie le ptr de pair_node?
						// std::cout << "Kikou " << std::endl;
					};

					template <class InputIterator> 
					map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
					{
						_allocation = alloc;
						_comp = comp;
						_size_tree = 0;

						/* Initializing an empty tree with its empty nodes */
						_sentinel = _node_allocation.allocate(1); // allocating memory for our sentinel
						_sentinel->color = BLACK;
						_sentinel->left = NULL;
						_sentinel->right = NULL;
						_sentinel->parent = _sentinel;
						_sentinel->node_sent = &_sentinel;
						_sentinel->node_base = &_base;

						/* Root node */
						_base = _sentinel;

						_allocation.construct(&_base->pair_node, _sentinel->pair_node); // pourquoi on envoie le ptr de pair_node?
						insert(first, last);
					};

					map(const map& x)
					{
						_allocation = x._allocation;
						_comp = x._comp;
						_size_tree = 0;

						_sentinel = _node_allocation.allocate(1); // allocating memory for our sentinel
						_sentinel->color = BLACK;
						_sentinel->left = NULL;
						_sentinel->right = NULL;
						_sentinel->parent = _sentinel;
						_sentinel->node_sent = &_sentinel;
						_sentinel->node_base = &_base;
						/* Root node */
						_base = _sentinel;
						_allocation.construct(&_base->pair_node, value_type()); // pourquoi on envoie le ptr de pair_node?
						insert(x.begin(), x.end());
						*this = x;
					}

					map& operator =(const map& x)
					{
						clear();
						insert(x.begin(), x.end());
						return (*this);
					};

					~map()
					{
						if	(_base == _sentinel)
						{
							_size_tree = 0;
							deallocate_node(_sentinel);
							return ;
						}
						if	(_size_tree > 0)
							clear();
						_size_tree = 0;
						deallocate_node(_sentinel);
					}


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
/*                           		Allocator:                                */
/* ************************************************************************** */

	allocator_type get_allocator() const {

		return allocator_type();
	};


/*************************************************************************/
/*                Iterators : 						                	*/
/* *********************************************************************/

	iterator begin()
	{
		return (iterator(minimum(_base)));
	}

	const_iterator begin() const
	{
		return (const_iterator(minimum(_base)));
	}

	iterator end()
	{
		return (iterator(_sentinel));
	}

	const_iterator end() const
	{
		return (const_iterator(_sentinel));
	}

/* ************************************************************************** */
/*                           		Modifiers:                                */
/* ************************************************************************** */

	pair<iterator, bool> insert(const value_type& val)
	{
		ptr_n already = searchTreeKey(_base, val.first);
		if	(already == _sentinel)
		{
			ptr_n node_Inserted = insert_node(val);
			iterator temp = iterator(node_Inserted);
			return ft::make_pair<iterator, bool>(temp, true);
		}
		return (ft::make_pair<iterator, bool>(iterator(already), false));
	}

	iterator insert (iterator position, const value_type& val)
	{
		(void)position;
		/* Position is a hint that helps us to insert the element at some position  */
		return (iterator(insert_node(val)));
	}

	template <class InputIterator>
		void insert (InputIterator first, InputIterator last)
		{
			while(first != last)
			{
				insert(*first);
				first++;
			}
		}

	void erase(iterator position)
	{
		deleteNode(*position);
	}

	size_type erase(const key_type& k)
	{
		ptr_n already = searchTreeKey(_base, k);
		if	(already != _sentinel)
		{
			deleteNode(already->pair_node);
			return 1;
		}
		return 0;
	}

	void erase(iterator first, iterator last)
	{
		iterator temp;
		while(first != last)
		{
			temp = first++;
			erase(temp);
		}
	}

	void clear()
	{
		delete_tree(_base);
		_base = _sentinel;
		_size_tree = 0;
	}

	void swap(map& x)
	{
		allocator_type tmp_alloc = _allocation;
		allocation_for_Node tmp_node_alloc = _node_allocation;
		ptr_n	tmp_base = _base;
		ptr_n	tmp_sent = _sentinel;
		size_type tmp_size = _size_tree;
		key_compare tmp_comp = _comp;

		// this->clear();
		_base = x._base;
		_allocation = x._allocation;
		_node_allocation = x._node_allocation;
		_sentinel = x._sentinel;
		_size_tree = x._size_tree;
		_comp = x._comp;

		// x.clear();
		x._base = tmp_base;
		x._allocation = tmp_alloc;
		x._node_allocation = tmp_node_alloc;
		x._sentinel = tmp_sent;
		x._size_tree = tmp_size;
		x._comp = tmp_comp;

		x._base_sentinelle(x._base);
		_base_sentinelle(_base);
	}

/*************************************************************************/
/*                Operations	 : 					                	*/
/* *********************************************************************/

	iterator find(const key_type& k)
	{
		ptr_n searched = searchTreeKey(_base, k);
		if	(searched == _sentinel)
			return end();
		else
			return (iterator(searched));
	}

	const_iterator find(const key_type& k) const
	{
		ptr_n searched = searchTreeKey(_base, k);
		if	(searched == _sentinel)
			return end();
		else
			return (const_iterator(searched));
	}

	size_type count(const key_type& k) const
	{
		ptr_n searching = searchTreeKey(_base, k);
		if	(searching == _sentinel || searching == NULL)
			return 0;
		return 1;
	}

	iterator lower_bound(const key_type& k)
	{
		ptr_n searched = searchTreeKey(_base, k);
		if	(searched == _sentinel)
		{
			iterator it = begin();
			for (;it != end();)
			{
				if	(_comp(k, it->first))
					return (it);
				it++;
			}
		}
		else if (searched)
			return (iterator(searched));
		else
		{
			ptr_n tmp = iterator(searched).right_after(searched);
			return (iterator(tmp));
		}
		return end();
	}


	const_iterator lower_bound(const key_type& k) const
	{
		ptr_n searched = searchTreeKey(_base, k);
		if	(searched == _sentinel)
		{
			const_iterator it = begin();
			for (;it != end();)
			{
				if	(_comp(k, it->first))
					return (it);
				it++;
			}
			return end();
		}
		else if (searched)
			return (const_iterator(searched));
		else
		{
			ptr_n tmp = const_iterator(searched).right_after(searched);
			return (const_iterator(tmp));
		}
	};


	iterator upper_bound(const key_type& k)
	{
		ptr_n searched = searchTreeKey(_base, k);
		if	(searched == _sentinel)
		{
			iterator it = begin();
			for (;it != end();)
			{
				if	(_comp(k, it->first))
					return (it);
				it++;
			}
		}
		else if (searched)
		{
			ptr_n next = iterator(searched).right_after(searched);
			if	(next)
				return (iterator(next));
			return end();
		}
		else
		{
			ptr_n tmp = iterator(searched).right_after(searched);
			return (iterator(tmp));
		}
		return end();
	}


	const_iterator upper_bound(const key_type& k) const
	{
		ptr_n searched = searchTreeKey(_base, k);
		if	(searched == _sentinel)
		{
			const_iterator it = begin();
			for (;it != end();)
			{
				if	(_comp(k, it->first))
					return (it);
				it++;
			}
		}
		else if (searched)
		{
			ptr_n next = const_iterator(searched).right_after(searched);
			if	(next)
				return (const_iterator(next));
			return end();
		}
		else
		{
			ptr_n tmp = iterator(searched).right_after(searched);
			return (iterator(tmp));
		}
		return end();
	}

	pair<iterator, iterator>
	equal_range(const key_type& k)
	{

		iterator lb = lower_bound(k);
		iterator ub = upper_bound(k);
		return (ft::make_pair<iterator, iterator>(lb, ub));
	}

	pair<const_iterator, const_iterator>
	equal_range(const key_type& k) const
	{

		iterator lb = lower_bound(k);
		iterator ub = upper_bound(k);
		return (ft::make_pair<const_iterator, const_iterator>(lb, ub));
	}


/*************************************************************************/
/*                Element Access : 					                	*/
/* *********************************************************************/

	mapped_type& operator[](const key_type& k)
	{
		ptr_n searched = searchTreeKey(_base, k);
		if	(searched == _sentinel)
		{
			insert(ft::make_pair(k, mapped_type()));
			searched = searchTreeKey(_base, k);
		}
		return searched->pair_node.second;
	}

/* ************************************************************************** */
/*                             		Red Black Tree : 		                  */
/* ************************************************************************** */

	private:


	/* ************************************************* */
	/*  		Ordering/utils		 : 		            */
	/* *********************************************** */

		void _base_sentinelle(ptr_n node)
		{
			if	(node->left)
				_base_sentinelle(node->left);
			if	(node->right)
				_base_sentinelle(node->right);
			node->node_base = &_base;
			node->node_sent = &_sentinel;
		}


	/* ************************************************* */
	/*  		Rotations		 : 		                */
	/* *********************************************** */
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

	/* ************************************************* */
	/*  		Inserting		 : 		                */
	/* *********************************************** */

		void insertFix(ptr_n k) {
			ptr_n u;
			while (k->parent->color == RED) {
				if (k->parent == k->parent->parent->right) {
						u = k->parent->parent->left;
					if (u->color == RED)
					{
						u->color = BLACK;
						k->parent->color = BLACK;
						k->parent->parent->color = RED;
						k = k->parent->parent;
					} 
					else {
						if (k == k->parent->left)
						{
							k = k->parent;
							rightRotate(k);
						}
						k->parent->color = BLACK;
						k->parent->parent->color = RED;
						leftRotate(k->parent->parent);
					}
				} 
				else {
					u = k->parent->parent->right;

					if (u->color == RED)
					{
						u->color = BLACK;
						k->parent->color = BLACK;
						k->parent->parent->color = RED ;
						k = k->parent->parent;
					}
					else 
					{
						if (k == k->parent->right) {
							k = k->parent;
							leftRotate(k);
					}
					k->parent->color = BLACK;
					k->parent->parent->color = RED;
					rightRotate(k->parent->parent);
					}
				}
				if (k == _base) {
					break;
				}
			}
			_base->color = BLACK;
		}

		ptr_n insert_node(const value_type& pair) {
			/* Création de node et allocation/construction en mémoire */
			ptr_n node;
			node = _node_allocation.allocate(1);
			node->parent = NULL;
			node->left = _sentinel;
			node->right = _sentinel;
			node->color = RED;
			node->node_sent = &_sentinel;
			_allocation.construct(&node->pair_node, pair);
			_size_tree++;


			ptr_n y = NULL;
			ptr_n x = this->_base;

			while (x != _sentinel) {
				// std::cout << "je rentre ici ? " << std::endl;
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
			/* Changement ici */
			if (node->parent == NULL) {
				node->node_base = &_base;
				node->color = BLACK;
				return node;
			}
			if (node->parent->parent == NULL) {
				node->node_base = &_base;
				insertFix(node);
				return node;
			}
			insertFix(node);
			node->node_base = &_base;
			return node;
		}

	/* ************************************************* */
	/*  		Deleting and Replace		            */
	/* *********************************************** */

	void rbTransplant(ptr_n u, ptr_n v) {
		
		if (u->parent == NULL)
			_base = v;
		else if (u == u->parent->left)
			u->parent->left = v;
		else
			u->parent->right = v;
		v->parent = u->parent;
	}

	void deleteNodeHelper(ptr_n node, key_type key) {
	
	ptr_n z = _sentinel;
	ptr_n x, y;
	while (node != _sentinel)
	{
		if (node->pair_node.first == key)
			z = node;
		if (node->pair_node.first <= key)
			node = node->right;
		else
			node = node->left;
	}
	if (z == _sentinel)
		return;

	y = z;
	int y_original_color = y->color;
	if (z->left == _sentinel)
	{
		x = z->right;
		rbTransplant(z, z->right);
	} 
	else if (z->right == _sentinel)
	{
		x = z->left;
		rbTransplant(z, z->left);
	} 
	else
	{
		y = minimum(z->right);
		y_original_color = y->color;
		x = y->right;
		if (y->parent == z)
			x->parent = y;
		else 
		{
			rbTransplant(y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		rbTransplant(z, y);
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
	}
	
	deallocate_node(z);
	_size_tree --;
	
	if (y_original_color == BLACK)
		deleteFix(x);
}

	void deleteFix(ptr_n x) 
	{	
		ptr_n s;
		while (x != _base && x->color == BLACK)
		{
			if (x == x->parent->left)
			{
				s = x->parent->right;
				if (s->color == RED)
				{
					s->color = BLACK;
					x->parent->color = RED;
					leftRotate(x->parent);
					s = x->parent->right;
				}
				if (s->left->color == BLACK && s->right->color == BLACK)
				{
					s->color = RED;
					x = x->parent;
				} 
				else
				{
					if (s->right->color == BLACK)
					{
						s->left->color = BLACK;
						s->color = RED;
						rightRotate(s);
						s = x->parent->right;
					}
					s->color = x->parent->color;
					x->parent->color = BLACK;
					s->right->color = BLACK;
					leftRotate(x->parent);
					x = _base;
				}
			} 
			else 
			{
				s = x->parent->left;
				if (s->color == RED)
				{
					s->color = BLACK;
					x->parent->color = RED;
					rightRotate(x->parent);
					s = x->parent->left;
				}
				if (s->right->color == BLACK && s->right->color == BLACK)
				{
					s->color = RED;
					x = x->parent;
				}
				else 
				{
					if (s->left->color == BLACK)
					{
						s->right->color = BLACK;
						s->color = RED;
						leftRotate(s);
						s = x->parent->left;
					}
					s->color = x->parent->color;
					x->parent->color = BLACK;
					s->left->color = BLACK;
					rightRotate(x->parent);
					x = _base;
				}
			}
		}
		x->color = BLACK;
	}

	void deleteNode(value_type data) {
		
		deleteNodeHelper(_base, data.first);
		_size_tree --;
	}

	void	deallocate_node(ptr_n node)
	{
		_allocation.destroy(&node->pair_node);
		_node_allocation.deallocate(node, 1);
	}

	void	delete_tree(ptr_n p )
	{
		if (p != _sentinel)
		{
			delete_tree(p->left);
			delete_tree(p->right);
			deallocate_node(p);
			_size_tree --;
		}
	}


	/* ************************************************* */
	/*  		Searching in Tree:  	                */
	/* *********************************************** */

	ptr_n searchTreeKey(ptr_n node, const key_type& key) const {
		if (node == _sentinel || key == node->pair_node.first)
			return node;
		if (_comp(key, node->pair_node.first))
			return searchTreeKey(node->left, key);
		return searchTreeKey(node->right, key);
	}


	/* ************************************************* */
	/*  		Getting max/min  :  	                */
	/* *********************************************** */

	ptr_n minimum(ptr_n node) const {
		
		if (node == _sentinel)
			return node;
		while (node->left != _sentinel)
			node = node->left;
		return node;
	}

	ptr_n maximum(ptr_n node) {
		
		if (node == _sentinel)
			return node;
		while (node->right != _sentinel)
			node = node->right;
		return node;
	}

	int get_max() {

		return (maximum(_base)->pair_node.first);
	}

	/* ************************************************* */
	/*  		Visualisation		 : 	                */
	/* *********************************************** */

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
		/* ************************************************************************** */
		/*                       Non-member function overloads                        */
		/* ************************************************************************** */
		
		template< class Key, class T, class Compare, class Alloc >
		bool operator == ( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
			
			typename ft::map<Key,T,Compare,Alloc>::const_iterator first = rhs.begin();
			typename ft::map<Key,T,Compare,Alloc>::const_iterator last = rhs.end();
			typename ft::map<Key,T,Compare,Alloc>::const_iterator cursor = lhs.begin();

			if (lhs.size() != rhs.size())
				return (false);
			return (ft::equal(lhs.begin(),lhs.end(),rhs.begin()));
		}

		template< class Key, class T, class Compare, class Alloc >
		bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) { return (!(lhs == rhs)); }

		template< class Key, class T, class Compare, class Alloc >
		bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
			
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}

		template< class Key, class T, class Compare, class Alloc >
		bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) { return (!(rhs < lhs)); }

		template< class Key, class T, class Compare, class Alloc >
		bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) { return (rhs < lhs); }
	
		template< class Key, class T, class Compare, class Alloc >
		bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) { return (!(rhs > lhs)); }

		template< class Key, class T, class Compare, class Alloc >
		void swap( ft::map<Key,T,Compare,Alloc>& lhs, ft::map<Key,T,Compare,Alloc>& rhs ) { lhs.swap(rhs); }
}
