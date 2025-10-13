#include "./include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string literal) {
	TYPE t = parse_arg(literal);
	switch (t) {
		case CHAR:
		{
			char c = literal[0];
			int i = static_cast<int>(c);
			float f = static_cast<float>(c);
			double d = static_cast<double>(c);
			std::cout << "char: '" << c << "'" << std::endl;
			std::cout << "int: " << i << std::endl;
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float: " << f << "f" << std::endl;
			std::cout << "double: " << d << std::endl;
			break;
		}
		case INT:
		{
			int i = std::atoi(literal.c_str());
			char c = static_cast<char>(i);
			float f = static_cast<float>(i);
			double d = static_cast<double>(i);
			break;
		}
		case FLOAT:
		{
			float f = std::atof(literal.c_str());
			char c = static_cast<char>(f);
			double d = static_cast<double>(f);
			int i = static_cast<int>(f);
			break;
		}
		case DOUBLE:
		{
			double d = std::atof(literal.c_str());
			int i = static_cast<int>(d);
			float f = static_cast<float>(d);
			char c = static_cast<char>(d);
			break;
		}
		case PSEUDO_FLOAT:
		case PSEUDO_DOUBLE:
		{
			break;
		}
		default:
			std::cout << "Invalid literal" << std::endl;
	}
}
