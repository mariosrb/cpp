#include "./include/ScalarConverter.hpp"
#include <cctype>

int	ends_with_f(std::string input)
{
	size_t size = input.size();

	if (input[size - 1] == 'f')
		return (1);
	return (0);
}

int	has_point(std::string input)
{
	if (input.find('.') != std::string::npos)
		return (1);
	return (0);
}

int valid_digit_around_point(std::string input)
{
	size_t pos = input.find('.');
	size_t end = input.size();
	size_t start = 0;
	char last = input[input.size() - 1];

	if (last == 'f')
		end = input.size() - 1;
	if (input[0] == '+' || input[0] == '-')
		start = 1;
	if (pos == 0 || pos == start)
		return (0);
	if (pos + 1 >= end)
		return (0);
	for (size_t i = start; i < pos; i++) {
		if (!std::isdigit(input[i]))
			return (0);
	}
	for (size_t i = pos + 1; i < end; i++) {
		if (!std::isdigit(input [i]))
			return (0);
	}
	return (1);
}

TYPE	parse_arg(std::string input)
{
	bool	isInt = true;
	size_t 	size = input.size();

	if (input == "nan" || input == "+inf" || input == "-inf")
		return (PSEUDO_DOUBLE);
	else if (input == "nanf" || input == "+inff" || input == "-inff")
		return (PSEUDO_FLOAT);
	else if (ends_with_f(input) && has_point(input) && valid_digit_around_point(input))
		return (FLOAT);
	else if (!ends_with_f(input) && has_point(input) && valid_digit_around_point(input))
		return (DOUBLE);

	if (!input.empty()) {
		size_t start = 0;
		if (input[0] == '-' || input[0] == '+')
			start = 1;
		for (size_t i = start; i < size; i++) {
			if (!std::isdigit(input[i])) {
				isInt = false;
				break;
			}
		}
		if (isInt && start < size)
			return (INT);
	}

	if (input.length() == 1)
		return (CHAR);

	return (INVALID);
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Error, must be 1 arguments : ./a.out arg" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
