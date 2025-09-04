#include <iostream>
#include <string>
#include <ctype.h>

int main (int argc, char **argv) {

	std::string	buffer;

	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++) {
		buffer += argv[i];
	}
	for (size_t j = 0; j < buffer.size(); j++) {
		buffer[j] = std::toupper(buffer[j]);
	}
	std::cout << buffer << std::endl;
	return (0);
}

