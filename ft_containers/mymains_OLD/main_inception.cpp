#include <iostream>
#include <iomanip>
#include "./includes/Stack.hpp"
#include "./includes/vector.hpp"
#include "./includes/ReverseIterator.hpp"

/* For colours in terminal/outputs : https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal*/

using namespace std;

int  main()
{
    std::cout << "\e[1;41m MAZOISE TESTS -- INCEPTION \033[0m\n" << std::endl;
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

    //     	// RESIZE
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
    //      // RESERVE
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


		cout << "\nPUSH/POP_BACK\n";
		test.assign(2, 42);
		BOB.push_back(test);
		cout << "last elem of BOB : " << BOB.back().back() << '\n';
		BOB.pop_back();
		cout << "last elem of BOB : " << BOB.back().back() << '\n';


		//INSERT
		cout << "\nINSERT\n";
		vector<vector<int> >	insert_in_me;
		for (int i = 0; i < 15; i++)
		{
			vector<int>	j(2, i);
			insert_in_me.push_back(j);
		}
		for (size_t i = 0; i < insert_in_me.size(); i++)
		{
			for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
				cout << insert_in_me.at(i).at(j) << ' ';
			cout << '\n';
		}

		// vector<vector<int> >::iterator	tmp;
		// test.assign(23, 19);
		// tmp = insert_in_me.begin() + 4;
		// insert_in_me.insert(tmp, 8, test);
		// for (size_t i = 0; i < insert_in_me.size(); i++)
		// {
		// 	for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
		// 		cout << insert_in_me.at(i).at(j) << ' ';
		// 	cout << '\n';
		// }

		// vector<vector<int> >::const_iterator const_it(insert_in_me.begin());
		// cout << "Const it.front() : " << std::endl;
		// cout << (*const_it).front() << '\n';

	// 		//INSERT
	// 	cout << "\nINSERT\n";
	// 	vector<vector<int> >	std_insert_in_me;
	// 	for (int i = 0; i < 15; i++)
	// 		std_insert_in_me.push_back(test);
	// 	for (size_t i = 0; i < std_insert_in_me.size(); i++)
	// 		cout << std_insert_in_me.at(i).front() << ' ';
	// 	cout << '\n';

	// 	vector<vector<int> >::iterator	std_tmp;
	// 	std_tmp = std_insert_in_me.begin() + 4;
	// 	std_insert_in_me.insert(std_tmp, 8, test);
	// 	for (size_t i = 0; i < std_insert_in_me.size(); i++)
	// 		cout << std_insert_in_me.at(i).back() << ' ';
	// 	cout << '\n';
	// 		//INSERT RANGE
	// 	cout << "\nINSERT RANGE\n";
	// 	vector<vector<int> >	insert_bis;
	// 	for (int i = 0; i < 7; i++)
	// 	{
	// 		vector<int>	j(2, i * 3);
	// 		insert_bis.push_back(j);
	// 	}
	// 	for (size_t i = 0; i < insert_bis.size(); i++)
	// 		cout << insert_bis[i].back() << ' ';
	// 	cout << '\n';

	// 	insert_bis.insert(insert_bis.begin() + 5, insert_in_me.begin(), insert_in_me.end());
	// 	for (size_t i = 0; i < insert_bis.size(); i++)
	// 		cout << insert_bis[i].back() << ' ';
	// 	cout << '\n';

	// 	//ERASE
	// 	cout << "\nERASE\n";
	// 	vector<vector<int> >	erase_in_me;
	// 	for (int i = 0; i < 15; i++)
	// 	{
	// 		vector<int>	j(1, i);
	// 		erase_in_me.push_back(j);
	// 	}
	// 	for (size_t i = 0; i < erase_in_me.size(); i++)
	// 		cout << erase_in_me.at(i).front() << ' ';
	// 	cout << '\n';

	// 	erase_in_me.erase(erase_in_me.begin() + 7);
	// 	for (size_t i = 0; i < erase_in_me.size(); i++)
	// 		cout << erase_in_me.at(i).front() << ' ';
	// 	cout << '\n';
	// 	erase_in_me.erase(erase_in_me.begin() + 2, erase_in_me.begin() + 6);
	// 	for (size_t i = 0; i < erase_in_me.size(); i++)
	// 		cout << erase_in_me.at(i).front() << ' ';
	// 	cout << '\n';

	// 	//SWAP
	// 	cout << "\nSWAP\n";
	// 	john_reserve = 4;
	// 	JOHN.reserve(john_reserve);
	// 	BOB.swap(MIKE);
	// 	cout << "Size of JOHN " << JOHN.size() << std::endl;
	// 	if (JOHN.capacity() >= JOHN.size())
	// 		cout << "Capacity of JOHN is sufficient\n";
	// 	else
	// 		std::cerr << "THERE IS A PROBLEM ON LINE 272\n";
	// 	cout << "Size of BOB " << BOB.size() << std::endl;
	// 	if (BOB.capacity() >= BOB.size())
	// 		cout << "Capacity of BOB is sufficient\n";
	// 	else
	// 		std::cerr << "THERE IS A PROBLEM ON LINE 277\n";
	// 	cout << "Size of MIKE " << MIKE.size() << std::endl;
	// 	if (MIKE.capacity() >= MIKE.size())
	// 		cout << "Capacity of MIKE is sufficient\n";
	// 	else
	// 		std::cerr << "THERE IS A PROBLEM ON LINE 282\n";
	// 	for (size_t i = 0; i < MIKE.size(); i++)
	// 	{
	// 		for (size_t j = 0; j < MIKE[i].size(); j++)
	// 			cout << MIKE[i][j] << ' ';
	// 	cout << std::endl;
	// 	}


	// 	MIKE.swap(JOHN);
	// 	cout << "Size of JOHN " << JOHN.size() << std::endl;
	// 	if (JOHN.capacity() >= JOHN.size())
	// 		cout << "Capacity of JOHN is sufficient\n";
	// 	else
	// 		std::cerr << "THERE IS A PROBLEM ON LINE 298\n";
	// 	cout << "Size of BOB " << BOB.size() << std::endl;
	// 	if (BOB.capacity() >= BOB.size())
	// 		cout << "Capacity of BOB is sufficient\n";
	// 	else
	// 		std::cerr << "THERE IS A PROBLEM ON LINE 303\n";
	// 	cout << "Size of MIKE " << MIKE.size() << std::endl;
	// 	if (MIKE.capacity() >= MIKE.size())
	// 		cout << "Capacity of MIKE is sufficient\n";
	// 	else
	// 		std::cerr << "THERE IS A PROBLEM ON LINE 308\n";
	// 	for (size_t i = 0; i < MIKE.size(); i++)
	// 	{
	// 		for (size_t j = 0; j < MIKE[i].size(); j++)
	// 			cout << MIKE[i][j] << ' ';
	// 	cout << std::endl;
	// 	}

	// 	//CLEAR
	// 	cout << "\nCLEAR\n";
	// 	JOHN.clear();
	// 	MIKE.clear();
	// 	cout << "Size of JOHN " << JOHN.size() << std::endl;
	// 	if (JOHN.capacity() >= JOHN.size())
	// 		cout << "Capacity of JOHN is sufficient\n";
	// 	else
	// 		std::cerr << "THERE IS A PROBLEM ON LINE 327\n";
	// 	cout << "Size of BOB " << BOB.size() << std::endl;
	// 	if (BOB.capacity() >= BOB.size())
	// 		cout << "Capacity of BOB is sufficient\n";
	// 	else
	// 		std::cerr << "THERE IS A PROBLEM ON LINE 332\n";
	// 	cout << "Size of MIKE " << MIKE.size() << std::endl;
	// 	if (MIKE.capacity() >= MIKE.size())
	// 		cout << "Capacity of MIKE is sufficient\n";
	// 	else
	// 		std::cerr << "THERE IS A PROBLEM ON LINE 337\n";
	// 	for (size_t i = 0; i < MIKE.size(); i++)
	// 	{
	// 		for (size_t j = 0; j < MIKE[i].size(); j++)
	// 			cout << MIKE[i][j] << ' ';
	// 	cout << std::endl;
	// 	}

	// //NON MEMBER Functions
	// 	cout << "\nNON MEMBER functions\n";
	// 	swap(BOB, MIKE);
	// 	cout << "Size of JOHN " << JOHN.size() << std::endl;
	// 	if (JOHN.capacity() >= JOHN.size())
	// 		cout << "Capacity of JOHN is sufficient\n";
	// 	else
	// 		std::cerr << "THERE IS A PROBLEM ON LINE 355\n";
	// 	cout << "Size of BOB " << BOB.size() << std::endl;
	// 	if (BOB.capacity() >= BOB.size())
	// 		cout << "Capacity of BOB is sufficient\n";
	// 	else
	// 		std::cerr << "THERE IS A PROBLEM ON LINE 360\n";
	// 	cout << "Size of MIKE " << MIKE.size() << std::endl;
	// 	if (MIKE.capacity() >= MIKE.size())
	// 		cout << "Capacity of MIKE is sufficient\n";
	// 	else
	// 		std::cerr << "THERE IS A PROBLEM ON LINE 365\n";
	// 	for (size_t i = 0; i < MIKE.size(); i++)
	// 	{
	// 		for (size_t j = 0; j < MIKE[i].size(); j++)
	// 			cout << MIKE[i][j] << ' ';
	// 	cout << std::endl;
	// 	}

	// 	cout << "\nRELATIONAL OPERATORS\n";
	// 	vector<vector<int> > MIKE_2(MIKE);
	// 	cout << "MIKE and BOB are equal ? " << (MIKE == BOB) << '\n';
	// 	cout << "MIKE and MIKE_2 are equal ? " << (MIKE == MIKE_2) << '\n';

	// 	cout << "\nReal Vector\n";
	// 	vector<vector<int> > real;
	// 	real.assign(5, test);
	// 	for (vector<vector<int> >::iterator it = real.begin(); it != real.end(); it++)
	// 		cout << (*it).front() << " ";
	// 	cout << '\n';

	// 	cout << std::endl;

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

        // // RESERVE
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
		ft::vector<ft::vector<int> >	assign_range;
		assign_range.assign(8, test);
		assign_range.assign(BOB.begin() + 1, BOB.end() - 2);

		//EMPTY
		cout << "\nEMPTY\n";
		cout << "BOB is empty ? " << BOB.empty() << '\n';
		cout << "BOB at(1) : " << BOB.at(1).front() << '\n';
		/* OKKKKKKKKKK jusque la */

		//PUSH/POP_BACK
		cout << "\nPUSH/POP_BACK\n";
		test.assign(2, 42);
		BOB.push_back(test);
		cout << "last elem of BOB : " << BOB.back().back() << '\n';
		BOB.pop_back();
		cout << "last elem of BOB : " << BOB.back().back() << '\n';

		//INSERT
		cout << "\nINSERT\n";
		ft::vector<ft::vector<int> >	insert_in_me;
		for (int i = 0; i < 15; i++)
		{
			ft::vector<int>	j(2, i);
			insert_in_me.push_back(j);
		}
		for (size_t i = 0; i < insert_in_me.size(); i++)
		{
			for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
				cout << insert_in_me.at(i).at(j) << ' ';
			cout << '\n';
		}

		ft::vector<ft::vector<int> >::iterator	tmp;
		test.assign(23, 19);
		tmp = insert_in_me.begin() + 4;
		insert_in_me.insert(tmp, 8, test);
		for (size_t i = 0; i < insert_in_me.size(); i++)
		{
			for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
				cout << insert_in_me.at(i).at(j) << ' ';
			cout << '\n';
		}

		ft::vector<ft::vector<int> >::const_iterator const_it(insert_in_me.begin());
		cout << "Const it.front() : " << std::endl;
		cout << (*const_it).front() << '\n';

		// //INSERT
		cout << "\nINSERT\n";
		ft::vector< ft::vector<int> >	std_insert_in_me;
		for (int i = 0; i < 15; i++)
		{
			std_insert_in_me.push_back(test);
			// std::cout << std_insert_in_me[i][i] << std::endl;
		}
		for (size_t i = 0; i < std_insert_in_me.size(); i++)
			cout << std_insert_in_me.at(i).front() << ' ';
		cout << '\n';

		ft::vector<ft::vector<int> >::iterator	std_tmp;
		std_tmp = std_insert_in_me.begin() + 4;
		std_insert_in_me.insert(std_tmp, 8, test);
		for (size_t i = 0; i < std_insert_in_me.size(); i++)
			cout << std_insert_in_me.at(i).back() << ' ';
		cout << '\n';

		// 	//INSERT RANGE
		cout << "\nINSERT RANGE\n";
		ft::vector<ft::vector<int> >	insert_bis;
		for (int i = 0; i < 7; i++)
		{
			ft::vector<int>	j(2, i * 3);
			insert_bis.push_back(j);
		}
		for (size_t i = 0; i < insert_bis.size(); i++)
			cout << insert_bis[i].back() << ' ';
		cout << '\n';

		insert_bis.insert(insert_bis.begin() + 5, insert_in_me.begin(), insert_in_me.end());
		for (size_t i = 0; i < insert_bis.size(); i++)
			cout << insert_bis[i].back() << ' ';
		cout << '\n';


		// //ERASE
		cout << "\nERASE\n";
		ft::vector<ft::vector<int> >	erase_in_me;
		for (int i = 0; i < 15; i++)
		{
			ft::vector<int>	j(1, i);
			erase_in_me.push_back(j);
		}
		for (size_t i = 0; i < erase_in_me.size(); i++)
			cout << erase_in_me.at(i).front() << ' ';
		cout << '\n';

		erase_in_me.erase(erase_in_me.begin() + 7);
		for (size_t i = 0; i < erase_in_me.size(); i++)
			cout << erase_in_me.at(i).front() << ' ';
		cout << '\n';
		std::cout << "ici ?????? " << std::endl;
		erase_in_me.erase(erase_in_me.begin() + 2, erase_in_me.begin() + 6);
		std::cout << erase_in_me.size() << std::endl;
		for (size_t i = 0; i < erase_in_me.size(); i++)
		{
			cout << erase_in_me.at(i).front() << ' ';
		}
		cout << '\n';


		// //SWAP
		cout << "\nSWAP\n";
		john_reserve = 4;
		JOHN.reserve(john_reserve);
		BOB.swap(MIKE);
		cout << "Size of JOHN " << JOHN.size() << std::endl;
		if (JOHN.capacity() >= JOHN.size())
			cout << "Capacity of JOHN is sufficient\n";
		else
			std::cerr << "THERE IS A PROBLEM ON LINE 272\n";
		cout << "Size of BOB " << BOB.size() << std::endl;
		if (BOB.capacity() >= BOB.size())
			cout << "Capacity of BOB is sufficient\n";
		else
			std::cerr << "THERE IS A PROBLEM ON LINE 277\n";
		cout << "Size of MIKE " << MIKE.size() << std::endl;
		if (MIKE.capacity() >= MIKE.size())
			cout << "Capacity of MIKE is sufficient\n";
		else
			std::cerr << "THERE IS A PROBLEM ON LINE 282\n";
		for (size_t i = 0; i < MIKE.size(); i++)
		{
			for (size_t j = 0; j < MIKE[i].size(); j++)
				cout << MIKE[i][j] << ' ';
		cout << std::endl;
		}


		MIKE.swap(JOHN);
		cout << "Size of JOHN " << JOHN.size() << std::endl;
		if (JOHN.capacity() >= JOHN.size())
			cout << "Capacity of JOHN is sufficient\n";
		else
			std::cerr << "THERE IS A PROBLEM ON LINE 298\n";
		cout << "Size of BOB " << BOB.size() << std::endl;
		if (BOB.capacity() >= BOB.size())
			cout << "Capacity of BOB is sufficient\n";
		else
			std::cerr << "THERE IS A PROBLEM ON LINE 303\n";
		cout << "Size of MIKE " << MIKE.size() << std::endl;
		if (MIKE.capacity() >= MIKE.size())
			cout << "Capacity of MIKE is sufficient\n";
		else
			std::cerr << "THERE IS A PROBLEM ON LINE 308\n";
		for (size_t i = 0; i < MIKE.size(); i++)
		{
			for (size_t j = 0; j < MIKE[i].size(); j++)
				cout << MIKE[i][j] << ' ';
		cout << std::endl;
		}


		// //CLEAR
		cout << "\nCLEAR\n";
		JOHN.clear();
		MIKE.clear();
		cout << "Size of JOHN " << JOHN.size() << std::endl;
		if (JOHN.capacity() >= JOHN.size())
			cout << "Capacity of JOHN is sufficient\n";
		else
			std::cerr << "THERE IS A PROBLEM ON LINE 327\n";
		cout << "Size of BOB " << BOB.size() << std::endl;
		if (BOB.capacity() >= BOB.size())
			cout << "Capacity of BOB is sufficient\n";
		else
			std::cerr << "THERE IS A PROBLEM ON LINE 332\n";
		cout << "Size of MIKE " << MIKE.size() << std::endl;
		if (MIKE.capacity() >= MIKE.size())
			cout << "Capacity of MIKE is sufficient\n";
		else
			std::cerr << "THERE IS A PROBLEM ON LINE 337\n";
		for (size_t i = 0; i < MIKE.size(); i++)
		{
			for (size_t j = 0; j < MIKE[i].size(); j++)
				cout << MIKE[i][j] << ' ';
		cout << std::endl;
		}

		// 	//NON MEMBER Functions
		cout << "\nNON MEMBER functions\n";
		swap(BOB, MIKE);
		cout << "Size of JOHN " << JOHN.size() << std::endl;
		if (JOHN.capacity() >= JOHN.size())
			cout << "Capacity of JOHN is sufficient\n";
		else
			std::cerr << "THERE IS A PROBLEM ON LINE 355\n";
		cout << "Size of BOB " << BOB.size() << std::endl;
		if (BOB.capacity() >= BOB.size())
			cout << "Capacity of BOB is sufficient\n";
		else
			std::cerr << "THERE IS A PROBLEM ON LINE 360\n";
		cout << "Size of MIKE " << MIKE.size() << std::endl;
		if (MIKE.capacity() >= MIKE.size())
			cout << "Capacity of MIKE is sufficient\n";
		else
			std::cerr << "THERE IS A PROBLEM ON LINE 365\n";
		for (size_t i = 0; i < MIKE.size(); i++)
		{
			for (size_t j = 0; j < MIKE[i].size(); j++)
				cout << MIKE[i][j] << ' ';
		cout << std::endl;
		}
		cout << "\nRELATIONAL OPERATORS\n";

		ft::vector<ft::vector<int> > MIKE_2(MIKE);
		cout << "MIKE and BOB are equal ? " << (MIKE == BOB) << '\n';
		cout << "MIKE and MIKE_2 are equal ? " << (MIKE == MIKE_2) << '\n';

		cout << "\nReal ft::Vector Hiiiiho\n";
		ft::vector<ft::vector<int> > real;
		real.assign(5, test);
		for (ft::vector<ft::vector<int> >::iterator it = real.begin(); it != real.end(); it++)
			cout << (*it).front() << " ";
		cout << '\n';

		cout << std::endl;
    }
}