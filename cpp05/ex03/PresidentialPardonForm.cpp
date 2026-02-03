#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm("PresidentialPardonForm", 25, 5), 
																		  target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form) 
: AForm(form.getName(), form.getSignGrade(), form.getExecGrade()),
      target(form.target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& form) {
	(void) form;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "DESTRUCTOR: PresidentialPardonForm archived." << std::endl;
}

const std::string PresidentialPardonForm::getTarget(void) const {
	return (this->target);
}

void PresidentialPardonForm::executeAction(Bureaucrat const &executor) const {
	(void) executor;
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
