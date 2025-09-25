#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

// int main()
// {
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();
//     delete j;//should not create a leak
//     delete i;
//     return 0;
// }

int main()
{
	std::cout << "== Test de copie profonde ==";
	Dog dog1;
	dog1.setIdea(0, "I love bones");
	dog1.setIdea(1, "I love bones");
	dog1.setIdea(2, "I love bones");

	Dog dog2(dog1);
	std::cout << "Dog1 idea 0: " << dog1.getIdea(0) << std::endl;
	std::cout << "Dog1 idea 1: " << dog1.getIdea(1) << std::endl;
	std::cout << "Dog1 idea 2: " << dog1.getIdea(2) << std::endl;
	std::cout << "Dog2 idea 0: " << dog2.getIdea(0) << std::endl;
	std::cout << "Dog2 idea 1: " << dog2.getIdea(1) << std::endl;
	std::cout << "Dog2 idea 2: " << dog2.getIdea(2) << std::endl;

	dog1.setIdea(0, "New idea");
	std::cout << "Dog1 idea 0: " << dog1.getIdea(0) << std::endl;
	std::cout << "Dog1 idea 1: " << dog1.getIdea(1) << std::endl;
	std::cout << "Dog1 idea 2: " << dog1.getIdea(2) << std::endl;
	std::cout << "Dog2 idea 0: " << dog2.getIdea(0) << std::endl;
	std::cout << "Dog2 idea 1: " << dog2.getIdea(1) << std::endl;
	std::cout << "Dog2 idea 2: " << dog2.getIdea(2) << std::endl;

	std::cout << "== Test avec operateur = ==" << std::endl;

	Dog dog3 = dog1;
	std::cout << "Dog1 idea 0: " << dog1.getIdea(0) << std::endl;
	std::cout << "Dog1 idea 1: " << dog1.getIdea(1) << std::endl;
	std::cout << "Dog1 idea 2: " << dog1.getIdea(2) << std::endl;
	std::cout << "Dog3 idea 0: " << dog3.getIdea(0) << std::endl;
	std::cout << "Dog3 idea 1: " << dog3.getIdea(1) << std::endl;
	std::cout << "Dog3 idea 2: " << dog3.getIdea(2) << std::endl;
	dog1.setIdea(1, "New idea");

	std::cout << "Dog1 idea 0: " << dog1.getIdea(0) << std::endl;
	std::cout << "Dog1 idea 1: " << dog1.getIdea(1) << std::endl;
	std::cout << "Dog1 idea 2: " << dog1.getIdea(2) << std::endl;
	std::cout << "Dog3 idea 0: " << dog3.getIdea(0) << std::endl;
	std::cout << "Dog3 idea 1: " << dog3.getIdea(1) << std::endl;
	std::cout << "Dog3 idea 2: " << dog3.getIdea(2) << std::endl;
	std::cout << "== Test tableau polymorphe ==" << std::endl;
	const Animal* j[10];
	for (int i = 0; i < 10 / 2; i++) {
		j[i] = new Dog();
		std::cout << std::endl;
	}
	for (int i = 5; i < 10; i++) {
		j[i] = new Cat();
		std::cout << std::endl;
	}
	for (int i = 0; i < 10; i++) {
		delete j[i];
		std::cout << std::endl;
	}
	return 0;
}
