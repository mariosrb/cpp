#include "Harl.hpp"

void Harl::debug(void) {
	std::cout << "I love sushi" << std::endl;
}

void Harl::info(void) {
	std::cout << "But i prefer las vegas" << std::endl;
}

void Harl::warning(void) {
	std::cout << "Not the city, cause i hate america" << std::endl;
}

void Harl::error(void){
	std::cout << "Reboot" << std::endl;
}

int	string_to_int(std::string level) {
	if (level == "DEBUG")
		return (0);
	else if (level == "INFO")
		return (1);
	else if (level == "WARNING")
		return (2);
	else if (level == "ERROR")
		return (3);
	return (-1);
}
