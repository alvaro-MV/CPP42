#include "Input.hpp"

int main() {
	BitcoinExchange db("data.csv");
	Input in("chatgpt_pruebas.txt");

	db.insertDatabase();
	in.findAndPrintRows(db);
}