#ifndef ITER_H
#define ITER_H

#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <string> 

template<typename T, typename I>
void iter(T array, size_t len, void (*aFunc)(I& element)) {
	for (size_t i = 0; i < len; i++)
		aFunc(array[i]);
}

template< typename I>
void print_I(I& element) {
	std::cout << element << std::endl;
}

#endif