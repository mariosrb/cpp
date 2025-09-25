#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class Aanimal
{
	protected:
		std::string	type;

	public:
		Aanimal();
		Aanimal(std::string type);
		Aanimal(Aanimal const &src);
		Aanimal & operator=(Aanimal const & other);
		virtual ~Aanimal();

		std::string getType() const;
		void setType(const std::string type);
		virtual void makeSound() const = 0;
};


#endif
