#include "ScalarConverter.hpp"

void error_log() {
	std::cerr << "char: impossible"	<< std::endl;
	std::cerr << "int: impossible"	<< std::endl;
	std::cerr << "float: impossible" << std::endl;
	std::cerr << "double: impossible" << std::endl;
}

void printCharType(scaleTypes *stypes)
{
	if (!stypes->chValue)
		std::cout << "char: impossible" << std::endl;
	else if ((*stypes->chValue >= 0 && *stypes->chValue <= 31)
		|| *stypes->chValue == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << *stypes->chValue << std::endl;
}

void printScaleTypes(scaleTypes *stypes) {
	printCharType(stypes);
	if (stypes->iValue)
		std::cout << "int: " << *stypes->iValue << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << *stypes->fValue << "f" << std::endl;
	std::cout << "double: " << *stypes->dValue << std::endl;
}