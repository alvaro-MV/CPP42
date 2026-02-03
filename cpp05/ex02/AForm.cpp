#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int signGrade, int execGrade)
: _name(name), _signGrade(signGrade), _execGrade(execGrade), _signed(false)
{
    if (_signGrade < 1 || _execGrade < 1)
        throw GradeTooHighException();
    if (_signGrade > 150 || _execGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
: _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade), _signed(other._signed) {}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        _signed = other._signed;
    return *this;
}

AForm::~AForm() {}

const std::string &AForm::getName() const { return _name; }
int AForm::getSignGrade() const { return _signGrade; }
int AForm::getExecGrade() const { return _execGrade; }
bool AForm::isSigned() const { return _signed; }

void AForm::beSigned(Bureaucrat const &b)
{
    if (b.getGrade() > _signGrade)
        throw GradeTooLowException();
    _signed = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (!_signed)
        throw FormNotSignedException();
    if (executor.getGrade() > _execGrade)
        throw GradeTooLowException();

    executeAction(executor);
}

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

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
    os << f.getName()
       << " (sign grade: " << f.getSignGrade()
       << ", exec grade: " << f.getExecGrade()
       << ", signed: " << (f.isSigned() ? "yes" : "no") << ")";
    return os;
}