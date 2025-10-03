#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &src);
		~PresidentialPardonForm();
		PresidentialPardonForm & operator=(PresidentialPardonForm const & other);

		PresidentialPardonForm(const std::string& target);
		void execute(Bureaucrat const & executor) const;
};

#endif
