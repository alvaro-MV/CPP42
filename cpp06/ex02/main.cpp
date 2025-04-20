#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <random>

Base * generate(void) {
	Base *ret;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 3);
	int idxClass = distrib(gen);

	if (idxClass == 1)
		ret = new A;
	if (idxClass == 2)
		ret = new B;
	if (idxClass == 3)
		ret = new C;
	return (ret);
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
		std::cout << "object is of type A" << std::endl;
		return ;
	}
	catch (std::bad_cast &bad) {}
	try {
		B &bPtr = dynamic_cast<B&>(p);
		std::cout << "object is of type B" << std::endl;
		return ;
	}
	catch (std::bad_cast &bad) {}
	try {
		C &aPtr = dynamic_cast<C&>(p);
		std::cout << "object is of type C" << std::endl;
		return ;
	}
	catch (std::bad_cast &bad) {}
}

int main(void) {
	Base *p = generate();
	std::cout << "Pointer identification ";
	identify(p);
	std::cout << "Reference identification ";
	identify(*p);
}