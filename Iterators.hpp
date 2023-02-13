#include "vector.hpp"

class Iterator {
public:
	Iterator();
	Iterator(Iterator const &src);
	~Iterator();

	Iterator &operator=(Iterator const &rhs);

	bool operator==(Iterator const &rhs) const ;
	bool operator!=(Iterator const &rhs) const;
	bool operator<(Iterator const &rhs) const;
	bool operator<=(Iterator const &rhs) const;
	bool operator>(Iterator const &rhs) const;
	bool operator>=(Iterator const &rhs) const;

	Iterator &operator++();
	Iterator operator++(int);
	Iterator &operator--();
	Iterator operator--(int);

	int &operator*() const;
	int *operator->() const;
};

/* The operator in the iterator class in C++ refers to the various overloaded operators that allow you to manipulate iterators and access the elements they point to.

Here are some common iterator operators in C++:

Dereference operator *: Returns a reference to the element pointed to by the iterator.
Member selection operator ->: Returns a pointer to the element pointed to by the iterator, allowing you to call member functions or access members of the element.
Increment operator ++: Advances the iterator to the next element in the container.
Decrement operator --: Moves the iterator to the previous element in the container.
Equality operators == and !=: Compare two iterators for equality, indicating whether they point to the same location in the container.
Relational operators <, <=, >, and >=: Compare two iterators for their relative positions in the container.
These operators make it easy to traverse and manipulate elements in a container using iterators, and they form the basis for many algorithms in the C++ Standard Library.
Chokrane Chat Gpt*/