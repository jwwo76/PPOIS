#pragma once


#include "Point.h"

class Rectangle {
	
private:
	
	Point p1, p2;

public:

	Rectangle(Point left_down, Point top_right);
	Rectangle(int x1, int y1, int x2, int y2);
	Rectangle();
	void print_verticles(ostream& os) const;
	friend ostream& operator <<(ostream& os, const Rectangle& examp);

	void move_rectangle(int dx, int dy);
	void size_change(int d);
	Rectangle& operator ++ ();
	Rectangle operator ++(int);
	Rectangle& operator -- ();
	Rectangle operator --(int);
	Rectangle operator +(const Rectangle& second);
	Rectangle& operator +=(const Rectangle& second);
	Rectangle operator - (const Rectangle& second);
	Rectangle& operator-=(const Rectangle& second);
	bool operator ==(const Rectangle& second) const;
	bool operator !=(const Rectangle& second) const;
};