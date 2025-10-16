#ifndef INTER_HPP
# define INTER_HPP

#include <iostream>

template <typename T>
void iter(T* array, size_t length, void (*func)(T&));

#endif
