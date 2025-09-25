#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "-- WrongAnimal default constructor called --" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
	std::cout << "-- WrongAnimal default (type) constructor called --" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src) : type(src.type) {
	std::cout << "-- WrongAnimal copy constructor called --" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "-- WrongAnimal destructor called --" << std::endl;
}

std::string WrongAnimal::getType() const {
	return (this->type);
}

void WrongAnimal::setType(const std::string type) {
	this->type = type;
}

void WrongAnimal::makeSound() const {
	std::cout << "An WrongAnimal made a sound" << std::endl;
}
