#include "Harl.hpp"

void Harl::debug(void) {
	std::cout << "DEBUG" << std::endl;
}

void Harl::info(void) {
	std::cout << "INFO" << std::endl;
}

void Harl::warning(void) {
	std::cout << "WARNING" << std::endl;
}

void Harl::error(void){
	std::cout << "ERROR" << std::endl;
}

void Harl::complain(std::string level) {
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*pointeur[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*pointeur[i])();
			return ;
		}
	}
	std::cout << "Wrong level" << std::endl;
}
