#pragma once
#include "./iterator_traits.hpp"
#include "./iterator_baseClass.hpp"
#include "./is_integral.hpp"


/* Exemple d'appels de reverse_iterator : 
	>>> std::reverse_iterator<std::vector<int>::iterator> rit(v.end()); >>> */

/* Reverse iterator is an adaptor for the real iterator */

namespace ft
{
    template<typename T>
    class reverse_iterator
    {
        public:
            /* Shorthands and definitions */
			typedef 		ft::iterator_traits<T>  								standard;
			typedef			T														iterator_type;				
            typedef typename standard::difference_type      						difference_type;
            typedef typename standard::value_type           						value_type;
            typedef typename standard::pointer              						pointer;
            typedef typename standard::reference            						reference;
            typedef typename standard::iterator_category    						iterator_category;


/* ************************************************************************** */
/*                                Member functions : 	                      */
/* ************************************************************************** */
				/* Prototype 1 : Default constructor */
            reverse_iterator() : base()
			{
				// std::cout << "LOL" << std::endl;
			};

				/* Prototype 2 : Parametric constructor*/
			explicit reverse_iterator (iterator_type it) : base(it)
			{
				// std::cout << "LOL 1" << std::endl;
			};

				/* Prototype 3 : Copy constructor */
            template <class Iter>
  				reverse_iterator (const reverse_iterator<Iter>& rev_it) : base(rev_it.getBase()) 
				{
					// std::cout << "LOL 2" << std::endl;
				};

            	/* base : Return base iterator. Returns a copy of the base iterator. The base iterator is an iterator of the same type as the one used to construct the reverse_iterator, but pointing to the element next to the one the reverse_iterator is currently pointing to Retrieve the current pointer */
			iterator_type getBase() const 
			{
				// std::cout << "LOL 3" << std::endl;
				return base;
			};
            
            /* Comparison Operators */
            reverse_iterator &operator=(const reverse_iterator &other)
            {
				// std::cout << "LOL 4" << std::endl;
                if (this != &other)
                    base = other.base;
                return *this;
            }
            bool operator==(const reverse_iterator &other) const { return base == other.base; }

            // bool operator!=(const reverse_iterator &other) const { return base != other.base; }
            // bool operator<(const reverse_iterator &other) const { return base < other.base; }
            // bool operator<=(const reverse_iterator &other) const { return base <= other.base; }
            // bool operator>(const reverse_iterator &other) const { return base > other.base; }
            // bool operator>=(const reverse_iterator &other) const { return base >= other.base; }

            /* Operators */
				/* Operator* : Dereference iterator. Returns a reference to the element pointed to by the iterator. Internally, the function decreases a copy of its base iterator and returns the result of dereferencing it. The iterator shall point to some object in order to be dereferenceable.*/
            reference operator*() const
			{
				// std::cout << " je rentre ici 7" << std::endl;
				iterator_type mtp = base;
				mtp--;
				return (*mtp);
			};

            reverse_iterator operator++(int) // post
			{
				return (reverse_iterator(base--));
			}; // OK
            
			reverse_iterator &operator++() // pre
			{ 
				// std::cout << " je rentre ici 1" << std::endl;
				--base; 
				return (*this); 
			}; // OK	

			reverse_iterator operator--(int) // post
			{
				return (reverse_iterator(base++));
			}; // OK
            
			reverse_iterator &operator--() // pre
			{ 
				// std::cout << " je rentre ici 1" << std::endl;
				++base; 
				return (*this); 
			}; // OK
            
			// Returns a reverse_iterator which is advanced by n.
			reverse_iterator	operator+(difference_type n) const
			{
				return (reverse_iterator(base - n));
			}

			// Returns a reverse_iterator which is advanced by -n.
			reverse_iterator	operator-(difference_type n) const
			{
				return (reverse_iterator(base + n));
			}

			// Advance the current reverse_iterator by n.
			reverse_iterator&	operator+=(difference_type n)
			{
				base -= n;
				return (*this);
			}

			// Advance the current reverse_iterator by n.
			reverse_iterator&	operator-=(difference_type n)
			{
				base += n;
				return (*this);
			}

            iterator_type operator->() const { iterator_type tmp = base;
				return &*--tmp;; } // OK
			
			reference operator[] (size_t n) const { 
				
				return *(*this + n);
			};

			
        	protected :
          		iterator_type base; 
        };

        /* Template specialisations for operators - Different cases */
        template <typename T>
			inline bool operator==(const ft::reverse_iterator<T> &lhs, const ft::reverse_iterator<T> &rhs)
			{ 
				// std::cout << " je rentre ici 4" << std::endl;
				return lhs.getBase() == rhs.getBase(); }

        template<typename T1, typename T2>
			inline bool operator==(const ft::reverse_iterator<T1> &lhs, const ft::reverse_iterator<T2> &rhs)
			{
				// std::cout << " je rentre ici 6" << std::endl;
				return lhs.getBase() == rhs.getBase(); }

		template <typename T>
		inline bool operator!=(const ft::reverse_iterator<T> &lhs, const ft::reverse_iterator<T> &rhs)
		{ 
			// std::cout << " je rentre ici " << std::endl;
			return lhs.getBase() != rhs.getBase(); 
		}

		template<typename T1, typename T2>
		inline bool operator!=(const ft::reverse_iterator<T1> &lhs, const ft::reverse_iterator<T2> &rhs)
		{ 
			// std::cout << " je rentre ici 2" << std::endl;
			return lhs.getBase() != rhs.getBase(); }


        template <typename T>
        inline bool operator<(const ft::reverse_iterator<T> &lhs, const ft::reverse_iterator<T> &rhs)
        { return lhs.base() < rhs.base(); }

        template<typename T1, typename T2>
        inline bool operator<(const ft::reverse_iterator<T1> &lhs, const ft::reverse_iterator<T2> &rhs)
        { return lhs.base() < rhs.base(); }

        template <typename T>
        inline bool operator>(const ft::reverse_iterator<T> &lhs, const ft::reverse_iterator<T> &rhs)
        { return lhs.base() > rhs.base(); }

        template<typename T1, typename T2>
        inline bool operator>(const ft::reverse_iterator<T1> &lhs, const ft::reverse_iterator<T2> &rhs)
        { return lhs.base() > rhs.base(); }

        template <typename T>
        inline bool operator<=(const ft::reverse_iterator<T> &lhs, const ft::reverse_iterator<T> &rhs)
        { return lhs.base() <= rhs.base(); }

        template<typename T1, typename T2>
        inline bool operator<=(const ft::reverse_iterator<T1> &lhs,
                const ft::reverse_iterator<T2> &rhs)
        { return lhs.base() <= rhs.base(); }

        template <typename T>
        inline bool operator>=(const ft::reverse_iterator<T> &lhs,
                const ft::reverse_iterator<T> &rhs)
        { return lhs.base() >= rhs.base(); }

        template<typename T1, typename T2>
        inline bool operator>=(const ft::reverse_iterator<T1> &lhs, const ft::reverse_iterator<T2> &rhs)
        { return lhs.base() >= rhs.base(); }

        template<typename T>
        inline ft::reverse_iterator<T> operator+(typename ft::reverse_iterator<T>::difference_type n,typename ft::reverse_iterator<T> it)
        { return &(*it) + n; }

        template <typename T>
        inline typename ft::reverse_iterator<T>::difference_type operator-(const ft::reverse_iterator<T> &lhs, const ft::reverse_iterator<T> &rhs)
        { return lhs.base() - rhs.base(); }

        template<typename T1, typename T2>
        inline typename ft::reverse_iterator<T1>::difference_type operator-(const ft::reverse_iterator<T1> &lhs, const ft::reverse_iterator<T2> &rhs)
        { return lhs.base() - rhs.base(); }
} 
                                                         