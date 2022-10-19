1. Vectors are the same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted, with their storage being handled automatically by the container

2. Vector elements are placed in contiguous storage so that they can be accessed and traversed using iterators.

3. In vectors, data is inserted at the end. Inserting at the end takes differential time, as sometimes the array may need to be extended.
Removing the last element takes only constant time because no resizing happens. Inserting and erasing at the beginning or in the middle is linear in time.

Vector contient 7 fonctions :

a. begin() – Returns an iterator pointing to the first element in 	the vector

b. end() – Returns an iterator pointing to the theoretical element that follows the last element in the vector

c. rbegin() – Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element

d. rend() – Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)

e. cbegin() – Returns a constant iterator pointing to the first element in the vector.

f. cend() – Returns a constant iterator pointing to the theoretical element that follows the last element in the vector.
	
g. crbegin() – Returns a constant reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element

h. crend() – Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)

i. size() – Returns the number of elements in the vector.
max_size() – Returns the maximum number of elements that the vector can hold.

j. capacity() – Returns the size of the storage space currently allocated to the vector expressed as number of elements.
resize(n) – Resizes the container so that it contains ‘n’ elements.

k. empty() – Returns whether the container is empty.
shrink_to_fit() – Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity.
reserve() – Requests that the vector capacity be at least enough to contain n elements.

l. reference operator [g] – Returns a reference to the element at position ‘g’ in the vector

m. at(g) – Returns a reference to the element at position ‘g’ in the vector

n. front() – Returns a reference to the first element in the vector

o. back() – Returns a reference to the last element in the vector

p. data() – Returns a direct pointer to the memory array used internally by the vector to store its owned elements.

Subject

• std::iterator_traits
• std::reverse_iterator
• std::enable_if
Yes, it is C++11 but you will be able to implement it in a C++98 manner.
This is asked so you can discover SFINAE.
• std::is_integral
• std::equal and/or std::lexicographical_compare
• std::pair
• std::make_pair
You must use std::allocator.

For non-member overloads, the keyword friend is allowed. Each use of friend
must be justified and will be checked during evaluation.
• Of course, for the implementation of std::map::value_compare, the keyword
friend is allowed