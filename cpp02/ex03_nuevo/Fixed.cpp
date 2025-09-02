#include "Fixed.hpp"

Fixed::Fixed(): value(0) {
};

Fixed::Fixed(const Fixed &n_fixed) {
	this->value = n_fixed.value;	
}

Fixed::Fixed(const int i) {
	this->value = i << fract;
}

Fixed::Fixed(const float f) {
    this->value = static_cast<int>(roundf(f * (1 << getFract())));
}

Fixed::~Fixed(void) {
}

int Fixed::toInt(void) const {
	return (this->value >> this->getFract());
}

float Fixed::toFloat(void) const {
	float ret;

	ret = static_cast<float>(this->getRawBits());
	return (ret / (1 << this->getFract()));
}

Fixed &Fixed::operator=(const Fixed &n_fixed) {
	if (this != &n_fixed)
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
	if (f1 > f2)
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
	os << fix;
	return (os);
}