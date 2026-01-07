#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("RobotomyRequestForm", 72, 45), 
											   target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form) 
: AForm(form.getName(), form.getSignGrade(), form.getExecGrade()),
      target(form.target) {};

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& form) {
	(void) form;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "DESTRUCTOR: RobotomyRequestForm archived." << std::endl;
}

const std::string RobotomyRequestForm::getTarget(void) const {
	return (this->target);
}

void RobotomyRequestForm::executeAction(Bureaucrat const &executor) const {
	(void) executor;
	std::cout << "Bzzzzzzzz... drilling noises..." << std::endl;

    if (rand() % 2 == 0) {
        std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy failed on " << this->getTarget() << "." << std::endl;
    }
}
