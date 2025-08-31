#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <limits.h>
#include <cmath>
#include <string.h>


class Fixed {
	private:
		int value;
		static const int fract = 8;
	
	public:
		Fixed();
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed &n_fixed);
		Fixed(Fixed &n_fixed);
		//Fixed &operator=(Fixed &n_fixed);
		Fixed &operator=(const Fixed &n_fixed);
		~Fixed();

		/* 
			Operadores aritmeticos
		*/
		Fixed	operator+(const Fixed &f) const;
		Fixed	operator-(const Fixed &f) const;
		Fixed	operator/(const Fixed &f) const ;
		Fixed	operator*(const Fixed &f) const;

		/* 
			Comparación
		*/
		bool	operator<(const Fixed &f) const;
		bool	operator>(const Fixed &f) const;
		bool	operator<=(const Fixed &f) const;
		bool	operator>=(const Fixed &f) const;
		bool	operator==(const Fixed &f) const;
		bool	operator!=(const Fixed &f) const;

		/* 
			Incremento/Decremento
		*/
		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);

		/* 
			Min/Max
		*/
		static Fixed &min(Fixed &f1, Fixed &f2);
		static const Fixed &min(const Fixed &f1, const Fixed &f2);
		static Fixed &max(Fixed &f1, Fixed &f2);
		static const Fixed &max(const Fixed &f1, const Fixed &f2);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		int getFract() const;
		int toInt() const;
		float toFloat() const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif