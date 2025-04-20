#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <stdint.h>
#include <string.h>
#include <iostream>

typedef struct Data {
	int iValue;
	float fValue;
	double dValue;
} Data;

class Serializer {
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif