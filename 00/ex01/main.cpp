#include "phoneBook.hpp"

int main(void)
{
	PhoneBook	phoneBook;
	std::string command;

	while (1)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		getline(std::cin, command);
		if (std::cin.eof())
			return (1);
		if (command == "ADD") {
			phoneBook.addContact();
		}
		else if (command == "SEARCH") {
			phoneBook.displayContacts();
			while (true) {
				std::cout << "Which contact (index) do you want to see ? ";

				std::string input;
				getline(std::cin, input);
				if (input.length() == 1 && input[0] >= '0' && input[0] <= '7') {
					int index = input[0] - '0';
					phoneBook.showContact(index);
					break ;
				}
				else {
					std::cout << "Invalid input. Please enter a number between 0 and 7." << std::endl;
				}
			}
		}
		else if (command == "EXIT") {
			break ;
		}
	}
	return (0);
}
