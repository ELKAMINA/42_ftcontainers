#include <iostream>
#include <iomanip>
#include <map>
#include "./includes/stack.hpp"
#include "./includes/vector.hpp"
#include "./includes/map.hpp"
#include "./includes/ReverseIterator.hpp"
#include "./includes/map.hpp"
#include "./includes/prints.hpp"
#include <iostream>
#include <utility>
#include <functional>
#include <string>


int main() 
{
	/* ************************************************* */
	/*          		Member functions : 	          	*/
	/* *************************************************/

    std::cout << _IYELLOW << "MAP -  MEMBER FUNCTIONS " << _END << std::endl;
    {
        {
            {
                std::cout << _PURPLE << "Default constructors with ft " << _END << std::endl;
                // ft::map<int,float> map_ft;
                // ft::map<int,int> map_ft;
                // ft::map<int, std::string> map_ft;
                // ft::map<std::string, char> map_ft;
                ft::map<float, double> map_ft;
                std::cout << "size_ft : " << map_ft.size() << std::endl;
            }
            {
                std::cout <<  _PURPLE << "Default constructors with std " << _END << std::endl;
                // std::map<int,float> map_std;
                // std::map<int,int> map_std;
                // std::map<int, std::string> map_std;
                // std::map<std::string, char> map_std;
                std::map<float, double> map_std;
                std::cout << "size_std : " << map_std.size() << std::endl;
            }
        }
        {
            {
                std::cout << _PURPLE << "Range constructors with ft " << _END << std::endl;
            
                ft::map<char,float> map_ft_for_construction;
                map_ft_for_construction['a'] = 8.98;
                map_ft_for_construction['b'] = 30.8;
                map_ft_for_construction['c'] = 29.98;
                map_ft_for_construction['d'] = 10.01;
                map_ft_for_construction['e'] = 12.99;
                map_ft_for_construction['f'] = 16.0;

                ft::map<char,float> map_ft(map_ft_for_construction.begin(), map_ft_for_construction.end());

                std::cout << "size_ft : " << map_ft.size() << std::endl;
                ft::map<char, float>::iterator it = map_ft.begin();
                for(; it != map_ft.end(); it++)
                    std::cout << "Composition Map_ft : first = " << it->first << " second = " << it->second << std::endl; 
            }
            {
                std::cout << _PURPLE << "Range constructors with std " << _END << std::endl;
            
                std::map<char,float> map_ft_for_construction;
                map_ft_for_construction['a'] = 8.98;
                map_ft_for_construction['b'] = 30.8;
                map_ft_for_construction['c'] = 29.98;
                map_ft_for_construction['d'] = 10.01;
                map_ft_for_construction['e'] = 12.99;
                map_ft_for_construction['f'] = 16.0;

                std::map<char,float> map_ft(map_ft_for_construction.begin(), map_ft_for_construction.end());

                std::cout << "size_ft : " << map_ft.size() << std::endl;
                std::map<char, float>::iterator it = map_ft.begin();
                for(; it != map_ft.end(); it++)
                    std::cout << "Composition Map_ft : first = " << it->first << " second = " << it->second << std::endl; 
            }
        }
        {
            {
                std::cout << _PURPLE << "Copy constructors with ft " << _END << std::endl;
            
                ft::map<char,float> map_ft_for_construction;
                map_ft_for_construction['a'] = 8.98;
                map_ft_for_construction['b'] = 30.8;
                map_ft_for_construction['c'] = 29.98;
                map_ft_for_construction['d'] = 10.01;
                map_ft_for_construction['e'] = 12.99;
                map_ft_for_construction['f'] = 16.0;

                ft::map<char,float> map_ft(map_ft_for_construction);

                std::cout << "size_ft : " << map_ft.size() << std::endl;
                ft::map<char, float>::iterator it = map_ft.begin();
                for(; it != map_ft.end(); it++)
                    std::cout << "Composition Map_ft : first = " << it->first << " second = " << it->second << std::endl; 
            }
            {
                std::cout << _PURPLE << "Copy constructors with std " << _END << std::endl;
            
                std::map<char,float> map_std_for_construction;
                map_std_for_construction['a'] = 8.98;
                map_std_for_construction['b'] = 30.8;
                map_std_for_construction['c'] = 29.98;
                map_std_for_construction['d'] = 10.01;
                map_std_for_construction['e'] = 12.99;
                map_std_for_construction['f'] = 16.0;

                std::map<char,float> map_std(map_std_for_construction);

                std::cout << "size_ft : " << map_std.size() << std::endl;
                std::map<char, float>::iterator it = map_std.begin();
                for(; it != map_std.end(); it++)
                    std::cout << "Composition Map_std : first = " << it->first << " second = " << it->second << std::endl; 
            }
        }
        {
            {
                std::cout << _PURPLE << "Operator = with ft " << _END << std::endl;
                ft::map<char,int> first;
                ft::map<char,int> second;

                first['x']=8;
                first['y']=16;
                first['z']=32;

                second=first;                // second now contains 3 ints
                first=ft::map<char,int>();  // and first is now empty

                std::cout << "Size of first: " << first.size() << '\n';
                std::cout << "Size of second: " << second.size() << '\n';
            }
            {
                std::cout << _PURPLE << "Operator = with std " << _END << std::endl;
                std::map<char,int> first;
                std::map<char,int> second;

                first['x']=8;
                first['y']=16;
                first['z']=32;

                second=first;                // second now contains 3 ints
                first=std::map<char,int>();  // and first is now empty

                std::cout << "Size of first: " << first.size() << '\n';
                std::cout << "Size of second: " << second.size() << '\n';
            }
        }
    }
    /* ************** FIN DE MEMBER FUNCTIONS ************** */

    /* ************************************************* */
	/*          		Iterators functions : 	      	*/
	/* *************************************************/
    {
        std::cout << _IYELLOW << "MAP -  Iterators " << _END << std::endl;
        {
            {
                {
                    std::cout << _PURPLE << "Begin/end ft " << _END << std::endl;
                    ft::map<char,int> mymap;

                    mymap['b'] = 100;
                    mymap['a'] = 200;
                    mymap['c'] = 300;

                    // show content:
                    for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
                        std::cout << it->first << " => " << it->second << '\n';
                }
                {
                    std::cout << _PURPLE << "Begin/end std " << _END << std::endl;
                    std::map<char,int> mymap;

                    mymap['b'] = 100;
                    mymap['a'] = 200;
                    mymap['c'] = 300;

                    // show content:
                    for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
                        std::cout << it->first << " => " << it->second << '\n';
                }
            }

            {
                {
                    std::cout << _PURPLE << "rBegin/rend ft " << _END << std::endl;
                    ft::map<char,int> mymap;

                    mymap['x'] = 100;
                    mymap['y'] = 200;
                    mymap['z'] = 300;

                    // show content:
                    ft::map<char,int>::reverse_iterator rit;
                    for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
                        std::cout << rit->first << " => " << rit->second << '\n';
                }
                {
                    std::cout << _PURPLE << "rBegin/rend std " << _END << std::endl;
                    std::map<char,int> mymap;

                    mymap['x'] = 100;
                    mymap['y'] = 200;
                    mymap['z'] = 300;

                    // show content:
                    std::map<char,int>::reverse_iterator rit;
                    for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
                        std::cout << rit->first << " => " << rit->second << '\n';
                }
            }
        }
    /* ************** FIN ITERATORS ************** */
    }
    /* ************************************************* */
	/*          		Capacity : 	                	*/
	/* *************************************************/
    {
        {
            std::cout << _PURPLE << "empty/size/max_size with ft " << _END << std::endl;
            ft::map<char,int> mymap;


            std::cout << mymap.empty() << '\n';
            std::cout << "size () _ft " << mymap.size() << '\n';
            std::cout << "max_size _ft " << mymap.max_size() << '\n'; // max_size entre STL et le mien est normale (differente car dépend de ce qui a dedans)

            mymap['a']=10; 
            mymap['b']=20;
            mymap['c']=30;

            std::cout << "size () _ft " << mymap.size() << '\n';
            std::cout << "max_size _ft " << mymap.max_size() << '\n';

            while (!mymap.empty())
            {
                std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
                mymap.erase(mymap.begin());
            }
        }
        {
            std::cout << _PURPLE << "empty/size/max_size with std " << _END << std::endl;
            std::map<char,int> mymap;


            std::cout << mymap.empty() << '\n'; // 1 is true and 0 is false
             std::cout << "size () _std " << mymap.size() << '\n';
            std::cout << "max_size _std " << mymap.max_size() << '\n';
            mymap['a']=10;
            mymap['b']=20;
            mymap['c']=30;

            std::cout << "size () _std " << mymap.size() << '\n';
            std::cout << "max_size _std " << mymap.max_size() << '\n';
            while (!mymap.empty())
            {
                std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
                mymap.erase(mymap.begin());
            }

        }
    }
    /* ****************** FIN CAPACITY *********************************** */

    /* ************************************************* */
	/*          		Element accees : 	          	*/
	/* *************************************************/
    {
        std::cout << _PURPLE << "Operator [] with ft" << _END << std::endl;

        {
            ft::map<char,std::string> mymap;

            mymap['a']="an element";
            mymap['b']="another element";
            mymap['c']=mymap['b'];

            std::cout << "mymap['a'] is " << mymap['a'] << '\n';
            std::cout << "mymap['b'] is " << mymap['b'] << '\n';
            std::cout << "mymap['c'] is " << mymap['c'] << '\n';
            std::cout << "mymap['d'] is " << mymap['d'] << '\n';

            std::cout << "mymap now contains " << mymap.size() << " elements.\n";
        }
        {
            std::cout << _PURPLE << "Operator [] with std" << _END << std::endl;

            std::map<char,std::string> mymap;

            mymap['a']="an element";
            mymap['b']="another element";
            mymap['c']=mymap['b'];

            std::cout << "mymap['a'] is " << mymap['a'] << '\n';
            std::cout << "mymap['b'] is " << mymap['b'] << '\n';
            std::cout << "mymap['c'] is " << mymap['c'] << '\n';
            std::cout << "mymap['d'] is " << mymap['d'] << '\n'; //insert a new element

            std::cout << "mymap now contains " << mymap.size() << " elements.\n";
        }
    }



   // std::cout << "insert " << std::endl;
        // ft::pair<char, float> pr1('a', 7.6);
        // ft::pair<char, float> pr2('b', 0.6);
        // ft::pair<char, float> pr3('c', 7.996);
        // ft::pair<char, float> pr5('d', 7.6);

}