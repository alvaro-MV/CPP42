
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

void ShrubberyCreationForm::executeAction(Bureaucrat const &executor) const {
	std::ifstream file;
	std::string ascii_tree = 
		"	/\\\n"
        "  /  \\\n"
        " /____\\\n"
        "   ||\n"
        "   ||\n";
	
	file.open(this->getTarget() + "_shrubbery");
	std::ofstream output(this->getTarget() + "_shrubbery", std::ios::ate|std::ios::trunc); // append at end of file
	output << ascii_tree;
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& form) {
	os << "(";
	os << "ShrubberyCreationForm ";
	os << form.getTarget();
	os << ")";
	return (os);
}