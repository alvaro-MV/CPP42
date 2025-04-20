#include <string>
#include <iostream>
#include <string.h>
#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc != 2)
	{
		std::cerr << "Usage: ./convert <string to scale>" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
}