#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	std::cout << "****Welcome to your phonebookk****" << std::endl;

	std::string	command;
	char contact_break[40];
	int i;
		
	memset(contact_break, 45, 40);
	while (1)
	{
		std::cout << std::endl << "$ ";
		std::cin >> command;
		if (command.compare("EXIT") == 0)
			break ;
		else if (command.compare("ADD") == 0)
		{
			if (this->contact_idx == 9)
				this->contact_idx = 0;
			this->contact_array[this->contact_idx].init_contact();
			this->contact_idx++;
		}
		else if (command.compare("SEARCH") == 0)
		{
			i = 0;
			while (contact_array[i].is_init())
			{
				std::cout << "[" << i << "]";
				this->contact_array[i].display_contact();
				std::cout << contact_break << std::endl;
				i++;
			}
		}
		else
			continue ;
	}
}

PhoneBook::~PhoneBook()
{

}
