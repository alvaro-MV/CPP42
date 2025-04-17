#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat) {
	this->grade = bureaucrat.grade;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destroyed." << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat) {
	this->grade = bureaucrat.grade;
	return (*this);
}

const std::string Bureaucrat::getName(void) const {
	return (this->name);
}

void Bureaucrat::setGrade(size_t grade) {
	this->grade = grade;
}

size_t Bureaucrat::getGrade(void) const {
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

const char *Bureaucrat::GradeTooHighException::what(void) const throw() {

	std::string problem = "GradeTooHighException: grade "
	+ std::to_string(this->_grade)
	+" is higher than grade 1";
	
	char *ret = new char[problem.length() + 1];
	std::strcpy(ret, problem.c_str());
	return (ret);
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw() {

	std::string problem = "Gradetoolowexception: grade " 
	+ std::to_string(this->_grade)
	+ " is lower than grade 150";

	char *ret = new char[problem.length() + 1];
	std::strcpy(ret, problem.c_str());
	return (ret);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os <<  bureaucrat.getName();
	os << ", bureaucrat grade ";
	os << std::to_string(bureaucrat.getGrade());
	return (os);
}