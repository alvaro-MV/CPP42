#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <exception>
#include <cstring>
#include <cstdlib>

class Bureaucrat;

class RobotomyRequestForm : public AForm{
	private:
		const std::string target;
		bool _signed;

	public:
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& sh_form);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& sh_form);
		~RobotomyRequestForm();

		const std::string getTarget(void) const;
		void executeAction(Bureaucrat const &executor) const;
};
 
std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif