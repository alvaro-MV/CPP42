#include "Form.hpp"
#include "Bureaucrat.hpp"

// operator<<, form grade si alguno, beSigned (compare)
// signForm (facilito).

Form::Form(const Form& form): name(form.name),
							  sign_grade(form.sign_grade),
							  exec_grade(form.exec_grade) {};

Form& Form::operator=(const Form& form) {
	this->_signed = form._signed;
	return (*this);
}

Form::~Form() {
	std::cout << "Form archived." << std::endl;
}

const std::string Form::getName(void) const {
	return (this->name);
}

const size_t Form::getSignGrade(void) const {
	return (this->sign_grade);
}

const size_t Form::getExecGrade(void) const {
	return (this->exec_grade);
}

void Form::beSigned(Bureaucrat& bureaucrat) {
	if (this->getSignGrade() > bureaucrat.getGrade()) //Se asume pote
	{
		this->_signed = true;
		std::cout << "This form is signed" << std::endl;
	}
	else
		std::cout << "This form couldn't be signed." << std::endl;
}

bool Form::isSigned(void) {
	return (this->_signed);
}

const char *Form::GradeTooHighException::what(void) const throw() {

	std::string problem = "GradeTooHighException: grade "
	+ std::to_string(this->_grade)
	+" is higher than grade 1";
	
	char *ret = new char[problem.length() + 1];
	std::strcpy(ret, problem.c_str());
	return (ret);
}

const char *Form::GradeTooLowException::what(void) const throw() {

	std::string problem = "Gradetoolowexception: grade " 
	+ std::to_string(this->_grade)
	+ " is lower than grade 150";

	char *ret = new char[problem.length() + 1];
	std::strcpy(ret, problem.c_str());
	return (ret);
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "(";
	os << form.getName();
	os << ", form that can be signed with grade ";
	os << form.getSignGrade();
	os << " and be executed with grade ";
	os << form.getExecGrade();
	os << ")";
	return (os);
}