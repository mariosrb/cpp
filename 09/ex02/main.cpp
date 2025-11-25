#include "./include/Pmerge.hpp"

int main(int argc, char* argv[]) {
	PmergeMe sorter;

	try {
		sorter.parseInput(argc, argv);
		sorter.execute();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}

	return (0);
}
