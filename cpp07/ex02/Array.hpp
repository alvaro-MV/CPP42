#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <string> 
#include <cstring> 

template<typename T>
class Array {
	private:
		T *array;
		unsigned int len;
	public:
		Array();
		Array(unsigned int n);
		Array(Array& array);
		Array& operator=(Array& array);
		T& operator[](unsigned int index);
		~Array();
		size_t size();
		class IndexOutOfBounds : public std::exception {
			private:
					size_t index;

			public:
					IndexOutOfBounds(unsigned int index): index(index) {};
					const char* what(void) const throw();
			};
};

#include "Array.tpp"

#endif
