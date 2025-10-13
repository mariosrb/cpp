#include "./include/ScalarConverter.hpp"
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string literal) {
	TYPE t = parse_arg(literal);
	
}
