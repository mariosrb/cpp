#include "Aanimal.hpp"

Aanimal::Aanimal() {
	std::cout << "-- Aanimal default constructor called --" << std::endl;
}

Aanimal::Aanimal(std::string type) : type(type) {
	std::cout << "-- Aanimal default (type) constructor called --" << std::endl;
}

Aanimal::Aanimal(Aanimal const &src) : type(src.type) {
	std::cout << "-- Aanimal copy constructor called --" << std::endl;
}

Aanimal &Aanimal::operator=(Aanimal const &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Aanimal::~Aanimal() {
	std::cout << "-- Aanimal destructor called --" << std::endl;
}

std::string Aanimal::getType() const {
	return (this->type);
}

void Aanimal::setType(const std::string type) {
	this->type = type;
}

// void Aanimal::makeSound() const {
// 	std::cout << "An aanimal made a sound" << std::endl;
// }
