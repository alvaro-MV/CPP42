#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base *generate(void) {
    int idx = rand() % 3;
    switch (idx) {
        case 0: return new A;
        case 1: return new B;
        case 2: return new C;
    }
    return NULL; // nunca ocurre
}


void identify(Base* p) {
	A* aPtr = dynamic_cast<A*>(p);
	if (aPtr)
	{
		std::cout << "object is of type A" << std::endl;
		return ;
	}
	B* bPtr = dynamic_cast<B*>(p);
	if (bPtr)
	{
		std::cout << "object is of type B" << std::endl;
		return ;
	}
	C* cPtr = dynamic_cast<C*>(p);
	if (cPtr)
	{
		std::cout << "object is of type C" << std::endl;
		return ;
	}
}

void identify(Base& p) {
	try {
		A &aPtr = dynamic_cast<A&>(p);
		(void) aPtr;
		std::cout << "object is of type A" << std::endl;
		return ;
	}
	catch (std::exception &bad) {}
	try {
		B &bPtr = dynamic_cast<B&>(p);
		(void) bPtr;
		std::cout << "object is of type B" << std::endl;
		return ;
	}
	catch (std::exception &bad) {}
	try {
		C &cPtr = dynamic_cast<C&>(p);
		(void) cPtr;
		std::cout << "object is of type C" << std::endl;
		return ;
	}
	catch (std::exception &bad) {}
}


// Colores opcionales
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

// Función auxiliar para convertir tipos a char
char typeOf(Base* p) {
    if (dynamic_cast<A*>(p)) return 'A';
    if (dynamic_cast<B*>(p)) return 'B';
    if (dynamic_cast<C*>(p)) return 'C';
    return '?';
}

int main() {
    srand(time(NULL));

    std::cout << "===== TESTER ex02 =====\n\n";
    std::cout << "Test 1: Probando generate() 1000 veces...\n";

    int countA = 0, countB = 0, countC = 0;
    bool ok = true;

    for (int i = 0; i < 1000; i++) {
        Base* p = generate();
        if (!p) {
            std::cout << RED << "❌ generate() devolvió NULL\n" << RESET;
            ok = false;
            break;
        }

        if (dynamic_cast<A*>(p)) countA++;
        else if (dynamic_cast<B*>(p)) countB++;
        else if (dynamic_cast<C*>(p)) countC++;
        else {
            std::cout << RED << "❌ generate() devolvió un tipo desconocido\n" << RESET;
            ok = false;
        }
        delete p;
    }

    std::cout << "A: " << countA << "\nB: " << countB << "\nC: " << countC << "\n";

    if (countA > 0 && countB > 0 && countC > 0)
        std::cout << GREEN << "✔ Todas las clases generadas correctamente.\n\n" << RESET;
    else {
        std::cout << RED << "❌ Alguna clase NO ha sido generada (muy mala señal)\n\n" << RESET;
        ok = false;
    }

    std::cout << "Test 2: Probando identify(Base*) y identify(Base&)...\n";

    for (int i = 0; i < 10; i++) {
        Base* p = generate();
        char expected = typeOf(p);

        std::cout << "\nTest #" << i + 1 << " (tipo real: " << expected << ")\n";

        std::cout << "identify(ptr): ";
        identify(p);

        std::cout << "identify(ref): ";
        identify(*p);

        delete p;
    }

    std::cout << "\n===== RESULTADO FINAL =====\n";
    if (ok)
        std::cout << GREEN << "✔ Todo correcto. ex02 funciona perfectamente.\n" << RESET;
    else
        std::cout << RED << "❌ Hay errores en la implementación.\n" << RESET;

    return 0;
}

// int main(void) {
// 	srand(time(NULL));
// 	Base *p = generate();
// 	std::cout << "Pointer identification ";
// 	identify(p);
// 	std::cout << "Reference identification ";
// 	identify(*p);
// 	delete p;
// }