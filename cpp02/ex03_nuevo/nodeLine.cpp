
#include "nodeLine.hpp"

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