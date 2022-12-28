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

		ft::pair<int, int> pr(10,30);
		ft::pair<int, int> pr1(18,20);
		ft::pair<int, int> pr2(7,90);
		ft::pair<int, int> pr3(15,90);
		ft::pair<int, int> pr4(16,90);
		ft::pair<int, int> pr5(30,90);
		ft::pair<int, int> pr6(25,90);

		ft::pair<int, int> pr7(40,90);
		ft::pair<int, int> pr8(60,90);
		ft::pair<int, int> pr9(2,90);
		ft::pair<int, int> pr10(1,90);
		ft::pair<int, int> pr11(70,90);
		ft::map<int, int> kikou;
		kikou.insert_node(pr);
		kikou.insert_node(pr1);
		kikou.insert_node(pr2);
		kikou.insert_node(pr3);
		kikou.insert_node(pr4);
		kikou.insert_node(pr5);
		kikou.insert_node(pr6);
		kikou.insert_node(pr7);
		kikou.insert_node(pr8);
		kikou.insert_node(pr9);
		kikou.insert_node(pr10);
		kikou.insert_node(pr11);
		kikou.deleteNode(pr1);


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