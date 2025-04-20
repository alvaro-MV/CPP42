#include "ScalarConverter.hpp"

int allocScaleTypes(scaleTypes *stypes) {
	try {
		stypes->dValue = new double;
		stypes->fValue = new float;
		stypes->iValue = new int;
		stypes->chValue = new char;
	}
	catch (std::bad_alloc &bad) {
		std::cerr << "Error allocating memory" << std::endl;
		return (0);
	}
	return (1);
}

void deleteScaleTypes(scaleTypes *stypes) {
	delete stypes->chValue;
	delete stypes->iValue;
	delete stypes->fValue;
	delete stypes->dValue;
}

void safe_cast_int(scaleTypes *stypes) {
	if (std::isinf(*stypes->dValue) || std::isnan(*stypes->dValue))
		stypes->iValue = NULL;
	else if (*stypes->dValue > std::numeric_limits<int>::max()) {
        *stypes->iValue = std::numeric_limits<int>::max();
    }
	else if (*stypes->dValue < std::numeric_limits<int>::min()) {
        *stypes->iValue = std::numeric_limits<int>::min();
    }
	else {
        *stypes->iValue = static_cast<int>(*stypes->dValue);
    }
}
void ScalarConverter::convert(std::string str) {
	scaleTypes stypes;
	
	if (str[-1] == 'f')
		str = str.substr(0, -1);
	if (!allocScaleTypes(&stypes))
		return ;

	try {
		*stypes.dValue = std::stod(str);
	}
	catch(std::invalid_argument &invalid) {
		error_log();
		return ;
	}
	*stypes.fValue = static_cast<float>(*stypes.dValue);
	safe_cast_int(&stypes);
	if (stypes.iValue && *stypes.iValue < 255)
		*stypes.chValue = static_cast<char>(*stypes.iValue);
	else
		stypes.chValue = NULL;
	printScaleTypes(&stypes);
	deleteScaleTypes(&stypes);
}