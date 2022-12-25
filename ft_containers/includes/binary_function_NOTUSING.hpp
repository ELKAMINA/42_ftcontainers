#pragma once

// A binary function is a function...
template <class FirstArg, class SecondArg, class Result>
	struct binary_function
	{
		typedef FirstArg		first_argument_type;
		typedef SecondArg		second_argument_type;

		typedef Result	result_type;
	};