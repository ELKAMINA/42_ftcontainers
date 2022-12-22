#include <iostream>
#include <iomanip>
#include <vector>
#include "./includes/Stack.hpp"
#include "./includes/vector.hpp"
#include "./includes/ReverseIterator.hpp"
#include "./base.hpp"

/* For colours in terminal/outputs : https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal*/

using namespace std;
#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type
#define TESTED_TYPE int

template <typename T>
void	printSize(vector<T> const &vct, bool print_content = true)
{
	const typename vector<T>::size_type size = vct.size();
	const typename vector<T>::size_type capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << vct.capacity() << " " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename vector<T>::const_iterator it = vct.begin();
		typename vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

template <typename T>
void	printSize(ft::vector<T> const &vct, bool print_content = true)
{
	const typename ft::vector<T>::size_type size = vct.size();
	const typename ft::vector<T>::size_type capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << vct.capacity() << " " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename ft::vector<T>::const_iterator it = vct.begin();
		typename ft::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}


int		main(void)
{
	{
		std::cout << "\e[0;34m Real Vector -> >>>> \e[0m" << std::endl;

		const int start_size = 7;
		vector<TESTED_TYPE> vct(start_size, 20);
		vector<TESTED_TYPE> vct2;
		vector<TESTED_TYPE>::iterator it = vct.begin();

		for (int i = 2; i < start_size; ++i)
			it[i] = (start_size - i) * 3;
		// printSize(vct, true);

		vct.resize(10, 42);
		// printSize(vct, true);

		vct.resize(18, 43);
		// printSize(vct, true);
		vct.resize(10);
		// printSize(vct, true);
		// // // printSize(vct, true);
		vct.resize(23, 44);
		printSize(vct, true);
		// vct.resize(5);
		// printSize(vct, true);
		// vct.reserve(5);
		// vct.reserve(3);
		// printSize(vct, true);
		// vct.resize(87);
		// vct.resize(5);
		// printSize(vct, true);

		// is_empty(vct2);
		// vct2 = vct;
		// is_empty(vct2);
		// vct.reserve(vct.capacity() + 1);
		// printSize(vct, true);
		// printSize(vct2, true);

		// vct2.resize(0);
		// is_empty(vct2);
		// printSize(vct2, true);
	}
	{
		std::cout << "\e[0;34m My Vector -> >>>> \e[0m" << std::endl;
		const int start_size = 7;
		ft::vector<TESTED_TYPE> vct(start_size, 20);
		ft::vector<TESTED_TYPE> vct2;
		ft::vector<TESTED_TYPE>::iterator it = vct.begin();

		for (int i = 2; i < start_size; ++i)
			it[i] = (start_size - i) * 3;
		// printSize(vct, true);

		vct.resize(10, 42);
		// printSize(vct, true);

		vct.resize(18, 43);
		// printSize(vct, true);
		vct.resize(10);
		// printSize(vct, true);
		// // // printSize(vct, true);
		vct.resize(23, 44);
		printSize(vct, true);
		// vct.resize(5);
		// printSize(vct, true);
		// vct.reserve(5);
		// vct.reserve(3);
		// printSize(vct, true);
		// vct.resize(87);
		// vct.resize(5);
		// printSize(vct, true);

		// is_empty(vct2);
		// vct2 = vct;
		// is_empty(vct2);
		// vct.reserve(vct.capacity() + 1);
		// printSize(vct, true);
		// printSize(vct2, true);

		// vct2.resize(0);
		// is_empty(vct2);
		// printSize(vct2, true);

	}
	return (0);
}