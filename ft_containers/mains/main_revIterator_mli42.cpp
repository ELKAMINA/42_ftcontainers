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
	std::cout << "capacity: " << isCapacityOk << std::endl;
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
	std::cout << "capacity: " << isCapacityOk << std::endl;
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

		const int size = 5;
		vector<TESTED_TYPE> vct(size);
		vector<TESTED_TYPE>::reverse_iterator it = vct.rbegin();
		vector<TESTED_TYPE>::const_reverse_iterator ite = vct.rbegin();

		for (int i = 0; i < size; ++i)
			it[i] = (size - i) * 5;

		it = it + 5;
		it = 1 + it;
		it = it - 4;
		std::cout << *(it += 2) << std::endl;
		std::cout << *(it -= 1) << std::endl;

		*(it -= 2) = 42;
		*(it += 2) = 21;

		std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

		std::cout << "(it == const_it): " << (ite == it) << std::endl;
		std::cout << "(const_ite - it): " << (ite - it) << std::endl;
		std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

		printSize(vct, true);
	}
	{
		std::cout << "\e[0;34m My Vector -> >>>> \e[0m" << std::endl;
		const int size = 5;
		ft::vector<TESTED_TYPE> vct(size);
		ft::vector<TESTED_TYPE>::reverse_iterator it = vct.rbegin();
		ft::vector<TESTED_TYPE>::const_reverse_iterator ite = vct.rbegin();

		for (int i = 0; i < size; ++i)
			it[i] = (size - i) * 5;

		it = it + 5;
		it = 1 + it;
		it = it - 4;
		std::cout << *(it += 2) << std::endl;
		std::cout << *(it -= 1) << std::endl;

		*(it -= 2) = 42;
		*(it += 2) = 21;

		std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

		std::cout << "(it == const_it): " << (ite == it) << std::endl;
		std::cout << "(const_ite - it): " << (ite - it) << std::endl;
		std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

		printSize(vct, true);

	}
	return (0);
}