#include "Brain.hpp"

Brain::Brain() {
	std::cout << "-- Brain constructor called" << std::endl;
}

Brain::Brain(Brain const &src) {
	std::cout << "-- Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = src.ideas[i];
	}
}

Brain &Brain::operator=(Brain const &other) {
	std::cout << "-- Brain copy assignment operator called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = other.ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "-- Brain destructor called" << std::endl;
}

void Brain::setIdea(int index, std::string idea) {
	this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
	if (index >= 0 && index < 100)
		return (this->ideas[index]);
	return ("");
}
