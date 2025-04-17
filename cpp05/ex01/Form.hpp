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
		bool _signed = false;

	public:
		Form(const std::string name,
			size_t sign_grade,
			size_t exec_grade): name(name),
								sign_grade(sign_grade),
								exec_grade(exec_grade) {
				if (sign_grade > 150)
					Form::GradeTooLowException(this->sign_grade);
				else if (sign_grade < 1)
					Form::GradeTooHighException(this->sign_grade);
				if (exec_grade > 150)
					Form::GradeTooLowException(this->exec_grade);
				else if (exec_grade < 1)
					Form::GradeTooHighException(this->exec_grade);
			};

		Form(const Form& form);
		Form& operator=(const Form& form);
		~Form();

		const std::string getName(void) const;
		const size_t getSignGrade(void) const;
		const size_t getExecGrade(void) const;
		void beSigned(Bureaucrat& bureaucrat);
		bool isSigned(void);

		class GradeTooHighException : public std::exception {
			private:
				size_t _grade;

			public:
				GradeTooHighException(size_t grade): _grade(grade) {};
				const char* what(void) const throw();
		};

		class GradeTooLowException : public std::exception {
			private:
				size_t _grade;

			public:
				GradeTooLowException(size_t grade): _grade(grade) {};
				const char* what(void) const throw();
		};
};
 
std::ostream& operator<<(std::ostream& os, const Form& form);

#endif