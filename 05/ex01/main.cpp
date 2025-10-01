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

	return (0);
}
