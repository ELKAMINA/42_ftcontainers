  

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

int main()
{
    {
        using namespace std;

        map<char,int> mymap;

        map<char,int>::key_compare mycomp = mymap.key_comp();

        mymap['a']=100;
        mymap['b']=200;
        mymap['c']=300;


        char highest = mymap.rbegin()->first;     // key value of last element


        cout << "mymap contains:\n";
        map<char,int>::iterator it = mymap.begin();
        do {
            cout << it->first << " => " << it->second << '\n';
        } while ( mycomp((*it++).first, highest) );

        cout << '\n';
    }
    {
        using namespace ft;

        ft::map<char,int> mymap;

        ft::map<char,int>::key_compare mycomp = mymap.key_comp();

        mymap['a']=100;
        mymap['b']=200;
        mymap['c']=300;


        char highest = mymap.rbegin()->first;     // key value of last element
        std::cout << "highest :\n" << highest << std::endl;
            std::cout << "mymap contains:\n";
            ft::map<char,int>::iterator it = mymap.begin();
            do {
                std::cout << it->first << " => " << it->second << '\n';
            } while ( mycomp((*it++).first, highest) );

            std::cout << '\n'; 
    }
}