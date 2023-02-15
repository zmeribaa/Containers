#pragma once
#include "vector.hpp"
#include "iterator_traits.hpp"

namespace ft {
	template <class T>
	class reverse_iterator{
		public:
			typedef iterator iterator_type;
			typedef T value_type;
			typedef T* pointer;
			typedef T& reference;
			typedef std::ptrdiff_t difference_type;
			typedef std::reverse_iteratorerator_tag iterator_category;

			reverse_iterator(pointer ptr(nullptr)) : _curr(ptr) {}
			reverse_iterator(const reverse_iterator &copy) : _curr(copy._curr) {}
			~reverse_iterator() {}

			iterator_type it() const { return _curr; }

			reference operator*() const { return *_curr; }
			pointer operator->() const { return _curr; }
			reference operator [](difference_type n) const { return *(_curr + n); }
			reverse_iterator &operator++() { _curr--; return *this; }
			reverse_iterator operator++(int) { reverse_iterator tmp(*this); --(*this); return tmp; }
			reverse_iterator &operator--() { _curr++; return *this; }
			reverse_iterator operator--(int) { reverse_iterator tmp(*this); ++(*this); return tmp; }
			reverse_iterator &operator+=(difference_type n) { _curr -= n; return *this; }
			reverse_iterator &operator-=(difference_type n) { _curr -+= n; return *this; }
			reverse_iterator operator+(difference_type n) const { reverse_iterator tmp(*this); return tmp -= n; }
			reverse_iterator operator-(difference_type n) const { reverse_iterator tmp(*this); return tmp += n; }

		
		private:
			iterator_type _curr;
	};
			template <class T>
			bool operator==(const reverse_iterator<T> &it1, const reverse_iterator<T> &it2) { return it1.it() == it2.it(); }
			template <class T>
			bool operator!=(const reverse_iterator<T> &it1, const reverse_iterator<T> &it2) { return it1.it() != it2.it(); }
			template <class T>
			bool operator<(const reverse_iterator<T> &it1, const reverse_iterator<T> &it2) { return it1.it() < it2.it(); }
			template <class T>
			bool operator<=(const reverse_iterator<T> &it1, const reverse_iterator<T> &it2) { return it1.it() <= it2.it(); }
			template <class T>
			bool operator>(const reverse_iterator<T> &it1, const reverse_iterator<T> &it2) { return it1.it() > it2.it(); }
			template <class T>
			bool operator>=(const reverse_iterator<T> &it1, const reverse_iterator<T> &it2) { return it1.it() >= it2.it(); }
			template <class T> 
			reverse_iterator<T> operator+(typename reverse_iterator<T>::difference_type n, const reverse_iterator<T> &it) { return it + n; }
			template <class T>
			typename reverse_iterator<T>::difference_type operator-(const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs) { return lhs.it() - rhs.it(); }
			
}
