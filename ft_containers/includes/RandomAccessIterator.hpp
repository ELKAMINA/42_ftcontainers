template <typename T>


class MyRandomAccessIterator
 {
	T* ptr;

	public:
		MyRandomAccessIterator(T* p) : ptr(p)
		{

		}
		// Dereference operator
		T& operator*() { return *ptr; }

		// Increment and decrement operators
		MyRandomAccessIterator& operator++() { ++ptr; return *this; }
		MyRandomAccessIterator& operator--() { --ptr; return *this; }

		// Equality and inequality operators
		bool operator==(const MyRandomAccessIterator& other) const { return ptr == other.ptr; }
		bool operator!=(const MyRandomAccessIterator& other) const { return ptr != other.ptr; }

		// Relational operators
		bool operator<(const MyRandomAccessIterator& other) const { return ptr < other.ptr; }
		bool operator>(const MyRandomAccessIterator& other) const { return ptr > other.ptr; }
		bool operator<=(const MyRandomAccessIterator& other) const { return ptr <= other.ptr; }
		bool operator>=(const MyRandomAccessIterator& other) const { return ptr >= other.ptr; }

		// Offset dereference operator
		T& operator[](std::ptrdiff_t offset) { return *(ptr + offset); }
};
