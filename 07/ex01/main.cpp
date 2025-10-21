#include "./include/inter.hpp"


int main() {
	// Test 1 : Tableau d'int avec affichage
	int tab1[] = {1, 2, 3, 4, 5};
	std::cout << "Print int array:" << std::endl;
	iter(tab1, 5, printInt);

	// Test 2 : Tableau d'int avec modification
	std::cout << "\nIncrement array:" << std::endl;
	iter(tab1, 5, increment);
	iter(tab1, 5, printInt);  // Affiche pour voir le résultat

	// Test 3 : Tableau de string
	std::string tab2[] = {"hello", "world", "42"};
	std::cout << "\nPrint string array:" << std::endl;
	iter(tab2, 3, print<std::string>);

	// Test 4 : Modifier les strings
	std::cout << "\nUppercase strings:" << std::endl;
	iter(tab2, 3, toUpper);
	iter(tab2, 3, print<std::string>);

	// Test 5 : Tableau de float
	float tab3[] = {1.1f, 2.2f, 3.3f};
	std::cout << "\nPrint float array:" << std::endl;
	iter(tab3, 3, print<float>);

	return 0;
}
