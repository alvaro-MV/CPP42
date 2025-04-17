#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat) {
	try {
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException(grade);
		this->grade = bureaucrat.grade;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		const char *error = e.what();
		std::cout << error << std::endl;
	}
	
	try {
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException(grade);
		this->grade = bureaucrat.grade;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		const char *error = e.what();
		std::cout << error << std::endl;
	}
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat) {
	try {
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException(grade);
		this->grade = bureaucrat.grade;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		const char *error = e.what();
		std::cout << error << std::endl;
	}
	
	try {
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException(grade);
		this->grade = bureaucrat.grade;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		const char *error = e.what();
		std::cout << error << std::endl;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	std::cout << "DESTRUCTOR: Bureaucrat destroyed." << std::endl;
}

const std::string Bureaucrat::getName(void) const {
	return (this->name);
}

void Bureaucrat::setGrade(size_t grade) {
	try {
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException(grade);
		this->grade = grade;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		const char *error = e.what();
		std::cout << error << std::endl;
	}
	
	try {
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException(grade);
		this->grade = grade;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		const char *error = e.what();
		std::cout << error << std::endl;
	}
}

size_t Bureaucrat::getGrade(void) const {
	try {
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException(grade);
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		const char *error = e.what();
		std::cout << error << std::endl;
	}
	
	try {
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException(grade);
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		const char *error = e.what();
		std::cout << error << std::endl;
	}
	return (this->grade);
}

void Bureaucrat::incrGrade(size_t incr) {
	try {
		if (incr >= this->grade)
			throw Bureaucrat::GradeTooHighException(grade - incr);
		this->grade -= incr;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		const char *error = e.what();
		std::cout << error << std::endl;
	}
}

void Bureaucrat::decrGrade(size_t decr) {
	try {
		if (this->grade + decr > 150)
			throw Bureaucrat::GradeTooLowException(grade + decr);
		this->grade += decr;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		const char *error = e.what();
		std::cout << error << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	std::cout << "{";
	os <<  bureaucrat.getName();
	os << ", bureaucrat grade ";
	os << std::to_string(bureaucrat.getGrade());

	std::cout << "}";
	return (os);
}

void Bureaucrat::signForm(AForm &form) {
	form.beSigned(*this);
	if (form.isSigned()) {
		std::cout << (*this);
		std::cout << " signed form with sign grade: ";
		std::cout << form.getSignGrade() << std::endl;
	}
	else {
		std::cout << (*this);
		std::cout << " couldn't signed ";
		std::cout << form;
		std::cout << ", becouse it's rank is low in this company." 
		<< std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) {
	if (form.execute(*this))
	{
		std::cout << *this;
		std::cout << " executed ";
		std::cout << form << std::endl;
	}
	else
	{
		std::cout << *this;
		std::cout << " couldn't execute ";
		std::cout << form << std::endl;
	}
}
	
const char *Bureaucrat::GradeTooHighException::what(void) const throw() {

	std::string problem = "GradeTooHighException: grade "
	+ std::to_string(this->_grade)
	+" is higher than grade 1";
	
	char *ret = new char[problem.length() + 1];
	std::strcpy(ret, problem.c_str());
	return (ret);
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw() {

	std::string problem = "GradeTooLowException: grade " 
	+ std::to_string(this->_grade)
	+ " is lower than grade 150";

	char *ret = new char[problem.length() + 1];
	std::strcpy(ret, problem.c_str());
	return (ret);
}
