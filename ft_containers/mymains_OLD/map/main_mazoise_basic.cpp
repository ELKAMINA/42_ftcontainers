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
#include <string>

/* For colours in terminal/outputs : https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal*/

// using namespace ft;

int main()
{
	{

        using namespace ft;   
        pair<int, std::string>			my_pair(8, "salut");
        map<int, std::string>			test;
        map<int, std::string>::iterator	it;

        test.insert(my_pair);
        test.insert(pair<int, std::string>(-4, "bar"));
        test.insert(pair<int, std::string>(2, "machin"));
        test.insert(pair<int, std::string>(3, "foo"));
        test.insert(pair<int, std::string>(746, "Marcel"));
        test.insert(pair<int, std::string>(1, "truc"));
        it = test.begin();
        std::cout << '\n';

        while (it != test.end())
        {
            // cout << "start of while\n";
            std::cout << it->first << ", " << it->second << '\n';
            it++;
        }
    }
    {
        using namespace std;   
        pair<int, std::string>			my_pair(8, "salut");
        map<int, std::string>			test;
        map<int, std::string>::iterator	it;

        test.insert(my_pair);
        test.insert(pair<int, std::string>(-4, "bar"));
        test.insert(pair<int, std::string>(2, "machin"));
        test.insert(pair<int, std::string>(3, "foo"));
        test.insert(pair<int, std::string>(746, "Marcel"));
        test.insert(pair<int, std::string>(1, "truc"));
        it = test.begin();
        std::cout << '\n';

        while (it != test.end())
        {
            // cout << "start of while\n";
            std::cout << it->first << ", " << it->second << '\n';
            it++;
        }
    }
}