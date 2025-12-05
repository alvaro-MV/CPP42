#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// int	main(void) {

// 	// const std::string form_name = "Holly";
// 	try {

// 		Bureaucrat currela("EldeLosCafes", 146);
// 		Bureaucrat alto_exec("CEO", 2);
// 		ShrubberyCreationForm shrub("garden");
// 		std::cout << shrub.getTarget() <<std::endl;
	
// 		// currela.signForm(shrub);
// 		// shrub.beSigned(currela);
// 		currela.incrGrade();
// 		// currela.signForm(shrub);
// 		alto_exec.signForm(shrub);
// 		shrub.execute(alto_exec);
	
// 		currela.decrGrade();
// 		shrub.execute(currela);
// 	}
// 	catch (std::exception &e) {
// 		std::cout << e.what() << std::endl;
// 	}
// }

// int	main(void) {

// 	try {
// 		Bureaucrat alto_exec("CEO", 2);
// 		RobotomyRequestForm robo("robo");
// 		std::cout << robo.getTarget() <<std::endl;
	
// 		alto_exec.incrGrade();
// 		alto_exec.signForm(robo);
// 		robo.execute(alto_exec);
// 	}
// 	catch (std::exception &e) {
// 		std::cout << e.what() << std::endl;
// 	}
// }

int	main(void) {

	Bureaucrat alto_exec("CEO", 2);
	PresidentialPardonForm pardon("Perico");
	std::cout << pardon.getTarget() <<std::endl;

	alto_exec.signForm(pardon);
	alto_exec.executeForm(pardon);
}