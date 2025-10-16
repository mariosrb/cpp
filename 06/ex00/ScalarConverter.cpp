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
			long val = std::atol(literal.c_str());

			if (val > INT_MAX || val < INT_MIN) {
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: impossible" << std::endl;
				std::cout << "double: impossible" << std::endl;
				break;
    		}

			int i = std::atoi(literal.c_str());
			char c = static_cast<char>(i);
			float f = static_cast<float>(i);
			double d = static_cast<double>(i);

			if (i >= 0 && i <= 127 && std::isprint(c))
				std::cout << "char: '" << c << "'" << std::endl;
			else if (i >= 0 && i <= 127)
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: impossible" << std::endl;

			std::cout << "int: " << i << std::endl;
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float: " << f << "f" << std::endl;
			std::cout << "double: " << d << std::endl;
			break;

		}
		case FLOAT:
		{
			float f = std::atof(literal.c_str());
			if (f >= 0 && f <= 127 && std::isprint(static_cast<char>(f)))
				std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
			else if (f >= 0 && f <= 127)
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: impossible" << std::endl;
			if (f > INT_MAX || f < INT_MIN)
				std::cout << "int: impossible" << std::endl;
			else
				std::cout << "int: " << static_cast<int>(f) << std::endl;
			double d = static_cast<double>(f);

			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float: " << f << "f" << std::endl;
			std::cout << "double: " << d << std::endl;
			break;
		}
		case DOUBLE:
		{
			double d = std::atof(literal.c_str());

			if (d >= 0 && d <= 127 && std::isprint(static_cast<char>(d)))
				std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
			else if (d >= 0 && d <= 127)
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: impossible" << std::endl;
				
			if (d > INT_MAX || d < INT_MIN)
				std::cout << "int: impossible" << std::endl;
			else
				std::cout << "int: " << static_cast<int>(d) << std::endl;

			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
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
