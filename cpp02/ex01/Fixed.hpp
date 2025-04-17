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
			std::cout << "Default constructor called" << std::endl;
		};
		Fixed(int i);
		Fixed(float f);
		Fixed(const Fixed &n_fixed);
		Fixed(Fixed &n_fixed);
		Fixed &operator=(Fixed &n_fixed);
		Fixed &operator=(Fixed n_fixed);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
		int getFract() const;
		int toInt() const;
		float toFloat() const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif