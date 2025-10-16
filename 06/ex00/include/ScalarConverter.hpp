#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <climits>

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

	private:
		ScalarConverter();
		~ScalarConverter();
	public:
		static void convert(std::string literal);
};

TYPE	parse_arg(std::string input);
int 	valid_digit_around_point(std::string input);
int		has_point(std::string input);
int		ends_with_f(std::string input);

#endif
