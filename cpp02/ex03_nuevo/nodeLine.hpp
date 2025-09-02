#include "Point.hpp"

#ifndef NODELINE_HPP
#define NODELINE_HPP

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

struct BSPTree {
	BSPTree		*next;
	BSPTree		*other;
	nodeLine	line;
};

#endif