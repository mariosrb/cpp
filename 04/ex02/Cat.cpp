#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	this->brain = new Brain();
	std::cout << "-- Cat default constructor called --" << std::endl;
}

Cat::Cat(std::string type) : Animal(type) {
	std::cout << "-- Cat default (type) constructor called --" << std::endl;
}

Cat::Cat(Cat const &src) : Animal(src) {
	this->brain = new Brain(*src.brain);
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
	delete this->brain;
	std::cout << "-- Cat destructor called --" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "MEOWW" <<std::endl;
}

void Cat::setIdea(int index, std::string idea) {
	this->brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
	return (this->brain->getIdea(index));
}
