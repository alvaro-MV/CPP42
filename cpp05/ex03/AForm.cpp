#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Constructor
AForm::AForm(const std::string &name, size_t sign_grade, size_t exec_grade)
    : name(name), sign_grade(sign_grade), exec_grade(exec_grade), _signed(false)
{
    if (sign_grade < 1 || exec_grade < 1)
        throw GradeTooHighException();
    if (sign_grade > 150 || exec_grade > 150)
        throw GradeTooLowException();
}

// Copy constructor
AForm::AForm(const AForm &other)
    : name(other.name),
      sign_grade(other.sign_grade),
      exec_grade(other.exec_grade),
      _signed(other._signed)
{}

// Operator=
AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        *this = other;
    return *this;
}

AForm::~AForm() {}

// Getters
const std::string &AForm::getName() const { return name; }
size_t AForm::getSignGrade() const { return sign_grade; }
size_t AForm::getExecGrade() const { return exec_grade; }
bool AForm::isSigned() const { return _signed; }

// beSigned
void AForm::beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getGrade() > this->sign_grade)
        throw GradeTooLowException();
    this->_signed = true;
}

// execute()
void AForm::execute(Bureaucrat const &executor) const
{
    if (!this->_signed)
        throw FormNotSignedException();
    if (executor.getGrade() > this->exec_grade)
        throw GradeTooLowException();

    this->executeAction(executor);
}

// Exceptions what()

const char *AForm::GradeTooHighException::what() const throw()
{
    return "AForm: grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "AForm: grade too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "AForm: form not signed";
}

// operator<<
std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << form.getName()
       << " (sign grade: " << form.getSignGrade()
       << ", exec grade: " << form.getExecGrade()
       << ", signed: " << (form.isSigned() ? "yes" : "no") << ")";
    return os;
}
