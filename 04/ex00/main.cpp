#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// int main()
// {
// 	const WrongAnimal* meta = new WrongAnimal();
// 	const WrongAnimal* j = new WrongCat();
// 	const WrongAnimal* i = new WrongCat();
// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	i->makeSound();
// 	j->makeSound();
// 	meta->makeSound();
// 	delete meta;
// 	delete j;
// 	delete i;
// 	return 0;
// }

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=== Animal Polymorphism Test ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << dog->getType() << " says: ";
    dog->makeSound();
    std::cout << cat->getType() << " says: ";
    cat->makeSound();
    std::cout << "Animal says: ";
    meta->makeSound();

    delete meta;
    delete dog;
    delete cat;

    std::cout << "\n=== Wrong Classes (No Virtual) ===" << std::endl;
    const WrongAnimal* wrong_animal = new WrongAnimal();
    const WrongAnimal* wrong_cat_as_animal = new WrongCat();
    WrongCat* wrong_cat_direct = new WrongCat();

    std::cout << "WrongAnimal via pointer: ";
    wrong_cat_as_animal->makeSound(); // Should be WrongAnimal sound
    std::cout << "WrongCat direct: ";
    wrong_cat_direct->makeSound();     // Should be WrongCat sound

    delete wrong_animal;
    delete wrong_cat_as_animal;
    delete wrong_cat_direct;

    std::cout << "\n=== Copy Test ===" << std::endl;
    Dog original;
    Dog copy(original);
    original.makeSound();
    copy.makeSound();

    return 0;
}
