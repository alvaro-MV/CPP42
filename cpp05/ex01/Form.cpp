#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string name,
	size_t sign_grade,
	size_t exec_grade): name(name),
						sign_grade(sign_grade),
						exec_grade(exec_grade) {
	if (sign_grade > 150)
		throw Form::GradeTooLowException();
	else if (sign_grade < 1)
		throw Form::GradeTooHighException();
	if (exec_grade > 150)
		throw Form::GradeTooLowException();
	else if (exec_grade < 1)
		throw Form::GradeTooHighException();
};

Form::Form(const Form& form): name(form.name),
							  sign_grade(form.sign_grade),
							  exec_grade(form.exec_grade),
							  _signed(form._signed) {};

Form& Form::operator=(const Form& form) {
	if (this != &form)
		*this = copy;
	return (*this);
}

Form::~Form() {
	std::cout << "Form archived." << std::endl;
}

const std::string Form::getName(void) const {
	return (this->name);
}

const size_t &Form::getSignGrade(void) const {
	return (this->sign_grade);
}

const size_t &Form::getExecGrade(void) const {
	return (this->exec_grade);
}

void Form::beSigned(Bureaucrat& bureaucrat) {
	if (this->getSignGrade() >= bureaucrat.getGrade())
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}

bool Form::isSigned(void) const {
	return (this->_signed);
}

const char *Form::GradeTooHighException::what(void) const throw() {

	return ("Form: grade too high");
}

const char *Form::GradeTooLowException::what(void) const throw() {

	return ("Form: grade too low");
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "(";
	os << form.getName();
	os << ", form ";
	os << (form.isSigned() ? "signed" : "not signed");
	os << " that can be signed with grade ";
	os << form.getSignGrade();
	os << " and be executed with grade ";
	os << form.getExecGrade();
	os << ")";
	return (os);
}