#ifndef CONTACTS_H
# define CONTACTS_H

# include <string>
# include <string.h>
# include <unistd.h>
# include <cstring>
# include <iostream>

class Contact
{
	private:
		
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string phone_number;
		std::string darkest_secret;

	int	init = 0;
	
	public:
		Contact();
		Contact (const Contact &a);
		~Contact();
		Contact & operator = (const Contact &a);

		void display_contact();
		void init_contact();
		int  is_init();
};

#endif