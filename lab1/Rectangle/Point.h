#pragma once

#include <iostream>
#include <fstream>

using namespace std;

class Point {
private:
	int x, y;

public:

	Point(int x, int y);

	Point();

	friend ostream& operator<<(ostream& os, const Point& examp);

	void set_x(int d);
	void set_y(int d);

	int get_x() const;
	int get_y() const;

};