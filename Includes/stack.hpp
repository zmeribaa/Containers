#pragma once

#include "Vector.hpp"

namespace ft {
	 class Stack {
		public:
			Stack();
			Stack(Stack const &src);
			~Stack();

			Stack &operator=(Stack const &rhs);

			bool empty() const;
			size_t size() const;
			int top() const;
			void push(int val);
			void pop();
	 };
}