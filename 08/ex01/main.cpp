#include "./include/Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;

	try {
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
	catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

	std::cout << "===========  Test addNumbers avec gros vecteur  ============" << std::endl;

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

	std::cout << "\n===== Test exceptions addNumber =====" << std::endl;
    Span s1(3);
    try {
        s1.addNumber(1);
        s1.addNumber(2);
        s1.addNumber(3);
        s1.addNumber(4);
    }
	catch (std::exception &e) {
        std::cout << "Exception addNumber: " << e.what() << std::endl;
    }

	std::cout << "\n===== Test exceptions shortestSpan/longestSpan =====" << std::endl;
    Span s2(5);
    s2.addNumber(10);
    try {
        s2.shortestSpan();
    }
	catch (std::exception &e) {
        std::cout << "Exception shortestSpan: " << e.what() << std::endl;
    }

    try {
        s2.longestSpan();
    }
	catch (std::exception &e) {
        std::cout << "Exception longestSpan: " << e.what() << std::endl;
    }

	return 0;
}
