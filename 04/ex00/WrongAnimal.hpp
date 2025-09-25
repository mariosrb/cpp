#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(WrongAnimal const &src);
	WrongAnimal & operator=(WrongAnimal const & other);
	~WrongAnimal();

	std::string getType() const;
	void setType(const std::string type);
	void makeSound() const;
};


#endif
