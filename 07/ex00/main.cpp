#include "./include/template.hpp"
#include <string>

int main(void) {
	// Test avec des int
	int a = 2;
	int b = 3;

	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::cout << std::endl;

	// Test avec des string
	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

	std::cout << std::endl;

	// Test avec des float
	float x = 4.2f;
	float y = 42.0f;

	std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
	::swap(x, y);
	std::cout << "After swap: x = " << x << ", y = " << y << std::endl;
	std::cout << "min(x, y) = " << ::min(x, y) << std::endl;
	std::cout << "max(x, y) = " << ::max(x, y) << std::endl;

	std::cout << std::endl;

	// Test cas d'égalité
	int e = 5;
	int f = 5;

	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min(e, f) = " << ::min(e, f) << " (should return second: " << f << ")" << std::endl;
	std::cout << "max(e, f) = " << ::max(e, f) << " (should return second: " << f << ")" << std::endl;

	return 0;
}
