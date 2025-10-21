#ifndef INTER_HPP
# define INTER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T* array, size_t length, F func) {
	for (size_t i = 0; i < length; i++) {
		func(array[i]);
	}
}

void printInt(const int& n) {
	std::cout << n << std::endl;
}

void increment(int& n) {
	n++;
}

template <typename T>
void print(const T& element) {
	std::cout << element << std::endl;
}

void toUpper(std::string& str) {
	for (size_t i =0; i < str.length(); i++) {
		str[i] = std::toupper(str[i]);
	}
}

#endif

