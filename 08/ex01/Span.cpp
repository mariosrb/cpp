#include "./include/Span.hpp"

Span::Span() : N(0) {
}

Span::Span(const Span& to_copy) : N(to_copy.N), numbers(to_copy.numbers) {
}

Span::Span(unsigned int n) : N(n) {
}

Span &Span::operator=(const Span &other)
{
	if (this != &other) {
		N = other.N;
		numbers = other.numbers;
	}
	return (*this);
}

Span::~Span() {
}

void Span::addNumber(int value) {
	if (numbers.size() >= N)
		throw std::runtime_error("Not enough space");
	numbers.push_back(value);
}

int Span::shortestSpan() {
	if (numbers.size() < 2)
		throw std::runtime_error("Not enough numbers, must me 2 minimum");
	std::sort(numbers.begin(), numbers.end());
	int minSpan = numbers[1] - numbers[0];
	for (size_t i = 2; i < numbers.size(); i++) {
		int dif = numbers[i] - numbers[i - 1];
		if (dif < minSpan)
			minSpan = dif;
	}
	return (minSpan);
}

int Span::longestSpan() {
	if (numbers.size() < 2)
		throw std::runtime_error("Not enough numbers, must me 2 minimum");
	std::sort(numbers.begin(), numbers.end());
	return (numbers[numbers.size() - 1] - numbers[0]);
}
