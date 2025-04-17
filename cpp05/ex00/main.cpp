#include "Bureaucrat.hpp"

int	main(void) {
	Bureaucrat currela("EldeLosCafes", 146);
	currela.decrGrade(2);
	std::cout << currela << std::endl;
	currela.decrGrade(9);
}