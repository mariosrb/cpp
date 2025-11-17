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
		std::list<int>::iterator test = easyfind(list, 7);
		std::cout << "Found: " << *test << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::deque<int> d;
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);

	try {
		std::deque<int>::iterator it = easyfind(d, 2);
		std::cout << "Found in deque: " << *it << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::deque<int>::iterator it = easyfind(d, 99);
		std::cout << "Found in deque: " << *it << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
