#ifndef	VECTOR_CLASS_HPP
# define VECTOR_CLASS_HPP

template<typename T>
class Vector
{
// arr is the integer pointer
// which stores the address of our vector
	T* arr;

	// capacity is the total storage
	// capacity of the vector
	int capacity;

	// current is the number of elements
	// currently present in the vector
	int current;
	
	public:
		// Default constructor to initialise
		// an initial capacity of 1 element and
		// allocating storage using dynamic allocation
	vectorClass()
	{
		arr = new T[1];
		capacity = 1;
		// current is the number of elements
    	// currently present in the vector
		current = 0;
	}
	//destructor to deallocate storage allocated by dynamic allocation
	//to prevent memory leak
	~ vectorClass()
	{
		delete [] arr;
	}

	// Function to add an element at the last
	void push(T data)
	{

		// if the number of elements is equal to the
		// capacity, that means we don't have space to
		// accommodate more elements. We need to double the
		// capacity
		if (current == capacity) {
			T* temp = new T[2 * capacity];

			// copying old array elements to new array
			for (int i = 0; i < capacity; i++) {
				temp[i] = arr[i];
			}

			// deleting previous array
			delete[] arr;
			capacity *= 2;
			arr = temp;
		}

		// Inserting data
		arr[current] = data;
		current++;
	}

	// function to add element at any index
	void push(T data, int index)
	{

		// if index is equal to capacity then this
		// function is same as push defined above
		if (index == capacity)
			push(data);
		else
			arr[index] = data;
	}

	// function to extract element at any index
	T get(int index)
	{

		// if index is within the range
		if (index < current)
			return arr[index];
	}

	// function to delete last element
	void pop() { current--; }

	// function to get size of the vector
	int size() { return current; }

	void resize(size_type n)
	{
		// Resizes the container so that it contains n elements.

		// If n is smaller than the current container size, the content is reduced to its first n elements, removing those beyond (and destroying them).
		if (n < current)
		{
			T* temp = new T[n];
			for (size_t i = 0; i < n; i++)
			{
				temp[i] = arr[i];
			}
			delete [] arr;
			capacity = n;
			current = n;
			arr =  tmp;
		}
		else if (n > current)
		{
			T* tmp = new T
			for (size_t i = 0; i < (n - current); i++)
			{
				push()
			}
			
		}
		
		// If n is greater than the current container size, the content is expanded by inserting at the end as many elements as needed to reach a size of n. If val is specified, the new elements are initialized as copies of val, otherwise, they are value-initialized.

		// If n is also greater than the current container capacity, an automatic reallocation of the allocated storage space takes place.

		// Notice that this function changes the actual content of the container by inserting or erasing elements from it.




		// if the number of elements is equal to the
		// capacity, that means we don't have space to
		// accommodate more elements. We need to double the
		// capacity
		if (current == capacity) {
			
		}

		// Inserting data
		arr[current] = data;
		current++;
	}

	// function to get capacity of the vector
	int getcapacity() { return capacity; }

	// function to print array elements
	void print()
	{
		for (int i = 0; i < current; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};



#endif