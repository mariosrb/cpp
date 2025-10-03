#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <ctime>

int main() {
	srand(time(NULL));

	std::cout << "\n========== TEST 1: Intern creates Shrubbery ==========\n" << std::endl;
	{
		Intern someRandomIntern;
		AForm* form;

		form = someRandomIntern.makeForm("shrubbery creation", "home");
		if (form) {
			Bureaucrat bob("Bob", 1);
			bob.signForm(*form);
			bob.executeForm(*form);
			delete form;
		}
	}

	std::cout << "\n========== TEST 2: Intern creates Robotomy ==========\n" << std::endl;
	{
		Intern intern;
		AForm* form;

		form = intern.makeForm("robotomy request", "Bender");
		if (form) {
			Bureaucrat alice("Alice", 1);
			alice.signForm(*form);
			alice.executeForm(*form);
			delete form;
		}
	}

	std::cout << "\n========== TEST 3: Intern creates Presidential ==========\n" << std::endl;
	{
		Intern intern;
		AForm* form;

		form = intern.makeForm("presidential pardon", "Arthur Dent");
		if (form) {
			Bureaucrat president("President", 1);
			president.signForm(*form);
			president.executeForm(*form);
			delete form;
		}
	}

	std::cout << "\n========== TEST 4: Invalid form name ==========\n" << std::endl;
	{
		Intern intern;
		AForm* form;

		form = intern.makeForm("unknown form", "target");
		if (form) {
			delete form;
		} else {
			std::cout << "Form was not created (expected behavior)" << std::endl;
		}
	}

	std::cout << "\n========== TEST 5: Multiple forms creation ==========\n" << std::endl;
	{
		Intern intern;
		Bureaucrat boss("Boss", 1);
		AForm* forms[3];

		forms[0] = intern.makeForm("shrubbery creation", "garden");
		forms[1] = intern.makeForm("robotomy request", "criminal");
		forms[2] = intern.makeForm("presidential pardon", "prisoner");

		for (int i = 0; i < 3; i++) {
			if (forms[i]) {
				std::cout << "\nProcessing form " << i + 1 << ":" << std::endl;
				boss.signForm(*forms[i]);
				boss.executeForm(*forms[i]);
				delete forms[i];
			}
		}
	}

	std::cout << "\n========== TEST 6: Intern with low grade bureaucrat ==========\n" << std::endl;
	{
		Intern intern;
		AForm* form;

		form = intern.makeForm("presidential pardon", "someone");
		if (form) {
			Bureaucrat lowGrade("LowGrade", 150);
			std::cout << lowGrade << std::endl;
			std::cout << *form << std::endl;
			lowGrade.signForm(*form);
			delete form;
		}
	}

	return 0;
}
