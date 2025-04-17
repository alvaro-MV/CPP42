#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// int	main(void) {

// 	// const std::string form_name = "Holly";
// 	Bureaucrat currela("EldeLosCafes", 146);
// 	Bureaucrat alto_exec("CEO", 2);
// 	ShrubberyCreationForm shrub("garden");
// 	std::cout << shrub.getTarget() <<std::endl;

// 	currela.signForm(shrub);
// 	shrub.beSigned(currela);
// 	currela.incrGrade(2);
// 	currela.signForm(shrub);
// 	shrub.execute(alto_exec);

// 	currela.decrGrade(13);
// 	shrub.execute(currela);
// }

// int	main(void) {

// 	Bureaucrat alto_exec("CEO", 2);
// 	RobotomyRequestForm robo("robo");
// 	std::cout << robo.getTarget() <<std::endl;

// 	alto_exec.incrGrade(2);
// 	alto_exec.signForm(robo);
// 	robo.execute(alto_exec);
// }

int	main(void) {

	Bureaucrat alto_exec("CEO", 2);
	PresidentialPardonForm pardon("Perico");
	std::cout << pardon.getTarget() <<std::endl;

	alto_exec.signForm(pardon);
	alto_exec.executeForm(pardon);
}