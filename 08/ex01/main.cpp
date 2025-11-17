#include "./include/Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "=======================" << std::endl;

	Span iter = Span(10601);
	std::vector<int> numbers;
	for (int i = 0; i <= 10600; i++) {
		numbers.push_back(i);
	}
	try {
		iter.addNumbers(numbers.begin(), numbers.end());
		std::cout << "Shortest: " << iter.shortestSpan() << std::endl;
		std::cout << "Longest: " << iter.longestSpan() << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
