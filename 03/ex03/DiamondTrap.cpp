#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap() {
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 30;
	std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap(src), FragTrap(), ScavTrap() {
	*this = src;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		this->name = other.name;
	}
	return (*this);
}

void DiamondTrap::whoAmI() {
	std::cout << "My name is " << this->name << std::endl;
	std::cout << "My ClapTrap name is " << ClapTrap::name << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}
