#include "DataBtc.hpp"

// int main() {
// 	DataBtc data("chatgpt_pruebas.txt", "|");
// 	std::string line;
// 	DataBtc::Row row;

// 	while(data.readLine(line)) {
// 		std::cout << line << std::endl;
// 		std::cout << "------------------------------" << std::endl;
// 		std::pair<std::string, std::string> dateAndValue = data.getDateAndValue(line);
// 		try {
// 			row = data.fillRow(dateAndValue);

// 			std::cout << "year: " << row.year << " month: " << row.month << " day: ";
// 			std::cout << row.day << " value: " << row.value << std::endl;
// 		} catch(std::exception &e) {
// 			std::cout << e.what() << std::endl;
// 		}
// 		std::cout << "******************************	" << std::endl;

// 	}	
// }

struct CompareDateRows {
	bool operator()(DataBtc::Row a, DataBtc::Row b) const {
		if (a.year != b.year) return a.year < b.year;
		if (a.month != b.month) return a.month < b.month;
		return a.day < b.day;
	}
};

int main() {
	DataBtc data("chatgpt_pruebas.txt", "|");
	std::string line;
	DataBtc::Row row;
	std::multimap<DataBtc::Row, double, CompareDateRows> database;

	while(data.readLine(line)) {
		// std::cout << line << std::endl;
		// std::cout << "------------------------------" << std::endl;
		std::pair<std::string, std::string> dateAndValue = data.getDateAndValue(line);
		try {
			row = data.fillRow(dateAndValue);
			std::pair<DataBtc::Row, double> database_entry = {row, row.value};
			database.insert(database_entry);
		}
		catch(std::exception &e) {
			// std::cout << e.what() << std::endl;
		}
	}
	std::multimap<DataBtc::Row, double, CompareDateRows>::iterator it = database.begin();
	while (it != database.end()) {
		std::cout << it->first.year << "-" << it->first.month << "-" << it->first.day << std::endl;
		it++;
	}
}