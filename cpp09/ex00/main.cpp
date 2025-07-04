#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <map>

typedef std::string str;
typedef std::map<str, str> database;

str remove_extra_spaces(const str& input) {
    std::stringstream ss(input);
    str word, result;

    while (ss >> word) {
        if (!result.empty())
            result += " ";
        result += word;
    }

    return result;
}

str	identity(const str &input) {
	str iden = input;
	return (iden);
}

void	fill_db(database &db, const char *file, char del, str (*transform)(const str&)) {
	str	row;
	std::fstream fin;
	fin.open(file, std::ios::in);
	
	std::getline(fin, row);
	while (std::getline(fin, row)) {
		str cols;
		std::stringstream sstream(row);

		std::getline(sstream, cols, del);
		str col1 = cols;
		col1 = transform(col1);
		std::cout << col1 << std::endl;
		std::getline(sstream, cols, del);
		cols = transform(cols);
		db.insert(std::pair<str, str>(col1, cols));
		// bool	fail;
		
		// database::iterator value_in_db = db.find(col1);
		// if (value_in_db != db.end())
		// 	std::cout << db.find(col1)->first << ": s" << db.find(col1)->second << ": " << itoa(db.find(col1)->second, fail) * itoa(cols, fail) << std::endl;
	}
}

int	itoa(str str, bool &fail) {
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
	fill_db(db, "data.csv", ',', identity);
	// std::cout << "Por segunda vez de 2022-12-22: " << db.find("2021-12-22")->second << std::endl;

	database input;
	fill_db(input, "input.txt", '|', remove_extra_spaces);
	std::cout << db.find("2011-01-09")->first << ": s";// << db.find("2011-01-09")->second << ": " << itoa(db.find(col1)->second, fail) * itoa(, fail) << std::endl;
}
