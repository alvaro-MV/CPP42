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
	std::cout << "Hasta luego " << this->first_name << std::endl;
}

std::string	Contact::get_first_name(void)
{
	return (this->first_name);
}

std::string	Contact::get_last_name(void)
{
	return (this->last_name);
}

std::string	Contact::get_nickname(void)
{
	return (this->nickname);
}


std::string	padd_2_10(size_t len)
{
	std::string	ret = "";

	for (size_t i  = 0; i < 10 - len; i++)
		ret += " ";
	return (ret);
}

std::string	get_string_10_wide(std::string s, int field)
{
	static	size_t		count[3];
	std::string	ten_wide;
	size_t		len_wide;

	if (field == -1)
	{
		if (field == -1)
			bzero(count, 3 * sizeof(size_t));
		return ("");
	}
	else if (count[field] > s.length())
		return ("");
	ten_wide = s.substr(count[field], 9);
	len_wide = ten_wide.length();
	if (len_wide < 9 || s.length() == 9)
		ten_wide = padd_2_10(len_wide) + ten_wide;
	else
		ten_wide += std::string(".");
	ten_wide += "|";
	count[field] += 9;
	return (ten_wide);
}

void	print_10_wide(std::string name_10_wide)
{
	if (!name_10_wide.empty())
		std::cout << name_10_wide;
	else
		std::cout << padd_2_10(0) << "|";
}

void	Contact::display_contact(void)
{
	std::string	f;
	std::string	l;
	std::string	n;
	size_t		line_number = 0;

	do {
		f = get_string_10_wide(this->first_name, 0);
		l = get_string_10_wide(this->last_name, 1);
		n = get_string_10_wide(this->nickname, 2);
		if (f.empty() && l.empty() && n.empty())
		{
			get_string_10_wide("", -1);
			return ;
		}
		if (line_number > 0)
			std::cout << "   ";
		print_10_wide(f);
		print_10_wide(l);
		print_10_wide(n);
		line_number++;
		std::cout << std::endl;
	}
	while (!f.empty() || !l.empty() || !n.empty());
}

void Contact::init_contact()
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	do {
		if (first_name.empty())
		{
			std::cout << "Enter first name: ";
			first_name = "-----";
		}
		if (!(std::cin >> first_name))
		{
			std::cerr << "Invalid first_name.\n";
			std::cin.clear();
			std::cin.ignore();
		}
	} while (first_name.empty());
	this->first_name = first_name;

	do {
		if (last_name.empty())
			(std::cout << "Enter last name: ", last_name = "-----");
		if (!(std::cin >> last_name))
		{
			std::cerr << "Invalid last_name.\n";
			std::cin.clear();
			std::cin.ignore();
		}
	} while (last_name.empty());
	this->last_name = last_name;

	do {
		if (nickname.empty())
			(std::cout << "Enter nickname: ", nickname = "-----");
		if (!(std::cin >> nickname))
		{
			std::cerr << "Invalid nickname.\n";
			std::cin.clear();
			std::cin.ignore();
		}
	} while (nickname.empty());
	this->nickname = nickname;

	size_t n_digit = 0;
	do {
		if (n_digit < phone_number.length())
			std::cout << "Incorrect phone number" << std::endl;
		n_digit = 0;
		std::cout << "Enter phone number: ";
		std::cin >> phone_number;
		while (std::isdigit(phone_number[n_digit]) && phone_number[n_digit])
			n_digit++;
	} while (n_digit < phone_number.length());
	this->phone_number = phone_number;

	do {
		if (darkest_secret.empty())
			(std::cout << "Enter darkest secret: ", darkest_secret = "-----");
		if (!(std::cin >> darkest_secret))
		{
			std::cerr << "Invalid darkest secret";
			std::cin.clear();
			std::cin.ignore();
		}
	} while (darkest_secret.empty());
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