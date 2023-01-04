#include <iostream>
#include <iomanip>
#include <vector>
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

    std::cout << _IYELLOW << "Vector -  MEMBER FUNCTIONS " << _END << std::endl;
    {
        {
            {
                std::cout << _PURPLE << "Constructors with ft" << _END << std::endl;

                // constructors used in the same order as described above:
                ft::vector<int> first;                                // empty vector of ints
                ft::vector<int> second (4,100);                       // four ints with value 100
                ft::vector<int> third (second.begin(),second.end());  // iterating through second
                ft::vector<int> fourth (third);                       // a copy of third

                // the iterator constructor can also be used to construct from arrays:
                int myints[] = {16,2,77,29};
                ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

                std::cout << "The contents of fifth are:";
                for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
                    std::cout << ' ' << *it;
                std::cout << '\n';
            }
            {
                std::cout << _PURPLE << "Constructors with std" << _END << std::endl;

                // constructors used in the same order as described above:
                std::vector<int> first;                                // empty vector of ints
                std::vector<int> second (4,100);                       // four ints with value 100
                std::vector<int> third (second.begin(),second.end());  // iterating through second
                std::vector<int> fourth (third);                       // a copy of third

                // the iterator constructor can also be used to construct from arrays:
                int myints[] = {16,2,77,29};
                std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

                std::cout << "The contents of fifth are:";
                for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
                    std::cout << ' ' << *it;
                std::cout << '\n';
            }
        }
        {
            {
                std::cout << _PURPLE << "Operator with ft " << _END << std::endl;
                ft::vector<int> foo (3,0);
                ft::vector<int> bar (5,0);

                bar = foo;
                foo = ft::vector<int>();

                std::cout << "Size of foo: " << int(foo.size()) << '\n';
                std::cout << "Size of bar: " << int(bar.size()) << '\n';
            }
            {
                std::cout << _PURPLE << "Operator = with std " << _END << std::endl;
                std::vector<int> foo (3,0);
                std::vector<int> bar (5,0);

                bar = foo;
                foo = std::vector<int>();

                std::cout << "Size of foo: " << int(foo.size()) << '\n';
                std::cout << "Size of bar: " << int(bar.size()) << '\n';
            }
        }
    }

    /* ************** FIN DE MEMBER FUNCTIONS ************** */

    /* ************************************************* */
	/*          		Iterators functions : 	      	*/
	/* *************************************************/

    std::cout << std::endl;
    {
        std::cout << _IYELLOW << "Vector -  Iterators " << _END << std::endl;
        {
            {
                {
                    std::cout << _PURPLE << "Begin/end ft " << _END << std::endl;
                    ft::vector<int> myvector;
                    for (int i=1; i<=5; i++) myvector.push_back(i);

                    std::cout << "myvector contains:";
                    for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
                        std::cout << ' ' << *it;
                    std::cout << '\n';
                }
                {
                    std::cout << _PURPLE << "Begin/end std " << _END << std::endl;
                    std::vector<int> myvector;
                    for (int i=1; i<=5; i++) myvector.push_back(i);

                    std::cout << "myvector contains:";
                    for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
                        std::cout << ' ' << *it;
                    std::cout << '\n';
                }
            }
        }
            {
                {
                    std::cout << _PURPLE << "rBegin/rend ft " << _END << std::endl;
                    ft::vector<int> myvector (5);  // 5 default-constructed ints

                    int i=0;

                    ft::vector<int>::reverse_iterator rit = myvector.rbegin();
                    for (; rit!= myvector.rend(); ++rit)
                        *rit = ++i;

                    std::cout << "myvector contains:";
                    for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
                        std::cout << ' ' << *it;
                    std::cout << '\n';
                }
                {
                    std::cout << _PURPLE << "rBegin/rend std " << _END << std::endl;
                    std::vector<int> myvector (5);  // 5 default-constructed ints

                    int i=0;

                    std::vector<int>::reverse_iterator rit = myvector.rbegin();
                    for (; rit!= myvector.rend(); ++rit)
                        *rit = ++i;

                    std::cout << "myvector contains:";
                    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
                        std::cout << ' ' << *it;
                    std::cout << '\n';
                }
            }
        }
    /* ************** FIN ITERATORS ************** */

    /* ************************************************* */
	/*          		Capacity : 	                	*/
	/* *************************************************/
    std::cout << _IYELLOW << "Vector -  Capacity " << _END << std::endl;
    {
        {
            {
                std::cout << _PURPLE << "size with ft " << _END << std::endl;
                ft::vector<int> myints;
                std::cout << "0. size: " << myints.size() << '\n';

                for (int i=0; i<10; i++) myints.push_back(i);
                    std::cout << "1. size: " << myints.size() << '\n';

                myints.insert (myints.end(),10,100);
                std::cout << "2. size: " << myints.size() << '\n';

                myints.pop_back();
                std::cout << "3. size: " << myints.size() << '\n';
            }
            {
                std::cout << _PURPLE << "max_size with ft " << _END << std::endl;
                ft::vector<int> myvector;

                // set some content in the vector:
                for (int i=0; i<100; i++) myvector.push_back(i);

                std::cout << "size: " << myvector.size() << "\n";
                std::cout << "capacity: " << myvector.capacity() << "\n";
                std::cout << "max_size: " << myvector.max_size() << "\n";
            }
            {
                std::cout << _PURPLE << "resize with ft " << _END << std::endl;
                ft::vector<int> myvector;

                // set some initial content:
                for (size_t i=1;i<10;i++) myvector.push_back(i);

                myvector.resize(5);
                myvector.resize(8,100);
                myvector.resize(12);

                std::cout << "myvector contains:";
                for (size_t i=0;i<myvector.size();i++)
                    std::cout << ' ' << myvector[i];
                std::cout << '\n';
            }
            {
                std::cout << _PURPLE << "Capacity with ft " << _END << std::endl;
                ft::vector<int> myvector;

                // set some content in the vector:
                for (int i=0; i<100; i++) myvector.push_back(i);

                std::cout << "size: " << (int) myvector.size() << '\n';
                std::cout << "capacity: " << (int) myvector.capacity() << '\n';
                std::cout << "max_size: " << (int) myvector.max_size() << '\n';
            }
            {
                std::cout << _PURPLE << "Empty with ft " << _END << std::endl;
                ft::vector<int> myvector;
                int sum (0);

                for (int i=1;i<=10;i++) myvector.push_back(i);

                while (!myvector.empty())
                {
                    sum += myvector.back();
                    myvector.pop_back();
                }

                std::cout << "total: " << sum << '\n';
            }
            std::cout << _PURPLE << "reserve with ft " << _END << std::endl;
            {
                ft::vector<int>::size_type sz;

                ft::vector<int> foo;
                sz = foo.capacity();
                std::cout << "making foo grow:\n";
                for (int i=0; i<100; ++i) {
                    foo.push_back(i);
                    if (sz!=foo.capacity()) {
                    sz = foo.capacity();
                    std::cout << "capacity changed: " << sz << '\n';
                    }
                }

                ft::vector<int> bar;
                sz = bar.capacity();
                bar.reserve(100);   // this is the only difference with foo above
                std::cout << "making bar grow:\n";
                for (int i=0; i<100; ++i) {
                    bar.push_back(i);
                    if (sz!=bar.capacity()) {
                    sz = bar.capacity();
                    std::cout << "capacity changed: " << sz << '\n';
                    }
            }
        }
        {
            {
                std::cout << _PURPLE << "size with std " << _END << std::endl;
                std::vector<int> myints;
                std::cout << "0. size: " << myints.size() << '\n';

                for (int i=0; i<10; i++) myints.push_back(i);
                std::cout << "1. size: " << myints.size() << '\n';

                myints.insert (myints.end(),10,100);
                std::cout << "2. size: " << myints.size() << '\n';

                myints.pop_back();
                std::cout << "3. size: " << myints.size() << '\n';
            }
            {
                std::cout << _PURPLE << "max_size with std " << _END << std::endl;
                std::vector<int> myvector;

                // set some content in the vector:
                for (int i=0; i<100; i++) myvector.push_back(i);

                std::cout << "size: " << myvector.size() << "\n";
                std::cout << "capacity: " << myvector.capacity() << "\n";
                std::cout << "max_size: " << myvector.max_size() << "\n";
            }
            {
                std::cout << _PURPLE << "resize with std " << _END << std::endl;
                std::vector<int> myvector;

                // set some initial content:
                for (size_t i=1;i<10;i++) myvector.push_back(i);

                myvector.resize(5);
                myvector.resize(8,100);
                myvector.resize(12);

                std::cout << "myvector contains:";
                for (size_t i=0;i<myvector.size();i++)
                    std::cout << ' ' << myvector[i];
                std::cout << '\n';
            }
            {
                std::cout << _PURPLE << "Capacity with ft " << _END << std::endl;
                std::vector<int> myvector;

                // set some content in the vector:
                for (int i=0; i<100; i++) myvector.push_back(i);

                std::cout << "size: " << (int) myvector.size() << '\n';
                std::cout << "capacity: " << (int) myvector.capacity() << '\n';
                std::cout << "max_size: " << (int) myvector.max_size() << '\n';
            }
            {
                std::cout << _PURPLE << "Empty with std " << _END << std::endl;
                std::vector<int> myvector;
                int sum (0);

                for (int i=1;i<=10;i++) myvector.push_back(i);

                while (!myvector.empty())
                {
                    sum += myvector.back();
                    myvector.pop_back();
                }

                std::cout << "total: " << sum << '\n';
            }
            {
                std::vector<int>::size_type sz;

                std::vector<int> foo;
                sz = foo.capacity();
                std::cout << "making foo grow:\n";
                for (int i=0; i<100; ++i) {
                    foo.push_back(i);
                    if (sz!=foo.capacity()) {
                    sz = foo.capacity();
                    std::cout << "capacity changed: " << sz << '\n';
                    }
                }

                std::vector<int> bar;
                sz = bar.capacity();
                bar.reserve(100);   // this is the only difference with foo above
                std::cout << "making bar grow:\n";
                for (int i=0; i<100; ++i) {
                    bar.push_back(i);
                    if (sz!=bar.capacity()) {
                    sz = bar.capacity();
                    std::cout << "capacity changed: " << sz << '\n';
            }      

        }
    }
    /* ****************** FIN CAPACITY *********************************** */

    /* ************************************************* */
	/*          		Element accees : 	          	*/
	/* *************************************************/

    std::cout << _IYELLOW << "Vector - Element qccess " << _END << std::endl;

    {

        {
            std::cout << _PURPLE << "Operator [] with ft" << _END << std::endl;
            ft::vector<int> myvector (10);   // 10 zero-initialized elements

            ft::vector<int>::size_type sz = myvector.size();

            // assign some values:
            for (unsigned i=0; i<sz; i++) myvector[i]=i;

            // reverse vector using operator[]:
            for (unsigned i=0; i<sz/2; i++)
            {
                int temp;
                temp = myvector[sz-1-i];
                myvector[sz-1-i]=myvector[i];
                myvector[i]=temp;
            }

            std::cout << "myvector contains:";
            for (unsigned i=0; i<sz; i++)
                std::cout << ' ' << myvector[i];
            std::cout << '\n';
        }
        {
            std::cout << _PURPLE << "at with ft" << _END << std::endl;
            ft::vector<int> myvector (10);   // 10 zero-initialized ints

            // assign some values:
            for (unsigned i=0; i<myvector.size(); i++)
                myvector.at(i)=i;

            std::cout << "myvector contains:";
            for (unsigned i=0; i<myvector.size(); i++)
                std::cout << ' ' << myvector.at(i);
            std::cout << '\n';
        }
        {
            std::cout << _PURPLE << "font with ft" << _END << std::endl;
           ft::vector<int> myvector;

            myvector.push_back(78);
            myvector.push_back(16);

            // now front equals 78, and back 16

            myvector.front() -= myvector.back();

            std::cout << "myvector.front() is now " << myvector.front() << '\n';
        }
        {
            std::cout << _PURPLE << "back with ft" << _END << std::endl;

            ft::vector<int> myvector;

            myvector.push_back(10);

            while (myvector.back() != 0)
            {
                myvector.push_back ( myvector.back() -1 );
            }

            std::cout << "myvector contains:";
            for (unsigned i=0; i<myvector.size() ; i++)
                std::cout << ' ' << myvector[i];
            std::cout << '\n';
        }
        {
            std::cout << _PURPLE << "Operator [] with std" << _END << std::endl;

            std::vector<int> myvector (10);   // 10 zero-initialized elements

            std::vector<int>::size_type sz = myvector.size();

            // assign some values:
            for (unsigned i=0; i<sz; i++) myvector[i]=i;

            // reverse vector using operator[]:
            for (unsigned i=0; i<sz/2; i++)
            {
                int temp;
                temp = myvector[sz-1-i];
                myvector[sz-1-i]=myvector[i];
                myvector[i]=temp;
            }

            std::cout << "myvector contains:";
            for (unsigned i=0; i<sz; i++)
                std::cout << ' ' << myvector[i];
            std::cout << '\n';
        }
        {
            std::cout << _PURPLE << "at with std" << _END << std::endl;
            std::vector<int> myvector (10);   // 10 zero-initialized ints

            // assign some values:
            for (unsigned i=0; i<myvector.size(); i++)
                myvector.at(i)=i;

            std::cout << "myvector contains:";
            for (unsigned i=0; i<myvector.size(); i++)
                std::cout << ' ' << myvector.at(i);
            std::cout << '\n';
        }
        {
            std::cout << _PURPLE << "front with std" << _END << std::endl;
            std::vector<int> myvector;

            myvector.push_back(78);
            myvector.push_back(16);

            // now front equals 78, and back 16

            myvector.front() -= myvector.back();

            std::cout << "myvector.front() is now " << myvector.front() << '\n';
        }
        {
            std::cout << _PURPLE << "back with std" << _END << std::endl;

            std::vector<int> myvector;

            myvector.push_back(10);

            while (myvector.back() != 0)
            {
                myvector.push_back ( myvector.back() -1 );
            }

            std::cout << "myvector contains:";
            for (unsigned i=0; i<myvector.size() ; i++)
                std::cout << ' ' << myvector[i];
            std::cout << '\n';
        }
    }
    /* ****************** FIN CAPACITY *********************************** */

    /* ************************************************* */
	/*          		Modifiers : 	               	*/
	/* *************************************************/

    std::cout << _IYELLOW << "Vector - Modifiers " << _END << std::endl;
    {
        {
            std::cout << _PURPLE << "assign with ft" << _END << std::endl;
            ft::vector<int> first;
            ft::vector<int> second;
            ft::vector<int> third;

            first.assign (7,100);             // 7 ints with a value of 100

            ft::vector<int>::iterator it;
            it=first.begin()+1;

            second.assign (it,first.end()-1); // the 5 central values of first

            int myints[] = {1776,7,4};
            third.assign (myints,myints+3);   // assigning from array.

            std::cout << "Size of first: " << int (first.size()) << '\n';
            std::cout << "Size of second: " << int (second.size()) << '\n';
            std::cout << "Size of third: " << int (third.size()) << '\n';
        }
        {
            std::cout << _PURPLE << "assign with std" << _END << std::endl;
            std::vector<int> first;
            std::vector<int> second;
            std::vector<int> third;

            first.assign (7,100);             // 7 ints with a value of 100

            std::vector<int>::iterator it;
            it=first.begin()+1;

            second.assign (it,first.end()-1); // the 5 central values of first

            int myints[] = {1776,7,4};
            third.assign (myints,myints+3);   // assigning from array.

            std::cout << "Size of first: " << int (first.size()) << '\n';
            std::cout << "Size of second: " << int (second.size()) << '\n';
            std::cout << "Size of third: " << int (third.size()) << '\n';
        }
        {
            std::cout << _PURPLE << "push_back with ft" << _END << std::endl;
            ft::vector<int> myvector;
            int myint;

            std::cout << "Please enter some integers (enter 0 to end):\n";

            do {
                std::cin >> myint;
                myvector.push_back (myint);
            } while (myint);

            std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
        }
        {
            std::cout << _PURPLE << "push_back with std" << _END << std::endl;
            std::vector<int> myvector;
            int myint;

            std::cout << "Please enter some integers (enter 0 to end):\n";

            do {
                std::cin >> myint;
                myvector.push_back (myint);
            } while (myint);

            std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
        }
        {
            std::cout << _PURPLE << "pop_back with ft" << _END << std::endl;
            ft::vector<int> myvector;
            int sum (0);
            myvector.push_back (100);
            myvector.push_back (200);
            myvector.push_back (300);

            while (!myvector.empty())
            {
                sum+=myvector.back();
                myvector.pop_back();
            }

            std::cout << "The elements of myvector add up to " << sum << '\n';
        }
        {
            std::cout << _PURPLE << "pop_back with std" << _END << std::endl;
            ft::vector<int> myvector;
            int sum (0);
            myvector.push_back (100);
            myvector.push_back (200);
            myvector.push_back (300);

            while (!myvector.empty())
            {
                sum+=myvector.back();
                myvector.pop_back();
            }

            std::cout << "The elements of myvector add up to " << sum << '\n';
        }
        {
            std::cout << _PURPLE << "insert with ft" << _END << std::endl;
            ft::vector<int> myvector (3,100);
            ft::vector<int>::iterator it;

            it = myvector.begin();
            it = myvector.insert ( it , 200 );

            myvector.insert (it,2,300);

            // "it" no longer valid, get a new one:
            it = myvector.begin();

            ft::vector<int> anothervector (2,400);
            myvector.insert (it+2,anothervector.begin(),anothervector.end());

            int myarray [] = { 501,502,503 };
            myvector.insert (myvector.begin(), myarray, myarray+3);

            std::cout << "myvector contains:";
            for (it=myvector.begin(); it<myvector.end(); it++)
                std::cout << ' ' << *it;
            std::cout << '\n';
        }
        {
            std::cout << _PURPLE << "insert with std" << _END << std::endl;
            std::vector<int> myvector (3,100);
            std::vector<int>::iterator it;

            it = myvector.begin();
            it = myvector.insert ( it , 200 );

            myvector.insert (it,2,300);

            // "it" no longer valid, get a new one:
            it = myvector.begin();

            std::vector<int> anothervector (2,400);
            myvector.insert (it+2,anothervector.begin(),anothervector.end());

            int myarray [] = { 501,502,503 };
            myvector.insert (myvector.begin(), myarray, myarray+3);

            std::cout << "myvector contains:";
            for (it=myvector.begin(); it<myvector.end(); it++)
                std::cout << ' ' << *it;
            std::cout << '\n';
        }
        {
            std::cout << _PURPLE << "Erase with std" << _END << std::endl;
            ft::vector<int> myvector;

            // set some values (from 1 to 10)
            for (int i=1; i<=10; i++) myvector.push_back(i);

            // erase the 6th element
            myvector.erase (myvector.begin()+5);

            // erase the first 3 elements:
            myvector.erase (myvector.begin(),myvector.begin()+3);

            std::cout << "myvector contains:";
            for (unsigned i=0; i<myvector.size(); ++i)
                std::cout << ' ' << myvector[i];
            std::cout << '\n';
        }
        {
            std::cout << _PURPLE << "Erase with ft" << _END << std::endl;
            std::vector<int> myvector;

            // set some values (from 1 to 10)
            for (int i=1; i<=10; i++) myvector.push_back(i);

            // erase the 6th element
            myvector.erase (myvector.begin()+5);

            // erase the first 3 elements:
            myvector.erase (myvector.begin(),myvector.begin()+3);

            std::cout << "myvector contains:";
            for (unsigned i=0; i<myvector.size(); ++i)
                std::cout << ' ' << myvector[i];
            std::cout << '\n';
        }
        {
            std::cout << _PURPLE << "Swap with ft" << _END << std::endl;

            ft::vector<int> foo (3,100);   // three ints with a value of 100
            ft::vector<int> bar (5,200);   // five ints with a value of 200

            foo.swap(bar);

            std::cout << "foo contains:";
            for (unsigned i=0; i<foo.size(); i++)
                std::cout << ' ' << foo[i];
            std::cout << '\n';

            std::cout << "bar contains:";
            for (unsigned i=0; i<bar.size(); i++)
                std::cout << ' ' << bar[i];
            std::cout << '\n';
        }
        {
            std::cout << _PURPLE << "Swap with std" << _END << std::endl;

            std::vector<int> foo (3,100);   // three ints with a value of 100
            std::vector<int> bar (5,200);   // five ints with a value of 200

            foo.swap(bar);

            std::cout << "foo contains:";
            for (unsigned i=0; i<foo.size(); i++)
                std::cout << ' ' << foo[i];
            std::cout << '\n';

            std::cout << "bar contains:";
            for (unsigned i=0; i<bar.size(); i++)
                std::cout << ' ' << bar[i];
            std::cout << '\n';
        }
        {
            std::cout << _PURPLE << "Clear with ft" << _END << std::endl;
            ft::vector<int> myvector;
            myvector.push_back (100);
            myvector.push_back (200);
            myvector.push_back (300);

            std::cout << "myvector contains:";
            for (unsigned i=0; i<myvector.size(); i++)
                std::cout << ' ' << myvector[i];
            std::cout << '\n';

            myvector.clear();
            myvector.push_back (1101);
            myvector.push_back (2202);

            std::cout << "myvector contains:";
            for (unsigned i=0; i<myvector.size(); i++)
                std::cout << ' ' << myvector[i];
            std::cout << '\n';
        }
        {
            std::cout << _PURPLE << "Clear with std" << _END << std::endl;
            std::vector<int> myvector;
            myvector.push_back (100);
            myvector.push_back (200);
            myvector.push_back (300);

            std::cout << "myvector contains:";
            for (unsigned i=0; i<myvector.size(); i++)
                std::cout << ' ' << myvector[i];
            std::cout << '\n';

            myvector.clear();
            myvector.push_back (1101);
            myvector.push_back (2202);

            std::cout << "myvector contains:";
            for (unsigned i=0; i<myvector.size(); i++)
                std::cout << ' ' << myvector[i];
            std::cout << '\n';
        }
        {
            std::cout << _PURPLE << "getAllocator with ft" << _END << std::endl;
            ft::vector<int> myvector;
            int * p;
            unsigned int i;

            // allocate an array with space for 5 elements using vector's allocator:
            p = myvector.get_allocator().allocate(5);

            // construct values in-place on the array:
            for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

            std::cout << "The allocated array contains:";
            for (i=0; i<5; i++) std::cout << ' ' << p[i];
            std::cout << '\n';

            // destroy and deallocate:
            for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
            myvector.get_allocator().deallocate(p,5);
        }
        {
            std::cout << _PURPLE << "getAllocator with std" << _END << std::endl;
            std::vector<int> myvector;
            int * p;
            unsigned int i;

            // allocate an array with space for 5 elements using vector's allocator:
            p = myvector.get_allocator().allocate(5);

            // construct values in-place on the array:
            for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

            std::cout << "The allocated array contains:";
            for (i=0; i<5; i++) std::cout << ' ' << p[i];
            std::cout << '\n';

            // destroy and deallocate:
            for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
            myvector.get_allocator().deallocate(p,5);
        }
        {
            std::cout << _PURPLE << "Relational with ft" << _END << std::endl;
            ft::vector<int> foo (3,100);   // three ints with a value of 100
            ft::vector<int> bar (2,200);   // two ints with a value of 200

            if (foo==bar) std::cout << "foo and bar are equal\n";
            if (foo!=bar) std::cout << "foo and bar are not equal\n";
            if (foo< bar) std::cout << "foo is less than bar\n";
            if (foo> bar) std::cout << "foo is greater than bar\n";
            if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
            if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
        }
        {
            std::cout << _PURPLE << "Relational with std" << _END << std::endl;
            std::vector<int> foo (3,100);   // three ints with a value of 100
            std::vector<int> bar (2,200);   // two ints with a value of 200

            if (foo==bar) std::cout << "foo and bar are equal\n";
            if (foo!=bar) std::cout << "foo and bar are not equal\n";
            if (foo< bar) std::cout << "foo is less than bar\n";
            if (foo> bar) std::cout << "foo is greater than bar\n";
            if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
            if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
        }
    }
    // {
    //     {
    //         std::cout << _PURPLE << "Insert with ft" << _END << std::endl;

    //         ft::map<char,int> mymap;

    //         // first insert function version (single parameter):
    //         mymap.insert ( ft::pair<char,int>('a',100) );
    //         mymap.insert ( ft::pair<char,int>('z',200) );


    //         ft::pair<ft::map<char,int>::iterator,bool> ret;
    //         ret = mymap.insert ( ft::pair<char,int>('z',500) );
    //         if (ret.second==false) {
    //             std::cout << "element 'z' already existed";
    //             std::cout << " with a value of " << ret.first->second << '\n';
    //         }

    //         // second insert function version (with hint position):
    //         ft::map<char,int>::iterator it = mymap.begin();
    //         std::cout << "NOT INVALIDATING ITERATOR  = " << it->first << std::endl;
    //         mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
    //         mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting
    //         std::cout << "NOT INVALIDATING ITERATOR = " << it->first << std::endl;

    //         // third insert function version (range insertion):
    //         ft::map<char,int> anothermap;
    //         anothermap.insert(mymap.begin(),mymap.find('c'));

    //         // showing contents:
    //         std::cout << "mymap contains:\n";
    //         for (it=mymap.begin(); it!=mymap.end(); ++it)
    //             std::cout << it->first << " => " << it->second << '\n';

    //         std::cout << "anothermap contains:\n";
    //         for (it=anothermap.begin(); it!=anothermap.end(); ++it)
    //             std::cout << it->first << " => " << it->second << '\n';
    //     }
    //     {
    //         std::cout << _PURPLE << "Insert with std" << _END << std::endl;
    //         std::map<char,int> mymap;

    //         // first insert function version (single parameter):
    //         mymap.insert ( std::pair<char,int>('a',100) );
    //         mymap.insert ( std::pair<char,int>('z',200) );

    //         std::pair<std::map<char,int>::iterator,bool> ret;
    //         ret = mymap.insert ( std::pair<char,int>('z',500) );
    //         if (ret.second==false) {
    //             std::cout << "element 'z' already existed";
    //             std::cout << " with a value of " << ret.first->second << '\n';
    //         }

    //         // second insert function version (with hint position):
    //         std::map<char,int>::iterator it = mymap.begin();
    //         std::cout << "NOT INVALIDATING ITERATOR  = " << it->first << std::endl;
    //         mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
    //         mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting
    //         std::cout << "NOT INVALIDATING ITERATOR  = " << it->first << std::endl;

    //         // third insert function version (range insertion):
    //         std::map<char,int> anothermap;
    //         anothermap.insert(mymap.begin(),mymap.find('c'));

    //         // showing contents:
    //         std::cout << "mymap contains:\n";
    //         for (it=mymap.begin(); it!=mymap.end(); ++it)
    //             std::cout << it->first << " => " << it->second << '\n';

    //         std::cout << "anothermap contains:\n";
    //         for (it=anothermap.begin(); it!=anothermap.end(); ++it)
    //             std::cout << it->first << " => " << it->second << '\n';
    //     }
    //     {
    //         std::cout << _PURPLE << "Erase with ft" << _END << std::endl;
    //         ft::map<char,int> mymap;
    //         ft::map<char,int>::iterator it;

    //         // insert some values:
    //         mymap['a']=10;
    //         mymap['b']=20;
    //         mymap['c']=30;
    //         mymap['d']=40;
    //         mymap['e']=50;
    //         mymap['f']=60;

    //         it=mymap.find('b');
    //         mymap.erase (it);                   // erasing by iterator
    //         mymap.erase ('c');                  // erasing by key

    //         it=mymap.find ('e');
    //         mymap.erase ( it, mymap.end() );    // erasing by range

    //         // show content:
    //         for (it=mymap.begin(); it!=mymap.end(); ++it)
    //             std::cout << it->first << " => " << it->second << '\n';
    //     }
    //     {
    //         std::cout << _PURPLE << "Erase with std" << _END << std::endl;
            
    //         std::map<char,int> mymap;
    //         std::map<char,int>::iterator it;

    //         // insert some values:
    //         mymap['a']=10;
    //         mymap['b']=20;
    //         mymap['c']=30;
    //         mymap['d']=40;
    //         mymap['e']=50;
    //         mymap['f']=60;

    //         it=mymap.find('b');
    //         mymap.erase (it);                   // erasing by iterator

    //         mymap.erase ('c');                  // erasing by key

    //         it=mymap.find ('e');
    //         mymap.erase ( it, mymap.end() );    // erasing by range

    //         // show content:
    //         for (it=mymap.begin(); it!=mymap.end(); ++it)
    //             std::cout << it->first << " => " << it->second << '\n';
    //     }
    //     {
    //         std::cout << _PURPLE << "SWAP with ft" << _END << std::endl;
    //         ft::map<char,int> foo,bar;

    //         foo['x']=100;
    //         foo['y']=200;

    //         bar['a']=11;
    //         bar['b']=22;
    //         bar['c']=33;

    //         foo.swap(bar);

    //         std::cout << "foo contains:\n";
    //         for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    //             std::cout << it->first << " => " << it->second << '\n';

    //         std::cout << "bar contains:\n";
    //         for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
    //             std::cout << it->first << " => " << it->second << '\n';
    //     }
    //     {
    //         std::cout << _PURPLE << "SWAP with std" << _END << std::endl;

    //         std::map<char,int> foo,bar;

    //         foo['x']=100;
    //         foo['y']=200;

    //         bar['a']=11;
    //         bar['b']=22;
    //         bar['c']=33;

    //         foo.swap(bar);

    //         std::cout << "foo contains:\n";
    //         for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    //             std::cout << it->first << " => " << it->second << '\n';

    //         std::cout << "bar contains:\n";
    //         for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
    //             std::cout << it->first << " => " << it->second << '\n';
    //     }
    //     {
    //         std::cout << _PURPLE << "CLEAR with ft" << _END << std::endl;

    //         ft::map<char,int> mymap;

    //         mymap['x']=100;
    //         mymap['y']=200;
    //         mymap['z']=300;

    //         std::cout << "mymap contains:\n";
    //         for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    //             std::cout << it->first << " => " << it->second << '\n';

    //         mymap.clear();
    //         mymap['a']=1101;
    //         mymap['b']=2202;

    //         std::cout << "mymap contains:\n";
    //         for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    //             std::cout << it->first << " => " << it->second << '\n';
    //     }
    //     {
    //         std::cout << _PURPLE << "CLEAR with std" << _END << std::endl;

    //         std::map<char,int> mymap;

    //         mymap['x']=100;
    //         mymap['y']=200;
    //         mymap['z']=300;

    //         std::cout << "mymap contains:\n";
    //         for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    //             std::cout << it->first << " => " << it->second << '\n';

    //         mymap.clear();
    //         mymap['a']=1101;
    //         mymap['b']=2202;

    //         std::cout << "mymap contains:\n";
    //         for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    //             std::cout << it->first << " => " << it->second << '\n';
    //     }
        
    // }

    // /* ****************** FIN MODIFIERS *********************************** */

    // /* ************************************************* */
	// /*          		Modifiers : 	               	*/
	// /* *************************************************/
    // {
    //     {
    //         std::cout << _PURPLE << "KEY COMPARE with ft" << _END << std::endl;
            
    //         ft::map<char,int> mymap;

    //         ft::map<char,int>::key_compare mycomp = mymap.key_comp();

    //         mymap['a']=100;
    //         mymap['b']=200;
    //         mymap['c']=300;

    //         std::cout << "mymap contains:\n";

    //         char highest = mymap.rbegin()->first;     // key value of last element

    //         ft::map<char,int>::iterator it = mymap.begin();
    //         do {
    //             std::cout << it->first << " => " << it->second << '\n';
    //         } while ( mycomp((*it++).first, highest) );

    //         std::cout << '\n';
    //     }
    //     {
    //         std::cout << _PURPLE << "KEY COMPARE with std" << _END << std::endl;

    //         std::map<char,int> mymap;

    //         std::map<char,int>::key_compare mycomp = mymap.key_comp();

    //         mymap['a']=100;
    //         mymap['b']=200;
    //         mymap['c']=300;

    //         std::cout << "mymap contains:\n";

    //         char highest = mymap.rbegin()->first;     // key value of last element

    //         std::map<char,int>::iterator it = mymap.begin();
    //         do {
    //             std::cout << it->first << " => " << it->second << '\n';
    //         } while ( mycomp((*it++).first, highest) );

    //         std::cout << '\n';
    //     }
    //     {
    //         std::cout << _PURPLE << "VALUE COMPARE with ft" << _END << std::endl;
    //         ft::map<char,int> mymap;

    //         mymap['x']=1001;
    //         mymap['y']=2002;
    //         mymap['z']=3003;

    //         std::cout << "mymap contains:\n";

    //         ft::pair<char,int> highest = *mymap.rbegin();          // last element

    //         ft::map<char,int>::iterator it = mymap.begin();
    //         do {
    //             std::cout << it->first << " => " << it->second << '\n';
    //         } while ( mymap.value_comp()(*it++, highest) );
    //     }   
    //     {
    //         std::cout << _PURPLE << "VALUE COMPARE with std" << _END << std::endl;
    //         std::map<char,int> mymap;

    //         mymap['x']=1001;
    //         mymap['y']=2002;
    //         mymap['z']=3003;

    //         std::cout << "mymap contains:\n";

    //         std::pair<char,int> highest = *mymap.rbegin();          // last element

    //         std::map<char,int>::iterator it = mymap.begin();
    //         do {
    //             std::cout << it->first << " => " << it->second << '\n';
    //         } while ( mymap.value_comp()(*it++, highest) );
    //     }  
    // }

    // /* ****************** FIN Observers *********************************** */

    // /* ************************************************* */
	// /*          		OPERATIONS : 	               	*/
	// /* *************************************************/
    // {
    //     {

    //        std::cout << _PURPLE << "Find with ft" << _END << std::endl;

    //         ft::map<char,int> mymap;
    //         ft::map<char,int>::iterator it;

    //         mymap['a']=50;
    //         mymap['b']=100;
    //         mymap['c']=150;
    //         mymap['d']=200;

    //         it = mymap.find('b');
    //         if (it != mymap.end())
    //             mymap.erase (it);

    //         // print content:
    //         std::cout << "elements in mymap:" << '\n';
    //         std::cout << "a => " << mymap.find('a')->second << '\n';
    //         std::cout << "c => " << mymap.find('c')->second << '\n';
    //         std::cout << "d => " << mymap.find('d')->second << '\n';
    //     }
    //     {
    //         std::cout << _PURPLE << "Find with std" << _END << std::endl;

    //         std::map<char,int> mymap;
    //         std::map<char,int>::iterator it;

    //         mymap['a']=50;
    //         mymap['b']=100;
    //         mymap['c']=150;
    //         mymap['d']=200;

    //         it = mymap.find('b');
    //         if (it != mymap.end())
    //             mymap.erase (it);

    //         // print content:
    //         std::cout << "elements in mymap:" << '\n';
    //         std::cout << "a => " << mymap.find('a')->second << '\n';
    //         std::cout << "c => " << mymap.find('c')->second << '\n';
    //         std::cout << "d => " << mymap.find('d')->second << '\n';
    //     }
    //     {
    //         std::cout << _PURPLE << "Count with ft" << _END << std::endl;

    //         ft::map<char,int> mymap;
    //         char c;

    //         mymap ['a']=101;
    //         mymap ['c']=202;
    //         mymap ['f']=303;

    //         for (c='a'; c<'h'; c++)
    //         {
    //             std::cout << c;
    //             if (mymap.count(c)>0)
    //             std::cout << " is an element of mymap.\n";
    //             else 
    //             std::cout << " is not an element of mymap.\n";
    //         }
    //     }
    //     {
    //         std::cout << _PURPLE << "Count with std" << _END << std::endl;

    //         std::map<char,int> mymap;
    //         char c;

    //         mymap ['a']=101;
    //         mymap ['c']=202;
    //         mymap ['f']=303;

    //         for (c='a'; c<'h'; c++)
    //         {
    //             std::cout << c;
    //             if (mymap.count(c)>0)
    //             std::cout << " is an element of mymap.\n";
    //             else 
    //             std::cout << " is not an element of mymap.\n";
    //         }
    //     }
    //     {
    //         std::cout << _PURPLE << "lower bound  with ft" << _END << std::endl;
            
    //         ft::map<char,int> mymap;
    //         ft::map<char,int>::iterator itlow,itup;

    //         mymap['a']=20;
    //         mymap['b']=40;
    //         mymap['c']=60;
    //         mymap['d']=80;
    //         mymap['e']=100;

    //         itlow=mymap.lower_bound ('b');  // itlow points to b
    //         itup=mymap.upper_bound ('d');   // itup points to e (not d!)

    //         mymap.erase(itlow,itup);        // erases [itlow,itup)

    //         // print content:
    //         for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    //             std::cout << it->first << " => " << it->second << '\n';
    //     }
    //     {
    //         std::cout << _PURPLE << "lower bound  with ft" << _END << std::endl;
            
    //         std::map<char,int> mymap;
    //         std::map<char,int>::iterator itlow,itup;

    //         mymap['a']=20;
    //         mymap['b']=40;
    //         mymap['c']=60;
    //         mymap['d']=80;
    //         mymap['e']=100;

    //         itlow=mymap.lower_bound ('b');  // itlow points to b
    //         itup=mymap.upper_bound ('d');   // itup points to e (not d!)

    //         mymap.erase(itlow,itup);        // erases [itlow,itup)

    //         // print content:
    //         for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    //             std::cout << it->first << " => " << it->second << '\n';
    //     }
    //     {
    //         std::cout << _PURPLE << "upper bound  with ft" << _END << std::endl;
    //         ft::map<char,int> mymap;
    //         ft::map<char,int>::iterator itlow,itup;

    //         mymap['a']=20;
    //         mymap['b']=40;
    //         mymap['c']=60;
    //         mymap['d']=80;
    //         mymap['e']=100;

    //         itlow=mymap.lower_bound ('b');  // itlow points to b
    //         itup=mymap.upper_bound ('d');   // itup points to e (not d!)

    //         mymap.erase(itlow,itup);        // erases [itlow,itup)

    //         // print content:
    //         for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    //             std::cout << it->first << " => " << it->second << '\n';
    //     }
    //     {
    //         std::cout << _PURPLE << "upper bound  with std" << _END << std::endl;
    //         std::map<char,int> mymap;
    //         std::map<char,int>::iterator itlow,itup;

    //         mymap['a']=20;
    //         mymap['b']=40;
    //         mymap['c']=60;
    //         mymap['d']=80;
    //         mymap['e']=100;

    //         itlow=mymap.lower_bound ('b');  // itlow points to b
    //         itup=mymap.upper_bound ('d');   // itup points to e (not d!)

    //         mymap.erase(itlow,itup);        // erases [itlow,itup)

    //         // print content:
    //         for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    //             std::cout << it->first << " => " << it->second << '\n';
    //     }
    //     {
    //         std::cout << _PURPLE << "equal range with ft" << _END << std::endl;

    //         ft::map<char,int> mymap;

    //         mymap['a']=10;
    //         mymap['b']=20;
    //         mymap['c']=30;

    //         ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
    //         ret = mymap.equal_range('b');

    //         std::cout << "lower bound points to: ";
    //         std::cout << ret.first->first << " => " << ret.first->second << '\n';

    //         std::cout << "upper bound points to: ";
    //         std::cout << ret.second->first << " => " << ret.second->second << '\n';
    //     }
    //     {
    //         std::cout << _PURPLE << "equal range with std" << _END << std::endl;

    //         std::map<char,int> mymap;

    //         mymap['a']=10;
    //         mymap['b']=20;
    //         mymap['c']=30;

    //         std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
    //         ret = mymap.equal_range('b');

    //         std::cout << "lower bound points to: ";
    //         std::cout << ret.first->first << " => " << ret.first->second << '\n';

    //         std::cout << "upper bound points to: ";
    //         std::cout << ret.second->first << " => " << ret.second->second << '\n';
    //     }
        }
    }
    }
    }