#include "ScalarConverter.hpp"

void error_log() {
	std::cerr << "char: impossible"	<< std::endl;
	std::cerr << "int: impossible"	<< std::endl;
	std::cerr << "float: impossible" << std::endl;
	std::cerr << "double: impossible" << std::endl;
}

void printCharType(scaleTypes *stypes)
{
	if (!stypes->iValue)
		std::cout << "char: impossible" << std::endl;
	else if (!stypes->chValue)
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: " << *stypes->chValue << std::endl;
}

void printScaleTypes(scaleTypes *stypes, typesTag &tag) {
	if (tag == TAG0) {
		error_log();
		return ;
	}

	printCharType(stypes);
	if (stypes->iValue)
		std::cout << "int: " << *stypes->iValue << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << *stypes->fValue << "f" << std::endl;
	std::cout << "double: " << *stypes->dValue << std::endl;
}