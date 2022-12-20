#include <iostream>
#include <iomanip>
#include "./includes/Stack.hpp"
#include "./includes/myVector.hpp"
#include "./includes/ReverseIterator.hpp"

/* For colours in terminal/outputs : https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal*/

int main()
{
	/* ************************************************* */
	/*          		Vectors: 		        		*/
	/* *************************************************/	

	std::cout << "\e[1;41m Testing constructors\033[0m\n" << std::endl;
	{
		{
			ft::vector<int> myvec;
			std::cout << "\e[0;35mDefault constructor for int\e[0m" << std::endl;
			std::cout << "Adresse : " << &myvec << std::endl;
			std::cout << "Size : " << myvec.size() << std::endl;
			std::cout << std::endl;
		}
		{
			ft::vector<char> myvec;
			std::cout << "\e[0;35mDefault constructor for char\e[0m" << std::endl;
			std::cout << "Adresse : " << &myvec << std::endl;
			std::cout << "Size : " << myvec.size() << std::endl;
			std::cout << std::endl;
		}		
		{
			ft::vector<std::string> myvec;
			std::cout << "\e[0;35mDefault constructor for string\e[0m" << std::endl;
			std::cout << "Adresse : " << &myvec << std::endl;
			std::cout << "Size : " << myvec.size() << std::endl;
			std::cout << std::endl;
		}
		/*Resultat attendu : une adresse doit etre imprimee*/
		/*Size = 0*/
	}
	{
		{
			std::cout << "\e[0;35mParametric constructor <int>\e[0m" << std::endl;
			ft::vector<int> myvec(10, 100);
			std::cout << "Adresse : " <<&myvec << std::endl;
			std::cout << "Size : " << myvec.size() << std::endl;
			std::cout << std::endl;
			/*Resultat attendu : une adresse doit etre imprimee*/
			/*Size = 10*/
		}
		{
			ft::vector<char> myvec(10, 'c');
			std::cout << "\e[0;35mParametric constructor <char>\e[0m" << std::endl;
			std::cout << "Adresse : " << &myvec << std::endl;
			std::cout << "Size : " << myvec.size() << std::endl;
			std::cout << std::endl;
			/*Resultat attendu : une adresse doit etre imprimee*/
			/*Size = 10*/
		}
		{
			ft::vector<std::string> myvec(10, "salut");
			std::cout << "\e[0;35mParametric constructor <std::string>\e[0m" << std::endl;
			std::cout << "Adresse : " <<&myvec << std::endl;
			std::cout << "Size : " << myvec.size() << std::endl;
			std::cout << std::endl;
			/*Resultat attendu : une adresse doit etre imprimee*/
			/*Size = 10*/
		}

	}
	{
		/* RESTE A FAIRE - depend des iterateurs */
		// int array[] = {2, 5, 6, 90};
		ft::vector<int> myvector;
		myvector.push_back(56);
		myvector.push_back(85);
		myvector.push_back(36);
		myvector.push_back(97);
		ft::vector<int>::iterator first = myvector.begin();
		ft::vector<int>::iterator last = myvector.end();
		// ft::vector<int> myvec(array, array+4);
		ft::vector<int> copie(first, last);
		// std::cout << "\e[0;35mRange constructor\e[0m" << std::endl;
		// // std::cout << "Adresse : " <<&myvec << std::endl;
		// // std::cout << "Size : " << myvec.size() << std::endl;
		std::cout << "Adresse : " << &copie << std::endl;
		std::cout << "Size : " << copie.size() << std::endl;
		for (;first != last;)
		{
			std::cout << *first << std::endl;
			first++;
		}
		std::cout << std::endl;

		/*Resultat attendu : une adresse doit etre imprimee*/
		/*Size = 10*/
	}
	{
		/* RESTE A FAIRE - Copy constructor - depend de Assign*/
		ft::vector<int> myvec;
		myvec.push_back(56);
		myvec.push_back(85);
		myvec.push_back(36);
		myvec.push_back(97);
		std::cout << "\e[0;35mCopy constructor\e[0m" << std::endl;
		ft::vector<int>test(myvec);
		// std::cout << "Adresse : " << &test << std::endl;
		std::cout << "Size : " << test.size() << std::endl;
		// std::cout << std::endl;

		/*Resultat attendu : une adresse doit etre imprimee*/
		/*Size = 10*/
	}
	// std::cout << "\e[1;41m Testing Iterators\033[0m\n" << std::endl;
	// {
	// 	// {
	// 	// 	ft::vector<int> myvec(5, 150);
	// 	// 	std::cout << "\e[0;34mBegin constructor\e[0m" << std::endl;
	// 	// 	std::cout << "Adresse : " <<&myvec << std::endl;
	// 	// 	std::cout << "Derefeencing Begin() : " << *myvec.begin() << std::endl;
	// 	// 	std::cout << std::endl;

	// 	// 	/* Resultat attendu : une adresse doit etre imprimee */
	// 	// 	/* Deferencement de begin  = 150 */
	// 	// }
	// }
	// 	{
	// 		ft::vector<char> myvec(5, 'k');
	// 		std::cout << "\e[0;34mBegin constructor <char>\e[0m" << std::endl;
	// 		std::cout << "Adresse : " <<&myvec << std::endl;
	// 		std::cout << "Derefeencing Begin() : " << *myvec.begin() << std::endl;
	// 		std::cout << std::endl;

	// 		/* Resultat attendu : une adresse doit etre imprimee */
	// 		/* Deferencement de begin  = k */
	// 	}
	// 	{
	// 		ft::vector<std::string> myvec(5, "kikou");
	// 		std::cout << "\e[0;34mBegin constructor <string>\e[0m" << std::endl;
	// 		std::cout << "Adresse : " <<&myvec << std::endl;
	// 		std::cout << "Derefeencing Begin() : " << *myvec.begin() << std::endl;
	// 		std::cout << std::endl;

	// 		/* Resultat attendu : une adresse doit etre imprimee */
	// 		/* Deferencement de begin  = kikou */
	// 	}
	// }
	// {
	// 	ft::vector<int> myvec(5, 130);
	// 	std::cout << "\e[0;34mEnd iterator\e[0m" << std::endl;
	// 	std::cout << "Adresse : " <<&myvec << std::endl;
	// 	std::cout << "Dereferencing END() : " << *myvec.end() << std::endl;
	// 	std::cout << std::endl;

	// 	/*Resultat attendu : rien car end pointe sur l'adresse apres le tableau */
	// }
	// {
	// 	ft::vector<int> myvec(5, 130);
	// 	ft::vector<int>::iterator it(myvec.begin());
	// 	std::cout << "\e[0;34m IT \e[0m" << std::endl;
	// 	// std::cout << "Adresse : " << it << std::endl;
	// 	std::cout << "Dereferencing IT : " << *it << std::endl;
	// 	std::cout << std::endl;

	// 	/*Resultat attendu : rien car end pointe sur l'adresse apres le tableau */
	// }
	// std::cout << "\e[1;41m Testing Capacity\033[0m\n" << std::endl;
	// {
	// 	{
	// 		ft::vector<int> myvec(5, 130);
	// 		ft::vector<int> myvec2(0, 130);
	// 		std::cout << "\e[0;34mSize() >>>> \e[0m" << std::endl;
	// 		// std::cout << "Adresse : " << it << std::endl;
	// 		std::cout << "size of myvec: " << myvec.size() << std::endl;
	// 		std::cout << std::endl;
	// 		std::cout << "size of myvec2: " << myvec2.size() << std::endl;
	// 		std::cout << std::endl;
	// 	}
	// 	{
	// 		ft::vector<int> myvec(5, 130);
	// 		std::vector<int> myvec2(5, 130);
	// 		// ft::vector<int> myvec2(0, 130);
	// 		std::cout << "\e[0;34mMax_Size() >>>> \e[0m" << std::endl;
	// 		// std::cout << "Adresse : " << it << std::endl;
	// 		std::cout << "MAx size of myvec: " << myvec.max_size() << std::endl;
	// 		std::cout << "MAx size of myvec: " << myvec2.max_size() << std::endl;
	// 		std::cout << std::endl;
	// 	}
	// 	{
	// 		ft::vector<int> myvec(5, 130);
	// 		std::vector<int> myvec2(5, 130);
	// 		std::vector<int> myvec3(0, 130);
	// 		ft::vector<int> myvec4(0, 130);
	// 		// ft::vector<int> myvec2(0, 130);
	// 		std::cout << "\e[0;34mEmpty() >>>> \e[0m" << std::endl;
	// 		// std::cout << "Adresse : " << it << std::endl;
	// 		std::cout << "Empty: " << myvec.empty() << std::endl;
	// 		std::cout << "Real Empty: " << myvec2.empty() << std::endl;
	// 		std::cout << std::endl;
	// 		std::cout << "Empty: " << myvec4.empty() << std::endl;
	// 		std::cout << "Real Empty: " << myvec3.empty() << std::endl;
	// 		std::cout << std::endl;
	// 	}
	// 	{
	// 		ft::vector<size_t> myvec(5, 130);
	// 		std::vector<size_t> vec2(5, 130);
	// 		std::cout << "\e[0;34mResize() >>>> \e[0m" << std::endl;
	// 		std::cout << std::endl;
	// 		{
	// 			std::cout << "\e[0;46mCase 1 : n < curr ...\e[0m"  << std::endl;
	// 			std::cout << std::endl;
	// 			std::cout << "\e[0;33m$$$$$$ MY VECTOR $$$$$ \e[0m" << std::endl;
	// 			std::cout << "My Size: " << myvec.size() << std::endl;
	// 			std::cout << "My Capacity: " << myvec.capacity() << std::endl;
	// 			std::cout << "Resizing ... " << std::endl;
	// 			myvec.resize(3, 20);
	// 			std::cout << "My Size: " << myvec.size() << std::endl;
	// 			std::cout << "My Capacity: " << myvec.capacity() << std::endl;

	// 			std::cout << std::endl;

	// 			std::cout << "\e[0;32m~~~~ REAL VECTOR ~~~~~ \e[0m" << std::endl;
	// 			std::cout << "Size: " << vec2.size() << std::endl;
	// 			std::cout << "Capacity: " << vec2.capacity() << std::endl;
	// 			std::cout << "Resizing ... " << std::endl;
	// 			vec2.resize(3, 20);
	// 			std::cout << "Size: " << vec2.size() << std::endl;
	// 			std::cout << "Capacity: " << vec2.capacity() << std::endl;
	// 			std::cout << std::endl;
	// 		}
	// 		{
	// 			std::cout << "\e[0;46mCase 2 : n > curr ...\e[0m"  << std::endl;
	// 			std::cout << std::endl;
	// 			std::cout << "\e[0;33m$$$$$$ MY VECTOR $$$$$ \e[0m" << std::endl;
	// 			std::cout << "My Size: " << myvec.size() << std::endl;
	// 			std::cout << "My Capacity: " << myvec.capacity() << std::endl;
	// 			std::cout << "Resizing ... " << std::endl;
	// 			myvec.resize(8, 1200);
	// 			std::cout << "My Size: " << myvec.size() << std::endl;
	// 			std::cout << "My Capacity: " << myvec.capacity() << std::endl;
	// 			std::cout << "Traversing the tab ... " << std::endl;
	// 			ft::vector<size_t>::iterator start1 = myvec.begin();
	// 			for(; start1 != myvec.end(); start1++)
	// 				std::cout << *start1 << " ; ";
	// 			std::cout << std::endl;
	// 			std::cout << std::endl;
	// 			std::cout << "\e[0;32m~~~~ REAL VECTOR ~~~~~ \e[0m" << std::endl;
	// 			std::cout << "Size: " << vec2.size() << std::endl;
	// 			std::cout << "Capacity: " << vec2.capacity() << std::endl;
	// 			std::cout << "Resizing ... " << std::endl;
	// 			vec2.resize(8, 1200);
	// 			std::cout << "Size: " << vec2.size() << std::endl;
	// 			std::cout << "Capacity: " << vec2.capacity() << std::endl;
	// 			std::cout << "Traversing the tab ... " << std::endl;
	// 			std::vector<size_t>::iterator start = vec2.begin();
	// 			for(; start != vec2.end(); start++)
	// 				std::cout << *start << " ; ";
	// 			std::cout << std::endl;

	// 		}
	// 		{
	// 			try{
	// 				std::cout << std::endl;
	// 				std::cout << "\e[0;46mCase 3 : n > curr && n > max_size ...\e[0m"  << std::endl;
	// 				std::cout << std::endl;
	// 				std::cout << std::endl;
	// 				std::cout << "\e[0;33m$$$$$$ MY VECTOR $$$$$ \e[0m" << std::endl;
	// 				std::cout << "My Size: " << myvec.size() << std::endl;
	// 				std::cout << "My Capacity: " << myvec.capacity() << std::endl;
	// 				std::cout << "Resizing ... " << std::endl;
	// 				myvec.resize(2305843009213693955, 1200);
	// 				std::cout << "My Size: " << myvec.size() << std::endl;
	// 				std::cout << "My Capacity: " << myvec.capacity() << std::endl;
	// 				std::cout << "Traversing the tab ... " << std::endl;
	// 				ft::vector<size_t>::iterator start1 = myvec.begin();
	// 				for(; start1 != myvec.end(); start1++)
	// 					std::cout << *start1 << " ; ";
	// 				std::cout << std::endl;
	// 				std::cout << std::endl;
	// 				std::cout << "\e[0;32m~~~~ REAL VECTOR ~~~~~ \e[0m" << std::endl;
	// 				std::cout << "Size: " << vec2.size() << std::endl;
	// 				std::cout << "Capacity: " << vec2.capacity() << std::endl;
	// 				std::cout << "Resizing ... " << std::endl;
	// 				vec2.resize(2305843009213693956, 1200);
	// 				std::cout << "Size: " << vec2.size() << std::endl;
	// 				std::cout << "Capacity: " << vec2.capacity() << std::endl;
	// 				std::cout << "Traversing the tab ... " << std::endl;
	// 				std::vector<size_t>::iterator start = vec2.begin();
	// 				for(; start != vec2.end(); start++)
	// 					std::cout << *start << " ; ";
	// 			}
	// 			catch(const std::exception& e)
	// 			{
	// 				std::cout << e.what() << std::endl;
	// 			}
	// 		}
	// 		{
	// 			try{
	// 				std::cout << std::endl;
	// 				std::cout << "\e[0;46mCase 4 : n > curr && n > Capacity : testing also reserve ...\e[0m"  << std::endl;
	// 				std::cout << std::endl;
	// 				std::cout << std::endl;
	// 				std::cout << "\e[0;33m$$$$$$ MY VECTOR $$$$$ \e[0m" << std::endl;
	// 				std::cout << "My Size: " << myvec.size() << std::endl;
	// 				std::cout << "My Capacity: " << myvec.capacity() << std::endl;
	// 				std::cout << "Resizing ... " << std::endl;
	// 				myvec.resize(14, 1200);
	// 				std::cout << "My Size: " << myvec.size() << std::endl;
	// 				std::cout << "My Capacity: " << myvec.capacity() << std::endl;
	// 				std::cout << "Traversing the tab ... " << std::endl;
	// 				ft::vector<size_t>::iterator start1 = myvec.begin();
	// 				for(; start1 != myvec.end(); start1++)
	// 					std::cout << *start1 << " ; ";
	// 				std::cout << std::endl;
	// 				std::cout << std::endl;
	// 				std::cout << "\e[0;32m~~~~ REAL VECTOR ~~~~~ \e[0m" << std::endl;
	// 				std::cout << "Size: " << vec2.size() << std::endl;
	// 				std::cout << "Capacity: " << vec2.capacity() << std::endl;
	// 				std::cout << "Resizing ... " << std::endl;
	// 				vec2.resize(14, 1200);
	// 				std::cout << "Size: " << vec2.size() << std::endl;
	// 				std::cout << "Capacity: " << vec2.capacity() << std::endl;
	// 				std::cout << "Traversing the tab ... " << std::endl;
	// 				std::vector<size_t>::iterator start = vec2.begin();
	// 				for(; start != vec2.end(); start++)
	// 					std::cout << *start << " ; ";
	// 			}
	// 			catch(const std::exception& e)
	// 			{
	// 				std::cout << e.what() << std::endl;
	// 			}
	// 		}
	// 		std::cout << std::endl;
	// 		std::cout << std::endl;
	// 		std::cout << "\e[1;41m Modifiers\033[0m\n" << std::endl;
	// 		{
	// 			ft::vector<size_t> myvec(5, 130);
	// 			std::vector<size_t> vec2(5, 130);
	// 			{
	// 			std::cout << "\e[0;34mINSERT() >>>> \e[0m" << std::endl;
	// 				try
	// 				{
	// 					{
	// 						std::cout << std::endl;
	// 						std::cout << "\e[0;46mProtoype 2\e[0m"  << std::endl;
	// 						std::cout << std::endl;
	// 						std::cout << std::endl;
	// 						std::cout << "\e[0;33m$$$$$$ MY VECTOR $$$$$ \e[0m" << std::endl;
	// 						std::cout << "My Size: " << myvec.size() << std::endl;
	// 						std::cout << "My Capacity: " << myvec.capacity() << std::endl;
	// 						std::cout << "Inserting ... " << std::endl;
	// 						ft::vector<size_t>::iterator it = myvec.begin();
	// 						myvec.insert(it+2, 4, 15);
	// 						std::cout << "My Size: " << myvec.size() << std::endl;
	// 						std::cout << "My Capacity: " << myvec.capacity() << std::endl;
	// 						std::cout << "Traversing the tab ... " << std::endl;
	// 						ft::vector<size_t>::iterator start1 = myvec.begin();
	// 						for(; start1 != myvec.end(); start1++)
	// 							std::cout << *start1 << " ; ";
	// 						std::cout << std::endl;
	// 						ft::vector<size_t>::iterator start3 = myvec.begin();
	// 						myvec.insert(start3+5, 2, 12);
	// 						ft::vector<size_t>::iterator start4 = myvec.begin();
	// 						for(; start4 != myvec.end(); start4++)
	// 							std::cout << *start4 << " ; ";
	// 						std::cout << std::endl;
	// 						std::cout << std::endl;


	// 						std::cout << "\e[0;32m~~~~ REAL VECTOR ~~~~~ \e[0m" << std::endl;
	// 						std::cout << "Size: " << vec2.size() << std::endl;
	// 						std::cout << "Capacity: " << vec2.capacity() << std::endl;
	// 						std::cout << "Inserting ... " << std::endl;
	// 						std::vector<size_t>::iterator ittt = vec2.begin();
	// 						vec2.insert(ittt+2, 4, 15);
	// 						std::cout << "My Size: " << vec2.size() << std::endl;
	// 						std::cout << "My Capacity: " << vec2.capacity() << std::endl;
	// 						std::cout << "Traversing the tab ... " << std::endl;
	// 						std::vector<size_t>::iterator itt1 = vec2.begin();
	// 						for(; itt1 != vec2.end(); itt1++)
	// 							std::cout << *itt1 << " ; ";
	// 						std::cout << std::endl;
	// 						std::vector<size_t>::iterator itt2 = vec2.begin();
	// 						vec2.insert(itt2+5, 2, 12);
	// 						std::vector<size_t>::iterator itt3 = vec2.begin();
	// 						for(; itt3 != vec2.end(); itt3++)
	// 							std::cout << *itt3 << " ; ";
	// 						std::cout << std::endl;
	// 						std::cout << std::endl;
	// 					}
	// 					{
	// 						// std::cout << std::endl;
	// 						// std::cout << "\e[0;46mProtoype 3\e[0m"  << std::endl;
	// 						// std::cout << std::endl;
	// 						// std::cout << std::endl;
	// 						// std::cout << "\e[0;33m$$$$$$ MY VECTOR $$$$$ \e[0m" << std::endl;
	// 						// std::cout << "My Size: " << myvec.size() << std::endl;
	// 						// std::cout << "My Capacity: " << myvec.capacity() << std::endl;
	// 						// size_t myarray[] = {5, 6, 8};
	// 						// ft::vector<size_t>::iterator it = myvec.begin();
	// 						// ft::vector<size_t>::iterator first = myarray;
	// 						// myvec.insert(it+2, first, first+3);
	// 						// std::cout << "Inserting ... " << std::endl;
	// 						// ft::vector<size_t>::iterator toto = myvec.begin();
	// 						// for(; toto != myvec.end(); toto++)
	// 						// 	std::cout << *toto << " ; ";
	// 						// std::cout << std::endl;
	// 						// std::cout << std::endl;
	// 						{
	// 							std::cout << "\e[0;33m$$$$$$ Exemple cpp : Vrai vector $$$$$ \e[0m" << std::endl;
	// 							std::vector<int> myvector (3,100);
	// 							std::vector<int>::iterator it;

	// 							it = myvector.begin();
	// 							it = myvector.insert ( it , 200 );

	// 							myvector.insert (it,2,300);

	// 							// "it" no longer valid, get a new one:
	// 							it = myvector.begin();

	// 							std::vector<int> anothervector (2,400);
	// 							myvector.insert (it+2,anothervector.begin(),anothervector.end());

	// 							int myarray [] = { 501,502,503 };
	// 							myvector.insert (myvector.begin(), myarray, myarray+3);

	// 							std::cout << "REal vector contains:";
	// 							for (it=myvector.begin(); it<myvector.end(); it++)
	// 								std::cout << ' ' << *it;
	// 							std::cout << '\n';
	// 						}
	// 						std::cout << std::endl;
	// 						{
	// 							std::cout << "\e[0;33m$$$$$$ Exemple cpp : Mon vector $$$$$ \e[0m" << std::endl;
	// 							ft::vector<int> myvector (3,100);
	// 							ft::vector<int>::iterator it;

	// 							it = myvector.begin();
	// 							it = myvector.insert ( it , 200 );

	// 							myvector.insert (it,2,300);

	// 							// "it" no longer valid, get a new one:
	// 							it = myvector.begin();

	// 							ft::vector<int> anothervector (2,400);
	// 							myvector.insert (it+2,anothervector.begin(),anothervector.end());

	// 							int myarray [] = { 501,502,503 };
	// 							myvector.insert (myvector.begin(), myarray, myarray+3);

	// 							std::cout << "myvector contains:";
	// 							for (it=myvector.begin(); it<myvector.end(); it++)
	// 								std::cout << ' ' << *it;
	// 							std::cout << '\n';
	// 						}
	// 					}
	// 				}
	// 				catch(const std::exception& e)
	// 				{
	// 					std::cout << e.what() << std::endl;
	// 				}
	// 			}
	// 			std::cout << std::endl;
	// 			std::cout << "\e[0;34mPUSH_BACK() >>>> \e[0m" << std::endl;
	// 			{
	// 				{
	// 					std::cout << std::endl;
	// 					std::cout << "\e[0;33m$$$$$$ MY VECTOR $$$$$ \e[0m" << std::endl;
	// 					myvec.push_back(100);
	// 					myvec.push_back(20);
	// 					myvec.push_back(600);
	// 					myvec.push_back(1540);
	// 					myvec.push_back(99);
	// 					ft::vector<size_t>::iterator iter = myvec.begin();
	// 					for(; iter != myvec.end(); iter++)
	// 							std::cout << *iter << " ; ";
	// 				}
	// 				std::cout << std::endl;
	// 				{
	// 					std::cout << "\e[0;33m$$$$$$ REAL VECTOR $$$$$ \e[0m" << std::endl;
	// 					vec2.push_back(100);
	// 					vec2.push_back(20);
	// 					vec2.push_back(600);
	// 					vec2.push_back(1540);
	// 					vec2.push_back(99);
	// 					std::vector<size_t>::iterator iter = vec2.begin();
	// 					for(; iter != vec2.end(); iter++)
	// 							std::cout << *iter << " ; ";
	// 				}
	// 			}
	// 			std::cout << std::endl;
	// 			std::cout << std::endl;
	// 			std::cout << "\e[0;34mAssign() >>>> \e[0m" << std::endl;
	// 			{
	// 				// {
	// 				// 	std::cout << std::endl;
	// 				// 	std::cout << "\e[0;33m$$$$$$ MY VECTOR $$$$$ \e[0m" << std::endl;
	// 				// 	myvec.push_back(100);
	// 				// 	myvec.push_back(20);
	// 				// 	myvec.push_back(600);
	// 				// 	myvec.push_back(1540);
	// 				// 	myvec.push_back(99);
	// 				// 	ft::vector<size_t>::iterator iter = myvec.begin();
	// 				// 	for(; iter != myvec.end(); iter++)
	// 				// 			std::cout << *iter << " ; ";
	// 				// }
	// 				std::cout << std::endl;
	// 				{
	// 					std::cout << "\e[0;33m$$$$$$ REAL VECTOR $$$$$ \e[0m" << std::endl;
	// 					vec2.assign(7,100);
	// 					std::vector<size_t>::iterator iter = vec2.begin();
	// 					for(; iter != vec2.end(); iter++)
	// 							std::cout << "iter : " << *iter << " ; ";
	// 					std::cout << std::endl;
	// 					vec2.assign(5,20);
	// 					std::vector<size_t>::iterator iter2 = vec2.begin();
	// 					for(; iter2 != vec2.end(); iter2++)
	// 							std::cout << "iter2 :" << *iter2 << " ; ";
	// 					std::cout << std::endl;
	// 					{
	// 						std::cout << "\e[0;33m$$$$$$ EXEMPLE CPP REF avec REAL VECTOR $$$$$ \e[0m" << std::endl;
	// 						std::vector<int> first;
	// 						std::vector<int> second;
	// 						std::vector<int> third;

	// 						first.assign (7,100);             // 7 ints with a value of 100

	// 						std::vector<int>::iterator it;
	// 						it=first.begin()+1;

	// 						second.assign (it,first.end()-1); // the 5 central values of first

	// 						int myints[] = {1776,7,4};
	// 						third.assign (myints,myints+3);   // assigning from array.

	// 						std::cout << "Size of first: " << int (first.size()) << '\n';
	// 						std::cout << "Size of second: " << int (second.size()) << '\n';
	// 						std::cout << "Size of third: " << int (third.size()) << '\n';
	// 					}
	// 				}
	// 				std::cout << std::endl;
	// 				{
	// 					std::cout << "\e[0;33m$$$$$$ MY VECTOR $$$$$ \e[0m" << std::endl;
	// 					myvec.assign(7,100);
	// 					ft::vector<size_t>::iterator iter5 = myvec.begin();
	// 					for(; iter5 != myvec.end(); iter5++)
	// 							std::cout << "iter5 : " << *iter5 << " ; ";
	// 					std::cout << std::endl;
	// 					myvec.assign(5,20);
	// 					ft::vector<size_t>::iterator iter8 = myvec.begin();
	// 					for(; iter8 != myvec.end(); iter8++)
	// 							std::cout << "iter8 :" << *iter8 << " ; ";
	// 					std::cout << std::endl;
	// 					{
	// 						std::cout << "\e[0;33m$$$$$$ EXEMPLE CPP REF avec MY VECTOR $$$$$ \e[0m" << std::endl;
	// 						ft::vector<int> first;
	// 						ft::vector<int> second;
	// 						ft::vector<int> third;

	// 						first.assign (7,100);             // 7 ints with a value of 100

	// 						ft::vector<int>::iterator it;
	// 						it=first.begin()+1;

	// 						second.assign (it,first.end()-1); // the 5 central values of first

	// 						int myints[] = {1776,7,4};
	// 						third.assign (myints,myints+3);   // assigning from array.

	// 						std::cout << "Size of first: " << int (first.size()) << '\n';
	// 						std::cout << "Size of second: " << int (second.size()) << '\n';
	// 						std::cout << "Size of third: " << int (third.size()) << '\n';
	// 					}
	// 				}
	// 			}
	// 			std::cout << std::endl;
	// 			std::cout << std::endl;
	// 			std::cout << "\e[0;34mClear() >>>> \e[0m" << std::endl;
	// 			{
	// 				{
	// 					std::cout << "\e[0;33m$$$$$$ MY VECTOR $$$$$ \e[0m" << std::endl;
	// 					// myvec.clear();
	// 					// std::cout << myvec.size() << std::endl;
	// 					ft::vector<int> myvector;
	// 					myvector.push_back (100);
	// 					myvector.push_back (200);
	// 					myvector.push_back (300);

	// 					std::cout << "myvector contains:";
	// 					for (unsigned i=0; i<myvector.size(); i++)
	// 						std::cout << ' ' << myvector[i];
	// 					std::cout << '\n';

	// 					myvector.clear();
	// 					myvector.push_back (1101);
	// 					myvector.push_back (2202);

	// 					std::cout << "myvector contains:";
	// 					for (unsigned i=0; i<myvector.size(); i++)
	// 						std::cout << ' ' << myvector[i];
	// 					std::cout << '\n';
	// 				}
	// 				{
	// 					std::cout << "\e[0;33m$$$$$$ REAL VECTOR $$$$$ \e[0m" << std::endl;
	// 					std::vector<int> myvector;
	// 					myvector.push_back (100);
	// 					myvector.push_back (200);
	// 					myvector.push_back (300);

	// 					std::cout << "myvector contains:";
	// 					for (unsigned i=0; i<myvector.size(); i++)
	// 						std::cout << ' ' << myvector[i];
	// 					std::cout << '\n';

	// 					myvector.clear();
	// 					myvector.push_back (1101);
	// 					myvector.push_back (2202);

	// 					std::cout << "myvector contains:";
	// 					for (unsigned i=0; i<myvector.size(); i++)
	// 						std::cout << ' ' << myvector[i];
	// 					std::cout << '\n';
	// 					// vec2.clear();
	// 					// std::cout << vec2.size() << std::endl;
	// 				}
	// 			}
	// 			std::cout << std::endl;
	// 			std::cout << std::endl;
	// 			std::cout << "\e[0;34mErase() >>>> \e[0m" << std::endl;
	// 			{
	// 				std::cout << "\e[0;33m$$$$$$ REAL VECTOR $$$$$ \e[0m" << std::endl;
	// 				std::vector<int> myvector;
	// 				// set some values (from 1 to 10)
	// 				for (int i=1; i<=10; i++) myvector.push_back(i);

	// 				// erase the 6th element
	// 				// myvector.erase (myvector.begin()+5);

	// 				// erase the first 3 elements:
	// 				myvector.erase (myvector.begin() + 3,myvector.begin()+5);

	// 				std::cout << "myvector contains:";
	// 				for (unsigned i=0; i<myvector.size(); ++i)
	// 					std::cout << ' ' << myvector[i];
	// 				std::cout << '\n';

	// 			}
	// 			{
	// 				std::cout << "\e[0;33m$$$$$$ My VECTOR $$$$$ \e[0m" << std::endl;
	// 				ft::vector<int> myvector;
	// 				// set some values (from 1 to 10)
	// 				for (int i=1; i<=10; i++) myvector.push_back(i);

	// 				// erase the 6th element
	// 				// myvector.erase (myvector.begin()+5);

	// 				// // erase the first 3 elements:
	// 				myvector.erase (myvector.begin() + 3,myvector.begin()+5);

	// 				std::cout << "myvector contains:";
	// 				for (unsigned i=0; i<myvector.size(); ++i)
	// 					std::cout << ' ' << myvector[i];
	// 				std::cout << '\n';

	// 			}
	// 			std::cout << std::endl;
	// 			std::cout << std::endl;
	// 			std::cout << "\e[0;34mPop back() >>>> \e[0m" << std::endl;
	// 			{
	// 				std::cout << "\e[0;33m$$$$$$ Real VECTOR $$$$$ \e[0m" << std::endl;
	// 				std::vector<int> myvector;
	// 				// int sum (0);
	// 				myvector.push_back (100);
	// 				myvector.push_back (200);
	// 				myvector.push_back (300);
	// 				std::vector<int>::iterator start = myvector.begin();
	// 				for(; start != myvector.end(); start++) 
	// 					std::cout << *start << std::endl;
	// 				while (!myvector.empty())
	// 				{
	// 					// sum+=myvector.back();
	// 					myvector.pop_back();
	// 				}
	// 			}
	// 			{
	// 				std::cout << "\e[0;33m$$$$$$ My VECTOR $$$$$ \e[0m" << std::endl;
	// 				ft::vector<int> myvector;
	// 				// int sum (0);
	// 				myvector.push_back (100);
	// 				myvector.push_back (200);
	// 				myvector.push_back (300);
	// 				ft::vector<int>::iterator start = myvector.begin();
	// 				for(; start != myvector.end(); start++) 
	// 					std::cout << *start << std::endl;
	// 				while (!myvector.empty())
	// 				{
	// 					// sum+=myvector.back();
	// 					myvector.pop_back();
	// 				}
	// 			}
	// 			std::cout << std::endl;
	// 			std::cout << std::endl;
	// 			std::cout << "\e[0;34mat() >>>> \e[0m" << std::endl;
	// 			{
	// 				try
	// 				{
	// 					std::cout << "\e[0;33m$$$$$$ Real VECTOR $$$$$ \e[0m" << std::endl;
	// 					std::vector<int> myvector;
	// 					// int sum (0);
	// 					myvector.push_back (100);
	// 					myvector.push_back (200);
	// 					myvector.push_back (300);
	// 					std::cout << myvector.at(2) << std::endl;
	// 					myvector.at(6);
	// 				}
	// 				catch(const std::exception& e)
	// 				{
	// 					std::cout << e.what() << std::endl;
	// 				}
	// 			}
	// 			{
	// 				try
	// 				{
	// 					std::cout << "\e[0;33m$$$$$$ My VECTOR $$$$$ \e[0m" << std::endl;
	// 					ft::vector<int> myvector;
	// 					// int sum (0);
	// 					myvector.push_back (100);
	// 					myvector.push_back (200);
	// 					myvector.push_back (300);
	// 					std::cout << myvector.at(2) << std::endl;
	// 					myvector.at(6);
	// 				}
	// 				catch(const std::exception& e)
	// 				{
	// 					std::cout << e.what() << std::endl;
	// 				}
	// 			}
	// 		}
	// 			std::cout << std::endl;
	// 			std::cout << std::endl;
	// 			std::cout << "\e[0;34mfront() >>>> \e[0m" << std::endl;
	// 			{
	// 				try
	// 				{
	// 					std::cout << "\e[0;33m$$$$$$ Real VECTOR $$$$$ \e[0m" << std::endl;
	// 					std::vector<int> myvector;
	// 					// int sum (0);
	// 					myvector.push_back (100);
	// 					myvector.push_back (200);
	// 					myvector.push_back (300);
	// 					std::cout << myvector.front() << std::endl;
	// 				}
	// 				catch(const std::exception& e)
	// 				{
	// 					std::cout << e.what() << std::endl;
	// 				}
	// 			}
	// 			{
	// 				try
	// 				{
	// 					std::cout << "\e[0;33m$$$$$$ My VECTOR $$$$$ \e[0m" << std::endl;
	// 					ft::vector<int> myvector;
	// 					// int sum (0);
	// 					myvector.push_back (100);
	// 					myvector.push_back (200);
	// 					myvector.push_back (300);
	// 					std::cout << myvector.front() << std::endl;
	// 				}
	// 				catch(const std::exception& e)
	// 				{
	// 					std::cout << e.what() << std::endl;
	// 				}
	// 			}
	// 		}
	// 			std::cout << std::endl;
	// 			std::cout << std::endl;
	// 			std::cout << "\e[0;34mback() >>>> \e[0m" << std::endl;
	// 			{
	// 				try
	// 				{
	// 					std::cout << "\e[0;33m$$$$$$ Real VECTOR $$$$$ \e[0m" << std::endl;
	// 					std::vector<int> myvector;
	// 					// int sum (0);
	// 					myvector.push_back (100);
	// 					myvector.push_back (200);
	// 					myvector.push_back (300);
	// 					std::cout << myvector.back() << std::endl;
	// 				}
	// 				catch(const std::exception& e)
	// 				{
	// 					std::cout << e.what() << std::endl;
	// 				}
	// 			}
	// 			{
	// 				try
	// 				{
	// 					std::cout << "\e[0;33m$$$$$$ My VECTOR $$$$$ \e[0m" << std::endl;
	// 					ft::vector<int> myvector;
	// 					// int sum (0);
	// 					myvector.push_back (100);
	// 					myvector.push_back (200);
	// 					myvector.push_back (300);
	// 					std::cout << myvector.back() << std::endl;
	// 				}
	// 				catch(const std::exception& e)
	// 				{
	// 					std::cout << e.what() << std::endl;
	// 				}
	// 			}
	// 			std::cout << std::endl;
	// 			std::cout << std::endl;
	// 			std::cout << "\e[0;34m Relational Operators >>>> \e[0m" << std::endl;
	// 			{
	// 				try
	// 				{
	// 					std::cout << "\e[0;33m$$$$$$ Real VECTOR $$$$$ \e[0m" << std::endl;
	// 					std::vector<int> myvector;
	// 					std::vector<int> myvector2;
	// 					// int sum (0);
	// 					myvector.push_back (100);
	// 					myvector.push_back (200);
	// 					myvector.push_back (300);
	// 					myvector2.push_back (100);
	// 					myvector2.push_back (200);
	// 					myvector2.push_back (50);
	// 					if (myvector <= myvector2)
	// 						std::cout << " Kikou " << std::endl;
	// 					else
	// 						std::cout << " Not Kikou " << std::endl;
	// 					std::vector<int> vec1;
	// 					std::vector<int> vec2;
	// 					vec1.push_back (1);
	// 					vec1.push_back (2);
	// 					vec1.push_back (3);
	// 					vec1.push_back (6);
	// 					vec1.push_back (9);
	// 					vec2.push_back (1);
	// 					vec2.push_back (2);
	// 					vec2.push_back (3);
	// 					if (vec1 != vec2)
	// 						std::cout << " Kikou " << std::endl;
	// 					else
	// 						std::cout << " Not Kikou " << std::endl;

	// 				}
	// 				catch(const std::exception& e)
	// 				{
	// 					std::cout << e.what() << std::endl;
	// 				}
	// 			}
	// 			std::cout << std::endl;
	// 			{
	// 				try
	// 				{
	// 					std::cout << "\e[0;33m$$$$$$ My VECTOR $$$$$ \e[0m" << std::endl;
	// 					ft::vector<int> myvector;
	// 					ft::vector<int> myvector2;
	// 					// int sum (0);
	// 					myvector.push_back (100);
	// 					myvector.push_back (200);
	// 					myvector.push_back (300);
	// 					myvector2.push_back (100);
	// 					myvector2.push_back (200);
	// 					myvector2.push_back (50);
	// 					if (myvector <= myvector2)
	// 						std::cout << " Kikou " << std::endl;
	// 					else
	// 						std::cout << " Not Kikou " << std::endl;
	// 					std::vector<int> vec1;
	// 					std::vector<int> vec2;
	// 					vec1.push_back (1);
	// 					vec1.push_back (2);
	// 					vec1.push_back (3);
	// 					vec1.push_back (6);
	// 					vec1.push_back (9);
	// 					vec2.push_back (1);
	// 					vec2.push_back (2);
	// 					vec2.push_back (3);
	// 					if (vec1 != vec2)
	// 						std::cout << " Kikou " << std::endl;
	// 					else
	// 						std::cout << " Not Kikou " << std::endl;
	// 				}
	// 				catch(const std::exception& e)
	// 				{
	// 					std::cout << e.what() << std::endl;
	// 				}
	// 			}
	// 			std::cout << std::endl;
	// 			{
	// 				std::cout << "\e[0;33m$$$$$$ SWAP $$$$$ \e[0m" << std::endl;
	// 				{
	// 					try
	// 					{
	// 						std::cout << "\e[0;33m$$$$$$ REAL VECTOR $$$$$ \e[0m" << std::endl;
	// 						std::vector<int> myvector;
	// 						std::vector<int> myvector2;
	// 						// int sum (0);
	// 						myvector.push_back (1);
	// 						myvector.push_back (2);
	// 						myvector.push_back (3);
	// 						myvector2.push_back (100);
	// 						myvector2.push_back (200);
	// 						myvector2.push_back (50);
	// 						myvector2.push_back (550);
	// 						myvector2.push_back (5500);
	// 						myvector.swap(myvector2);
	// 						std::vector<int>::iterator start = myvector.begin();
	// 						for(; start != myvector.end(); start++)
	// 							std::cout << *start << std::endl;
	// 						std::vector<int>::iterator start2 = myvector2.begin();
	// 						for(; start2 != myvector2.end(); start2++)
	// 							std::cout << *start2 << std::endl;
				
	// 					}
	// 					catch(const std::exception& e)
	// 					{
	// 						std::cout << e.what() << std::endl;
	// 					}
	// 				}
	// 				{
	// 					try
	// 					{
	// 						std::cout << "\e[0;33m$$$$$$ My VECTOR $$$$$ \e[0m" << std::endl;
	// 						ft::vector<int> myvector;
	// 						ft::vector<int> myvector2;
	// 						// int sum (0);
	// 						myvector.push_back (1);
	// 						myvector.push_back (2);
	// 						myvector.push_back (3);
	// 						myvector2.push_back (100);
	// 						myvector2.push_back (200);
	// 						myvector2.push_back (50);
	// 						myvector2.push_back (550);
	// 						myvector2.push_back (5500);
	// 						myvector.swap(myvector2);
	// 						ft::vector<int>::iterator start = myvector.begin();
	// 						for(; start != myvector.end(); start++)
	// 							std::cout << *start << std::endl;
	// 						ft::vector<int>::iterator start2 = myvector2.begin();
	// 						for(; start2 != myvector2.end(); start2++)
	// 							std::cout << *start2 << std::endl;
				
	// 					}
	// 					catch(const std::exception& e)
	// 					{
	// 						std::cout << e.what() << std::endl;
	// 					}
	// 				}
	// 			}
	// 			std::cout << std::endl;
	// 			std::cout << std::endl;
	// 			std::cout << "\e[1;41m Reverse iterators \033[0m\n" << std::endl;
	// 			{
	// 				// {
	// 				// 	std::cout << "\e[0;34m Real Reverse_iterator ++ >>>> \e[0m" << std::endl;
	// 				// 	std::vector<int> myvector;
	// 				// 	for (int i=0; i<10; i++) myvector.push_back(i);

	// 				// 	typedef std::vector<int>::iterator iter_type;
	// 				// 															// ? 9 8 7 6 5 4 3 2 1 0 ?
	// 				// 	iter_type from (myvector.begin());                     //   ^
	// 				// 															//         ------>
	// 				// 	iter_type until (myvector.end());                      //                       ^
	// 				// 															//
	// 				// 	std::reverse_iterator<iter_type> rev_until (from);     // ^
	// 				// 	std::cout << "rev_util :" << *rev_until<< std::endl;
	// 				// 		//         <------
	// 				// 	std::reverse_iterator<iter_type> rev_from (until);     //                     ^
	// 				// 	std::cout << "rev_from :" << *rev_from << std::endl;

	// 				// 	std::cout << "myvector:";
	// 				// 	while (rev_from != rev_until)
	// 				// 		std::cout << ' ' << *rev_from++;
	// 				// 	std::cout << '\n';
	// 				// }
	// 				// {
	// 				// 	std::cout << "\e[0;34m My Reverse_iterator  ++ >>>> \e[0m" << std::endl;
	// 				// 	ft::vector<int> myvector;
	// 				// 	for (int i=0; i<10; i++)
	// 				// 	{
	// 				// 		myvector.push_back(i);
	// 				// 		// std::cout << myvector[i] << std::endl;
	// 				// 	}
	// 				// 	typedef ft::vector<int>::iterator iter_type;
	// 				// 															// ? 9 8 7 6 5 4 3 2 1 0 ?
	// 				// 	iter_type from (myvector.begin());                     //   ^
	// 				// 	// std::cout << "from :" << *from << std::endl;
	// 				// 	// 														//         ------>
	// 				// 	iter_type until (myvector.end());                     //                       ^
	// 				// 	// std::cout << "until :" << *until << std::endl;					//
	// 				// 	ft::reverse_iterator<iter_type> rev_until (from);     // ^
	// 				// 	// std::cout << "rev_util :" << *rev_until + 1 << std::endl;
	// 				// 												//         <------
	// 				// 	ft::reverse_iterator<iter_type> rev_from (until);     //                     ^
	// 				// 	// std::cout << "rev_from :" << *rev_from - 1 << std::endl;

	// 				// 	// std::cout << "myvector:" << std::endl;
	// 				// 	// int i = 0;
	// 				// 	// while (rev_from != rev_until)
	// 				// 	// {
	// 				// 	// 	std::cout << "revv fromm === : " << *rev_from++ << " " << std::endl;
	// 				// 	// 	i++;	
	// 				// 	// }
	// 				// 	int i = 0;
	// 				// 	while (rev_from != rev_until)
	// 				// 	{
	// 				// 		std::cout << *rev_from++ << std::endl;
	// 				// 		i++;	
	// 				// 	}
	// 				// 	// std::cout << '\n';
	// 				// }
	// 				// {
	// 				// 	std::cout << "\e[0;34m Real Reverse_iterator -- >>>> \e[0m" << std::endl;
	// 				// 	 std::vector<int> myvector;
	// 				// 	for (int i=0; i<10; i++) myvector.push_back(i);

	// 				// 	typedef std::vector<int>::iterator iter_type;

	// 				// 	std::reverse_iterator<iter_type> rev_begin (myvector.end());
	// 				// 	std::reverse_iterator<iter_type> rev_end (myvector.begin());

	// 				// 	std::reverse_iterator<iter_type> rev_iterator = rev_begin;
	// 				// 	while ( rev_iterator != rev_end )
	// 				// 		std::cout << *rev_iterator++ << ' ';
	// 				// 	std::cout << '\n';

	// 				// 	while ( rev_iterator != rev_begin )
	// 				// 		std::cout << *(--rev_iterator) << ' ';
	// 				// 	std::cout << '\n';
				
	// 				// }
	// 				// {
	// 				// 	std::cout << "\e[0;34m My Reverse_iterator  -- >>>> \e[0m" << std::endl;
	// 				// 	ft::vector<int> myvector;
	// 				// 	for (int i=0; i<10; i++) myvector.push_back(i);

	// 				// 	typedef ft::vector<int>::iterator iter_type;

	// 				// 	std::reverse_iterator<iter_type> rev_begin (myvector.end());
	// 				// 	std::reverse_iterator<iter_type> rev_end (myvector.begin());

	// 				// 	std::reverse_iterator<iter_type> rev_iterator = rev_begin;
	// 				// 	while ( rev_iterator != rev_end )
	// 				// 		std::cout << *rev_iterator++ << ' ';
	// 				// 	std::cout << '\n';

	// 				// 	while ( rev_iterator != rev_begin )
	// 				// 		std::cout << *(--rev_iterator) << ' ';
	// 				// 	std::cout << '\n';

	// 				// }
	// 				// {
	// 				// 	std::cout << "\e[0;34m Real Reverse_iterator -> >>>> \e[0m" << std::endl;
	// 				// 	std::vector<int> myvector;
	// 				// 	for (int i=0; i<10; i++) myvector.push_back(i);

	// 				// 	typedef std::vector<int>::iterator iter_type;

	// 				// 	std::reverse_iterator<iter_type> rev_begin (myvector.end());
	// 				// 	std::reverse_iterator<iter_type> rev_end (myvector.begin());

	// 				// 	std::reverse_iterator<iter_type> rev_iterator = rev_begin;
	// 				// 	while ( rev_iterator != rev_end )
	// 				// 		std::cout << *rev_iterator++ << ' ';
	// 				// 	std::cout << '\n';

	// 				// 	int i = 0;
	// 				// 	while ( rev_iterator != rev_begin && i < 10)
	// 				// 	{
	// 				// 		--rev_iterator;
	// 				// 		std::cout << rev_iterator[i] << ' ';
	// 				// 	}
	// 				// 	std::cout << '\n';

	// 				// }
	// 				// {
	// 				// 	std::cout << "\e[0;34m My Reverse_iterator  -> >>>> \e[0m" << std::endl;
	// 				// 	ft::vector<int> myvector;
	// 				// 	for (int i=0; i<10; i++) myvector.push_back(i);

	// 				// 	typedef ft::vector<int>::iterator iter_type;

	// 				// 	std::reverse_iterator<iter_type> rev_begin (myvector.end());
	// 				// 	std::reverse_iterator<iter_type> rev_end (myvector.begin());

	// 				// 	std::reverse_iterator<iter_type> rev_iterator = rev_begin;
	// 				// 	while ( rev_iterator != rev_end )
	// 				// 		std::cout << *rev_iterator++ << ' ';
	// 				// 	std::cout << '\n';

	// 				// 	int i = 0;
	// 				// 	while ( rev_iterator != rev_begin && i < 10)
	// 				// 	{
	// 				// 		--rev_iterator;
	// 				// 		std::cout << rev_iterator[i] << ' ';
	// 				// 	}
	// 				// 	std::cout << '\n';

	// 				// }

	// 			}
	// }
}