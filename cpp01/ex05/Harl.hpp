#ifndef HARL_H
# define HARL_H

#include <string>
#include <iostream>

class Harl
{
	public:

		Harl();
		Harl(const Harl& harl);
		Harl &operator=(const Harl& harl);
		~Harl();
		void complain(std::string level);

	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

		std::string	names[4];
		void (Harl::*levels[4])(void);
;
};

#endif