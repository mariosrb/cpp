#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : value(n * 256) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : value((int)(f * 256 + 0.5)) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(Fixed const &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->value = other.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw) {
	this->value = raw;
}

float Fixed::toFloat(void) const {
	return ((float)this->value / 256.0f);
}

int Fixed::toInt(void) const {
	return ((int)this->value / 256);
}

std::ostream &operator<<(std::ostream &os, const Fixed &i) {
	os << i.toFloat();
	return (os);
}
