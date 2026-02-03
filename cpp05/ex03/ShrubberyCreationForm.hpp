
#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

// #include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <exception>
#include <cstring>

class Bureaucrat;

class ShrubberyCreationForm : public AForm{
	private:
		const std::string target;

	public:
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& sh_form);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& sh_form);
		~ShrubberyCreationForm();

		const std::string getTarget(void) const;
		void executeAction(Bureaucrat const &executor) const;
};
 

#endif