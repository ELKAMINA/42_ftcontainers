#pragma once
/* explicit keyword : to avoid implicit casts/conversions */
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

namespace ft {
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
		
/*************************************************************************/
/*                Member types and their definition :                   */
/* *********************************************************************/

		typedef T 														value_type;
		typedef Allocator 												allocator_type;
		typedef typename allocator_type::reference 						reference;
		typedef typename allocator_type::const_reference 				const_reference;
		typedef typename allocator_type::pointer 						pointer;
		typedef typename allocator_type::const_pointer 					const_pointer;
		typedef ft::RandomAccessIterator<value_type>					iterator;
		typedef ft::RandomAccessIterator<const value_type>				const_iterator;
		typedef ft::reverse_iterator<iterator> 							reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> 					const_reverse_iterator;
		typedef ptrdiff_t												difference_type;
		typedef size_t													size_type;

/*************************************************************************/
/*                			Constructors/Member functions		        */
/* *********************************************************************/

		/* default constructor : creates an empty container */
		explicit vector (const allocator_type& alloc = allocator_type()) : _allocation(alloc), _capacity(0), _current(0) 
		{
			_arrey = NULL;
		};
		
		/* Constructor container with n elements */
		explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type()) : _allocation(alloc), _capacity(n), _current(n)
		{
			// std::cout << "here " << std::endl;
			_arrey = _allocation.allocate(_current); /* allocate() func allocate memory for a container. It returns a pointer to the start of the allocated memory */
			for	(size_type i = 0; i < _current; i++)
			{
				_allocation.construct(&_arrey[i], val); /* construct () is used to construct an object in allocated memory */
			}
		};
		
		/* Range constructor : Constructs a container with as many elements as the range [first,last)  */
		template <class InputIterator>
        vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0)
		{
			(void)alloc;
			/* Start with iterators and functions */
			_arrey = NULL;
			_capacity = 0;
			_current = 0;
			insert(begin(), first, last);
		}

		/* Constructs a container with a copy of each of the elements in x, in the same order.  */
		vector(const vector& x)
		{
			_arrey = NULL;
			_capacity = 0;
			_current = 0;
			assign(x.begin(), x.end());
		};

		/* Operator =  : Assigns new contents to the container, replacing its current contents, and modifying its size accordingly.*/

		vector& operator= (const vector& x)
		{
			if (&x == this)
				return *this;
			assign(x.begin(), x.end());
			return *this;
		};

/*************************************************************************/
/*                			Destructors 						        */
/* *********************************************************************/

		~vector()
		{
			clear();
			_allocation.deallocate(_arrey, _current);
		};

/* ************************************************************************** */
/*                                 Iterator :                                 */
/* ************************************************************************** */

			/* 1 - begin : returns a random access iterator pointing to the first element.
			Warning : If the container is empty, the returned iterator value shall not be dereferenced.
			*/
		iterator begin()
		{
			return (iterator(_arrey));
		};

		const_iterator begin() const
		{
			return (const_iterator(_arrey));
		};
			/* 2 - end : An iterator to the element past the end of the sequence.
			Warning : If the container is empty, the returned iterator value shall not be dereferenced.*/
		iterator end()
		{
			return (iterator(begin() + _current));
		};
		const_iterator end() const
		{
			return (const_iterator(begin() + _current));
		};

		reverse_iterator 		rbegin()		{ return reverse_iterator(end()); };

		const_reverse_iterator	rbegin() const	{ return reverse_iterator(end()); };

		reverse_iterator		rend() 			{ return reverse_iterator(begin()); };
		const_reverse_iterator 	rend() const	{ return const_reverse_iterator(begin()); };

/* ************************************************************************** */
/*                                 Capacity :                                 */
/* ************************************************************************** */

			/* 1- Size : Returns the number of elements in the vector so last - firsr */
		size_type size() const
		{
			return (_current);
		};

			/* 2- The maximum size of a vector is determined by the amount of memory available on the system and the size of the elements stored in the vector. This returns std::numeric_limits<size_type>::max() / sizeof(value_type)*/
		size_type max_size() const
		{
			return (_allocation.max_size());
		};
			/* 3- Checks if a vector is empty or not.*/
		bool empty() const
		{
			if(size() == 0)
				return true; // value 1
			else
				return false; // value 0
		};

			/* 4- Resizes the container so that it contains n elements.*/
		void resize (size_type n, value_type val = value_type())
		{
			// Cas 1  : If n is smaller than the current container size, the content is reduced to its first n elements, removing those beyond (and destroying them).
			while(_current > n)
			{
				_allocation.destroy(&_arrey[_current]);
				_current--;
			}
			/* Cas 2 : If n is greater than the current container size, the content is expanded by inserting at the end as many elements as needed to reach a size of n. If val is specified, the new elements are initialized as copies of val, otherwise, they are value-initialized.*/
			if	(n > _current)
				insert(end(), (n - _current), val);
		};

			/* Reserve : Requests that the vector capacity be at least enough to contain n elements. Only change capacity*/
		void reserve (size_type n)
		{
			/* Cas 1 : If the size requested is greater than the maximum size (vector::max_size), a length_error exception is thrown.*/ 
			if (n > max_size())
			{
				throw std::length_error("vector::reserve");
			}
			/* Cas 2  : If n is greater than the current vector capacity, the function causes the container to reallocate its storage increasing its capacity to n (or greater).*/
			else if (n > _capacity)
			{
				pointer reallocation = _allocation.allocate(n);
				for (size_type i = 0; i < _current; i++)
				{
					_allocation.construct(&reallocation[i], _arrey[i]);	
					_allocation.destroy(&_arrey[i]);
				}
				_allocation.deallocate(_arrey, _current);
				_capacity = n;
				_arrey = reallocation;
			}
			/* Cas 3  : If n is smaller than the current vector capacity, nothing is done*/
			else if(n < _capacity)
				return ;
		};

		/* Capacity : Return size of allocated storage capacity*/
		size_type capacity() const
		{
			return (_capacity);
		};


/* ************************************************************************** */
/*                                 Modifiers:                                 */
/* ************************************************************************** */

			/* Insert : Requests that the vector capacity be at least enough to contain n elements. Only change capacity*/

				/* Prototype 1 */
			iterator insert (iterator position, const value_type& val)
			{
				insert(position, 1, val);
				return (_arrey);
			};
			
				/* Prototype 2 */
			void insert (iterator position, size_type n, const value_type& val)
			{
				difference_type index = position - begin();
				// std::cout << "index " << index << std::endl;

				if	(_capacity == 0)
					reserve(n);
				else
				{
					/* Why *2 : https://stackoverflow.com/questions/33571130/how-does-stdvector-reallocates-every-time-an-item-is-inserted-using-a-loop*/
					if (_current * 2 >= _current + n)
        		    	reserve(_current * 2);
        		  	else
        		    	 reserve(_current + n);
				}
				for (size_type i = n + _current - 1; i > index + n - 1; i--)
				{
					_allocation.construct(&_arrey[i], _arrey[i - n]);
					_allocation.destroy(&_arrey[i - n]);
				}
				for (size_type i = index; i < index + n; i++)
				{
					_allocation.construct(&_arrey[i], val);
					_current++;
				}
			};

				/* Prototype 3 */
			template <class InputIterator>
				void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0)
				{
					difference_type index = position - begin();
					InputIterator tmp = first;
					size_type n = 0;
					
					while (tmp != last)
					{
						tmp++;
						n++;
					}
					if (_current + n > _capacity)
					{
						if (_capacity == 0)
							reserve(n);
						else 
						{
							if (_current * 2 >= _current + n)
								reserve(_current * 2);
							else
								reserve(_current + n);
						}
					}
					
					for (size_type i = n + _current - 1; i > index + n - 1; i--)
					{
						_allocation.construct(&_arrey[i], _arrey[i - n]);
						_allocation.destroy(&_arrey[i - n]);
					}
					for (size_type i = index; i < index + n; i++)
					{
						_allocation.construct(&_arrey[i], *first);
						_current++;
						first++;
					}
				};

				/* Push back : Adds a new element at the end of the vector, after its current last element. It increases the container size by one, which causes an automatic reallocation of the allocated storage space if -and only if- the new vector size surpasses the current vector capacity.*/
			void push_back(const T& x)
			{
				insert(end(), 1, x);
			};

				/* Pop back : Removes the last element in the vector, effectively reducing the container size by one.	This destroys the removed element.*/
			void pop_back()
			{
				erase(end() - 1);
			};

				/* Clear : Erases all elements from the container. After this call, size() returns zero.Invalidates any references, pointers, or iterators referring to contained elements. Any past-the-end iterators are also invalidated. Leaves the capacity() of the vector unchanged.*/
			void clear()
			{
				if	(_arrey)
				{
					for(size_type i = 0; i < _current; i++)
					{
						_allocation.destroy(&_arrey[i]);
					}
				}
				_current = 0;
			};

				/* Assign : Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.*/

				/* Prototype 1 */
			template <class InputIterator>
				void assign (InputIterator first, InputIterator last)
				{
					InputIterator tmp = first;
					size_type n = 0;
					
					while (tmp != last)
					{
						tmp++;
						n++;
					}
					clear();
					reserve(n);
				 	insert(begin(), first, last);
				};	
				
				/* Prototype 2 */
			void assign (size_type n, const value_type& val)
			{
				clear();
				reserve(n);
				insert(begin(), n, val);
			};

				/*Erase : Removes from the vector either a single element (position) or a range of elements ([first,last)). This effectively reduces the container size by the number of elements removed, which are destroyed. Return value : An iterator pointing to the new location of the element that followed the last element erased by the function call*/
			
				/* Prototype 1 */
			iterator erase (iterator position)
			{
				size_type index = position - begin();
				_current--;
				for (size_type i = index; i < _current; i++)
				{
					_allocation.destroy(&_arrey[i]);
					_allocation.construct(&_arrey[i], _arrey[i + 1]);
				}
				return (iterator(&_arrey[index]));
			};
				/* Prototype 2 */
			iterator erase (iterator first, iterator last)
			{
				size_type index = first - begin();
				size_type diff = last - first;
				while(first != last)
				{
					_allocation.destroy(&(*first));
					first++;
				}
				_current -= diff;
				if	(diff < _current)
				{
					for (size_type i = index; i < _current; i++)
					{
						_allocation.destroy(&_arrey[i + diff]);
						_allocation.construct(&_arrey[i], _arrey[i + diff]);
					}
				}
				return (iterator(&_arrey[index]));
			};

			void swap (vector& other)
			{
				pointer	tmp_arrey = other._arrey;
				other._arrey = _arrey;
				_arrey = tmp_arrey;

				size_type	tmp_current = other._current;
				other._current = _current;
				_current = tmp_current;

				size_type	tmp_capacity = other._capacity;
				other._capacity = _capacity;
				_capacity = tmp_capacity;

				allocator_type	tmp_allocation = other._allocation;
				other._allocation = _allocation;
				_allocation = tmp_allocation;
			};
/* ************************************************************************** */
/*                                 Element acces :                            */
/* ************************************************************************** */
	
	reference 				operator[] (size_type n) { return _arrey[n]; };
	const_reference 		operator[] (size_type n) const { return _arrey[n]; };

		/* at : Access element. Returns a reference to the element at position n in the vector. The function automatically checks whether n is within the bounds of valid elements in the vector, throwing an out_of_range exception if it is not (i.e., if n is greater than, or equal to, its size). This is in contrast with member operator[], that does not check against bounds.*/
		
		/* Prototype 1 */
	reference at (size_type n)
	{
		if (n >= _current)
		{
			std::stringstream str;
			str << "vector::_M_range_check: __n (which is " << n << ") >= this->size() (which is " << _current << ")";
			throw std::out_of_range(str.str().c_str());
		}
		return (_arrey[n]);
	};

		/* Prototype 2 */
	const_reference at (size_type n) const
	{
		if (n >= _current)
		{
			std::stringstream str;
			str << "vector::_M_range_check: __n (which is " << n << ") >= this->size() (which is " << _current << ")";
			throw std::out_of_range(str.str().c_str());
		}
		return (_arrey[n]);
	};

		/* front : Access first element. Returns a reference to the first element in the vector. Unlike member vector::begin, which returns an iterator to this same element, this function returns a direct reference.Calling this function on an empty container causes undefined behavior..*/
		
		/* Prototype 1 */
	reference front()
	{
			return (*_arrey);
	};
	
		/* Prototype 2 */
	const_reference front() const
	{
		return (*_arrey);
	};

			/* back :Access last element. Returns a reference to the last element in the vector. Unlike member vector::end, which returns an iterator just past this element, this function returns a direct reference..*/

		/* Prototype 1 */
		reference back()
	{
			return (*(end() - 1));
	};
	
		/* Prototype 2 */
	const_reference back() const
	{
		return (*(end() - 1));
	};

/* ************************************************************************** */
/*                                 Allocator :                                */
/* ************************************************************************** */


	allocator_type get_allocator() const
	{
		return (_allocation);
	};


/* ************************************************************************** */
/*                                 Attributes :                                 */
/* ************************************************************************** */

		private:
			allocator_type	_allocation;
			
			// arrey is  the pointer which stores the address of our vector(first element)
			pointer 		_arrey;

			// capacity is the total storage capacity of the vector
			size_type 		_capacity;

			// current is the number of element currently present in the vector
			size_type 		_current;
	};


/* ************************************************************************** */
/*                                 Non member functions :                     */
/* ************************************************************************** */

	template <class T, class Allocator>
	inline bool operator==(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()) ? true : false);
	}

	template <class T, class Allocator>
	inline bool operator<(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs)
	{ 
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); 
	}

	template <class T, class Allocator>
	inline bool operator!=(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs)
	{ return not (lhs == rhs); }

	template <class T, class Allocator>
	inline bool operator>(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs)
	{ return rhs < lhs; }

	template <class T, class Allocator>
	inline bool operator>=(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs)
	{ return not (lhs < rhs); }

	template <class T, class Allocator>
	inline bool operator<=(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs)
	{ return not (rhs < lhs); }

	template <class T, class Allocator>
		void swap(vector<T, Allocator> &x, vector<T, Allocator> &y)
		{ x.swap(y); }
}

