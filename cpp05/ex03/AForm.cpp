#include "AForm.hpp"

// operator<<, form grade si alguno, beSigned (compare)
// signForm (facilito).

AForm::AForm(const AForm& form): name(form.name),
							  sign_grade(form.sign_grade),
							  exec_grade(form.exec_grade) {};

AForm& AForm::operator=(const AForm& form) {
	this->_signed = form._signed;
	return (*this);
}

std::string AForm::getName(void) const {
	return (this->name);
}

size_t AForm::getSignGrade(void) const {
	return (this->sign_grade);
}

size_t AForm::getExecGrade(void) const {
	return (this->exec_grade);
}

void AForm::beSigned(Bureaucrat& bureaucrat) {
	if (this->getSignGrade() > bureaucrat.getGrade()) //Se asume pote
	// {
		this->_signed = true;
		// std::cout << "This form is signed" << std::endl;
	// }
	// else
		// std::cout << "This form isn't signed." << std::endl;
}

bool AForm::isSigned(void) const {
	return (this->_signed);
} 

const char *AForm::GradeTooHighException::what(void) const throw() {

	std::string problem = "GradeTooHighException: grade "
	+ std::to_string(this->_grade)
	+" is higher than grade 1";
	
	char *ret = new char[problem.length() + 1];
	std::strcpy(ret, problem.c_str());
	return (ret);
}

const char *AForm::GradeTooLowException::what(void) const throw() {

	std::string problem = "Gradetoolowexception: grade " 
	+ std::to_string(this->_grade)
	+ " is lower than grade 150";

	char *ret = new char[problem.length() + 1];
	std::strcpy(ret, problem.c_str());
	return (ret);
}

const char *AForm::FormNotSignedException::what(void) const throw() {

	std::string problem = "FormNotSignedException: Form is not signed.";
	char *ret = new char[problem.length() + 1];
	std::strcpy(ret, problem.c_str());
	return (ret);
}

int AForm::execute(const Bureaucrat& executor) const {
	try {
		if (!this->isSigned())
			throw AForm::FormNotSignedException(executor.getGrade());
		if (executor.getGrade() > this->getExecGrade())
			throw GradeTooLowException(executor.getGrade());
    	this->executeAction(); // 👈 método virtual puro protegido
		return (1);
	}
	catch (std::exception &e) {
		e.what();
		return (0);
	}
}


std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os << "(";
	os << form.getName();
	os << ", form that can be signed with grade ";
	os << form.getSignGrade();
	os << " and be executed with grade ";
	os << form.getExecGrade();
	os << ")";
	return (os);
}