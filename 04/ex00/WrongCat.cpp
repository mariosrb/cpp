#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "-- WrongCat default constructor called --" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type) {
	std::cout << "-- WrongCat default (type) constructor called --" << std::endl;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src) {
	std::cout << "-- WrongCat copy constructor called --" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &other) {
	std::cout << "-- WrongCat copy operator called --" << std::endl;
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "-- WrongCat destructor called --" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "MEOWW" <<std::endl;
}

