#include "Fixed.hpp"

// int main( void ) {
// 	// Fixed a;
// 	Fixed const b(2147483647);
// 	// Fixed const e(INT_MIN);
// 	// Fixed const c(42.42f);
// 	// Fixed const d(b);
// 	// a = Fixed(1234.4321f);

// 	// std::cout << "a is " << a << std::endl;
// 	std::cout << "b is " << b << std::endl;
// 	// std::cout << "c is " << c << std::endl;
// 	// std::cout << "d is " << d << std::endl;
// 	// std::cout << "e is " << e << std::endl;
// 	// std::cout << "a is " << a.toInt() << " as integer" << std::endl;
// 	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
// 	// std::cout << "c is " << c.toInt() << " as integer" << std::endl;
// 	// std::cout << "d is " << d.toInt() << " as integer" << std::endl;
// 	// std::cout << "e is " << e.toInt() << " as integer" << std::endl;
// 	return 0;
// }


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

int	getUpperMask(int fract) {
	int ret = 0;
	int	tmp = fract;
	while (fract--) {
		ret = ret << 1;
		ret |= 0x1;
	}
	int left = 32 - tmp;
	ret = ret << left;
	return (ret);
}

int	getLowerMask(int fract) {
	int ret = 0;
	int	tmp = fract;
	while (fract--) {
		ret = ret << 1;
		ret |= 0x1;
	}
	return (ret);
}



int	getUnitMask(int fract) {
	int ret = 1;
	while (fract--) {
		ret *= 2;
	}
	return (ret);
}

/* 
	-Cuando es negativo --> 0
	-Cuando es positivo --> 1

*/
int	main(void) {
	int a = INT_MAX;
	int sign = a > 0;
	int	fractPart = a & getUpperMask(8);

	std::cout << "a antes de shifteo: ";
	printBits(a);
	
	a = a << 8;
	printBits(a);
	std::cout << "fractPart: ";
	printBits(fractPart);
	a >>= 8;

	int tmp = getLowerMask(32 - 8);
	sign ? fractPart |= tmp : fractPart << (32 - 8);
	std::cout << "fractPart: ";
	printBits(fractPart);

	(sign) ? a &= fractPart : a |= fractPart;
	std::cout << "a despues de shifteo: ";
	printBits(a);
}