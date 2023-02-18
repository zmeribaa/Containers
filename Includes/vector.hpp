#pragma once 

#include <string>
#include <iostream>

#include "vector.hpp"
#include "random_access_it.hpp"
#include "reverse_iterators.hpp"
#include "iterator_traits.hpp"

namespace  ft {
template <class T, class Allocator = std::allocator<T> >
	class vector {
		public:
// types:
			typedef typename Allocator::reference reference;
			typedef typename Allocator::const_reference const_reference;
			typedef ft::random_access_it<T> iterator; // See 23.1
			typedef ft::random_access_it<const T> const_iterator; // See 23.1
			typedef size_t size_type; // See 23.1
			// typedef implementation defined difference_type;// See 23.1
			typedef T value_type;
			typedef Allocator allocator_type;
			typedef typename Allocator::pointer pointer;
			typedef typename Allocator::const_pointer const_pointer;
			// typedef ft::reverse_iterator<iterator> reverse_iterator;
			// typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

			// 23.2.4.1 construct/copy/destroy:
			explicit vector(const Allocator& = Allocator())
			{
				_data = _alloc.allocate(0);
				_size = 0;
				_capacity = 0;
			}
			explicit vector(size_type n, const T& value = T(),
			const Allocator& = Allocator());
			template <class InputIterator>
			vector(InputIterator first, InputIterator last,
			const Allocator& = Allocator());
			vector(const vector<T,Allocator>& x);
			~vector();
			vector<T,Allocator>& operator=(const vector<T,Allocator>& x);
			template <class InputIterator>
			void assign(InputIterator first, InputIterator last);
			void assign(size_type n, const T& u);
			allocator_type get_allocator() const;
			// iterators:
			iterator begin();
			const_iterator begin() const;
			iterator end();
			const_iterator end() const;
			// reverse_iterator rbegin();
			// const_reverse_iterator rbegin() const;
			// reverse_iterator rend();
			// const_reverse_iterator rend() const;
			// 23.2.4.2 capacity:
			size_type size() const
			{
				return (_size);
			}
			size_type max_size() const
			{
				return (_alloc.max_size());
			}
			void resize(size_type sz, T c = T());
			size_type capacity() const
			{
				return (_capacity);
			}
			bool empty() const
			{
				return (_size == 0);
			}
			void reserve(size_type n)
			{
				if (n > _capacity)
					{
						pointer tmp = _alloc.allocate(n);
						for (size_type i = 0 ; i < _size ; i++)
						{
							_alloc.construct(&tmp[i], _data[i]);
							_alloc.destroy(&_data[i]);
						}
						_alloc.deallocate(_data, _capacity);
						_data = tmp;
						_capacity = n; 
					}
			}
			// element access:
			reference operator[](size_type n);
			const_reference operator[](size_type n) const;
			const_reference at(size_type n) const;
			reference at(size_type n);
			reference front();
			const_reference front() const;
			reference back();
			const_reference back() const;
			// 23.2.4.3 modifiers:
			void push_back(const T& x);
			void pop_back();
			iterator insert(iterator position, const T& x);
			void insert(iterator position, size_type n, const T& x);
			template <class InputIterator>
			void insert(iterator position,
			InputIterator first, InputIterator last);
			iterator erase(iterator position);
			iterator erase(iterator first, iterator last);
			void swap(vector<T,Allocator>&);
			void clear()
			{
				for (size_type i = 0 ; i < _size ; i++)
					_alloc.destroy(&_data[i]);
				_size = 0;
			}
		private:
				allocator_type _alloc;
				size_type _size;
				size_type _capacity;
				pointer _data;


			};
			//
			template <class T, class Allocator>
			bool operator==(const vector<T,Allocator>& x,
			const vector<T,Allocator>& y);
			template <class T, class Allocator>
			bool operator< (const vector<T,Allocator>& x,
			const vector<T,Allocator>& y);
			template <class T, class Allocator>
			bool operator!=(const vector<T,Allocator>& x,
			const vector<T,Allocator>& y);
			template <class T, class Allocator>
			bool operator> (const vector<T,Allocator>& x,
			const vector<T,Allocator>& y);
			template <class T, class Allocator>
			bool operator>=(const vector<T,Allocator>& x,
			const vector<T,Allocator>& y);
			template <class T, class Allocator>
			bool operator<=(const vector<T,Allocator>& x,
			const vector<T,Allocator>& y);
			// specialized algorithms:
			template <class T, class Allocator>
			void swap(vector<T,Allocator>& x, vector<T,Allocator>& y);
}