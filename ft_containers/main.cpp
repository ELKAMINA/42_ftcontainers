#include <iostream>
#include <iomanip>
#include "./includes/Stack.hpp"
#include "./includes/myVector.hpp"

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
			ft::vector<int> myvec(10, 100);
			std::cout << "\e[0;35mParametric constructor <int>\e[0m" << std::endl;
			std::cout << "Adresse : " <<&myvec << std::endl;
			std::cout << "Size : " << myvec.size() << std::endl;
			std::cout << std::endl;
			/*Resultat attendu : une adresse doit etre imprimee*/
			/*Size = 10*/
		}
		{
			ft::vector<char> myvec(10, 'c');
			std::cout << "\e[0;35mParametric constructor <char>\e[0m" << std::endl;
			std::cout << "Adresse : " <<&myvec << std::endl;
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
		// ft::vector<int> myvec(first, last);
		// std::cout << "\e[0;35mRange constructor\e[0m" << std::endl;
		// std::cout << "Adresse : " <<&myvec << std::endl;
		// std::cout << "Size : " << myvec.size() << std::endl;
		// std::cout << std::endl;

		/*Resultat attendu : une adresse doit etre imprimee*/
		/*Size = 10*/
	}
	{
		/* RESTE A FAIRE - Copy constructor - depend de Assign*/
		// ft::vector<int> myvec();
		// std::cout << "\e[0;35mRange constructor\e[0m" << std::endl;
		// std::cout << "Adresse : " <<&myvec << std::endl;
		// std::cout << "Size : " << myvec.size() << std::endl;
		// std::cout << std::endl;

		/*Resultat attendu : une adresse doit etre imprimee*/
		/*Size = 10*/
	}
	std::cout << "\e[1;41m Testing Iterators\033[0m\n" << std::endl;
	{
		{
			ft::vector<int> myvec(5, 150);
			std::cout << "\e[0;34mBegin constructor\e[0m" << std::endl;
			std::cout << "Adresse : " <<&myvec << std::endl;
			std::cout << "Derefeencing Begin() : " << *myvec.begin() << std::endl;
			std::cout << std::endl;

			/* Resultat attendu : une adresse doit etre imprimee */
			/* Deferencement de begin  = 150 */
		}
		{
			ft::vector<char> myvec(5, 'k');
			std::cout << "\e[0;34mBegin constructor <char>\e[0m" << std::endl;
			std::cout << "Adresse : " <<&myvec << std::endl;
			std::cout << "Derefeencing Begin() : " << *myvec.begin() << std::endl;
			std::cout << std::endl;

			/* Resultat attendu : une adresse doit etre imprimee */
			/* Deferencement de begin  = k */
		}
		{
			ft::vector<std::string> myvec(5, "kikou");
			std::cout << "\e[0;34mBegin constructor <string>\e[0m" << std::endl;
			std::cout << "Adresse : " <<&myvec << std::endl;
			std::cout << "Derefeencing Begin() : " << *myvec.begin() << std::endl;
			std::cout << std::endl;

			/* Resultat attendu : une adresse doit etre imprimee */
			/* Deferencement de begin  = kikou */
		}
	}
	{
		ft::vector<int> myvec(5, 130);
		std::cout << "\e[0;34mEnd iterator\e[0m" << std::endl;
		std::cout << "Adresse : " <<&myvec << std::endl;
		std::cout << "Dereferencing END() : " << *myvec.end() << std::endl;
		std::cout << std::endl;

		/*Resultat attendu : rien car end pointe sur l'adresse apres le tableau */
	}
	{
		ft::vector<int> myvec(5, 130);
		ft::vector<int>::iterator it(myvec.begin());
		std::cout << "\e[0;34m IT \e[0m" << std::endl;
		// std::cout << "Adresse : " << it << std::endl;
		std::cout << "Dereferencing IT : " << *it << std::endl;
		std::cout << std::endl;

		/*Resultat attendu : rien car end pointe sur l'adresse apres le tableau */
	}
	std::cout << "\e[1;41m Testing Capacity\033[0m\n" << std::endl;
	{
		{
			ft::vector<int> myvec(5, 130);
			ft::vector<int> myvec2(0, 130);
			std::cout << "\e[0;34mSize() >>>> \e[0m" << std::endl;
			// std::cout << "Adresse : " << it << std::endl;
			std::cout << "size of myvec: " << myvec.size() << std::endl;
			std::cout << std::endl;
			std::cout << "size of myvec2: " << myvec2.size() << std::endl;
			std::cout << std::endl;
		}
		{
			ft::vector<int> myvec(5, 130);
			std::vector<int> myvec2(5, 130);
			// ft::vector<int> myvec2(0, 130);
			std::cout << "\e[0;34mMax_Size() >>>> \e[0m" << std::endl;
			// std::cout << "Adresse : " << it << std::endl;
			std::cout << "MAx size of myvec: " << myvec.max_size() << std::endl;
			std::cout << "MAx size of myvec: " << myvec2.max_size() << std::endl;
			std::cout << std::endl;
		}
		{
			ft::vector<int> myvec(5, 130);
			std::vector<int> myvec2(5, 130);
			std::vector<int> myvec3(0, 130);
			ft::vector<int> myvec4(0, 130);
			// ft::vector<int> myvec2(0, 130);
			std::cout << "\e[0;34mEmpty() >>>> \e[0m" << std::endl;
			// std::cout << "Adresse : " << it << std::endl;
			std::cout << "Empty: " << myvec.empty() << std::endl;
			std::cout << "Real Empty: " << myvec2.empty() << std::endl;
			std::cout << std::endl;
			std::cout << "Empty: " << myvec4.empty() << std::endl;
			std::cout << "Real Empty: " << myvec3.empty() << std::endl;
			std::cout << std::endl;
		}
		{
			ft::vector<size_t> myvec(5, 130);
			std::vector<size_t> vec2(5, 130);
			std::cout << "\e[0;34mResize() >>>> \e[0m" << std::endl;
			std::cout << std::endl;
			{
				std::cout << "\e[0;46mCase 1 : n < curr ...\e[0m"  << std::endl;
				std::cout << std::endl;
				std::cout << "\e[0;33m$$$$$$ MY VECTOR $$$$$ \e[0m" << std::endl;
				std::cout << "My Size: " << myvec.size() << std::endl;
				std::cout << "My Capacity: " << myvec.capacity() << std::endl;
				std::cout << "Resizing ... " << std::endl;
				myvec.resize(3, 20);
				std::cout << "My Size: " << myvec.size() << std::endl;
				std::cout << "My Capacity: " << myvec.capacity() << std::endl;

				std::cout << std::endl;

				std::cout << "\e[0;32m~~~~ REAL VECTOR ~~~~~ \e[0m" << std::endl;
				std::cout << "Size: " << vec2.size() << std::endl;
				std::cout << "Capacity: " << vec2.capacity() << std::endl;
				std::cout << "Resizing ... " << std::endl;
				vec2.resize(3, 20);
				std::cout << "Size: " << vec2.size() << std::endl;
				std::cout << "Capacity: " << vec2.capacity() << std::endl;
				std::cout << std::endl;
			}
			{
				std::cout << "\e[0;46mCase 2 : n > curr ...\e[0m"  << std::endl;
				std::cout << std::endl;
				std::cout << "\e[0;33m$$$$$$ MY VECTOR $$$$$ \e[0m" << std::endl;
				std::cout << "My Size: " << myvec.size() << std::endl;
				std::cout << "My Capacity: " << myvec.capacity() << std::endl;
				std::cout << "Resizing ... " << std::endl;
				myvec.resize(8, 1200);
				std::cout << "My Size: " << myvec.size() << std::endl;
				std::cout << "My Capacity: " << myvec.capacity() << std::endl;
				std::cout << "Traversing the tab ... " << std::endl;
				ft::vector<size_t>::iterator start1 = myvec.begin();
				for(; start1 != myvec.end(); start1++)
					std::cout << *start1 << " ; ";
				std::cout << std::endl;
				std::cout << std::endl;
				std::cout << "\e[0;32m~~~~ REAL VECTOR ~~~~~ \e[0m" << std::endl;
				std::cout << "Size: " << vec2.size() << std::endl;
				std::cout << "Capacity: " << vec2.capacity() << std::endl;
				std::cout << "Resizing ... " << std::endl;
				vec2.resize(8, 1200);
				std::cout << "Size: " << vec2.size() << std::endl;
				std::cout << "Capacity: " << vec2.capacity() << std::endl;
				std::cout << "Traversing the tab ... " << std::endl;
				std::vector<size_t>::iterator start = vec2.begin();
				for(; start != vec2.end(); start++)
					std::cout << *start << " ; ";
				std::cout << std::endl;

			}
			{
				try{
					std::cout << std::endl;
					std::cout << "\e[0;46mCase 3 : n > curr && n > max_size ...\e[0m"  << std::endl;
					std::cout << std::endl;
					std::cout << std::endl;
					std::cout << "\e[0;33m$$$$$$ MY VECTOR $$$$$ \e[0m" << std::endl;
					std::cout << "My Size: " << myvec.size() << std::endl;
					std::cout << "My Capacity: " << myvec.capacity() << std::endl;
					std::cout << "Resizing ... " << std::endl;
					myvec.resize(2305843009213693955, 1200);
					std::cout << "My Size: " << myvec.size() << std::endl;
					std::cout << "My Capacity: " << myvec.capacity() << std::endl;
					std::cout << "Traversing the tab ... " << std::endl;
					ft::vector<size_t>::iterator start1 = myvec.begin();
					for(; start1 != myvec.end(); start1++)
						std::cout << *start1 << " ; ";
					std::cout << std::endl;
					std::cout << std::endl;
					std::cout << "\e[0;32m~~~~ REAL VECTOR ~~~~~ \e[0m" << std::endl;
					std::cout << "Size: " << vec2.size() << std::endl;
					std::cout << "Capacity: " << vec2.capacity() << std::endl;
					std::cout << "Resizing ... " << std::endl;
					vec2.resize(2305843009213693956, 1200);
					std::cout << "Size: " << vec2.size() << std::endl;
					std::cout << "Capacity: " << vec2.capacity() << std::endl;
					std::cout << "Traversing the tab ... " << std::endl;
					std::vector<size_t>::iterator start = vec2.begin();
					for(; start != vec2.end(); start++)
						std::cout << *start << " ; ";
				}
				catch(const std::exception& e)
				{
					std::cout << e.what() << std::endl;
				}
			}
			{
				try{
					std::cout << std::endl;
					std::cout << "\e[0;46mCase 4 : n > curr && n > Capacity : testing also reserve ...\e[0m"  << std::endl;
					std::cout << std::endl;
					std::cout << std::endl;
					std::cout << "\e[0;33m$$$$$$ MY VECTOR $$$$$ \e[0m" << std::endl;
					std::cout << "My Size: " << myvec.size() << std::endl;
					std::cout << "My Capacity: " << myvec.capacity() << std::endl;
					std::cout << "Resizing ... " << std::endl;
					myvec.resize(14, 1200);
					std::cout << "My Size: " << myvec.size() << std::endl;
					std::cout << "My Capacity: " << myvec.capacity() << std::endl;
					std::cout << "Traversing the tab ... " << std::endl;
					ft::vector<size_t>::iterator start1 = myvec.begin();
					for(; start1 != myvec.end(); start1++)
						std::cout << *start1 << " ; ";
					std::cout << std::endl;
					std::cout << std::endl;
					std::cout << "\e[0;32m~~~~ REAL VECTOR ~~~~~ \e[0m" << std::endl;
					std::cout << "Size: " << vec2.size() << std::endl;
					std::cout << "Capacity: " << vec2.capacity() << std::endl;
					std::cout << "Resizing ... " << std::endl;
					vec2.resize(14, 1200);
					std::cout << "Size: " << vec2.size() << std::endl;
					std::cout << "Capacity: " << vec2.capacity() << std::endl;
					std::cout << "Traversing the tab ... " << std::endl;
					std::vector<size_t>::iterator start = vec2.begin();
					for(; start != vec2.end(); start++)
						std::cout << *start << " ; ";
				}
				catch(const std::exception& e)
				{
					std::cout << e.what() << std::endl;
				}
			}
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "\e[1;41m Modifiers\033[0m\n" << std::endl;
			{
				ft::vector<size_t> myvec(5, 130);
				std::vector<size_t> vec2(5, 130);
				std::cout << "\e[0;34mINSERT() >>>> \e[0m" << std::endl;
				{
					try
					{
						{
							std::cout << std::endl;
							std::cout << "\e[0;46mProtoype 2\e[0m"  << std::endl;
							std::cout << std::endl;
							std::cout << std::endl;
							std::cout << "\e[0;33m$$$$$$ MY VECTOR $$$$$ \e[0m" << std::endl;
							std::cout << "My Size: " << myvec.size() << std::endl;
							std::cout << "My Capacity: " << myvec.capacity() << std::endl;
							std::cout << "Inserting ... " << std::endl;
							ft::vector<size_t>::iterator it = myvec.begin();
							myvec.insert(it+2, 4, 15);
							std::cout << "My Size: " << myvec.size() << std::endl;
							std::cout << "My Capacity: " << myvec.capacity() << std::endl;
							std::cout << "Traversing the tab ... " << std::endl;
							ft::vector<size_t>::iterator start1 = myvec.begin();
							for(; start1 != myvec.end(); start1++)
								std::cout << *start1 << " ; ";
							std::cout << std::endl;
							ft::vector<size_t>::iterator start3 = myvec.begin();
							myvec.insert(start3+5, 2, 12);
							ft::vector<size_t>::iterator start4 = myvec.begin();
							for(; start4 != myvec.end(); start4++)
								std::cout << *start4 << " ; ";
							std::cout << std::endl;
							std::cout << std::endl;


							std::cout << "\e[0;32m~~~~ REAL VECTOR ~~~~~ \e[0m" << std::endl;
							std::cout << "Size: " << vec2.size() << std::endl;
							std::cout << "Capacity: " << vec2.capacity() << std::endl;
							std::cout << "Inserting ... " << std::endl;
							std::vector<size_t>::iterator ittt = vec2.begin();
							vec2.insert(ittt+2, 4, 15);
							std::cout << "My Size: " << vec2.size() << std::endl;
							std::cout << "My Capacity: " << vec2.capacity() << std::endl;
							std::cout << "Traversing the tab ... " << std::endl;
							std::vector<size_t>::iterator itt1 = vec2.begin();
							for(; itt1 != vec2.end(); itt1++)
								std::cout << *itt1 << " ; ";
							std::cout << std::endl;
							std::vector<size_t>::iterator itt2 = vec2.begin();
							vec2.insert(itt2+5, 2, 12);
							std::vector<size_t>::iterator itt3 = vec2.begin();
							for(; itt3 != vec2.end(); itt3++)
								std::cout << *itt3 << " ; ";
							std::cout << std::endl;
							std::cout << std::endl;
					}
					{
						std::cout << std::endl;
						std::cout << "\e[0;46mProtoype 3\e[0m"  << std::endl;
						std::cout << std::endl;
						std::cout << std::endl;
						std::cout << "\e[0;33m$$$$$$ MY VECTOR $$$$$ \e[0m" << std::endl;
						std::cout << "My Size: " << myvec.size() << std::endl;
						std::cout << "My Capacity: " << myvec.capacity() << std::endl;
						size_t myarray[] = {5, 6, 8};
						ft::vector<size_t>::iterator it = myvec.begin();
						ft::vector<size_t>::iterator first = myarray;
						myvec.insert(it+2, first, first+3);
						std::cout << "Inserting ... " << std::endl;
						ft::vector<size_t>::iterator toto = myvec.begin();
						for(; toto != myvec.end(); toto++)
							std::cout << *toto << " ; ";
						std::cout << std::endl;
						std::cout << std::endl;
					}
			}
			catch(const std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
			}
//		}
	}
}