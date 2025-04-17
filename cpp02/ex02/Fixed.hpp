#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>
#include <string.h>


class Fixed {
	private:
		int value;
		int fshift; // Para float conversion
		static const int fract = 8;
	
	public:
		Fixed() : value(0) {
			// std::cout << "Default constructor called" << std::endl;
		};
		Fixed(int i);
		Fixed(float f);
		Fixed(const Fixed &n_fixed);
		Fixed(Fixed &n_fixed);
		Fixed &operator=(const Fixed &n_fixed);
		bool operator>(const Fixed &n_fixed);
		bool operator<(const Fixed &n_fixed);
		bool operator>=(const Fixed &n_fixed);
		bool operator<=(const Fixed &n_fixed);
		bool operator==(const Fixed &n_fixed);
		bool operator!=(const Fixed &n_fixed);

		Fixed operator+(const Fixed &n_fixed);
		Fixed operator-(const Fixed &n_fixed);
		Fixed operator*(const Fixed &n_fixed);
		Fixed operator/(const Fixed &n_fixed);

		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);

		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);

		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
		int getFract() const;
		int toInt() const;
		float toFloat() const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
// void operator--(Fixed &n_fixed);

#endif