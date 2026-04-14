#include "Input.hpp"

Input::Input(std::string filename): DataBtc(filename, "|") {}
Input::Input(const Input &other): DataBtc(other.filename, "|") {}
Input& Input::operator=(const Input &other) {
	DataBtc::operator=(other);
	return *this;
}
Input::~Input() {
	if (file.is_open())
		file.close();
}

void Input::findAndPrintRows(Database &db) {
	std::string line;
	DataBtc::Row row;
	DataBtc::Row nearest;

	while(readLine(line)) {
		std::pair<std::string, std::string> dateAndValue = getDateAndValue(line);
		try {
			row = fillRow(dateAndValue);
			nearest = db.findNearest(row);
			std::cout << line << " ==> " << row.value << " = " << row.value * nearest.value << std::endl;
		}
		catch(std::exception &e) {
			std::cout << e.what() << " ==> " << line << std::endl;
		}
	}
}
