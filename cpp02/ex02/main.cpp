#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed const b(Fixed(-5.05f) / Fixed(2.9f));
	Fixed dos(2.0f);
	Fixed uno(1.0f);

	std::cout << b << std::endl;
	if (dos > Fixed(0.0f))
		std::cout << "dos is positive" << std::endl;
	Fixed que_sera = dos - uno;
	std::cout << "Que sera: " << que_sera << std::endl;
	std::cout << "Cual es menor: "<< Fixed::min(uno, dos) << std::endl;

	std::cout << que_sera << std::endl;
	std::cout << que_sera-- << std::endl;
	std::cout << que_sera << std::endl;
	std::cout << --que_sera << std::endl;
	return 0;
}
