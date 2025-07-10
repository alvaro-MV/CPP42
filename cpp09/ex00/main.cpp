#include "BitcoinExchange.hpp"

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
	
	if (!fin.is_open()) {
        std::cerr << "Error: could not open file " << std::endl;
		exit(1);
    }

	std::getline(fin, row);
	while (std::getline(fin, row)) {
		str _exchange;
		std::stringstream sstream(row);

		std::getline(sstream, _exchange, del);
		str date = _exchange;
		date = transform(date);
		// std::cout << date << std::endl;

		std::getline(sstream, _exchange, del);
		str value = _exchange;
		value = transform(value);

		db.insert(std::pair<str, str>(date, value));
	}
	fin.close();
}

int	main(int argc, char **argv) {

	if (argc != 2)
	{
		std::cerr << "./btc <file>" << std::endl;
		return (1);
	}
	database db;
	fill_db(db, "data.csv", ',', identity);

	database input;
	fill_db(input, argv[1], '|', remove_extra_spaces);
	database::iterator it = input.begin();

	while (it != input.end()) {
		if (!verifyDate(it->first) || !verifyValue(it->second))
		{
			it++;
			continue ;
		}
		database::iterator rata = db.find(it->first);
		if (rata == db.end())
			rata = findNearestDate(db, it->first);
		std::cout << "fecha escogida: " << rata->first << " " << it->first << " => " << it->second;
		std::cout << " = " << stoff(it->second) * stoff(rata->second) << std::endl;
		it++;
	}
}
