#pragma once
/* explicit keyword : to avoid implicit casts/conversions */
#include <memory> // for allocator
#include <stdexcept>
#include "./enable_if.hpp"
#include "./RandomAccessIterator.hpp"

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
		//typedef std::reverse_iterator<iterator> 						reverse_iterator;
		//typedef std::reverse_iterator<const_iterator> 					const_reverse_iterator;
		typedef ptrdiff_t												difference_type;
		typedef size_t													size_type;

/*************************************************************************/
/*                			Constructors 						        */
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
			_arrey = _allocation.allocate(_current); /* allocate() func allocate memory for a container. It returns a pointer to the start of the allocated memory */
			for	(size_type i = 0; i < _current; i++)
			{
				_allocation.construct(&_arrey[i], val); /* construct () is used to construct an object in allocated memory */
			}
		};
		
		/* Range constructor : Constructs a container with as many elements as the range [first,last)  */
		// template <class InputIterator>
        // vector (InputIterator first, InputIterator last,
        //          const allocator_type& alloc = allocator_type(), typename ft::enable_if<ft::is_integral<InputIterator>::value,
        //                          <InputIterator>::type* = nullptr)
		// {
		// 	/* Start with iterators and functions */
		// 	// _arrey = NULL;
		// 	// insert(begin(), first, last);
		// }

		/* Constructs a container with a copy of each of the elements in x, in the same order.  */
		//vector (const vector& x)
		// {
			// _vector = NULL;
			// assign(x.begin(), x.end());
		// };

/*************************************************************************/
/*                			Destructors 						        */
/* *********************************************************************/

		// ~vector()
		// {
		// 	clear();
		// 	_allocation.deallocate(_arrey, _current);
		// };

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
			return (const_iterator(_current));
		};

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
				throw std::length_error("MY VECTOR : _M_fill_insert");
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
					
					while (tmp++ != last)
						n++;
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

				/*Erase : Removes from the vector either a single element (position) or a range of elements ([first,last)). This effectively reduces the container size by the number of elements removed, which are destroyed. Return value : An iterator pointing to the new location of the element that followed the last element erased by the function call*/
			// iterator erase (iterator position)
			// {

			// };
			// iterator erase (iterator first, iterator last);

		/* *********************************************************************  */
		// allocator_type get_allocator() const;
		// // iterators:
		// iterator end();
		// const_iterator end() const;
		// reverse_iterator rbegin();
		// const_reverse_iterator rbegin() const;
		// reverse_iterator rend();
		// const_reverse_iterator rend() const;
		// // 23.2.4.2 capacity:
		// size_type size() const;
		// size_type max_size() const;
		// void resize(size_type sz, T c = T());
		// size_type capacity() const;
		// bool empty() const;
		// void reserve(size_type n);
		// // element access:
		// reference operator[](size_type n);
		// const_reference operator[](size_type n) const;
		// const_reference at(size_type n) const;
		// reference at(size_type n);
		// reference front();
		// const_reference front() const;
		// reference back();
		// const_reference back() const;
		// // 23.2.4.3 modifiers:
		// void pop_back();
		// iterator insert(iterator position, const T& x);
		// void insert(iterator position, size_type n, const T& x);
		// template <class InputIterator>
		// void insert(iterator position,
		// InputIterator first, InputIterator last);
		// iterator erase(iterator position);
		// iterator erase(iterator first, iterator last);
		// void swap(vector<T,Allocator>&);
		// void clear();
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
}
