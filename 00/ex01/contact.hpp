#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact {

public:

	Contact();
	~Contact();

	std::string getLastName() const;
	std::string getFirstName() const;
	std::string getNickName() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;

	void setFirstName(const std::string &name);
	void setLastName(const std::string &name);
	void setNickName(const std::string &name);
	void setPhoneNumber(const std::string &number);
	void setDarkestSecret(const std::string &secret);

private:

	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string darkestSecret;

};

#endif
