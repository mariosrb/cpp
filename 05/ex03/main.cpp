#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <ctime>

int main() {
	srand(time(NULL)); // Seed aleatoire depuis le 1er janvier 1970
	std::cout << std::endl;
	try {
		std::cout << "== Test PresidentialPardonForm ==" << std::endl;
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Mario do");
		std::cout << president << std::endl;
		std::cout << pardon << std::endl;
		president.signForm(pardon);
		president.executeForm(pardon);
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		std::cout << "== Test RobotomyForm ==" << std::endl;
		Bureaucrat stefan("Stefan", 40);
		RobotomyRequestForm work("Work");
		std::cout << stefan << std::endl;
		std::cout << work << std::endl;
		stefan.signForm(work);
		stefan.executeForm(work);
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		std::cout << "== Test RobotomyForm - Formulaire non signe ==" << std::endl;
		Bureaucrat boss("Boss", 1);
		RobotomyRequestForm unsigned_form("Target");
		std::cout << boss << std::endl;
		std::cout << unsigned_form << std::endl;
		boss.executeForm(unsigned_form);
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try {
		std::cout << "== Test Shrubbery Form ==" << std::endl;
		Bureaucrat maokai("Maokai", 2);
		ShrubberyCreationForm sapling("sapling");
		std::cout << maokai << std::endl;
		std::cout << sapling << std::endl;
		maokai.signForm(sapling);
		maokai.executeForm(sapling);
	}
	catch (std::exception &e) {
		std::cerr << "Exception" << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		std::cout << "== Test Grade trop bas pour executer ==" << std::endl;
		Bureaucrat high("High", 1);
		Bureaucrat low("Low", 100);
		PresidentialPardonForm form("Prisoner");
		std::cout << high << std::endl;
		std::cout << low << std::endl;
		std::cout << form << std::endl;
		high.signForm(form);
		low.executeForm(form);
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		std::cout << "== Test Multiple robotomies (50/50 chance) ==" << std::endl;
		Bureaucrat robot("Robot", 1);
		for (int i = 0; i < 3; i++) {
			RobotomyRequestForm target("Subject");
			robot.signForm(target);
			robot.executeForm(target);
			std::cout << std::endl;
		}
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return (0);
}
