#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
	private:
		int value;
		static const int fract = 8;
	
	public:
		Fixed() : value(0) {
			std::cout << "Default constructor called" << std::endl;
		};
		Fixed(Fixed &n_fixed);
		Fixed &operator=(Fixed &n_fixed);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif