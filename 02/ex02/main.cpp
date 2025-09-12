#include "Fixed.hpp"

int main( void )
{
    std::cout << "=== Test du main obligatoire ===" << std::endl;

    Fixed a;
    std::cout << "a (défaut) = " << a << std::endl;  // 0

    Fixed const b( Fixed(5.05f) * Fixed(2));  // 5.05 * 2 = 10.1
    std::cout << "b (5.05f * 2) = " << b << std::endl;  // 10.1

    std::cout << "\n=== Incrémentations ===" << std::endl;
    std::cout << "++a = " << ++a << std::endl;        // 0.00390625
    std::cout << "a après ++a = " << a << std::endl;  // 0.00390625
    std::cout << "a++ = " << a++ << std::endl;        // 0.00390625 (puis a s'incrémente)
    std::cout << "a après a++ = " << a << std::endl;  // 0.0078125

    std::cout << "\n=== Fonction max ===" << std::endl;
    std::cout << "max(a=" << a << ", b=" << b << ") = " << Fixed::max(a,b) << std::endl;  // 10.1

    return (0);
}

// int main( void )
// {
// 	Fixed 		a;
// 	Fixed const	b( Fixed(5.05f) * Fixed(2));

// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;

// 	std::cout << b << std::endl;

// 	std::cout << Fixed::max(a,b) << std::endl;

// 	return (0);
// }

// int main()
// {
// 	Fixed a(4.0f);
// 	Fixed b(2.0f);
// 	Fixed c(2.0f);
// 	std::cout << "a + b = " << a + b << std::endl;
// 	std::cout << "a - b = " << a - b << std::endl;
// 	std::cout << "a * b = " << a * b << std::endl;
// 	std::cout << "a / b = " << a / b << std::endl;
// 	std::cout << "---------" << std::endl;
// 	if (a > b)
// 		std::cout << "oui" << std::endl;
// 	if (b == c)
// 		std::cout << "non" << std::endl;
// 	if (a >= c)
// 		std::cout << "oui" << std::endl;
// 	if (b <= a)
// 		std::cout << "non" << std::endl;
// 	if (a != b)
// 		std::cout << "oui" << std::endl;
// 	if (c < a)
// 		std::cout << "non" << std::endl;
// 	std::cout << "a = " << ++a << std::endl;
// 	Fixed & smallest = Fixed::min(b, a);
// 	std::cout << smallest << std::endl;
// 	return (0);
// }
