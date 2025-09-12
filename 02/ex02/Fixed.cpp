#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
}

Fixed::Fixed(const int n) : value(n * 256) {
}

Fixed::Fixed(const float f) : value((int)(f * 256 + 0.5)) {
}

Fixed::Fixed(Fixed const &src) {
	*this = src;
}

Fixed &Fixed::operator=(Fixed const &other) {
	if (this != &other)
		this->value = other.getRawBits();
	return *this;
}

Fixed::~Fixed() {
}

int Fixed::getRawBits(void) const {
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

Fixed Fixed::operator+(Fixed const &other) const {
	Fixed result;
	result.value = this->value + other.value;
	return (result);
}

Fixed Fixed::operator-(Fixed const &other) const {
	Fixed result;
	result.value = this->value - other.value;
	return (result);
}

Fixed Fixed::operator*(Fixed const &other) const {
	Fixed result;
	result.value = (this->value * other.value) / 256;
	return (result);
}

Fixed Fixed::operator/(Fixed const &other) const {
	Fixed result;
	result.value = (this->value / other.value) * 256;
	return (result);
}

bool Fixed::operator>(Fixed const &other) const {
	return (this->value > other.value);
}

bool Fixed::operator<(Fixed const &other) const {
	return (this->value < other.value);
}

bool Fixed::operator==(Fixed const &other) const {
	return (this->value == other.value);
}

bool Fixed::operator!=(Fixed const &other) const {
	return (this->value != other.value);
}

bool Fixed::operator<=(Fixed const &other) const {
	return (this->value <= other.value);
}

bool Fixed::operator>=(Fixed const &other) const {
	return (this->value >= other.value);
}

Fixed &Fixed:: operator++() {
	this->value += 1;
	return (*this);
}

Fixed Fixed:: operator++(int) {
	Fixed temp = *this;
	this->value += 1;
	return (temp);
}

Fixed &Fixed:: operator--() {
	this->value -= 1;
	return (*this);
}

Fixed Fixed:: operator--(int) {
	Fixed temp = *this;
	this->value -= 1;
	return (temp);
}

Fixed &Fixed::min(Fixed & a, Fixed & b) {
	if (a > b)
		return (b);
	else
		return (a);
}

Fixed const &Fixed::min(Fixed const & a, Fixed const & b) {
	if (a > b)
		return (b);
	else
		return (a);
}

Fixed &Fixed::max(Fixed & a, Fixed & b) {
	if (a < b)
		return (b);
	else
		return (a);
}

Fixed const &Fixed::max(Fixed const & a, Fixed const & b) {
	if (a < b)
		return (b);
	else
		return (a);
}
