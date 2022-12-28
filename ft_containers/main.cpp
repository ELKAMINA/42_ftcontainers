#include <iostream>
#include <iomanip>
#include <map>
#include "./includes/stack.hpp"
#include "./includes/vector.hpp"
#include "./includes/ReverseIterator.hpp"
#include "./includes/map.hpp"
#include <iostream>
#include <utility>
#include <functional>

/* For colours in terminal/outputs : https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal*/

// using namespace ft;

int main()
{
	{
		/*************************************************************************/
		/*                Constructors : 						                */
		/* *********************************************************************/

		ft::pair<int, int> pr(50,30);
		ft::pair<int, int> pr1(10,20);
		ft::pair<int, int> pr2(60,90);
		ft::map<int, int> kikou;
		kikou.insert_node(pr);
		kikou.insert_node(pr1);
		kikou.insert_node(pr2);

		// std::cout << kikou.size() << std::endl;
		kikou.printTree();
		// kikou.insert(pr);
		// kikou.printTrees();

		std::cout << " le vrai map " << std::endl;
		std::map<int, int> real;
		real.insert(std::pair<int, int> (50, 30));
		real.insert(std::pair<int, int> (10, 20));
		real.insert(std::pair<int, int> (60, 90));
		std::map<int, int>::iterator it = real.begin();
		for	(; it != real.end(); it++)
		{
			std::cout << "first : " << it->first << " second :" << it->second << std::endl;
			// std::cout << it-> << std::endl;
		}
		// real.printTree();
	}
  
}