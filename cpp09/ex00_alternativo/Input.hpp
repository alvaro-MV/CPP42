#ifndef INPUT_H
# define INPUT_H

#include "DataBtc.hpp"

class Input: public DataBtc {
	public:
		Input();
		Input(const Input &input);
		Input &operator=(const Input &input);
		~Input();

		

};

#endif