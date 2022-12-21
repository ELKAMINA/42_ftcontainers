#include <iostream>
#include <iomanip>
#include "./includes/Stack.hpp"
#include "./includes/vector.hpp"
#include "./includes/ReverseIterator.hpp"

/* For colours in terminal/outputs : https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal*/

using namespace std;

int  main()
{
    std::cout << "\e[1;41m MAZOISE TESTS\033[0m\n" << std::endl;
    {
        std::cout << "\e[0;34m Real Constructors -> >>>> \e[0m" << std::endl;
    	vector<int>			test(3, 3);

		cout << "self assignation test\n";
		vector<vector<int> >	self_assign;
		vector<vector<int> >	*ptr = &self_assign;
		vector<vector<int> >	*ptr2 = &self_assign;

		self_assign.assign(4, test);
		*ptr = *ptr2;

		cout << std::boolalpha << (*ptr == *ptr2) << '\n';
	//	self_assign = self_assign; //compiler doesn't like it!
		vector<vector<int> > JOHN;
		vector<vector<int> > BOB(5, test);
		cout << "BOB(5, test(test, 5)) : \n";
		for (size_t i = 0; i < BOB.size(); i++)
		{
			for (size_t j = 0; j < BOB[i].size(); j++)
				cout << BOB[i][j] << ' ';
			cout << '\n';
		}
		vector<vector<int> > MIKE(BOB);

		// // CTORs
		cout << "\nCTORS\n";
		cout << "Empty is empty ? " << std::boolalpha << JOHN.empty() << '\n';
		cout << "BOB is empty? " << BOB.empty() << '\n';

		cout << "Size of JOHN " << JOHN.size() << std::endl;
		cout << "Size of BOB " << BOB.size() << std::endl;
		cout << "Size of MIKE " << MIKE.size() << std::endl;
        /* This part is OKKKKK */

        	// RESIZE
		size_t	bob_resize = 2;
		cout << "\nRESIZE\n";
		BOB.resize(bob_resize);
		cout << "Size of JOHN " << JOHN.size() << std::endl;
		if (JOHN.capacity() >= JOHN.size())
			cout << "Capacity of JOHN is sufficient\n";
		else
			std::cerr << "THERE IS A PROBLEM ON LINE 53\n";
		cout << "Size of BOB " << BOB.size() << std::endl;
		if (BOB.capacity() >= bob_resize)
			cout << "Capacity of BOB is sufficient\n";
		else
			std::cerr << "THERE IS A PROBLEM ON LINE 58\n";
		cout << "Size of MIKE " << MIKE.size() << std::endl;
		if (MIKE.capacity() >= MIKE.size())
			cout << "Capacity of MIKE is sufficient\n";
		else
			std::cerr << "THERE IS A PROBLEM ON LINE 63\n";

		size_t	mike_resize = 9;
		bob_resize = 0;
		
		BOB.resize(bob_resize);
		cout << "BOB is empty now ? " << BOB.empty() << '\n';
		MIKE.resize(mike_resize, test);
		cout << "Size of JOHN " << JOHN.size() << std::endl;
		if (JOHN.capacity() >= JOHN.size())
			cout << "Capacity of JOHN is sufficient\n";
		else
			std::cerr << "THERE IS A PROBLEM ON LINE 86\n";
		cout << "Size of BOB " << BOB.size() << std::endl;
		if (BOB.capacity() >= bob_resize)
			cout << "Capacity of BOB is sufficient\n";
		else
			std::cerr << "THERE IS A PROBLEM ON LINE 91\n";
		cout << "Size of MIKE " << MIKE.size() << std::endl;
		if (MIKE.capacity() >= mike_resize)
			cout << "Capacity of MIKE is sufficient\n";
		else
			std::cerr << "THERE IS A PROBLEM ON LINE 96\n";
		for (size_t i = 0; i < MIKE.size(); i++)
		{
			for (size_t j = 0; j < MIKE[i].size(); j++)
			{
				cout << MIKE[i][j] << ' ';
			}
		cout << std::endl;
		}
         // RESERVE
        cout << "\n REAALRESERVE ************\n";

        size_t	john_reserve = 0;
        size_t	bob_reserve = 3;
        size_t	mike_reserve = 4;

        JOHN.reserve(john_reserve);
        BOB.reserve(bob_reserve);
        MIKE.reserve(mike_reserve);
        cout << "Size of JOHN " << JOHN.size() << std::endl;
        if (JOHN.capacity() >= john_reserve)
            cout << "Capacity of JOHN is sufficient\n";
        else
            std::cerr << "THERE IS A PROBLEM ON LINE 120\n";
        cout << "Size of BOB " << BOB.size() << std::endl;
        if (BOB.capacity() >= bob_reserve)
            cout << "Capacity of BOB is sufficient\n";
        else
            std::cerr << "THERE IS A PROBLEM ON LINE 125\n";
        cout << "Size of MIKE " << MIKE.size() << std::endl;
        if (MIKE.capacity() >= mike_reserve)
            cout << "Capacity of MIKE is sufficient\n";
        else
            std::cerr << "THERE IS A PROBLEM ON LINE 130\n";
        for (size_t i = 0; i < MIKE.size(); i++)
        {
            for (size_t j = 0; j < MIKE[i].size(); j++)
                cout << MIKE[i][j] << ' ';
        cout << std::endl;
        }

            //AT
        cout << "\n REAAAAL AT\n";
        try
        {
            cout << MIKE.at(2).front() << '\n';
            cout << MIKE.at(87).back() << '\n';
        }
        catch (std::out_of_range& oor)
        {
            (void)oor;
            cout << "OOR error caught\n";
        }
        // FRONT / BACK
        cout << "\n REALLLLLLLLLLL FRONT / BACK\n";
        cout << "front() of MIKE : " << MIKE.front().front() << '\n';
        cout << "back() of MIKE : " << MIKE.back().back() << '\n';

        //ASSIGN
        cout << "\nASSIGN\n";
        test.assign(3, 17);
        BOB.assign(3, test);

        //ASSIGN RANGE
        cout << "\nASSIGN RANGE\n";
        vector<vector<int> >	assign_range;
        assign_range.assign(8, test);
        assign_range.assign(BOB.begin() + 1, BOB.end() - 2);

        //EMPTY
        cout << "\nEMPTY\n";
        cout << "BOB is empty ? " << BOB.empty() << '\n';
        cout << "BOB at(1) : " << BOB.at(1).front() << '\n';

    }
    {
        std::cout << "\e[0;34m My Constructors -> >>>> \e[0m" << std::endl;
    	ft::vector<int>			test(3, 3);

		cout << "self assignation test\n";
		ft::vector<ft::vector<int> >	self_assign;
		ft::vector<ft::vector<int> >	*ptr = &self_assign;
		ft::vector<ft::vector<int> >	*ptr2 = &self_assign;

		self_assign.assign(4, test);
		*ptr = *ptr2;

		cout << std::boolalpha << (*ptr == *ptr2) << '\n';
	//	self_assign = self_assign; //compiler doesn't like it!
		ft::vector<ft::vector<int> > JOHN;
		ft::vector<ft::vector<int> > BOB(5, test);
		cout << "BOB(5, test(test, 5)) : \n";
		for (size_t i = 0; i < BOB.size(); i++)
		{  
			for (size_t j = 0; j < BOB[i].size(); j++)
				cout << BOB[i][j] << ' ';
			cout << '\n';
		}
		ft::vector<ft::vector<int> > MIKE(BOB);

		// // CTORs
		cout << "\nCTORS\n";
		cout << "Empty is empty ? " << std::boolalpha << JOHN.empty() << '\n';
		cout << "BOB is empty? " << BOB.empty() << '\n';

		cout << "Size of JOHN " << JOHN.size() << std::endl;
		cout << "Size of BOB " << BOB.size() << std::endl;
		cout << "Size of MIKE " << MIKE.size() << std::endl;
        /* This part is OKKKKKK */
        	// RESIZE
		size_t	bob_resize = 2;
		cout << "\nRESIZE\n";
		BOB.resize(bob_resize);
		cout << "Size of JOHN " << JOHN.size() << std::endl;
		if (JOHN.capacity() >= JOHN.size())
			cout << "Capacity of JOHN is sufficient\n";
		else
			std::cerr << "THERE IS A PROBLEM ON LINE 53\n";
		cout << "Size of BOB " << BOB.size() << std::endl;
		if (BOB.capacity() >= bob_resize)
			cout << "Capacity of BOB is sufficient\n";
		else
			std::cerr << "THERE IS A PROBLEM ON LINE 58\n";
		cout << "Size of MIKE " << MIKE.size() << std::endl;
		if (MIKE.capacity() >= MIKE.size())
			cout << "Capacity of MIKE is sufficient\n";
		else
			std::cerr << "THERE IS A PROBLEM ON LINE 63\n";

		size_t	mike_resize = 9;
		bob_resize = 0;
		
		BOB.resize(bob_resize);
		cout << "BOB is empty now ? " << BOB.empty() << '\n';
		MIKE.resize(mike_resize, test);
		cout << "Size of JOHN " << JOHN.size() << std::endl;
		if (JOHN.capacity() >= JOHN.size())
			cout << "Capacity of JOHN is sufficient\n";
		else
			std::cerr << "THERE IS A PROBLEM ON LINE 86\n";
		cout << "Size of BOB " << BOB.size() << std::endl;
		if (BOB.capacity() >= bob_resize)
			cout << "Capacity of BOB is sufficient\n";
		else
			std::cerr << "THERE IS A PROBLEM ON LINE 91\n";
		cout << "Size of MIKE " << MIKE.size() << std::endl;
		if (MIKE.capacity() >= mike_resize)
			cout << "Capacity of MIKE is sufficient\n";
		else
			std::cerr << "THERE IS A PROBLEM ON LINE 96\n";
		for (size_t i = 0; i < MIKE.size(); i++)
		{
			for (size_t j = 0; j < MIKE[i].size(); j++)
			{
				cout << MIKE[i][j] << ' ';
			}
		cout << std::endl;
		}

        // RESERVE
        cout << "\n MYYYY RESERVE ************************\n";

        size_t	john_reserve = 0;
        size_t	bob_reserve = 3;
        size_t	mike_reserve = 4;

        JOHN.reserve(john_reserve);
        BOB.reserve(bob_reserve);
        MIKE.reserve(mike_reserve);
        cout << "Size of JOHN " << JOHN.size() << std::endl;
        if (JOHN.capacity() >= john_reserve)

            cout << "Capacity of JOHN is sufficient\n";
        else
            std::cerr << "THERE IS A PROBLEM ON LINE 120\n";
        cout << "Size of BOB " << BOB.size() << std::endl;
        if (BOB.capacity() >= bob_reserve)
            cout << "Capacity of BOB is sufficient\n";
        else
            std::cerr << "THERE IS A PROBLEM ON LINE 125\n";
        cout << "Size of MIKE " << MIKE.size() << std::endl;
        if (MIKE.capacity() >= mike_reserve)
            cout << "Capacity of MIKE is sufficient\n";
        else
            std::cerr << "THERE IS A PROBLEM ON LINE 130\n";
        for (size_t i = 0; i < MIKE.size(); i++)
        {
            for (size_t j = 0; j < MIKE[i].size(); j++)
                cout << MIKE[i][j] << ' ';
        cout << std::endl;
        }
        //AT
        cout << "\n MYYYYYYY AT\n";
        try
        {
            cout << MIKE.at(2).front() << '\n';
            cout << MIKE.at(87).back() << '\n';
        }
        catch (std::out_of_range& oor)
        {
            (void)oor;
            cout << "OOR error caught\n";
        }
         cout << "\nMy functiiiiiiioooooooons FRONT / BACK\n";
        // FRONT / BACK
        cout << "\nFRONT / BACK\n";
        cout << "front() of MIKE : " << MIKE.front().front() << '\n';
        cout << "back() of MIKE : " << MIKE.back().back() << '\n';

        //ASSIGN
        cout << "\nASSIGN\n";
        test.assign(3, 17);
        BOB.assign(3, test);

        //ASSIGN RANGE
        cout << "\nASSIGN RANGE\n";
        ft::vector<vector<int> >	assign_range;
        assign_range.assign(8, test);
        assign_range.assign(BOB.begin() + 1, BOB.end() - 2);

        //EMPTY
        cout << "\nEMPTY\n";
        cout << "BOB is empty ? " << BOB.empty() << '\n';
        cout << "BOB at(1) : " << BOB.at(1).front() << '\n';

    }
}