#include "ScavTrap.hpp"

int main()
{
    std::cout << "=== Construction ===" << std::endl;
    ScavTrap robot("Guardian");

    std::cout << "\n=== Test des fonctions ===" << std::endl;
    robot.attack("intruder");
    robot.takeDamage(30);
    robot.beRepaired(15);
    robot.guardGate();

    std::cout << "\n=== Test constructeur de copie ===" << std::endl;
    ScavTrap copy(robot);

    std::cout << "\n=== Test opérateur d'affectation ===" << std::endl;
    ScavTrap assigned("Temp");
    assigned = robot;

    std::cout << "\n=== Test limites d'énergie ===" << std::endl;
    // Épuiser l'énergie (ScavTrap a 50 points d'énergie)
    for (int i = 0; i < 52; i++) {
        robot.attack("dummy");
    }

    std::cout << "\n=== Destruction (ordre inverse) ===" << std::endl;
    return 0;
}
