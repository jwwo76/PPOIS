#include "Rectangle.h"

Rectangle::Rectangle(Point left_down, Point top_right) {

	p1 = left_down;
	p2 = top_right;

}

Rectangle::Rectangle(int x1, int y1, int x2, int y2) {

	int min_x = min(x1, x2);
	int min_y = min(y1, y2);
	int max_x = max(x1, x2);
	int max_y = max(y1, y2);

	p1 = Point(min_x,min_y);
	p2 = Point(max_x, max_y);
}

Rectangle::Rectangle() : Rectangle::Rectangle(0, 0, 1, 1) {};

void Rectangle::print_verticles(ostream& os) const {
	Point on_p1(p1.get_x(), p2.get_y());
	Point down_p2(p2.get_x(), p1.get_y());
	os << p1<<on_p1<<p2<<down_p2;
}

ostream& operator <<(ostream& os, const Rectangle& examp) {
	examp.print_verticles(os);
	return os;
}

void Rectangle::move_rectangle(int dx, int dy) {
	p1.set_x(p1.get_x() + dx);
	p1.set_y(p1.get_y() + dy);
	p2.set_x(p2.get_x() + dx);
	p2.set_y(p2.get_y() + dy);
}

void Rectangle::size_change(int d) {
	p2.set_x(p2.get_x() + d);
	p2.set_y(p2.get_y() + d);
}

Rectangle& Rectangle::operator++() {
	size_change(1);
	return *this;
}

Rectangle Rectangle::operator++(int) {
	Rectangle temp = *this;
	size_change(1);
	return temp;
}

Rectangle& Rectangle::operator--() {
	size_change(-1);
	return *this;
}

Rectangle Rectangle::operator--(int) {
	Rectangle temp = *this;
	size_change(-1);
	return temp;	
}

Rectangle Rectangle:: operator+(const Rectangle& second) {

	Point left_down;
	Point top_right;

	left_down.set_x(min(p1.get_x(), second.p1.get_x()));
	left_down.set_y(min(p1.get_y(), second.p1.get_y()));
	top_right.set_x(max(p2.get_x(), second.p2.get_x()));
	top_right.set_y(max(p2.get_y(), second.p2.get_y()));

	return Rectangle(left_down, top_right);

}

Rectangle& Rectangle::operator+=(const Rectangle& second) {

	*this = *this + second;

	return *this;	

}

Rectangle Rectangle::operator-(const Rectangle& second) {
	int inter_left = max(p1.get_x(), second.p1.get_x());
	int inter_bottom = max(p1.get_y(), second.p1.get_y());
	int inter_right = min(p2.get_x(), second.p2.get_x());
	int inter_top = min(p2.get_y(), second.p2.get_y());

	if (inter_left >= inter_right || inter_bottom >= inter_top) {
		return Rectangle(0, 0, 0, 0);
	}

	return Rectangle(inter_left, inter_bottom, inter_right, inter_top);
}

Rectangle& Rectangle::operator-=(const Rectangle& second) {
	*this = *this - second;
	return *this;
}

bool Rectangle::operator==(const Rectangle& second) const {
	return (p1.get_x() == second.p1.get_x() &&
		p1.get_y() == second.p1.get_y() &&
		p2.get_x() == second.p2.get_x() &&
		p2.get_y() == second.p2.get_y());
}

bool Rectangle::operator!=(const Rectangle& second) const {
	return !(*this == second);
}


