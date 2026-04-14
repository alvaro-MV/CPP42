#include "Input.hpp"

int main() {
	Database db("data.csv");
	Input in("input.txt");

	db.insertDatabase();
	in.findAndPrintRows(db);
}