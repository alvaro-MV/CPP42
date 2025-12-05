
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm("ShrubberyCreationForm", 145, 137), 
																		target(target) {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form) 
: AForm(form.getName(), form.getSignGrade(), form.getExecGrade()),
      target(form.target) {};

 ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& form) {
	(void) form;
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
	std::string ascii_tree = 
		"	/\\\n"
        "  /  \\\n"
        " /____\\\n"
        "   ||\n"
        "   ||\n";
	
	std::ofstream output((this->getTarget() + "_shrubbery").c_str()); // append at end of file
	output << ascii_tree;
	output.close();
}
