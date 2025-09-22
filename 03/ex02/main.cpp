#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << "=== Construction FragTrap ===" << std::endl;
    FragTrap destroyer("Boom");

    std::cout << "\n=== Test des fonctions héritées ===" << std::endl;
    destroyer.attack("target");
    destroyer.takeDamage(25);
    destroyer.beRepaired(10);

    std::cout << "\n=== Fonction spéciale FragTrap ===" << std::endl;
    destroyer.highFivesGuys();

    std::cout << "\n=== Comparaison avec ClapTrap et ScavTrap ===" << std::endl;
    ClapTrap basic("Basic");
    ScavTrap guard("Guard");

    basic.attack("dummy");   // ClapTrap attack (0 damage)
    guard.attack("dummy");   // ScavTrap attack (20 damage)
    destroyer.attack("dummy"); // Utilise attack() de ClapTrap (30 damage)

    std::cout << "\n=== Test constructeur de copie ===" << std::endl;
    FragTrap copy(destroyer);
    copy.highFivesGuys();

    std::cout << "\n=== Test opérateur d'affectation ===" << std::endl;
    FragTrap assigned("Temp");
    assigned = destroyer;
    assigned.highFivesGuys();

    std::cout << "\n=== Test limites d'énergie FragTrap (100 energy) ===" << std::endl;
    for (int i = 0; i < 102; i++) {
        destroyer.attack("energy_test");
    }

    std::cout << "\n=== Destruction (ordre inverse) ===" << std::endl;
    return 0;
}
