#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Robotomy Request", 145, 137) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), target(src.target) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other) {
	if (this != &other) {
		this->target = other.target;
	}
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery Creation", 145, 137), target(target) {
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::string filename = this->target + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file.is_open()) {
		std::cout << "couldn't open the file" << std::endl;
	}
    file << "      ccee88oo\n"
        "   C8O8O8Q8PoOb o8oo\n"
        "  dOB69QO8PdUOpugoO9bD\n"
        " CgggbU8OU qOp qOdoUOdcb\n"
        "     6OuU  /p u gcoUodpP\n"
        "        \\\\//  /douUP\n"
        "          \\\\\\////\n"
        "           |||/\\\n"
        "           |||\\/\n"
        "           |||||\n"
        "      .....//||||\\....";
	file.close();
}
