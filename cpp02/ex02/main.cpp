#include <iostream>
#include "Fixed.hpp"

// int main( void ) {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	return 0;
// }

// 0
// 0.00390625
// 0.00390625
// 0.00390625
// 0.0078125
// 10.1016
// 10.1016

int main(void)
{
	std::cout << "\nSubject main\n";
	std::cout << "-----------------\n";
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl; // 0
	std::cout << ++a << std::endl; // 0.00390625
	std::cout << a << std::endl; // 0.00390625
	std::cout << a++ << std::endl; // 0.00390625
	std::cout << a << std::endl; // 0.0078125
	std::cout << b << std::endl; // 10.1016
	std::cout << Fixed::max(a, b) << std::endl; // 10.1016

	std::cout << "\nMy main\n";
	std::cout << "-----------------\n";
	Fixed const c = a;
	std::cout << Fixed::min(c, b) << std::endl; // 0.0078125
	std::cout << b / Fixed(2) << std::endl; // 5.05078
	std::cout << b + Fixed(-3.14f) << std::endl; // 6.96094
	std::cout << b - Fixed(18) << std::endl; // -7.89844
	std::cout << (c != a) << std::endl; // 0
	std::cout << (c == a) << std::endl; // 1
	return 0; 
}