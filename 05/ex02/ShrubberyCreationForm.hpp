#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>


class ShrubberyCreationForm : public AForm {
	private:
		std::string target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		~ShrubberyCreationForm();
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & other);

		ShrubberyCreationForm(const std::string& target);
		void execute(Bureaucrat const & executor) const;
};

#endif
