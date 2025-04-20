#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <string>
#include <iostream>
#include <exception>
#include <cmath>
#include <cstring>
#include <limits>

typedef struct scalarTypes {
	char *chValue;
	int *iValue;
	float *fValue;
	double *dValue;
} scaleTypes;

class ScalarConverter {
	public:
		static void convert(std::string str);
};

#endif