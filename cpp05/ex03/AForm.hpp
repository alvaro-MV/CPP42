#ifndef AFORM_H
#define AFORM_H

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <exception>
#include <cstring>

class Bureaucrat;

class AForm {
	private:
		const std::string name;
		const size_t sign_grade;
		const size_t exec_grade;
		bool _signed = false;

	public:
		AForm(const std::string name,
			size_t sign_grade,
			size_t exec_grade): name(name),
								sign_grade(sign_grade),
								exec_grade(exec_grade) {
				if (sign_grade > 150)
					AForm::GradeTooLowException(this->sign_grade);
				else if (sign_grade < 1)
					AForm::GradeTooHighException(this->sign_grade);
				if (exec_grade > 150)
					AForm::GradeTooLowException(this->exec_grade);
				else if (exec_grade < 1)
					AForm::GradeTooHighException(this->exec_grade);
			};

		AForm(const AForm& form);
		AForm& operator=(const AForm& form);
		virtual ~AForm() {};

		std::string getName(void) const;
		size_t getSignGrade(void) const;
		size_t getExecGrade(void) const;
		void beSigned(Bureaucrat& bureaucrat);
		bool isSigned(void) const;

		int execute(Bureaucrat const & executor) const;
		virtual void executeAction() const = 0;

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

		class FormNotSignedException : public std::exception {
			private:
				size_t _grade;

			public:
				FormNotSignedException(size_t grade): _grade(grade) {};
				const char* what(void) const throw();
		};
};
 
std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif