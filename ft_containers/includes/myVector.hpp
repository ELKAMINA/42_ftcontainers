
/* explicit keyword : to avoid implicit casts/conversions */
#include <memory> // for allocator

namespace ft {
	template <class T, class Allocator = allocator<T> >
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
		typedef random_access_iterator<value_type>;
		typedef random_access_iterator<const value_type>;
		typedef std::reverse_iterator<iterator> reverse_iterator;
		typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef ptrdiff_t												difference_type;
		typedef size_t													size_type;

		private:
			allocator_type	_allocation
			// arr is the size_teger posize_ter which stores the address of our vector
			pointer 		_arrey;

			// capacity is the total storage capacity of the vector
			size_type 		_capacity;

			// current is the number of element currently present in the vector
			size_type 		_current;



		/*************************************************************************/
		/*                			Constructors 						        */
		/* *********************************************************************/

		/* default constructor for an empty container */
		explicit vector (const allocator_type& alloc = allocator_type()); 
		
		/* Constructor container with n elements */
		explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type());
		
		/* Constructs a container with as many elements as the range [first,last)  */
		template <class InputIterator>
        vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type());

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
