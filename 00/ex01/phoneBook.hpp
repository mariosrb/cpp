#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook {
private:

    Contact contacts[8];
    int 	currentIndex;

    std::string truncateString(const std::string& str);
	std::string getValidInput(const std::string& prompt);

public:
    PhoneBook();
	~PhoneBook();
    void addContact();
    void displayContacts();
    void showContact(int index);
};

#endif
