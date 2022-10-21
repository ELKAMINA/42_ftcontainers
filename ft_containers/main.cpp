#include <iostream>
#include <iomanip>
#include "./includes/Vector.hpp"

int main()
{
	Vector<int> kikou;

	/* *** Normal push *** */
	kikou.push(5);
	kikou.push(10);
	kikou.push(20);
	kikou.push(30);
	// std::cout << "Capacity : " << kikou.getcapacity() << std::endl;
	// std::cout << "Size : " << kikou.size() << std::endl;
	kikou.print();

	/* *** push at a certain index *** */
	kikou.push(150, 2);
	kikou.print();

	/* *** Resize without reassigning *** */
	// kikou.resize(7);
	// kikou.print();

	/* *** Resize without reassigning *** */
	kikou.resize(8, 50);
	kikou.print();
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