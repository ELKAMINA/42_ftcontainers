#include <iostream>
#include <iomanip>
#include <vector>
#include "./includes/Stack.hpp"
#include "./includes/vector.hpp"
#include "./includes/ReverseIterator.hpp"

/* For colours in terminal/outputs : https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal*/

using namespace std;
#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type

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
		vector<int> vct(5);
		vector<int> vct2;
		// const int cut = 3;

		for (unsigned long int i = 0; i < vct.size(); ++i)
			vct[i] = (vct.size() - i) * 7;
		printSize(vct);

		// vct2.insert(vct2.begin(), vct.begin(), vct.begin() + cut);
		// printSize(vct2);
		// vct2.insert(vct2.begin(), vct.begin() + cut, vct.end());
		// printSize(vct2);
		// vct2.insert(vct2.end(), vct.begin(), vct.begin() + cut);
		// printSize(vct2);

		// std::cout << "insert return:" << std::endl;

		// std::cout << *vct2.insert(vct2.end(), 42) << std::endl;
		// std::cout << *vct2.insert(vct2.begin() + 5, 84) << std::endl;
		// std::cout << "----------------------------------------" << std::endl;

		// printSize(vct2);

	}
	{
		std::cout << "\e[0;34m My Vector -> >>>> \e[0m" << std::endl;
		ft::vector<int> vct(5);
		ft::vector<int> vct2;
		// const int cut = 3;

		for (unsigned long int i = 0; i < vct.size(); ++i)
			vct[i] = (vct.size() - i) * 7;
		printSize(vct);

		// vct2.insert(vct2.begin(), vct.begin(), vct.begin() + cut);
		// printSize(vct2);
		// vct2.insert(vct2.begin(), vct.begin() + cut, vct.end());
		// printSize(vct2);
		// vct2.insert(vct2.end(), vct.begin(), vct.begin() + cut);
		// printSize(vct2);

		// std::cout << "insert return:" << std::endl;

		// std::cout << *vct2.insert(vct2.end(), 42) << std::endl;
		// std::cout << *vct2.insert(vct2.begin() + 5, 84) << std::endl;
		// std::cout << "----------------------------------------" << std::endl;

		// printSize(vct2);

	}
	return (0);
}