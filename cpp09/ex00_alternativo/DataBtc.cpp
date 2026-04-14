#include "DataBtc.hpp"

DataBtc::DataBtc(std::string filename, std::string del): filename(filename), del("|") {
	file.open(filename, std::ios::in);
	
	if (!file.is_open()) {
        std::cerr << "Error: could not open file " << std::endl;
		exit(1);
    }
}

DataBtc::DataBtc(const DataBtc& data): filename(data.filename), del(data.del) {
	file.open(filename, std::ios::in);
	
	if (!file.is_open()) {
        std::cerr << "Error: could not open file " << std::endl;
		exit(1);
    }
}

DataBtc& DataBtc::operator=(const DataBtc& data) {
	if (this != &data) {
		file.close();
		filename = data.filename;
		file.open(filename.c_str());
		if (!file.is_open()) {
			std::cerr << "Error: could not open file " << std::endl;
			exit(1);
   		}
	}
	return *this;
}

DataBtc::~DataBtc() {
	if (file.is_open())
		file.close();
}

bool DataBtc::readLine(std::string &line){
	if (!std::getline(file, line))
		return (false);
	return (true);
}

std::pair<std::string, std::string> DataBtc::getDateAndValue(std::string &line) {
	std::pair<std::string, std::string> dateAndValue = splitByDel(line, del);	
	
	dateAndValue.first = trimDelAndSpaces(dateAndValue.first);
	dateAndValue.second = trimDelAndSpaces(dateAndValue.second);

	return (dateAndValue);
}

DataBtc::Row	DataBtc::fillRow(std::pair<std::string, std::string> dateAndValue) {
	std::string date = dateAndValue.first;
	std::string value = dateAndValue.second;
	std::string year;
	std::string month;
	std::string day;
	std::pair<std::string, std::string> yearAndMonth;
	std::pair<std::string, std::string> monthAndDay;
	Row row;

	if (date.empty()) {
		std::cout << "NO hay fecha" << std::endl;
		year = "";
		month = "";
		day = "";
	}
	else {
		yearAndMonth = splitByDel(date, "-");
		year = yearAndMonth.first;
		month = yearAndMonth.second;
	
		if (month.empty())
			std::cout << "NO hay mes" << std::endl;
		else {
			monthAndDay = splitByDel(month, "-");
			month = monthAndDay.first;
			day = monthAndDay.second;
		
			if (day.empty())
				std::cout << "NO hay día." << std::endl;
		}
	
	}

	if (!convertValueToInt(year, row.year) || (row.year < 2009 && row.year > 2026))
		std::cout << "Año no guarda un formato correcto." << std::endl;
	if (!convertValueToInt(month, row.month) || (row.month < 0 && row.month > 12))
		std::cout << "Mes no guarda un formato correcto." << std::endl;
	if (!convertValueToInt(day, row.day) || (row.day < 0 && row.day > 31)
		|| (row.day == 29 && row.month == 2
		&& (row.year % 4 != 0 || (row.year % 100 == 0 && row.year % 400 != 0)) ) )
		std::cout << "Día no guarda un formato correcto." << std::endl;

	if (!convertValueToFloat(value, row.value))
		std::cout << "NO valor numérico." << std::endl;
	else if (row.value < 0)
		std::cout << "not a positive number." << std::endl;
	else if (row.value > 1000)
		std::cout << "too large a number." << std::endl;


	return (row);
}

std::pair<std::string, std::string> DataBtc::splitByDel(std::string &line, std::string del) {
	size_t	del_pos = line.find(del);
	std::pair<std::string, std::string> ret;
	
	if (del_pos == std::string::npos) {
		ret = {line, ""};
		return (ret);
	}

	std::string first = line.substr(0, del_pos);
	std::string second = line.substr(del_pos + del.length());
	ret = {first, second};
	return (ret);
}

bool	checkEmptyString(std::string s) {
	for (size_t i = 0; i < s.length(); i++) {
		if (!isspace(s[i]))
			return (false);
	}
	return (true);
}

std::string DataBtc::trimDelAndSpaces(std::string s) {
	if (s.empty() || checkEmptyString(s))
		return "";
	s = s.substr(s.find_first_not_of(" \n\t\r" + del));	
	s.erase(s.find_last_not_of(" " + del) + 1);
	return (s);
}

size_t DataBtc::mfind(std::string &s, std::string pattern, size_t iters) {
	int pos = -1;
	while (iters && (pos = s.find(pattern, static_cast<size_t>(++pos))) != std::string::npos)
		--iters;
	return (pos);
}

bool DataBtc::convertValueToFloat(std::string value, double &out) {
    char* end;
    out = strtod(value.c_str(), &end);

    // no se ha podido convertir nada
    if (end == value.c_str())
        return false;

    // comprobar basura después
    while (*end) {
        if (!std::isspace(*end))
            return false;
        end++;
    }
    return true;
}

bool DataBtc::convertValueToInt(const std::string &value, int& out) {
    char* end;
    long val = strtol(value.c_str(), &end, 10);

    // no se ha convertido nada
    if (end == value.c_str())
        return false;

    // comprobar basura al final
    while (*end) {
        if (!std::isspace(*end))
            return false;
        end++;
    }

    // comprobar overflow de int
    if (val > (std::numeric_limits<int>::max())
		|| val < std::numeric_limits<int>::min())
        return false;

    out = static_cast<int>(val);
    return true;
}
