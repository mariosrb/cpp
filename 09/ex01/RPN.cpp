#include "./include/RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other) {
	(void)other;
}

RPN& RPN::operator=(const RPN& other) {
	(void) other;
	return (*this);
}

bool RPN::isNumber(const std::string& token) const {
	if (token.length() != 1)
		return (false);
	return (token[0] >= '0' && token[0] <= '9');
}

bool RPN::isOperator(const std::string& token) const {
	return (token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '/' || token[0] == '*'));
}

int RPN::performOperation(int a, int b, char op) const {
	switch (op)
	{
	case '+': return (a + b);
	case '-': return (a - b);
	case '*': return (a * b);
	case '/':
		if (b == 0) {
			std::cerr << "Error: division by zero" << std::endl;
			return (0);
		}
		return (a / b);
	default:
		return (0);
	}
}

bool RPN::evaluate(const std::string& expression) {
	// 1 --> Vider la pile
	while (!_stack.empty())
		_stack.pop();

	// 2 --> Flux de parsing
	std::istringstream	iss(expression);
	std::string			token;

	// 3 --> Traiter chaque token
	while (iss >> token) {
		// cas 1 : Cest un nombre
		if (isNumber(token)) {
			int num = token[0] - '0';
			_stack.push(num);
		}
		// cas 2 : C'est un operateur
		else if (isOperator(token)) {
			// verifier si 2 nombres
			if (_stack.size() < 2) {
				std::cerr << "Error" << std::endl;
				return (false);
			}

			// Depiler dans le bon ordre
			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();

			int result = performOperation(a, b, token[0]);

			if (token[0] == '/' && b == 0) {
				return (false);
			}
			// remettre le resultat dessus
			_stack.push(result);
		}
		//cas 3 : token invalide
		else {
			std::cerr << "Error" << std::endl;
			return (false);
		}
	}
	// Étape 4 : Vérifier qu'il reste exactement 1 élément
    if (_stack.size() != 1) {
		std::cerr << "Error" << std::endl;
		return (false);
	}
    return (true);
}

int RPN::getResult() const {
	if (_stack.empty())
		return 0;
	return (_stack.top());
}
