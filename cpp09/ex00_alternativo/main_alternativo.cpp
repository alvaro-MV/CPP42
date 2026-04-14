#include "DataBtc.hpp"

int main() {
	DataBtc data("chatgpt_pruebas.txt", "|");
	std::string line;
	DataBtc::Row row;

	while(data.readLine(line)) {
		std::cout << line << std::endl;
		std::cout << "------------------------------" << std::endl;
		std::pair<std::string, std::string> dateAndValue = data.getDateAndValue(line);
		try {
			row = data.fillRow(dateAndValue);

			std::cout << "year: " << row.year << " month: " << row.month << " day: ";
			std::cout << row.day << " value: " << row.value << std::endl;
		} catch(std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << "******************************	" << std::endl;

	}	
}