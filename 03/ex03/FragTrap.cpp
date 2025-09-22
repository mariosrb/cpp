#include "FragTrap.hpp"

FragTrap::FragTrap() {}

FragTrap::FragTrap(const std::string &name): ClapTrap(name) {
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &src): ClapTrap(src) {
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &other) {
	std::cout << "FragTrap copy assignement operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::attack(const std::string &target) {
	if (this->hitPoints == 0 || this->energyPoints == 0) {
		std::cout << "FragTrap" << this->name << " cannot attack (no HP or energy) !" << std::endl;
		return ;
	}
	this->energyPoints--;
	std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << this->name << "asked : can i get a high fives ?" << std::endl;
}
