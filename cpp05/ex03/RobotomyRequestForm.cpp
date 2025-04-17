#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form) 
: AForm(form.getName(), form.getSignGrade(), form.getExecGrade()),
      target(form.target) {};

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& form) {
	this->_signed = form._signed;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "DESTRUCTOR: RobotomyRequestForm archived." << std::endl;
}

const std::string RobotomyRequestForm::getTarget(void) const {
	return (this->target);
}

void RobotomyRequestForm::executeAction(void) const {
	std::cout << "Bzzzzzzzz... drilling noises..." << std::endl;

    if (std::rand() % 2 == 0) {
        std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy failed on " << this->getTarget() << "." << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& form) {
	os << "(";
	os << "RobotomyRequestForm ";
	os << form.getTarget();
	os << ")";
	return (os);
}
