#include "./include/RPN.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}

	RPN calculator;
	if (calculator.evaluate(argv[1])){
		std::cout << calculator.getResult() << std::endl;
		return (0);
	}
	return (1);
}
