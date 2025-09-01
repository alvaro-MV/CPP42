#include "Point.hpp"

/* 
	Este rollo consiste en separar el mundo/escena en base a líneas divisorias.
	Me explico. Si se tiene un plano, una linea divisoria divide el plano en dos 
	mitades: las que estan a un lado y las que estan al otro lado del plano.

	Si tienes dos lineas, entonces delimitas cuatro espacios, y asi todo el rato. La gracia
	de utilizar lineas divisorias es que te permite determinar si un punto pertence a un 
	objeto de forma sencilla y eficiente. El requisito para poder hacer esto es trazar lineas
	divisorias que rodeen al objeto.


									checknode (currentnode)
									if(currentnode is a leaf)
										if(currentnode contents are solid)
											return HIT
										else
											return MISS
									if(side start is on = side end is on)
										return checknode (child of currentnode both sides are on)
									result1 = checknode (child of currentnode start is on)
									result2 = checknode (child of currentnode end is on)
									if(result1 does not equal result2)
										nodehit = currentnode
									if(result1 = HIT or result2 = HIT)
										return HIT
									else
										return MISS
*/


typedef struct nodeLine {
	private:
		Point const a;
		Point const b;
	
	public:
		Point const ga() {return a;};
		Point const gb() {return b;};
		nodeLine(Point const a, Point const b);
		int side(Point p);
} nodeLine;

nodeLine::nodeLine(Point const a, Point const b): a(a), b(b) {};

int nodeLine::side(Point p) {
    Fixed val = (p.getX() - a.getX()) * (b.getY()  - a.getY())
				- (p.getY() - a.getY()) * (b.getX() - a.getX());
	
	if (val > 0)
		return 1;   // lado izquierdo
    if (val < 0)
		return -1;  // lado derecho
    return 0;  
}

Point	baricenter(Point a, Point b, Point c) {
	Fixed x = (a.getX() + b.getX() + c.getX()) / 3;
	Fixed y = (a.getY() + b.getY() + c.getY()) / 3;
	Point ret(x.toFloat(), y.toFloat());
	return (ret);
}

struct BSPTree {
	BSPTree		*next;
	BSPTree		*other;
	nodeLine	line;
};

bool	bspTraverse(BSPTree *current, Point const &p, Point const &center) {
	if (!current)
		return (true);
	//std::cout << "a: " << current->line.ga().getX();
	//std::cout << " b: " << current->line.gb().getX() << std::endl;
	//std::cout << "p: " << current->line.side(p) << " center: " << current->line.side(center) << std::endl;
	//std::cout << "next: " << current->next << std::endl;
	//std::cout << "\n ------------------------------------ \n";

	if (current->line.side(p) == current->line.side(center))
		return (bspTraverse(current->next, p, center));
	return (false);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	//std::cout << "Comprobacion random: " << b.getX() << std::endl;
	Point const center = baricenter(a, b, c);
	
	nodeLine node1(a, b);
	nodeLine node2(a, c);
	nodeLine node3(b, c);

	BSPTree bsp3 = {NULL, NULL, node3};
	BSPTree bsp2 = {&bsp3, NULL, node2};
	BSPTree bsp1 = {&bsp2, NULL, node1};

	bool valor = bspTraverse(&bsp1, point, center);
	std::cout << "Cual cojones es el resultado: " << valor << std::endl;
	return (valor);
}