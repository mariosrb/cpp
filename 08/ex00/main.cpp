#include "./include/easyfind.hpp"

int main(void)
{
	std::vector<int> v;
	v.push_back(10);
	v.push_back(11);
	v.push_back(14);

	try {
		std::vector<int>::iterator it = easyfind(v, 10);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::list<int> list;
	list.push_back(10);
	list.push_back(11);
	list.push_back(14);

	try {
		std::list<int>::iterator test = easyfind(list, 10);
		std::cout << "Found: " << *test << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}
