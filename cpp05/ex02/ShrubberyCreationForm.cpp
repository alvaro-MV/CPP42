
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm("ShrubberyCreationForm", 145, 137), 
																		target(target),
																		_signed(false) {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form) 
: AForm(form.getName(), form.getSignGrade(), form.getExecGrade()),
      target(form.target), _signed(form._signed) {};

 ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& form) {
	this->_signed = form._signed;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "DESTRUCTOR: ShrubberyCreationForm archived." << std::endl;
}

const std::string ShrubberyCreationForm::getTarget(void) const {
	return (this->target);
}

void ShrubberyCreationForm::executeAction(Bureaucrat const &executor) const {
	(void) executor;
	std::ifstream file;
	std::string ascii_tree = 
		"	/\\\n"
        "  /  \\\n"
        " /____\\\n"
        "   ||\n"
        "   ||\n";
	
	file.open((this->getTarget() + "_shrubbery").c_str());
	std::ofstream output((this->getTarget() + "_shrubbery").c_str(), std::ios::ate|std::ios::trunc); // append at end of file
	output << ascii_tree;
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& form) {
	os << "(";
	os << "ShrubberyCreationForm ";
	os << form.getTarget();
	os << ")";
	return (os);
}