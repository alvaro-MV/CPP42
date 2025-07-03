#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <map>

int	main(void) {
	std::string	row;
	std::fstream fin;
	std::map<std::string, std::string> database;
	fin.open("data.csv", std::ios::in);
	
	std::getline(fin, row);
	while (std::getline(fin, row)) {
		std::string cols;
		std::stringstream sstream(row);

		std::getline(sstream, cols, ',');
		std::string col1 = cols;
		std::getline(sstream, cols, ',');
		database[col1] = cols;
		std::cout << database.find(col1)->first << ": " << database.find(col1)->second << std::endl;
	}
	

}
