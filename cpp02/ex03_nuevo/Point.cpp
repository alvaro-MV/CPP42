#include "Point.hpp"

Point::Point(): x(0), y(0) {}

Point::Point(float x, float y): x(x), y(y) {}

Point::Point(const Point &p): x(p.x), y(p.y) {}

Point &Point::operator=(const Point &p) {
	return (*this);
}

Point::~Point() = default;

Fixed const Point::getX() const {
	return (x);
}

Fixed const Point::getY() const {
	return (y);
}
