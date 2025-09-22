#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {

private:
	std::string name;

public:
	DiamondTrap();
	DiamondTrap(const std::string &name);
	DiamondTrap(DiamondTrap const & src);
	DiamondTrap & operator=(DiamondTrap const & other);
	void whoAmI();
	~DiamondTrap();
	void attack(const std::string& target);
};

#endif
