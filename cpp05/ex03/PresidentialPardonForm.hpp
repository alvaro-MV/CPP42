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
		bool _signed = false;

	public:
		PresidentialPardonForm(const std::string target): AForm("PresidentialPardonForm", 25, 5), target(target) {};

		PresidentialPardonForm(const PresidentialPardonForm& sh_form);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& sh_form);
		~PresidentialPardonForm();

		const std::string getTarget(void) const;
		void executeAction() const;
};
 
std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif