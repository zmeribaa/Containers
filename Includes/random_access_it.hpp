#pragma once
#include "vector.hpp"
#include "iterator_traits.hpp"

namespace ft{
	template <class T>
	class random_access_it{
		public:
			typedef T value_type;
			typedef typename ft::iterator<std::random_access_iterator_tag, T>::pointer pointer;
			typedef typename ft::iterator<std::random_access_iterator_tag, T>::reference reference;
			typedef typename ft::iterator<std::random_access_iterator_tag, T>::difference_type difference_type;
			typedef typename ft::iterator<std::random_access_iterator_tag, T>::iterator_category iterator_category;

			random_access_it(pointer ptr = 0) : _ptr(ptr) {}
			random_access_it(const random_access_it &copy) : _ptr(copy._ptr) {}
			~random_access_it() {}

			reference operator*() const { return *_ptr; }
			pointer operator->() const { return _ptr; }
			reference operator [](difference_type n) const { return *(_ptr + n); }
			random_access_it &operator++() { _ptr++; return *this; }
			random_access_it operator++(int) { random_access_it tmp(*this); ++(*this); return tmp; }
			random_access_it &operator--() { _ptr--; return *this; }
			random_access_it operator--(int) { random_access_it tmp(*this); --(*this); return tmp; }
			random_access_it &operator+=(difference_type n) { _ptr += n; return *this; }
			random_access_it &operator-=(difference_type n) { _ptr -= n; return *this; }
			random_access_it operator+(difference_type n) const { random_access_it tmp(*this); return tmp += n; }
			random_access_it operator-(difference_type n) const { random_access_it tmp(*this); return tmp -= n; }
			difference_type operator-(const random_access_it &it) const {return _ptr - it._ptr; }
			bool operator==(const random_access_it &it) const { return _ptr == it._ptr; }
			bool operator!=(const random_access_it &it) const { return _ptr != it._ptr; }
			bool operator<(const random_access_it &it) const { return _ptr < it._ptr; }
			bool operator<=(const random_access_it &it) const { return _ptr <= it._ptr; }
			bool operator>(const random_access_it &it) const { return _ptr > it._ptr; }
			bool operator>=(const random_access_it &it) const {return _ptr >= it._ptr; }
		private:
			pointer _ptr;
	};
}


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