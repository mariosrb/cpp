#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

public:
	WrongCat();
	WrongCat(std::string type);
	WrongCat(WrongCat const &src);
	WrongCat & operator=(WrongCat const & other);
	~WrongCat();

	void makeSound() const;
};

#endif
