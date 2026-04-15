#include "Input.hpp"

int main(int argc, char **argv) {
	(void) argc;
	BitcoinExchange db("data.csv");
	Input in(argv[1]);

	db.insertDatabase();
	in.findAndPrintRows(db);
}