#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	this->brain = new Brain();
	std::cout << "-- Dog default constructor called --" << std::endl;
}

Dog::Dog(std::string type) : Animal(type) {
	std::cout << "-- Dog default (type) constructor called --" << std::endl;
}

Dog::Dog(Dog const &src) : Animal(src) {
	this->brain = new Brain(*src.brain);
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
	delete this->brain;
	std::cout << "-- Dog destructor called --" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "WOOF" <<std::endl;
}

void Dog::setIdea(int index, std::string idea) {
	this->brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
	return (this->brain->getIdea(index));
}
