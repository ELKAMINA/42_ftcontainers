#include "./Vector.hpp"
#include <iostream>
#include <iomanip>
#include <string>

template<typename T>
Vector::Vector<T>( void )
{
	arr = new T[1];
	capacity = 1;
	current = 0;
}

Vector::~Vector<T>()
{
	delete [] arr;
}

void Vector::push(T data)
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

void Vector::push(T data, int index)
{
	// if index is within the range
	if (index < current)
		return arr[index];
}

void Vector::pop(T data, int index)
{
	current--;
}

void Vector::pop(T data, int index)
{
	current--;
}

void Vector::getcapacity()
{
	capacity;
}

void Vector::print()
{
	for (int i = 0; i < current; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}