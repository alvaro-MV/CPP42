#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void) {

	// const std::string form_name = "Holly";
	Bureaucrat currela("EldeLosCafes", 26);
	Form asignacion("Holly", 132, 33);
	std::cout << asignacion.getName() <<std::endl;

	asignacion.beSigned(currela);
	currela.signForm(asignacion);
}