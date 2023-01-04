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
    /* ****************** FIN CAPACITY *********************************** */

    /* ************************************************* */
	/*          		Modifiers : 	               	*/
	/* *************************************************/

    {
        {
            std::cout << _PURPLE << "Insert with ft" << _END << std::endl;

            ft::map<char,int> mymap;

            // first insert function version (single parameter):
            mymap.insert ( ft::pair<char,int>('a',100) );
            mymap.insert ( ft::pair<char,int>('z',200) );


            ft::pair<ft::map<char,int>::iterator,bool> ret;
            ret = mymap.insert ( ft::pair<char,int>('z',500) );
            if (ret.second==false) {
                std::cout << "element 'z' already existed";
                std::cout << " with a value of " << ret.first->second << '\n';
            }

            // second insert function version (with hint position):
            ft::map<char,int>::iterator it = mymap.begin();
            std::cout << "NOT INVALIDATING ITERATOR  = " << it->first << std::endl;
            mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
            mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting
            std::cout << "NOT INVALIDATING ITERATOR = " << it->first << std::endl;

            // third insert function version (range insertion):
            ft::map<char,int> anothermap;
            anothermap.insert(mymap.begin(),mymap.find('c'));

            // showing contents:
            std::cout << "mymap contains:\n";
            for (it=mymap.begin(); it!=mymap.end(); ++it)
                std::cout << it->first << " => " << it->second << '\n';

            std::cout << "anothermap contains:\n";
            for (it=anothermap.begin(); it!=anothermap.end(); ++it)
                std::cout << it->first << " => " << it->second << '\n';
        }
        {
            std::cout << _PURPLE << "Insert with std" << _END << std::endl;
            std::map<char,int> mymap;

            // first insert function version (single parameter):
            mymap.insert ( std::pair<char,int>('a',100) );
            mymap.insert ( std::pair<char,int>('z',200) );

            std::pair<std::map<char,int>::iterator,bool> ret;
            ret = mymap.insert ( std::pair<char,int>('z',500) );
            if (ret.second==false) {
                std::cout << "element 'z' already existed";
                std::cout << " with a value of " << ret.first->second << '\n';
            }

            // second insert function version (with hint position):
            std::map<char,int>::iterator it = mymap.begin();
            std::cout << "NOT INVALIDATING ITERATOR  = " << it->first << std::endl;
            mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
            mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting
            std::cout << "NOT INVALIDATING ITERATOR  = " << it->first << std::endl;

            // third insert function version (range insertion):
            std::map<char,int> anothermap;
            anothermap.insert(mymap.begin(),mymap.find('c'));

            // showing contents:
            std::cout << "mymap contains:\n";
            for (it=mymap.begin(); it!=mymap.end(); ++it)
                std::cout << it->first << " => " << it->second << '\n';

            std::cout << "anothermap contains:\n";
            for (it=anothermap.begin(); it!=anothermap.end(); ++it)
                std::cout << it->first << " => " << it->second << '\n';
        }
        {
            std::cout << _PURPLE << "Erase with ft" << _END << std::endl;
            ft::map<char,int> mymap;
            ft::map<char,int>::iterator it;

            // insert some values:
            mymap['a']=10;
            mymap['b']=20;
            mymap['c']=30;
            mymap['d']=40;
            mymap['e']=50;
            mymap['f']=60;

            it=mymap.find('b');
            mymap.erase (it);                   // erasing by iterator
            mymap.erase ('c');                  // erasing by key

            it=mymap.find ('e');
            mymap.erase ( it, mymap.end() );    // erasing by range

            // show content:
            for (it=mymap.begin(); it!=mymap.end(); ++it)
                std::cout << it->first << " => " << it->second << '\n';
        }
        {
            std::cout << _PURPLE << "Erase with std" << _END << std::endl;
            
            std::map<char,int> mymap;
            std::map<char,int>::iterator it;

            // insert some values:
            mymap['a']=10;
            mymap['b']=20;
            mymap['c']=30;
            mymap['d']=40;
            mymap['e']=50;
            mymap['f']=60;

            it=mymap.find('b');
            mymap.erase (it);                   // erasing by iterator

            mymap.erase ('c');                  // erasing by key

            it=mymap.find ('e');
            mymap.erase ( it, mymap.end() );    // erasing by range

            // show content:
            for (it=mymap.begin(); it!=mymap.end(); ++it)
                std::cout << it->first << " => " << it->second << '\n';
        }
        {
            std::cout << _PURPLE << "SWAP with ft" << _END << std::endl;
            ft::map<char,int> foo,bar;

            foo['x']=100;
            foo['y']=200;

            bar['a']=11;
            bar['b']=22;
            bar['c']=33;

            foo.swap(bar);

            std::cout << "foo contains:\n";
            for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
                std::cout << it->first << " => " << it->second << '\n';

            std::cout << "bar contains:\n";
            for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
                std::cout << it->first << " => " << it->second << '\n';
        }
        {
            std::cout << _PURPLE << "SWAP with std" << _END << std::endl;

            std::map<char,int> foo,bar;

            foo['x']=100;
            foo['y']=200;

            bar['a']=11;
            bar['b']=22;
            bar['c']=33;

            foo.swap(bar);

            std::cout << "foo contains:\n";
            for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
                std::cout << it->first << " => " << it->second << '\n';

            std::cout << "bar contains:\n";
            for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
                std::cout << it->first << " => " << it->second << '\n';
        }
        {
            std::cout << _PURPLE << "CLEAR with ft" << _END << std::endl;

            ft::map<char,int> mymap;

            mymap['x']=100;
            mymap['y']=200;
            mymap['z']=300;

            std::cout << "mymap contains:\n";
            for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
                std::cout << it->first << " => " << it->second << '\n';

            mymap.clear();
            mymap['a']=1101;
            mymap['b']=2202;

            std::cout << "mymap contains:\n";
            for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
                std::cout << it->first << " => " << it->second << '\n';
        }
        {
            std::cout << _PURPLE << "CLEAR with std" << _END << std::endl;

            std::map<char,int> mymap;

            mymap['x']=100;
            mymap['y']=200;
            mymap['z']=300;

            std::cout << "mymap contains:\n";
            for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
                std::cout << it->first << " => " << it->second << '\n';

            mymap.clear();
            mymap['a']=1101;
            mymap['b']=2202;

            std::cout << "mymap contains:\n";
            for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
                std::cout << it->first << " => " << it->second << '\n';
        }
        
    }

    /* ****************** FIN MODIFIERS *********************************** */

    /* ************************************************* */
	/*          		Modifiers : 	               	*/
	/* *************************************************/
    {
        {
            std::cout << _PURPLE << "KEY COMPARE with ft" << _END << std::endl;
            
            ft::map<char,int> mymap;

            ft::map<char,int>::key_compare mycomp = mymap.key_comp();

            mymap['a']=100;
            mymap['b']=200;
            mymap['c']=300;

            std::cout << "mymap contains:\n";

            char highest = mymap.rbegin()->first;     // key value of last element

            ft::map<char,int>::iterator it = mymap.begin();
            do {
                std::cout << it->first << " => " << it->second << '\n';
            } while ( mycomp((*it++).first, highest) );

            std::cout << '\n';
        }
        {
            std::cout << _PURPLE << "KEY COMPARE with std" << _END << std::endl;

            std::map<char,int> mymap;

            std::map<char,int>::key_compare mycomp = mymap.key_comp();

            mymap['a']=100;
            mymap['b']=200;
            mymap['c']=300;

            std::cout << "mymap contains:\n";

            char highest = mymap.rbegin()->first;     // key value of last element

            std::map<char,int>::iterator it = mymap.begin();
            do {
                std::cout << it->first << " => " << it->second << '\n';
            } while ( mycomp((*it++).first, highest) );

            std::cout << '\n';
        }
        {
            std::cout << _PURPLE << "VALUE COMPARE with ft" << _END << std::endl;
            ft::map<char,int> mymap;

            mymap['x']=1001;
            mymap['y']=2002;
            mymap['z']=3003;

            std::cout << "mymap contains:\n";

            ft::pair<char,int> highest = *mymap.rbegin();          // last element

            ft::map<char,int>::iterator it = mymap.begin();
            do {
                std::cout << it->first << " => " << it->second << '\n';
            } while ( mymap.value_comp()(*it++, highest) );
        }   
        {
            std::cout << _PURPLE << "VALUE COMPARE with std" << _END << std::endl;
            std::map<char,int> mymap;

            mymap['x']=1001;
            mymap['y']=2002;
            mymap['z']=3003;

            std::cout << "mymap contains:\n";

            std::pair<char,int> highest = *mymap.rbegin();          // last element

            std::map<char,int>::iterator it = mymap.begin();
            do {
                std::cout << it->first << " => " << it->second << '\n';
            } while ( mymap.value_comp()(*it++, highest) );
        }  
    }

    /* ****************** FIN Observers *********************************** */

    /* ************************************************* */
	/*          		OPERATIONS : 	               	*/
	/* *************************************************/
    {
        {

           std::cout << _PURPLE << "Find with ft" << _END << std::endl;

            ft::map<char,int> mymap;
            ft::map<char,int>::iterator it;

            mymap['a']=50;
            mymap['b']=100;
            mymap['c']=150;
            mymap['d']=200;

            it = mymap.find('b');
            if (it != mymap.end())
                mymap.erase (it);

            // print content:
            std::cout << "elements in mymap:" << '\n';
            std::cout << "a => " << mymap.find('a')->second << '\n';
            std::cout << "c => " << mymap.find('c')->second << '\n';
            std::cout << "d => " << mymap.find('d')->second << '\n';
        }
        {
            std::cout << _PURPLE << "Find with std" << _END << std::endl;

            std::map<char,int> mymap;
            std::map<char,int>::iterator it;

            mymap['a']=50;
            mymap['b']=100;
            mymap['c']=150;
            mymap['d']=200;

            it = mymap.find('b');
            if (it != mymap.end())
                mymap.erase (it);

            // print content:
            std::cout << "elements in mymap:" << '\n';
            std::cout << "a => " << mymap.find('a')->second << '\n';
            std::cout << "c => " << mymap.find('c')->second << '\n';
            std::cout << "d => " << mymap.find('d')->second << '\n';
        }
        {
            std::cout << _PURPLE << "Count with ft" << _END << std::endl;

            ft::map<char,int> mymap;
            char c;

            mymap ['a']=101;
            mymap ['c']=202;
            mymap ['f']=303;

            for (c='a'; c<'h'; c++)
            {
                std::cout << c;
                if (mymap.count(c)>0)
                std::cout << " is an element of mymap.\n";
                else 
                std::cout << " is not an element of mymap.\n";
            }
        }
        {
            std::cout << _PURPLE << "Count with std" << _END << std::endl;

            std::map<char,int> mymap;
            char c;

            mymap ['a']=101;
            mymap ['c']=202;
            mymap ['f']=303;

            for (c='a'; c<'h'; c++)
            {
                std::cout << c;
                if (mymap.count(c)>0)
                std::cout << " is an element of mymap.\n";
                else 
                std::cout << " is not an element of mymap.\n";
            }
        }
        {
            std::cout << _PURPLE << "lower bound  with ft" << _END << std::endl;
            
            ft::map<char,int> mymap;
            ft::map<char,int>::iterator itlow,itup;

            mymap['a']=20;
            mymap['b']=40;
            mymap['c']=60;
            mymap['d']=80;
            mymap['e']=100;

            itlow=mymap.lower_bound ('b');  // itlow points to b
            itup=mymap.upper_bound ('d');   // itup points to e (not d!)

            mymap.erase(itlow,itup);        // erases [itlow,itup)

            // print content:
            for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
                std::cout << it->first << " => " << it->second << '\n';
        }
        {
            std::cout << _PURPLE << "lower bound  with ft" << _END << std::endl;
            
            std::map<char,int> mymap;
            std::map<char,int>::iterator itlow,itup;

            mymap['a']=20;
            mymap['b']=40;
            mymap['c']=60;
            mymap['d']=80;
            mymap['e']=100;

            itlow=mymap.lower_bound ('b');  // itlow points to b
            itup=mymap.upper_bound ('d');   // itup points to e (not d!)

            mymap.erase(itlow,itup);        // erases [itlow,itup)

            // print content:
            for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
                std::cout << it->first << " => " << it->second << '\n';
        }
        {
            std::cout << _PURPLE << "upper bound  with ft" << _END << std::endl;
            ft::map<char,int> mymap;
            ft::map<char,int>::iterator itlow,itup;

            mymap['a']=20;
            mymap['b']=40;
            mymap['c']=60;
            mymap['d']=80;
            mymap['e']=100;

            itlow=mymap.lower_bound ('b');  // itlow points to b
            itup=mymap.upper_bound ('d');   // itup points to e (not d!)

            mymap.erase(itlow,itup);        // erases [itlow,itup)

            // print content:
            for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
                std::cout << it->first << " => " << it->second << '\n';
        }
        {
            std::cout << _PURPLE << "upper bound  with std" << _END << std::endl;
            std::map<char,int> mymap;
            std::map<char,int>::iterator itlow,itup;

            mymap['a']=20;
            mymap['b']=40;
            mymap['c']=60;
            mymap['d']=80;
            mymap['e']=100;

            itlow=mymap.lower_bound ('b');  // itlow points to b
            itup=mymap.upper_bound ('d');   // itup points to e (not d!)

            mymap.erase(itlow,itup);        // erases [itlow,itup)

            // print content:
            for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
                std::cout << it->first << " => " << it->second << '\n';
        }
        {
            std::cout << _PURPLE << "equal range with ft" << _END << std::endl;

            ft::map<char,int> mymap;

            mymap['a']=10;
            mymap['b']=20;
            mymap['c']=30;

            ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
            ret = mymap.equal_range('b');

            std::cout << "lower bound points to: ";
            std::cout << ret.first->first << " => " << ret.first->second << '\n';

            std::cout << "upper bound points to: ";
            std::cout << ret.second->first << " => " << ret.second->second << '\n';
        }
        {
            std::cout << _PURPLE << "equal range with std" << _END << std::endl;

            std::map<char,int> mymap;

            mymap['a']=10;
            mymap['b']=20;
            mymap['c']=30;

            std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
            ret = mymap.equal_range('b');

            std::cout << "lower bound points to: ";
            std::cout << ret.first->first << " => " << ret.first->second << '\n';

            std::cout << "upper bound points to: ";
            std::cout << ret.second->first << " => " << ret.second->second << '\n';
        }
    /* ****************** FIN Operations *********************************** */

        /* ************************************************* */
        /*          		Get Allocator : 	               	*/
        /* *************************************************/
        {
            std::cout << _PURPLE << "get allocator with ft" << _END << std::endl;

            int psize;
            ft::map<char,int> mymap;
            ft::pair<const char,int>* p;

            // allocate an array of 5 elements using mymap's allocator:
            p=mymap.get_allocator().allocate(5);

            // assign some values to array
            psize = sizeof(ft::map<char,int>::value_type)*5;

            std::cout << "The allocated array has a size of " << psize << " bytes.\n";

            mymap.get_allocator().deallocate(p,5);
        }
        {
            std::cout << _PURPLE << "get allocator with std" << _END << std::endl;

            int psize;
            std::map<char,int> mymap;
            std::pair<const char,int>* p;

            // allocate an array of 5 elements using mymap's allocator:
            p=mymap.get_allocator().allocate(5);

            // assign some values to array
            psize = sizeof(std::map<char,int>::value_type)*5;

            std::cout << "The allocated array has a size of " << psize << " bytes.\n";

            mymap.get_allocator().deallocate(p,5);  
        }
  
    }
}