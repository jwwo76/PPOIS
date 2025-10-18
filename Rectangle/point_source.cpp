#include "Point.h"

point::point(int x, int y) : x(x), y(y) {}

point::point() : point::point(0, 0) {}

int point::get_x() const {
	return x;
}

int point::get_y() const {
	return y;
}

ostream& operator <<(ostream& os, const point& p) {
	os << "(" << p.x << ", " << p.y << ") ";
	return os;
}

void point::set_x(int d) {
	x = d;
}

void point::set_y(int d) {
	y = d;
}