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

bool stood(const std::string& s, double& out) {
    char* end;
    out = strtod(s.c_str(), &end);

    // Caso 1: no se ha convertido NADA
    if (end == s.c_str())
		return false;

	if (*end == 'f')
		end++;
    while (*end != '\0') {
        if (!std::isspace(*end))  // permite espacios al final
            return false;
        end++;
    }

    return true;
}


void safe_cast_int(scaleTypes *stypes) {
	if (std::isinf(*stypes->dValue) || std::isnan(*stypes->dValue))
	{
		delete stypes->iValue;
		stypes->iValue = NULL;
	}
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
	scaleTypes	stypes;
	typesTag	tag = TAG0;

	if (!allocScaleTypes(&stypes))
		return ;

	if (stood(str, *stypes.dValue))
		tag = DOUBLE;
	else if (str.length() == 1 && isprint(str[0]))
	{
		tag = CHAR;
		*stypes.chValue = str[0];
		*stypes.iValue = static_cast<int>(str[0]);
		*stypes.fValue = static_cast<float>(str[0]);
		*stypes.dValue = static_cast<double>(str[0]);
	}
	
	if (tag == DOUBLE)
	{
		*stypes.fValue = static_cast<float>(*stypes.dValue);
		safe_cast_int(&stypes);
		if (stypes.iValue && *stypes.iValue > 31 && *stypes.iValue < 255 && isprint(*stypes.iValue))
			*stypes.chValue = static_cast<char>(*stypes.iValue);
		else
		{
			delete stypes.chValue;
			stypes.chValue = NULL;
		}
	}
	printScaleTypes(&stypes, tag);
	deleteScaleTypes(&stypes);
}