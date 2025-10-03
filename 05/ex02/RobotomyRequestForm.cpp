#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src), target(src.target) {
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other) {
	if (this != &other) {
		this->target = other.target;
	}
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy Request", 72, 45), target(target) {
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << "BZZRRRRRRRRR BRRRRRRRR" << std::endl;
	if (rand() % 2 == 0) {
		std::cout << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << "The robotomy of " << this->target << " failed!" << std::endl;
	}
}
