#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string type;

public:
	Animal();
	Animal(std::string type);
	Animal(Animal const &src);
	Animal & operator=(Animal const & other);
	virtual ~Animal();

	std::string getType() const;
	void setType(const std::string type);
	virtual void makeSound() const;
};


#endif
