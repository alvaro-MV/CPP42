#include "Bureaucrat.hpp"

// Constructor
Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : name(name), grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : name(other.name), grade(other.grade)
{}

// Operator=
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    	*this = other;

    return *this;
}

Bureaucrat::~Bureaucrat() {}

// Getters
const std::string &Bureaucrat::getName() const { return name; }
int Bureaucrat::getGrade() const { return grade; }

// Modifiers
void Bureaucrat::incrGrade()
{
    if (grade - 1 < 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrGrade()
{
    if (grade + 1 > 150)
        throw GradeTooLowException();
    grade++;
}

// what()
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat: grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat: grade too low";
}

// Operator <<
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}
