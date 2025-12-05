#include "Bureaucrat.hpp"

int	main(void) {
	try {
		Bureaucrat currela("EldeLosCafes", 146);
		currela.decrGrade();
		std::cout << currela << std::endl;
		for (int i = 0; i < 9; i++)
			currela.decrGrade();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}