#include "Bureaucrat.hpp"

int main() {
	std::cout << "===============" << std::endl;
	Bureaucrat bob("Bob", 50);
	std::cout << bob << std::endl;
	bob.incrementGrade();
	std::cout << bob << std::endl;
	bob.decrementGrade();
	std::cout << bob << std::endl;
	try {
		Bureaucrat invalid("Alice", 0);
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try {
		Bureaucrat mark("Mark", 151);
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << "===============" << std::endl;
	try {
		Bureaucrat mario("Mario", 2);
		std::cout << mario << std::endl;
		mario.incrementGrade();
		std::cout << mario << std::endl;
		mario.incrementGrade();
	}
	catch (const std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << "===============" << std::endl;
	Bureaucrat original("Original", 75);
	Bureaucrat copy(original);
	std::cout << "Original: " << original << std::endl;
	std::cout << "Copy: " << copy << std::endl;
	return (0);
}
