#include "phoneBook.hpp"

PhoneBook::PhoneBook() : currentIndex(0) {
}

std::string PhoneBook::truncateString(const std::string& str) {
    if (str.length() > 10) {
        std::string result = str;
        result.resize(9);
        result += ".";
        return result;
    }
    return str;
}

std::string PhoneBook::getValidInput(const std::string& prompt) {
	std::string input;
	while (true) {
		std::cout << prompt;
		if (!std::getline(std::cin, input)) {
			std::cout << std::endl << "Input interrupted. Exiting..." << std::endl;
			exit (1);
		}
		if (!input.empty()) {
			return input;
		}
		std::cout << "Field cannot be empty. Please try again" << std::endl;
	}
}

void PhoneBook::addContact() {
	contacts[currentIndex].setFirstName(getValidInput("First name: "));
	contacts[currentIndex].setLastName(getValidInput("Last name: "));
	contacts[currentIndex].setNickName(getValidInput("Nick name: "));
	contacts[currentIndex].setPhoneNumber(getValidInput("Phone number: "));
	contacts[currentIndex].setDarkestSecret(getValidInput("Darkest secret: "));
	currentIndex++;
	if (currentIndex >= 8) {
		currentIndex = 0;
	}
}

void PhoneBook::displayContacts() {

	std::cout << std::setw(10) << std::right << "index" << "|";
	std::cout << std::setw(10) << std::right << "first name" << "|";
	std::cout << std::setw(10) << std::right << "last name" << "|";
	std::cout << std::setw(10) << std::right << "nickname" << "|";
	std::cout << std::endl;

	for (int i = 0; i < 8; i++) {
		std::cout << std::setw(10) << std::right << i << "|";
		std::cout << std::setw(10) << std::right << truncateString(contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << std::right << truncateString(contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << std::right << truncateString(contacts[i].getNickName()) << "|";
		std::cout << std::endl;
	}
}

void PhoneBook::showContact(int index) {
	if (index < 0 || index >= 8) {
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	std::cout << "First name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nick name: " << contacts[index].getNickName() << std::endl;
	std::cout << "Phone number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contacts[index].getDarkestSecret() << std::endl;
}

PhoneBook::~PhoneBook() {
}
