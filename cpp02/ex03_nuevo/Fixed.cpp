#include "Fixed.hpp"

Fixed::Fixed(): value(0) {
	//std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed &n_fixed) {
	this->value = n_fixed.value;	
	//std::cout << "Copy constructor called" << std::endl;
}

#include <stdio.h>

void printBits(int num) {
    // Iterar sobre los 32 bits de un entero
    for (int i = 31; i >= 0; i--) {
        // Desplazamos el bit i de num a la posición más baja y lo imprimimos
        int bit = (num >> i) & 1;
        printf("%d", bit);
        
        // Añadir un espacio para facilitar la lectura
        if (i % 8 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}

Fixed::Fixed(const int i) {
	//std::cout << "Int constructor called" << std::endl;
	//std::cout  << "Value before integer to fixed conversion: " << i << std::endl;
	// printBits(i);
	this->value = i << fract;
	// std::cout  << " Value after integer to fixed conversion: " << this->value;
	// std::cout << std::endl;
}

Fixed::Fixed(const float f) {
    this->value = static_cast<int>(roundf(f * (1 << 8)));
    //std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void) {
	//std::cout << "Fixed number destroyed." << std::endl;
}

int Fixed::toInt(void) const {
	// std::cout << "valeu = ";
	// printBits(this->value);
	// std::cout << ">> getFract: ";
	// unsigned int polla = static_cast<unsigned>(this->value >> this->getFract());
	// printBits(polla);
	// std::cout << std::endl;
	return (this->value >> this->getFract());
}

float Fixed::toFloat(void) const {
	float ret;

	ret = static_cast<float>(this->getRawBits());
	//std::cout << "toFloat called, ret = " << ret << std::endl;
	return (ret / (1 << this->getFract()));
}

//Fixed &Fixed::operator=(Fixed &n_fixed) {
	//this->value = n_fixed.value;
	//return (*this);
//}

Fixed &Fixed::operator=(const Fixed &n_fixed) {
	this->value = n_fixed.value;
	return (*this);
}

/* 
				Operadores Artiméticos
*/
Fixed	Fixed::operator+(const Fixed &f) const {
	Fixed	ret;

	ret.setRawBits(this->getRawBits()
				   + f.getRawBits());
	return (ret);
}

Fixed	Fixed::operator-(const Fixed &f) const {
	Fixed	ret;

	ret.setRawBits(this->getRawBits()
				   - f.getRawBits());
	return (ret);
}

Fixed	Fixed::operator*(const Fixed &f) const {
	Fixed	ret(this->toFloat() * f.toFloat());
	return (ret);
}

Fixed	Fixed::operator/(const Fixed &f) const {
	Fixed	ret(this->toFloat() / f.toFloat());
	return (ret);
}

/* Comparación */
bool	Fixed::operator<(const Fixed &f) const {
	return (this->getRawBits()
			< f.getRawBits());
}

bool	Fixed::operator<=(const Fixed &f) const {
	return (this->getRawBits()
			<= f.getRawBits());
}

bool	Fixed::operator>(const Fixed &f) const {
	return (this->getRawBits()
			> f.getRawBits());
}

bool	Fixed::operator>=(const Fixed &f) const {
	return (this->getRawBits()
			>= f.getRawBits());
}

bool	Fixed::operator==(const Fixed &f) const {
	return (this->getRawBits()
			== f.getRawBits());
}

bool	Fixed::operator!=(const Fixed &f) const {
	return (this->getRawBits()
			!= f.getRawBits());
}

/* 
	Incremento/Decremento
*/
Fixed	Fixed::operator++(int) {
	Fixed ret = *this;
	if (this->getRawBits() < INT_MAX)
	{
		this->setRawBits(
			this->getRawBits() + 1
		);
	}
	return (ret);
}

Fixed	&Fixed::operator++() {
	if (this->getRawBits() < INT_MAX)
	{
		this->setRawBits(
			this->getRawBits() + 1
		);
	}
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed ret = *this;
	if (this->getRawBits() > INT_MIN)
	{
		this->setRawBits(
			this->getRawBits() - 1
		);
	}
	return (ret);
}

Fixed	&Fixed::operator--() {
	if (this->getRawBits() > INT_MIN)
	{
		this->setRawBits(
			this->getRawBits() - 1
		);
	}
	return (*this);
}

/* 
	Min/Max
*/
Fixed &Fixed::min(Fixed &f1, Fixed &f2) {
	if (f1 <= f2)
		return (f1);
	else
		return (f2);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2) {

	// Fixed	&non_const_f2 = (Fixed &) f2;
	// Fixed	&non_const_f1 = (Fixed &) f1;
	// if (non_const_f1 <= non_const_f2)
	if (f1 <= f2)
		return (f1);
	else
		return (f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
	if (f1 > f2)
		return (f1);
	else
		return (f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2) {

	Fixed	&non_const_f2 = (Fixed &) f2;
	Fixed	&non_const_f1 = (Fixed &) f1;
	if (non_const_f1 > non_const_f2)
		return (f1);
	else
		return (f2);
}

/* 
	Raw Bits
*/

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
	os << "Fixed: " << fix;
	return (os);
}