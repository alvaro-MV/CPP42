#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main(void) {

	Bureaucrat alto_exec("CEO", 2);
	Intern intern;
	AForm *pardon = intern.makeForm("PresidentialPardon   Form", "Ryan");
	if (pardon)
	{
		alto_exec.signForm(*pardon);
		alto_exec.executeForm(*pardon);
		delete pardon;
	}
}