#include <iostream>
#include <iomanip>
#include "./includes/Vector.hpp"

int main()
{
	Vector<int> kikou;

	kikou.push(5);
	// kikou.push(10);
	std::cout << "Capacity : " << kikou.getcapacity() << std::endl;
	std::cout << "Size : " << kikou.size() << std::endl;
	// kikou.push(120);
	// kikou.push(-951);
	// kikou.push(223);
	// kikou.push(575);
	// kikou.push(854);
	// kikou.push(11);
	// kikou.push(21);
	// kikou.push(66);
	// kikou.pop();
	// kikou.print();
	// kikou.size();

}