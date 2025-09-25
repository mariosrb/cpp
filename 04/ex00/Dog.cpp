#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "-- Dog default constructor called --" << std::endl;
}

Dog::Dog(std::string type) : Animal(type) {
	std::cout << "-- Dog default (type) constructor called --" << std::endl;
}

Dog::Dog(Dog const &src) : Animal(src) {
	std::cout << "-- Dog copy constructor called --" << std::endl;
}

Dog &Dog::operator=(Dog const &other) {
	std::cout << "-- Dog copy operator called --" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << "-- Dog destructor called --" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "WOOF" <<std::endl;
}
