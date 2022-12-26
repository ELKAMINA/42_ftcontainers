#pragma once
#include <cstddef>
#include <iostream>
#include <memory> // for std::allocator
#include "./map.hpp"
//#include "./binary_function.hpp"
#include "./map.hpp"

/* We need to create a temlate structure of nodes so that it can adapt to any type of value_type. For map, it will adapt to pair<T,U>*/

namespace ft
{
	template<typename T>
	struct Node 
	{
		typedef struct Common
		{
			int	  			nb_nodes;
		} comm;

		typedef T		value_type;
		
			enum colors
			{
				RED = 'r',
				BLACK = 'b',
			};
		
			colors 			color; 
			colors			parent_colors;
			colors			left_color;
			colors			right_color;
			Node* 			left;
			Node* 			right;
			Node* 			parent; // parent
			value_type		*data;
			int				level;
			comm*			commun;

			Node() : color(RED), left(NULL), right(NULL), parent(NULL), data(NULL){};
			Node(const T &data) : color(RED), left(NULL), right(NULL), parent(NULL), data(data){};

			/* ***Constructeur par copie*** */
			// Node(const Node &rhs)
			// {
			// 	*this = rhs;
			// }
			
			// /* ***Constructeur par assignation*** */
			// Node &operator=(const Node &rhs)
			// {
			// 	if (this != &rhs)
			// 	{
			// 		*data = *(rhs.data);
			// 		left = rhs.left;
			// 		right = rhs.right;
			// 		parent = rhs.parent;
			// 		color = rhs.color;
			// 	}
			// }
	/*
	** ********************************************************************
	** To access protected data from the tree and the iterator
	** ********************************************************************
	*/
			//friend of mytree so that it can access its protected data.
			template <class, class, class, class, class>
			friend class mytree;

			//friend of re_tree_iterator so that it can access its protected data.
			// template <class, class>
			// friend class rb_tree_iterator;

	};





}
