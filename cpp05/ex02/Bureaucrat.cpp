#include "Bureaucrat.hpp"
#include "AForm.hpp"

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
        this->grade = other.grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

// Getters
const std::string &Bureaucrat::getName() const { return name; }
size_t Bureaucrat::getGrade() const { return grade; }

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

void Bureaucrat::signForm(AForm &form) {
    form.beSigned(*this);

    try {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << name << " couldn't sign " << form.getName()
                << " because " << e.what() << std::endl;
    }
}


void Bureaucrat::executeForm(AForm const & form) {
	try {
		form.execute(*this);
		std::cout << getName();
		std::cout << " executed ";
		std::cout << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << getName();
		std::cout << " couldn't execute ";
		std::cout << form.getName() << std::endl;
	}
}

