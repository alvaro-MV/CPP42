#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point {
	private:
		Fixed const x;
		Fixed const y;

	public:
		Point();
		Point(float x, float y);
		Point(const Point &p);
		Point &operator=(const Point &p);
		~Point();

		Fixed const getX() const;
		Fixed const getY() const;
};

#endif