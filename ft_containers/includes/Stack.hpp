#pragma once

#include <vector>
#include <iostream>

namespace ft
{
	template <class T, class Container = std::vector<T> >
		class stack
		{
			public:

				typedef Container							container_type;
				typedef typename Container::value_type		value_type;
				typedef typename Container::size_type		size_type;
				typedef typename Container::reference		reference;
				typedef typename Container::const_reference	const_reference;

				explicit stack(const Container& cont = Container())
					: c(cont) {}

				~stack() {}

				stack&	operator=(const stack& other)
				{
					if (this != &other)
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
				template <class _T, class _Container>
					friend inline bool	operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs);

				template <class _T, class _Container>
					friend inline bool	operator<(const stack<T, _Container>& lhs, const stack<T, _Container>& rhs);
				
				template <class _T, class _Container>
					friend inline bool	operator!=(const stack<T, _Container>& lhs, const stack<T, _Container>& rhs);

				template <class _T, class _Container>
					friend inline bool	operator<=(const stack<T, _Container>& lhs, const stack<T, _Container>& rhs);

				template <class _T, class _Container>
					friend inline bool	operator>(const stack<T, _Container>& lhs, const stack<T, _Container>& rhs);
				
				template <class _T, class _Container>
					friend inline bool	operator>=(const stack<T, _Container>& lhs, const stack<T, _Container>& rhs);

			protected:
				Container	c;
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