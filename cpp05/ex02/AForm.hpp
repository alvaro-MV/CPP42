#ifndef AFORM_H
# define AFORM_H

# include "Bureaucrat.hpp"
# include <string>
# include <iostream>
# include <exception>
# include <cstring>

class Bureaucrat;

class AForm {

private:
    const std::string name;
    const size_t sign_grade;
    const size_t exec_grade;
    bool _signed;

public:
    AForm(const std::string &name, size_t sign_grade, size_t exec_grade);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm();

    const std::string &getName() const;
    size_t getSignGrade() const;
    size_t getExecGrade() const;
    bool isSigned() const;

    void beSigned(Bureaucrat const &bureaucrat);

    void execute(Bureaucrat const &executor) const; // subject-compliant
    virtual void executeAction(Bureaucrat const &executor) const = 0;

    // Exceptions
    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class FormNotSignedException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};
 
std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif