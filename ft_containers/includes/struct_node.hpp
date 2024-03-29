#pragma once
#include <cstddef>
#include <iostream>
#include <memory> // for std::allocator
// #include "./map.hpp"
//#include "./binary_function.hpp"

/* We need to create a temlate structure of nodes so that it can adapt to any type of value_type. For map, it will adapt to pair<T,U>*/

enum
{
	BLACK = 0,
	RED,
};

namespace ft
{
	template<typename T>
	struct Node 
	{

		typedef T		value_type;
	
		value_type		pair_node;
		Node* 			left;
		Node* 			right;
		Node* 			parent; // parent
		Node**			node_base;			
		Node**			node_sent;
		int				color;

		Node() : pair_node(NULL), color(0), left(NULL), right(NULL), parent(NULL), node_base(NULL), node_sent(NULL)
		{};
		Node(const T &data) : pair_node(data), color(0), left(NULL), right(NULL), parent(NULL), node_base(NULL), node_sent(NULL)
		{};

	/*
	** ********************************************************************
	** To access protected data from the tree and the iterator
	** ********************************************************************
	*/
			//friend of mytree so that it can access its protected data.
			template <class, class, class, class>
			friend class map;

			//friend of tree_iterator so that it can access its protected data.

	};





}
