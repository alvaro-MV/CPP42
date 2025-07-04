#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <map>

typedef std::map<std::string, std::string> database;

void	fill_database(database &db) {
	std::string	row;
	std::fstream fin;
	
	fin.open("data.csv", std::ios::in);
	
	std::getline(fin, row);
	while (std::getline(fin, row)) {
		std::string cols;
		std::stringstream sstream(row);

		std::getline(sstream, cols, ',');
		std::string col1 = cols;
		std::getline(sstream, cols, ',');
		db.insert(std::pair<std::string, std::string>(col1, cols));
		// std::cout << db.find(col1)->first << ": " << db.find(col1)->second << std::endl;
	}
	std::cout << "Este es la de 2022-12-22: " << db.find("2021-12-22")->second << std::endl;
}

std::string remove_extra_spaces(const std::string& input) {
    std::stringstream ss(input);
    std::string word, result;

    while (ss >> word) {
        if (!result.empty())
            result += " ";
        result += word;
    }

    return result;
}

int	itoa(std::string str, bool &fail) {
	int num;
	std::istringstream iss(str);

    iss >> num;
	if (iss.fail() == false)
	{
		fail = false;
		return (num);
	}
	else
	{
		fail = true;
		return (-1);
	}
}

int	main(void) {

	database db;
	fill_database(db);
	std::cout << "Por segunda vez de 2022-12-22: " << db.find("2021-12-22")->second << std::endl;

	std::string	row;
	std::fstream fin;
	fin.open("input.txt", std::ios::in);
	
	std::getline(fin, row);
	while (std::getline(fin, row)) {
		std::string cols;
		std::stringstream sstream(row);

		std::getline(sstream, cols, '|');
		std::string col1 = cols;
		col1 = remove_extra_spaces(col1);
		// std::cout << col1 << std::endl;
		std::getline(sstream, cols, '|');
		cols = remove_extra_spaces(cols);
		bool	fail;
		
		database::iterator value_in_db = db.find(col1);
		if (value_in_db != db.end())
			std::cout << db.find(col1)->first << ": s" << db.find(col1)->second << ": " << itoa(db.find(col1)->second, fail) * itoa(cols, fail) << std::endl;
	}
}
