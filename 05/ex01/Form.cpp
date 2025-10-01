#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default Form"), isSigned(false), gradeToSign(150), gradeToExecute(150) {
}

Form::Form(const std::string name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	if (gradeToExecute < 1 || gradeToSign < 1)
		throw (GradeTooHighException());
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw (GradeTooLowException());
}

Form::Form(const Form &src) : name(src.name), isSigned(src.isSigned), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute) {
}

Form &Form::operator=(Form const &other) {
	if (this != &other) {
		this->isSigned = other.isSigned;
	}
	return (*this);
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

Form::~Form() {
}

std::string Form::getName() const {
	return (this->name);
}

bool Form::getIsSigned() const {
	return (this->isSigned);
}

int Form::getGradeToSign() const {
	return (this->gradeToSign);
}

int Form::getGradeToExecute() const {
	return (this->gradeToExecute);
}

void Form::beSigned(const Bureaucrat &b) {
	if (b.getGrade() <= this->getGradeToSign()) {
		this->isSigned = true;
	}
	else
		throw (GradeTooLowException());
}

std::ostream &operator<<(std::ostream &os, const Form &f) {
	os << "Form " << f.getName() << ", signed: " << f.getIsSigned()
	<< ", grade to sign: " << f.getGradeToSign() << ", grade to execute: "
	<< f.getGradeToExecute();
	return (os);
}
