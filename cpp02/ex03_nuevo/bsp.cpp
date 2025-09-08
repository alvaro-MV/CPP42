#include "nodeLine.hpp"

Point	baricenter(Point a, Point b, Point c) {
	Fixed x = (a.getX() + b.getX() + c.getX()) / 3;
	Fixed y = (a.getY() + b.getY() + c.getY()) / 3;
	Point ret(x.toFloat(), y.toFloat());
	return (ret);
}

bool	bspTraverse(BSPTree *current, Point const &p, Point const &center) {
	if (!current)
		return (true);
	if (current->line.side(p) == current->line.side(center))
		return (bspTraverse(current->next, p, center));
	return (false);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Point const center = baricenter(a, b, c);
	
	nodeLine node1(a, b);
	nodeLine node2(a, c);
	nodeLine node3(b, c);

	BSPTree bsp3 = {NULL, node3};
	BSPTree bsp2 = {&bsp3, node2};
	BSPTree bsp1 = {&bsp2, node1};

	bool valor = bspTraverse(&bsp1, point, center);
	std::cout << "Resultado: " << valor << std::endl;
	return (valor);
}