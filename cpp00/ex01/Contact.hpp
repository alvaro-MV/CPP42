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
		int	init;
	
	public:
		Contact();
		~Contact();

		void display_contact();
		std::string	get_first_name(void);
		std::string	get_last_name(void);
		std::string	get_nickname(void);
		void init_contact();
		int  is_init();
};

#endif