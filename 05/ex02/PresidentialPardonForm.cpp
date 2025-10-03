#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", 25, 5) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src), target(src.target) {
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other) {
	if (this != &other) {
		this->target = other.target;
	}
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Presidential Pardon", 25, 5), target(target) {
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
