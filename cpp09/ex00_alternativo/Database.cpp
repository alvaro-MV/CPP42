#include "Database.hpp"

Database::Database(std::string filename): DataBtc(filename, ",") {}
Database::Database(const Database &other): DataBtc(other.filename, ",") {}
Database& Database::operator=(const Database &other) {
	DataBtc::operator=(other);
}
Database::~Database() {
	if (file.is_open())
		file.close();
}

void	Database::insertDatabase() {
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

DataBtc::Row Database::findNearest(DataBtc::Row &search) const {
	std::multimap<DataBtc::Row, double, CompareDateRows>::const_iterator it = database.begin();
	CompareDateRows comp;
	
	while (it != database.end() && comp(it->first, search)) {
		it++;
	}
	it--;
	return (it->first);
}