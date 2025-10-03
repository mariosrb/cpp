#include "Intern.hpp"

static AForm* createShrubbery(std::string target) {
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(std::string target) {
	return new RobotomyRequestForm(target);
}

static AForm* createPresidential(std::string target) {
	return new PresidentialPardonForm(target);
}

Intern::Intern() {
}

Intern::Intern(const Intern &src) {
	(void)src;
}

Intern &Intern::operator=(Intern const &other) {
	(void)other;
	return (*this);
}

Intern::~Intern() {
}

AForm *Intern::makeForm(std::string formName, std::string target) {
	struct FormCreator {
		std::string name;
		AForm* (*creator)(std::string);
	};

	FormCreator forms[] = {
		{"shrubbery creation", createShrubbery},
		{"robotomy request", createRobotomy},
		{"presidential pardon", createPresidential}
	};

	for (int i = 0; i < 3; i++) {
		if (forms[i].name == formName) {
			std::cout << "Intern creates " << formName << std::endl;
			return forms[i].creator(target);
		}
	}
	std::cerr << "Error: Form '" << formName << "' does not exist!" << std::endl;
	return (NULL);
}
