#include "./include/Pmerge.hpp"

int main(int argc, char* argv[]) {
	PmergeMe sorter;

	try {
		// On essaie d'exécuter le parsing
		sorter.parseInput(argc, argv);
		sorter.execute();
		// ... le reste de ta logique de tri ...

	} catch (const std::exception& e) {
		// Si une exception est lancée (invalid_argument ou overflow_error)
		// On l'attrape ici et on affiche le message d'erreur
		std::cerr << e.what() << std::endl;
		return (1); // On quitte le programme proprement avec un code d'erreur
	}

	return (0);
}
