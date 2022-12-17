#pragma once
/* explicit keyword : to avoid implicit casts/conversions */
#include <memory> // for allocator
#include "./enable_if.hpp"
#include "./RandomAccessIterator.hpp"

namespace ft {
	template <class T, class Allocator = std::allocator<T> >
	class vector {
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
		typedef RandomAccessIterator<value_type>						iterator;
		typedef RandomAccessIterator<const value_type>					const_iterator;
		typedef std::reverse_iterator<iterator> 						reverse_iterator;
		typedef std::reverse_iterator<const_iterator> 					const_reverse_iterator;
		typedef ptrdiff_t												difference_type;
		typedef size_t													size_type;

		private:
			allocator_type	_allocation
			
			// arrey is  the pointer which stores the address of our vector
			pointer 		_arrey;

			// capacity is the total storage capacity of the vector
			size_type 		_capacity;

			// current is the number of element currently present in the vector
			size_type 		_current;



		/*************************************************************************/
		/*                			Constructors 						        */
		/* *********************************************************************/

		/* default constructor : creates an empty container */
		explicit vector (const allocator_type& alloc = allocator_type()) : _allocation(alloc), _current(0), _capacity(0)
		{
			_arrey = NULL
		}
		
		/* Constructor container with n elements */
		explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type()) : _allocation(alloc), _current(n), _capacity(n)
		{
			_arrey = _allocation.allocate(_capacity); /* allocate() func allocate memory for a container. It returns a pointer to the start of the allocated memory */
			for	(size_type i = 0; i < _size; i++)
			{
				_allocation.construct(&_arrey[i], val); /* construct () is used to construct an object in allocated memory */
			}
		}
		
		/* Constructs a container with as many elements as the range [first,last)  */
		template <class InputIterator, typename ft::enable_if<ft::is_integral<T>::value,
                                 T>::type* = nullptr>
        vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type())
		{
			/* Start with iterators and functions */
			// _arrey = NULL;
			// insert(begin(), first, last);
		}

		/* Constructs a container with a copy of each of the elements in x, in the same order.  */
		vector (const vector& x);

		template <class InputIterator>
		vector(InputIterator first, InputIterator last,
		const Allocator& = Allocator());
		vector(const vector<T,Allocator>& x);
		~vector();
		vector<T,Allocator>& operator=(const vector<T,Allocator>& x);
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last);
		void assign(size_type n, const T& u);
		allocator_type get_allocator() const;
		// iterators:
		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;
		// 23.2.4.2 capacity:
		size_type size() const;
		size_type max_size() const;
		void resize(size_type sz, T c = T());
		size_type capacity() const;
		bool empty() const;
		void reserve(size_type n);
		// element access:
		reference operator[](size_type n);
		const_reference operator[](size_type n) const;
		const_reference at(size_type n) const;
		reference at(size_type n);
		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;
		// 23.2.4.3 modifiers:
		void push_back(const T& x);
		void pop_back();
		iterator insert(iterator position, const T& x);
		void insert(iterator position, size_type n, const T& x);
		template <class InputIterator>
		void insert(iterator position,
		InputIterator first, InputIterator last);
		iterator erase(iterator position);
		iterator erase(iterator first, iterator last);
		void swap(vector<T,Allocator>&);
		void clear();
	}
}
