#include <iostream>
#include <iomanip>
// #include <map>
#include "./includes/stack.hpp"
#include "./includes/vector.hpp"
#include "./includes/ReverseIterator.hpp"
#include "./includes/map.hpp"
#include <iostream>
#include <utility>
#include <functional>

/* For colours in terminal/outputs : https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal*/

using namespace std;

int main()
{
	{
		/* Exemple du vrai MAP */
		// map<int, int> gquiz1;
		
		// 	// insert elements in random order
		// 	// gquiz1.insert(pair<int, int>(1, 40));
		// 	// gquiz1.insert(pair<int, int>(2, 30));
		// 	// gquiz1.insert(pair<int, int>(3, 60));
		// 	// gquiz1.insert(pair<int, int>(4, 20));
		// 	// gquiz1.insert(pair<int, int>(5, 50));
		// 	// gquiz1.insert(pair<int, int>(6, 50));
			
		// 	// gquiz1[7]=10;     // another way of inserting a value in a map
			
		
		// 	// printing map gquiz1
		// 	map<int, int>::iterator itr;
		// 	cout << "\nThe map gquiz1 is : \n";
		// 	cout << "\tKEY\tELEMENT\n";
		// 	for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) {
		// 		cout << '\t' << itr->first << '\t' << itr->second
		// 			<< '\n';
		// 	}
		// 	cout << "index 4 : " << gquiz1[4];
		// 	cout << endl;
		
		// std::map<char,int> mymap;
		// std::map<char,int>::key_compare mycomp = mymap.key_comp();

		// mymap['a']=100;
		// mymap['b']=200;
		// mymap['c']=300;

		// // cout << "index 4 : " << mymap['c'];
		// std::cout << "mymap contains:\n";
		// char highest = mymap.rbegin()->first;     // key value of last element
		// std::map<char,int>::iterator it = mymap.begin();
		// do {
		// 	std::cout << it->first << " => " << it->second << '\n';
		// } while ( mycomp((*it++).first, highest) );

		// std::cout << '\n';

		// int n = 1;
		// int a[5] = {1, 2, 3, 4, 5};
	
		// // build a pair from two ints
		// // auto p1 = std::make_pair(n, a[1]);
		// // std::map mymap;
		// // std::cout << "The value of p1 is "
		// // 		<< "(" << p1.first << ", " << p1.second << ")\n";
		// // std::cout << "The value of p1 is "
		// // 		<< "(" << mymap[1] << ")\n";
		// // build a pair from a reference to int and an array (decayed to pointer)
		// auto p2 = std::make_pair(std::ref(n), a);
		// n = 7;
		// std::cout << "The value of p2 is "
		// 	<< "(" << p2.first << ", " << *(p2.second + 1) << ")\n";


		// std::map<char,int> mymap;

		// std::map<char,int>::key_compare mycomp = mymap.key_comp();

		// mymap['a']=100;
		// mymap['b']=200;
		// mymap['c']=300;

		// std::cout << "mymap contains:\n";

		// char highest = mymap.rbegin()->first;     // key value of last element

		// std::map<char,int>::iterator it = mymap.begin();
		// do {
		// 	std::cout << it->first << " => " << it->second << '\n';
		// } while ( mycomp((*it++).first, highest) );

		// std::cout << '\n';

		//   std::map<char,int> mymap;

		// 	mymap['x']=1001;
		// 	mymap['y']=2002;
		// 	mymap['z']=3003;

		// 	std::cout << "mymap contains:\n";

		// 	std::pair<char,int> highest = *mymap.rbegin();          // last element

		// 	std::map<char,int>::iterator it = mymap.begin();
		// 	do {
		// 		std::cout << it->first << " => " << it->second << '\n';
		// 	} while ( mymap.value_comp()(*it++, highest) );

		// std::map<char,int> mymap;
		// std::cout <<  << '\n';
		// char lowest = mymap.begin()->first;

		ft::map<int, int> kikou;

		std::cout << kikou.size() << std::endl;
	}
  
}