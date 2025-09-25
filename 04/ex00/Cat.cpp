#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "-- Cat default constructor called --" << std::endl;
}

Cat::Cat(std::string type) : Animal(type) {
	std::cout << "-- Cat default (type) constructor called --" << std::endl;
}

Cat::Cat(Cat const &src) : Animal(src) {
	std::cout << "-- Cat copy constructor called --" << std::endl;
}

Cat &Cat::operator=(Cat const &other) {
	std::cout << "-- Cat copy operator called --" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
	}
	return (*this);
}

Cat::~Cat() {
	std::cout << "-- Cat destructor called --" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "MEOWW" <<std::endl;
}
