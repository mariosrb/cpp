#include "ClapTrap.hpp"

int main() {
    // Test du constructeur
    ClapTrap robot("Bob");

    // Test des fonctions de base
    robot.attack("target dummy");
    robot.takeDamage(3);
    robot.beRepaired(2);

    std::cout << "\n--- Tests limites ---" << std::endl;

    // Épuiser l'énergie
    for (int i = 0; i < 10; i++) {
        robot.attack("enemy");
    }

    // Plus d'énergie, ne peut plus attaquer/réparer
    robot.attack("another enemy");
    robot.beRepaired(5);

    // Test avec dégâts mortels
    ClapTrap robot2("Alice");
    robot2.takeDamage(15); // Plus que ses 10 HP
    robot2.attack("ghost"); // Ne peut plus attaquer (0 HP)

    return 0;
}
