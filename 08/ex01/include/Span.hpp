#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Span {
	public:
		Span();
		Span(const Span& to_copy);
		Span(unsigned int n);
		Span& operator=(const Span& to_copy);
		~Span();
		void addNumber(int value);
		template <typename InputIterator>
		void addNumbers(InputIterator begin, InputIterator end) {
			size_t count = std::distance(begin, end);
			if (numbers.size() + count > N)
				throw std::runtime_error("Not enough space");
			numbers.insert(numbers.end(), begin, end);
		}
		int shortestSpan();
		int longestSpan();

	private:
		unsigned int 		N;
		std::vector<int> 	numbers;

};
#endif
