#pragma once
#include "./iterator_traits.hpp"
#include "./iterator_baseClass.hpp"

namespace ft
{
    template<typename T>
    class random_access_iterator : ft::iterator<std::random_access_iterator_tag, T>
    {
        private:
            pointer _ptr; // pointer to the current element
    
        public:
            /* Shorthands and definitions */

            typedef typename ft::iterator_traits<T>::difference_type      difference_type;
            typedef typename ft::iterator_traits<T>::value_type           value_type;
            typedef typename ft::iterator_traits<T>::pointer              pointer;
            typedef typename ft::iterator_traits<T>::reference            reference;
            typedef typename ft::iterator_traits<T>::iterator_category    iterator_category;

            /* Constructors and Destructors */
            random_access_iterator() : _ptr(NULL) {}
            random_access_iterator(pointer ptr) : _ptr(ptr) {}
            random_access_iterator(const random_access_iterator<T> &other) : _ptr(other._ptr) {}
            virtual ~random_access_iterator() {} // virtual destructor : why?

            /* Retrieve the current pointer */
            pointer base() { return this->current};
            
            /* Comparison Operators */
            random_access_iterator &operator=(const random_access_iterator &other)
            {
                if (this != &other)
                    _ptr = other._ptr;
                return *this;
            }
            bool operator==(const random_access_iterator &other) const { return _ptr == other._ptr; } // OK
            bool operator!=(const random_access_iterator &other) const { return _ptr != other._ptr; } // OK
            bool operator<(const random_access_iterator &other) const { return _ptr < other._ptr; }
            bool operator<=(const random_access_iterator &other) const { return _ptr <= other._ptr; }
            bool operator>(const random_access_iterator &other) const { return _ptr > other._ptr; }
            bool operator>=(const random_access_iterator &other) const { return _ptr >= other._ptr; }

            /* Operators */
            reference operator*() const { return *_ptr; } // OK
            pointer operator->() const { return _ptr; } // OK
            random_access_iterator &operator++() { ++_ptr; return *this; } // OK
            random_access_iterator operator++(int) { random_access_iterator tmp(*this); ++_ptr; return tmp; } // OK
            random_access_iterator &operator--() { --_ptr; return *this; } // OK prefix -- 
            random_access_iterator operator--(int) { random_access_iterator tmp(*this); --_ptr; return tmp; } // OK postfix --
            random_access_iterator operator+(difference_type n) const { return random_access_iterator(_ptr + n); } // OK
            random_access_iterator operator-(difference_type n) const { return random_access_iterator(_ptr - n); } // OK
            random_access_iterator &operator+=(difference_type n) { _ptr += n; return *this; } //OK arithmetic op between iterator and int value/another it
            random_access_iterator &operator-=(difference_type n) { _ptr -= n; return;}// OK arithmetic op between iterator and int value/another it
            reference operator[](difference_type n) const { return _ptr[n]; } //OK
        };

        /* Template specialisations for operators - Different cases */
        template <typename T>
        inline bool operator==(const ft::random_access_iterator<T> &lhs, const ft::random_access_iterator<T> &rhs)
        { return lhs.base() == rhs.base(); }

        template<typename T1, typename T2>
        inline bool operator==(const ft::random_access_iterator<T1> &lhs, const ft::random_access_iterator<T2> &rhs)
        { return lhs.base() == rhs.base(); }

        template <typename T>
        inline bool operator!=(const ft::random_access_iterator<T> &lhs, const ft::random_access_iterator<T> &rhs)
        { return lhs.base() != rhs.base(); }

        template<typename T1, typename T2>
        inline bool operator!=(const ft::random_access_iterator<T1> &lhs, const ft::random_access_iterator<T2> &rhs)
        { return lhs.base() != rhs.base(); }

        template <typename T>
        inline bool operator<(const ft::random_access_iterator<T> &lhs, const ft::random_access_iterator<T> &rhs)
        { return lhs.base() < rhs.base(); }

        template<typename T1, typename T2>
        inline bool operator<(const ft::random_access_iterator<T1> &lhs, const ft::random_access_iterator<T2> &rhs)
        { return lhs.base() < rhs.base(); }

        template <typename T>
        inline bool operator>(const ft::random_access_iterator<T> &lhs, const ft::random_access_iterator<T> &rhs)
        { return lhs.base() > rhs.base(); }

        template<typename T1, typename T2>
        inline bool operator>(const ft::random_access_iterator<T1> &lhs, const ft::random_access_iterator<T2> &rhs)
        { return lhs.base() > rhs.base(); }

        template <typename T>
        inline bool operator<=(const ft::random_access_iterator<T> &lhs, const ft::random_access_iterator<T> &rhs)
        { return lhs.base() <= rhs.base(); }

        template<typename T1, typename T2>
        inline bool operator<=(const ft::random_access_iterator<T1> &lhs,
                const ft::random_access_iterator<T2> &rhs)
        { return lhs.base() <= rhs.base(); }

        template <typename T>
        inline bool operator>=(const ft::random_access_iterator<T> &lhs,
                const ft::random_access_iterator<T> &rhs)
        { return lhs.base() >= rhs.base(); }

        template<typename T1, typename T2>
        inline bool operator>=(const ft::random_access_iterator<T1> &lhs, const ft::random_access_iterator<T2> &rhs)
        { return lhs.base() >= rhs.base(); }

        template<typename T>
        inline ft::random_access_iterator<T> operator+(typename ft::random_access_iterator<T>::difference_type n,typename ft::random_access_iterator<T> it)
        { return &(*it) + n; }

        template <typename T>
        inline typename ft::random_access_iterator<T>::difference_type operator-(const ft::random_access_iterator<T> &lhs, const ft::random_access_iterator<T> &rhs)
        { return lhs.base() - rhs.base(); }

        template<typename T1, typename T2>
        inline typename ft::random_access_iterator<T1>::difference_type operator-(const ft::random_access_iterator<T1> &lhs, const ft::random_access_iterator<T2> &rhs)
        { return lhs.base() - rhs.base(); }
} 
