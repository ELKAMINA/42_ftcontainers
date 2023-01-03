#pragma once

#include <iostream>
#include <memory> // for allocator
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "./vector.hpp"
#include "./enable_if.hpp"
#include "./equal.hpp"
#include "./lexicographical_compare.hpp"
#include "./RandomAccessIterator.hpp"
#include "./ReverseIterator.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
		class stack
		{
			public:

				typedef Container							container_type;
				typedef typename Container::value_type		value_type;
				typedef typename Container::size_type		size_type;
				typedef typename Container::reference		reference;
				typedef typename Container::const_reference	const_reference;

				explicit stack(const container_type& cont = container_type())
					: c(cont) {}

				~stack() {}

				stack&	operator=(const stack& other)
				{
					c = other.c;
					return (*this);
				}

				/* ############################# Element Access ############################# */

				reference	top() // note : definition of reference is value_type&
				{
					return (c.back());
				}

				const_reference	top() const
				{
					return (c.back());
				}

				/* ################################ Capacity ################################ */

				bool	empty() const
				{
					return (c.empty());
				}

				size_type	size() const
				{
					return (c.size());
				}

				/* ############################### Modifiers ################################ */

				void	push(const value_type& value)
				{
					c.push_back(value);
				}

				void	pop()
				{
					c.pop_back();
				}

				/* Relational operators friends */
				template <class T1, class C1>
				friend bool operator== (const stack<T1, C1>& lhs, const stack<T1, C1>& rhs);
		
				template <class T1, class C1>
				friend bool operator< (const stack<T1, C1>& lhs, const stack<T1, C1>& rhs);
	
				// template <class _T, class _container_type>
				// 	friend inline bool	operator==(const stack<T, container_type>& lhs, const stack<T, container_type>& rhs);

				// template <class _T, class _container_type>
				// 	friend inline bool	operator<(const stack<T, _container_type>& lhs, const stack<T, _container_type>& rhs);
				
				// template <class _T, class _container_type>
				// 	friend inline bool	operator!=(const stack<T, _container_type>& lhs, const stack<T, _container_type>& rhs);

				// template <class _T, class _container_type>
				// 	friend inline bool	operator<=(const stack<T, _container_type>& lhs, const stack<T, _container_type>& rhs);

				// template <class _T, class _container_type>
				// 	friend inline bool	operator>(const stack<T, _container_type>& lhs, const stack<T, _container_type>& rhs);
				
				// template <class _T, class _container_type>
				// 	friend inline bool	operator>=(const stack<T, _container_type>& lhs, const stack<T, _container_type>& rhs);

			protected:
				container_type	c;
		};

	template <class T, class Container>
		inline bool	operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
		{
			return (lhs.c == rhs.c);
		}

	template <class T, class Container>
		inline bool	operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
		{
			return !(lhs == rhs);
		}

	template <class T, class Container>
		inline bool	operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
		{
			return (std::lexicographical_compare(lhs.c.begin(), lhs.c.end(), rhs.c.begin(), rhs.c.end()));
		}

	template <class T, class Container>
		inline bool	operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
		{
			return !(rhs < lhs);
		}

	template <class T, class Container>
		inline bool	operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
		{
			return (rhs < lhs);
		}

	template <class T, class Container>
		inline bool	operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
		{
			return !(lhs < rhs);
		}
}