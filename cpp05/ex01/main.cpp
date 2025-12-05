#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void) {

	try {
		Bureaucrat currela("EldeLosCafes", 26);
		Form asignacion("Holly", 132, 33);
		std::cout << asignacion.getName() <<std::endl;
	
		asignacion.beSigned(currela);
		currela.signForm(asignacion);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}