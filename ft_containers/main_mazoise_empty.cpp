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

// #ifndef STD
// # define NAMESPACE ft
// #else
// # define NAMESPACE std
// #endif

// using namespace NAMESPACE;

    // template <class Key, class T>
    // void	print(map<Key, T>& lst)
    // {
    //     for (typename map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
	// 	cout << it->first << " => " << it->second << '\n';
    // }

    int main ()
    {
        {
            std::cout << "real vector " << std::endl;
            std::map<char,int> mymap;

            mymap['a']=10;
            mymap['b']=20;
            mymap['c']=30;

            while (!mymap.empty())
            {
                std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
                mymap.erase(mymap.begin());
            }
        }
        {
            std::cout << "My vector " << std::endl;
            ft::map<char,int> mymap;

            mymap['a']=10;
            mymap['b']=20;
            mymap['c']=30;

            while (!mymap.empty())
            {
                std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
                mymap.erase(mymap.begin());
            }
        }


    }