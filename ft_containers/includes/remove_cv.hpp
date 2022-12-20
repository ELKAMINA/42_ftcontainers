#pragma once


/* En C++, le mot-clé volatile est utilisé pour indiquer qu'une variable peut être modifiée dans le programme de manières autres que par des affectations ou des incrémentations/décrémentations. Cela peut inclure des registres matériels, des entrées/sorties mémoire-mappées ou d'autres valeurs qui peuvent changer de manière asynchrone.

L'utilisation du mot-clé volatile indique au compilateur de générer du code qui accède à la variable en question chaque fois qu'elle est utilisée, plutôt que de mettre en cache la valeur dans un registre ou d'optimiser l'accès à celle-ci de quelque manière que ce soit. Cela peut être utile dans des situations où la valeur d'une variable doit être lue à partir de sa position de mémoire effective, plutôt que d'un cache ou d'un registre, pour garantir que la valeur la plus à jour est utilisée. 

The remove_cv template class is also used to remove any const or volatile qualifiers from T before checking if it is an integral type.

*/


namespace ft 
{
/*---------------  remove_cv  -----------------*/
	template< class T > struct remove_cv                   { typedef T type; };
	template< class T > struct remove_cv<const T>          { typedef T type; };
	template< class T > struct remove_cv<volatile T>       { typedef T type; };
	template< class T > struct remove_cv<const volatile T> { typedef T type; };

	template< class T > struct remove_const                { typedef T type; };
	template< class T > struct remove_const<const T>       { typedef T type; };

	template< class T > struct remove_volatile             { typedef T type; };
	template< class T > struct remove_volatile<volatile T> { typedef T type; };
}