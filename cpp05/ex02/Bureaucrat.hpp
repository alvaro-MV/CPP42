#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include "AForm.hpp"
#include <string>
#include <iostream>
#include <exception>
#include <cstring>

class AForm;

class Bureaucrat {
	private:
		const std::string name;
		size_t grade;

	public:
		Bureaucrat(const std::string name, size_t grade): name(name),
												  grade(grade) {};
		Bureaucrat(const Bureaucrat& Bureaucrat);
		Bureaucrat& operator=(const Bureaucrat& Bureaucrat);
		~Bureaucrat();

		const std::string getName(void) const;
		void setGrade(size_t grade);
		size_t getGrade(void) const;
		void incrGrade(size_t incr);
		void decrGrade(size_t decr);
		void signForm(AForm &form);
		void executeForm(AForm const & form);

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
 
std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bureaucrat);

#endif