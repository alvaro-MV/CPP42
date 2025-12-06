#ifndef PRESIDENTIALPARDONFORM
#define PRESIDENTIALPARDONFORM

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <exception>
#include <cstring>

class Bureaucrat;

class PresidentialPardonForm : public AForm{
	private:
		const std::string target;

	public:
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& sh_form);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& sh_form);
		~PresidentialPardonForm();

		const std::string getTarget(void) const;
		void executeAction(Bureaucrat const &executor) const;
};
 
#endif