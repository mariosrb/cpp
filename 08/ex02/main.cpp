#include "./include/MutantStack.hpp"

int main(void)
{
	std::cout << std::endl << "===== Subject tests =====" << std::endl ;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << std::endl << "print last inserted number(at the top):" << std::endl ;
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << std::endl << "print size after deleting a number:" << std::endl ;
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << std::endl << "iterate through the whole stack:" << std::endl ;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << std::endl << "===== Same tests  with list =====" << std::endl ;
	std::list<int> mlist;
	mlist.push_back(5);
	mlist.push_back(17);
	std::cout << std::endl << "print last inserted number(at the top):" << std::endl ;
	std::cout << mlist.front() << std::endl;
	mlist.pop_back();
	std::cout << std::endl << "print size after deleting a number:" << std::endl ;
	std::cout << mlist.size() << std::endl;
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(0);

	// Itération sur la liste avec iterator
	std::cout << std::endl << "iterate through the whole list:" << std::endl;
	for (std::list<int>::iterator lit = mlist.begin(); lit != mlist.end(); ++lit)
	{
		std::cout << *lit << std::endl;
	}

	return 0;
}
