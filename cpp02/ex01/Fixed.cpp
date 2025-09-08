#include "Fixed.hpp"

Fixed::Fixed(): value(0) {
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed &n_fixed) {
	std::cout << "Copy constructor called" << std::endl;
	this->value = n_fixed.value;	
}


Fixed::Fixed(const int i) {
	std::cout << "Int constructor called" << std::endl;
	this->value = i << fract;
}

Fixed::Fixed(const float f) {	
    std::cout << "Float constructor called" << std::endl;
    this->value = static_cast<int>(roundf(f * (1 << fract)));
}


int Fixed::toInt(void) const {
	return (this->value >> this->getFract());
}

float Fixed::toFloat(void) const {
	float ret;

	ret = (float) this->getRawBits();
	return (ret / (1 << this->getFract()));
}

Fixed &Fixed::operator=(const Fixed &n_fixed) {
	this->value = n_fixed.value;
	return (*this);
}

Fixed::~Fixed(void) {
	std::cout << "Fixed number destroyed." << std::endl;
}

int Fixed::getRawBits(void) const {
	return (this->value);
}

void Fixed::setRawBits(int const raw) {
	this->value = raw;
}

int Fixed::getFract(void) const {
	return (this->fract);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	float fix;

	fix = fixed.toFloat();
	os << fix;
	return (os);
}