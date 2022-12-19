#pragma once
#include "./iterator_traits.hpp"
#include "./iterator_baseClass.hpp"
#include "./is_integral.hpp"

namespace ft
{
    template<typename T>
    class reverse_iterator : public ft::iterator<std::random_access_iterator_tag, T>
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

            /* Constructors and Destructors */
            reverse_iterator() {}
            reverse_iterator(pointer ptr) : _ptr(ptr) {}
            reverse_iterator(const reverse_iterator<T> &other) : _ptr(other._ptr) {}
            virtual ~reverse_iterator() {} // virtual destructor : why?

            /* Retrieve the current pointer */
            pointer base() const { return this->_ptr;};
            
            /* Comparison Operators */
            reverse_iterator &operator=(const reverse_iterator &other)
            {
                if (this != &other)
                    _ptr = other._ptr;
                return *this;
            }
            bool operator==(const reverse_iterator &other) const { return _ptr == other._ptr; } // OK
            bool operator!=(const reverse_iterator &other) const { return _ptr != other._ptr; } // OK
            bool operator<(const reverse_iterator &other) const { return _ptr < other._ptr; }
            bool operator<=(const reverse_iterator &other) const { return _ptr <= other._ptr; }
            bool operator>(const reverse_iterator &other) const { return _ptr > other._ptr; }
            bool operator>=(const reverse_iterator &other) const { return _ptr >= other._ptr; }

            /* Operators */
            reference operator*() const {return *_ptr; } // OK
            pointer operator->() const { return _ptr; } // OK
            reverse_iterator &operator++() { ++_ptr; return *this; } // OK
            reverse_iterator operator++(int) { reverse_iterator tmp(*this); ++_ptr; return tmp; } // OK
            reverse_iterator &operator--() { --_ptr; return *this; } // OK prefix -- 
            reverse_iterator operator--(int) { reverse_iterator tmp(*this); --_ptr; return tmp; } // OK postfix --
            reverse_iterator operator+(difference_type n) const { return reverse_iterator(_ptr + n); } // OK
            reverse_iterator operator-(difference_type n) const { return reverse_iterator(_ptr - n); } // OK
            reverse_iterator &operator+=(difference_type n) { _ptr += n; return *this; } //OK arithmetic op between iterator and int value/another it
            reverse_iterator &operator-=(difference_type n) { _ptr -= n; return;}// OK arithmetic op between iterator and int value/another it
            reference operator[](difference_type n) const { return _ptr[n]; } //OK

        	private:
          		pointer _ptr; // pointer to the current element
    
        };

        /* Template specialisations for operators - Different cases */
        template <typename T>
        inline bool operator==(const ft::reverse_iterator<T> &lhs, const ft::reverse_iterator<T> &rhs)
        { return lhs.base() == rhs.base(); }

        template<typename T1, typename T2>
        inline bool operator==(const ft::reverse_iterator<T1> &lhs, const ft::reverse_iterator<T2> &rhs)
        { return lhs.base() == rhs.base(); }

        template <typename T>
        inline bool operator!=(const ft::reverse_iterator<T> &lhs, const ft::reverse_iterator<T> &rhs)
        { return lhs.base() != rhs.base(); }

        template<typename T1, typename T2>
        inline bool operator!=(const ft::reverse_iterator<T1> &lhs, const ft::reverse_iterator<T2> &rhs)
        { return lhs.base() != rhs.base(); }

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
                                                         