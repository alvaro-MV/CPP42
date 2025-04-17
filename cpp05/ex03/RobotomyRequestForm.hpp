#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <exception>
#include <cstring>

class Bureaucrat;

class RobotomyRequestForm : public AForm{
	private:
		const std::string target;
		bool _signed = false;

	public:
		RobotomyRequestForm(const std::string target): AForm("RobotomyRequestForm", 72, 45), target(target) {};

		RobotomyRequestForm(const RobotomyRequestForm& sh_form);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& sh_form);
		~RobotomyRequestForm();

		const std::string getTarget(void) const;
		void executeAction() const;
};
 
std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif