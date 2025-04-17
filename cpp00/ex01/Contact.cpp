#include "Contact.hpp"

/* 
	-Controlar si el hay contactos para el display contacts.

	-Controlar si la entrada es numérica para el phone number
 */

Contact::Contact() {

	std::cout << "";
	this->init = 0;
}

Contact::~Contact()
{
	std::cout << "Hasta luego" << this->first_name << std::endl;
}

void Contact::display_contact()
{
	int i = 0, finished_info = 0, pos = 0, pos_offset = 0;
	char padding[10];
	size_t len_rest;
	std::string str_to_display[3] = {first_name, last_name, nickname};
	
	while (finished_info < 3) 
	{
		finished_info = 0;
		i = 0;
		while (i < 3)
		{
			if (pos < str_to_display[i].length())
			{
				if (i == 0)
					std::cout << "|";
				if (strlen(&str_to_display[i].data()[pos - pos_offset]) <= 10)
				{
					std::cout << str_to_display[i].substr(pos - pos_offset, 10);
					len_rest = strlen(&str_to_display[i].data()[pos - pos_offset]);
				}
				else
				{
					if (!pos)
						std::cout << str_to_display[i].substr(pos, 9) << ".";
					else
						std::cout << str_to_display[i].substr(pos - pos_offset, 9) << ".";
					len_rest = 10;
				}
				if (i < 2)
				{
					memset(padding, 0, 10);
					memset(padding, 32, 10 - len_rest);
					std::cout << padding;
					std::cout  << "|" ;
				}
			}
			else
				finished_info++;
			i++;
		}
		std::cout << std::endl;
		pos += 10;
		pos_offset++;
	}
}

void Contact::init_contact()
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	std::cout << "Enter first name: ";
	std::cin >> first_name;
	this->first_name = first_name;

	std::cout << "Enter last name: ";
	std::cin >> last_name;
	this->last_name = last_name;

	std::cout << "Enter nickname: ";
	std::cin >> nickname;
	this->nickname = nickname;

	int n_digit = 0;
	do {
		if (n_digit < phone_number.length())
			std::cout << "Incorrect phone number" << std::endl;
		n_digit = 0;
		std::cout << "Enter phone number: ";
		std::cin >> phone_number;
		while (std::isdigit(phone_number[n_digit]) && phone_number[n_digit])
			n_digit++;
	}
	while (n_digit < phone_number.length());

	this->phone_number = phone_number;

	std::cout << "Enter darkest secret: ";
	std::cin >> darkest_secret;
	this->darkest_secret = darkest_secret;
	this->init = 1;

	std::cout << std::endl;
}

int Contact::is_init() {
	if (this->init)
		return (1);
	else
		return (0);
}