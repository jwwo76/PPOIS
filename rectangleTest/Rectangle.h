#pragma once


#include "Point.h"

class rectangle {
	
private:
	
	point p1, p2;

public:

	rectangle(point left_down, point top_right);
	rectangle(int x1, int y1, int x2, int y2);
	rectangle();
	void print_verticles(ostream& os) const;
	friend ostream& operator <<(ostream& os, const rectangle& examp);

	void move_rectangle(int dx, int dy);
	void size_change(int d);
	rectangle& operator ++ ();
	rectangle operator ++(int);
	rectangle& operator -- ();
	rectangle operator --(int);
	rectangle operator +(const rectangle& second);
	rectangle& operator +=(const rectangle& second);
	rectangle operator - (const rectangle& second);
	rectangle& operator-=(const rectangle& second);
	bool operator ==(const rectangle& second) const;
	bool operator !=(const rectangle& second) const;
};