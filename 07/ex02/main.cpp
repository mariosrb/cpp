#include "./include/Array.hpp"

int main(void)
{
	std::cout << "===== Test 1: Empty array ===" << std::endl;
	Array<int> empty;
	std::cout << "Size: " << empty.size() << std::endl;
	std::cout << std::endl;



	std::cout << "===== Test 2: Array 5 size ===" << std::endl;
	Array<int> numbers(5);
	for (unsigned int i = 0; i < numbers.size(); i++) {
		numbers[i] = i * 10;
	}
	std::cout << "Content: ";
	for (unsigned int i = 0; i < numbers.size(); i++) {
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;



	std::cout << "=== Test 3: Deep copy ===" << std::endl;
	Array<int> copy(numbers);

	std::cout << "Original[0]: " << numbers[0] << std::endl;
	std::cout << "Copy[0]: " << copy[0] << std::endl;

	copy[0] = 999;

	std::cout << "\nAfter modifying copy[0] to 999:" << std::endl;
	std::cout << "Original[0]: " << numbers[0] << " (should still be 0)" << std::endl;
	std::cout << "Copy[0]: " << copy[0] << " (should be 999)" << std::endl;
	std::cout << std::endl;



	std::cout << "=== Test 4: Assignment operator ===" << std::endl;
	Array<int> assigned;
	assigned = numbers;

	std::cout << "Original[1]: " << numbers[1] << std::endl;
	std::cout << "Assigned[1]: " << assigned[1] << std::endl;

	assigned[1] = 777;

	std::cout << "\nAfter modifying assigned[1] to 777:" << std::endl;
	std::cout << "Original[1]: " << numbers[1] << " (should still be 10)" << std::endl;
	std::cout << "Assigned[1]: " << assigned[1] << " (should be 777)" << std::endl;
	std::cout << std::endl;



	std::cout << "=== Test 5: Out of bounds exception ===" << std::endl;
	try {
		numbers[100] = 42;
		std::cout << "ERROR: No exception thrown!" << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;



	std::cout << "=== Test 6: Array of strings ===" << std::endl;
	Array<std::string> words(3);
	words[0] = "Hello";
	words[1] = "World";
	words[2] = "!";

	std::cout << "Content: ";
	for (unsigned int i = 0; i < words.size(); i++) {
		std::cout << words[i] << " ";
	}
	std::cout << std::endl;

	return (0);
}
