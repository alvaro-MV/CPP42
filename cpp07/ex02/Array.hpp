#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <string> 
#include <cstring> 
#include <typeinfo>

std::string toString(size_t sz);

template<typename T>
class Array {
	private:
		T *array;
		unsigned int len;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& array);
		Array& operator=(const Array& array);
		~Array();
		T& operator[](unsigned int index);
		unsigned int size() const;
		class IndexOutOfBounds : public std::exception {
			public:
				const char* what(void) const throw();
		};
};

#include "Array.tpp"

#endif
