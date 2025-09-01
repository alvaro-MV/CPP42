#ifndef FIXED_H
#define FIXED_H

#include <iostream>
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