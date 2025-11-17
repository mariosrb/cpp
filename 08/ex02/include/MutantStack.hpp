#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <list>

template <typename T>
class MutantStack : public std::stack<T> {
	private:

	public:
		MutantStack() : std::stack<T>() {}
		MutantStack(const MutantStack& to_copy) : std::stack<T>(to_copy) {}
		MutantStack& operator=(const MutantStack& to_copy) {
			std::stack<T>::operator=(to_copy);
			return *this;
		}
		~MutantStack() {}

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		iterator begin() {
			return this->c.begin();
		}

		iterator end() {
			return this->c.end();
		}

		const_iterator begin() const {
			return this->c.begin();
		}

		const_iterator end() const {
			return this->c.end();
		}
};

#endif

