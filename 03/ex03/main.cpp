#include "DiamondTrap.hpp"

int main() {
    std::cout << "=== Construction DiamondTrap ===" << std::endl;
    DiamondTrap hybrid("Hybrid");

    std::cout << "\n=== Test whoAmI ===" << std::endl;
    hybrid.whoAmI();

    std::cout << "\n=== Test des fonctions héritées ===" << std::endl;
    hybrid.attack("enemy");        // Utilise ScavTrap::attack() avec 30 dégâts
    hybrid.takeDamage(40);
    hybrid.beRepaired(20);

    std::cout << "\n=== Test des fonctions spéciales héritées ===" << std::endl;
    hybrid.guardGate();           // De ScavTrap
    hybrid.highFivesGuys();       // De FragTrap

    std::cout << "\n=== Comparaison des attaques ===" << std::endl;
    ScavTrap scav("Scav");
    FragTrap frag("Frag");

    scav.attack("target");        // ScavTrap: 20 dégâts
    frag.attack("target");        // FragTrap: 30 dégâts
    hybrid.attack("target");      // DiamondTrap: utilise ScavTrap mais 30 dégâts

    std::cout << "\n=== Test constructeur de copie ===" << std::endl;
    DiamondTrap copy(hybrid);
    copy.whoAmI();

    std::cout << "\n=== Test opérateur d'affectation ===" << std::endl;
    DiamondTrap assigned("Temp");
    assigned = hybrid;
    assigned.whoAmI();

    std::cout << "\n=== Destruction (ordre complexe avec héritage multiple) ===" << std::endl;
    return 0;
}
