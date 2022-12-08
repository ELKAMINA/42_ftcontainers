# Introdution to "ft_containers" project

**Goal** : Reimplementing STL containers (c++98) 

  1. Vector
  2. Map

**Tools to implement for each container**

  1. iterator_traits
  2. reverse_iterator
  3. enable_if (SFINAE)
  4. is_integral
  5. equal
  6. lexicographical_compare
  7. pair
  8. make_pair

**Requirements**
  
  > Iterators system.
  
  > std::allocator.
  
  > keyword friend if needed.

# To start :

1. What is a container ?
a container is an object that contains other objects that can be manipulated (suppressed, added, sorted, searched ...). It is done thanks to iterators.

2. What makes a container more intersting than another in some situations ?
We call **Complexity** : the idea of how efficient it is to access an element from the container. W can distinguish :
 - Linear Complexity O(n) : if calculation is proportional to n.
 - Instantaneous Complexity O(1) : if calculation is instantaneous.
 - Logarithmic COmplexity O(log(n))
  .
  .
  .
  
 3. What are iterators ?
 
 => Pointer-like objects
 
 In C++ STL (Standard Template Library), 3 things are meaningful and important:

**Containers**: These are used to manage collection of objects of a certain kind. Containers can be of two types: Sequence Containers (vector, deque, list) and Associative Containers (Set, Multiset, Map, Multimap).

**Algorithms**: These are used to process the elements of a collection. That is algorithms feed from containers and process those elements in a predefined way and may also push the results into the same/different container.

**Iterator**: These are used to step through the elements of collection of objects (aka containers).
The designer of STL chose a wonderful yet simple common approach - "The separation of data and operation".

*The data is held and managed by the Container classes.*
*The operations over the containers are defined and managed by the configurable algorithms.*

**Iterators are those Bridge/Tunnel/Glue** between containers classes and algorithms.

Different categories of iterators :
  - Bidirectionnal
  - Random access
  - Input iterators
  - Output iterators
  - Forward iterators
 
 4. Creating our own container ?
 
 3 requirements :
  
  - **Container interface requirements**
  
  - **Allocator interface requirements :**
  
    The basic interface of an allocator class consists of a set of typedefs, a pair of allocation functions, allocate() and deallocate(), and a pair of       construction/destruction members, construct() and destroy(). The typedefs are used by a container to determine the look of pointers, references,           sizes, and differences, where a difference means a distance between two pointers  
  
  - **Iterator requirements**

5. What are *.traits ?


  
# Vector container

*Vector* is a **sequential container** that encapsulates dynamic sized arrays. The data elements are stored in contiguous storage. Data elements are inserted at the end.
Elements can be accessed with :
- **iterators / reverse iterators** : objects that points to other objects
- **classical pointers**

*Time Complexity for vector differs depending on the operation*;
  - to access an element : O(1)
  - to insert an element : O(n) if pop_back or O(1) if push_back because array need to be extended
 
 *Container Adapter* : vector limited to some functionalities (stack, queue, priority queue)
 
 *class template of vector* : template < class T, class Alloc = allocator<T> > class vector
  
Links that helped
-----------
| Subject | Link |
|:--------------|:----------------|
| Conteneurs STL | http://tvaira.free.fr/dev/cours/cours-conteneurs-stl.pdf |
| Allocator | https://medium.com/@vgasparyan1995/what-is-an-allocator-c8df15a93ed |
| Member types | https://stackoverflow.com/questions/37714566/what-do-member-types-mean-in-vectors |
| Github inspo| https://github.com/yongjulejule/ft_containers/tree/fa4e0535dcdd04d911ac8c2ae5bf5c8e0cdd73d7#ft_containers |
  


Glossary for vector
-----------
| Title | Definition |
|:--------------|:----------------|
| Modifiers | functions that modifies the structure of a vector container |
| Allocator | to give the programmer control over memory allocation within containers. It's stateless|

Perks and cons regarding other dynamic sequence containers
-----------

Perks : vectors are very efficient accessing its elements (just like arrays) and relatively efficient adding or removing elements from its end. 
  
Cons : For operations that involve inserting or removing elements at positions other than the end, they perform worse than the others, and have less consistent iterators and references than lists and forward_lists.

  # Global glossary
  
1. *Namespaces*

In C++, a namespace is a collection of related names or identifiers (functions, class, variables) which helps to separate these identifiers from similar identifiers in other namespaces or the global namespace. The identifiers of the C++ standard library are defined in a namespace called std .

2. *Typedef and Typename*

typedef typename _MyBase::value_type value_type;
value_type v;
  => **typedef** is defining a new type for use in your code, like a shorthand
  => **typename** here is letting the compiler know that value_type is a type and not a static member of _MyBase.
        the :: is the scope of the type. It is kind of like "is in" so value_type "is in" _MyBase. or can also be thought of as contains.
        
 3. *Templates*
 
 allow generic coding bc we don't need to consider the datas type
 has parameters of three kinds :
 - type template parameters
 - non-type template parameters
 - template template parameters.
  
 4. *Allocator-aware*
 
  An object that dynamically handle the container storage needs.

5. What are Range access ?

At a high level, a range is something that you can iterate over. The containers, such as vector and list, in the C++ Standard Library are range.
With ranges, you can call std::ranges::sort(myVector);, which is treated as if you called std::sort(myVector.begin(), myVector.end());. In range libraries, algorithms take ranges as parameters (although they can also take iterators, if you want). They can operate directly on collections.
