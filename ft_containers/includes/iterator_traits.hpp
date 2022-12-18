#pragma once
/* Ces types (tel que difference_type/value_type/pointer....) sont utilisés par les itérateurs nativement, cependant, ils ne le sont généralement pas par les algorithmes. En effet, ceux-ci sont susceptibles d'être appelées avec des pointeurs normaux, et les pointeurs ne définissent pas tous ces types. Or, les algorithmes sont definis generiquement pour tous les containers.
C'est pour cette raison qu'une classe de traits a été définie pour les itérateurs par la bibliothèque standard. Cette classe est déclarée comme suit dans l'en-tête iterator : */


/* La declaration des structures en plusieurs fois permet de pouvoir repondre au besoin des algorithmes qui ne connaissent pas les iterateurs en tan qu'objet mais uniquemet les pointeurs. */


/* Les traits permettent de faire la jointure entre les pointeurs et les iterators. Unification entre iterateurs/pointeurs/const_pointeurs*/

template<class Iterator> 
struct iterator_traits
{
	typedef typename Iterator::difference_type 		difference_type;
	typedef typename Iterator::value_type 			value_type;
	typedef typename Iterator::pointer 				pointer;
	typedef typename Iterator::reference 			reference;
	typedef typename Iterator::iterator_category 	iterator_category;
};

template <class T>
struct iterator_traits<T *>
{
    typedef T         							value_type;
    typedef std::ptrdiff_t 						difference_type;
    typedef T         							*pointer;
    typedef T         							&reference;
    typedef std::random_access_iterator_tag 	iterator_category;
};

template <class T>
struct iterator_traits<const T*> 
{
	
	typedef T										value_type;
	typedef std::ptrdiff_t							difference_type;
	typedef const T*								pointer;
	typedef const T&								reference;
	typedef std::random_access_iterator_tag			iterator_category;
};