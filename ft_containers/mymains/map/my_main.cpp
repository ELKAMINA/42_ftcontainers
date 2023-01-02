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
		// ft::map<int, int> kikou;
		// ft::map<int, int> test2;
		// kikou.insert(ft::pair<int, int> (10, 30));
		// kikou.insert(ft::pair<int, int> (70, 30));
		// kikou.insert(ft::pair<int, int> (50, 90));
		// ft::map<int, int>::iterator it = kikou.begin();
		// it++;
		// ft::map<int, int>::iterator inserted = kikou.insert(it, ft::pair<int, int> (90, 100));
		// test2.insert(kikou.begin(), kikou.end());
		// ft::map<int, int>::iterator it_test = test2.begin();
		// // ft::map<int, int>::iterator it_test2 = test2.begin();
		// // it_test2 = it_test++;
		// test2.erase(inserted, test2.end());
		// // it_test++;
		// // std::cout << test2.erase(70) << std::endl;
		// // test2.erase(it_test, );
		// ft::map<int, int>::iterator it_test3 = test2.begin();
		// // ft::map<int, int>::iterator it_test2 = test2.begin();
		// for	(; it_test3 != test2.end(); it_test3++) 
		// {
		// 	std::cout << "first : " << it_test3->first << " second :" << it_test3->second << std::endl;
		// 	// std::cout << it-> << std::endl;
		// }
		// ft::map<char,int> mymap;
		// ft::map<char,int>::iterator it;
		// // insert some values:
		// mymap['a']=10;
		// mymap['b']=20;
		// mymap['c']=30;
		// mymap['d']=40;
		// mymap['e']=50;
		// mymap['f']=60;

		// it=mymap.find('b');
		// mymap.erase (it);                   // erasing by iterator

		// mymap.erase ('c');                  // erasing by key

		// it=mymap.find ('e');
		// mymap.erase ( it, mymap.end() );    // erasing by range
		// // std::cout << "here ?? " << std::endl;

		// // show content:
		// for (it=mymap.begin(); it!=mymap.end(); ++it)
		// 	std::cout << it->first << " => " << it->second << '\n';
		// ft::map<char,int> mymap;

		// mymap['x']=100;
		// mymap['y']=200;
		// mymap['z']=300;

		// std::cout << "mymap contains:\n";
		// for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		// 	std::cout << it->first << " => " << it->second << '\n';

		// mymap.clear();
		// mymap['a']=1101;
		// mymap['b']=2202;

		// std::cout << "mymap contains:\n";
		// for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		// 	std::cout << it->first << " => " << it->second << '\n';

		// ft::map<char,int> foo,bar;
		// foo['x']=100;
		// foo['y']=200;

		// bar['a']=11;
		// bar['b']=22;
		// bar['c']=33;

		// foo.swap(bar);

		// std::cout << "foo contains:\n";
		// for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		// {
		// 	std::cout << it->first << " => " << it->second << '\n';
		// 	// it++;
		// 	// std::cout << "Adresse first "<< '\n';
		// }

		// std::cout << "bar contains:\n";
		// for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		// 	std::cout << it->first << " => " << it->second << '\n';

		// ft::map<char,int> mymap;
		// char c;

		// mymap ['a']=101;
		// mymap ['c']=202;
		// mymap ['f']=303;

		// for (c='a'; c<'h'; c++)
		// {
		// 	std::cout << c;
		// 	if (mymap.count(c)>0)
		// 	std::cout << " is an element of mymap.\n";
		// 	else 
		// 	std::cout << " is not an element of mymap.\n";
		// }  
		// ft::map<char,int> mymap;
		// ft::map<char,int>::iterator itlow,itup;

		// mymap['a']=20;
		// mymap['b']=40;
		// mymap['c']=60;
		// mymap['d']=80;
		// mymap['e']=100;
		// mymap['f']=100;

		// // itlow=mymap.lower_bound ('b');  // itlow points to b
		// itup=mymap.upper_bound ('d');   // itup points to e (not d!)
		// std::cout << itup->first << " => " << itup->second << '\n';
		// ft::map<char,int> mymap;

		// mymap['a']=10;
		// mymap['b']=20;
		// mymap['c']=30;
		// mymap['d']=30;

		// ft::map<char,int> map2(mymap);
		// ft::map<char,int>::iterator it = map2.begin();
		// ft::map<char,int> map3;
		// map3 = map2;
		// ft::map<char,int>::iterator it2 = map3.begin();
		// for(; it2 != map3.end(); it2++)
		// 	std::cout << it2->first << " => " << it2->second << '\n';

		// ret = mymap.equal_range('p');
		// std::cout << "lower bound points to: ";

		// std::cout << "upper bound points to: ";
		// std::cout << ret.second->first << " => " << ret.second->second << '\n';
		// mymap.erase(itlow,itup);        // erases [itlow,itup)

		// print content:
		// for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		// 	std::cout << it->first << " => " << it->second << '\n';
  	}
// kikou.printTree();
	std::cout << std::endl;
	std::cout << std::endl;



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
			// std::map<char,int> mymap;
			// std::map<char,int>::iterator it;

			// // insert some values:
			// mymap['a']=10;
			// mymap['b']=20;
			// mymap['c']=30;
			// mymap['d']=40;
			// mymap['e']=50;
			// mymap['f']=60;

			// it=mymap.find('b');
			// mymap.erase (it);                   // erasing by iterator

			// mymap.erase ('c');                  // erasing by key

			// it=mymap.find ('e');
			// mymap.erase ( it, mymap.end() );    // erasing by range

			// // show content:
			// for (it=mymap.begin(); it!=mymap.end(); ++it)
			// 	std::cout << it->first << " => " << it->second << '\n';
			// std::map<char,int> mymap;

			// mymap['x']=100;
			// mymap['y']=200;
			// mymap['z']=300;

			// std::cout << "mymap contains:\n";
			// for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			// 	std::cout << it->first << " => " << it->second << '\n';

			// mymap.clear();
			// mymap['a']=1101;
			// mymap['b']=2202;

			// std::cout << "mymap contains:\n";
			// for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			// 	std::cout << it->first << " => " << it->second << '\n';

			// std::map<char,int> foo,bar;

			// foo['x']=100;
			// foo['y']=200;

			// bar['a']=11;
			// bar['b']=22;
			// bar['c']=33;

			// foo.swap(bar);

			// std::cout << "foo contains:\n";
			// for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
			// 	std::cout << it->first << " => " << it->second << '\n';

			// std::cout << "bar contains:\n";
			// for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
			// 	std::cout << it->first << " => " << it->second << '\n';

			// std::map<char,int> mymap;
			// char c;

			// mymap ['a']=101;
			// mymap ['c']=202;
			// mymap ['f']=303;

			// for (c='a'; c<'h'; c++)
			// {
			// 	std::cout << c;
			// 	if (mymap.count(c)>0)
			// 	std::cout << " is an element of mymap.\n";
			// 	else 
			// 	std::cout << " is not an element of mymap.\n";
			// }


		// std::map<char,int> mymap;
		// std::map<char,int>::iterator itlow,itup;

		// mymap['a']=20;
		// mymap['b']=40;
		// mymap['c']=60;
		// mymap['d']=80;
		// mymap['e']=100;
		// mymap['f']=100;

		// // itlow=mymap.lower_bound ('b');  // itlow points to b
		// itup=mymap.upper_bound ('d');   // itup points to e (not d!)
		// std::cout << itup->first << " => " << itup->second << '\n';
	 	std::map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=30;

		std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
		ret = mymap.equal_range('p');

		std::cout << "lower bound points to: ";
		std::cout << ret.first->first << " => " << ret.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << ret.second->first << " => " << ret.second->second << '\n';

		// mymap.erase(itlow,itup);        // erases [itlow,itup)

		// print content:
		// for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		// 	std::cout << it->first << " => " << it->second << '\n';
			// itup=mymap.upper_bound ('d');   // itup points to e (not d!)

			// mymap.erase(itlow,itup);        // erases [itlow,itup)

			// // print content:
			// for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			// 	std::cout << it->first << " => " << it->second << '\n';
			// std::cout << std::endl;
			// std::cout << " The Real MAP " << std::endl;
			// std::map<int, int> real;
			// std::map<int, int> test2;
			// real.insert(std::pair<int, int> (10, 30));
			// real.insert(std::pair<int, int> (70, 30));
			// real.insert(std::pair<int, int> (50, 90));
			// std::map<int, int>::iterator it = real.begin();
			// it++;
			// real.insert(it, std::pair<int, int> (90, 100));
			// test2.insert(real.begin(), real.end());
			// // std::map<int, int>::iterator it_test = test2.begin();

			// // test2.erase(inserted, test2.end());
			// // // it_test++;
			// // // std::cout << test2.erase(70) << std::endl;
			// // // test2.erase(it_test, );
			// std::map<int, int>::iterator it_test3 = test2.begin();
			// // ft::map<int, int>::iterator it_test2 = test2.begin();
			// for	(; it_test3 != test2.end(); it_test3++) 
			// {
			// 	std::cout << "first : " << it_test3->first << " second :" << it_test3->second << std::endl;
			// 	// std::cout << it-> << std::endl;
			// }
			// test2.erase(it_test++);
			// std::cout << test2.erase(70) << std::endl;
			// std::map<int, int>::iterator it_test2;
			// it_test2 = it_test++;
			// test2.erase(it_test, it_test2);
			// for	(; it_test != test2.end(); it_test++)
			// {
			// 	std::cout << "first : " << it_test->first << " second :" << it_test->second << std::endl;
			// 	// std::cout << it-> << std::endl;
			// }
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