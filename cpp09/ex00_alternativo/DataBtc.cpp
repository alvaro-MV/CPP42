#include "DataBtc.hpp"

DataBtc::DataBtc(std::string filename, std::string del): filename(filename), del(" | ") {
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

std::pair<std::string, std::string> DataBtc::getValueAndDateAsPair(std::string &line) {
	std::pair<std::string, std::string> dateAndValue = splitByDel(line, del);
	
	
	dateAndValue.first = trimDelAndSpaces(dateAndValue.first);
	dateAndValue.second = trimDelAndSpaces(dateAndValue.second);
	return (dateAndValue);
}

// Row DataBtc::fillRow() {

// }

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

std::string DataBtc::trimDelAndSpaces(std::string s) {
	if (s.empty())
		return "";
	s = s.substr(s.find_first_not_of(" " + del));	
	s.erase(s.find_last_not_of(" " + del) + 1);
	return (s);
}