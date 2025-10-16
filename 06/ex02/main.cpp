#include "./include/Base.hpp"

int main()
{
	Base*	obj = generate();
	srand(time(NULL));

	std::cout << "Identify with pointer: ";
	identify(obj);

	std::cout << "Identify with reference: ";
	identify(*obj);

	delete obj;
	return (0);
}
