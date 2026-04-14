#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string filename): DataBtc(filename, ",") {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other): DataBtc(other.filename, ",") {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other) {
	DataBtc::operator=(other);
	return *this;
}
BitcoinExchange::~BitcoinExchange() {
	if (file.is_open())
		file.close();
}

void	BitcoinExchange::insertDatabase() {
	std::string line;
	DataBtc::Row row;

	while(readLine(line)) {
		std::pair<std::string, std::string> dateAndValue = getDateAndValue(line);
		try {
			row = fillRow(dateAndValue);
			std::pair<DataBtc::Row, double> database_entry = {row, row.value};
			database.insert(database_entry);
		}
		catch(std::exception &e) {
			// std::cout << e.what() << std::endl;
		}
	}
}

DataBtc::Row BitcoinExchange::findNearest(DataBtc::Row &search) const {
	std::multimap<DataBtc::Row, double, CompareDateRows>::const_iterator it = database.begin();
	CompareDateRows comp;
	
	while (it != database.end() && comp(it->first, search)) {
		it++;
	}
	it--;
	return (it->first);
}