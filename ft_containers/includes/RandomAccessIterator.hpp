#pragma once

#include "./iterator_traits.hpp"
#include "./iterator_baseClass.hpp"
#include "./is_integral.hpp"
#include "./remove_cv.hpp"

namespace ft
{
    template<typename T>
    class RandomAccessIterator : public ft::iterator<std::random_access_iterator_tag, T>
    {
        public:
            /* Shorthands and definitions */
			typedef 		 ft::iterator<std::random_access_iterator_tag, T>  		standard;
            typedef typename standard::difference_type      						difference_type;
            typedef typename standard::value_type           						value_type;
            typedef typename standard::pointer              						pointer;
            typedef typename standard::reference            						reference;
            typedef typename standard::iterator_category    						iterator_category;

            /* Constructors and Destructors */
            RandomAccessIterator() : _ptr(NULL) {}
            RandomAccessIterator(pointer ptr) : _ptr(ptr) {}
            RandomAccessIterator(const RandomAccessIterator<typename remove_cv<value_type>::type> &other) : _ptr(other.base()) {}
            virtual ~RandomAccessIterator() {} // virtual destructor : why?

            /* Retrieve the current pointer */
            pointer base() const { return this->_ptr;};
            
            /* Comparison Operators */
            RandomAccessIterator &operator=(const RandomAccessIterator<typename remove_cv<value_type>::type> &other)
            {
            //     if (this != &other)
                _ptr = other.base();
                return *this;
            }
            bool operator==(const RandomAccessIterator &other) const { return _ptr == other.base(); } // OK
            bool operator!=(const RandomAccessIterator &other) const { return _ptr != other.base(); } // OK
            bool operator<(const RandomAccessIterator &other) const { return _ptr < other.base(); }
            bool operator<=(const RandomAccessIterator &other) const { return _ptr <= other.base(); }
            bool operator>(const RandomAccessIterator &other) const { return _ptr > other.base(); }
            bool operator>=(const RandomAccessIterator &other) const { return _ptr >= other.base(); }

            /* Operators */
            reference operator*() const {return *_ptr; } // OK
            pointer operator->() const { return _ptr; } // OK
            RandomAccessIterator &operator++() { ++_ptr; return *this; } // OK
            RandomAccessIterator operator++(int) { RandomAccessIterator tmp(*this); ++_ptr; return tmp; } // OK
            RandomAccessIterator &operator--() { --_ptr; return *this; } // OK prefix -- 
            RandomAccessIterator operator--(int) { RandomAccessIterator tmp(*this); --_ptr; return tmp; } // OK postfix --
            RandomAccessIterator operator+(difference_type n) const { return RandomAccessIterator(_ptr + n); } // OK
            RandomAccessIterator operator-(difference_type n) const { return RandomAccessIterator(_ptr - n); } // OK
            RandomAccessIterator &operator+=(difference_type n) { _ptr += n; return *this; } //OK arithmetic op between iterator and int value/another it
            RandomAccessIterator &operator-=(difference_type n) { _ptr -= n; return *this;}// OK arithmetic op between iterator and int value/another it
            reference operator[](difference_type n) const { return _ptr[n]; } //OK

        	private:
          		pointer _ptr; // pointer to the current element
    
        };

        /* Template specialisations for operators - Different cases */
        template <typename T>
        inline bool operator==(const ft::RandomAccessIterator<T> &lhs, const ft::RandomAccessIterator<T> &rhs)
        { return lhs.base() == rhs.base(); }

        template<typename T1, typename T2>
        inline bool operator==(const ft::RandomAccessIterator<T1> &lhs, const ft::RandomAccessIterator<T2> &rhs)
        { return lhs.base() == rhs.base(); }

        template <typename T>
        inline bool operator!=(const ft::RandomAccessIterator<T> &lhs, const ft::RandomAccessIterator<T> &rhs)
        { return lhs.base() != rhs.base(); }

        template<typename T1, typename T2>
        inline bool operator!=(const ft::RandomAccessIterator<T1> &lhs, const ft::RandomAccessIterator<T2> &rhs)
        { return lhs.base() != rhs.base(); }

        template <typename T>
        inline bool operator<(const ft::RandomAccessIterator<T> &lhs, const ft::RandomAccessIterator<T> &rhs)
        { return lhs.base() < rhs.base(); }

        template<typename T1, typename T2>
        inline bool operator<(const ft::RandomAccessIterator<T1> &lhs, const ft::RandomAccessIterator<T2> &rhs)
        { return (lhs.base() < rhs.base()); }

        template <typename T>
        inline bool operator>(const ft::RandomAccessIterator<T> &lhs, const ft::RandomAccessIterator<T> &rhs)
        { return lhs.base() > rhs.base(); }

        template<typename T1, typename T2>
        inline bool operator>(const ft::RandomAccessIterator<T1> &lhs, const ft::RandomAccessIterator<T2> &rhs)
        { return lhs.base() > rhs.base(); }

        template <typename T>
        inline bool operator<=(const ft::RandomAccessIterator<T> &lhs, const ft::RandomAccessIterator<T> &rhs)
        { return lhs.base() <= rhs.base(); }

        template<typename T1, typename T2>
        inline bool operator<=(const ft::RandomAccessIterator<T1> &lhs,
                const ft::RandomAccessIterator<T2> &rhs)
        { return lhs.base() <= rhs.base(); }

        template <typename T>
        inline bool operator>=(const ft::RandomAccessIterator<T> &lhs,
                const ft::RandomAccessIterator<T> &rhs)
        { return lhs.base() >= rhs.base(); }

        template<typename T1, typename T2>
        inline bool operator>=(const ft::RandomAccessIterator<T1> &lhs, const ft::RandomAccessIterator<T2> &rhs)
        { return lhs.base() >= rhs.base(); }

        template<typename T>
        inline ft::RandomAccessIterator<T> operator+(typename ft::RandomAccessIterator<T>::difference_type n,typename ft::RandomAccessIterator<T> it)
        { return &(*it) + n; }

        template <typename T>
        inline typename ft::RandomAccessIterator<T>::difference_type operator-(const ft::RandomAccessIterator<T> &lhs, const ft::RandomAccessIterator<T> &rhs)
        { return lhs.base() - rhs.base(); }

        template<typename T1, typename T2>
        inline typename ft::RandomAccessIterator<T1>::difference_type operator-(const ft::RandomAccessIterator<T1> &lhs, const ft::RandomAccessIterator<T2> &rhs)
        { return lhs.base() - rhs.base(); }
} 
