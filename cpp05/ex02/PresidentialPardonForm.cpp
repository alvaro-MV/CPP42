#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm("PresidentialPardonForm", 25, 5), 
																		  target(target),
																		  _signed(false) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form) 
: AForm(form.getName(), form.getSignGrade(), form.getExecGrade()),
      target(form.target), _signed(form._signed) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& form) {
	this->_signed = form._signed;
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

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& form) {
	os << "(";
	os << "PresidentialPardonForm ";
	os << form.getTarget();
	os << ")";
	return (os);
}
