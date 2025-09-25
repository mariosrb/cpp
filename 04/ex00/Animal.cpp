#include "Animal.hpp"

Animal::Animal() {
	std::cout << "-- Animal default constructor called --" << std::endl;
}

Animal::Animal(std::string type) : type(type) {
	std::cout << "-- Animal default (type) constructor called --" << std::endl;
}

Animal::Animal(Animal const &src) : type(src.type) {
	std::cout << "-- Animal copy constructor called --" << std::endl;
}

Animal &Animal::operator=(Animal const &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Animal::~Animal() {
	std::cout << "-- Animal destructor called --" << std::endl;
}

std::string Animal::getType() const {
	return (this->type);
}

void Animal::setType(const std::string type) {
	this->type = type;
}

void Animal::makeSound() const {
	std::cout << "An animal made a sound" << std::endl;
}
