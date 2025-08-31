#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <limits.h>
#include <cmath>
#include <string.h>


class Fixed {
	private:
		int value;
		static const int fract = 1;
	
	public:
		Fixed();
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed &n_fixed);
		Fixed(Fixed &n_fixed);
		Fixed &operator=(Fixed &n_fixed);
		//Fixed &operator=(Fixed n_fixed);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
		int getFract() const;
		int toInt() const;
		float toFloat() const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif