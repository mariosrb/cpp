#include "./include/ScalarConverter.hpp"
#include <cctype>

TYPE	parse_arg(std::string input)
{
	if (input.length() == 3 && input[0] == '\'' && input[2] == '\'')
		return (CHAR);
	else if (input == "nan" || input == "+inf" || input == "-inf")
		return (PSEUDO_DOUBLE);
	else if (input == "nanf" || input == "+inff" || input == "-inff")
		return (PSEUDO_FLOAT);


}

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Error, must be 1 arguments : ./a.out arg" << std::endl;
	}
	parse_arg((std::string)argv[1]);

}
