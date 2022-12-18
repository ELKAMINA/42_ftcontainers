#include <iostream>
#include <iomanip>
#include "./includes/Stack.hpp"
#include "./includes/myVector.hpp"

/* For colours in terminal/outputs */

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
}