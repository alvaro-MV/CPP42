#ifndef INPUT_H
# define INPUT_H

#include "DataBtc.hpp"
#include "Database.hpp"

class Input: public DataBtc {
	public:
		Input(std::string filename);
		Input(const Input &input);
		Input &operator=(const Input &input);
		~Input();

		void findAndPrintRows(Database &db);
};

#endif