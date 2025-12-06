#ifndef ITER_H
#define ITER_H

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <cmath>
#include <string> 

template<typename T>
void iter(T *array, const size_t len, void (*aFunc)(T& element)) {
	for (size_t i = 0; i < len; i++)
		aFunc(array[i]);
}

template <typename T>
void iter(T const* array, size_t len, void (*func)(T const&)) {
    for (size_t i = 0; i < len; i++)
        func(array[i]);
}

template< typename I>
void print_I(const I& element) {
	std::cout << element << std::endl;
}

#endif