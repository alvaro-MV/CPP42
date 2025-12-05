
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

// operator<<, form grade si alguno, beSigned (compare)
// signForm (facilito).


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form) 
: AForm(form.getName(), form.getSignGrade(), form.getExecGrade()),
      target(form.target) {};

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

void ShrubberyCreationForm::executeAction(void) const {
	std::string ascii_tree = 
		"	/\\\n"
        "  /  \\\n"
        " /____\\\n"
        "   ||\n"
        "   ||\n";
	
	std::ofstream output((this->getTarget() + "_shrubbery").c_str()); // append at end of file
	output << ascii_tree;
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& form) {
	os << "(";
	os << "ShrubberyCreationForm ";
	os << form.getTarget();
	os << ")";
	return (os);
}