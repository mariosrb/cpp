#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default AForm"), isSigned(false), gradeToSign(150), gradeToExecute(150) {
}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	if (gradeToExecute < 1 || gradeToSign < 1)
		throw (GradeTooHighException());
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw (GradeTooLowException());
}

AForm::AForm(const AForm &src) : name(src.name), isSigned(src.isSigned), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute) {
}

AForm &AForm::operator=(AForm const &other) {
	if (this != &other) {
		this->isSigned = other.isSigned;
	}
	return (*this);
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

AForm::~AForm() {
}

std::string AForm::getName() const {
	return (this->name);
}

bool AForm::getIsSigned() const {
	return (this->isSigned);
}

int AForm::getGradeToSign() const {
	return (this->gradeToSign);
}

int AForm::getGradeToExecute() const {
	return (this->gradeToExecute);
}

void AForm::beSigned(const Bureaucrat &b) {
	if (b.getGrade() <= this->getGradeToSign()) {
		this->isSigned = true;
	}
	else
		throw (GradeTooLowException());
}

std::ostream &operator<<(std::ostream &os, const AForm &f) {
	os << "AForm " << f.getName() << ", signed: " << f.getIsSigned()
	<< ", grade to sign: " << f.getGradeToSign() << ", grade to execute: "
	<< f.getGradeToExecute();
	return (os);
}

const char *AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed!";
}
