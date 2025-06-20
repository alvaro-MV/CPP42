#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contact_array[8];
		int		contact_idx;

	public:
		PhoneBook();
		~PhoneBook();
};

#endif