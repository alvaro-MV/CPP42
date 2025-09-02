#include "Fixed.hpp"
#include "Point.hpp"

#include <iostream>
//int main( void ) {
	//Fixed a;
	//Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	//Fixed c = Fixed(13);

	//std::cout << a << std::endl;
	//std::cout << ++a << std::endl;
	//std::cout << a << std::endl;
	//std::cout << a++ << std::endl;
	//std::cout << a << std::endl;
	//std::cout << b << std::endl;
	//std::cout << Fixed::max( a, b ) << std::endl;
	//return 0;
//}

#include "Point.hpp"
#include <iostream>

// Declaración de bsp
bool bsp(Point const a, Point const b, Point const c, Point const point);

void testCase(const std::string& desc, const Point& a, const Point& b, const Point& c, const Point& p) {
	std::cout << desc << ": " << (bsp(a, b, c, p) ? "✅ Dentro" : "❌ Fuera") << std::endl;
}

// int main() {
// 	Point a(0.0f, 0.0f);
// 	Point b(5.0f, 0.0f);
// 	Point c(2.5f, 5.0f);

// 	std::cout << "=== TEST BSP TRIÁNGULO A(0,0) B(5,0) C(2.5,5) ===" << std::endl;

// 	// Dentro (claramente en el centro)
// 	testCase("1. Centro del triángulo", a, b, c, Point(2.5f, 2.0f));
// 	testCase("2. Ligeramente dentro (cerca de A)", a, b, c, Point(1.0f, 1.0f));
// 	testCase("3. Ligeramente dentro (cerca de B)", a, b, c, Point(4.0f, 1.0f));
// 	testCase("4. Ligeramente dentro (cerca de C)", a, b, c, Point(2.5f, 3.5f));
// 	testCase("5. Muy dentro (cerca del centro exacto)", a, b, c, Point(2.5f, 2.49f));

// 	// Fuera (cercanos)
// 	testCase("6. Muy cerca fuera abajo", a, b, c, Point(2.5f, -0.01f));
// 	testCase("7. Muy cerca fuera arriba", a, b, c, Point(2.5f, 5.01f));
// 	testCase("8. Muy cerca fuera izquierda", a, b, c, Point(-0.01f, 1.0f));
// 	testCase("9. Muy cerca fuera derecha", a, b, c, Point(5.01f, 1.0f));

// 	// Fuera (claramente)
// 	testCase("10. Fuera a la derecha", a, b, c, Point(6.0f, 1.0f));
// 	testCase("11. Fuera arriba derecha", a, b, c, Point(4.5f, 5.5f));
// 	testCase("12. Fuera abajo izquierda", a, b, c, Point(-2.0f, -2.0f));

// 	// En vértices (deberían ser fuera si excluyes bordes)
// 	testCase("13. Vértice A", a, b, c, a);
// 	testCase("14. Vértice B", a, b, c, b);
// 	testCase("15. Vértice C", a, b, c, c);

// 	// En lados (también fuera si excluyes bordes)
// 	testCase("16. Punto en mitad de AB", a, b, c, Point(2.5f, 0.0f));
// 	testCase("17. Punto en mitad de BC", a, b, c, Point(3.75f, 2.5f));
// 	testCase("18. Punto en mitad de CA", a, b, c, Point(1.25f, 2.5f));

// 	// En línea pero fuera del segmento
// 	testCase("19. Prolongación de AB", a, b, c, Point(6.0f, 0.0f));
// 	testCase("20. Prolongación de BC", a, b, c, Point(6.0f, 6.0f));
// 	testCase("21. Prolongación de CA", a, b, c, Point(-2.0f, 5.0f));

// 	// Lejos
// 	testCase("22. Muy lejos", a, b, c, Point(100.0f, 100.0f));

// 	return 0;
// }


//int main() {
	//Point a(0.0f, 0.0f);
	//Point b(5.0f, 0.0f);
	//Point c(2.5f, 5.0f);

	//// Casos
	//testCase("1. Centro del triángulo", a, b, c, Point(2.5f, 2.0f));
	//testCase("2. Vértice A", a, b, c, a);
	//testCase("2. Vértice B", a, b, c, b);
	//testCase("2. Vértice C", a, b, c, c);
	//testCase("3. Mitad de AB", a, b, c, Point(2.5f, 0.0f));
	//testCase("3. Mitad de BC", a, b, c, Point(3.75f, 2.5f));
	//testCase("3. Mitad de CA", a, b, c, Point(1.25f, 2.5f));
	//testCase("4. Muy cerca fuera abajo", a, b, c, Point(2.5f, -0.01f));
	//testCase("4. Muy cerca fuera arriba", a, b, c, Point(2.5f, 5.01f));
	//testCase("4. Muy cerca fuera lateral", a, b, c, Point(-0.01f, 2.5f));
	//testCase("5. En prolongación de AB", a, b, c, Point(6.0f, 0.0f));
	//testCase("5. En prolongación de BC", a, b, c, Point(5.0f, 5.0f));
	//testCase("5. En prolongación de CA", a, b, c, Point(-1.0f, 2.0f));
	//testCase("6. Lejos del triángulo", a, b, c, Point(100.0f, 100.0f));
	//testCase("7. Sobre línea AC diagonal", a, b, c, Point(1.25f, 2.5f));  // Mismo que mitad CA
//}

//int main() {
	//Point a(0.0f, 0.0f);
	//Point b(5.0f, 0.02f);
	//Point c(2.5f, 5.0f);

	//Point p1(2.5f, 2.0f);  // Dentro
	//Point p2(2.5f, 0.0f);  // En borde
	//Point p3(5.1f, 1.0f);  // Fuera

	//std::cout << "Punto dentro:   " << (bsp(a, b, c, p1) ? "✅ Dentro" : "❌ Fuera") << std::endl;
	//std::cout << "Punto en borde: " << (bsp(a, b, c, p2) ? "✅ Dentro" : "❌ Fuera") << std::endl;
	//std::cout << "Punto fuera:    " << (bsp(a, b, c, p3) ? "✅ Dentro" : "❌ Fuera") << std::endl;


	//return 0;
//}

int main(void)
{
	{
	const Point a;
	const Point b(10, 0);
	const Point c(0, 10);
	const Point point(1, 1);

	std::cout << "The point( x= " << point.getX() << "\t\ty= " << point.getY() << "\t) is inside the triangle\n" <<
	"\ta( x= " << a.getX() << "\t\ty= " << a.getY() << "\t)\n" <<
	"\tb( x= " << b.getX() << "\ty= " << b.getY() << "\t)\n" <<
	"\tc( x= " << c.getX() << "\t\ty= " << c.getY() << "\t)\n" << std::endl;
	if (bsp(a, b, c, point) == true)
		std::cout << "\033[32mTRUE\033[0m" << std::endl;
	else
		std::cout << "\033[31mFALSE\033[0m" << std::endl;
	}
	std::cout << "\n---------------------------------------------------------------------\n" << std::endl;
	{
	Point a(-1.5, -1.5);
	Point b(2.5, 2.5);
	Point c(-1, -2);
	Point point(8.5, -9);

	std::cout << "The point( x= " << point.getX() << "\ty= " << point.getY() << "\t) is inside the triangle\n" <<
	"\ta( x= " << a.getX() << "\ty= " << a.getY() << "\t)\n" <<
	"\tb( x= " << b.getX() << "\ty= " << b.getY() << "\t)\n" <<
	"\tc( x= " << c.getX() << "\ty= " << c.getY() << "\t)\n" << std::endl;
	if (bsp(a, b, c, point) == true)
		std::cout << "\033[32mTRUE\033[0m" << std::endl;
	else
		std::cout << "\033[31mFALSE\033[0m" << std::endl;
	}
	return (0);
}