#include "Harl.hpp"

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cout << "Invalid number of arguments. Must be 2" << std::endl;
		return (-1);
	}
	std::string level = argv[1];
	int			nbLevel = string_to_int(level);
	Harl	harl;
	switch (nbLevel) {
		case 0:
			harl.debug();
		case 1:
			harl.info();
		case 2:
			harl.warning();
		case 3:
			harl.error();
			break;
		default:
			std::cout << "Invalid Input" << std::endl;
	}
	return 0;
}
