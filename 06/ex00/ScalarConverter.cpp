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
			if (std::isprint(c))
				std::cout << "char: '" << c << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
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
			if (std::isprint(c))
				std::cout << "char: '" << c << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
			std::cout << "int: " << i << std::endl;
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float: " << f << "f" << std::endl;
			std::cout << "double: " << d << std::endl;
			break;
		}
		case FLOAT:
		{
			float f = std::atof(literal.c_str());
			char c = static_cast<char>(f);
			double d = static_cast<double>(f);
			int i = static_cast<int>(f);
			if (std::isprint(c))
				std::cout << "char: '" << c << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
			std::cout << "int: " << i << std::endl;
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float: " << f << "f" << std::endl;
			std::cout << "double: " << d << std::endl;
			break;
		}
		case DOUBLE:
		{
			double d = std::atof(literal.c_str());
			int i = static_cast<int>(d);
			float f = static_cast<float>(d);
			char c = static_cast<char>(d);
			if (std::isprint(c))
				std::cout << "char: '" << c << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
			std::cout << "int: " << i << std::endl;
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float: " << f << "f" << std::endl;
			std::cout << "double: " << d << std::endl;
			break;
		}
		case PSEUDO_FLOAT:
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << literal << std::endl;
			std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
			break;
		}
		case PSEUDO_DOUBLE:
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << literal << "f" << std::endl;
			std::cout << "double: " << literal << std::endl;
			break;
		}
		default:
			std::cout << "Invalid literal" << std::endl;
	}
}
