#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	std::cout << "===============" << std::endl;
	Bureaucrat bob("bob", 50);
	Form formA("FormA", 100, 50);
	std::cout << bob << std::endl;
	std::cout << formA << std::endl;

	bob.signForm(formA);
	std::cout << formA << std::endl;

	std::cout << "===============" << std::endl;
	Bureaucrat lowGrade("LowGrade", 100);
	Form hardForm("HardForm", 50, 25);

	lowGrade.signForm(hardForm);
	std::cout << hardForm << std::endl;

	std::cout << "=======Creation avec grade invalide========" << std::endl;
	try {
		Form invalidHigh("InvalidHigh", 0, 50);
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		Form invalidLow("InvalidLow", 50, 151);
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "=======Affichage avant et apres signature========" << std::endl;
	Bureaucrat signer("Signer", 1);
	Form testForm("TestForm", 50, 25);

	std::cout << "Before signing:" << std::endl;
	std::cout << testForm << std::endl;

	signer.signForm(testForm);

	std::cout << "After signing:" << std::endl;
	std::cout << testForm << std::endl;

	return (0);
}
}
