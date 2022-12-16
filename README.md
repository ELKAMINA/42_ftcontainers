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
 
 Iterator algorithms are not dependent on the container type.
 Adding iterators to your containers will make them compatible with the range-based for loops(c++11) and the C++ Algorithms library: a collection of functions for searching, sorting, counting and manipulating containers, based on iterators.
 
 4. Creating our own container ?
 
 3 requirements :
  
  - **Container interface requirements**
  
  - **Allocator interface requirements :**
  
    The basic interface of an allocator class consists of a set of typedefs, a pair of allocation functions, allocate() and deallocate(), and a pair of       construction/destruction members, construct() and destroy(). The typedefs are used by a container to determine the look of pointers, references,           sizes, and differences, where a difference means a distance between two pointers  
  
  - **Iterator requirements**

5. What are *.traits ?

 Traits are a powerful tool for providing type information at compile time.
 A trait is a class or class template that characterizes a type, possibly a template parameter
 Traits are typically implemented using template metaprogramming, which allows them to provide type information without requiring any runtime overhead.
 Traits are a C++ convention adopted by programmers, they're also always declared **as struct**.
 
 6. What is ptrdiff_t ?
 
 IT'S A TYPE.
 ptrdiff_t is the signed integer type of the result of subtracting two pointers.
 ptrdiff_t is used for pointer arithmetic and array indexing, if negative values are possible
  
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
 
 ** How to reimplement a vector container **
 
 1. A vector container needs some required typedefs (member types from cplusplus) 
  * TO understand the use of typename/typedef used in containers - **cf item 42** of the book `Effective c++ - 3rd Edition` *
 
 
  
Links that helped
-----------
| Subject | Link |
|:--------------|:----------------|
| Conteneurs STL | http://tvaira.free.fr/dev/cours/cours-conteneurs-stl.pdf |
| Allocator | https://medium.com/@vgasparyan1995/what-is-an-allocator-c8df15a93ed |
| Member types | https://stackoverflow.com/questions/37714566/what-do-member-types-mean-in-vectors |
| Github inspo| https://github.com/yongjulejule/ft_containers/tree/fa4e0535dcdd04d911ac8c2ae5bf5c8e0cdd73d7#ft_containers |
| Traits | https://h-deb.clg.qc.ca/Sujets/Divers--cplusplus/Traits.html| 
| Vectors | https://www.scaler.com/topics/cpp/vector-in-cpp/| 
| Iterators | https://www.internalpointers.com/post/writing-custom-iterators-modern cpp#:~:text=An%20iterator%20is%20an%20object,some%20methods%20to%20retrieve%20it.|
| Types of template specializations | https://www.ibm.com/docs/en/zos/2.4.0?topic=only-explicit-specialization-c |

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
  
6. Compile time VS Running time 
 
Compile time : error detected at compiling time ( from .cpp to .o)
Running time : error detected at running/execution time 

**Compile-time tasks **
    In C++, the compile time refers to the phase of the program's execution when the source code is transformed into an executable program by the compiler. During this phase, the compiler performs a number of tasks, including:

  > Syntax checking: The compiler checks the source code for syntactic correctness, ensuring that the code follows the rules of the C++ language.

  > Preprocessing: The compiler processes any preprocessor directives in the source code, such as #include or #define statements.

  > Type checking: The compiler checks the types of variables, functions, and expressions to ensure that they are used correctly.

  > Optimization: The compiler may perform various optimizations on the code to improve its performance, such as inlining functions or eliminating unnecessary instructions.

  > Code generation: The compiler generates machine code (also known as object code) from the source code, which can be executed by the computer's processor.

  > Linking: The compiler may link the object code with libraries or other object files to create the final executable program.
 
**run-time tasks ** 
    During the run time of a C++ program, the executable code is loaded into memory and executed by the processor. At run time, the following tasks are performed:

  > Memory allocation: The program allocates memory for variables, data structures, and other objects as needed.

  > Function calls: The program calls functions and executes their code.

  > Control flow: The program executes statements in a specific order based on the control flow of the program, such as looping or branching.

  > Input/output: The program may read input from the user or external sources, or output results to the user or external destinations.

  > Exception handling: The program may handle exceptions or errors that occur during execution.

  > Cleanup: The program may perform cleanup tasks when it finishes executing, such as releasing resources or closing files.

    At run time, the program executes the machine code that was generated by the compiler at compile time. This code may include calls to functions, manipulation of data structures, and other operations that are performed by the processor.  

  7. Generic programing / SFINAE

Generic programing is a a way to define identical algorithms on differents types of data. It's a kind of polymorphism (type polymorphism or type setting)
It is based on SFINAE : Substitution Failure is not an Error.
SFINAE is based on the idea that when a compiler encounters an invalid type or expression during template instantiation, it will simply ignore that invalid code and continue the compilation process, instead of generating a compilation error. This allows you to write code that uses template metaprogramming to perform type-based dispatching and conditional logic, without causing compilation errors.
  
8. Metadata et Metaprograming

 ** A TRADUIRE **
Où une donnée peut simplement être une information, une liste de mesures ou des observations, une histoire ou une description d’une certaine chose. Les métadonnées spécifient les informations pertinentes sur les données, ce qui aide à identifier la nature et la caractéristique des données.
*Une information disponible au programme sur les types qui y sont utilisés*

9. Template specialization/ Template instantiation :
  
purpose : sometimes, Templates works for 2/3 datas types out of 4. So we need, a template specialization to make our class really generic regardless of all data types.
> Link : https://www.ibm.com/docs/en/zos/2.4.0?topic=only-explicit-specialization-c
The act of creating a new definition of a function, class, or member of a class from a template declaration. **One or more template arguments is called template instantiation**. 
The definition created from a template instantiation is called a **specialization**. 
The primary template is the template that is being specialized.
 
 
 
10. What is partial template specialization ?

# To deepen

  > Overhead
  
  > RUNTIME vs COMPILE TIME (how it really works)
  
  > Embedded system

