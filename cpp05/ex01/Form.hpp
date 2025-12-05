#ifndef FORM_H
#define FORM_H

// #include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <exception>
#include <cstring>

class Bureaucrat;

class Form {
	private:
		const std::string name;
		const size_t sign_grade;
		const size_t exec_grade;
		bool _signed;

	public:
		Form(const std::string name,
			size_t sign_grade,
			size_t exec_grade);
		Form(const Form& form);
		Form& operator=(const Form& form);
		~Form();

		const std::string getName(void) const;
		const size_t &getSignGrade(void) const;
		const size_t &getExecGrade(void) const;
		void beSigned(Bureaucrat& bureaucrat);
		bool isSigned(void) const;

		class GradeTooHighException : public std::exception {
			public:
				const char* what(void) const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what(void) const throw();
		};
};
 
std::ostream& operator<<(std::ostream& os, const Form& form);

#endif