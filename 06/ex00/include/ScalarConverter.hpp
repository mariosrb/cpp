#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

enum TYPE {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO_FLOAT,
	PSEUDO_DOUBLE,
	INVALID
};

class ScalarConverter {
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter & operator=(ScalarConverter const &other);
		~ScalarConverter();
};

#endif
