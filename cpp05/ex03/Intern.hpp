#ifndef INTERN_H
# define INTERN_H

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string.h>

class Intern {
	public:
		Intern() {};
		Intern(const Intern &intern);
		Intern& operator=(const Intern& intern);
		~Intern();

		AForm *makeForm(std::string name, std::string target);

};

#endif