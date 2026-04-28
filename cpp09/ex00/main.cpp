#include "Input.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Input file missing. Expected: ./btc <input_file>" << std::endl;
		return (1);
	}
	BitcoinExchange db("data.csv");
	Input in(argv[1]);

	db.insertDatabase();
	in.findAndPrintRows(db);
}