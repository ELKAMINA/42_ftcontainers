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

/*************************************************************************/
/*                Insert : 						              			*/
/* *********************************************************************/
	{
		ft::map<int, int> kikou;
		ft::map<int, int> test2;
		kikou.insert(ft::pair<int, int> (10, 30));
		kikou.insert(ft::pair<int, int> (70, 30));
		kikou.insert(ft::pair<int, int> (50, 90));
		ft::map<int, int>::iterator it = kikou.begin();
		it++;
		kikou.insert(ft::pair<int, int> (90, 100));
		test2.insert(kikou.begin(), kikou.end());
		ft::map<int, int>::iterator it_test = test2.begin();
		for	(; it_test != test2.end(); it_test++)
		{
			std::cout << "first : " << it_test->first << " second :" << it_test->second << std::endl;
			// std::cout << it-> << std::endl;
		}
	}
// kikou.printTree();


/* ************************************************************************** */
/*                      Testing private func insert_node :                    */
/* ************************************************************************** */
		// kikou.insert_node(pr);
		// kikou.insert_node(pr1);
		// kikou.insert_node(pr2);
		// kikou.insert_node(pr3);
		// kikou.insert_node(pr4);
		// kikou.insert_node(pr5);
		// kikou.insert_node(pr6);
		// kikou.insert_node(pr7);
		// kikou.insert_node(pr8);
		// kikou.insert_node(pr9);
		// kikou.insert_node(pr10);
		// kikou.insert_node(pr11);
		// kikou.deleteNode(pr1);


		// std::cout << kikou.size() << std::endl;
		// kikou.insert(pr);
		// kikou.printTrees();
		{
			std::cout << std::endl;
			std::cout << " The Real MAP " << std::endl;
			std::map<int, int> real;
			std::map<int, int> test2;
			real.insert(std::pair<int, int> (10, 30));
			real.insert(std::pair<int, int> (70, 30));
			real.insert(std::pair<int, int> (50, 90));
			std::map<int, int>::iterator it = real.begin();
			it++;
			real.insert(it, std::pair<int, int> (90, 100));
			test2.insert(real.begin(), real.end());
			std::map<int, int>::iterator it_test = test2.begin();
			for	(; it_test != test2.end(); it_test++)
			{
				std::cout << "first : " << it_test->first << " second :" << it_test->second << std::endl;
				// std::cout << it-> << std::endl;
			}
			// for	(; it != real.end(); it++)
			// {
			// 	std::cout << "first : " << it->first << " second :" << it->second << std::endl;
			// 	// std::cout << it-> << std::endl;
			// }
		}
		// real.printTree();
	}
	return 0;
}