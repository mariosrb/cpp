#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <iostream>
#include <sstream>

class RPN {
	private:
		std::stack<int>	_stack;

		// Private helper methods
		bool	isNumber(const std::string& token) const;
		bool 	isOperator(const std::string& token) const;
		int		performOperation(int a, int b, char op) const;

		// Orthodox canonical Form
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);

	public:
		RPN();
		~RPN();

		bool	evaluate(const std::string& expression);
		int		getResult() const;

};

#endif
