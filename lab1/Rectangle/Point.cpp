#include "Point.h"

Point::Point(int x, int y) : x(x), y(y) {}

Point::Point() : Point::Point(0, 0) {}

int Point::get_x() const {
	return x;
}

int Point::get_y() const {
	return y;
}

ostream& operator <<(ostream& os, const Point& p) {
	os << "(" << p.x << ", " << p.y << ") ";
	return os;
}

void Point::set_x(int d) {
	x = d;
}

void Point::set_y(int d) {
	y = d;
}