#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

private:
	static const int	fractionalBits = 8;
	int					value;

public:
	Fixed();
	Fixed(Fixed const & src);
	Fixed & operator=(Fixed const & other);
	Fixed(const int n);
	Fixed(const float f);
	Fixed operator+(Fixed const & other) const;
	Fixed operator-(Fixed const & other) const;
	Fixed operator*(Fixed const & other) const;
	Fixed operator/(Fixed const & other) const;
	bool operator>(Fixed const & other) const;
	bool operator<(Fixed const & other) const;
	bool operator==(Fixed const &other) const;
	bool operator!=(Fixed const &other) const;
	bool operator<=(Fixed const &other) const;
	bool operator>=(Fixed const &other) const;
	Fixed & operator++();
	Fixed operator++(int);
	Fixed & operator--();
	Fixed operator--(int);
	static Fixed & min(Fixed & a, Fixed & b);
	static Fixed const & min(Fixed const & a, Fixed const & b);
	static Fixed & max(Fixed & a, Fixed & b);
	static Fixed const & max(Fixed const & a, Fixed const & b);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

};

std::ostream& operator<<(std::ostream& os, const Fixed& i);


#endif
