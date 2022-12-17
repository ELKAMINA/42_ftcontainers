#pragma once

/* recoding enable_if use a combination of template metaprogramming and type traits */

namespace ft
{
	// primary template for enable_if
	template <bool B, typename T = void>
	struct enable_if {};

	// partial specialization for true
	template <typename T>
	struct enable_if<true, T> 
	{
		typedef T type;
	};
}