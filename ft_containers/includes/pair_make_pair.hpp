#pragma once
/* explicit keyword : to avoid implicit casts/conversions */
#include <memory> // for allocator
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <cstddef>
#include <iomanip>
#include "./enable_if.hpp"
#include "./equal.hpp"
#include "./lexicographical_compare.hpp"
#include "./RandomAccessIterator.hpp"
#include "./ReverseIterator.hpp"

namespace ft
{
	template <class T1, class T2>		struct pair
		{

			typedef T1					first_type;
			typedef T2					second_type;

			
			T1	first;
			T2	second;


		/*************************************************************************/
/*                Member functions :                   */
/* *********************************************************************/		

			// Default Constructors
				pair() : first(), second() {}

			// Parametric Constructors
			template<class U, class V>
				pair (const pair<U,V>& pr) : first(pr.first), second(second.pr) {};
			// Copy Constructors
	
			pair (const first_type& a, const second_type& b) : first(a), second(b) {
			}

			~pair(){}
			// Assignment operators
			// pair& operator=(const pair& other) {
			// 	first = other.first;
			// 	second = other.second;
			// 	return *this;
			// }

		};
			// Comparison operators

		template <class T1, class T2>
		bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
			return lhs.first==rhs.first && lhs.second==rhs.second;
		}

		template <class T1, class T2>
		bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
			return !(lhs==rhs);
		}

		template <class T1, class T2>
		bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
			return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
		}

		template <class T1, class T2>
		bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
			return !(rhs<lhs);
		}

		template <class T1, class T2>
		bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
			return rhs<lhs;
		}

		template <class T1, class T2>
		bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
			return !(lhs<rhs);
		}

		template <class T1,class T2>
			pair<const T1,T2> make_pair (T1 x, T2 y)
			{
				return (pair<T1,T2>(x,y));
			}


}