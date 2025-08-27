#include "Fixed.hpp"

Fixed::Fixed(void): value(0) {
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(Fixed &n_fixed) {
	this->value = n_fixed.value;	
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed &n_fixed) {
	this->value = n_fixed.value;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

Fixed::~Fixed(void) {
	std::cout << "Fixed number destroyed." << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw) {
	this->value = raw;
}