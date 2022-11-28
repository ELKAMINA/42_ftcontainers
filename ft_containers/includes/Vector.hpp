#ifndef	VECTOR_CLASS_HPP
# define VECTOR_CLASS_HPP

#include <string>
#include <iostream>
#include <iomanip>

template<typename T>
class ft_vector
{
	private :
		// arr is the size_teger posize_ter which stores the address of our vector
		T* arr;

		// capacity is the total storage capacity of the vector
		size_t capacity;

		// current is the number of element currently present in the vector
		size_t current;

		void Realloc(size_t newCapacity)
		{
			T* block = new T[newCapacity];

			// std::cout << "NEW CAPACITY : " << newCapacity << std::endl;
			for (size_t i = 0; i < (size_t)current; i++)
			{
				block[i] = arr[i];
				// std::cout << "block  : "<< block[i] << std::endl;

			}
			delete[] arr;
			arr = block;
			capacity = newCapacity;
		}

		void Realloc_and_assign(size_t newCapacity, T val)
		{
			T* block = new T[newCapacity];

			for (size_t i = 0; i < newCapacity; i++)
			{
				block[i] = arr[i];
			}
			for (size_t i = current; i < (newCapacity - current); i++)
			{
				block[i] = val;
			}
		}
	
	public:
		MyVector()
		{
			arr = new T[1];
			capacity = 1;
			current = 0;
		}

		~ MyVector()
		{
			delete [] arr;
		}

		T &MyVector<T>::operator[](size_t pos) {
			if (pos >= 0 &&  pos <= current)
				return *(this->arr + pos);
			throw std::out_of_range("Out of bounds element access");
		}
		// Function to add an element at the last
		void push(T data)
		{
			// std::cout << " je rentre ici " << std::endl;
			// if the number of elements is equal to the
			// capacity, that means we don't have space to
			// accommodate more elements. We need to double the
			// // capacity
			// std::cout << "current " << current << std::endl;
			// std::cout << "capacity " << capacity << std::endl;
			// std::cout << "DATA : " << data << std::endl;
			if (current == capacity)
				this->Realloc(2 * capacity);
				// deleting previous array
			// Inserting data
			arr[current] = data;
			current++;
		}

		// function to add element at any index
		void push(T data, size_t index)
		{
			// if index is equal to capacity then this
			// function is same as push defined above
			if (index == capacity)
				push(data);
			else
				arr[index] = data;
		}

		// function to extract element at any index
		T get(size_t index)
		{

			// if index is within the range
			if (index < current)
				return arr[index];
		}

		// function to delete last element
		void pop()
		{ 
			current--; 
		}

		// function to get size of the vector
		size_t size() 
		{ 
			return current;
		}

		void resize(size_t n)
		{
			// Resizes the container so that it contains n elements.

			// If n is smaller than the current container size, the content is reduced to its first n elements, removing those beyond (and destroying them).
			if (n < current)
			{
				std::cout << "Here " << std::endl;
				current = n;
				this->Realloc(n);
			}
			else if (n > current)
			{
				if	(n > capacity)
					capacity = n;
				this->Realloc(n);
				for (size_t i = current; i < n; i++)
					push(0);
			}
			// If n is greater than the current container size, the content is expanded by inserting at the end as many elements as needed to reach a size of n. If val is specified, the new elements are initialized as copies of val, otherwise, they are value-initialized.

			// If n is also greater than the current container capacity, an automatic reallocation of the allocated storage space takes place.

			// Notice that this function changes the actual content of the container by inserting or erasing elements from it.




			// if the number of elements is equal to the
			// capacity, that means we don't have space to
			// accommodate more elements. We need to double the
			// capacity
		}

		void resize(size_t n, T value)
		{
			// Resizes the container so that it contains n elements.

			// If n is smaller than the current container size, the content is reduced to its first n elements, removing those beyond (and destroying them).
			if (n < current)
			{
				std::cout << "Here " << std::endl;
				current = n;
				this->Realloc(n);
			}
			else if (n > current)
			{
				if	(n > capacity)
					capacity = n;
				this->Realloc(n);
				for (size_t i = current; i < n; i++)
					push(value);
			}
			// If n is greater than the current container size, the content is expanded by inserting at the end as many elements as needed to reach a size of n. If val is specified, the new elements are initialized as copies of val, otherwise, they are value-initialized.

			// If n is also greater than the current container capacity, an automatic reallocation of the allocated storage space takes place.

			// Notice that this function changes the actual content of the container by inserting or erasing elements from it.




			// if the number of elements is equal to the
			// capacity, that means we don't have space to
			// accommodate more elements. We need to double the
			// capacity
		}

		size_t getcapacity()
		{
			return capacity;
		}

		void print()
		{
			for (size_t i = 0; i < current; i++) {
				std::cout << arr[i] << " ";
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
};



#endif