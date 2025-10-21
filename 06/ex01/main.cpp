#include "./include/Serializer.hpp"

// int main() {
//     int x = 42;
//     int* ptr = &x;

//     // Convertir pointeur en entier
// 	std::cout << "Adresse en entier : " << ptr << std::endl;
//     uintptr_t iptr = reinterpret_cast<uintptr_t>(ptr);
//     std::cout << "Adresse en entier : " << iptr << std::endl;

//     // Convertir entier en pointeur
//     int* ptr2 = reinterpret_cast<int*>(iptr);
//     std::cout << "Valeur pointée : " << *ptr2 << std::endl;

//     return 0;
// }

int main()
{
	Data	d;
	d.value = 42;
	d.c= 'a';
	Data*	original = &d;

	uintptr_t raw = Serializer::serialize(original);
	Data* restored = Serializer::deserialize(raw + 1);
	std::cout << "Original pointer: " << original << std::endl;
	std::cout << "Serialized value: " << raw  << std::endl;
	std::cout << "Deserialized pointer: " << restored << std::endl;

	if (restored == original)
		std::cout << "Success: pointers match" << std::endl;
	else
		std::cout << "Failure: pointers do not match" << std::endl;
	return (0);
}
